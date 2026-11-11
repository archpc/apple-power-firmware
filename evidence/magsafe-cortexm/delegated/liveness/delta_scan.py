#!/usr/bin/env python3
"""Task 1 (v2): delta / offset-table reference scan.

Two tests, both against 32-bit little-endian words at every 2-byte offset.

TEST A -- word-pair difference ("offset table" test, low false-positive):
    find words W1 @p1, W2 @p2 with W1 - W2 == E  (E = island entry, and E|1).
    A relocation/addend table that stores base and base+delta in the same
    table produces exactly this. Reported with both offsets.

TEST B -- anchored base+delta (curated anchors only):
    W == E - X where X is a *legitimate anchor*: a Ghidra function start, a
    BL/B.W branch target, or a known island block start.  |W| <= 0x14608.
    Arbitrary interior bytes are NOT accepted as anchors (that produced
    random hits in v1: 12596 "hits" for 0x13088 vs 0x86cc, all coincidence).

Also reports, for each target, whether *any* word in the image equals E or
E|1 exactly (a plain pointer), as a control.
"""
import json, struct

IMG = "firmware/images/A2363_3.1.8_10M569_base0.bin"
INV = "evidence/magsafe-cortexm/inventory3_318.json"
BLX = "evidence/magsafe-cortexm/bl_xref_318.json"
BRX = "evidence/magsafe-cortexm/br_xref_318.json"
OUT = "evidence/magsafe-cortexm/delegated/liveness/delta_scan.json"

data = open(IMG, "rb").read()
N = len(data)
words = {}
for p in range(0, N - 3, 2):
    words.setdefault(struct.unpack_from("<I", data, p)[0], []).append(p)

funcs = json.load(open(INV))
anchors = set(int(f["addr"], 16) for f in funcs)


def collect_targets(path):
    out = set()
    try:
        d = json.load(open(path))
    except Exception:
        return out
    keynames = {"target", "dst", "to", "dest", "dst_addr", "target_addr"}

    def walk(o):
        if isinstance(o, dict):
            for k, v in o.items():
                if k in keynames and isinstance(v, (int, str)):
                    try:
                        out.add(int(v, 16) if isinstance(v, str) else int(v))
                    except Exception:
                        pass
                walk(v)
        elif isinstance(o, list):
            for v in o:
                walk(v)

    walk(d)
    return out


anchors |= collect_targets(BLX)
anchors |= collect_targets(BRX)
ISLAND_STARTS = {0xa9bc, 0xa9d8, 0xaa10, 0xaed0, 0xae90, 0xb154, 0xaf08, 0xaf50,
                 0xaf72, 0xaf80, 0x10ac0, 0x10b30, 0x10f50, 0x10f70, 0x10fc0,
                 0x1128, 0x12012, 0x1291c, 0x12938, 0x1297c, 0x12988, 0x129c8}
anchors |= ISLAND_STARTS

TARGETS = [
    ("dispatcher 0xa9bc", 0xa9bc),
    ("disp table 0xa9d8", 0xa9d8),
    ("big island 0x10ac0", 0x10ac0),
    ("big island 0x10b30", 0x10b30),
    ("island blk 0x10fc0", 0x10fc0),
    ("island blk 0x1128", 0x1128),
    ("island blk 0x12012", 0x12012),
    ("island lease 0x12938", 0x12938),
    ("island last 0x129c8", 0x129c8),
]

report = {"anchors": len(anchors), "words_unique": len(words), "tests": {}}
for label, E in TARGETS:
    r = {}
    r["exact_word_E"] = [hex(p) for e in (E, E | 1) for p in words.get(e, [])]
    pairs = []
    for W2, ps2 in words.items():
        W1 = W2 + E
        if W1 not in words:
            continue
        if W1 > N or W2 > N:
            continue            # both operands must be plausible in-image addresses
        for p1 in words[W1]:
            for p2 in ps2:
                if abs(p1 - p2) <= 0x400:      # co-located: same table/record
                    pairs.append([hex(p1), hex(W1), hex(p2), hex(W2)])
    r["pair_diff"] = pairs
    hits = []
    for X in anchors:
        for E2 in (E, E | 1):
            W = E2 - X
            if W <= 0 or W > 0x14608:
                continue
            for p in words.get(W, []):
                hits.append({"word_off": hex(p), "word": hex(W), "anchor_X": hex(X)})
    r["anchored_delta"] = hits
    report["tests"][label] = r
    print(f"== {label}: exact={len(r['exact_word_E'])} pairs={len(pairs)} anchored={len(hits)}")
    for x in r["exact_word_E"][:6]:
        print("   exact word @", x)
    for x in pairs[:8]:
        print("   PAIR", x)
    for x in hits[:8]:
        print("   ANCH", x)

json.dump(report, open(OUT, "w"), indent=1)
