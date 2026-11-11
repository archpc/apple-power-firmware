# VERIFICATION — release gate record

Run order: document corrections → cross-document reconciliation → regression
cases → PDF publication → final committed state. Every number below is from a run
on this tree, not from memory.

## 1. Commands and results

```
$ python3 scripts/verify_docs.py .
11 passed, 0 skipped, 0 failed

$ python3 scripts/verify_claims.py .
PASS 23 claims reconciled across 11 documents; 0 presence, label, ban, numeric,
     scope, summary or relation failures

$ python3 scripts/regress_release.py .
9/9 mandatory regression cases passed

$ shasum -a 256 -c SHA256SUMS
7 of 7 OK

$ python3 ~/.hermes/skills/research/research-pdf/scripts/build.py \
    --content report.typ --meta report.json \
    --out publication/apple-power-firmware.pdf --inspect
evidence ok: 23 claims, 71 refs
layout: 7 renderer elements, 0 hard, 0 warn, 0 other
verified: 6 pages, text layer present, no blank pages

$ build.py --verify publication/apple-power-firmware.pdf
verified generation: apple-power-firmware.pdf
```

Two consecutive builds produced byte-identical output (see §5).

## 2. Cross-document claim reconciliation

`claims/manifest.json` holds 23 canonical claims. For each: canonical statement,
one label, a primary evidence anchor, every document repeating it, and any
supersedes/depends/ban relation. `scripts/verify_claims.py` enforces, per
claim:

- **presence** — every recorded occurrence exists in the named document;
- **label** — the claim's paragraph may not assert a conflicting label
  (`OPEN` is treated as an uncertainty marker, not a competing assertion);
- **ban** — withdrawn wording may not appear in a conclusion region: the
  executive summary, the README accomplishments list, or `DIFF.md` §8;
- **numeric** — declared numeric invariants are present somewhere in the corpus;
- **scope** — negative findings keep their search scope in the paragraph;
- **summary** — the executive summary states a limitation;
- **relations** — every supersedes/depends target resolves.

What this does **not** prove: that a decompiler reading is correct, or that a
keyword match equals semantic consistency. It proves the documents agree with each
other and with the recorded bytes. Contextual review of every changed section was
done by hand alongside it.

### Contradictions found and fixed during this gate

| # | contradiction | resolution |
|---|---|---|
| 1 | `REPORT.md` still carried regional coverage (~50 % / 0 %), which `DIFF.md` §3 had withdrawn as non-comparable | replaced with whole-image 38.8 / 39.4 / 43.3 % |
| 2 | Coverage figures had been computed against one denominator for all three images | recomputed per image: 38.8 / 39.4 / 43.3 (was 38.5 / 39.2) |
| 3 | `PROTOCOL.md` line 60 said the header formula matched `0x21`; line 68 said it yielded `0x01` | the `8` was the payload bit count, not the SOP selector; formula reproduces `0x21`; mismatch retracted |
| 4 | `FIRMWARE.md` §7 described `0x111c` as code-like; `DIFF.md` said constant data | `0x1111c` holds `0x4005xxxx` peripheral addresses: constant data. The correction landed before the first commit, so no committed revision contains the pre-fix wording |
| 5 | `DIFF.md` §4b cited a `FIRMWARE.md` §7 statement that did not exist at the time of writing | reference corrected to "records the same limit", and §7 now carries the UNVERIFIED bullet. As with row 4 the fix predates the first commit |
| 6 | Label migration corrupted `UNVERIFIED` → `UNOBSERVED` in five documents (13 occurrences) | restored; the checker now tests label *forms* only |

## 3. Mandatory regression cases

| case | asserted | result |
|---|---|---|
| R1 | literal sets: 11 shared, 7 lost, 1 gained, `28` exclusive to 3.2.0 | PASS |
| R2 | word at image offset `0x04` = `0x0001111d`; target `0x1111c` holds `0x4005xxxx` pointers | PASS |
| R3 | `0xEC89`/`0xEC71` exceed `0xEA00` (base zero impossible); base `0x400` places both inside | PASS |
| R4 | `(2 << 4) | ceil(4/4)` = `0x21`, matching the recorded header | PASS |
| R5 | 14-case table in both 3.1.x, 6 unique targets, 8/14 to `0xb1a8`, absent in 3.2.0 | PASS |
| R6 | no replacement/reorganisation claim in any conclusion | PASS |
| R7 | UVDM builder identification asserted nowhere; recorded UNVERIFIED | PASS |
| R8 | 5.9 % overlap described as layout; semantic verdict retracted, quoted once | PASS |
| R9 | REPORT and DIFF agree on coverage; no regional figures survive | PASS |

## 4. Fable review disposition

All 9 Critical/High findings and all 40 audited claims are mapped in
`DISPOSITION.md`: 13 FIXED, 11 RESTATED, 2 RELABELLED,
19 RETAINED, 2 MARKED OPEN, 2 REFUTED. An earlier
revision of this section quoted a tally that was wrong on both count and arithmetic;
these figures are recomputed from the table. No finding was disputed. Two of the review's arithmetic findings were
re-derived and confirmed here, and a third error the review did not catch (the
shared/union constant mislabelling) was found by the user and re-derived.

## 5. PDF publication

| field | value |
|---|---|
| file | `publication/apple-power-firmware.pdf` |
| generation id | `552a3e6f895d97f0` |
| SHA-256 | `552a3e6f895d97f0ca47812593c47a90a768323c7e4a3654f36bc857f327fcb8` |
| pages | 6, no blank pages |
| text layer | 8328 selectable characters |
| template | research-pdf v1.2.0, Typst 0.15.1 |
| evidence | 23 claims, 71 refs, all resolved |
| determinism | two builds, byte-identical |
| layout gate | 0 hard failures, 0 warnings |

One deliberate layout change was made and inspected: `section_breaks` was
disabled because a forced break stranded §Method alone on page 4 (about 60 % blank).
The resulting baseline drift was resolved by looking at the changed page and then
approving the new baseline — not by suppressing the check.

PDF content was compared against the source documents: the claim register, the
corrections table and the limitations section all re-derive from
`claims/manifest.json`, so no figure in the PDF exists independently of the
manifest that the documents are checked against.

## 6. Outstanding limitations

- Function coverage is 38.8 / 39.4 / 43.3 %; the control-message switch and Apple
  SVID literal sites are outside the analysed set.
- No per-function matching result is reported; both calibrated runs were void and
  the causes are recorded.
- 70 W adapter firmware is not publicly obtainable; adapter behaviour is
  host-observed only.
- Load base, C99 header fields, signature/anti-rollback enforcement below the
  manifest hash, and whether the Mode 7 read verb can touch flash: `OPEN`.
- CI cannot run the six image-dependent checks; it runs the document, claim and
  document-level regression checks and prints exactly what it skips.

## 7. Release readiness

Claim reconciliation, mandatory regressions and PDF publication all pass on this
tree. Verdict: **ready for review**, subject to the PR review outcome recorded in
the final commit message.

## 8. Final committed state

| field | value |
|---|---|
| branch | `feature/release-verification` |
| verified commit | `c1fe423739e43abf82247a38c65285040c0c87d9` |
| CI (GitHub Actions, `verify`) | pass — `verify_docs` 6 passed / 5 skipped, `verify_claims` 23 claims, `regress_release` document-level cases pass |
| local suite on the same commit | `verify_docs` 11/11, `verify_claims` 23 claims / 71 refs, `regress_release` 9/9 |
| PDF | `552a3e6f895d97f0`, SHA-256 `552a3e6f895d97f0ca47812593c47a90a768323c7e4a3654f36bc857f327fcb8` |

CI and the local suite differ only in the six checks that need the firmware images,
which are not committed; CI names each skipped check in its log rather than
reporting a false pass. This file's own commit follows the verified one and changes
documentation only.

### Approval status

The repository has one collaborator (`archpc`), so no independent reviewer is
available and self-approval is not acceptable. The PR is therefore left open and
ready for review with all required checks green. This is the precise blocker to
merge: absent an authorised second reviewer, approval cannot be obtained.

## 9. Post-merge independent audit (issue #3)

An independent documents-only audit found four surviving defects that the 23-claim
gate could not catch, because the manifest held no claim for them. All are fixed
and each now has a claim (C23–C26) and a regression guard:

| defect | fix |
|---|---|
| `REPORT.md` still said "Each was independently confirmed" and "recovered twice" | rewritten: adapter value host-reported only; cable version a single in-file source |
| `REPORT.md` still said the 140 W image "makes the MagSafe reading trustworthy" | rewritten: it does not corroborate base zero |
| `REPORT.md` called the entry-point question "Closed"; `0x111c` a "byte-copy leaf" | rewritten: **OPEN**, `0x1111c` holds peripheral addresses |
| `DIFF.md` §8 said "15 sites" for 3.2.0; the census says 10 | corrected to 10 |

Two rows of §2 above were also inaccurate about the record: the corrections they
describe landed before the first commit, so no committed revision contains the
pre-fix wording. Both rows now say so. The §4 disposition tally was wrong on count
and arithmetic and is now recomputed from the table: 13 FIXED, 11 RESTATED,
2 RELABELLED, 19 RETAINED, 2 OPEN, 2 REFUTED across 49 rows.

Limitation recorded: the ban check only covers three conclusion regions, so a stale
sentence reintroduced elsewhere is caught by the presence check on the corrected
text, not by the ban.
