#!/usr/bin/env python3
"""First-order cross-version match over the three seeded Cortex-M inventories.

Signature = (function body size in bytes, operand-free mnemonic sequence).
Mnemonic sequences come from MnemSeqs.java over the kept seeded projects, so
they are exactly the instructions inside Ghidra's function bodies.

Reported:
  * functions whose signature exists in all three builds;
  * same-mnemonic / different-size pairs (3.1.8->3.1.12 and 3.1.12->3.2.0);
  * 3.2.0 functions with no 3.1.12 counterpart;
  * duplication ("identical twins") statistics that qualify the counts.

Usage: match.py <out.json>
"""
import json, os, sys
from collections import defaultdict

OUT = os.path.dirname(os.path.abspath(__file__))
MN = {"3.1.8": os.path.join(OUT, "mnems_318.json"),
      "3.1.12": os.path.join(OUT, "mnems_3112.json"),
      "3.2.0": os.path.join(OUT, "mnems_320.json")}

def norm(seq):
    # operand-free mnemonics already; canonicalise branch/call classes so that
    # relocation-induced address changes cannot matter (they are already absent).
    out = []
    for m in seq.split():
        if m in ("bl", "blx", "blxns", "blxs"):
            out.append("call")
        elif m == "b":
            out.append("ubr")
        elif m.startswith("b") and m not in ("bic", "bics", "bfc", "bfi", "bkpt"):
            out.append("cbr")
        elif m in ("cbz", "cbnz"):
            out.append("cbr")
        else:
            out.append(m)
    return " ".join(out)

data = {}
for ver, path in MN.items():
    rows = json.load(open(path))
    for r in rows:
        r["norm"] = norm(r["mnems"])
        r["sig"] = (r["size"], r["norm"])
    data[ver] = rows

sigidx = {v: defaultdict(list) for v in data}
for v in data:
    for r in data[v]:
        sigidx[v][r["sig"]].append(r["addr"])

sigs = {v: set(sigidx[v]) for v in data}
all3 = sigs["3.1.8"] & sigs["3.1.12"] & sigs["3.2.0"]

# unique triples: one representative per signature
triples = []
for s in all3:
    triples.append({"size": s[0], "n_318": len(sigidx["3.1.8"][s]),
                    "n_3112": len(sigidx["3.1.12"][s]), "n_320": len(sigidx["3.2.0"][s]),
                    "a318": sigidx["3.1.8"][s][0], "a3112": sigidx["3.1.12"][s][0],
                    "a320": sigidx["3.2.0"][s][0]})
triples.sort(key=lambda t: -t["size"])

# same mnemonic sequence, differing size
def size_changed(a, b):
    bynorm_a, bynorm_b = defaultdict(list), defaultdict(list)
    for r in data[a]: bynorm_a[r["norm"]].append(r)
    for r in data[b]: bynorm_b[r["norm"]].append(r)
    out = []
    for seq in set(bynorm_a) & set(bynorm_b):
        for ra in bynorm_a[seq]:
            for rb in bynorm_b[seq]:
                if ra["size"] != rb["size"]:
                    out.append({"norm_len": len(seq.split()), "a": ra["addr"], "b": rb["addr"],
                                "size_a": ra["size"], "size_b": rb["size"],
                                "d_mnems": rb["n"] - ra["n"]})
    return out

sc_3112 = size_changed("3.1.8", "3.1.12")
sc_320 = size_changed("3.1.12", "3.2.0")

# 3.2.0 functions with no 3.1.12 counterpart (no shared mnemonic sequence at all)
norms_3112 = set(r["norm"] for r in data["3.1.12"])
unmatched_320 = [r for r in data["3.2.0"] if r["norm"] not in norms_3112]
unmatched_3112 = [r for r in data["3.1.12"] if r["norm"] not in set(r2["norm"] for r2 in data["3.2.0"])]

# duplication stats
def dup(v):
    c = defaultdict(int)
    for r in data[v]: c[r["norm"]] += 1
    return c
dupstats = {}
for v in data:
    c = dup(v)
    dupstats[v] = {"distinct_norm_seqs": len(c),
                   "functions": len(data[v]),
                   "seqs_with_multiplicity": sum(1 for k, n in c.items() if n > 1),
                   "max_multiplicity": max(c.values()),
                   "functions_in_duplicated_seqs": sum(n for n in c.values() if n > 1)}

# ---- tier 2: similarity-based one-to-one assignment (3.1.12 vs 3.2.0) ----
import difflib
A = data["3.1.12"]; B = data["3.2.0"]
def similar(rb, ra):
    if abs(rb["size"] - ra["size"]) > 16:
        return 0.0
    return difflib.SequenceMatcher(None, rb["norm"].split(), ra["norm"].split()).ratio()
pairs = []
for rb in B:
    best, bscore = None, 0.0
    for ra in A:
        s = similar(rb, ra)
        if s > bscore:
            best, bscore = ra, s
    if best is not None and bscore >= 0.85:
        pairs.append((bscore, rb, best))
pairs.sort(key=lambda t: -t[0])
used_a, used_b, one2one = set(), set(), []
for s, rb, ra in pairs:
    if ra["addr"] in used_a or rb["addr"] in used_b:
        continue
    used_a.add(ra["addr"]); used_b.add(rb["addr"]); one2one.append((s, rb, ra))
nomatch320 = [rb for rb in B if rb["addr"] not in used_b]

res = {
    "signature": "(size_bytes, operand-free mnemonic sequence; bl->call, b->ubr, b<cond>/cbz->cbr)",
    "functions": {v: len(data[v]) for v in data},
    "distinct_signatures": {v: len(sigs[v]) for v in data},
    "signatures_in_all_three": len(all3),
    "functions_320_matching_all3": sum(len(sigidx["3.2.0"][s]) for s in all3),
    "functions_3112_matching_all3": sum(len(sigidx["3.1.12"][s]) for s in all3),
    "functions_318_matching_all3": sum(len(sigidx["3.1.8"][s]) for s in all3),
    "triples": triples[:60],
    "dupstats": dupstats,
    "size_changed_318_3112": {"count": len(sc_3112), "pairs": sc_3112[:40]},
    "size_changed_3112_320": {"count": len(sc_320), "pairs": sc_320[:40]},
    "unmatched_320": {"count": len(unmatched_320),
                      "items": [{"addr": r["addr"], "size": r["size"], "n": r["n"]} for r in
                                sorted(unmatched_320, key=lambda r: -r["size"])[:40]]},
    "unmatched_3112": {"count": len(unmatched_3112)},
    "tier2": {
        "rule": "best match with |size diff| <= 16 and sequence similarity >= 0.85, greedy one-to-one",
        "one2one_pairs": len(one2one),
        "nomatch_320": len(nomatch320),
        "median_similarity": round(sorted(s for s, _, _ in one2one)[len(one2one)//2], 3) if one2one else None,
        "nomatch_320_largest": [{"addr": r["addr"], "size": r["size"], "n": r["n"]}
                                for r in sorted(nomatch320, key=lambda r: -r["size"])[:20]],
        "pairs_low_score": [{"s": round(s, 3), "a320": rb["addr"], "a3112": ra["addr"],
                             "size320": rb["size"], "size3112": ra["size"]}
                            for s, rb, ra in one2one[-20:]],
    },
}
json.dump(res, open(sys.argv[1], "w"), indent=1)
print(json.dumps({k: v for k, v in res.items() if k not in
                  ("triples", "size_changed_318_3112", "size_changed_3112_320",
                   "unmatched_320", "unmatched_3112")}, indent=1))
print("size_changed 318->3112:", res["size_changed_318_3112"]["count"])
print("size_changed 3112->320:", res["size_changed_3112_320"]["count"])
print("unmatched_320:", res["unmatched_320"]["count"], "unmatched_3112:", res["unmatched_3112"]["count"])
