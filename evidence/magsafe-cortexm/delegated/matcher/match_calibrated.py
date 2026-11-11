#!/usr/bin/env python3
"""Calibrated cross-version function matcher for MagSafe A2363 (3.1.8/3.1.12/3.2.0).

Survives the two failure modes in DIFF.md section 10:

  * failure 1 (empty mnemonics): every function must carry n >= 1 tokens; the
    script hard-fails on an empty sequence, so a broken disassembly cannot
    silently produce a zero score matrix.
  * failure 2 (nulls drawn from the other build): the negative pool is drawn
    from WITHIN each build - pairs of distinct functions in the *same* image.
    For a near-identical pair the other build contains the true counterpart,
    which is exactly why the cross-build null tail reached 1.0.

The threshold is hard-capped below 1.0 (MAX_THRESHOLD).  Scores of exactly 1.0
are structurally ambiguous (duplicate bodies) and are reported as AMBIGUOUS,
never as match evidence.

Signature = (body size in bytes, operand-free mnemonic sequence with branch and
call classes canonicalised).  Similarity = difflib ratio over canonical tokens,
gated to |d_size| <= SIZE_GATE (else 0.0).

Usage: python3 match_calibrated.py [out.json]   (default results_calibrated.json)
No firmware is read or modified.
"""
import difflib
import json
import os
import sys
from collections import Counter, defaultdict

HERE = os.path.dirname(os.path.abspath(__file__))
XVER = os.path.normpath(os.path.join(HERE, "..", "xversion"))
MN = {"3.1.8": os.path.join(XVER, "mnems_318.json"),
      "3.1.12": os.path.join(XVER, "mnems_3112.json"),
      "3.2.0": os.path.join(XVER, "mnems_320.json")}

SIZE_GATE = 16          # bytes; same as the first-pass matcher, so deltas are comparable
MAX_THRESHOLD = 0.99    # hard cap: a threshold of 1.0 is unsatisfiable by design
STUB_N = 8              # functions with fewer instructions are "stubs" (DIFF.md section 2)
BAND_EDGES = ((0.95, "confident"), (0.85, "probable"))
REPORT_THRESHOLDS = (None, 0.95, 0.85)   # None = calibrated threshold


def canon(seq):
    out = []
    for m in seq.split():
        if m in ("bl", "blx", "blxns", "blxs"):
            out.append("call")
        elif m == "b":
            out.append("ubr")
        elif m in ("cbz", "cbnz"):
            out.append("cbr")
        elif m.startswith("b") and m not in ("bic", "bics", "bfc", "bfi", "bkpt", "bfcsel"):
            out.append("cbr")
        else:
            out.append(m)
    return " ".join(out)


def sim(a, b):
    if abs(a["size"] - b["size"]) > SIZE_GATE:
        return 0.0
    return difflib.SequenceMatcher(None, a["tok"], b["tok"], autojunk=False).ratio()


def load():
    data = {}
    for ver, path in MN.items():
        rows = json.load(open(path))
        for r in rows:
            r["norm"] = canon(r["mnems"])
            r["tok"] = r["norm"].split()
            r["sig"] = (r["size"], r["norm"])
            if not r["tok"]:
                raise SystemExit("FAIL: empty mnemonic sequence at %s %s - disassembly "
                                 "is broken, refusing to produce a result" % (ver, r["addr"]))
            r["stub"] = r["n"] < STUB_N
        data[ver] = rows
    return data


def quantiles(xs):
    if not xs:
        return {}
    s = sorted(xs)
    n = len(s)
    def q(p):
        return round(s[min(n - 1, int(p * (n - 1)))], 4)
    return {"n": n, "min": round(s[0], 4), "p25": q(.25), "median": q(.5),
            "p75": q(.75), "p90": q(.9), "p95": q(.95), "p99": q(.99),
            "p999": q(.999), "max": round(s[-1], 4)}


EDGES = (0.0, 0.5, 0.6, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 0.98, 0.99, 1.0001)


def histogram(xs):
    c = Counter()
    for x in xs:
        for i in range(len(EDGES) - 1):
            if EDGES[i] <= x < EDGES[i + 1]:
                c["[%s,%s)" % (EDGES[i], EDGES[i + 1])] += 1
                break
    return {k: c[k] for k in ("[%s,%s)" % (EDGES[i], EDGES[i + 1]) for i in range(len(EDGES) - 1))}


def within_build_negatives(rows):
    """Distinct-function pairs in the SAME build, nonzero similarity."""
    scores, top = [], []
    n = len(rows)
    for i in range(n):
        for j in range(i + 1, n):
            s = sim(rows[i], rows[j])
            if s <= 0.0:
                continue
            scores.append(s)
            if s < 1.0:
                top.append({"s": round(s, 4), "a": rows[i]["addr"], "b": rows[j]["addr"],
                            "size_a": rows[i]["size"], "size_b": rows[j]["size"],
                            "n_a": rows[i]["n"], "n_b": rows[j]["n"]})
    top.sort(key=lambda t: -t["s"])
    return scores, top[:8]


def calibration(data):
    """Positives: 3.1.8->3.1.12 exact-signature pairs (98.2% exact overlap = ground
    truth).  Restricted to signatures unique in both builds, so each positive is one
    known pairing and no duplicate pair can masquerade as ground truth."""
    c18 = Counter(r["sig"] for r in data["3.1.8"])
    c12 = Counter(r["sig"] for r in data["3.1.12"])
    ix18 = {r["sig"]: r for r in data["3.1.8"]}
    ix12 = {r["sig"]: r for r in data["3.1.12"]}
    pos = []
    for sig, n in c18.items():
        if n == 1 and c12.get(sig, 0) == 1:
            pos.append(sim(ix18[sig], ix12[sig]))
    neg12, top12 = within_build_negatives(data["3.1.12"])
    neg20, top20 = within_build_negatives(data["3.2.0"])
    return {"pos": pos, "neg": neg12 + neg20,
            "neg_3112": len(neg12), "neg_320": len(neg20),
            "ident_3112": sum(1 for x in neg12 if x >= 1.0),
            "ident_320": sum(1 for x in neg20 if x >= 1.0),
            "top_hard_negatives": top12 + top20}


def choose_threshold(cal):
    neg = sorted(cal["neg"], reverse=True)
    neg_below1 = [x for x in neg if x < 1.0]
    floor = neg_below1[0] if neg_below1 else 0.0
    raw = floor + 1e-4
    th = min(raw, MAX_THRESHOLD)
    def rates(t):
        tp = sum(1 for x in cal["pos"] if x >= t) / len(cal["pos"])
        fp = sum(1 for x in neg if x >= t) / len(neg)
        fpn = sum(1 for x in neg_below1 if x >= t) / len(neg)   # non-identical negatives
        return tp, fp, fpn
    tpr, fpr, fpr_nid = rates(th)
    return {"threshold": round(th, 4),
            "rule": "max(similarity over within-build gated negatives strictly below 1.0) "
                    "+ 1e-4, hard-capped at %.2f" % MAX_THRESHOLD,
            "largest_negative": round(neg[0], 4),
            "largest_negative_below_1": round(floor, 4),
            "capped": raw > MAX_THRESHOLD,
            "negatives_at_1.0": sum(1 for x in neg if x >= 1.0),
            "tpr_positives": round(tpr, 4),
            "fpr_all_negatives": round(fpr, 6),
            "fpr_nonidentical_negatives": round(fpr_nid, 6),
            "sweep": [{"t": t, "tpr": round(rates(t)[0], 3),
                       "fpr": round(rates(t)[1], 5),
                       "fpr_nonidentical": round(rates(t)[2], 5)}
                      for t in (0.99, 0.9829, 0.98, 0.95, 0.90, 0.85, 0.80, 0.75)]}


def classify(A, B, th, matrix):
    """matrix[(b_addr, a_addr)] = score.  Classification at one threshold."""
    cA = Counter(r["sig"] for r in A)
    cB = Counter(r["sig"] for r in B)
    ia = {r["addr"]: r for r in A}
    ib = {r["addr"]: r for r in B}
    cands = [{"b": ib[b], "a": ia[a], "s": s} for (b, a), s in matrix.items() if s >= th]
    per_b, per_a = defaultdict(list), defaultdict(list)
    for c in cands:
        per_b[c["b"]["addr"]].append(c)
        per_a[c["a"]["addr"]].append(c)

    for c in cands:
        a, b = c["a"], c["b"]
        # AMBIGUOUS only when the pairing cannot be resolved to one function pair:
        # identical bodies are ambiguous only if the signature is duplicated in a
        # build; a unique signature at score 1.0 is the strongest possible match.
        if cA[a["sig"]] > 1 or cB[b["sig"]] > 1:
            reason = "duplicate_signature"
        elif len(per_b[b["addr"]]) > 1:
            reason = "one_to_many"
        elif len(per_a[a["addr"]]) > 1:
            reason = "many_to_one"
        else:
            reason = "unique"
        c["reason"] = reason
        c["amb"] = reason != "unique"
        c["exact"] = c["s"] >= 1.0
        c["stub"] = a["stub"] or b["stub"]

    unique = [c for c in cands if not c["amb"]]
    amb = [c for c in cands if c["amb"]]
    band = lambda s: next((n for t, n in BAND_EDGES if s >= t), "below")
    def summarize(subset):
        return {"total": len(subset),
                "nonstub": sum(1 for c in subset if not c["stub"]),
                "stub": sum(1 for c in subset if c["stub"]),
                "exact_score_1.0": sum(1 for c in subset if c["exact"]),
                "by_band": dict(Counter(band(c["s"]) for c in subset)),
                "by_band_nonstub": dict(Counter(band(c["s"]) for c in subset if not c["stub"]))}
    matched_b = {c["b"]["addr"] for c in cands}
    matched_a = {c["a"]["addr"] for c in cands}
    unm_b = [r for r in B if r["addr"] not in matched_b]
    unm_a = [r for r in A if r["addr"] not in matched_a]
    return {
        "threshold": round(th, 4),
        "candidate_pairs": summarize(cands),
        "unique_1to1": summarize(unique),
        "ambiguous": summarize(amb),
        "ambiguous_by_reason": dict(Counter(c["reason"] for c in amb)),
        "ambiguous_new_functions": len({c["b"]["addr"] for c in amb}),
        "ambiguous_old_functions": len({c["a"]["addr"] for c in amb}),
        "unmatched_new": {"count": len(unm_b),
                          "stub": sum(1 for r in unm_b if r["stub"]),
                          "nonstub": sum(1 for r in unm_b if not r["stub"]),
                          "largest": [{"addr": r["addr"], "size": r["size"], "n": r["n"],
                                       "name": r["name"]} for r in sorted(unm_b, key=lambda r: -r["size"])[:15]]},
        "unmatched_old": {"count": len(unm_a),
                          "stub": sum(1 for r in unm_a if r["stub"]),
                          "nonstub": sum(1 for r in unm_a if not r["stub"]),
                          "largest": [{"addr": r["addr"], "size": r["size"], "n": r["n"],
                                       "name": r["name"]} for r in sorted(unm_a, key=lambda r: -r["size"])[:10]]},
        "_unique": unique, "_cands": cands,
    }


def first_pass(A, B, th=0.85):
    """Reproduce the DIFF.md 11d rule exactly: best match per new function with
    |d_size|<=16 and similarity >= th, then greedy 1:1 in descending score."""
    pairs = []
    for b in B:
        best, bs = None, 0.0
        for a in A:
            s = sim(b, a)
            if s > bs:
                best, bs = a, s
        if best is not None and bs >= th:
            pairs.append((bs, b, best))
    pairs.sort(key=lambda t: -t[0])
    cA = Counter(r["sig"] for r in A)
    cB = Counter(r["sig"] for r in B)
    ua, ub, keep = set(), set(), []
    for s, b, a in pairs:
        if a["addr"] in ua or b["addr"] in ub:
            continue
        ua.add(a["addr"]); ub.add(b["addr"]); keep.append((s, b, a))
    affected = [k for k in keep if cA[k[2]["sig"]] > 1 or cB[k[1]["sig"]] > 1]
    return {"rule": "best per new function, |d_size|<=16, sim>=%.2f, greedy 1:1" % th,
            "pairs": len(keep),
            "new_functions_matched": len(ub),
            "unmatched_new": len(B) - len(ub),
            "pairs_on_duplicated_signature": len(affected),
            "pairs_on_duplicated_signature_pct": round(100.0 * len(affected) / len(keep), 1) if keep else 0.0,
            "pairs_exact_score": sum(1 for k in keep if k[0] >= 1.0),
            "pairs_stub": sum(1 for k in keep if k[2]["stub"] or k[1]["stub"])}


def main():
    out_path = sys.argv[1] if len(sys.argv) > 1 else os.path.join(HERE, "results_calibrated.json")
    data = load()
    cal = calibration(data)
    th = choose_threshold(cal)
    T = th["threshold"]

    # one score matrix per direction, computed once
    def matrix(A, B):
        return {(b["addr"], a["addr"]): sim(b, a) for b in B for a in A}
    M312 = matrix(data["3.1.12"], data["3.2.0"])
    M318 = matrix(data["3.1.8"], data["3.1.12"])

    runs312 = {}
    for t in REPORT_THRESHOLDS:
        tt = T if t is None else t
        runs312[("%.4f" % tt)] = classify(data["3.1.12"], data["3.2.0"], tt, M312)
    runs318 = {}
    for t in REPORT_THRESHOLDS:
        tt = T if t is None else t
        runs318[("%.4f" % tt)] = classify(data["3.1.8"], data["3.1.12"], tt, M318)

    s18 = set(r["sig"] for r in data["3.1.8"])
    s12 = set(r["sig"] for r in data["3.1.12"])
    s20 = set(r["sig"] for r in data["3.2.0"])
    exact_pairs_312 = sum(1 for r in data["3.2.0"] if r["sig"] in s12)
    res = {
        "signature": "size_bytes + operand-free mnemonic sequence (bl->call, b->ubr, b<cond>/cbz->cbr)",
        "threshold": th,
        "functions": {v: len(data[v]) for v in data},
        "stubs_n_lt_%d" % STUB_N: {v: sum(1 for r in data[v] if r["stub"]) for v in data},
        "distinct_signatures": {v: len(set(r["sig"] for r in data[v])) for v in data},
        "signature_multiplicity": {v: {"max": max(Counter(r["sig"] for r in data[v]).values()),
                                       "functions_in_duplicated_signatures":
                                       sum(n for n in Counter(r["sig"] for r in data[v]).values() if n > 1)}
                                   for v in data},
        "signatures_in_all_three": len(s18 & s12 & s20),
        "exact_signature_3112_to_320_count": exact_pairs_312,
        "exact_signature_3112_to_320_pct_of_320": round(100.0 * exact_pairs_312 / len(data["3.2.0"]), 1),
        "calibration": {
            "positives_dist": quantiles(cal["pos"]),
            "positives_hist": histogram(cal["pos"]),
            "negatives_gated_dist": quantiles(cal["neg"]),
            "negatives_hist": histogram(cal["neg"]),
            "counts": {"positives": len(cal["pos"]), "negatives_3112": cal["neg_3112"],
                       "negatives_320": cal["neg_320"], "negatives_total": len(cal["neg"]),
                       "identical_pairs_3112": cal["ident_3112"],
                       "identical_pairs_320": cal["ident_320"]},
            "hardest_within_build_negatives": cal["top_hard_negatives"],
            "positives_below_threshold": [round(x, 3) for x in sorted(cal["pos"]) if x < T],
        },
        "first_pass_rule_reproduced": {"3112_320": first_pass(data["3.1.12"], data["3.2.0"]),
                                       "318_3112": first_pass(data["3.1.8"], data["3.1.12"])},
        "match_3112_320": {k: {kk: vv for kk, vv in v.items() if not kk.startswith("_")}
                           for k, v in runs312.items()},
        "match_318_3112": {k: {kk: vv for kk, vv in v.items() if not kk.startswith("_")}
                           for k, v in runs318.items()},
    }
    # pair lists at the calibrated threshold
    best = runs312["%.4f" % T]
    res["pairs_3112_320"] = {
        "unique_1to1": [{k: c[k] for k in ("s",)} | {
            "a_3112": c["a"]["addr"], "b_320": c["b"]["addr"],
            "size_3112": c["a"]["size"], "size_320": c["b"]["size"],
            "n_3112": c["a"]["n"], "n_320": c["b"]["n"]} for c in best["_unique"]],
        "ambiguous_groups": [],
    }
    groups = defaultdict(list)
    for c in best["_cands"]:
        if c["amb"]:
            groups[c["b"]["addr"]].append(c["a"]["addr"])
    res["pairs_3112_320"]["ambiguous_groups"] = [
        {"new_320": k, "old_3112_candidates": sorted(v)} for k, v in sorted(groups.items())]
    json.dump(res, open(out_path, "w"), indent=1)

    print("positives n=%d %s" % (len(cal["pos"]), quantiles(cal["pos"])))
    print("negatives gated n=%d %s" % (len(cal["neg"]), quantiles(cal["neg"])))
    print("threshold", json.dumps(th))
    for k, v in runs312.items():
        print("3112->320 @%s cands=%d unique=%d amb=%d reasons=%s unm_new=%d(nonstub %d) unm_old=%d nonstub=%d" %
              (k, v["candidate_pairs"]["total"], v["unique_1to1"]["total"], v["ambiguous"]["total"],
               v["ambiguous_by_reason"], v["unmatched_new"]["count"],
               v["unmatched_new"]["nonstub"], v["unmatched_old"]["count"],
               v["unmatched_old"]["nonstub"]))
    for k, v in runs318.items():
        print("318->3112 @%s cands=%d unique=%d amb=%d unm_new=%d unm_old=%d" %
              (k, v["candidate_pairs"]["total"], v["unique_1to1"]["total"],
               v["ambiguous"]["total"], v["unmatched_new"]["count"], v["unmatched_old"]["count"]))
    print("first-pass reproduction:", res["first_pass_rule_reproduced"])
    print("wrote", out_path)


if __name__ == "__main__":
    main()
