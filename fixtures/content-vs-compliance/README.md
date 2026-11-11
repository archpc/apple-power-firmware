# Fixture: compliance without quality

Two publications of the same research, both produced by this skill, both passing
every structural check it enforces.

| file | what it is |
|---|---|
| `../publication/prior/claim-register-6pp.pdf` | the first publication: executive summary, method, 23-claim register, corrections table, limitations |
| `../publication/current/apple-power-firmware.pdf` | the rebuild: three firmware objects, power path, acquisition, container format, image anatomy, cross-version table, claims examined individually, host stack, security, limits, method, register as appendix |
| `*.typ`, `*.json` | the sources and metadata each PDF came from, as snapshots |

The PDFs are not duplicated here. `publication/` holds one copy of each build; this
directory holds the sources, the comparison script and the judgement. `compare.py`
resolves both PDFs relative to `../../publication/`.

`compare.py` measures both and stops. It reports pages, selectable characters,
heading count, table count and claim markers — and prints no verdict.

## Why it exists

The six-page document satisfied the gate completely: text layer present, no blank
pages, evidence manifest resolved 23 claims and 71 refs, layout gate clean, two
builds byte-identical. It was nevertheless a bad report. It opened with a claim
that three firmware objects exist, then listed the claims that said so, and never
explained what was done, what was found, or why any of it was hard.

Nothing in this skill detected that, and nothing should pretend to. The lesson is
narrow and mechanical: **a gate that measures anchoring cannot measure
usefulness**, so a publication which passes only proves that its claims are
traceable.

## How to use it

When changing the skill — components, authoring rules, the gate — re-read both
PDFs and ask which one the change serves. Concretely:

- A new component should make the nine-page shape easier to write, not easier to
  pad.
- A new check must not claim to distinguish these two documents. If a proposed
  rule would reject the six-page file, ask whether it also rejects a legitimate
  short report; brevity is not the defect, absence of research content is.
- `compare.py` is deliberately inert. Adding a score, a threshold or a "quality"
  field would convert this fixture into exactly the false assurance it was built
  to prevent.

## Reproducing the PDFs

The sources are snapshots and will not rebuild in place: `report.typ` references
evidence files in this repository (`../evidence/...`), which is, which is not part of
this skill. Rebuild from
this repository's root with `scripts/build_report.py` for the
nine-page version; the six-page version is the same script before it gained the
narrative sections and is preserved here because that state no longer exists on
disk.

Generation identifiers: six-page `552a3e6f895d97f0`, nine-page `1848b3a363df46de`.

---

# Editorial decision record

Written by the author of both documents, for readers of neither. This is a record
of judgement at a fixed point, not a specification. It exists so a future reviewer
has a concrete standard rather than a vibe, and it is deliberately not executable.

## 1. What the nine-page report let a technically literate reader understand

Not "it had more sections". These are specific things a competent reader could not
recover from the six-page version:

- **Which numbers were read and which were merely reported.** The six-page version
  said three firmware objects exist, then listed a claim that they are distinct.
  It never said that the HPM and cable values were read out of the machine while
  the adapter's `1030030` came from the host's own reporting and no adapter image
  exists. A reader could not tell the two evidential classes apart, and the one
  number that was weakest looked exactly like the two that were strongest.
- **How the firmware was obtained at all.** The method was two sentences. Without
  the MobileAsset path, the CDN, the SHA-1 check against Apple's `_Measurement`,
  and the fact that unpacking came from Apple's parser rather than a hex guess, a
  reader had no way to judge whether the images were authentic or the extraction
  was sound.
- **Why the container format can be trusted.** The difference between "we inferred
  a structure that looks plausible" and "the host enforces this structure" is the
  whole basis for the extraction, and it was absent.
- **That a negotiated contract is not a firmware property.** 67.80 W is a
  negotiation result. Presenting it beside firmware identifiers without that
  distinction invites exactly the category error the report exists to correct.
- **Why 5.9 % window overlap is not a rewrite.** The six-page version reported the
  retraction; it did not give the reason a reader needs in order to evaluate the
  retraction itself.
- **Why the hard-reset claim fails mechanically** — Hard_Reset has no MessageType,
  so a switch over message types 9–22 cannot address it. Stated as a verdict
  without the mechanism, it reads as an opinion.
- **What `OPEN` costs.** Coverage of 38.8 % with the relevant paths outside the
  analysed set is the reason several questions are unanswered. Without that, `OPEN`
  looks like caution rather than arithmetic.

## 2. What was already there but badly organised

Almost everything. This is the uncomfortable part of the record: the nine-page
version contains very little that did not already exist somewhere in the documents.

- The `0x1111c` bytes, the peripheral-address interpretation, and the base caveat
  were all in `FIRMWARE.md` §5 and §7. The six-page report reduced them to a claim
  line with no bytes and no arithmetic.
- The PDO addresses, literal counts and dispatcher census were already tabulated
  in `DIFF.md`. The six-page body asserted "identical across builds" without
  showing the table that establishes it.
- The three 2026 claims were each answered in `DIFF.md` with a distinct verdict
  (refuted, open, unsupported). The six-page version carried single-sentence claim
  entries, which flattened three different kinds of answer into one shape.
- The evidence labels were defined in the README and then not used inline, so the
  body read as bare assertion while the definitions sat in a document the reader
  was not looking at.

What was missing was sequence, not substance: which object, read how, implying
what. The six-page version was ordered by claim identifier, which is an artifact of
the verification machinery. That ordering is correct for an appendix and wrong for
a report — the document had been organised around the tool that checked it.

## 3. What would make a future revision worse while still passing every check

Each of these passes the gate today. That is the point of listing them.

- **Restating claims in prose to look thorough.** Anchors still resolve, the page
  count rises, and nothing new is asserted. Padding is invisible to a check that
  asks only whether each claim is anchored.
- **Softening a negative into a vague one.** "Could not be obtained by three
  enumeration methods, which bounds the claim to Apple's public catalogue" becomes
  "could not be obtained". The claim still anchors; the reader loses the boundary
  and reads absence as proof.
- **Hedging `OPEN` items into confident-sounding prose.** "Likely reflects a
  compiler change" reads as a finding and still satisfies a label check whose
  window does not reach it.
- **Merging host-observed with host-reported.** One sentence that treats the
  adapter value and the cable version as equally established destroys the
  distinction the whole report is built on, and no numeric check notices.
- **Treating the nine-page shape as the required shape.** Thirteen sections and
  three tables is what this project needed. A narrow finding forced into that
  skeleton produces filler, and filler passes.
- **Replacing raw counts with narrative summary.** "The dispatch mechanism changed
  substantially" while the census table disappears — the reader can no longer
  check the claim, but nothing fails.
- **Trimming limitations to save a page.** The limits are the load-bearing part of
  a report whose main result is a set of `OPEN` questions.
- **Returning the claim register to the body.** The single most likely regression,
  because it is the easiest thing to generate.

## 4. What this fixture is not

**A five-page report could be better than either of these.** Nothing here argues
for length, section count, or the presence of tables. The objective is not to
reproduce the nine-page shape; it is to preserve the qualities that made it useful:
evidence classes kept distinct, method stated well enough to be judged, negatives
carrying their scope, verdicts carrying their mechanism, and limits doing real work.

**The fixture must not become a benchmark.** It has no threshold, no score, and no
place in CI. No check in this skill consumes it, and none should be added that
does. A number derived from these two documents would be optimised against, and the
first casualty would be the honesty of the `OPEN` sections — the cheapest thing to
make look resolved.

If a future change to the skill needs this fixture to pass, that is a defect in the
change. The correct use is to read both documents and ask which one the change
serves.

This is the stopping point for this fixture. The next improvement to the skill
should come from another real reporting failure, not from refining this record.

