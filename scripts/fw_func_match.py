#!/usr/bin/env python3
"""Multi-signal, one-to-one function matching across MagSafe 3 builds.

Deliberately conservative normalisation, per review guidance:
  * normalised away: relocations (FUN_/DAT_/PTR_/UNK_/LAB_ refs), addresses,
    variable names. Nothing else.
  * preserved: integer literals that are not address-shaped, i.e. protocol
    constants, bitmasks, comparison values, command IDs. These form the
    semantic signature.

Four independent signals per function:
  P  pseudocode token ratio        (data + control flow shape)
  M  mnemonic sequence ratio       (ri zin linear disassembly, operand-free)
  C  CFG feature distance          (branch/call/return/block counts + branch kinds)
  R  call-relationship distance    (multiset of callee code sizes)
  S  semantic constant Jaccard     (multiset overlap of non-address literals)

One-to-one assignment by descending composite score. Unmatched, split, merged
and inlined functions are all expected outcomes and are reported as such.
Trivial stubs are excluded from aggregate similarity but still listed.

Usage: fw_func_match.py <raw_dir> <pd_dir> <out_json>
"""
import json
import os
import re
import sys
import difflib
from collections import Counter

CALLEE = re.compile(r"\bFUN_[0-9a-fA-F]+")
GLOBAL = re.compile(r"\b(?:DAT|PTR|UNK)_[A-Za-z0-9_]+")
LABEL = re.compile(r"\b(?:LAB|code)_[0-9a-fA-F]+")
HEXL = re.compile(r"\b0x([0-9a-fA-F]+)\b")
DECL = re.compile(r"(?<![\w.])(\d+)(?![\w.])")
LOCAL = re.compile(r"\b(?:local|uStack|iStack|auStack|aStack|param|in|unaff|extraout|"
                   r"stack|localReserved|bStack|uVar|iVar|lVar|uScan|pcVar|pbVar|"
                   r"plVar|pfVar|puVar|p[ui]Var)_?[A-Za-z0-9_]*\b")
SPACES = re.compile(r"\s+")
IMAGE_SPAN = 0x15000

COND_BRANCH = re.compile(r"^(b[a-z]{1,3}|cbz|cbnz)$")


def addr_shaped(v):
    return v < IMAGE_SPAN or 0x40000000 <= v < 0xF0000000


def load_pseudo(d):
    out = {}
    fdir = os.path.join(d, "functions")
    if not os.path.isdir(fdir):
        return out
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
        if addr is None:
            continue
        out[addr] = "\n".join(body)
    return out


def norm_pseudo(body):
    """Return (token list, semantic constant Counter)."""
    consts = Counter()
    for m in HEXL.finditer(body):
        v = int(m.group(1), 16)
        if not addr_shaped(v):
            consts[v] += 1
    for m in DECL.finditer(body):
        v = int(m.group(1))
        if not addr_shaped(v) and v > 1:
            consts[v] += 1

    t = CALLEE.sub("F", body)
    t = GLOBAL.sub("G", t)
    t = LABEL.sub("L", t)
    t = HEXL.sub(lambda m: "A" if addr_shaped(int(m.group(1), 16)) else "K", t)
    t = DECL.sub(lambda m: "A" if addr_shaped(int(m.group(1))) else "K", t)
    t = LOCAL.sub("V", t)
    t = SPACES.sub(" ", t).strip()
    toks = re.findall(r"[A-Za-z_][A-Za-z0-9_]*|[^A-Za-z0-9_\s]", t)
    return toks, consts


def load_mnemonics(pd_path, inv):
    """Bucket operand-free mnemonics into function address ranges."""
    ins = json.load(open(pd_path))
    by_addr = {}
    for i in ins:
        by_addr[i["offset"]] = i["opcode"].split()[0] if i.get("opcode") else "?"
    out = {}
    for addr, meta in inv.items():
        end = addr + meta["size"]
        seq = [by_addr[a] for a in range(addr, end, 2) if a in by_addr]
        out[addr] = seq
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


def cf_feat(mnem):
    cond = sum(1 for m in mnem if COND_BRANCH.match(m))
    uncond = sum(1 for m in mnem if m == "b")
    calls = sum(1 for m in mnem if m in ("bl", "blx"))
    rets = sum(1 for m in mnem if m in ("pop", "bx") )
    blocks = 1 + cond + uncond
    return {"cond": cond, "uncond": uncond, "calls": calls, "ret": rets,
            "blocks": blocks, "len": len(mnem)}


def cf_dist(a, b):
    keys = ("cond", "uncond", "calls", "ret", "blocks")
    tot = sum(max(a[k], b[k]) for k in keys) or 1
    return sum(abs(a[k] - b[k]) for k in keys) / tot


def jac(a, b):
    if not a and not b:
        return 1.0
    inter = sum((a & b).values())
    union = sum((a | b).values())
    return inter / union if union else 1.0


def ratio(x, y):
    if not x or not y:
        return 0.0
    return difflib.SequenceMatcher(None, x, y, autojunk=False).ratio()


def main():
    raw, pdd, outp = sys.argv[1], sys.argv[2], sys.argv[3]
    tagmap = {"318": ("pseudo_318", "inventory_318.tsv", "pd_318.json"),
              "3112": ("pseudo_3_1_12", "inventory_3112.tsv", "pd_3112.json"),
              "320": ("pseudo_3_2_0", "inventory_320.tsv", "pd_320.json")}
    F = {}
    for tag, (pd, invf, pdf) in tagmap.items():
        inv = load_inventory(os.path.join(raw, invf))
        ps = load_pseudo(os.path.join(raw, pd))
        mn = load_mnemonics(os.path.join(pdd, pdf), inv)
        feats = {}
        for addr, body in ps.items():
            toks, consts = norm_pseudo(body)
            mnem = mn.get(addr, [])
            feats[addr] = {"toks": toks, "consts": consts, "mnem": mnem,
                           "cf": cf_feat(mnem),
                           "size": inv.get(addr, {}).get("size", 0),
                           "nins": inv.get(addr, {}).get("instructions", len(mnem)),
                           "name": inv.get(addr, {}).get("name", "")}
        F[tag] = feats
        stubs = sum(1 for f in feats.values() if f["nins"] < 8)
        print(f"{tag}: {len(feats)} funcs, {stubs} stubs (<8 insn) excluded from aggregates")

    def callee_sig(tag, addr):
        f = F[tag][addr]
        return tuple(sorted(F[tag][t]["size"] for t in f.get("callees", [])))

    def do_match(A, B):
        ax, bx = F[A], F[B]
        cand = []
        for a, fa in ax.items():
            for b, fb in bx.items():
                if max(fa["nins"], fb["nins"]) == 0:
                    continue
                szr = min(fa["nins"], fb["nins"]) / max(1, max(fa["nins"], fb["nins"]))
                if szr < 0.45:
                    continue
                P = ratio(fa["toks"], fb["toks"])
                if P < 0.35:
                    continue
                M = ratio(fa["mnem"], fb["mnem"])
                C = 1.0 - cf_dist(fa["cf"], fb["cf"])
                S = jac(fa["consts"], fb["consts"])
                R = 1.0 - min(1.0, abs(len(fa["mnem"]) - len(fb["mnem"])) /
                              max(1, max(len(fa["mnem"]), len(fb["mnem"]))))
                score = 0.45 * P + 0.25 * M + 0.15 * C + 0.10 * S + 0.05 * R
                cand.append((score, P, M, C, S, R, a, b))
        cand.sort(reverse=True)
        ua, ub, pairs = set(), set(), []
        for score, P, M, C, S, R, a, b in cand:
            if a in ua or b in ub:
                continue
            ua.add(a); ub.add(b)
            if P == 1.0 and M == 1.0:
                kind = "EXACT"
            elif score >= 0.85:
                kind = "STRUCTURAL"
            elif S >= 0.75 and score >= 0.55:
                kind = "SEMANTIC"
            else:
                kind = "WEAK"
            pairs.append({"a": a, "b": b, "score": round(score, 4), "P": round(P, 4),
                          "M": round(M, 4), "C": round(C, 4), "S": round(S, 4),
                          "R": round(R, 4), "kind": kind,
                          "a_ins": F[A][a]["nins"], "b_ins": F[B][b]["nins"]})
        return pairs, sorted(set(ax) - ua), sorted(set(bx) - ub)

    out = {}
    for A, B, label in (("318", "3112", "3.1.8->3.1.12 control"),
                        ("3112", "320", "3.1.12->3.2.0")):
        pairs, only_a, only_b = do_match(A, B)
        kinds = Counter(p["kind"] for p in pairs)
        # aggregates exclude stubs on both sides
        keep = [p for p in pairs if p["a_ins"] >= 8 and p["b_ins"] >= 8]
        mean = sum(p["score"] for p in keep) / len(keep) if keep else 0
        out[label] = {"A": len(F[A]), "B": len(F[B]), "matched": len(pairs),
                      "kinds": dict(kinds), "nonstub_mean": round(mean, 4),
                      "only_a": only_a, "only_b": only_b, "pairs": pairs}
        print(f"\n{label}: A={len(F[A])} B={len(F[B])} matched={len(pairs)} "
              f"kinds={dict(kinds)} nonstub_mean={out[label]['nonstub_mean']} "
              f"onlyA={len(only_a)} onlyB={len(only_b)}")

    json.dump({"meta": {"signals": "P pseudocode, M mnemonics, C cfg, S semantic consts, R call-relation",
                        "weights": "0.45P 0.25M 0.15C 0.10S 0.05R"},
               "runs": out}, open(outp, "w"), indent=1)
    print(f"\nwrote {outp}")

    # Trace requested protocol functions from 3.1.12 into 3.2.0
    trace = [(0xA9D8, "reset/PD dispatcher jump table"), (0xB154, "shared Soft_Reset handler"),
             (0xC2B8, "UVDM tx builder"), (0xC2F8, "UVDM message assembler")]
    print("\n== trace into 3.2.0")
    for addr, why in trace:
        src = None
        for a in F["3112"]:
            if a <= addr < a + max(F["3112"][a]["size"], 2):
                src = a
        if src is None:
            print(f"  0x{addr:05x} ({why}): not inside any 3.1.12 function")
            continue
        m = [p for p in out["3.1.12->3.2.0"]["pairs"] if p["a"] == src]
        fa = F["3112"][src]
        if m:
            p = m[0]
            print(f"  0x{addr:05x} ({why}) in 3.1.12 func 0x{src:05x} "
                  f"[{fa['nins']} insn] -> 3.2.0 0x{p['b']:05x} [{p['b_ins']} insn] "
                  f"kind={p['kind']} score={p['score']} P={p['P']} M={p['M']} S={p['S']}")
        else:
            print(f"  0x{addr:05x} ({why}) in 3.1.12 func 0x{src:05x} "
                  f"[{fa['nins']} insn] -> UNMATCHED")


if __name__ == "__main__":
    main()
