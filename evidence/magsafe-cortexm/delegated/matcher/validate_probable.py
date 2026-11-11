#!/usr/bin/env python3
"""Validate the 0.85-band 'probable' cross-version pairs with literal multisets.

Recomputes 3.1.12->3.2.0 similarities the same way match_calibrated.py does,
selects unique-1:1 pairs with 0.85 <= s < 0.983 (the 'probable' band), and
scores each pair by literal-word multiset agreement (Jaccard) computed from
the function byte ranges in the respective images. Low literal agreement on a
high mnemonic similarity flags pairs whose bodies read different data.

Usage: validate_probable.py <img3112> <img320> <inv3112.json> <inv320.json> <out.json>
"""
import json, struct, sys, itertools
from collections import Counter

img_a, img_b, inv_a, inv_b, out = sys.argv[1:6]
A = open(img_a, "rb").read()
B = open(img_b, "rb").read()


def canon(seq):
    # same normalization contract as match_calibrated.canon
    if isinstance(seq, str):
        seq = seq.split()
    out_, prev_hi = [], False
    for tok in seq:
        hi = tok.startswith("bl") or tok in ("blx",)
        if not (hi and prev_hi):
            out_.append(tok)
        prev_hi = hi
    return out_


def sim(a, b):
    if not a or not b:
        return 0.0
    n = min(len(a), len(b))
    import difflib
    m = difflib.SequenceMatcher(None, a[: n * 4], b[: n * 4], autojunk=False)
    return m.ratio()


def literals(img, addr, size, img_len=None):
    """Non-pointer literal words inside the body: words >= 0x100 that are NOT
    plausible in-image addresses (those shift wholesale on relink)."""
    words = Counter()
    limit = img_len or len(img)
    for off in range(addr & ~1, min(addr - (addr & 1) + size, len(img)) - 3, 4):
        w, = struct.unpack_from("<I", img, off)
        if w >= 0x100 and w >= limit:  # exclude in-image-range words (pointers)
            words[w] += 1
    return words


mn_a = json.load(open(inv_a.replace("inventory", "mnems") if False else inv_a))
# inventories carry (addr,size); mnemonics come from the matcher workspace files
base = "/Users/sein/.hermes/artifacts/apple-power-firmware/evidence/magsafe-cortexm/delegated/xversion"
mna = json.load(open(base + "/mnems_3112.json"))
mnb = json.load(open(base + "/mnems_320.json"))
iva = json.load(open(inv_a))
ivb = json.load(open(inv_b))
sizes_a = {f["addr"]: f["size"] for f in iva}
sizes_b = {f["addr"]: f["size"] for f in ivb}
seqs_a = {f["addr"]: canon(f.get("mnems") or f.get("mnemonic_seq") or f.get("seq") or []) for f in mna}
seqs_b = {f["addr"]: canon(f.get("mnems") or f.get("mnemonic_seq") or f.get("seq") or []) for f in mnb}

# count signature multiplicity to detect ambiguous pairs
sig_a = Counter(tuple(seqs_a[k]) for k in seqs_a)
sig_b = Counter(tuple(seqs_b[k]) for k in seqs_b)

pairs = []
for ka, sa in seqs_a.items():
    if len(sa) < 8:
        continue
    best, bk = 0.0, None
    for kb, sb in seqs_b.items():
        if len(sb) < 8 or abs(sizes_a.get(ka, 0) - sizes_b.get(kb, 0)) > 16:
            continue
        s = sim(sa, sb)
        if s > best:
            best, bk = s, kb
    if bk is not None and 0.85 <= best < 0.983:
        if sig_a[tuple(sa)] > 1 or sig_b[tuple(seqs_b[bk])] > 1:
            continue  # ambiguous by duplication
        la = literals(A, int(ka, 16), sizes_a[ka])
        lb = literals(B, int(bk, 16), sizes_b[bk])
        inter = sum((la & lb).values())
        union = sum((la | lb).values())
        j = inter / union if union else None
        pairs.append({"a_3112": ka, "b_320": bk, "s": round(best, 4),
                      "lit_jaccard": None if j is None else round(j, 3),
                      "lit_a": sum(la.values()), "lit_b": sum(lb.values())})

pairs.sort(key=lambda p: p["s"])
json.dump({"count": len(pairs), "pairs": pairs}, open(out, "w"), indent=1)
weak = [p for p in pairs if p["lit_jaccard"] is not None and p["lit_jaccard"] < 0.3]
print("probable pairs:", len(pairs), "| literal-weak (<0.3):", len(weak))
for p in weak[:15]:
    print(" weak:", p)
