# Per-pair semantic diff — MagSafe A2363 3.1.12 → 3.2.0 (calibrated 1:1 pairs)

Scope: the 155 non-stub unique 1:1 pairs at threshold **0.9830** from
`../matcher/results_calibrated.json` (`pairs_3112_320.unique_1to1`, `n ≥ 8`).
Decoding: `rizin 0.9.1 -e scr.color=0 -a arm -b 16`, file offsets, no runtime
base asserted. Images: `firmware/images/A2363_3.1.12_10M1543_base0.bin`
(83 592 B) and `A2363_3.2.0_10M13722_base0.bin` (84 048 B).

Labels: **OBSERVED** = printed by a run in this directory or read directly from
bytes; **COMPUTED** = arithmetic over those observations; **INFERRED** =
semantic reading explicitly separated from the instructions that support it;
**OPEN** = not settled; **NOT CLAIMED** = refused.

Nothing here re-opens the matcher's pairing claim. Every statement below is
about *the pair as given*; if a pair were wrong, the diff would be a diff
between two unrelated functions.

---

## Step 1 — Selection, and the size-changed list that does not exist

**OBSERVED / COMPUTED** (`analyze.py`, `analyze3.py` over the 155 pairs):

- 151 pairs have an *identical* canonical mnemonic sequence; 5 differ
  (`0x1178`, `0x1df0`, `0xa018`, `0xbb4c`, `0xcf38`). Note `0xa018` scores
  `s = 1.0` in the matcher yet its sequence differs — the matcher compares
  `difflib` ratio over token multisets, and a same-position `ble`→`bls`
  substitution leaves the ratio at 1.0. **Consequence: `s = 1.0` does not mean
  "same instructions".**
- **154 of 155 pairs have |Δbody size| = 0**; exactly one changes size
  (`0x1df0`, 268 → 276 B, +8).
- DIFF.md has **no section 2e**: §2 is four paragraphs of method prose and
  contains no size-changed list (checked by reading §2, lines 36–52). The
  requested "top-10 size-changed list" therefore does not exist to reconcile,
  and the data cannot produce one — there is one size-changed pair, not ten.
  **Substituted selection**, stated so it can be audited:

| # | pair | why selected |
|---|---|---|
| 1 | `0x1178`→`0x11a0` | mnemonic sequence differs (s 0.98485) |
| 2 | `0x1df0`→`0x1d78` | mnemonic sequence differs **and** only size-changed pair (+8 B) |
| 3 | `0xa018`→`0xa020` | mnemonic sequence differs at s = 1.0 |
| 4 | `0xbb4c`→`0xbc6c` | mnemonic sequence differs (s 0.98551) |
| 5 | `0xcf38`→`0xd0c8` | mnemonic sequence differs (s 0.99138) |
| 6 | `0x17cc`→`0x175a` | most non-target changes (12 register-only) |
| 7 | `0x8ff4`→`0x9128` | 5 non-target changes (4 offsets + 1 immediate) |
| 8 | `0x1244`→`0x126c` | 4 offset changes, uniform −8 |
| 9 | `0x9ddc`→`0x9dec` | 4 changes, uniform +0x20 |
| 10 | `0xc78c`→`0xc908` | 4 changes (2 reg + 2 imm, swapped compares) |
| 11 | `0xd908`→`0xdac4` | 3 changes (2 offsets + 1 index) |
| 12 | `0x9964`→`0x993c` | 2 immediate changes, largest single constant delta |

All five mnemonic-divergent pairs fall inside the top 12 by body size as well,
except `0xa018` (52 insns / 106 B), which is small; the two rankings overlap by
four, no pair in the size ranking was displaced, and `0xa018` is included
because its mnemonic sequence differs at `s = 1.0` — the case the divergence
ranking exists to catch.

---

## Step 2 — The twelve pairs, decoded windows (OBSERVED)

**1. `0x1178` → `0x11a0`** (66/66 insns, 146/146 B). One instruction deleted,
one inserted. Old `0x1198 ldr r5,[pc,0x74]` then `0x119a ldr r0,[r5,0x48]`
then `0x119c cmp r1,r6`; new `0x11c0 ldr r0,[pc,0x74]` then `0x11c2 cmp r1,r5`
— the base pointer load into `r5` and the subsequent dereference of field
`0x48` are gone, and the compare is against `r5` itself. Second site: new
`0x11de ldr r0,[r0,0x40]` inserted between `beq` and `lsls`, where old has no
load. The literals `0x48`/`0x40` appear only on the respective side
(`constcheck.json`). Two `invalid` decode slots, at the same indices in both
images — a decoder slot, not a difference.

**2. `0x1df0` → `0x1d78`** (131/135 insns, 268→276 B). New inserts a
read-modify-write bit clear at entry: `0x1d7a movs r1,8; 0x1d7c bics r0,r1;
0x1d7e str r0,[r6,0x6c]`, where old goes straight from
`0x1df0 str r0,[r6,0x6c]` to `0x1df2 ldr r0,[r6,0x6c]`. A second insertion at
`new[12]` is an extra `ldr r2,[sp,0x10]` that re-loads a spilled pointer before
`ldr r0,[r2,0x18]` (old uses `r7` live). **Caveat, OBSERVED**: this pair has 6
`invalid` slots on the old side and 10 on the new (the only asymmetric pair in
the set), and the tail windows (`old[121:125]`, `new[131:135]`) are a decode
desync: re-decoding the new image from `0x1e74` yields
`str r1,[r6,0x1c]; ldr r0,[0x1eb8]; str r0,[r5,0x48]; movs r0,0x32`, matching
the old stream modulo relink and register (`r4`→`r5`). The tail diff is
therefore **a decoder-boundary artifact** and is not counted as a change. Only
the two head insertions stand.

**3. `0xa018` → `0xa020`** (52/52 insns, 106/106 B). Two conditional branches
change condition with the compare untouched: `0xa030/a038 cmp r4,r0` followed
by `ble 0xa03e` (old) vs `bls 0xa046` (new); and `0xa040/a048 cmp r4,r0`
followed by `bgt 0xa048` (old) vs `bhi 0xa050` (new). Everything else in the
52 instructions is identical modulo branch targets. Signed → unsigned.

**4. `0xbb4c` → `0xbc6c`** (69/69 insns, 150/150 B). Old `0xbb56 ldr r0,[pc,0xa0];
0xbb58 ldrb r0,[r0,0x18]` — pool pointer, fixed field `0x18`. New
`0xbc76 movs r0,0x20; 0xbc78 ldr r1,[pc,0x9c]; 0xbc7a ldrb r0,[r1,r0]` — the
same kind of table pointer, but indexed by an immediate `0x20`. Old also
carries `0xbb62 mov r8,r8` (a 2-byte no-op padding instruction) which the new
build lacks. Literals `0x18` (old only) and `0x20` (new only).

**5. `0xcf38` → `0xd0c8`** (116/116 insns, 246/246 B). Pure reordering:
`0xcf8a ldr r2,[pc,0xb4]; 0xcf8c cmp r0,0; 0xcf8e bmi ...` becomes
`0xd11a cmp r0,0; 0xd11c ldr r2,[pc,0xb0]; 0xd11e bmi ...`. The pool
displacement necessarily shifts (`0xb4`→`0xb0`, 4 bytes) because the `ldr` moved
across a 4-byte `cmp`; no instruction is added, removed or re-targeted other
than the branch.

**6. `0x17cc` → `0x175a`** (43/43 insns, 86/86 B). Twelve register renames and
no constant or opcode change: `ldrh r1,[r3,r2]`→`ldrh r4,[r3,r2]`,
`muls r1,r5,r1`→`muls r4,r5,r4`, `uxth r4,r1`→`uxth r2,r4`,
`adds r2,r4,r2`→`adds r1,r2,r1`, `strh r2,[r7]`→`strh r1,[r7]`, closing
`lsrs r2,r2,0x10`/`lsrs r1,r1,0x10` swapped. The two accumulator registers
(r1, r2) and the scratch register (r4) are permuted consistently through the
loop body; immediates (`0x10`, `2`, `1`) are unchanged.

**7. `0x8ff4` → `0x9128`** (39/39 insns, 84/84 B). Three field offsets move by
+0x0c (`[r5,0x58]`→`[r5,0x64]` at `0x9004/0x9138`, `0x9014/0x9148`,
`0x903c/0x9170`), and one immediate moves by −8: `0x9034 adds r1,0x28` →
`0x9168 adds r1,0x20`, whose result is the argument to `bl 0x9fa4`/`0x9fac`.

**8. `0x1244` → `0x126c`** (37/37 insns, 82/82 B). Four stores, all −8:
`str r1,[r3,0x14]`→`[r3,0xc]`, `str r2,[r3,0x10]`→`[r3,8]`, and the same two
through `r1` at `0x128c/0x12b4`. The relocation is uniform across both base
registers, i.e. the two destination fields both moved down 8 bytes.

**9. `0x9ddc` → `0x9dec`** (11/11 insns, 24/24 B). Entire body, old → new:
`ldr r4,[pc,0x14]; ldr r0,[r4,0x50]; adds r0,r0,1; str r0,[r4,0x50];
mov r0,r4; adds r0,0x38; movs r1,0x1c; bl 0x1460; str r0,[r4,0x54]; pop`.
New: `...[r4,0x70]` (twice), `adds r0,0x58`, `bl 0x140c`, `str r0,[r4,0x74]`.
Three displacements +0x20 and one immediate +0x20, uniform.

**10. `0xc78c` → `0xc908`** (67/67 insns, 146/146 B). The two guard compares are
exchanged: old `cmp r1,0xff; beq; cmp r2,0; beq`; new `cmp r2,0; beq;
cmp r1,0xff; beq`. Both branches target the same respective labels
(`0xc80a`/`0xc986` modulo relink). Same predicates, different evaluation order.

**11. `0xd908` → `0xdac4`** (45/45 insns, 112/112 B). `0xd926 movs r6,0x33` →
`0xdae2 movs r6,0x31` (index into `[r5,r6]` used by `strb` at `0xd92a` and
`ldrb` at `0xd938`), and two offsets `0xc`→`0x13` (+7) at `0xd942/0xdafe` and
`0xd95a/0xdb16`. Nothing else changes.

**12. `0x9964` → `0x993c`** (37/37 insns, 88/88 B). `0x9978 movs r0,0x40` →
`0x9950 movs r0,0x60`, where `r0` indexes `ldrb r5,[r4,r0]` immediately after;
and a second constant pair `0x58`→`0x38` later in the body (`constcheck.json`
lists `old {0x40,0x58}` vs `new {0x38,0x60}`).

---

## Step 3 — Semantic readings (INFERRED, each tied to the instructions above)

Only pairs whose decoded window alone supports a reading are listed. Everything
not listed stays at the structural class in Step 5.

**I1 — `0xa018`: the comparison became unsigned (strong).** The `cmp r4,r0` is
byte-identical; only the condition code changes, twice, and in the consistent
direction signed `ble`/`bgt` → unsigned `bls`/`bhi`. Supporting instructions:
`0xa030 cmp r4,r0` / `0xa032 ble 0xa03e` vs `0xa038 cmp r4,r0` /
`0xa03a bls 0xa046`; `0xa040 cmp r4,r0` / `0xa042 bgt 0xa048` vs
`0xa048 cmp r4,r0` / `0xa04a bhi 0xa050`. **INFERRED**: the value compared
(loaded from the pool at `0xa02e`/`0xa036`) is treated as unsigned in 3.2.0 —
a counter, length or millivolt-like quantity rather than a signed delta. The
values themselves are unchanged, so this is a *type* change, not a threshold
change. What is **NOT CLAIMED**: which physical quantity, or that behaviour
changes for any real input (for non-negative inputs the two are identical).

**I2 — `0x9ddc`: an object member block grew by 0x20 bytes (strong).** Four
operands move by exactly +0x20 in an 11-instruction body, including the pointer
handed to the callee: `adds r0,0x38` → `adds r0,0x58` with `r0 = r4`
(`0x9de6-0x9de8` vs `0x9df6-0x9df8`). **INFERRED**: in 3.2.0 the fields at
`+0x50/+0x54` sit at `+0x70/+0x74`, and the sub-object passed to `0x140c`
starts 0x20 bytes later — i.e. a 0x20-byte block was inserted before these
members in whatever struct `r4` points at. The counter increment
(`adds r0,r0,1` on `[r4,0x70]`) is structurally unchanged.

**I3 — `0xd908`: a per-index byte array shifted and an index value changed
(moderate).** `movs r6,0x33`→`0x31` feeds `strb r1,[r5,r6]` / `ldrb r0,[r5,r6]`,
and the two field accesses move `0xc`→`0x13` (+7). The two facts are
consistent: an array base sits 7 bytes later and the index into a parallel
byte array decreased by 2. **INFERRED**: this is a per-port/per-channel record
whose layout changed (7-byte prefix, 2 slots removed before this index).
Supporting, same build, same +7 pattern in two other pairs (`0xa7dc`
`0xc`→`0x13`, `0xa824` `0xb`→`0x12`, `0xc`→`0x13`). **NOT CLAIMED**: what the
record describes.

**I4 — `0x9964`: an indexed table base moved from 0x40 to 0x60 (moderate).**
`movs r0,0x40` → `movs r0,0x60` immediately before `ldrb r5,[r4,r0]`
(`0x9978-0x997a` vs `0x9950-0x9952`), with the same `adds r0,r5,1` /
`cmp r1,0x63` / `bhi` bound check after it on both sides. **INFERRED**: the
same byte is read from a table slot 0x20 further along, i.e. the record for this
index grew or a new field was added before it; the valid-range check
(`≤ 0x63`) is unchanged, so the table's *length* did not change.

**I5 — `0xbb4c`: a fixed-offset read became an indexed read (moderate).**
Old reaches the byte through one pool pointer and a literal displacement
`0x18`; new materialises `0x20` in a register and indexes `[r1,r0]` through a
*second* pool pointer (`0xbc78 ldr r1,[pc,0x9c]`). **INFERRED**: the 3.2.0 code
selects a slot at runtime (`0x20`) from a table whose base is now loaded
separately, where 3.1.12 read a compile-time field — a lookup that was
constant-folded in 3.1.12 and is not in 3.2.0. The drop of `mov r8,r8`
(padding no-op) is consistent with recompilation of this region.

**I6 (weaker, stated for completeness) — `0x8ff4`: argument and field move in
opposite directions.** Field offsets +0x0c but the immediate passed as an
argument (`adds r1,0x28`→`0x20`) −8. **INFERRED**: the struct grew while the
argument constant — a size/limit passed to callee `0x9fa4`/`0x9fac` — shrank;
these are two independent edits, not one layout shift. **OPEN**: whether the
shrunken constant is a length that now matches a shorter array.

---

## Step 4 — Constant-level cross-check

Two measurements, because they answer different questions and one of them is
known to be contaminated.

**A. Raw non-pointer word multiset (the specified method).** 4-byte-aligned
words inside the body range with value ≥ image length, image pointers therefore
excluded by construction; `0x2000_0000-0x2008_0000` counted separately.
**COMPUTED**: differs in **5 / 155** pairs — `0x1178`, `0x1df0`, `0x2e30`,
`0x7a6c`, `0xe1bc`. This measure is a **bad proxy and is recorded as such**:
values like `0xa0fe6d` / `0xa0feb5` (`0x2e30`, Δ = 0x48) and `0xb62645`
(`0x1178`) are two packed 16-bit Thumb instructions read as a word, not
literals — the "difference" is the branch displacement, which is exactly the
relink artefact this check was meant to avoid. Three of the five pairs
(`0x2e30`, `0x7a6c`, `0xe1bc`) have *no* other change at all, which confirms
the reading. **Conclusion: the raw-word method has no discriminating power on
this corpus; it neither confirms nor refutes anything.**

**SRAM pointers (`0x2000xxxx`) remain a confound** in this measure: they are
addresses that relocate with the data layout and are not evidence of different
logic. **OBSERVED**: 16 of the 155 pairs contain at least one such word, and in
all 16 the *count* is identical on both sides, so no pair is flagged by SRAM
churn alone. A relocated SRAM pointer that changes value but not count would be
invisible here — this bound is stated, not resolved.

**B. Decoded-operand constants (syntax-based; the usable measurement).** A hex
literal on a non-branch, non-memory operand is an immediate by syntax; a hex
literal inside `[...]` is a field displacement. Branch/call targets excluded.
This is immune to the raw-word problem and does not need a magnitude filter
(applying one, as a first attempt did, silently drops every small immediate —
recorded because it produced a wrong 24-pair count before correction).
**OBSERVED** (`pass5_constcheck.py`, `constcheck.json`):

- **immediate** multiset differs in **11 / 155**: `0xf10` (`0xf7`), `0x1df0`
  (`0x32`), `0x8fa8` (`0x28`→`0x20`), `0x8ff4` (`0x28`→`0x20`), `0x9944`
  (`0x38`→`0x58`), `0x9964` (`0x40,0x58`→`0x38,0x60`), `0x9d38`
  (`0x25`→`0x2d`), `0x9ddc` (`0x38`→`0x58`), `0xbb4c` (`0x20` new only),
  `0xd908` (`0x33`→`0x31`), `0xf1b4` (`0x21`→`0x29`).
- **displacement** multiset differs in **23 / 155**, all of them in the table
  above plus `0x1178`, `0xcf38`, `0x12ac8`.
- union = **26 pairs**; the remaining 5 of the 31 semantically-changed pairs
  change registers or instruction order only and have no constant change.

**Displacement deltas are uniform per pair** (**COMPUTED**, 18 of the 20 pairs
that change displacements; `0xb9a0` is the exception with −4 and +8, and
`0x9604` reads `7`→`0xf` only because rizin prints small displacements in
decimal, a regex gap in `pass5_constcheck.py` that affects the *reporting* of
the delta, not the classification):
`−2` ×5 (`0x12a9c`, `0x12ac8`, `0x12b70`, `0x12bb0`, `0x9d38`), `−4` ×4
(`0xf28`, `0x131c`, `0x13bc`, `0xf1b4`), `+0x20` ×3 (`0x9dc0`, `0x9ddc`,
`0x9944`), `+7` ×3 (`0xa7dc`, `0xa824`, `0xd908`), `−8` ×2 (`0xe50`, `0x1244`),
`+0x0c` ×1 (`0x8ff4`), `+0x20` immediate (`0x9964`). A uniform shift of every
displacement in a function is what a *struct/record layout change* looks like;
an isolated edit would move one field. That is a structural fact; the semantic
reading of it is INFERRED and limited to I2/I3/I4 above.

---

## Step 5 — Deliverable counts and classification

**COMPUTED** over all 155 pairs (`results_pair_class.json`):

| class | pairs |
|---|---|
| `identical_modulo_target_relink` (same instruction text, different branch/call displacement) | **116** |
| `identical_instructions` (not even a target differs) | **8** |
| `field_offset_change` | 14 |
| `combined_field+imm` | 6 |
| `immediate_change` | 2 |
| `combined_imm+reg` | 2 |
| `register_change` | 2 |
| `instruction_sequence_edit` | 2 |
| `condition_signedness_change` | 1 |
| `indexed_load_replaces_fixed_offset_load` | 1 |
| `instruction_reordering` | 1 |

- **Pairs with any decoded instruction-level difference: 147 / 155 (94.8 %).**
- **Pairs with a substantive (non-relink, non-identical) difference: 31 / 155
  (20.0 %).** Of those, 26 change a constant or field offset, 2 change only
  registers, 1 changes signedness, 1 changes instruction order, 2 edit the
  instruction sequence.
- **124 / 155 (80.0 %) are byte-for-byte the same code once relink
  displacements are masked.** This is the first quantitative statement in this
  repo about *how much of the calibrated pair set is actually unchanged*, as
  opposed to merely matched.

Caveats that bound the numbers: `0x1df0`'s tail diff is a decoder desync and
was excluded from its change count (its two head insertions are real); 47/51
`invalid` decode slots across the set are symmetric and cancel, with `0x1df0`
the only asymmetric pair; addresses are file offsets; and the pairing itself
carries the matcher's stated confidence, not a proof of identity.

## Artifacts

- `analyze.py` — pass 1 (difflib opcodes, operand-string equality). Superseded;
  kept because its errors are documented (it mis-labelled a displacement change
  as register allocation).
- `analyze2.py` — pass 2 (field-level operand diff). Immediate extraction bug.
- `analyze3.py` — pass 3, corrected field splitter; `pairs_final.json`.
- `pass4_windows.py` — decoded windows for the 12 selected pairs;
  `windows12.json`.
- `pass5_constcheck.py` — constant cross-check; `constcheck.json`.
- `finalize.py` — emits `results_pair_class.json` (pair → class + the
  instruction that evidences it).

Open: whether any of the 31 changed pairs is *live* (no liveness claim is made
here); whether the uniform `−2` family (`0x12a70..0x12e34`) reflects a single
struct edit or a copy-relocated header; and whether the 116 relink-only pairs
include inlined/aliased duplicates the matcher resolved as 1:1.
