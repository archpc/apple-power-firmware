#!/usr/bin/env python3
"""Whole-image Ghidra function coverage: bytes inside function bodies / image size.

Regional figures for fixed address windows are deliberately NOT produced: those
windows are applied to shifted layouts and are not comparable between builds
(see DIFF.md §3).

Usage: coverage.py <raw_dir> <images_dir>
Exit 0 when the printed whole-image figures match the documented 38.8/39.4/43.3.
"""
import os
import sys

BUILDS = {"3.1.8": ("inventory_318.tsv", "A2363_3.1.8_10M569_base0.bin"),
          "3.1.12": ("inventory_3112.tsv", "A2363_3.1.12_10M1543_base0.bin"),
          "3.2.0": ("inventory_320.tsv", "A2363_3.2.0_10M13722_base0.bin")}
EXPECTED = {"3.1.8": 38.8, "3.1.12": 39.4, "3.2.0": 43.3}


def spans(path):
    out = []
    with open(path) as f:
        next(f)
        for line in f:
            p = line.rstrip("\n").split("\t")
            if len(p) >= 3:
                out.append((int(p[0], 16), int(p[2])))
    return sorted(out)


def main():
    raw, images = sys.argv[1], sys.argv[2]
    ok = True
    for tag, (inv, img) in BUILDS.items():
        size = os.path.getsize(os.path.join(images, img))
        cov = 0
        for a, s in spans(os.path.join(raw, inv)):
            cov += min(size, a + s) - max(0, a) if a + s > 0 else 0
        pct = round(cov / size * 100, 1)
        good = abs(pct - EXPECTED[tag]) <= 0.2
        ok = ok and good
        print(f"{tag}: {len(spans(os.path.join(raw, inv)))} funcs  "
              f"{pct}% coverage  expected {EXPECTED[tag]}%  {'ok' if good else 'MISMATCH'}")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
