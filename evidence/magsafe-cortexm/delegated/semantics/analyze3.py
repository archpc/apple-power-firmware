#!/usr/bin/env python3
"""Pass 3 -- final classification + literal cross-check (supersedes pass 2).

Fixes pass 2's operand field splitter: rizin prints immediates WITHOUT '#' for
Thumb `movs/adds rX, 0xNN`, so those were landing in the "enc" bucket. Memory
operands are now stripped before immediates are collected, and the effective
base register / displacement of a memory operand are separated.

Also performs the required constant-level cross-check two ways:
  A) raw word scan: 4-byte-aligned words inside the body range that are
     >= image length (literal-pool image pointers excluded by construction);
     words in 0x2000_0000..0x2008_0000 are counted separately because SRAM
     data/bss addresses relocate between builds -- a known confound.
  B) decoded-operand constants: values that reach an instruction as an
     immediate or a memory displacement (decoder, not byte pattern).

Writes pairs_final.json and windows12.json.
"""
import json, os, re, subprocess, collections, difflib, sys

REPO = "/Users/sein/.hermes/artifacts/apple-power-firmware"
DELEG = os.path.join(REPO, "evidence/magsafe-cortexm/delegated")
OUT = os.path.join(DELEG, "semantics")
IMG = {"3112": os.path.join(REPO, "firmware/images/A2363_3.1.12_10M1543_base0.bin"),
       "320": os.path.join(REPO, "firmware/images/A2363_3.2.0_10M13722_base0.bin")}
LEN = {k: os.path.getsize(v) for k, v in IMG.items()}
RAW = {k: open(v, "rb").read() for k, v in IMG.items()}
RIZIN = ["rizin", "-e", "scr.color=0", "-a", "arm", "-b", "16", "-q"]
REG = re.compile(r"\b(r(?:1[0-5]|[0-9])|sb|sl|fp|ip|sp|lr|pc)\b")
BRANCH = re.compile(r"^(b|bl|bx|blx|b[a-z]{1,2}|cbz|cbnz)$")
MEM = re.compile(r"\[[^\]]*\]")
HEX = re.compile(r"(?<![0-9a-z])0x[0-9a-f]+")


def pd(img, addr, n):
    out = subprocess.run(RIZIN + ["-c", "pdj %d @ %d" % (n, addr), IMG[img]],
                         capture_output=True, text=True, timeout=120).stdout.strip()
    return json.loads(out) if out else []


def fields(opcode):
    """mnemonic, regs, (base_regs, disps), imms, branch/call targets."""
    m = opcode.split()[0]
    ops = opcode[len(m):].strip()
    if BRANCH.match(m.rstrip("s")):
        return m, [], [], "", [], [h for h in HEX.findall(ops)]
    mem = MEM.findall(ops)
    disps, bases = [], []
    for x in mem:
        hm = HEX.findall(x)
        disps += hm
        bm = REG.findall(x)
        bases += bm[:1]
    outside = MEM.sub(" ", ops)
    imms = [h for h in HEX.findall(outside)]
    # registers: all register tokens, memory base registers already covered
    regs = REG.findall(ops)
    return m, regs, (bases, disps), imms, [], []


def pairdiff(a, b):
    ch = []
    for i, (x, y) in enumerate(zip(a, b)):
        if x["opcode"] == y["opcode"]:
            continue
        mx, rx, dx, ix, _, tx = fields(x["opcode"])
        my, ry, dy, iy, _, ty = fields(y["opcode"])
        kinds, extra = [], {}
        if mx != my:
            kinds.append("mnemonic")
        if tx != ty:
            kinds.append("target")
            extra["target"] = [tx, ty]
        if ix != iy:
            kinds.append("imm")
            extra["imm"] = [ix, iy]
        if dx != dy:
            kinds.append("field")
            extra["field"] = [dx, dy]
        if rx != ry:
            kinds.append("reg")
            extra["reg"] = [rx, ry]
        if not kinds:
            kinds.append("encoding")
        ch.append({"idx": i, "old": x["opcode"], "new": y["opcode"],
                   "old_off": hex(x["offset"]), "new_off": hex(y["offset"]),
                   "old_bytes": x["bytes"], "new_bytes": y["bytes"],
                   "kinds": kinds, **extra})
    return ch


def classify(ch):
    if not ch:
        return "identical_instructions"
    kinds = collections.Counter(k for c in ch for k in c["kinds"])
    semantic = {k: v for k, v in kinds.items() if k not in ("target", "encoding")}
    if not semantic:
        if kinds.get("encoding"):
            return "encoding_only"
        return "identical_modulo_target_relink"
    parts = sorted(semantic)
    if len(parts) == 1 and parts[0] == "field":
        return "field_offset_change"
    if len(parts) == 1 and parts[0] == "imm":
        return "immediate_change"
    if len(parts) == 1 and parts[0] == "reg":
        return "register_change"
    return "combined_" + "+".join(parts)


def word_scan(key, addr, size):
    data = RAW[key][addr:addr + size]
    c = collections.Counter()
    vals = []
    for off in range(0, len(data) - 3, 4):
        w = int.from_bytes(data[off:off + 4], "little")
        if w < LEN[key]:
            continue
        if 0x20000000 <= w < 0x20080000:
            c["sram_ptr"] += 1
        elif w >= 0x08000000 or (0x40000000 <= w < 0x60000000):
            c["mmio_or_flash_ptr"] += 1
        else:
            c["constant"] += 1
            vals.append(w)
    return c, sorted(vals)


def main():
    pairs = [p for p in json.load(open(os.path.join(DELEG, "matcher/results_calibrated.json")))
             ["pairs_3112_320"]["unique_1to1"] if p["n_3112"] >= 8]
    out = []
    for k, p in enumerate(pairs):
        a = pd("3112", int(p["a_3112"], 16), p["n_3112"])[:p["n_3112"]]
        b = pd("320", int(p["b_320"], 16), p["n_320"])[:p["n_320"]]
        rec = {"a_3112": p["a_3112"], "b_320": p["b_320"], "s": p["s"],
               "n_3112": p["n_3112"], "n_320": p["n_320"],
               "size_3112": p["size_3112"], "size_320": p["size_320"],
               "mnem_seq_equal": [i["opcode"].split()[0] for i in a] ==
                                 [i["opcode"].split()[0] for i in b],
               "invalid": [sum(1 for i in a if i["opcode"] == "invalid"),
                           sum(1 for i in b if i["opcode"] == "invalid")]}
        if rec["mnem_seq_equal"]:
            rec["changes"] = pairdiff(a, b)
        else:
            sm = difflib.SequenceMatcher(None, [i["opcode"].split()[0] for i in a],
                                         [i["opcode"].split()[0] for i in b], autojunk=False)
            rec["changes"] = []
            rec["windows"] = [(t, i1, i2, j1, j2) for t, i1, i2, j1, j2 in sm.get_opcodes()
                              if t != "equal"]
            rec["_a"], rec["_b"] = a, b
        rec["kind_counts"] = dict(collections.Counter(k2 for c in rec["changes"] for k2 in c["kinds"]))
        rec["class"] = classify(rec["changes"])
        # constant cross-check
        ca, va = word_scan("3112", int(p["a_3112"], 16), p["size_3112"])
        cb, vb = word_scan("320", int(p["b_320"], 16), p["size_320"])
        rec["words"] = {"old": dict(ca), "new": dict(cb),
                        "const_multiset_equal": va == vb,
                        "const_only_old": [hex(x) for x in va if x not in vb],
                        "const_only_new": [hex(x) for x in vb if x not in va]}
        out.append(rec)
        if (k + 1) % 40 == 0:
            print("...%d" % (k + 1), file=sys.stderr)
    agg = collections.Counter(r["class"] for r in out)
    print(json.dumps(dict(agg), indent=1, sort_keys=True))
    print("with decoded diff:", sum(1 for r in out if r["class"] != "identical_instructions"))
    print("field_offset:", sum(1 for r in out if r["class"] == "field_offset_change"),
          "imm:", sum(1 for r in out if r["class"] == "immediate_change"))
    print("const multiset differs:", sum(1 for r in out if not r["words"]["const_multiset_equal"]))
    for r in out:
        r.pop("_a", None); r.pop("_b", None)
        r["windows"] = [list(w) for w in r.get("windows", [])]
    json.dump({"pairs": out, "class_counts": dict(agg),
               "img_len": LEN}, open(os.path.join(OUT, "pairs_final.json"), "w"), indent=1)
    print("--- semantic-change pairs (excluding relink/encoding/identical) ---")
    for r in out:
        if r["class"].startswith(("field", "imm", "reg", "comb", "instr")):
            print(r["a_3112"], r["b_320"], r["class"], r["kind_counts"])


if __name__ == "__main__":
    main()
