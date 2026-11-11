# DIFF — MagSafe 3 firmware 3.1.8 → 3.1.12 → 3.2.0

Inputs (flat ARM Thumb images extracted from the Apple UARP assets):
`firmware/images/A2363_3.1.8_10M569_base0.bin` (83,464 B),
`A2363_3.1.12_10M1543_base0.bin` (83,592 B),
`A2363_3.2.0_10M13722_base0.bin` (84,048 B).

Evidence labels used throughout, defined once in `README.md`:
**OBSERVED** (read directly at a cited offset), **REPRODUCED** (a checked-in
script deterministically re-derives it), **INFERRED** (reasoned from evidence,
not proven), **UNVERIFIED** (asserted without checking), **REFUTED** (checked and
false), **OPEN** (unsettled on available evidence).

No semantic or behavioural conclusion is drawn anywhere in this document.

---

## 1. Retracted claims

1. **"3.2.0 is a rebuild, not a patch."** **REFUTED.** Inferred from 5.9 %
   aligned 16-byte window overlap against 73.1 % for 3.1.8→3.1.12. Window
   overlap measures byte layout. Reordered functions, relocated literal pools and
   different register allocation all produce low overlap with unchanged logic.
   The numbers are real; the inference from them is withdrawn.
2. **The 244/303 function pairing as evidence of equivalence.** Withdrawn. Its
   address heuristic classified any literal below the image span as an address,
   erasing `0x09`, `0x0D`, `0x05AC…`, `0xA001…`; its mnemonic signal came from
   whole-image linear decode, which treats literal pools and jump tables as
   instructions. See §10.
3. **"The ~61 % of each image not covered by functions is data, not missed
   code."** **REFUTED** for the regions that matter. §3 measures the opposite.
4. **A constant table listing `28` as both shared and 3.2.0-only.** Withdrawn and
   re-derived in §4a. The shared row had been generated as a magnitude-filtered
   union and mislabelled.

## 2. Method, and why no matching result appears here

Signals, kept independent: normalised pseudocode, mnemonic sequence from bodies
bounded by Ghidra function extents, CFG topology, literal multiset, callee-size
multiset. Normalisation removes relocations, addresses and variable names only;
integer literals are preserved except where the code dereferences or calls
through the value. Matching is one-to-one; unmatched, split, merged and inlined
functions are permitted outcomes; stubs under 8 instructions are excluded from
aggregates.

**No per-function matching result is reported in this document.** Both calibrated
runs were void (§10), and the calibration rule as specified was defective: it
drew null pairs from the other build, which for a near-identical pair contains the
true counterpart, so the null tail reached 1.0 and the threshold became
unsatisfiable. A valid calibration must draw hard negatives from within-build
pairs and cap the threshold below 1.0. Until a run survives that, matching
contributes nothing here.

## 3. Coverage (OBSERVED, REPRODUCED)

Coverage is the fraction of image bytes falling inside Ghidra function bodies,
measured by `scripts/coverage.py`.

| build | functions | instructions reported | coverage |
|---|---|---|---|
| 3.1.8 | 300 | 15,279 | 38.8 % |
| 3.1.12 | 303 | 15,568 | 39.4 % |
| 3.2.0 | 296 | 17,249 | 43.3 % |

Two consequences, both **OBSERVED**:

- The 3.1.x control-message switch site (`0xAA2A`) is not inside any Ghidra
  function. Neither are the two 3.2.0 candidate sites (`0x4EE2`, `0x5166`). The
  switch itself was never decompiled in any build.
- No decompiled function in any build references a `0x05AC…` literal, although
  the bytes are present in all three images.

An earlier revision quoted regional coverage for fixed address windows and drew
conclusions from it. **Withdrawn**: those windows are applied to shifted layouts,
so the columns are not comparable between builds. Only the whole-image figures
above are meaningful.

Ghidra analysed these images as generic `ARM:LE:32:v7`, not Cortex-M. It fails to
decode `cpsid i` and mis-delimits code, which is why the regions of interest sit
outside its function set.

## 4. Dispatcher inventory (OBSERVED, REPRODUCED)

`scripts/dispatcher_census.py` scans for `mov pc, Rn` sites, locates each case
table empirically as the longest run of in-image code pointers in the surrounding
window, and records the fingerprint. Data:
`evidence/dispatcher-census.json`.

| build | dispatchers | case-count profile | the 14-case table |
|---|---|---|---|
| 3.1.8 | 14 | 10,7,9,12,9,7,8,7,7,7,8,6,14,42 | `0x0A9D8`, 6 unique, 8/14 → `0xB154` |
| 3.1.12 | 14 | 10,7,9,12,9,7,8,7,7,7,8,6,14,42 | `0x0AA2C`, 6 unique, 8/14 → `0xB1A8` |
| 3.2.0 | 10 | 10,7,9,7,7,8,15,13,7,42 | not detected |

Full per-site rows including every case target are in the JSON above.

3.1.12's 14-case table, case → handler (**OBSERVED**):

```
09 → 0AF24   0A → 0AEE4   0B → 0B1A8   0C → 0AF5C   0D → 0B1A8   0E → 0B1A8
0F → 0B1A8   10 → 0B1A8   11 → 0B1A8   12 → 0AEE4   13 → 0AFA4   14 → 0B1A8
15 → 0B1A8   16 → 0AFC6
```

Guard: `subs r0,#9 ; cmp r0,#0xd` — a switch over message types 9–22, with
Soft_Reset (0x0D) sharing the dominant target with seven other cases.

Established, and only this: **a table with that fingerprint is present in both
3.1.x builds and is not detected in 3.2.0 by this detector.**

Not established:

- That the two 3.2.0 tables of 15 and 13 cases are successors of this switch, or
  cover the same message types, or are control-message dispatchers at all.
  **OPEN.**
- That any case count is a source-level quantity. A dense table's length follows
  the guard's range span, and whether a switch compiles to one table, two tables
  or a compare chain is a code-generation decision. The earlier claim that "case
  counts come from source" is **REFUTED**.
- Anything about hard-reset handling: per the USB-PD specification Hard_Reset is a
  vSafe0V protocol action with no MessageType, so a 9–22 message-type switch
  cannot speak to it. "Hard-reset handling changed" is **REFUTED**.

## 4a. Two Ghidra bodies compared (OPEN)

The dominant switch target lies inside a function Ghidra did decompile, so two
bodies can be compared. Literal sets were re-extracted with the §2 rule.

| | 3.1.12 | 3.2.0 |
|---|---|---|
| function reported by Ghidra | `0x0B0F0` | `0x0B18C` |
| instructions | 110 | 89 |
| normalised pseudocode length | 906 chars | 637 chars |

```
shared         : 4 14 32 33 62 84 85 88 105 444 460   (11 values)
only in 3.1.12 : 3 8 10 19 80 92 1024                 (7 values)
only in 3.2.0  : 28                                   (1 value)
```

Including the trivial `0` and `1`, the intersection is 13. Counts reconcile:
11 + 7 + 2 = 20 on the 3.1.12 side; 11 + 1 + 2 = 14 on the 3.2.0 side.
**REPRODUCED** by `scripts/literal_sets.py`.

**Status: OPEN.** Under an unvalidated pairing the two bodies differ in length and
in literal set. Cause undetermined — source change, inlining/outlining, or
mis-pairing all fit. Reasons no stronger reading is offered:

- The pairing is inferred. The ratios quoted in an earlier revision (0.713 /
  0.896) came from an unrecorded run and are dropped.
- Handler entry `0xB1A8` is `0xB8` bytes inside the reported function start
  `0x0B0F0`, and the other five case targets lie before `0x0B0F0`. Nothing
  establishes that `0x0B0F0` is a true function entry, and §3 records that this
  analysis mis-delimits code.
- No control comparison exists: the same handler is at `0xB154` in 3.1.8, but no
  3.1.8-vs-3.1.12 comparison of length or literal set was made, so there is no
  baseline for natural variation between near-identical builds.
- Nothing ties `0x0B18C` to any dispatch table; the dominant targets of the two
  3.2.0 switches are `0x0554A` and `0x05704`.

Earlier wording — "the shared handler changed", "a semantic difference, not a
code-generation difference", "the handler's logic differs" — is **withdrawn**.

## 4b. Apple SVID literal sites (OBSERVED)

Whole-image literal counts, little-endian:

| literal | 3.1.8 | 3.1.12 | 3.2.0 |
|---|---|---|---|
| `0x05AC8106` | 1 | 1 | 1 |
| `0x05AC0005` | 2 | 2 | 2 |
| `0x05AC0002` | 1 | 1 | **0** |
| `0x05AC0000` | 6 | 6 | **7** |

Exactly one literal changes across the three releases: `0x05AC0002` disappears
and `0x05AC0000` gains an occurrence. **OBSERVED**, independent of any matching.
What the change means is **OPEN**; the enclosing functions are outside the
analysed set (§3), so no function-level comparison is possible.

Sites and the instructions that load them:

| build | `0x05AC0005` | `0x05AC8106` | `0x05AC0002` | `0x05AC0000` |
|---|---|---|---|---|
| 3.1.12 | `0x0C340`, loaded at `0xC322`, `0xC32E` | `0x0C344`, loaded at `0xC326` | `0x0C724`, loaded at `0xC6B6` | `0x0C66C` |
| 3.2.0 | `0x0C4E0`, loaded at `0xC4C2`, `0xC4CE` | `0x0C4E4`, loaded at `0xC4C6` | — absent | `0x0C82C`, `0x0C8FC` |

Byte agreement within fixed windows, best uniform shift per window:

| window | shift | agreement |
|---|---|---|
| `0xC2C0–0xC350` | `+0x1A0` | 63.9 % |
| `0xC5E0–0xC640` | `+0x1C0` | **100.0 %** |
| `0xC6B0–0xC730` | `+0x1D8` | 32.0 % |

Reading, deliberately narrow:

- One 96-byte window is byte-identical under a single uniform shift.
  **OBSERVED** at byte level. Whether the enclosing code is unchanged is
  **OPEN** — a 96-byte window says nothing about the function containing it, and
  the earlier `RELOCATED` label was misapplied to code.
- The 32 % window is **not** evidence of a rewrite: a single uniform shift cannot
  distinguish rewriting from an insertion or deletion inside the window, and an
  `0x18`-byte insertion sits nearby. **"Substantially rewritten" withdrawn;
  OPEN.**
- Three windows moved by three different shifts. Consistent with reordering
  between them, but three values do not independently establish reordering.
  **INFERRED.**
- An earlier revision called this region "the UVDM builder" and asserted the
  change was "not in the builder itself". **Both withdrawn.** These are sites
  that load Apple SVID literals. That they constitute a UVDM builder is a
  subagent claim never re-derived here; `FIRMWARE.md` §7 records the same limit.
  This section makes no claim about what the code does.

## 5. Power-negotiation table (OBSERVED, REPRODUCED)

4-entry fixed-PDO table, duplicated twice per image. Decode:
`voltage = bits 19:10 × 50 mV`, `current = bits 9:0 × 10 mA`.

| version | copy 1 | copy 2 |
|---|---|---|
| 3.1.8 | `0x136E4` | `0x137D4` |
| 3.1.12 | `0x13764` | `0x13854` |
| 3.2.0 | `0x13894` | `0x13984` |

Content identical in all six copies: `5.00 / 9.00 / 15.00 / 20.00 V @ 3.00 A`.
**REPRODUCED** by `scripts/diff_verify.py`. Placement moves with the rebuild, so a
fixed-offset read in 3.1.12 or 3.2.0 returns unrelated bytes; the subagent claim
that one address holds the table in all builds is **REFUTED**.

What the table *is* remains **INFERRED**: a capability set consistent with a
source PDO list. It is not the 20 V / 3.39 A contract the host reported, which
belongs to the adapter's negotiation with the Mac.

## 6. Version strings (OBSERVED)

No ASCII build, version or hardware-revision string exists in any image. Versions
are numeric and rendered by the host (`"FWVersion": %u`, `%s%d.%d.%d`), so version
identification rests on the container header and `bcdDevice`, as documented in
`FIRMWARE.md`.

## 7. USB-PD / VDM literals (OBSERVED)

Searched all three images for the 4CC `VDMs` (`56 44 4d 73`), `VDM`, and PD
message-type constant runs over 0x01–0x26 in byte and halfword form: zero hits.
The `VDMs` 4CC the macOS kernel emits (`PROTOCOL.md` §2) does not appear in the
cable firmware. A 33-entry pointer table reported by a subagent is unreferenced —
nothing branches to it — and is not called a dispatch table here.

## 8. Verdicts

Issued:

- A 14-case table with 6 unique targets and 8/14 to one target is present in
  3.1.8 and 3.1.12 and not detected in 3.2.0. **OBSERVED.**
- The `mov pc` dispatch mechanism survives in 3.2.0 with 10 detected sites, its largest
  tables being 15 and 13 cases. **OBSERVED.** "The dispatcher disappeared" is
  **REFUTED**.
- Exactly one Apple SVID literal changes across the releases. **OBSERVED.**
- PDO table content is identical across all three. **REPRODUCED.**

Withheld:

- Whether 3.2.0 is semantically equivalent to 3.1.12. **OPEN** — undeterminable
  at 39 % coverage with the paths of interest outside the analysed set.
- Whether a soft→hard reset escalation exists. **OPEN.**
- Any host-observable behavioural difference. **OPEN.**

## 9. What would make the comparison reliable

Re-analyse all three images with a Cortex-M language specification and seeded
entries: the pointer block at 0, the `0x10` entry, and every `mov pc` case target
as a function start. That should move the switch and literal-site regions into
the analysed set. Then run the matcher with within-build hard negatives and a
threshold capped below 1.0, reporting a confidence distribution rather than a
mean. Neither step was performed here.

## 10. Recorded failures

- `evidence/functionmatch/match_final.json`: **void, twice.** First attempt:
  bounded disassembly used a multi-line rizin `-i` script this build rejects, so
  every function got an empty mnemonic list, `M = 0`, the composite capped at
  0.75 and the 0.78 threshold excluded everything. Second attempt: null pairs
  drawn from the other build contained the true counterpart, so null p99 = 1.0
  and the threshold became 1.03. Neither run is evidence of dissimilarity.
- `evidence/functionmatch/match.json`: superseded. Literals erased by a magnitude
  heuristic; mnemonics from whole-image linear decode.
- Two of my own jump-table reads were wrong before the empirical finder replaced
  them: an int32-delta read at `0xA9D8` and a Thumb `ADR` arithmetic model.
- Subagent claims corrected here: "uncovered 61 % is data" (**REFUTED**), "PDO
  table at a fixed address" (**REFUTED**), "`0xB154` shared handler"
  (**OBSERVED** true for 3.1.8).

## 11. Seeded Cortex-M re-analysis (supersedes §3/§4 detection limits)

Pipeline: Ghidra 12.1.4 headless, `-processor ARM:LE:32:Cortex -cspec default`
(same `ARM7_le.sla` as v7 but `ARMCortex.pspec` with `TMode=1` default, external
name `armv7e-m`). Census-derived seeds were first DIAGNOSED per address
(unit type, containing function, inbound refs, decode attempt —
`scripts/ghidra/DiagSeeds.java`); only seeds proven to be decodable code were
created, and only units proven wrong (with before/after evidence in the seed
log) were cleared. BL/B.W xref maps came from `scripts/ghidra/bl_xref.py`.
Delegated verification: `evidence/magsafe-cortexm/delegated/execmodel.md`,
`protocol.md`, `xversion.md`.

### 11a. Coverage (REPRODUCED)

| build | functions | coverage | prior generic-v7 |
|---|---|---|---|
| 3.1.8 | 444 | 46.4 % | 300 / 38.8 % |
| 3.1.12 | 436 | 45.2 % | 303 / 39.4 % |
| 3.2.0 | 423 | 56.2 % | 296 / 43.3 % |

Two independent 3.1.8 runs produce identical inventories except the `0x10`
function body length (4 vs 8 B). `0x10` stays **CANDIDATE** startup entry; the
reset-vector words still land in the pointer table at `0x10f4c..` and decode as
nothing (`REFUTED` as code, again). Addresses remain file offsets; no runtime
base is asserted.

### 11b. The control-message dispatcher, corrected (OBSERVED unless noted)

- 3.1.8 entry `0xa9bc`, guard `subs r0,#9; cmp r0,#0xd`, table `0xa9d8` with
  exactly 14 entries (`0xaa10` = `0xd0002c01`, not a pointer), six unique
  targets `0xaed0 0xae90 0xb154 0xaf08 0xaf50 0xaf72`, dispatch `mov pc,r0` at
  `0xa9d6`. 3.1.12 counterpart `0xaa10`, table `0xaa2c`, same case grouping.
- **§3's "switch site 0xAA2A" was mislabelled for 3.1.8**: at `0xaa2a` the
  bytes are `cmp r1,#0x28; bne 0xaa2e` (bytes `28 29 00 d1`) — a compare
  chain in the
  out-of-table cases, reached by fallthrough. `0xaa2a` is the 3.1.12
  dispatcher site. The earlier "not inside any Ghidra function" statements
  were true of the old analysis and are superseded by the seeded one.
- Body extent: Ghidra's function body says 552 B, but flow continues through
  shared epilogue at `0xacd4/0xacd6`; `0xa9bc..0xacd7 = 796 B`. The 552 figure
  is an analysis-boundary artifact, not a semantic size.
- Decompiler dataflow at `0xaf76`, settled after two conflicting delegated
  reports and an independent audit: `adr r1,#4` at `0xa9d2` sets `r1` to the
  table base `0xa9d8` before dispatch, and `r1` survives to
  `str r1,[r4,#0x60]` (`r4` = `0x20001854`). The decompiler's original claim
  `param_1[0x18] = &table` therefore STANDS; the intervening "writes the
  message type" reading was **REFUTED**. The `blx r1` branch at `0xaf80`
  exists (r0 = 0 or 1) but is reached only when `0x20001854[0x11] == 0`;
  whether either path executes is **OPEN** (liveness, §11b above).
  Control-flow structure of the decompilation is otherwise supported by
  decode. (Audit: delegated/review/.)
- **Liveness OPEN**: no BL, B.W, pointer word or halfword reference to
  `0xa9bc` (or `0xaa10`) exists in either image. The island `0xa9bc..0xb1a3`
  has zero static inbound edges, and three of its six case targets enter
  foreign stack frames. Inferred (not established): scheduling via a
  function-pointer/callback mechanism invisible to static xref, or a
  stale/duplicated copy. Do not call it "the live control-message handler".
- Callee deltas 3.1.8→3.1.12 are NOT uniform (the subagent claim of a
  uniform +0x54 shift is **REFUTED**): 14 callees are address-identical;
  table-adjacent code moved +0x54; the large handler `0xd904→0xd984` moved
  +0x80.
- Case-value → USB-PD message-type mapping (9=DR_Swap … 22=Get_Sink_Cap_Ext
  under standard PD numbering; earlier draft numbering in this document was
  off by one) remains **INFERRED**; no in-image constant names a type.
  Out-of-table cases 2, 3, 0x28, 0x3d, 0x41: **OPEN**.

### 11c. 3.2.0 (OBSERVED)

The 14-case 9–22 table is absent (`REFUTED` both "unchanged" and "the
dispatcher disappeared"). Three switches with different guards and message
index sources exist: entries `0x4b78` (8 cases, span 2–9), `0x50fc` (13 cases,
span 2–14), and `0x4eca` (15 cases, span 3–17, reached only indirectly).
Whether any is the successor of the 3.1.x control-message dispatcher:
**OPEN**.

### 11d. Cross-version match (first pass, many-to-many caveat)

Audit-corrected figures (the first-pass numbers were computed against a
superseded 430-function 3.2.0 inventory): 181 exact signatures shared by all
three builds, covering 224/222/209 functions. 3.1.8→3.1.12: 98.2 % exact.
3.1.12→3.2.0: 49.9 % strict, 234 pairs at similarity ≥ 0.85, 189 3.2.0
functions without a counterpart (largest `0xfbc8`, 2,932 B). Max
mnemonic-sequence multiplicity 7 (3.2.0), so these counts are many-to-many
upper bounds, consistent with §2's rule that no per-function semantic claim
rests on them yet. (Reproduced by the auditor with `match.py` on current
inventories: `delegated/review/match_result_audit.json`.)

### 11e. New evidence bounds

The largest uncovered 3.1.8 region `0x10abc..0x129f0` (7,988 B) is a
coherent code island with prologues at `0x10ac0/0x10b30/0x12938/0x129c8`,
an `"NVM0"`-tagged descriptor table at `0x10f4c`, and no external caller —
like the dispatcher island, statically unreachable. Roughly 22.7 kB of the
image (27 %) contains coherent `push {…,lr}` bodies outside the analysed
function set; 4.4 kB are strings. Reachability of these islands is **OPEN**
and bounds every claim in §11.

## 12. Second investigation wave (liveness, successor, calibrated matcher)

Delegated evidence: `delegated/liveness.md`, `delegated/successor.md`,
`delegated/matcher.md` (+ scripts/results alongside). Independent spot-checks
by the lead are marked below.

### 12a. Liveness of the islands (3.1.8)

- Base+delta relocation pattern: **REFUTED** by exhaustive word-pair scan
  (`delta_scan.py`): zero co-located pairs whose difference equals any island
  entry; zero anchored hits.
- The callback mechanism exists and is used by reachable code: `0x1d00`
  installs a 13-entry vtable (`0x13a2c`) at `port_obj+0x60`; 47 reachable
  `ldr [rY,#0x60] → blx` sites all dispatch on `0x200002b0 + port*0x1cc`;
  the vtable image words are all zero, i.e. runtime-filled. The islands are
  never installed or called through this mechanism in-image.
- The `"NVM0"` block at `0x10f4c` is a flat descriptor (masks + MMIO run +
  3 odd code points), referenced only by the vector words at 0x4/0x8/0xc and
  one literal inside the island itself (`0x12978`); `0xe000ed08` (VTOR) is
  absent from the image, and the startup at `0x10` (90 instructions decoded)
  never reads it.
- Verdict per island: **no evidence of static reachability**; dead/stale-copy
  not refuted (3.1.12 retains a counterpart). One positive internal link: the
  large island calls `0x10` (`0x12960 bl 0x10`).
- **Correction of a delegated "correction"**: the claim that `0xaf76`'s
  stored `r1` is the containing function's argument is true only for a direct
  call entering at `0xaf54`. On the table path the dispatcher jumps
  `mov pc,r0` from `0xa9d6` straight into `0xaf72`, no prologue runs, and
  `r1` is still the table base `0xa9d8` set at `0xa9d2` — the §11b reading
  stands for that path. Both entries of `0xaf54` are now on record; which
  runs is **OPEN** (liveness).
- Environment note: Ghidra 12.1.4 remains installed at the canonical path;
  the subagent's "no longer installed" report was an environment artifact.

### 12b. 3.2.0 switch landscape and the successor question

- The three inventoried switches (`0x4b78`, `0x50fc`, `0x4eca`) are decoded
  and boundary-checked; none matches the 3.1.x dispatcher on index register,
  grouping shape or callee set (callee overlap 1/19, 1/20, 1/12; LCS ≈ 2%).
- Two further dispatch sites exist in uncovered 3.2.0 code (`0xa958`,
  `0xab64`); the landscape was incomplete.
- **The 3.1.x dispatcher's second-stage switch has a verified successor**:
  `0xad2a` (3.1.8) / `0xad7e` (3.1.12) / `0xab64` (3.2.0) share the identical
  guard `mov r3,r2; subs r3,#8; cmp r3,#0x10; bls` (lead-verified in all
  three images), identical index chain and `add pc` table fetch, 17 cases
  (span 8–24) in 3.2.0 vs a 17-byte byte-table in 3.1.x — same grouping
  (1,8,1,1,2,1,1,1,1; 10/17 dominant), non-dominant offsets growing
  monotonically. The only structural change is the index width
  (`ldrb` → `ldrh` halfword table). **INFERRED, high confidence.**
- The 14-case outer table has no 3.2.0 counterpart on current evidence:
  **OPEN** whether its function was removed, renamed beyond recognition, or
  lives in an uncovered island.
- SVID-literal anchoring is a **negative** cross-check: the pair builder
  tracks `0xc2b8 → 0xc30c → 0xc4ac`, but the 3.1.x dispatcher never calls
  into the SVID region, so the literals cannot arbitrate the successor
  question.

### 12c. Calibrated matcher (§2 gate satisfied)

`match_calibrated.py` fixes both recorded failure modes: mnemonics come from
Ghidra body ranges (hard-fail on empty sequences) and calibration draws
hard negatives from WITHIN each build. Calibration: 352 known-true
3.1.8→3.1.12 pairs all score 1.0 (TPR 1.0); 41,103 within-build gated
negative pairs, hardest non-identical negative 0.9829 → threshold 0.9830
(cap rule < 1.0), FPR 0.0 on non-identical negatives; the only false
positives are 197 exact-duplicate body pairs, handled by the ambiguity rule.

3.1.12→3.2.0 at 0.983: **167 unique 1:1 pairs (155 non-stub), 208 ambiguous
pairs over 48 duplicated-signature functions, 208 unmatched 3.2.0 functions
(173 non-stub, largest `0xfbc8` 2,932 B)**. At 0.85: 195 unique (30
"probable"), 337 ambiguous, 150 unmatched. 9.2 % of the first-pass pair set
sat on duplicated signatures — the §11d greedy counts overstated resolvable
matches by ~40 %. The §11d delta vs the audit rerun is explained exactly by
`difflib autojunk` (verified both ways).

Claim status: pair memberships are now confidence-graded; no semantic claim
rests on any pair yet. Open: 16-byte size gate may suppress true
correspondences for large unmatched functions; the 30 "probable" pairs need
literal/callee-multiset confirmation before use.

## 13. Third wave: update transport and security bounding

Delegated evidence: `delegated/vdm/` (SPEC.md), `delegated/security/`
(hash_test.py/.log, field_matrix, crypto_scan). Lead independently
reproduced the load-bearing claims (marked below); the flagged image/payload
offset convention: **the flat base0 images equal `payload[0x180:]`** — the
384-byte C99 header is the payload's first 0x180 bytes (verified byte-exact
on 3.1.8). Delegated offset tables are image-space; add 0x180 for payload
space.

### 13a. Update transport (host side OBSERVED, cable side OBSERVED)

- `VDMs` is a 4CC command tag, one of many: `hpmIECSCommand` revs an
  arbitrary 4CC and polls for `!CMD`; `hpmIECSSendVDM` appends the tag via a
  second call. UARP uses `CFUa`/`CFUp`/`CFUs` as runtime 4CC arguments (0
  static hits in the kext — earlier "CFUp 11x" was the false positive
  `CPUF`). CFUa descriptors carry `_sopType` bits 31:30; the stored value is
  **OPEN**.
- Cable side, all three builds: a real SVDM dispatcher exists at 3.1.8
  `0xb34c` (prologue verified by lead): SVID compare via `lsrs r0,r4,#0x10`
  against `0x05AC` (pool `0xb59c`), structured/unstructured split on bit 15,
  unstructured handler `0xb64c` accepting 1–5 VDOs with **no 4CC compare**.
  Composes `0x05AC8106` (Discover Identity) at `0xc2ce` (3.1.12 `0xc344`,
  3.2.0 `0xc4e4`). `VDMs`/`CFU`/`UARP` strings: 0 hits in all three images.
- Reading: the update TLV transport is not visible above the 4CC-tag layer
  in the cable images; whether CFU is consumed below the app image (PD
  PHY/ROM) is **OPEN**. A single passive CC capture during an update would
  settle endpoint, envelope and chunk size at once (no experiment run).

### 13b. Integrity: the C99 header is a two-record hash chain (REPRODUCED)

Lead re-derived all five relations byte-exactly on all three payloads:

- `sha256(payload[0x180 : 0x180+lenf]) == field@0x110` and
  `crc32(body) == field@0x108` (body = the shipped firmware image)
- `sha256(payload[0x100 : 0x180+lenf]) == field@0x0c` (record 3 = header
  prefix + body)
- `sha256(payload[tail .. EOF]) == field@0x30` (record 4, the second
  crypto-bearing module; tail = `0x13e34/0x13eb4/0x14084`)
- `sha256(payload[0:0xa0]) == field@0xe0` (header self-hash)

FIRMWARE.md §6's "header contents not recovered" is **superseded**: the
header carries a complete SHA-256/CRC-32 hash tree over the image, record 3
and record 4, plus its own self-hash. Unexplained remain `0xa0..0xdf`
(64 B) and the `0x17c` trailer word.

### 13c. Crypto inventory (REPRODUCED)

SHA-256 (FIPS 180-4 K table + IV, twice per image) and a complete secp256r1
parameter block (p, b, Gx, Gy, n — lead-verified byte-exact at payload
`0x1336c` et seq. for 3.1.8) are present. No RSA, AES, secp256k1. The
64-byte `0xa0..0xdf` field is range-valid as an ECDSA (r,s) but not
on-curve: the embedded-public-key reading is **REFUTED**; its role is
**OPEN**. The crypto block sits outside the analysed function set
(uncovered island) — enclosing function unidentified.

### 13d. Anti-rollback and update path

- No version-threshold constant or `cmp.w` exists in any image; at 46–56 %
  coverage "no anti-rollback" is **NOT claimed** — **OPEN**, byte-granular
  or register-register compares are indistinguishable statically.
- `0xd904` (3.1.8; `0xd984`/`0xdb40` successors) is a table-driven flash
  programmer: 18 address/value records, 256-B transfer splits, command +
  3-byte-address writes to `0x40070240` with per-byte status polling
  (`&0x1f <= 0xe`), erase commands `0x20/0x52/0xD8` at 4 kB alignment,
  guarded to address `< 0x40000`. No hashing or compare inside it; integrity
  enforcement therefore lives elsewhere (the hash chain of §13b is the
  candidate, but nothing OBSERVED wires them together yet).
