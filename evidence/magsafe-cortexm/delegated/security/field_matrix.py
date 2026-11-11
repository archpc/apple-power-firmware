#!/usr/bin/env python3
"""Exhaustive field-match matrix over structural boundaries (offline evidence).

Boundaries are taken only from values that appear in the file itself:
0, 4, 8, 0xc, 0x2c(=BE 0x20), 0x30, 0x50, 0x9c, 0xa0, 0xc0, 0xe0, 0x100,
0x104, 0x108, 0x10c, 0x110, 0x130, 0x160, 0x170, 0x17c, 0x180, 0x180+len,
L, plus the tail-record boundaries 0x180+len+0x80 and 0x180+len+0x80+0x8d4.
"""
import hashlib, zlib

FIELDS32 = [0x0c, 0x30, 0xa0, 0xc0, 0xe0, 0x110]
U32 = [0x100, 0x104, 0x108, 0x10c, 0x9c]

for v in ["3.1.8_10M569", "3.1.12_10M1543", "3.2.0_10M13722"]:
    d = open(f"firmware/payload_{v}.bin", "rb").read()
    L = len(d)
    lenf = int.from_bytes(d[0x100:0x104], "little")
    tail = 0x180 + lenf
    tl = int.from_bytes(d[tail:tail+4], "little")
    B = sorted({0, 4, 8, 0xc, 0x2c, 0x30, 0x50, 0x9c, 0xa0, 0xc0, 0xe0,
                0x100, 0x104, 0x108, 0x10c, 0x110, 0x130, 0x17c, 0x180,
                tail, tail + 4, tail + 8, tail + 0x10, tail + 0x20,
                tail + 0x80, tail + 0x80 + tl, L})
    B = [b for b in B if 0 <= b <= L]
    print(f"== {v}  L={L:#x} lenf={lenf:#x} tail@{tail:#x} taillen={tl:#x} "
          f"tailhdr_end={tail+0x80:#x} tailbody_end={tail+0x80+tl:#x}")
    hits = 0
    for i, a in enumerate(B):
        for b in B[i+1:]:
            blob = d[a:b]
            for kind, dg in (("sha256", hashlib.sha256(blob).digest()),
                             ("sha1", hashlib.sha1(blob).digest()),
                             ("crc32le", (zlib.crc32(blob) & 0xFFFFFFFF).to_bytes(4, "little")),
                             ("crc32be", (zlib.crc32(blob) & 0xFFFFFFFF).to_bytes(4, "big"))):
                for f in FIELDS32:
                    if d[f:f+32] == dg:
                        print(f"   MATCH  {kind}(payload[{a:#x}:{b:#x}]) == field[{f:#x}]")
                        hits += 1
                for u in U32:
                    if d[u:u+4] == dg:
                        print(f"   MATCH  {kind}(payload[{a:#x}:{b:#x}]) == u32[{u:#x}]")
                        hits += 1
    # tail-record internal fields
    print(f"   tail record: len@{tail}={tl:#x} ({tl}), f4={d[tail+4:tail+8].hex()},"
          f" f8={d[tail+8:tail+12].hex()} crc?={int.from_bytes(d[tail+8:tail+12],'little'):#x},"
          f" f12={int.from_bytes(d[tail+12:tail+16],'little'):#x}")
    print(f"   tail hdr bytes: {d[tail:tail+0x80].hex(' ')}")
    print(f"   total matches: {hits}\n")
