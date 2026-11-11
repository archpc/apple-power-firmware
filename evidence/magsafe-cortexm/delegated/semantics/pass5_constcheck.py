#!/usr/bin/env python3
"""Pass 5 -- decoded constant cross-check, syntax-based (corrects pass 4).

Pass 4 filtered constants by value (v >= image length) to exclude literal-pool
image pointers, which silently discarded every *small* immediate (0x20, 0x28,
0x38, 0x40, 0x60 ...) because a 4-byte value below 0x14850 is indistinguishable
from an in-image address by value alone. That is the wrong filter for decoded
operands: an immediate is identified by syntax (bare hex outside a memory
operand), not by magnitude. This pass splits:

  imm   -- hex literal on a non-branch, non-memory operand  (true immediate)
  disp  -- hex displacement inside [...]                    (struct field offset)

and compares the multisets per pair. Branch/call targets are excluded entirely
(they are relink artefacts). Values are NOT filtered by magnitude; the only
pointer confusion left is a pool-loaded 32-bit constant used as an address,
which cannot appear here because pool loads are `ldr rX,[pc,#off]` (the word is
in the pool, not in an operand).
"""
import json, os, re, subprocess, collections

REPO = "/Users/sein/.hermes/artifacts/apple-power-firmware"
DELEG = os.path.join(REPO, "evidence/magsafe-cortexm/delegated")
OUT = os.path.join(DELEG, "semantics")
IMG = {"3112": os.path.join(REPO, "firmware/images/A2363_3.1.12_10M1543_base0.bin"),
       "320": os.path.join(REPO, "firmware/images/A2363_3.2.0_10M13722_base0.bin")}
RIZIN = ["rizin", "-e", "scr.color=0", "-a", "arm", "-b", "16", "-q"]
BRANCH = re.compile(r"^(b|bl|bx|blx|b[a-z]{1,2}|cbz|cbnz)$")
MEM = re.compile(r"\[[^\]]*\]")
HEX = re.compile(r"(?<![0-9a-z])0x[0-9a-f]+")

meta = {p["a_3112"]: p for p in json.load(open(os.path.join(DELEG, "matcher/results_calibrated.json")))
        ["pairs_3112_320"]["unique_1to1"] if p["n_3112"] >= 8}


def pd(img, addr, n):
    out = subprocess.run(RIZIN + ["-c", "pdj %d @ %d" % (n, addr), IMG[img]],
                         capture_output=True, text=True, timeout=120).stdout.strip()
    return json.loads(out) if out else []


def split(opcode):
    m = opcode.split()[0]
    if BRANCH.match(m.rstrip("s")):
        return [], []
    ops = opcode[len(m):]
    imm = [int(h, 16) for h in HEX.findall(MEM.sub(" ", ops))]
    disp = [int(h, 16) for x in MEM.findall(ops) for h in HEX.findall(x)]
    return imm, disp


def main():
    imm_diff, disp_diff, both = [], [], []
    cls = {p["a_3112"]: p for p in json.load(open(os.path.join(OUT, "results_pair_class.json")))["pairs"]}
    for a, p in meta.items():
        A = pd("3112", int(p["a_3112"], 16), p["n_3112"])[:p["n_3112"]]
        B = pd("320", int(p["b_320"], 16), p["n_320"])[:p["n_320"]]
        ia, da = collections.Counter(), collections.Counter()
        ib, db = collections.Counter(), collections.Counter()
        for i in A:
            x, y = split(i["opcode"]); ia.update(x); da.update(y)
        for i in B:
            x, y = split(i["opcode"]); ib.update(x); db.update(y)
        rec = {"a": a, "b": p["b_320"],
               "imm_only_old": [hex(v) for v in sorted(set(ia) - set(ib))],
               "imm_only_new": [hex(v) for v in sorted(set(ib) - set(ia))],
               "disp_only_old": [hex(v) for v in sorted(set(da) - set(db))],
               "disp_only_new": [hex(v) for v in sorted(set(db) - set(da))]}
        if rec["imm_only_old"] or rec["imm_only_new"]:
            imm_diff.append(rec)
        if rec["disp_only_old"] or rec["disp_only_new"]:
            disp_diff.append(rec)
    json.dump({"imm_diff": imm_diff, "disp_diff": disp_diff},
              open(os.path.join(OUT, "constcheck.json"), "w"), indent=1)
    print("imm multiset differs: %d / 155" % len(imm_diff))
    for r in imm_diff:
        print("   ", r["a"], r["b"], cls[r["a"]]["class"], "old", r["imm_only_old"], "new", r["imm_only_new"])
    print("disp multiset differs: %d / 155" % len(disp_diff))
    for r in disp_diff:
        print("   ", r["a"], r["b"], cls[r["a"]]["class"], "old", r["disp_only_old"], "new", r["disp_only_new"])


if __name__ == "__main__":
    main()
