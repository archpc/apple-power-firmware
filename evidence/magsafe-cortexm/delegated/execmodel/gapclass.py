#!/usr/bin/env python3
"""Classify uncovered byte ranges in the A2363 3.1.8 image as data vs plausible code.

Inputs: seeds3-derived inventory (addr+size), bl_xref prologue/BL map.
Method per range:
  - prologue candidates (push {...,lr}) inside the range
  - BL targets inside the range
  - for each prologue candidate, decode up to 64 instructions with rizin and ask
    whether it is a coherent body (no 'invalid' before a return/unconditional branch)
  - printable ASCII runs >= 8 and pointer-word density as data signals
Addresses are FILE OFFSETS (base-0).
"""
import json, re, subprocess, struct, sys

ROOT = "/Users/sein/.hermes/artifacts/apple-power-firmware"
IMG = ROOT + "/firmware/images/A2363_3.1.8_10M569_base0.bin"
d = open(IMG, "rb").read()
inv = json.load(open(ROOT + "/evidence/magsafe-cortexm/inventory3_318.json"))
bx = json.load(open(ROOT + "/evidence/magsafe-cortexm/bl_xref_318.json"))
rng = sorted((int(f["addr"], 16), int(f["addr"], 16) + f["size"], f["name"]) for f in inv)
pro = sorted(int(p, 16) for p in bx["prologues"])
tgt = set(int(p, 16) for p in bx["bl_targets"])

gaps, cur = [], 0
for a, b, n in rng:
    if a > cur:
        gaps.append((cur, a))
    cur = max(cur, b)
if cur < len(d):
    gaps.append((cur, len(d)))
gaps = [g for g in gaps if g[1] > g[0]]


def dec(addr, n=64):
    p = subprocess.run(["rizin", "-a", "arm", "-b", "16", "-q", "-e", "scr.color=0",
                        "-c", "s 0x%x; pd %d" % (addr, n), IMG],
                       capture_output=True, text=True, errors="replace")
    out = []
    for line in p.stdout.splitlines():
        m = re.search(r"0x([0-9a-f]{8})\s+(.*)$", line)
        if m:
            out.append((int(m.group(1), 16), m.group(2).strip()))
    return out


def coherent(addr):
    ins = dec(addr)
    if not ins or not ins[0][1].startswith("push"):
        return False, "not-a-push-start"
    for a, t in ins[1:]:
        if t == "invalid":
            return False, "invalid@0x%x" % a
        if t.startswith("pop") and "pc" in t:
            return True, "pop-pc@0x%x" % a
        if t.startswith("bx") and "lr" in t:
            return True, "bx-lr@0x%x" % a
        if t.startswith("b ") and "0x" in t:
            return True, "b@0x%x" % a
    return False, "no-terminator-within-64"


def classify(a, b):
    seg = d[a:b]
    pr = [x for x in pro if a <= x < b]
    tg = [x for x in tgt if a <= x < b]
    runs = [m.group(0) for m in re.finditer(rb"[ -~]{8,}", seg)]
    words = [struct.unpack_from("<I", d, x)[0] for x in range(a, b - 3, 4)]
    ptr = sum(1 for v in words if 0x20000000 <= v < 0x20040000 or 0xe000e000 <= v < 0xe0010000
              or 0x40000000 <= v < 0x60000000)
    ok = []
    for p in pr:
        good, why = coherent(p)
        if good:
            ok.append((p, why))
    if ok:
        verdict = "CODE-plausible"
    elif runs and len(runs) >= 3:
        verdict = "DATA-strings"
    elif ptr and ptr * 4 >= (b - a) * 0.40:
        verdict = "DATA-pointer-table"
    elif pr:
        verdict = "DATA-prologue-false-positive"
    else:
        verdict = "DATA-other"
    return dict(start=a, end=b, length=b - a, prologues=[hex(x) for x in pr],
                coherent=[(hex(p), w) for p, w in ok], bl_targets=[hex(x) for x in tg],
                ascii_runs=len(runs), ascii_sample=[r[:48].decode("ascii", "replace") for r in runs[:3]],
                ptr_words=ptr, verdict=verdict)


tops = sorted(gaps, key=lambda g: g[1] - g[0], reverse=True)[:12]
res = [classify(a, b) for a, b in tops]
tot_gap = sum(b - a for a, b in gaps)
print("gaps=%d  uncovered_bytes=%d (%.2f%% of %d)" % (len(gaps), tot_gap, 100 * tot_gap / len(d), len(d)))
for r in res:
    print("0x%05x..0x%05x len=%5d %-26s pro=%d coherent=%d bl=%d ascii=%d ptr=%d"
          % (r["start"], r["end"], r["length"], r["verdict"], len(r["prologues"]),
             len(r["coherent"]), len(r["bl_targets"]), r["ascii_runs"], r["ptr_words"]))
    if r["coherent"]:
        print("     coherent:", r["coherent"][:4])
    if r["ascii_sample"]:
        print("     strings:", r["ascii_sample"])
json.dump(res, open("/Users/sein/gp_execmodel/gapclass318.json", "w"), indent=1)
