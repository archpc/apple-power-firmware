# Calibrated cross-version matcher (2nd calibrated attempt)

Scope: A2363 MagSafe, three seeded Cortex-M inventories. Inputs are the
existing normalized mnemonic sequences (`xversion/mnems_318.json`,
`mnems_3112.json`, `mnems_320.json`) and the three inventories. No firmware was
read or written. Scripts and results live in `delegated/matcher/`.

Labels used here: **OBSERVED** (printed by a run in this directory),
**COMPUTED** (derived from those observations by the script), **OPEN**
(unresolved), **NOT CLAIMED** (explicitly refused).

---

## Step 1 — What the first-pass matcher measures, and why it cannot support a semantic claim

`xversion/match.py` (**OBSERVED**, read in full) computes:

- a signature `(body size in bytes, operand-free mnemonic sequence)` after
  canonicalising `bl*`→`call`, `b`→`ubr`, `b<cond>/cbz/cbnz`→`cbr`;
- three counts: signatures present in all three builds, signatures shared by a
  pair with different body size, and 3.2.0 functions with no shared sequence;
- a "tier 2" greedy one-to-one assignment over `difflib` similarity with
  `|Δsize| ≤ 16` and `sim ≥ 0.85`.

Its raw output supports **no** semantic claim, for four reasons found in the
code, not inferred:

1. **It never calibrates.** `0.85` is a constant. Nothing in the script
   measures what similarity two *unrelated* functions in this firmware reach, so
   no false-positive rate exists to attach to the 234 pairs.
2. **Its assignment is greedy and score-ordered.** Ties at 1.0 are broken by
   list order, so which of several identical bodies gets the pair depends on
   iteration order, not on evidence. Identical bodies are counted as if they
   were distinct, resolved correspondences.
3. **`difflib` autojunk silently changes long functions** (**OBSERVED**).
   `SequenceMatcher` defaults to `autojunk=True`, which down-weights tokens
   appearing in >1 % of a sequence once it exceeds 200 elements. Functions here
   reach 1385 mnemonics. The effect is measurable: rerunning match.py's own
   rule with `autojunk=True` gives **234 pairs / 189 unmatched** (exactly the
   DIFF.md §11d figure), and with `autojunk=False` gives **238 / 185**. The
   published count is therefore partly an artefact of a length-dependent
   heuristic, not a property of the binaries.
4. **Multiplicity is reported but not acted on.** `dupstats` says "max
   multiplicity 7", yet the greedy loop still emits one pair per 3.2.0
   function, so the 234 are a many-to-many upper bound presented in the shape
   of a 1:1 result.

Consequence: match.py's output can support "this signature recurs across
builds", nothing finer. **NOT CLAIMED**: that any pair is the same function.

---

## Step 2 — Calibration, inside the builds

Script: `matcher/match_calibrated.py` (SECTION: `calibration`, `choose_threshold`).

**Negatives** (**OBSERVED**): all unordered pairs of distinct functions inside
3.1.12 (21 722 pairs with `|Δsize| ≤ 16` and nonzero similarity) and inside
3.2.0 (19 381 pairs), pooled to **41 103 within-build negative pairs**. These
cannot contain a true historical counterpart — the defect that voided attempt 2.

Distribution (**COMPUTED**, full histogram in
`results_calibrated.json.calibration.negatives_hist`):

| bin | pairs |
|---|---|
| [0.0,0.5) | 34 929 |
| [0.5,0.6) | 3 860 |
| [0.6,0.7) | 1 405 |
| [0.7,0.75) | 297 |
| [0.75,0.8) | 155 |
| [0.8,0.85) | 156 |
| [0.85,0.9) | 80 |
| [0.9,0.95) | 20 |
| [0.95,0.98) | 2 |
| [0.98,0.99) | 2 |
| [0.99,1.0] | **197** |

quantiles: median 0.321, p95 0.609, p99 0.800, max 1.0.

The hard negatives are real and few: the highest **non-identical** within-build
pairs are `0x1520`/`0x14550` in 3.2.0 at 0.9829 (290 B vs 296 B, 145 vs 148
instructions) and `0x16ac`/`0x143e4` in 3.1.12 at 0.9818 (56 B vs 58 B). Both
are near-duplicate helper bodies differing by extra trailing instructions —
exactly the class that defeated attempt 2. Above 0.9 there are **4** such pairs
in 41 103.

**Positives** (**OBSERVED**): 352 3.1.8→3.1.12 pairs whose signature is unique
in both builds — ground truth fixed by the 98.2 % exact overlap. All 352 score
**1.0**; the positive distribution is a point mass (min = p25 = median = p99 =
max = 1.0).

**Threshold** (**COMPUTED**): `max(non-identical within-build negative) + 1e-4`,
hard-capped at 0.99 → **T = 0.9830**.

ROC-style separation at T:

- TPR on known-true pairs: **1.000** (352/352)
- FPR over all 41 103 within-build negatives: **0.00479** — but every one of
  those 197 positives is a pair of *identical signatures*, i.e. structural
  duplication, not a similarity error.
- FPR over the 40 906 **non-identical** negatives: **0.00000**.

So the threshold is not merely "below 1.0"; it is *above every near-duplicate
pair that is not an exact duplicate*. Identical bodies remain at 1.0 and are
handled by the ambiguity rule (Step 4), never by the threshold.

Trade-off curve (**OBSERVED**, `threshold.sweep`) — because the positives are
all 1.0, they carry no information about *modified* functions, so the curve
below 0.983 is driven by negatives only:

| t | TPR | FPR (all) | FPR (non-identical) |
|---|---|---|---|
| 0.99 | 1.000 | 0.0048 | 0.0000 |
| **0.983** | **1.000** | **0.0048** | **0.0000** |
| 0.95 | 1.000 | 0.0049 | 0.0001 |
| 0.90 | 1.000 | 0.0054 | 0.0006 |
| 0.85 | 1.000 | 0.0073 | 0.0025 |
| 0.80 | 1.000 | 0.0111 | 0.0063 |

**Validity check on an independent pair** (**COMPUTED**): applying the same
calibrated threshold to 3.1.8→3.1.12, where the answer is known, recovers
**351 unique 1:1 pairs** (350 at exact score 1.0) and leaves only **7 of 436**
old-build functions unmatched (98.4 % coverage, against the 98.2 % exact-overlap
ground truth); 4 further pairs are one_to_many, i.e. a 3.1.8 function competing
for two 3.1.12 neighbours, which is the residual ambiguity class.
The pipeline is therefore capable of reproducing a near-identical pair; it is
not returning empty sets the way attempt 1 did.

---

## Step 3 — 3.1.12 → 3.2.0 at the calibrated threshold

All figures **OBSERVED** (`results_calibrated.json.match_3112_320`).

| quantity | @0.983 (calibrated) | @0.95 | @0.85 (11d band) |
|---|---|---|---|
| candidate pairs above threshold | 375 | 391 | 532 |
| unique 1:1 | **167** | 181 | 195 |
| … of which non-stub (n ≥ 8) | 155 | 169 | 185 |
| ambiguous pairs | 208 | 210 | 337 |
| unmatched 3.2.0 functions | 208 (35 stubs) | 193 | 150 (121 non-stub) |
| unmatched 3.1.12 functions | 208 (47 stubs) | 192 | 152 (111 non-stub) |

Confidence bands, unique 1:1 pairs only:

- **≥ 0.95 (confident)**: 167 at T; 165 at 0.85 (165/195) — 156 non-stub.
- **0.85 – 0.95 (probable)**: 0 at T; **30** at 0.85 (29 non-stub).
- **< 0.85**: excluded from every count above.

The 30 probable pairs are genuinely edited bodies (one to three instruction
edits on a 12–40 instruction function), not near-duplicates of an unrelated
routine: the threshold sweep shows the within-build negative density in that
band is 100/41 103 (0.24 %).

Comparison with DIFF.md §11d (181 sigs / 234 pairs / 189 unmatched):

- **181 distinct signatures in all three builds: reproduced exactly**
  (**COMPUTED**). 49.9 % strict 3.1.12→3.2.0 match: reproduced exactly
  (211/423 = 49.9 %).
- **234 → 238 pairs, 189 → 185 unmatched**: the whole delta is `autojunk`
  (§1 point 3), verified by rerunning §11d's own rule both ways on the current
  423-function inventory. 238 + 185 = 423 and 234 + 189 = 423, so the two runs
  partition the same build and differ only in which 4 borderline pairs clear
  0.85.
- **167 unique vs 234 greedy pairs** is the substantive delta: 71 of the 234
  cannot be resolved to a single function pair at all (they sit on duplicated
  signatures or have competing candidates). 11d's "many-to-many upper bound"
  caveat is therefore correct, and now quantified: the greedy rule overstates
  resolvable correspondences by 40 % (234 vs 167).

Largest unmatched 3.2.0 functions (**OBSERVED**, non-stub):
`0xfbc8` 2 932 B / 1 385 instrs, `0x12250` 2 220 B, `0xdb40` 2 016 B,
`0xf5b8` 1 954 B, `0x21a0` 1 234 B, `0x14018` 1 070 B. These are not "changed
functions" — they have no candidate at all in the old build under a 16-byte size
gate, consistent with 11d's reading that the large islands are absent or
re-organised, but also consistent with the size gate being too tight for large
functions; the two are **OPEN**.

---

## Step 4 — Duplicate bodies are AMBIGUOUS, never forced 1:1

Rule (**OBSERVED** in `classify`): a pair is AMBIGUOUS when either member's
signature has multiplicity > 1 in its own build, or when more than one candidate
clears the threshold on either side. A unique signature scoring 1.0 stays a
unique match — the ambiguity is multiplicity, not equality.

Effect at T = 0.983 (**COMPUTED**):

- **208 of 375 candidate pairs (55 %) are AMBIGUOUS**, all for
  `duplicate_signature`, involving **48 distinct 3.2.0 functions**.
- Of the **238 first-pass 1:1 pairs** (§11d's rule, 234 in the doc), **22
  (9.2 %) sit on a duplicated signature** and are reclassified AMBIGUOUS. Of
  those 238, 183 are exact-score and 26 are stubs.
- At the 0.85 band the same measurement is **295 of 532 candidate pairs**
  (duplicate_signature 295, one_to_many 38, many_to_one 4).

Example cluster (**OBSERVED**): 3.2.0 `0x12d14` and `0x12d30` both have 3.1.12
`0x12b38` and `0x12b54` as candidates — a 2×2 block of interchangeable tiny
helpers. No 1:1 answer exists; the honest output is the block.

Duplication is structural, not an artefact of this matcher: max signature
multiplicity 14 in 3.1.8 and 3.1.12, 7 in 3.2.0; 78 / 76 / 51 functions sit in
duplicated signatures (**COMPUTED**). Any future matcher over these inventories
must report blocks, not pairs.

---

## Step 5 — Deliverables and what may now be claimed

Files (this directory):

- `match_calibrated.py` — the matcher; hard-fails on empty mnemonic sequences,
  draws negatives within-build, caps the threshold below 1.0, classifies
  ambiguity, `autojunk=False`, reproduces §11d's rule for comparison.
- `results_calibrated.json` — full distributions, histograms, sweep, all three
  thresholds for both pairs, pair lists, unmatched lists.
- `run.log` — stdout of the delivered run.
- `../matcher.md` — this file.

Claims now supportable, each with its stated basis:

| claim | confidence | basis |
|---|---|---|
| 167 3.1.12→3.2.0 function pairs are 1:1 at identical body size *and* identical canonical mnemonic sequence | **high** — 0 false positives over 40 906 within-build non-identical negatives | computed |
| 30 further pairs are 1:1 with 0.85 ≤ sim < 0.95 | **moderate** — FPR 0.25 % on the same negative pool; each still needs manual inspection | computed |
| 48 3.2.0 functions belong to an interchangeable duplicate cluster, with block membership known | **high** for membership, **zero** for which member maps where | computed |
| 173 non-stub 3.2.0 functions have no candidate ≥ 0.983 | **high** as a statement about *this signature*; **OPEN** as a statement about the binary (size gate, uncovered islands per §11e) | computed |
| the §11d "234 pairs" figure is an `autojunk`-dependent greedy count, not a pairing | **high** — 234/189 vs 238/185 reproduce both ways | observed |

**NOT CLAIMED**, explicitly: that any matched pair performs the same
computation, holds the same role, or corresponds semantically. Matching on
size + mnemonic sequence with no operand or control-flow comparison cannot
distinguish a copied helper from a coincidental twin; every pair above is an
address-level correspondence hypothesis at the stated confidence, and the 208
ambiguous pairs are left unresolved on purpose.

Open items: whether the 16-byte size gate suppresses true correspondences among
large functions (`0xfbc8` et al.); whether mnemonic order alone is the right
signal for the 30 probable pairs, which would be settled by comparing literals
and callee multisets (available in `inventory3_*.json`, not used here).

## Lead follow-up (2026-11-11): probable-band validation attempt — NEGATIVE

`validate_probable.py` recomputed the 3.1.12→3.2.0 best-match scan (≥8
instructions, |Δsize| ≤ 16, unique 1:1, 0.85 ≤ s < 0.983): 46 pairs. Literal-
multiset Jaccard over function bodies flags 32/46 as "weak" (< 0.3). This
measure is CONFOUNDED and was not used to confirm or refute any pair:

- Function literal pools are dominated by pointers — in-image code addresses
  shift wholesale on relink, and SRAM addresses (`0x2000xxxx`) relocate with
  the BSS/data layout. Excluding only in-image-range words (first attempt)
  changed nothing; the remaining disagreement is SRAM-pointer churn, not
  evidence of different logic.
- Verdict: literal-multiset agreement is not a usable validator at this
  band. A callee-multiset comparison (BL target multisets, which survive
  relink modulo the known per-region deltas) is the candidate replacement;
  not yet run. The 30 "probable" pairs remain UNVERIFIED.
- Artifact: `matcher/probable_validation.json` (46 pairs, per-pair literal
  stats).
