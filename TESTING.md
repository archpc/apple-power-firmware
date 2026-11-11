# TESTING — deterministic checks

`scripts/verify_docs.py .` runs every check below and exits non-zero on any
failure. Checks that need the proprietary firmware images (not committed) report
**SKIP** with a named reason rather than failing, so CI validates documentation
without the images.

## What is asserted

| check | asserts | needs images |
|---|---|---|
| legacy evidence labels absent | no `CONFIRMED`/`VERIFIED` label survives in the research documents (`REVIEW-FABLE.md` excluded: external artifact) | no |
| label scale defined in README | all six labels present and defined | no |
| no duplicated paragraphs | no block over 120 chars repeated within a document | no |
| documented paths exist | every `scripts/…`, `evidence/…`, `firmware/…` path in backticks resolves | no |
| claims table reconciled | `DISPOSITION.md` maps at least 40 claims and references the review | no |
| retractions recorded | the five withdrawn claims are present in `DIFF.md` | no |
| firmware image hashes | `shasum -a 256 -c SHA256SUMS` | yes |
| PDO table invariant | all builds carry `5.00/9.00/15.00/20.00 V @ 3.00 A` | yes |
| literal sets disjoint | `28` is 3.2.0-only; intersection 13, only-A 7, only-B 1 | yes |
| dispatcher inventory | 14/14/10 sites; 14-case table in 3.1.x, absent in 3.2.0 | yes |
| function coverage | 38.8 / 39.4 / 43.3 % whole-image | yes |

## Recorded results

Run against the local artifact tree with images present:

```
11/11 checks passed
```

Run without `firmware/images` (the CI condition): the six document checks pass and
the five numeric checks report SKIP with `images absent`.

## Deliberate non-checks

- **No assertion that any firmware claim is true.** These checks verify that the
  documents, data and scripts agree with each other and with the recorded bytes.
  They cannot verify that a decompiler reading is correct, and they do not try.
- **No regional coverage assertion.** Fixed address windows are not comparable
  across builds (`DIFF.md` §3), so asserting them would encode the error the
  review found.
- **No matcher threshold assertion.** Both calibrated runs were void; asserting a
  match count would launder a broken procedure into a test.

## Failure handling

Every check reports PASS, FAIL or SKIP with a one-line reason and a value. A
failing check was fixed at the document or script level, never by relaxing the
assertion. The two runs that produced zero matches are retained under
`evidence/functionmatch/` and described in `DIFF.md` §10; they are not tests.
