#!/usr/bin/env python3
"""Build the seeded-pipeline seed files for 3.1.12 and 3.2.0.

Rules applied (same as the validated 3.1.8 run):
  * start from the census-derived seed list (site + case targets);
  * drop the reset-vector word at 0x10 (a pointer word, not code);
  * drop every seed whose default-analysis listing proves it is a jump-table
    data word, a literal/constant-pool word, or the interior of an existing
    instruction (classification recorded in findings.md);
  * add the switch-enclosing function entry as a precise clear seed,
    ',clear,1,data', only where the default-analysis listing shows a 1-byte
    data unit sitting on a decodable `push {...,lr}` prologue.
"""
import os

REPO = "/Users/sein/.hermes/artifacts/apple-power-firmware"
OUT = os.path.join(REPO, "evidence/magsafe-cortexm/delegated/xversion")

EXCLUDE = {
    "3.1.12": {
        0x10: "reset vector word 0x00010ffd (4-byte data)",
        0x2c6a: "interior of 4-byte word at 0x2c68 (literal pool after epilogue)",
        0x2c78: "4-byte literal-pool word (case target points into pool)",
        0x3b72: "interior of bl at 0x3b70",
        0x3dca: "interior of bl at 0x3dc8",
        0x59c4: "interior of bl at 0x59c2",
        0x5a72: "interior of bl at 0x5a70",
        0x9adc: "interior of bl at 0x9ada",
        0x9ae8: "interior of bl at 0x9ae6",
        0xe7a4: "constant-pool word in 0xe798 block",
    },
    "3.2.0": {
        0x10: "reset vector word 0x0001111d (4-byte data)",
        0x3c20: "entry of a 16-bit constant table (0x30,0x3b,0x58,0x85,0x89,0x16b...), data len=2",
        0xe9a0: "constant-pool word in 0xe998 block",
        # interior switch sites / case bodies inside the verified enclosing
        # functions 0x4b78 and 0x50fc: seeding them as function entries splits
        # the body into fragments (measured: 0x4b78 body shrank to 26 B).
        0x4b92: "mov pc site inside 0x4b78 (switch table 0x4b94)",
        0x4ee2: "mov pc site inside 0x4b78 (switch table 0x4ee4)",
        0x5166: "mov pc site inside 0x50fc (switch table 0x5168)",
        0x5034: "case body inside 0x4b78",
        0x5076: "case body inside 0x4b78",
        0x50ae: "case body inside 0x4b78",
        0x50d0: "case body inside 0x4b78",
    },
}

CLEARS = {
    "3.1.12": [(0xaa10, "push {r4,r5,r6,r7,lr}; guard subs r0,#9 / cmp r0,#0xd; table 0xaa2c")],
    "3.2.0": [
        (0x4b78, "push {r4,r5,r6,r7,lr}; contains 15-case table 0x4ee4 (guard ldrb [r0+1]-3 <= 0xe)"),
        (0x50fc, "push {r4,r5,r6,r7,lr}; contains 13-case table 0x5168 (guard subs r0,r1,#2 / cmp r0,#0xc)"),
    ],
}


def load(name):
    return [int(l.strip(), 16) for l in open(os.path.join(OUT, name)) if l.strip()]


for ver, src, dst in [("3.1.12", "seeds_3112.csv", "seeds3_3112.csv"),
                      ("3.2.0", "seeds_320.csv", "seeds3_320.csv")]:
    seeds = load(src)
    excl = EXCLUDE[ver]
    kept = [a for a in seeds if a not in excl]
    lines = ["0x%x,clear,1,data" % a for a, _ in CLEARS[ver]]
    lines += ["0x%x" % a for a in kept]
    with open(os.path.join(OUT, dst), "w") as fh:
        fh.write("\n".join(lines) + "\n")
    print(ver, "census", len(seeds), "dropped", len(seeds) - len(kept),
          "kept", len(kept), "clears", len(CLEARS[ver]), "entries", len(lines))
    for a, why in sorted(excl.items()):
        print("   drop 0x%x  %s" % (a, why))
