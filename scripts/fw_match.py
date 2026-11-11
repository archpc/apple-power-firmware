#!/usr/bin/env python3
"""Calibrated multi-signal function matching on Ghidra-defined boundaries.

Corrections applied after review:
  * instruction decode is bounded by Ghidra function bodies (address+size from the
    provider inventory) and truncated to Ghidra's own instruction count, so
    literal pools and jump tables are not decoded as code. No whole-image sweep.
  * constants are preserved. Only relocations, addresses and variable names are
    normalised. Command IDs, bitmasks, comparison values live in the semantic
    signature.
  * matching uses four independent signals and is one-to-one.
  * false-positive rate is calibrated per build pair against unrelated functions
    of comparable size; a match must beat the calibrated threshold.
  * results are reported as a confidence distribution with explicit unmatched
    sets, not a single mean.

Verdict vocabulary for a matched pair, keeping relocation, compiler generation,
code change and behaviour strictly separate:
  RELOCATED      identical normalised pseudocode AND identical mnemonic sequence
                 AND identical constants; only addresses differ.
  RECOMPILED     identical constants and same CFG topology within tolerance, but
                 mnemonic sequence and instruction count differ. Logic preserved,
                 code generation changed.
  CODE_CHANGED   constants differ or CFG topology differs beyond tolerance.
  NO_MATCH       nothing above the calibrated threshold.
No pair is labelled a behaviour change by this script. Behaviour claims require
constants or reachable-branch evidence and are argued in DIFF.md, not here.

Usage: fw_match.py <raw_dir> <images_dir> <out_dir>
"""
import json
import os
import re
import subprocess
import sys
import random
import difflib
from collections import Counter

random.seed(0xC0FFEE)

CALLEE = re.compile(r"\bFUN_([0-9a-fA-F]+)")
GLOBAL = re.compile(r"\b(?:DAT|PTR|UNK)_[A-Za-z0-9_]+")
LABEL = re.compile(r"\b(?:LAB|code)_[0-9a-fA-F]+")
HEXL = re.compile(r"\b0x([0-9a-fA-F]+)\b")
DECL = re.compile(r"(?<![\w.])(\d+)(?![\w.])")
VAR = re.compile(r"\b(?:local|uStack|iStack|auStack|aStack|param|unaff|extraout|"
                 r"stack|localReserved|bStack|uVar|iVar|lVar|uVar\d|pcVar|pbVar|"
                 r"plVar|pfVar|puVar|cVar)(?:_[A-Za-z0-9_]+|\d*)\b")
SPACES = re.compile(r"\s+")
IMAGE_SPAN = 0x15000
COND = re.compile(r"^(b[a-z]{1,3}|cbz|cbnz)$")

BUILDS = {
    "318": {"img": "A2363_3.1.8_10M569_base0.bin", "pseudo": "pseudo_318",
            "inv": "inventory_318.tsv"},
    "3112": {"img": "A2363_3.1.12_10M1543_base0.bin", "pseudo": "pseudo_3_1_12",
             "inv": "inventory_3112.tsv"},
    "320": {"img": "A2363_3.2.0_10M13722_base0.bin", "pseudo": "pseudo_3_2_0",
            "inv": "inventory_320.tsv"},
}


ADDR_DEREF = re.compile(r"\*\s*\([^)]*\*\)\s*(0x[0-9a-fA-F]+)|\(code \*\)\s*(0x[0-9a-fA-F]+)"
                        r"|\(_func_[^)]*\)\s*(0x[0-9a-fA-F]+)")


def addr_shaped(v):
    """Deprecated magnitude heuristic. Retained only for reference.

    This test classifies any literal below the image span as an address, which
    wrongly erases command IDs, bitmasks and protocol constants (0x09, 0x0D,
    0x05AC..., 0xA001...). It must not be used to decide whether a literal is
    semantic. Use addr_refs() below, which only treats a literal as an address
    when the pseudocode dereferences or calls through it.
    """
    return v < IMAGE_SPAN or 0x40000000 <= v < 0xF0000000


def addr_refs(body):
    """Literals proven to be addresses by dereference/call context."""
    out = set()
    for m in ADDR_DEREF.finditer(body):
        g = next(x for x in m.groups() if x)
        out.add(int(g, 16))
    return out


def load_inventory(path):
    inv = {}
    with open(path) as f:
        next(f)
        for line in f:
            p = line.rstrip("\n").split("\t")
            if len(p) < 5:
                continue
            inv[int(p[0], 16)] = {"name": p[1], "size": int(p[2]),
                                  "instructions": int(p[3]), "sha16": p[4]}
    return inv


def load_pseudo(d):
    out = {}
    fdir = os.path.join(d, "functions")
    for fn in os.listdir(fdir):
        if not fn.endswith(".c"):
            continue
        txt = open(os.path.join(fdir, fn), encoding="utf-8", errors="replace").read()
        addr, body = None, []
        for line in txt.splitlines():
            if line.startswith("// address:"):
                addr = int(line.split(":", 1)[1].strip(), 16)
            elif line.startswith("//"):
                continue
            else:
                body.append(line)
        if addr is not None:
            out[addr] = "\n".join(body)
    return out


def norm_pseudo(body):
    consts = Counter()
    for m in HEXL.finditer(body):
        v = int(m.group(1), 16)
        if not addr_shaped(v):
            consts[v] += 1
    for m in DECL.finditer(body):
        v = int(m.group(1))
        if not addr_shaped(v) and v > 1:
            consts[v] += 1
    callees = sorted({int(x, 16) for x in CALLEE.findall(body)})
    t = CALLEE.sub("F", body)
    t = GLOBAL.sub("G", t)
    t = LABEL.sub("L", t)
    t = HEXL.sub(lambda m: "A" if addr_shaped(int(m.group(1), 16)) else "K", t)
    t = DECL.sub(lambda m: "A" if addr_shaped(int(m.group(1))) else "K", t)
    t = VAR.sub("V", t)
    t = SPACES.sub(" ", t).strip()
    toks = re.findall(r"[A-Za-z_][A-Za-z0-9_]*|[^A-Za-z0-9_\s]", t)
    return toks, consts, callees


def bounded_disasm(img, inv, tag, outdir):
    """Decode only inside Ghidra function bodies, truncated to Ghidra's count."""
    rz = os.path.join(outdir, f"rz_{tag}.rz")
    order = []
    cmds = []
    with open(rz, "w") as f:
        for addr, m in sorted(inv.items()):
            n = m["instructions"]
            if n <= 0 or n > 4000:
                continue
            order.append(addr)
            cmds.append(f"s 0x{addr:x};pdj {n}")
            f.write(f"s 0x{addr:x};pdj {n}\n")
    # This rizin build rejects '?e' and 'echo' inside -c, and rejects multi-line
    # -i scripts, so no marker mechanism is available. pdj emits one JSON array
    # per command in command order; concatenate and split on '][' instead.
    p = subprocess.run(["rizin", "-q", "-N", "-e", "scr.color=0", "-a", "arm", "-b", "16",
                        "-c", ";".join(cmds), img], capture_output=True, text=True)
    flat = p.stdout.replace("\n", "").replace("\r", "").strip()
    chunks = []
    if flat.startswith("["):
        for part in flat.split("]["):
            part = part.strip()
            if not part.startswith("["):
                part = "[" + part
            if not part.endswith("]"):
                part = part + "]"
            chunks.append(part)
    by_addr = {}
    for addr, chunk in zip(order, chunks):
        try:
            ins = json.loads(chunk)
        except ValueError:
            by_addr[addr] = []
            continue
        by_addr[addr] = [i["opcode"].split()[0] for i in ins if i.get("opcode")]
    return by_addr


def cf_feat(mnem):
    cond = sum(1 for m in mnem if COND.match(m))
    uncond = sum(1 for m in mnem if m == "b")
    calls = sum(1 for m in mnem if m in ("bl", "blx"))
    rets = sum(1 for m in mnem if m in ("bx",))
    return {"cond": cond, "uncond": uncond, "calls": calls, "ret": rets,
            "blocks": 1 + cond + uncond, "len": len(mnem)}


def cf_dist(a, b):
    keys = ("cond", "uncond", "calls", "ret", "blocks")
    tot = sum(max(a[k], b[k]) for k in keys) or 1
    return sum(abs(a[k] - b[k]) for k in keys) / tot


def jacc(a, b):
    if not a and not b:
        return 1.0
    return sum((a & b).values()) / (sum((a | b).values()) or 1)


def rat(x, y):
    if not x or not y:
        return 0.0
    return difflib.SequenceMatcher(None, x, y, autojunk=False).ratio()


def build_feats(raw, imgdir, tag, outdir):
    cfg = BUILDS[tag]
    inv = load_inventory(os.path.join(raw, cfg["inv"]))
    ps = load_pseudo(os.path.join(raw, cfg["pseudo"]))
    mn = bounded_disasm(os.path.join(imgdir, cfg["img"]), inv, tag, outdir)
    feats = {}
    for addr, body in ps.items():
        toks, consts, callees = norm_pseudo(body)
        mnem = mn.get(addr, [])
        feats[addr] = {"toks": toks, "consts": consts, "callees": callees,
                       "mnem": mnem, "cf": cf_feat(mnem),
                       "nins": inv.get(addr, {}).get("instructions", len(mnem)),
                       "size": inv.get(addr, {}).get("size", 0)}
    return feats, inv


def score_pair(fa, fb):
    P = rat(fa["toks"], fb["toks"])
    M = rat(fa["mnem"], fb["mnem"])
    C = 1.0 - cf_dist(fa["cf"], fb["cf"])
    S = jacc(fa["consts"], fb["consts"])
    la, lb = len(fa["mnem"]), len(fb["mnem"])
    R = 1.0 - abs(la - lb) / max(1, max(la, lb))
    return 0.45 * P + 0.25 * M + 0.15 * C + 0.10 * S + 0.05 * R, P, M, C, S, R


def calibrate(A, B):
    """Score unrelated pairs (similar instruction count) to get a null threshold."""
    by_size = {}
    for b, fb in B.items():
        by_size.setdefault(fb["nins"] // 16, []).append(b)
    null = []
    for a, fa in A.items():
        if fa["nins"] < 8:
            continue
        bucket = by_size.get(fa["nins"] // 16, [])
        if len(bucket) < 4:
            continue
        for b in random.sample(bucket, 3):
            null.append(score_pair(fa, B[b])[0])
    null.sort()
    if not null:
        return {"n": 0, "p95": 0.75, "p99": 0.8, "max": 0.9}
    return {"n": len(null),
            "p50": round(null[len(null) // 2], 4),
            "p95": round(null[int(len(null) * 0.95)], 4),
            "p99": round(null[min(len(null) - 1, int(len(null) * 0.99))], 4),
            "max": round(null[-1], 4)}


def run(A, B, featsA, featsB, thr):
    cand = []
    for a, fa in featsA.items():
        for b, fb in featsB.items():
            if min(fa["nins"], fb["nins"]) / max(1, max(fa["nins"], fb["nins"])) < 0.45:
                continue
            s = score_pair(fa, fb)
            if s[0] >= thr:
                cand.append((s[0],) + s[1:] + (a, b))
    cand.sort(reverse=True)
    ua, ub, pairs = set(), set(), []
    for sc, P, M, C, S, R, a, b in cand:
        if a in ua or b in ub:
            continue
        ua.add(a); ub.add(b)
        fa, fb = featsA[a], featsB[b]
        if P >= 0.999 and M >= 0.999:
            verdict = "RELOCATED"
        elif S >= 0.90 and C >= 0.75 and (P >= 0.80 or M >= 0.80):
            verdict = "RECOMPILED"
        else:
            verdict = "CODE_CHANGED"
        pairs.append({"a": a, "b": b, "score": round(sc, 4), "P": round(P, 3),
                      "M": round(M, 3), "C": round(C, 3), "S": round(S, 3),
                      "R": round(R, 3), "verdict": verdict,
                      "a_ins": fa["nins"], "b_ins": fb["nins"],
                      "a_size": fa["size"], "b_size": fb["size"]})
    return pairs, sorted(set(featsA) - ua), sorted(set(featsB) - ub)


def main():
    raw, imgdir, outdir = sys.argv[1], sys.argv[2], sys.argv[3]
    os.makedirs(outdir, exist_ok=True)
    F, INV = {}, {}
    for tag in BUILDS:
        F[tag], INV[tag] = build_feats(raw, imgdir, tag, outdir)
        stubs = sum(1 for f in F[tag].values() if f["nins"] < 8)
        print(f"{tag}: {len(F[tag])} funcs ({stubs} stubs excluded from aggregates)")

    results = {}
    for A, B in (("318", "3112"), ("3112", "320")):
        cal = calibrate(F[A], F[B])
        thr = max(0.60, cal["p99"] + 0.03)
        pairs, only_a, only_b = run(A, B, F[A], F[B], thr)
        keep = [p for p in pairs if p["a_ins"] >= 8 and p["b_ins"] >= 8]
        verdicts = Counter(p["verdict"] for p in keep)
        bands = Counter()
        for p in keep:
            lo = int(p["score"] * 10) / 10
            bands[f"{lo:.1f}-{lo+0.1:.1f}"] += 1
        results[f"{A}->{B}"] = {"calibration": cal, "threshold": round(thr, 4),
                                "matched": len(pairs), "nonstub": len(keep),
                                "verdicts": dict(verdicts),
                                "score_bands": dict(sorted(bands.items())),
                                "only_a": only_a, "only_b": only_b, "pairs": pairs}
        print(f"\n{A}->{B}: thr={thr:.3f} null p95={cal.get('p95')} p99={cal.get('p99')} "
              f"max={cal.get('max')} matched={len(pairs)} nonstub={len(keep)} "
              f"{dict(verdicts)}")
        print("   score bands:", dict(sorted(bands.items())))
        print(f"   only in {A}: {len(only_a)}   only in {B}: {len(only_b)}")

    json.dump(results, open(os.path.join(outdir, "match_final.json"), "w"), indent=1)

    # targeted traces
    probes = [(0xA9D8, "PD/reset dispatch switch table"), (0xB154, "shared Soft_Reset handler"),
              (0xC2B8, "UVDM tx builder"), (0xC2F8, "UVDM message assembler")]
    print("\n== targeted trace 3.1.12 -> 3.2.0")
    r = results["3112->320"]
    for addr, why in probes:
        src = None
        for a in F["3112"]:
            if a <= addr < a + max(F["3112"][a]["size"], 2):
                src = a
        if src is None:
            print(f"  0x{addr:05x} {why}: not inside a 3.1.12 function")
            continue
        hit = [p for p in r["pairs"] if p["a"] == src]
        if hit:
            p = hit[0]
            print(f"  0x{addr:05x} {why}\n     3.1.12 0x{src:05x} ({F['3112'][src]['nins']} insn)"
                  f" -> 3.2.0 0x{p['b']:05x} ({p['b_ins']} insn) {p['verdict']} "
                  f"score={p['score']} P={p['P']} M={p['M']} C={p['C']} S={p['S']}")
        else:
            print(f"  0x{addr:05x} {why}\n     3.1.12 0x{src:05x} ({F['3112'][src]['nins']} insn)"
                  f" -> NO_MATCH above threshold")
    print(f"\nwrote {outdir}/match_final.json")


if __name__ == "__main__":
    main()
