# REVIEW-FABLE — documentation and evidence-quality audit

Scope: REPORT.md, DIFF.md, PROTOCOL.md (primary); FIRMWARE.md, HARDWARE.md,
SECURITY.md, NEXT.md, EXTRACTION-NOTES.md (supporting). Documents only.
Line numbers (`L`) refer to the files as they stood on 2026-11-11.

Excluded, by instruction or by choice:

- Nothing in `firmware/` or `kexts/` was opened or listed. Cross-references into
  `firmware/` (`MANIFEST.txt`, `images/*.bin`) are therefore unchecked.
- No script was run or read. No binary was disassembled. No evidence file was
  opened. `evidence/`, `scripts/`, `ghidra/`, `host/` were listed by filename
  only, to test cross-references.
- No number in the reports was checked against data. Every arithmetic check
  below uses only numbers printed in the documents.
- Two findings (H4, L5) use the public USB-PD specification as a reference.
  They are marked. Nothing here asserts what the binaries contain.

---

## 1. Overall assessment

Reliability is uneven and splits cleanly by document.

- Trustworthy as written: host observation (HARDWARE.md), SuperBinary container
  parse (FIRMWARE.md §2–3), BootKC extraction (EXTRACTION-NOTES.md), PDO table
  identity (DIFF.md §6), the raw constant counts (DIFF.md §5, as counts).
- Not trustworthy as written: every statement in DIFF.md §4, §4a, §4b that goes
  beyond "these bytes / this table shape is or is not present"; the entry-point
  closure in REPORT.md §4; the "frame format (CONFIRMED)" in PROTOCOL.md §2; the
  "CONFIRMED twice" headline in REPORT.md §1.

DIFF.md is honest about its failures and still does not obey its own limits. It
retracts one inference from byte layout to source change (§1), then makes the
same class of inference twice in the opposite direction (§4, §4a). It declares
"no semantic-equivalence verdict" and, in §4a, issues one. It names three
evidence items as "the only trustworthy diff evidence" (§10) while two further
sections carry the heading "Verified evidence".

REPORT.md is more cautious than DIFF.md on the diff, and less cautious than its
supporting documents on three other points (version confirmation, entry point,
adapter firmware availability). It was last written before DIFF.md and is stale
against it in at least three places.

No executive conclusion depends on the two void matcher runs. One surviving
claim (the §4a function pairing) has no documented source run at all.

---

## 2. Findings

Tag after each ID: [R] = defect in the research reasoning or method.
[P] = defect in presentation (labels, counts, transcription, staleness).

### Critical

**C1 [R][P] DIFF.md issues a semantic verdict it says it withholds.**

Refs: DIFF.md status L3; §4a L155-160, L166-167; §9 L299; §10 L314-315;
REPORT.md §4 L117-123.

Quotes:
- "Status: **no semantic-equivalence verdict.**"
- "Losing `1024` and `92`/`80`/`19` from a reset-path handler is a semantic
  difference, not a code-generation difference: those are comparison and size
  values, which come from source."
- "A changed constant set tells us the handler's logic differs."
- "Withheld: Whether 3.2.0 is semantically equivalent to 3.1.12."
- "the switch census (§4), the constant counts (§5) and the PDO table (§6) are
  the only trustworthy diff evidence"

Why it matters: a semantic difference in one handler is a non-equivalence
verdict. The document asserts it and withholds it at once. §10 and REPORT.md
both exclude §4a from the trustworthy set, yet §4a is headed "Verified evidence"
and opens with a bold flat claim. A reader cannot tell which status applies.

The assertion itself is not supported by what §4a describes:

1. The pairing is inferred. Same section: "It is nonetheless an inferred
   pairing. A competing candidate was not ruled out by an exhaustive search."
   Every constant difference is conditional on that pairing. The bold claim
   "**The shared handler changed.**" drops the condition.
2. "which come from source" is the retracted §1 error reversed. §1: low overlap
   "is consistent with recompilation *and* with rewriting, and cannot separate
   them." Constants in decompiler pseudocode of one function also change under
   inlining, outlining and function splitting, which §2 lists as "permitted
   outcomes". A function 21 instructions shorter that lost constants and gained
   at most one fits code moved out of the body as well as it fits changed logic.
3. "those are comparison and size values" is asserted. Three lines later:
   "neither `3, 8, 10, 19, 80, 92, 1024` nor `28` has been identified with a
   protocol field." The role of the constants is unknown by the document's own
   statement.
4. "reset-path handler" labels a handler by one of the eight case values that
   reach it. Nothing ties the 3.2.0 function `0x0B18C` to any dispatch table:
   §4 says "Nothing here maps 3.2.0's message types to handlers", and the
   dominant targets of the two 3.2.0 switches are `0x0554A` and `0x05704`, not
   an address in `0x0B18C`. The closing claim that this evidence is "about the
   reset-dispatch path" is unsupported for the 3.2.0 side.
5. The compared unit is a Ghidra body, not the handler. The handler `0xB1A8` is
   `0xB8` bytes inside "function `0x0B0F0`", while the dispatcher (`0xAA2A`)
   and the other five case targets (`0x0AEE4`–`0x0AFC6`) lie before `0x0B0F0`.
   The documents do not show that `0x0B0F0` is a true function entry, and §3
   states the same Ghidra run mis-delimits code. Documentation insufficient.
6. No control. The same handler exists in 3.1.8 (`0xB154`, counterpart address
   not given). No 3.1.8 vs 3.1.12 comparison is reported, so there is no
   baseline for how much instruction count, pseudocode length or constant set
   varies between builds the report treats as near-identical.

Correction: retitle §4a as inferred. State the result as: "under an unvalidated
pairing, the two Ghidra bodies differ in length and in pseudocode constant set;
cause undetermined (source change, inlining/outlining, or mis-pairing)". Delete
"semantic difference, not a code-generation difference" and "the handler's
logic differs". Then make §9, §10 and the status line agree with whatever
status §4a is given.

**C2 [R] An absent table shape is promoted to a source-level change, then to
"new control-message dispatchers".**

Refs: DIFF.md §3 L70-72; §4 L119-126; §8 L278; §9 L292-293; REPORT.md §4
L101-102.

Quotes, in order of escalation:
- "the two candidate 3.2.0 sites (`0x4EE2`, `0x5166`)"
- "**Structural change: established.** ... two switches of 15 and 13 cases
  appear. Case counts come from source, not code generation, so this is not
  attributable to the compiler."
- "replaced by 15- and 13-case switches"
- "3.2.0 reorganised its control-message dispatch structures (structural
  `CODE_CHANGED`; not a behaviour claim)."
- REPORT.md: "the two new control-message dispatchers in 3.2.0"

Why it matters: four separate steps, none demonstrated.

1. What the census demonstrates: a table with fingerprint (14 cases, 6 unique,
   8 to one target) is found in 3.1.8 and 3.1.12 and not found in 3.2.0 by a
   detector that only sees `mov pc, Rn` sites with absolute pointer tables.
2. "Case counts come from source" is wrong as an inference rule. A dense jump
   table's length is the guard's range span, and 8 of 14 entries here go to one
   shared target. Whether a switch becomes one table, two tables, or a compare
   chain is a code-generation decision. The same section concedes "the idiom
   changed". A different lowering of the same source produces exactly the
   observation in step 1.
3. "appear" and "replaced by" need the 3.1.x inventory. The census reports 14
   tables in each 3.1.x build and describes one. Whether 3.1.x also contains
   15- and 13-case tables is not documented. Without that list, "new" is
   unsupported.
4. The two 3.2.0 sites are selected only as "its largest tables". Nothing
   identifies them as control-message dispatchers. The same bullet says they
   may be "a different switch entirely".
5. `CODE_CHANGED` is defined in §2 for a matched pair ("constants or topology
   differ"). No 3.2.0 counterpart was identified, so the document's own
   vocabulary gives `NO_MATCH`.
6. The identification of the 3.1.x switch as a *PD message-type* dispatcher is
   itself undemonstrated in the documents. The stated basis is the guard range
   9–22 containing `0x0D`. How the switch operand was traced to the PD header
   is not described. §11 meanwhile reports zero hits for "PD message-type
   constant runs".

Correction: issue only "the 14-case/6-unique/8-dominant table fingerprint is
present in 3.1.8 and 3.1.12 and not detected in 3.2.0". Publish all 14/14/10
tables per build with site, table address, case count, unique count. Change
`CODE_CHANGED` to `NO_MATCH` or "unresolved". Change REPORT.md to "two candidate
switch sites of unknown role".

### High

**H1 [P][R] The §4a constant table is internally impossible.**

Ref: DIFF.md §4a L147-151, L155-158, L163.

Quote:
```
shared        : 4 14 28 32 33 62 84 85 88 105 444 460   (11 values)
only in 3.1.12: 3 8 10 19 80 92 1024
only in 3.2.0 : 28
```

Defects: the shared row prints 12 values and is labelled 11. `28` is in both
the intersection and the 3.2.0-only difference, which no set comparison can
produce.

Three readings:

| reading | edit needed | effect on the text |
|---|---|---|
| (a) transcription: `28` wrongly copied into the shared row | remove `28` from shared | shared = 11, count correct, prose stands as written |
| (b) arithmetic: count wrong, and `28` wrongly listed as new | count → 12, 3.2.0-only → empty | 3.2.0 set is a strict subset of 3.1.12. "The constant set is not a superset or subset" and "gained one (`28`)" are both false |
| (c) multiset overlap: `28` occurs more often in 3.2.0 | print multiplicities; count → 12 | not defensible as printed: the section says "Constant sets", argues in set terms, and prints no multiplicities |

Determination from the documents: (a) is the only single edit that reconciles
every other statement. "11" appears twice ("(11 values)", "eleven shared
constants") and "`28` is new" appears three times. So a transcription error in
the shared row is the most probable reading, and an arithmetic error the less
probable one. The documents cannot settle it: §4a cites no evidence file, and
only §2 uses the word "multiset". Documentation insufficient.

Effect on the conclusion: the seven values lost from 3.1.12 are unaffected, so
"the constant sets differ" survives all three readings. "Not a superset or
subset" survives only (a) and (c). Under (b) the difference is pure removal,
which weakens the already unsupported "semantic difference" reading in C1
further. The corroboration count for the pairing moves between 11 and 12, which
is immaterial.

Correction: regenerate the table from the recorded extraction output, cite that
file, state set or multiset, print multiplicities if multiset.

**H2 [R][P] The "UVDM builder" is UNVERIFIED in §5 and established in §3 and
§4b. §4b then contradicts itself about it.**

Refs: DIFF.md §3 L62; §4b L175, L190, L205, L215-220; §5 L243-245.

Quotes:
- §5: "The subagent's description of a UVDM builder at `0x00C2B8` remains
  **UNVERIFIED** — I confirmed the constants and their counts, not that control
  flow."
- §4b heading: "Verified evidence: the UVDM path, traced into 3.2.0"
- §4b: "it locates the change: it is *not* in the builder itself."
- §4b, next bullet: "The builder cluster at 63.9 % is ambiguous. ... Labelled
  unresolved, not changed."

Why it matters: the label "UVDM builder" rests on an unverified subagent
description, yet names a coverage column, a section, and a region. And one
bullet says the change is not in the builder while the next says the builder is
unresolved. Both cannot stand.

Further reasoning defects in §4b:

1. "substantially rewritten" at 32.0 % has no baseline. The search picks the
   shift that maximises agreement and no null figure is given for unrelated
   code under the same search. The window is 128 bytes.
2. The document's own anchors show the shift is not uniform across that
   window's neighbourhood. `0x0C66C → 0x0C82C` is `+0x1C0`. `0x0C724 → 0x0C8FC`
   is `+0x1D8`. So `0x18` bytes were inserted somewhere in `0xC66C–0xC724`,
   which overlaps the compared window `0xC6B0–0xC730`. A single uniform shift
   over a region containing an insertion yields low agreement with unchanged
   code on both sides. The metric cannot separate "rewritten" from "`0x18`
   bytes inserted". The document's own caveat says so: "Uniform-shift search is
   therefore valid only within a cluster."
3. The explanation for 63.9 % ("sensitive to the chosen shift") does not hold.
   Six printed anchors in that window agree on `+0x1A0`. At a well-determined
   shift, 36 % of bytes differ. That is byte-level difference of unknown cause,
   not shift ambiguity.
4. "Code between clusters was reordered" is not shown. Three increasing shifts
   (`+0x1A0`, `+0x1C0`, `+0x1D8`) at increasing addresses are what insertions
   produce. Reordering needs a non-monotonic mapping, and none is shown here.
5. `RELOCATED` is defined in §2 on functions ("identical normalised pseudocode,
   mnemonics and constants"). §4b applies it to a 96-byte window with unknown
   function boundaries. What is demonstrated is byte identity over 96 bytes at
   `+0x1C0`. That is a sound byte-level result. It does not show the enclosing
   function is unchanged.

Correction: drop "UVDM" from headings and column labels or mark it INFERRED.
Replace "substantially rewritten" with "32.0 % byte agreement at the best
single shift; cause undetermined; an insertion in or near the window is not
excluded". Remove "it is *not* in the builder itself". Replace "reordered" with
"shifted by differing amounts". Report the 96-byte region as "byte-identical
window", not `RELOCATED`.

**H3 [R][P] REPORT.md closes the entry-point question on the wrong address and
on a negative the report elsewhere declares unusable.**

Refs: REPORT.md §2 L51-56, §4 L111-115; FIRMWARE.md §5 L147-175, §7 L200-201;
NEXT.md item 2 L16-20; DIFF.md §3.

Quotes:
- REPORT.md: "Closed since the last revision of this document: the entry-point
  question. ... the reset target at `0x111c` is a byte-copy leaf and Ghidra
  created no function containing any of the three pointer targets. Real entry
  is offset `0x10`."
- FIRMWARE.md table: 3.2.0 reset `0x0001111d`.
- FIRMWARE.md: "image offset `0x1111c` is constant data, not code."
- FIRMWARE.md: "All vector targets fall inside the image, so load base is
  `0x00000000`."
- FIRMWARE.md: "The genuine entry point is therefore not yet settled"

Why it matters:

1. Address error. `0x0001111d` with the Thumb bit cleared is `0x1111c`, not
   `0x111c`. FIRMWARE.md §5, FIRMWARE.md §7 ("the vector points there"),
   NEXT.md item 2 and REPORT.md §4 all call `0x111c` the reset target. At the
   real target the document reports constant data. `0x111c` is the vector
   target only if the load base were `0x10000`, which contradicts the base-0
   claim. The documents do not say which is intended. Documentation
   insufficient.
2. The closing evidence is a Ghidra negative. DIFF.md §3 says Ghidra covered
   38.5–43.3 % of these images and missed real code. "Ghidra created no
   function" at an address is therefore not evidence about that address.
3. The test FIRMWARE.md specified (who calls `0x10`; whether the target is
   referenced only from the pointer block) is not reported as run.
4. "SP plus three code pointers" does not follow. If the targets are data at
   base 0, they are not code pointers at base 0.
5. "fall inside the image, so load base is `0x00000000`" is a non sequitur. Any
   base that keeps the targets inside the image satisfies it. Base 0 has better
   support elsewhere (DIFF.md §4 absolute jump tables landing next to their
   sites), but FIRMWARE.md does not use it.
6. The 140 W control does not corroborate. Its payload length is `0xea00`
   (FIRMWARE.md §3). Its pointers are `0x0000ec89`, `0x0000ec71`, `0x0000ec71`.
   All three lie past the end of the payload at base 0. REPORT.md §2 says the
   control "shows the same shape from offset 0, which is what makes the MagSafe
   reading trustworthy rather than a coincidence." By the printed numbers it
   shows the opposite of "targets fall inside the image".
7. FIRMWARE.md: "Its first pointer is likewise reset+0x24 for the latter two."
   `0xec89 − 0xec71 = 0x18` and the reset value is the larger. The relation is
   reset − `0x18`, not reset + `0x24`.
8. Three documents disagree: REPORT.md closed, FIRMWARE.md §5 and §7 open,
   NEXT.md item 2 open. REPORT.md §2 still says "Cortex-M vector table" while
   §4 says "not a conventional Cortex-M vector table". FIRMWARE.md §5 is headed
   "(CONFIRMED)" and contains the open question.

Correction: reopen the question in REPORT.md. Fix `0x111c`/`0x1111c` everywhere
and state which address was actually disassembled. State that the pointer
block is unexplained in both the MagSafe and 140 W images. Remove "load layout
validated" from REPORT.md §5. Remove the 140 W image as corroboration.

**H4 [R][P] PROTOCOL.md §2 labels a host-to-controller write sequence as a
CONFIRMED on-wire frame.**

Refs: PROTOCOL.md intro L4-5; §2 L24-69; §10 L260-261; REPORT.md §2 L58-62;
SECURITY.md §3 L76-79.

Quotes:
- "## 2. Apple UVDM frame format (CONFIRMED)"
- "The `VDMs` 4CC is appended by a **separate** call (vtable +0x8f0) with
  argument 5, after the payload write (vtable +0x8c0) succeeds. Two calls, one
  logical frame."
- "`AppleHPMInterface::isCableKartCapable` emits, byte for byte: `21 | 01 A0 AC
  05 | 56 44 4D 73`"
- "only the on-wire value (2) is solid."
- "the caller passes `8` and the transport masks/normalises to 2."
- §10: "whether that argument is a channel, a length or a flag is unresolved."
- Intro: "Nothing here was probed by sending traffic to a device."

Why it matters:

1. Nothing was observed on a wire. "On-wire" and "emits, byte for byte" exceed
   the evidence. What is described is two separate writes from the host driver
   to the controller.
2. "one logical frame" is an interpretation. The same document set treats other
   4CCs as controller mailbox commands: SECURITY.md calls `CRYm` "a mailbox
   command executed by the controller hardware", and PROTOCOL.md §9 lists
   `iecsCommand(CFUp)`. The function here is named `hpmIECSSendVDM`. The
   alternative that `VDMs` is a command tag written to the controller, and not
   a frame trailer, is neither considered nor excluded.
3. The formula does not reproduce the frame. `hdr = (sop & 3) << 4 |
   ceil(len/4)` with the stated argument `8` gives `0x01`, not `0x21`. An
   8 → 2 mapping is asserted and not documented. So `0x21` is reconstructed,
   not "read out of the instruction stream" as REPORT.md says.
4. "Unstructured" has no stated basis. Spec-based note: in the USB-PD VDM
   header, bit 15 distinguishes Structured (1) from Unstructured (0). The
   recorded payload word `0x05ACA001` has bit 15 set and command field 1. The
   document calls the message both "Discover-Identity", which is a Structured
   VDM command, and "UVDM". That bears directly on what §9 calls "the single
   most important open protocol question".
5. DIFF.md §11 treats the absence of `VDMs` in the cable firmware as a finding.
   If the 4CC is a host-to-controller tag, that absence carries no information.

Correction: retitle §2 "Host-to-controller VDM send sequence (read from
decompiled code)". Remove "on-wire". Document the 8 → 2 mapping or mark the
header byte derived. Mark "unstructured" INFERRED and record the bit-15
observation as an open item. Correct REPORT.md §2 to match.

**H5 [P][R] The REPORT.md headline "CONFIRMED" rests on non-independent
sources.**

Refs: REPORT.md §1 L23-27; §2 L64-66; HARDWARE.md §5.2 L117-118; FIRMWARE.md
§1 L28-29.

Quotes:
- "Each was independently confirmed."
- "The MagSafe cable's 3.2.0 was recovered twice from different data: once from
  the register-derived `bcdDevice 0x3200` in HPM register `0x49`, and once from
  the in-file version quadruple of the downloaded 3.2.0 SuperBinary. Those
  agree, so the previously "reported" 3.2.0 is now CONFIRMED rather than
  assumed."
- FIRMWARE.md: "`1030030` therefore remains a host-reported value with no
  binary to compare against."

Why it matters:

1. The downloaded SuperBinary's header says that a 3.2.0 release exists. It
   says nothing about what the attached cable runs. Only the register reading
   bears on the cable. One source, not two.
2. "matching IOKit and the firmware version independently": IOKit's SOP′
   metadata and register `0x49` both come from the same controller's record of
   the same identity response. Not independent.
3. The `0x3200` → "3.2.0" mapping is asserted from one data point. No encoding
   rule is stated, and no second version is shown under it.
4. No document links this cable (PID `0x7800`) to model A2363 or to asset
   `UARP.A2363`. HARDWARE.md never mentions A2363. That the downloaded images
   are this cable's firmware is an unstated assumption.
5. Adapter `1030030` has one source (`system_profiler`). "Each was
   independently confirmed" contradicts FIRMWARE.md.

The version is probably right. The label is not earned.

Correction: "bcdDevice `0x3200` read from register `0x49`; consistent with
Apple's published 3.2.0 release; single host-side source". State the
PID-to-model link and its source, or mark it assumed. Change the adapter row to
"host-reported, single source".

**H6 [R] The coverage table compares fixed address windows across builds whose
layouts differ, with an undefined metric.**

Refs: DIFF.md §3 L62-66, L80-82; §9 L299-300; §10 L308-309; REPORT.md §4
L120-122.

Quotes:
- Table columns "0x9000–0xB500 (PD region)" and "0xC000–0xC400 (UVDM region)".
- "Aggregate match rates over 39 % coverage are not evidence of semantic
  equivalence"
- "That should lift coverage in the PD and UVDM regions from ~50 %/~0 % toward
  complete"
- REPORT.md: "left the PD and UVDM regions at roughly 50 % and 0 % function
  coverage"

Why it matters:

1. The same window is applied to all three builds. The document shows 3.2.0
   code displaced by `+0x1A0` or more near `0xC2C0`, so the 3.2.0 counterpart
   of the 3.1.12 cluster sits at `0xC460–0xC4F0`, outside `0xC000–0xC400`. The
   two candidate 3.2.0 dispatch sites (`0x4EE2`, `0x5166`) are outside
   `0x9000–0xB500` altogether. The 3.2.0 row measures different code from the
   3.1.x rows. The columns are not comparable across builds.
2. "Coverage" is not defined (bytes in function bodies over window bytes is the
   likely meaning). The denominator includes literal pools, jump tables and
   data. It cannot reach "complete", and the share of uncovered bytes that is
   code is unknown. §1 correctly retracts "the uncovered 61 % is data", but the
   complement is not quantified either.
3. 0.0 % (3.1.8) against 14.1 % (3.1.12) on builds the report treats as
   near-identical shows the analysis itself is unstable between builds. That
   confounds any cross-build comparison of Ghidra-derived function sets,
   including §4a.
4. Rounding. "roughly 50 % and 0 %" flattens 41.3 % and 14.1 %. "39 % coverage"
   and "~61 %" describe 3.1.x. 3.2.0 is 43.3 % and 56.7 %.
5. The cause is asserted, not tested. "generic `ARM:LE:32:v7`, not Cortex-M" is
   offered as the reason. No re-analysis was run (§10: "should lift").

The limitation the document draws is valid and conservative: aggregate match
rates are not evidence, and the semantic verdict is undeterminable. The direct
facts carry it (dispatcher sites not inside any function; no decompiled
function references the `0x05AC…` constants), not the percentages. The
limitation is then not applied consistently: §4a relies on pseudocode from the
same run, and REPORT.md's entry-point closure relies on a Ghidra negative.

Correction: define the metric. Report per-build windows that track the same
code, or drop the regional columns and keep the two direct facts. Mark the
language-spec cause as a hypothesis. Quote exact figures in REPORT.md.

**H7 [R][P] DIFF.md §8 attaches dispatcher evidence to a sub-claim the same
section says the dispatcher cannot carry.**

Ref: DIFF.md §8 L274-287; §3 L73-76.

Quotes:
- "hard-reset handling changed | **structure changed, behaviour not
  established** | 14-case dispatcher fingerprint present in 3.1.x, absent in
  3.2.0"
- "The 9–22 range does include 0x0D (Soft_Reset) and does not include a
  hard-reset message"
- "soft-reset escalation changed | **open, not negative** | the dispatcher that
  would host an escalation ladder is in the unanalysed region"
- §3: "Correction to the previous revision: the switch *target* is analysable."

Why it matters: by the section's own premise correction, the 14-case switch
does not handle hard reset. Its change is therefore not evidence about
hard-reset handling in either direction. The verdict should be "no evidence",
not "structure changed". The soft-reset row is stale against §3 and §4a, which
say the 3.1.x handler was decompiled. The "2026 changes" claim being judged is
never quoted or sourced in any document, and REPORT.md does not mention it.

Correction: quote the claim and its source. Hard-reset row: "no evidence
located; the examined switch does not cover it". Soft-reset row: state what was
and was not decompiled per build.

### Medium

**M1 [P][R] Void matcher runs: clearly withdrawn, with loose ends.**

Ref: DIFF.md §12 L327-344; §2 L43-49; §4a L161-163; NEXT.md item 1 L10-14.

Quote: "**void run, twice**, 0 matches on both build pairs. ... Both runs are
tooling failures, not evidence of dissimilarity. Neither is used in any
conclusion here."

Confirmed: both runs are unambiguously marked invalid, with cause. No
conclusion cites `match_final.json`. The 244/303 figure is withdrawn in §1 and
again in §12. This is good failure accounting.

Loose ends:

1. Provenance of the §4a pairing. "The link was proposed by structural matching
   with pseudocode ratio 0.713 and mnemonic ratio 0.896". No run or file is
   named. The only matcher outputs the document describes are one superseded
   run and one void run. Whether these ratios come from either cannot be
   determined. Documentation insufficient. This is the one surviving claim that
   may depend on an invalidated run.
2. `evidence/functionmatch/match2.json` exists and no document mentions it.
   `scripts/fw_func_match.py` and `scripts/diff_verify.py` likewise. Which
   script produced which file is undocumented.
3. "Two different causes" is imprecise. Run 1: threshold 0.78, calibration p99
   0.75, and `0.75 + 0.03 = 0.78`. So run 1 also had its null p99 at the
   maximum attainable score. The null-sampling defect was present in both runs.
   The rizin failure was an additional defect in run 1.
4. The run-2 root cause is asserted, not shown. If the null draws one random
   function from the other build, the true counterpart turns up about once in
   300 draws (303 functions per §1), which cannot move a p99 to 1.0. Either the
   null was a best-of-many search, or unrelated pairs score 1.0. The sampling
   procedure is not described. Documentation insufficient. The second case
   would be a scoring defect, not a threshold defect.
5. §2 "Method in force" describes a pipeline with no valid output. "Five
   independent signals" are not independent: four derive from the same Ghidra
   function bodies and the constants come from the pseudocode.
6. NEXT.md item 1 still reads "Owner: in flight ... Blocks `DIFF.md`" with a
   success criterion of "a stated behavioural inference for the largest
   changes". That conflicts with DIFF.md §10 (re-analysis and calibration
   first, no behaviour claims). REPORT.md does not mention the void runs.
7. A void run stored as `match_final.json` invites misuse.

Correction: name the source of the 0.713 / 0.896 figures or withdraw them.
Document or remove `match2.json`. Restate the failure causes. Update NEXT.md.

**M2 [R] The verdict vocabulary hard-wires causes that its criteria cannot
separate.**

Ref: DIFF.md §2 L51-54; §6 L259; §9 L295.

Quote: "`RELOCATED` (identical normalised pseudocode, mnemonics and constants;
addresses differ), `RECOMPILED` (identical constants and CFG topology,
different code generation), `CODE_CHANGED` (constants or topology differ)"

Why it matters: the names are causal and the criteria are observational. A
source edit that keeps constants and CFG lands in `RECOMPILED`. A compiler
change that inlines or alters switch lowering lands in `CODE_CHANGED`. No
document establishes whether the toolchain changed between 3.1.12 and 3.2.0, so
no allocation between compiler and source has an anchor. The hard-negative
calibration is "specified but **not yet completed**". The vocabulary is then
used outside its definition: on a data table (§9, PDO table `RELOCATED`), on a
byte window (§4b), and without a matched pair (§9, `CODE_CHANGED`). §6 says
"Placement moves with the rebuild", reusing the term §1 retracted.

Correction: rename to observational labels (byte-identical at shift;
same-constants-same-CFG; differs; unmatched). Add a separate, explicitly
inferred cause column. Remove "rebuild" from §6.

**M3 [P] DIFF.md §5 calls a byte count "semantic" and "exactly one" without
stating the search scope.**

Ref: DIFF.md §5 L237-239.

Quote: "Exactly one vendor-code constant changes: `0x05AC0002` → `0x05AC0000`.
This survives every methodological objection above because it is a direct byte
count at a semantic level."

Why it matters: a pattern count is byte-level evidence, the lowest of the four
levels, though robust. Four patterns are tabulated. Whether a wildcard search
over all `0x05ACxxxx` words was done is not stated, so "exactly one" holds only
among the four listed. Alignment of matches is not stated. The arrow
(substitution) is an inference from −1/+1 counts. It does have support the
document never cites: `0x0C724 + 0x1D8 = 0x0C8FC`, a `0x05AC0000` site at the
shifted position of the old `0x05AC0002` literal. The literal-site table lists
one or two addresses per constant against counts of 2, 6 and 7.

Correction: "counts of four enumerated patterns; one count falls 1 → 0 and one
rises 6 → 7; positional correspondence at `0xC724`/`0xC8FC` supports a
substitution". State search scope and alignment. List every site.

**M4 [P] DIFF.md count and status inconsistencies.**

- §4 L105-107: "Soft_Reset (0x0D) maps to the dominant shared handler, along
  with eight other cases." The table shows 8 of 14 in total, so seven others.
- Status L4-5: "the counterexamples that killed two earlier claims". §1 has
  three "Retracted:" entries. REPORT.md L118: "retracts two earlier claims".
- §4 L128-129 gives 3.2.0 "15 `mov pc` sites" against 10 "dispatch sites with
  tables". No `mov pc` site count is given for 3.1.x.
- §9 neither issues nor withholds the §4a and §4b results.
- §4b L212-214: "the first region in this investigation where relocation is
  demonstrable". §6 and §9 claim the same for the PDO table.

**M5 [P] DIFF.md §11 is a stale section in conflict with §4–§6.**

Ref: DIFF.md §11 L317-323.

Quote: "## 11. USB-PD / VDM presence (unchanged negative)" ... "does not appear
in the cable A 33-entry pointer table found by a subagent is unreferenced"

Why it matters: a negative on PD/VDM presence sits beside a "PD dispatcher"
(§4), a "UVDM builder" (§4b) and a PDO table (§6), with no reconciliation. The
sentence is truncated mid-clause. The search range "0x01–0x26" matches the
uarpd opcode index range in PROTOCOL.md §8, not any PD message-type range, and
is not justified. A "33-entry" table also appears in NEXT.md item 3 as a uarpd
table. Two different binaries, same count, no disambiguation.

**M6 [R] "Not publicly obtainable, confirmed three independent ways" rests on
an unsourced model number.**

Refs: REPORT.md §3 L89-91; FIRMWARE.md §1 L23-29; NEXT.md item 8.

Quote: "The 70 W adapter firmware **is not publicly obtainable**, confirmed
three independent ways."

Why it matters: all three probes query Apple asset infrastructure for `A2743`
or nearby numbers. No document establishes that this adapter (ID `0x701c`) is
A2743. The probes share that assumption and one infrastructure, so they are not
independent. NEXT.md already concedes the payload may be "bundled inside a
macOS update". The "281-type sweep" is undefined.

Correction: "not found in Apple's public MobileAsset UARP catalogues under the
asset names tried". Source the model number.

**M7 [P][R] SECURITY.md labels exceed evidence in six places.**

- §1 L16, L21-24: "the manifest is fetched over TLS from Apple". FIRMWARE.md
  says 3.1.8 and 3.1.12 "came from archived copies", and the evidence filenames
  are `UARP_A2363_wayback_*.xml`. For those two the binding is to a third-party
  archive copy. No document says a manifest signature was verified. CONFIRMED
  is too strong for two of the four.
- §8 item 1 L170-172: "CONFIRMED — the accessory firmware container is an
  unsigned-by-structure SuperBinary". The recovered layout has "four further
  fields, names not recovered", two TLVs of unknown meaning, and an opaque
  384-byte inner header with "20 bytes of high-entropy material" and several
  32-byte fields. A negative over a partly recovered layout is not CONFIRMED.
  §9 retreats ("Nothing here should be read as "the update path is
  unsigned""). The ranked list and the non-claims disagree in tone.
- §3 L76-83: two protocol generations and "The crypto itself runs on the HPM"
  are read from log strings. Strings are CONFIRMED present. The architecture is
  INFERRED. "Multiple call sites exist (17 log anchors), so it is not a
  single-purpose routine" is a non sequitur: log lines in one function are not
  callers.
- §4 L96-102: "Running as root without the entitlement would not be enough". No
  privileged run was made and no kernel-side check is cited. Untested.
- §9 L189-192: "have not yet analysed for the cable". Stale. DIFF.md is that
  analysis.
- §2 L56-57: "no authentication occurred during the session" is drawn from one
  point-in-time property (`AuthenticationStatus = 0`).

**M8 [P] PROTOCOL.md mixes verified and unverified within single statements.**

- §8 L181-185: "What I did verify independently is that uarpd builds paired
  request/response messages ... — also reported by the subagent, also not
  re-derived here." Verified independently and not re-derived cannot both hold.
- §9 L227-231: "So the shipping design is: ..." is built from string and
  selector names. Strings are CONFIRMED present. The design is INFERRED. The
  section has no label. REPORT.md §2 hardens it to "implements".
- REPORT.md L151-152: "One claim (UARP-over-USB-PD in
  `UARPUpdaterServiceUSBPD`) was checked and confirmed." PROTOCOL.md §10: "No
  UARP-over-USB-PD frame was observed ... INFERRED ... not proven." What was
  confirmed is that the service binary and its strings exist.
- §7 L137-162, headed CONFIRMED: the name "protocolVersion" is given to a field
  only ever seen written as 0, and "sequence and window/ID fields" are named
  from offsets. The stores are confirmed. The names are inferred. The
  correction paragraph (L164-167) does not state clearly what was wrong.
- REPORT.md §3 and §6 against SECURITY.md §6: the `usbcupdater` role is
  "checked and corrected" in one and "Reported by subagent, spot-checked
  against strings" in the other. A flat "does **not** update adapters or
  cables" is stronger than a string spot-check supports.

**M9 [P] "CONFIRMED" carries at least four meanings across the set.**

Live observation (HARDWARE.md), static reading of decompiled code (PROTOCOL.md
intro), string presence (PROTOCOL.md §9, SECURITY.md §3), agreement of two
readings (REPORT.md §1). DIFF.md adds "Verified evidence", "established",
"Verified negative". HARDWARE.md applies a blanket "CONFIRMED unless labelled
otherwise" and then lists the RID 5 identification under "Not verified" as
"inferred". The reader cannot map a label to an evidence level.

Correction: one scale, defined once in REPORT.md: OBSERVED (live), READ (static
code), PRESENT (bytes or strings), INFERRED, UNVERIFIED.

### Low

- **L1 [P]** PROTOCOL.md section numbering skips §6 (… 5, 7, 8 …).
- **L2 [P]** FIRMWARE.md §6 L181: "Three 32-byte fields sit at header offsets
  `0x24`, `0x98`(+4), `0xb8`, `0x110`." Four offsets for three fields.
- **L3 [P]** FIRMWARE.md §4 L130-132: "byte[1] = minor, byte[2] = major" and
  "3.2.0 -> major 2". By §2's own field names those bytes are release and
  minor. L64-65: "four version words ... so this triple". REPORT.md and
  SECURITY.md say "quadruple".
- **L4 [P]** HARDWARE.md §5.1 L97-99 lists RID 2 on two lines with different
  suffixes (`P01`, `P2`). §2 says "P05 on RID 5" and §5.1 says `P5`. "The
  trailing digit is the instance suffix" does not fit `P01` shared by RIDs 0–2.
- **L5 [P]** DIFF.md §8 L283-284: Hard_Reset "is a vSafe0V protocol action".
  Spec-based note: Hard Reset is ordered-set signalling with no header.
  vSafe0V is the resulting VBUS level. The conclusion (no MessageType) holds.
- **L6 [P]** SECURITY.md §2 prints `AuthorizationStatus`. HARDWARE.md §6 prints
  `UserAuthorizationStatus` for the same line.
- **L7 [P]** FIRMWARE.md §3 L109: "Independent arithmetic confirmation". The
  equality uses the same parsed header fields as check 4, so it is a stronger
  consistency check, not an independent one. The six script checks omit the
  parser's "multiple of `0x28`" rule listed in §2.
- **L8 [P]** FIRMWARE.md gives `payloadDataOffset` `0x60`, `0x60`, `0x6c`,
  `0x84` with no per-file metadata listing to explain the differences. No hash
  is recorded for the extracted `.uarp` files or the `_base0.bin` images. The
  SuperBinary's location inside the zip is stated only in SECURITY.md.
- **L9 [P]** FIRMWARE.md L177 names images `A2363_<version>_base0.bin`. DIFF.md
  L7-9 names them `A2363_3.1.8_10M569_base0.bin`. Not checked against disk.
- **L10 [P]** Inferences under CONFIRMED headings: HARDWARE.md §4 and
  PROTOCOL.md §5 on the Brick ID node ("used before the main contract");
  HARDWARE.md §6 ("not required to authenticate for power delivery" as "a
  concrete, verified statement"); FIRMWARE.md §5 ("implies 8 KB of SRAM");
  PROTOCOL.md §1 ("must therefore ride on USB-PD itself").
- **L11 [P]** REPORT.md §5 "Maximum reachable state" and SECURITY.md §4 "the
  *maximum* unprivileged visibility" are universal claims. Other user clients
  and tools are not enumerated.
- **L12 [P]** PROTOCOL.md §8 names 31 message types for a 39-entry table. The
  section is already marked UNVERIFIED.
- **L13 [P]** `ghidra/` is empty. `evidence/magsafe-ghidra/notes.md` and
  `evidence/magsafe-behavior/notes.md` exist and no document references them.
- **L14 [P]** EXTRACTION-NOTES.md limitation 2 reports that `rz-bin -sj`
  undercounts symbols and then recommends "rizin" in the next sentence.
- **L15 [P]** DIFF.md §6 L249: "duplicated twice per image". Two copies are
  listed. "Power-negotiation table" and "the cable's own capability set" name a
  role the documents do not demonstrate. The content identity is demonstrated.
- **L16 [P]** DIFF.md §7 L269: "No ASCII build, version or hardware-revision
  string exists in any image." The search method is not described.

---

## 3. The four evidentiary levels, as used

| level | what would establish it | where the documents have it | where a lower level is passed off as it |
|---|---|---|---|
| 1. byte-level similarity | byte counts, identical windows | DIFF §5 counts; §6 PDO content; §4b 96-byte window; §1 overlap figures | — |
| 2. structural correspondence | a validated mapping between code units | 3.1.8 ↔ 3.1.12 dispatcher (same fingerprint, both shifted `+0x54`) | §4a pairing (inferred, uncalibrated); §4b "builder" (unverified label); 3.2.0 "dispatchers" (chosen by size) |
| 3. code change (source) | level 2 plus exclusion of code-generation causes | none | §4 "not attributable to the compiler"; §4a "come from source"; §4b "rewritten"; §9 `CODE_CHANGED` |
| 4. observable behaviour | execution, capture, or traced host-visible effect | none, and correctly disclaimed in §4, §4a, §8, §9 | §4a "semantic difference", "logic differs" |

DIFF.md keeps level 4 separate from the rest with care. It does not keep level
3 separate from levels 1 and 2. §5's "at a semantic level" gives a level-1
result a higher name.

Relocation, compiler generation, code change and behaviour: behaviour is
handled consistently. The other three are not. §1 states they cannot be
separated by layout metrics. §4, §4a and §4b then separate them without new
grounds. No document contains any direct evidence about the toolchain.

---

## 4. Claims table

| # | claim | where | class | note |
|---|---|---|---|---|
| 1 | Charger is on the MagSafe port, 20 V / 3.390 A / 67.80 W | REPORT §1, HARDWARE §3–4 | SUPPORTED | live, consistent across documents |
| 2 | HPM firmware `FW003.115.00`, distinct from adapter firmware | REPORT §1, HARDWARE §2 | SUPPORTED | three renderings from one controller |
| 3 | Cable runs 3.2.0, "CONFIRMED", "recovered twice" | REPORT §1 | OVERSTATED | one host-side source (H5) |
| 4 | "Each was independently confirmed" (incl. adapter `1030030`) | REPORT §1 | CONTRADICTORY | FIRMWARE §1 (H5) |
| 5 | Register `0x49` field map and `0x78003200` | REPORT §2, HARDWARE §5.2 | SUPPORTED | as a reading; the 3.2.0 mapping is inferred |
| 6 | Three MagSafe releases acquired, SHA-1 matches manifest | REPORT §2, FIRMWARE §1 | SUPPORTED | two manifests are archive copies (M7) |
| 7 | SuperBinary layout and parser checks recovered | FIRMWARE §2 | SUPPORTED | static reading; four header fields unnamed |
| 8 | Extraction validated, offset + length reconciles 4/4 | FIRMWARE §3 | SUPPORTED | printed arithmetic checks out |
| 9 | Payload is Thumb code at base 0 behind a 384-byte header | REPORT §2, FIRMWARE §5 | OVERSTATED | base 0 by non sequitur; pointer block unexplained (H3) |
| 10 | Entry-point question closed; real entry `0x10` | REPORT §4 | CONTRADICTORY | wrong address; FIRMWARE and NEXT say open (H3) |
| 11 | 140 W image corroborates the MagSafe reading | REPORT §2, FIRMWARE §5 | CONTRADICTORY | its pointers lie past its payload end (H3) |
| 12 | UVDM "frame format (CONFIRMED)", "on-wire" | PROTOCOL §2, REPORT §2 | OVERSTATED | write sequence, nothing on a wire (H4) |
| 13 | Header formula `(sop & 3) << 4 \| ceil(len/4)` gives `0x21` | PROTOCOL §2 | CONTRADICTORY | with stated argument 8 gives `0x01` (H4) |
| 14 | Kernel VDM is unstructured | PROTOCOL §2, §9 | UNRESOLVED | no stated basis; recorded word has bit 15 set (H4) |
| 15 | `isCableKartCapable` discovery sequence | PROTOCOL §3 | SUPPORTED | as a static reading of one function |
| 16 | UARP header is 6 bytes, three BE u16 | PROTOCOL §7 | SUPPORTED | field names inferred (M8) |
| 17 | uarpd opcode table | PROTOCOL §8 | UNRESOLVED | labelled UNVERIFIED by the author; correct |
| 18 | Updater service "implements" Mode 7 and CFU; UARP-over-PD "confirmed" | REPORT §2, §6 | OVERSTATED | strings and class names only (M8) |
| 19 | 70 W firmware "not publicly obtainable", three independent ways | REPORT §3 | OVERSTATED | shared unsourced model assumption (M6) |
| 20 | Function coverage 38.5 / 39.2 / 43.3 %; equivalence undeterminable | DIFF §3, §9 | SUPPORTED | limitation valid; regional columns not comparable (H6) |
| 21 | 14-case table fingerprint in 3.1.x, not detected in 3.2.0 | DIFF §4 | SUPPORTED | as a detector result |
| 22 | "not attributable to the compiler"; `CODE_CHANGED`; "two new control-message dispatchers" | DIFF §4, §9, REPORT §4 | OVERSTATED | (C2) |
| 23 | "The shared handler changed"; "semantic difference" | DIFF §4a | CONTRADICTORY | against status, §9, §10, REPORT §4 (C1) |
| 24 | Constant-set comparison: 11 shared, 7 lost, 1 gained | DIFF §4a | CONTRADICTORY | table impossible as printed (H1) |
| 25 | 96-byte region byte-identical at `+0x1C0` | DIFF §4b | SUPPORTED | at byte level; `RELOCATED` label misapplied |
| 26 | `0x05AC0002` site "substantially rewritten" | DIFF §4b | OVERSTATED | single shift across a non-uniform region (H2) |
| 27 | Change is "not in the builder itself" | DIFF §4b | CONTRADICTORY | next bullet: builder unresolved (H2) |
| 28 | Region is a "UVDM builder" | DIFF §3, §4b | CONTRADICTORY | §5 marks it UNVERIFIED (H2) |
| 29 | Pattern counts: `0x05AC0002` 1→0, `0x05AC0000` 6→7 | DIFF §5 | SUPPORTED | "exactly one" and "semantic level" overstated (M3) |
| 30 | PDO table content identical in all six copies | DIFF §6 | SUPPORTED | offsets given; role of the table inferred |
| 31 | Hard-reset handling: "structure changed" | DIFF §8 | CONTRADICTORY | examined switch excludes hard reset (H7) |
| 32 | Soft-reset escalation: open | DIFF §8 | UNRESOLVED | correct status; stated basis is stale |
| 33 | 3.2.0 semantically equivalent to 3.1.12? | DIFF §9, REPORT §4 | UNRESOLVED | correctly withheld there; violated in §4a |
| 34 | Void matcher runs are not evidence | DIFF §12 | SUPPORTED | clearly withdrawn (M1) |
| 35 | §4a pairing scores 0.713 / 0.896 | DIFF §4a | UNRESOLVED | no source run documented (M1) |
| 36 | Container is "unsigned-by-structure", CONFIRMED | SECURITY §8 | OVERSTATED | layout only partly recovered (M7) |
| 37 | MagSafe power needs no authentication on this host | SECURITY §2 | SUPPORTED | property value observed; "none occurred" inferred |
| 38 | `hpmdiagnose` reads all registers without root | HARDWARE §7, SECURITY §4 | SUPPORTED | "root alone would not suffice" untested |
| 39 | Accessory signature check, anti-rollback, Mode 7 flash read | SECURITY §8, NEXT | UNRESOLVED | correctly labelled |
| 40 | BootKC extraction byte-identical for four sections | EXTRACTION-NOTES | SUPPORTED | best-documented procedure in the set |

---

## 5. Reproducibility as documented

Reproducible from the text: HARDWARE.md (commands and evidence files named and
present); FIRMWARE.md §2–3 (layout, offsets, parser addresses, uarpd hash);
EXTRACTION-NOTES.md (hashes, offsets, validation steps); DIFF.md §6 (offsets
and decode rule); PROTOCOL.md §2–3 as static readings (symbols and one address
given).

Not reproducible from the text (documentation gaps, not filled here):

- Ghidra version, analysis options, loader settings. `ghidra/` is empty.
- Rizin version ("this rizin build").
- Coverage metric definition and how the regional windows were chosen.
- Switch census: `mov pc` match rule, window size, minimum run length,
  definition of "in-image code pointer", script name, per-build table list.
- §4a: source run, normalisation rules, ratio definitions, raw constant output.
- §4b: byte-agreement definition, shift search range, how region bounds were
  chosen, any null baseline. 3.1.8 is absent from the comparison.
- §5: search scope, alignment, full site list, script name.
- §1: definition of "aligned 16-byte window overlap" (retracted, low priority).
- §12: null sampling procedure, composite weights, calibration sample.
- Hashes of the `_base0.bin` inputs to DIFF.md.
- Which script produced which file in `evidence/functionmatch/`.
- Source of model numbers A2363 (for PID `0x7800`) and A2743 (for the adapter).
- Hash of the `UARPUpdaterServiceUSBPD` executable (size only is given).

---

## 6. Research problems versus presentation problems

Problems with the underlying research (the reasoning or method is unsound even
if every number is right):

1. Source-level cause inferred from binary structure without excluding code
   generation (C1, C2, H2). Same error class as the retracted §1 claim.
2. Function pairing used as fact without calibration, exhaustive search, or a
   3.1.8 control (C1).
3. Single uniform-shift comparison applied where the document's own anchors
   show a non-uniform shift (H2).
4. Fixed address windows compared across builds with different layouts (H6).
5. Ghidra negatives used as evidence when the same report measures 39–43 %
   coverage (H3, and the selective use of §3 generally).
6. Load base and vector-table reading inferred by non sequitur. The control
   image contradicts the stated criterion (H3).
7. Two-call write sequence read as one on-wire frame without excluding the
   command-tag alternative (H4).
8. Independence claimed for sources that share an origin or an assumption (H5,
   M6).
9. Matcher null model and score not shown to discriminate (M1).
10. Verdict vocabulary encodes causes its criteria cannot distinguish (M2).

Problems with presentation (the work may be fine, the write-up misstates it):

1. Constant table transcription or count error (H1).
2. `0x111c` against `0x1111c` across three documents (H3).
3. REPORT.md stale against DIFF.md and FIRMWARE.md: retraction count,
   entry-point status, "roughly 50 % and 0 %", "two new control-message
   dispatchers".
4. NEXT.md stale against DIFF.md and REPORT.md (items 1 and 2).
5. SECURITY.md stale ("have not yet analysed for the cable").
6. Headings stronger than content: "Verified evidence" on §4a and §4b,
   "(CONFIRMED)" on FIRMWARE.md §5 and PROTOCOL.md §2.
7. "CONFIRMED" overloaded (M9).
8. Count slips: "eight other cases", "two earlier claims", "three" fields with
   four offsets, RID suffixes.
9. Stale or truncated section (DIFF.md §11), missing section number
   (PROTOCOL.md §6).
10. Undocumented files and unnamed scripts (M1, L13).

---

## 7. Recommended corrections, in order

1. DIFF.md §4a: demote to inferred. Remove "semantic difference" and "logic
   differs". Regenerate the constant table from recorded output and cite it.
   Name the run that produced 0.713 / 0.896 or withdraw the figures.
2. DIFF.md §4, §8, §9 and REPORT.md §4: reduce the dispatcher claim to the
   fingerprint result. Remove "not attributable to the compiler", "replaced
   by", `CODE_CHANGED` and "new control-message dispatchers". Publish the full
   table inventory for all three builds.
3. DIFF.md status, §9, §10: give §4a and §4b one status and make all three
   places agree. Fix the retraction count.
4. REPORT.md §4, FIRMWARE.md §5 and §7, NEXT.md item 2: reopen the entry-point
   question. Correct the reset-target address. Record that the 140 W pointers
   lie outside its payload. Drop "load layout validated".
5. DIFF.md §4b and §5: resolve the "UVDM builder" status in one direction.
   Replace "rewritten" and "reordered" with the measured statement. Remove "not
   in the builder itself".
6. PROTOCOL.md §2 and REPORT.md §2: retitle as a host-to-controller write
   sequence. Remove "on-wire". Fix or document the SOP argument mapping. Mark
   "unstructured" INFERRED.
7. REPORT.md §1: replace "CONFIRMED / recovered twice / each independently
   confirmed" with the single-source statement. Source the A2363 and A2743
   model links.
8. DIFF.md §3: define coverage. Fix or drop the regional columns. Quote exact
   figures in REPORT.md.
9. Adopt one evidence-label scale across all eight documents (M9). Rename the
   DIFF.md verdict vocabulary to observational terms (M2).
10. DIFF.md §12 and NEXT.md item 1: restate the void-run causes, document
    `match2.json` and the script-to-output mapping, and bring NEXT.md in line
    with DIFF.md §10.
11. SECURITY.md: correct the manifest provenance statement, soften §8 item 1,
    relabel §3 and §4 inferences, remove the stale sentence in §9.
12. Clean-up: DIFF.md §11, "eight other cases", PROTOCOL.md §6 numbering and §8
    wording, FIRMWARE.md field counts and version-byte labels, HARDWARE.md
    §5.1 suffixes.
