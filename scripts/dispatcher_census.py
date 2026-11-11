#!/usr/bin/env python3
"""Dispatcher census: mov pc,Rn sites and their absolute case-pointer tables.

Writes evidence/dispatcher-census.json. Exit 0 when the documented counts hold:
14 / 14 / 10 dispatchers and a 14-case table in 3.1.8 and 3.1.12 but not 3.2.0.

Usage: dispatcher_census.py <images_dir> <out_json>
"""
import collections
import json
import os
import struct
import sys

MOVPC = {0x87, 0x8F, 0x97, 0x9F, 0xA7, 0xAF, 0xB7, 0xBF}
IMAGES = {"3.1.8": "A2363_3.1.8_10M569_base0.bin",
          "3.1.12": "A2363_3.1.12_10M1543_base0.bin",
          "3.2.0": "A2363_3.2.0_10M13722_base0.bin"}
EXPECTED_CASES = {"3.1.8": 14, "3.1.12": 14, "3.2.0": 10}


def table_at(b, site):
    """Longest run of in-image code pointers near the site; the table is the
    longest such run found. Empirical: Thumb ADR arithmetic proved unreliable."""
    best = None
    for start in range(max(0, site - 2), min(len(b) - 4, site + 0x90), 2):
        if start % 4:
            continue
        tg, p = [], start
        while p + 4 <= len(b) and len(tg) < 64:
            t = struct.unpack_from("<I", b, p)[0] & ~1
            if 0x400 < t < len(b) - 2 and (t & 1) == 0:
                tg.append(t)
                p += 4
            else:
                break
        if len(tg) >= 6 and (best is None or len(tg) > len(best[1])):
            best = (start, tg)
    return best


def census(b):
    rows = []
    for i in range(1, len(b) - 1):
        if b[i + 1] != 0x46 or b[i] not in MOVPC:
            continue
        r = table_at(b, i)
        if not r:
            continue
        start, tg = r
        c = collections.Counter(tg)
        top = c.most_common(1)[0]
        rows.append({"site": hex(i), "table": hex(start), "cases": len(tg),
                     "unique": len(c), "dominant": hex(top[0]),
                     "dominant_share": top[1], "targets": [hex(t) for t in tg]})
    return rows


def main():
    images, out = sys.argv[1], sys.argv[2]
    result, ok = {}, True
    for tag, fn in IMAGES.items():
        rows = census(open(os.path.join(images, fn), "rb").read())
        result[tag] = rows
        has14 = [r["site"] for r in rows if r["cases"] == 14]
        good = len(rows) == EXPECTED_CASES[tag] and (bool(has14) == (tag != "3.2.0"))
        ok = ok and good
        print(f"{tag}: dispatchers={len(rows)} 14-case={has14 or 'none'} "
              f"{'ok' if good else 'MISMATCH'}")
    os.makedirs(os.path.dirname(out) or ".", exist_ok=True)
    json.dump(result, open(out, "w"), indent=1)
    print(f"wrote {out}")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
