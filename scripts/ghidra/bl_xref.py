#!/usr/bin/env python3
"""Thumb BL xref map + prologue candidates for flat MagSafe A2363 images.

Decodes every 32-bit Thumb BL in the image (fixed encoding pattern), builds a
call-target -> callers map, and pairs it with push{...,lr} prologue candidates.
Addresses are FILE OFFSETS (base-0 import). Output: JSON xref map.

Usage: bl_xref.py <image.bin> <out.json>
"""
import json, struct, sys

path, out = sys.argv[1], sys.argv[2]
data = open(path, "rb").read()

def bl_target(hw1, hw2, pc):
    # hw1: 11110 S imm10 ; hw2: 11 J1 J2 imm11
    if (hw1 & 0xF800) != 0xF000 or (hw2 & 0xD000) != 0xD000:
        return None
    S = (hw1 >> 10) & 1
    imm10 = hw1 & 0x3FF
    J1 = (hw2 >> 13) & 1
    J2 = (hw2 >> 11) & 1
    imm11 = hw2 & 0x7FF
    I1 = ~(J1 ^ S) & 1
    I2 = ~(J2 ^ S) & 1
    imm32 = (S << 24) | (I1 << 23) | (I2 << 22) | (imm10 << 12) | (imm11 << 1)
    if S:
        imm32 -= 1 << 25
    return (pc + 4 + imm32) & 0xFFFFFFFF

def wide_branch(hw1, hw2, pc):
    # T3/T4: 11110 S imm10 cond|10J1J2 imm11 -> return target or None
    if (hw1 & 0xF800) != 0xF000:
        return None
    S = (hw1 >> 10) & 1
    imm10 = hw1 & 0x3FF
    J1 = (hw2 >> 13) & 1
    J2 = (hw2 >> 11) & 1
    I1 = ~(J1 ^ S) & 1
    I2 = ~(J2 ^ S) & 1
    if (hw2 & 0xD000) == 0xD000:      # BL (handled elsewhere)
        return None
    imm11 = hw2 & 0x7FF
    imm32 = (S << 24) | (I1 << 23) | (I2 << 22) | (imm10 << 12) | (imm11 << 1)
    if S:
        imm32 -= 1 << 25
    return (pc + 4 + imm32) & 0xFFFFFFFF

callers = {}       # target -> [call sites]
n_ins = 0
for off in range(0, len(data) - 4, 2):
    hw1, = struct.unpack_from("<H", data, off)
    if (hw1 & 0xF800) != 0xF000:
        continue
    hw2, = struct.unpack_from("<H", data, off + 2)
    t = bl_target(hw1, hw2, off) or wide_branch(hw1, hw2, off)
    if t is None or t >= len(data):
        continue
    callers.setdefault(t, []).append(off)
    n_ins += 1

# prologue candidates: halfword 0xB5xx (push with LR) at even offsets
pros = []
for off in range(0, len(data), 2):
    hw, = struct.unpack_from("<H", data, off)
    if (hw & 0xFF00) == 0xB500 and hw != 0xB500:
        pros.append(off)

bl_targets = sorted(callers)
res = {
    "image": path,
    "bl_count": n_ins,
    "bl_targets": ["0x%x" % t for t in bl_targets],
    "callers": {"0x%x" % t: ["0x%x" % c for c in cs] for t, cs in sorted(callers.items())},
    "prologues": ["0x%x" % p for p in pros],
}
json.dump(res, open(out, "w"), indent=0)
print("bl_sites=%d distinct_targets=%d prologues=%d" % (n_ins, len(bl_targets), len(pros)))
