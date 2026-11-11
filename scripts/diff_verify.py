#!/usr/bin/env python3
"""Reproduce the load-bearing numbers in DIFF.md from the extracted images.

Checks, all computed directly from the image bytes:
  1. aligned 16-byte window overlap between each version pair
  2. Apple SVID literal counts (0x05ACxxxx little-endian)
  3. Thumb idiom counts: subs r0,#9 / cmp r0,#0xd
  4. the fixed-PDO table: locate it in every image and decode all copies

Usage: diff_verify.py firmware/images
"""
import struct
import sys
import os

VERSIONS = {
    "3.1.8": "A2363_3.1.8_10M569_base0.bin",
    "3.1.12": "A2363_3.1.12_10M1543_base0.bin",
    "3.2.0": "A2363_3.2.0_10M13722_base0.bin",
}
SVIDS = [0x05AC8106, 0x05AC0005, 0x05AC0002, 0x05AC0000]


def pdo_decode(w):
    """Fixed-supply PDO as packed here: bits 19:10 = mV/50, bits 9:0 = mA/10."""
    return ((w >> 10) & 0x3FF) * 0.05, (w & 0x3FF) * 0.01


def find_all(hay, needle, limit=8):
    out, i = [], hay.find(needle)
    while i >= 0 and len(out) < limit:
        out.append(i)
        i = hay.find(needle, i + 1)
    return out


def main():
    d = {}
    for k, fn in VERSIONS.items():
        p = os.path.join(sys.argv[1], fn)
        d[k] = open(p, "rb").read()

    print("== aligned 16-byte window overlap")
    def wins(b):
        return set(b[i:i + 16] for i in range(0, len(b) - 16, 16))
    for a, b in (("3.1.8", "3.1.12"), ("3.1.12", "3.2.0"), ("3.1.8", "3.2.0")):
        wa, wb = wins(d[a]), wins(d[b])
        print(f"  {a:7s} vs {b:7s}  {len(wa&wb):5d} shared  "
              f"{len(wa&wb)/len(wa)*100:5.1f}% of first")

    print("== Apple SVID literals (little-endian occurrences)")
    for k in d:
        counts = [d[k].count(struct.pack("<I", s)) for s in SVIDS]
        print(f"  {k:7s} " + "  ".join(f"0x{s:08X}={c}" for s, c in zip(SVIDS, counts)))

    print("== Thumb idioms")
    for k in d:
        print(f"  {k:7s} subs r0,#9={d[k].count(bytes([0x09,0x38]))}  "
              f"cmp r0,#0xd={d[k].count(bytes([0x0d,0x28]))}")

    print("== fixed-PDO table (20 V / 3 A word, all copies)")
    pat = struct.pack("<I", 0x0006412C)
    for k in d:
        b = d[k]
        for o in find_all(b, pat):
            base = o
            while base >= 4:
                w = struct.unpack_from("<I", b, base - 4)[0]
                v, i = pdo_decode(w)
                if (w & 0x3FF) and 0 < v < 50 and 0 < i < 10:
                    base -= 4
                else:
                    break
            words = [struct.unpack_from("<I", b, base + 4 * j)[0] for j in range(4)]
            dec = "  ".join(f"{v:.2f}V/{i:.2f}A" for v, i in map(pdo_decode, words))
            print(f"  {k:7s} @0x{base:05X}: {dec}")
            break


if __name__ == "__main__":
    main()
