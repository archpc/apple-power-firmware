# 3.1.12 / 3.2.0 — seeded Cortex-M extension and first cross-version match

Scope: extends the validated 3.1.8 seeded Cortex-M pipeline to
`A2363_3.1.12_10M1543_base0.bin` (83,592 B) and
`A2363_3.2.0_10M13722_base0.bin` (84,048 B), then a first-order cross-version
match. All addresses are **file offsets** (base-0 import), not runtime addresses.
Nothing here forces data to code: every clear is gated on a default-analysis
listing that shows a 1-byte data unit sitting on a decodable `push {...,lr}`
prologue. Outputs live beside this file under `xversion/`.

Profile: `-processor ARM:LE:32:Cortex -cspec default`, Ghidra 12.1.4,
`JAVA_HOME=$(brew --prefix openjdk@21)`. Projects were built under `/tmp`
(analyzeHeadless rejects project paths containing dot-directories).

---

## Step 1 — BL xref maps and default-analysis seed diagnosis

`scripts/ghidra/bl_xref.py` (REPRODUCED → `xversion/bl_xref_3112.json`,
`xversion/bl_xref_320.json`):

| build | BL/B.W sites | distinct targets | push{lr} prologue candidates |
|---|---|---|---|
| 3.1.12 | 1,924 | 341 | 436 |
| 3.2.0  | 1,883 | 339 | 429 |
| 3.1.8  (reference) | — | — | — |

Seed lists were re-derived from `evidence/dispatcher-census.json` with the same
constructor as `seeds_318.csv` (`{0x10} ∪ {site} ∪ {case targets}`) and verified
**identical** to the checked-in `seeds_3112.csv` / `seeds_320.csv`
(`xversion/gen_seeds.py`, REPRODUCED): 107 and 87 entries.

`DiagSeeds.java` on a default-analysis import (REPRODUCED →
`xversion/diag_3112.txt`, `xversion/diag_320.txt`; 107/107 and 87/87 seeds
reported, script exited 0):

| build | seeds | disasm=FAILED |
|---|---|---|
| 3.1.12 | 107 | 10 |
| 3.2.0  | 87 | 3 |

Because `DiagSeeds` disassembles each seed in sequence, later seeds can see
listing mutations made by earlier ones; the classification below therefore uses
a read-only `DumpRange.java` pass over the same default analysis
(`xversion/dump_3112_fail.txt`, `xversion/dump_320_fail.txt`).

### 3.1.12 — all 10 FAILED seeds (OBSERVED)

| seed | default unit | classification |
|---|---|---|
| 0x10 | data len=4 | **reset-vector word** `0x00010ffd` — pointer, not code |
| 0x2c6a | none (inside data len=4 at 0x2c68) | **mid-data interior** — literal-pool word after `pop {r4,r5,r6,r7,pc}` at 0x2c64 |
| 0x2c78 | data len=4 | **jump-table data word** — 4-byte literal in the pool; case target points into the pool |
| 0x3b72 | none | **mid-instruction interior** — 2nd half of `bl 0x31a0` at 0x3b70 |
| 0x3dca | none | **mid-instruction interior** — 2nd half of `bl 0x31a0` at 0x3dc8 |
| 0x59c4 | data len=1 | **mid-instruction interior** — 2nd half of `bl` at 0x59c2 (bytes `01 f0 0f fa`) |
| 0x5a72 | none | **mid-instruction interior** — 2nd half of `bl 0x31a0` at 0x5a70 |
| 0x9adc | data len=1 | **mid-instruction interior** — 2nd half of `bl` at 0x9ada (`00 f0 1b f9`) |
| 0x9ae8 | none | **mid-instruction interior** — 2nd half of `bl` at 0x9ae6 (`ff f7 1f ff`) |
| 0xe7a4 | data len=1 | **constant-pool word** in the 0xe798 block (`20001940 000140bc 0ffff278 03010c00`); 4 identical adjacent 42-case-table entries point here |

Counts: 6 mid-instruction interiors, 2 data words (1 literal-pool, 1 constant-pool),
1 mid-data interior, 1 vector word, 0 unresolved-but-high-confidence.

### 3.2.0 — all 3 FAILED seeds (OBSERVED)

| seed | default unit | classification |
|---|---|---|
| 0x10 | data len=4 | **reset-vector word** `0x0001111d` — pointer, not code |
| 0x3c20 | data len=2 | **jump-table data word** — entry of a 16-bit constant table (`0x0030,0x003b,0x0058,0x0085,0x0089,0x016b…`); 7-case table 0x3704 points into it |
| 0xe9a0 | data len=1 | **constant-pool word** in the 0xe998 block (`6c41 6c43 f845 0000 f0ff 0fff d45b 0000`) |

(Note: the census tables sometimes point into data blocks, not code — the
0x2c78 / 0xe7a4 / 0x3c20 / 0xe9a0 cases. INFERRED: those census "case targets"
are mis-read table entries, not handlers.)

---

## Step 2 — locating the control-message switch function in each build

Table boundaries were verified by reading the words after the `mov pc, Rn` site
(OBSERVED):

| build | site | table | entries | first word after table |
|---|---|---|---|---|
| 3.1.8 (ref) | 0xa9d6 | 0xa9d8 | 14 | — |
| 3.1.12 | 0xaa2a | 0xaa2c | 14 (spans 0xaa2c–0xaa63) | `0xd0002c01` at 0xaa64 (non-pointer) |
| 3.2.0 A | 0x4b92 | 0x4b94 | 8 | — |
| 3.2.0 B | 0x4ee2 | 0x4ee4 | 15 (0x4ee4–0x4f1f) | `0x200002a8` at 0x4f20 (SRAM pointer) |
| 3.2.0 C | 0x5166 | 0x5168 | 13 (0x5168–0x519b) | `0x2e03461f` at 0x519c (Thumb code) |

Enclosing function entries, found the same way 0xa9bc was found (prologue
candidate from `bl_xref.py` immediately before the case table, confirmed by
disassembly):

* **3.1.12 → 0xaa10** (OBSERVED): `push {r4,r5,r6,r7,lr}; sub sp,#0x1c;
  mov r5,r2; mov r4,r0; mov r0,r1; subs r0,#9; cmp r0,#0xd; bhi 0xaa70;
  lsls r0,#2; adr r1,4 (→0xaa2c); ldr r0,[r1,r0]; mov pc,r0`.
  Guard = message types **9–22**, 14 cases. Exactly the 3.1.8 shape
  (`subs r0,#9 / cmp r0,#0xd`).
* **3.2.0 → 0x4b78** (OBSERVED, contains table B 0x4ee4): `push {r4-r7,lr};
  sub sp,#0x34; mov r6,r0; subs r0,r1,#2; cmp r0,#7; bls; adr r1,8 (→0x4b94)…`
  Guard = **2–9**, 8 cases (table A at 0x4b94 is a *different*, nested switch in
  the same body).
* **3.2.0 → 0x50fc** (OBSERVED, contains table C 0x5168): `push {r4-r7,lr};
  sub sp,#0x34; … subs r0,r1,#2; cmp r0,#0xc; bls; adr r1,4 (→0x5168);
  ldr r0,[r1,r0]; mov pc,r0`. Guard = **2–14**, 13 cases.
* **3.2.0 → 0x4eca** (OBSERVED via supplementary seed): no prologue and no BL
  caller; reached only indirectly. Body starts `ldr r0,[r0]; ldrb r0,[r0,#1];
  subs r1,r0,#3; cmp r1,#0xe; bls 0x4eda; b 0x50c8; lsls r1,#2; adr r2,4
  (→0x4ee4); mov pc,r2`. Guard = field value **3–17**, 15 cases (table B).

Verified clear seeds (`',clear,1,data'`), each backed by a listing that shows a
1-byte data unit on a decodable prologue (`xversion/dump_*_fail.txt`):

* 3.1.12: **0xaa10** (`f0 b5`)
* 3.2.0: **0x4b78**, **0x50fc** (both `f0 b5`)

Seed files (`xversion/build_seeds3.py`, REPRODUCED):

* `seeds3_3112.csv` — 98 entries: 1 clear + 97 census seeds (10 dropped).
* `seeds3_320.csv` — 84 entries: 2 clears + 82 census seeds (13 dropped).

Dropped in 3.2.0 beyond the table above: `0x4b92`, `0x4ee2`, `0x5166`,
`0x5034`, `0x5076`, `0x50ae`, `0x50d0`. Reason (OBSERVED): these are switch
sites / case bodies *inside* the verified bodies 0x4b78 and 0x50fc; seeding them
as function entries carved the 0x4b78 body down to 26 bytes and produced 6
1-token fragments. This is the same class of artifact the 3.1.8 baseline carries
at 0xa9d6 (`FUN_0000a9d6`, 2 B), which was left untouched for comparability.

---

## Step 3 — seeded re-analysis (fresh project per build)

`SeedCortexM.java`, coverage = bytes inside function bodies / image bytes.

| build | old (generic v7) | seeded Cortex-M | Δ functions | seeded coverage |
|---|---|---|---|---|
| 3.1.8  (reference rerun) | 300 / 38.8 % | **444** / 46.4 % | +144 | 38,760 / 83,464 |
| 3.1.12 | 303 / 39.4 % | **436** / 45.2 % | +133 | 37,748 / 83,592 |
| 3.2.0  | 296 / 43.3 % | **423** / 56.2 % | +127 | 47,208 / 84,048 |

The 3.1.8 rerun reproduces the checked-in `inventory3_318.json` exactly
(444 functions, 38,760 bytes) — the pipeline is REPRODUCED. Largest bodies:
3.1.8 0xd904 (2,014 B), 3.1.12 0xd984 (2,014 B), 3.2.0 0xfbc8 (2,932 B).

Coverage of the previously-unreached dispatchers (OBSERVED):

* 3.1.12: 0xaa2a and the table at 0xaa2c are now inside `FUN_0000aa10` (552 B).
* 3.2.0: table 0x5168 is inside `FUN_000050fc` (222 B); table 0x4ee4 is **not**
  inside any body of the primary inventory — Ghidra's CFG from 0x4b78 stops at
  0x4bda, so the 0x4eca block is only reachable as an extra seed. A
  supplementary run (`inventory3_320_disp15.json`, `decomp3_320_disp15/`) seeds
  0x4eca and yields `FUN_00004eca` (74 B) containing `switchD_00004ee2`.
  Function count is unchanged at 423 there (0x4eca absorbs 0x4ee2/0x4f0x).

Artifacts to keep in mind (OBSERVED): 39 functions ≤ 6 B in each 3.1.x inventory
(21 of them ≤ 2 B) — mostly case bodies seeded as separate entries, the same as
the 3.1.8 baseline; 30 in 3.2.0.

---

## Step 4 — first-order cross-version match

Signature = (body size in bytes, operand-free mnemonic sequence), with
`bl→call`, `b→ubr`, `b<cond>/cbz/cbnz→cbr`. Mnemonics were dumped from the
analysed projects (`xversion/MnemSeqs.java` → `mnems_{318,3112,320}.json`);
matching in `xversion/match.py` → `match_result.json` (REPRODUCED).

| pair | shared signatures | functions matched | share of smaller build |
|---|---|---|---|
| 3.1.8 → 3.1.12 | 379 | 430 / 428 | **98.2 %** of 3.1.12 |
| 3.1.12 → 3.2.0 | 183 | 224 / 211 | **49.9 %** of 3.2.0 |
| 3.1.8 → 3.2.0  | 182 | 225 / 210 | 49.6 % of 3.2.0 |

* **Present in all three inventories**: 182 distinct signatures, covering
  225 / 223 / 213 functions (3.1.8 / 3.1.12 / 3.2.0). Largest exact triple: 234 B
  (0x718c / 0x718c / 0x7304).
* **Size-changed pairs** (same normalized mnemonic sequence, different body
  size): **2** for 3.1.8→3.1.12 and **1** for 3.1.12→3.2.0 — all trivial
  2-token bodies (0x3d38/0x4418 6↔4 B; 0x4418/0x5034 4↔6 B). No non-trivial
  function changes size without changing its mnemonic sequence.
* **3.2.0 functions with no 3.1.12 counterpart**: **215** by strict signature.
  With a looser tier (|Δsize| ≤ 16 and token-sequence similarity ≥ 0.85,
  greedy one-to-one) **235** pairs are found, median similarity 1.0, leaving
  **195** with no counterpart. Largest unmatched: 0xfbc8 (2,932 B), 0x12250
  (2,220 B), 0xdb40 (2,016 B), 0xf5b8 (1,954 B), 0x21a0 (1,234 B).
* The 3.2.0 switches themselves match nothing in 3.1.12: 0x4b78 (98 B) and
  0x50fc (222 B) have no signature twin, and 0x4b78 / 0x50fc carry no exact
  (size, sequence) match in 3.1.12 at all.

**Known artifact risk (OBSERVED, do not over-read the counts).** Identical
bodies are common: 28 distinct sequences are duplicated in each 3.1.x build,
80 / 78 functions sit in duplicated sequences, max multiplicity **14**; 3.2.0
has 19 duplicated sequences, 54 functions, max multiplicity 10. Matching is
therefore many-to-many: a signature "present in all three" may correspond to 14
different functions per build. The counts above are function-level and cannot be
read as one-to-one correspondences; helper/twin bodies inflate them, and a
relocated helper may match a different call site's helper. Tier-2 pairing
removes that by construction but is greedy, not optimal.

---

## Step 5 — dispatcher comparison: 3.1.8 0xa9bc vs 0xaa10 vs 3.2.0

### 3.1.8 `FUN_0000a9bc` vs 3.1.12 `FUN_0000aa10` (OBSERVED)

Both decompile to the same 3-parameter shape
`(undefined **param_1, int param_2, undefined **param_3)`, both with

```
if (param_2 - 9U < 0xe) {
    switch (param_2) { case 9 .. case 22 ... default: ... }
```

* same guard, same 14-entry table, same 23 case labels, same case grouping
  (9; 10 and 0x12 share a target; 0xc tail-calls `FUN_00006854`; 0x13 empty;
  0x16 tests a function pointer).
* Callee multisets are identical in count and order, with every address shifted
  by a constant: `0xa450→0xa4a4`, `0xa500→0xa554`, `0xae90→0xaee4`,
  `0xaed0→0xaf24`, `0xaf08→0xaf5c`, `0xb73c→0xb790` (**+0x54** each);
  table `0xa9d8→0xaa2c` (+0x54); handler `0xd904→0xd984` (**+0x80**, because
  the largest function grew by 0x2c earlier in the image).
* Table contents (OBSERVED, same 6-unique / dominant pattern):
  `09→af24  0A→aee4  0B→b1a8  0C→af5c  0D→b1a8  0E→b1a8  0F→b1a8  10→b1a8
   11→b1a8  12→aee4  13→afa4  14→b1a8  15→b1a8  16→afc6`, vs 3.1.8's
  `09→aed0 0A→ae90 0B→b154 0C→af08 … 12→ae90 13→af50 16→af72`.

**OBSERVED:** the control-message dispatcher is structurally unchanged from
3.1.8 to 3.1.12 — same guard, same 14-case span 9–22, same handler sharing,
addresses shifted by +0x54.
**INFERRED:** 3.1.12 is a small delta on 3.1.8 in this region, not a rewrite.
**OPEN:** whether any handler body changed internally (not inspected here).

### 3.2.0 (OBSERVED)

No 14-case 9–22 table exists in 3.2.0. Three switches exist instead:

| function | guard | span | cases | switch data |
|---|---|---|---|---|
| `FUN_00004b78` | `param_2 - 2U < 8` | 2–9 | 8 | `switchdataD_00004b94` |
| `FUN_000050fc` | `uVar5 = param_2 - 2; if (0xc < uVar5) return;` then `switch(param_2)` | 2–14 | 13 | `PTR_FUN_00005168` / `switchdataD_00005168` |
| `FUN_00004eca` | `*(byte*)(*param_1+1) - 3 <= 0xe` | 3–17 | 15 | `switchdataD_00004ee4` |

* `FUN_00004b78(uint param_1, int param_2, undefined4 param_3, int param_4)` —
  4 parameters (3.1.x dispatcher has 3), body 98 B, cases 2/6/8/9 plus a
  `default:` that tail-calls `FUN_00005b5c(DAT_00004f28, switchdata[param_2-2], DAT_00004f24)`.
  Callees: 0x3258, 0x5b5c, 0x6328, 0x7260 — none shared with the 3.1.x
  dispatcher's callee set.
* `FUN_000050fc(code *param_1, int param_2)` — 2 parameters, first one is a
  *code pointer*, not a struct pointer; 222 B. Reads fields through
  `DAT_0000547c + param_1*0xf0` and `DAT_00005480 + param_1*0x1cc` (two
  strided per-instance arrays), then `switch(param_2)` over 2–14 with
  22 case labels including nested switches (`switch(puVar13)`, `switch(pcVar6 + 0x56aa)`).
  Callees include 0x301a, 0x30f0, 0x3258, 0x51xx-family `FUN_000056da/56ee/5704/5752/576a`,
  0x5b5c, 0x5c68, 0x5c8c, 0x6ec8, 0x7260, 0x7272, 0xca08.
* `FUN_00004eca(int *param_1, …)` — reads the message type from
  `*(byte*)(*param_1 + 1)`, i.e. from a structure field, not from `param_2`.
  Cases 6, 0x10, 0x11 visible plus a `default:` that falls into
  `switchD_00004ee2_caseD_5`; callees 0x3140, 0x3258, 0x5b5c, 0x6328, 0x7260,
  0xb9dc, 0xca08.

**OBSERVED differences (3.1.12 → 3.2.0)** — structural, not semantic:
1. The single 9–22 / 14-case dispatcher at 0xaa10 is gone; 3.2.0 has three
   switches with spans 2–9, 2–14 and 3–17, in three different functions.
2. The message index is taken from a `param_2` (3.1.x) vs from an argument
   (0x4b78, 0x50fc) vs from `*(byte*)(*param_1+1)` (0x4eca) — different sources.
3. Call convention changed: 3.1.x dispatcher takes `(struct**, int, struct**)`;
   0x4b78 takes 4 args; 0x50fc takes `(code*, int)`.
4. Callee sets are disjoint except for 0x3258 / 0x5b5c / 0x6328 / 0x7260, which
   do not appear in the 3.1.x dispatcher body.
5. The dominant-case structure changed: 3.1.x has 8/14 cases mapping to one
   handler (0xb154 / 0xb1a8); 3.2.0's largest switch (15 cases) is dominated by
   `0x554a` (census: 6/15) and 0x5168 by `0x5704`.

**Semantic interpretations — separate, labelled:**
* **INFERRED (not observed):** 3.2.0 likely split one control-message switch
  into per-class handlers (transport/state vs message-type dispatch), or changed
  the message-type numbering so 9–22 became 2–14 / 3–17. Neither is established.
* **OPEN:** whether the 15-case (0x4ee4) or 13-case (0x5168) table is the
  successor of the 9–22 table. The guards do not line up (3–17 field read vs
  9–22 argument), and no case-target set is shared.
* **REFUTED:** "3.2.0 has no control-message switch" (DIFF §4's detector found
  none) — three switch tables with case bodies are present at 0x4b94, 0x4ee4
  and 0x5168. **REFUTED:** "the dispatcher is unchanged" — the 9–22 table is
  absent and the shape/call convention differ.

---

## Commands (reproducible)

```
python3 scripts/ghidra/bl_xref.py firmware/images/A2363_3.1.12_10M1543_base0.bin xversion/bl_xref_3112.json
python3 scripts/ghidra/bl_xref.py firmware/images/A2363_3.2.0_10M13722_base0.bin  xversion/bl_xref_320.json
python3 xversion/gen_seeds.py          # census -> seeds_*.csv, verified identical
python3 xversion/build_seeds3.py       # -> seeds3_3112.csv / seeds3_320.csv

analyzeHeadless /tmp/ghproj_X X -import <img> -processor ARM:LE:32:Cortex -cspec default \
  -scriptPath scripts/ghidra -postScript DiagSeeds.java xversion/seeds_<v>.csv xversion/diag_<v>.txt
analyzeHeadless /tmp/ghproj_S X -import <img> ... -postScript SeedCortexM.java \
  xversion/seeds3_<v>.csv xversion/inventory3_<v>.json xversion/decomp3_<v>
analyzeHeadless /tmp/ghproj_S X -process <img> -noanalysis -scriptPath xversion \
  -postScript MnemSeqs.java xversion/mnems_<v>.json
python3 xversion/match.py xversion/match_result.json
```
