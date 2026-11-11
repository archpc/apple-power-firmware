#!/usr/bin/env python3
"""Regenerate census-derived seed lists for 3.1.12 / 3.2.0.

Seed construction (same as seeds_318.csv): {0x10} U {site} U {case targets},
sorted ascending, one file offset per line, no clear specifiers.
Verifies the result is identical to the checked-in seeds_3112.csv / seeds_320.csv.
"""
import json, os, sys

repo = "/Users/sein/.hermes/artifacts/apple-power-firmware"
outdir = os.path.join(repo, "evidence/magsafe-cortexm/delegated/xversion")
census = json.load(open(os.path.join(repo, "evidence/dispatcher-census.json")))

for ver, fname in [("3.1.12", "seeds_3112.csv"), ("3.2.0", "seeds_320.csv")]:
    addrs = {0x10}
    for e in census[ver]:
        addrs.add(int(e["site"], 16))
        addrs.update(int(t, 16) for t in e["targets"])
    text = "\n".join("0x%x" % a for a in sorted(addrs)) + "\n"
    with open(os.path.join(outdir, fname), "w") as fh:
        fh.write(text)
    prev = set(int(l.strip(), 16) for l in
               open(os.path.join(repo, "evidence/magsafe-cortexm", fname)) if l.strip())
    print(ver, len(addrs), "identical_to_checked_in_copy=", prev == addrs)
