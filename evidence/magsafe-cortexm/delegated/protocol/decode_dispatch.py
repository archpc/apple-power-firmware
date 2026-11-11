#!/usr/bin/env python3
"""Static facts about the 0xa9bc switch table in A2363 3.1.8 (base 0).

Independent of Ghidra/rizin: pure byte reads plus a Thumb branch-target scan.
Reproduces:
  * the 14 little-endian case-table words and the six unique targets
  * the verdict that the word *after* the table (0xaa10) is code, not a pointer
  * which addresses in the image are the target of any BL / B.W / B / B<cond>
  * whether a given address appears anywhere as a 32-bit word or a 16-bit halfword

Usage: python3 decode_dispatch.py <image.bin> [table_off] [nslots]
"""
import struct
import sys


def sext(v, bits):
    return v - (1 << bits) if v >> (bits - 1) else v


def branch_refs(data):
    """Map target address -> list of (source_offset, kind) for every Thumb
    branch-shaped halfword pair, aligned at every halfword boundary.  Crude on
    purpose (it also fires inside data), but it cannot *miss* a real branch."""
    refs = {}
    n = len(data)

    def add(tgt, src, kind):
        refs.setdefault(tgt & ~1, []).append((src, kind))

    for o in range(0, n - 1, 2):
        h1 = struct.unpack_from("<H", data, o)[0]
        if (h1 & 0xF000) == 0xD000 and ((h1 >> 8) & 0xF) not in (0xE, 0xF):
            add(o + 4 + sext(h1 & 0xFF, 8) * 2, o, "B<cond>")
        elif (h1 & 0xF800) == 0xE000:
            add(o + 4 + sext(h1 & 0x7FF, 11) * 2, o, "B")
        elif o + 3 < n:
            h2 = struct.unpack_from("<H", data, o + 2)[0]
            if (h1 & 0xF800) == 0xF000 and (h2 & 0x8000) == 0x8000:
                s = (h1 >> 10) & 1
                i1 = 1 - (((h2 >> 13) & 1) ^ s)
                i2 = 1 - (((h2 >> 11) & 1) ^ s)
                imm = (s << 24) | (i1 << 23) | (i2 << 22) | ((h1 & 0x3FF) << 12) | ((h2 & 0x7FF) << 1)
                if s:
                    imm -= 1 << 25
                add(o + 4 + imm, o, "BL/B.W")
    return refs


def occurrences(data, value, width):
    pat = struct.pack("<I" if width == 4 else "<H", value)
    out, start = [], 0
    while True:
        i = data.find(pat, start)
        if i < 0:
            return out
        out.append(i)
        start = i + 1


def main():
    path = sys.argv[1]
    table = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0xA9D8
    nslots = int(sys.argv[3], 0) if len(sys.argv) > 3 else 14
    data = open(path, "rb").read()
    print(f"image {path}  size {len(data)} ({len(data):#x})")
    print(f"\ncase table @ {table:#x}, {nslots} little-endian words")
    words = []
    for i in range(nslots + 1):
        w = struct.unpack_from("<I", data, table + 4 * i)[0]
        words.append(w)
        tag = "" if i < nslots else "   <-- slot after the table"
        print(f"  [{i:2d}] {table + 4 * i:#07x} = {w:#010x}  in_image={w < len(data)!s:5s} even={w % 2 == 0!s:5s} align4={w % 4 == 0!s:5s}{tag}")
    uniq = sorted(set(words[:nslots]))
    print(f"\nunique targets in the {nslots} slots ({len(uniq)}): " + ", ".join(hex(u) for u in uniq))

    probes = uniq + [table - 2, 0xAA2A, 0xACD4, 0xAA1C]
    refs = branch_refs(data)
    print("\nbranch-reference census")
    for p in probes:
        r = refs.get(p, [])
        near = [f"{s:#07x}:{k}" for s, k in r if abs(s - p) < 0x4000]
        print(f"  {p:#07x}: {len(r)} total, {len(near)} within +/-0x4000  {near[:10]}")
    print("\nraw word / halfword occurrences")
    for p in probes:
        print(f"  {p:#07x}: word {len(occurrences(data, p, 4))} @ "
              f"{[hex(x) for x in occurrences(data, p, 4)][:6]}   half {len(occurrences(data, p, 2))} @ "
              f"{[hex(x) for x in occurrences(data, p, 2)][:8]}")


if __name__ == "__main__":
    main()
