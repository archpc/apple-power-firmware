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
