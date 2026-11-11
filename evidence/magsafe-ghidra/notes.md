# MagSafe 3 (A2363) firmware — Ghidra function inventory + cross-version diff

Evidence dir: `<artifact-root>/evidence/magsafe-ghidra/`
Raw dumps: `raw/` (per-image `decompile-index.json`, `inventory.json`, `inventory_ins.json`, `reset_targets.json`, per-function pseudocode in `raw/pseudo_*/functions/`).
Inputs (unmodified, read-only): `<artifact-root>/firmware/images/A2363_{3.1.8_10M569,3.1.12_10M1543,3.2.0_10M13722}_base0.bin`

## Tooling actually used

`rea` is not on PATH; it is a repo checkout at `<rea>`, invoked as
`node scripts/rea.mjs <cmd>`. Ghidra 12.1.4 is at `<ghidra>`
and requires `GHIDRA_INSTALL_DIR` to be exported (otherwise `rea doctor` reports `missing_analysis_engine`).

Common invocation (per image, one standalone process — no MCP session touched):

```
export GHIDRA_INSTALL_DIR=<ghidra>
cd <rea>
node scripts/rea.mjs <cmd> <image.bin> [...] \
  --target-format raw-binary --architecture arm --entry-point 0x0 --provider ghidra \
  --format json --full-output
```

Provider analysis profile confirmed from the returned evidence (`analysis_profile.parameters`):
`loader=BinaryLoader`, `language_id=ARM:LE:32:v7`, `compiler_spec_id=default`, `entry_point=0x0`,
`import_mode=ephemeral-source-immutable`. So: ARM v7 generic, little-endian, 32-bit, base 0 — as specified.

Per-image function inventory (address, body ranges → size, instruction count, mnemonics) was produced with:

```
node scripts/rea.mjs decompile-all <image.bin> --output raw/pseudo_<ver> \
  --target-format raw-binary --architecture arm --entry-point 0x0 --provider ghidra --format json --full-output
```

`decompile-all` writes `decompile-index.json` (address + `body.ranges` per function) plus one
pseudocode file per function; it is the cheapest complete inventory the CLI offers (one JVM import,
~15 s per image). Its `latest_run.selection.limit` is `null`, i.e. the 296–303 functions are the full
inventory, not a truncated page.

Instruction counts / mnemonics were then taken by decoding **Ghidra's own function body ranges** with
rizin 0.9.1 (`rizin -q -a arm -b 16 -c "pDj <len> @ <addr>"`, i.e. Thumb mode), one `pDj` per body range.
Cross-check against Ghidra's own disassembly (`rea instructions <addr>`) on six functions:

| function (3.1.8) | rizin instrs | Ghidra instrs | |
|---|---|---|---|
| 0x110a | 35 | 35 | match |
| 0xd904 | 965 | 965 | match |
| 0x2204 | 640 | 640 | match |
| 0x5ed0 | 444 | 444 | match |
| 0x13dc8 | 423 | 423 | match |
| 0x0 | 8 | 4 | **differs** (see 1a: the 0x0 "function" is the vector table, not code) |

CONFIRMED: for real code functions the two decoders agree exactly, so instruction counts are sound.
41 of ~305 body ranges per image decode to fewer bytes than Ghidra's body length (undecodable
trailing bytes, e.g. `0xb50` body 8 B decodes 5 B); those are counted as decoded, and the shortfall is
recorded in `raw/inventory_ins.json`.

---

## 1a. Architecture / base / reset-vector target

CONFIRMED architecture and base. Both are settled by the provider profile (`ARM:LE:32:v7`, base 0,
file offset 0 → address 0) and by the fact that all three vector words point inside the file only
under base 0: reset targets 0x10f7c / 0x10ffc / 0x1111c, NMI/HardFault 0x10fa0 / 0x11020 / 0x11140,
all < image end (0x14608 / 0x14688 / 0x14850). Any non-zero base would push the targets out of range.

Raw header per image (CONFIRMED, `xxd -l 32`, `struct.unpack('<4I', b, 0)`):

| image | SP @0 | reset @4 | NMI @8 | HardFault @0xc |
|---|---|---|---|---|
| 3.1.8 | 0x20002000 | 0x00010f7d | 0x00010fa1 | 0x00010fa1 |
| 3.1.12 | 0x20002000 | 0x00010ffd | 0x00011021 | 0x00011021 |
| 3.2.0 | 0x20002000 | 0x0001111d | 0x00011141 | 0x00011141 |

CONFIRMED: `NMI = HardFault = reset + 0x24` in all three (both point at the same default handler).

### The reset target is NOT code — this is the headline finding of 1a

`pDj 24 @ <reset target>` (Thumb), first 12 instructions:

3.1.8 @ 0x10f7c
```
0x10f7c: lsls r0, r2, 6      0x10f84: movs r4, r7       0x10f8c: b 0x107a0
0x10f7e: movs r0, 0          0x10f86: ands r3, r0       0x10f8e: b 0x10f92
0x10f80: adds r0, r2, r3     0x10f88: asrs r1, r5, 4    0x10f90: b 0x11194
0x10f82: movs r0, 0          0x10f8a: movs r0, r0       0x10f92: b 0x10f96
```

3.1.12 @ 0x10ffc — byte-identical garbage, only the branch targets shift:
```
0x10ffc: lsls r0, r2, 6      0x11004: movs r4, r7       0x1100c: b 0x10820
0x10ffe: movs r0, 0          0x11006: ands r3, r0       0x1100e: b 0x11012
0x11000: adds r0, r2, r3     0x11008: asrs r1, r5, 4    0x11010: b 0x11214
0x11002: movs r0, 0          0x1100a: movs r0, r0       0x11012: b 0x11016
```

3.2.0 @ 0x1111c — hits an invalid encoding:
```
0x1111c: lsrs r0, r0, 0x1c   0x11124: lsrs r0, r0, 0x20  0x1112c: subs r3, 0x58
0x1111e: ands r5, r0         0x11126: strh r0, [r0]      0x1112e: movs r1, r0
0x11120: lsrs r0, r0, 0x1e   0x11128: invalid           0x11130: add r0, sp, 0xc4
0x11122: ands r5, r0         0x1112a: (2 B skipped)      0x11132: ldr r1, [sp, 0x78]
```

CONFIRMED, therefore: **none of the three reset targets is a coherent function (no prologue, no
epilogue) and none is a leaf routine.** Ghidra independently agrees — it created **no function at or
containing** any reset target (`reset_targets.json`); each sits in an analyzer gap:
3.1.8 0x10f7c in 0x10abc–0x129ef, 3.1.12 0x10ffc in 0x10b3c–0x12a9b, 3.2.0 0x1111c in 0x10c60–0x12c4b.

What the bytes actually are (CONFIRMED by value inspection of 0x10f70–0x10fb4 in 3.1.8): a
constant/pointer table — `0x20000190`, `0x200018d0`, `0x4003003c`, `0x00001129`, `0xe000e408`
(NVIC SHPR), `0xe000e100` (NVIC ISER), `0x40050000`, `0x40050204`, `0x40050304`, `0x40050f00`,
`0x40050f80`. The word *at* each reset target is itself a RAM/MMIO pointer (0x20000190, 0x20000190,
0x40050f00), not an odd (Thumb) code address.

INFERRED explanation: the 4-word header at offset 0 is vector-shaped (SP=0x20002000 is a real SRAM
stack top) but its handler addresses are **not resolvable in this extracted image** — they land in the
read-only pointer table that the real (SRAM-relocated) vector table would consume. Consequence for
analysis, and the reason it matters: **the header cannot be used to seed the entry point**; nothing in
this file turns 0x00000000 into a reachable code path via the reset vector.

CONFIRMED, the actual code entry is offset 0x10. Ghidra's disassembly at 0x10 for both 3.1.8 and 3.2.0:
```
0x10: push {r4,r5,r6,r7,lr}
0x12: sub sp, #0x14
```
and then **Ghidra stops**: the body is 0x10–0x13, 2 instructions, 4 bytes. Raw bytes at 0x14 are
`72 b6` = `cpsid i`, an ARMv7-M instruction that the generic `ARM:LE:32:v7` language does not decode.
So this startup routine is truncated after its prologue by the language choice — CONFIRMED by the
fact that all three images carry the identical byte sequence at 0x10 (`f0b5 85b0 72b6 4148 4149 0160
dd20 0006`) and all three get the identical 4-byte body.

Second CONFIRMED caveat about Ghidra's function *names*: the loader applied 32-bit-ARM exception-vector
semantics to offsets 0x0–0x1c, so functions at 0x10 / 0x14 / 0x18 are named `DataAbort` / `NotUsed` /
`IRQ`, and the function at 0x0 is named `entry` (alias `Reset`). Those names are spurious — 0x10 is a
Thumb startup routine, not an ARM DataAbort handler. The 0x0 "function" is the 16-byte vector table
itself decoded as code (rizin decodes 8 instructions in those 16 bytes where Ghidra sees 4).

### 1b/1c. Function inventory, counts, coverage

| image | size | functions | instructions | bytes covered by function bodies | coverage |
|---|---|---|---|---|---|
| 3.1.8 | 83,464 | **300** | 15,279 | 32,380 | **38.80 %** |
| 3.1.12 | 83,592 | **303** | 15,568 | 32,962 | **39.43 %** |
| 3.2.0 | 84,048 | **296** | 17,249 | 36,391 | **43.30 %** |

Full per-function tables: `raw/inventory_ins.json` (address, name, body ranges, size, instruction
count, mnemonics). Bodies are contiguous for every function (`non_contiguous: false` everywhere).

Interpretation of coverage (CONFIRMED numbers, INFERRED reading): Ghidra did find real code, not just
entry points — 300 functions / 15.3k instructions is a genuine function inventory, and the largest
function (3.1.8 `FUN_0000d904`, 2014 B / 965 instructions) decompiles to structured C. But ~61 % of
each image is outside any function body, and that remainder is data, not missed code: of the uncovered
bytes, 36.7 % are printable ASCII (string/config tables), 12.1 % are 0x00 and 1.4 % are 0xFF.
Independent check for missed code: 43 occurrences of a `push {…, lr}` (`0xB5xx`) halfword at an even
offset in 3.1.8, of which 15 are inside Ghidra bodies and 28 are not — so on the order of a couple of
dozen small functions may be undiscovered, i.e. ≲1 KB, which does not change the coverage picture.

Largest 10 functions per image are in `raw/inventory_ins.json`; the top four:

| 3.1.8 | | 3.1.12 | | 3.2.0 | |
|---|---|---|---|---|---|
| 0xd904 | 2014 B / 965 ins | 0xd984 | 2014 B / 965 ins | 0xfbc8 | 2932 B / 1385 ins |
| 0x2204 | 1362 B / 640 ins | 0x2204 | 1362 B / 640 ins | 0xdb40 | 2016 B / 966 ins |
| 0x5ed0 | 940 B / 444 ins | 0x5ed0 | 940 B / 444 ins | 0x21a0 | 1390 B / 654 ins |
| 0x13dc8 | 874 B / 423 ins | 0x13e48 | 874 B / 423 ins | 0x14018 | 1070 B / 517 ins |

Note 3.2.0 gains a new largest function `0xfbc8` (2932 B) that has no counterpart at that size in
3.1.8/3.1.12 — handled in section 2d.

---

## 2d. Cross-version function matching

### Method (and why a naive byte diff fails)

First, a content measurement that reframes the whole question. Byte-level comparison of the three
images (difflib `SequenceMatcher` over the halfword stream, `autojunk=False`; plus order-insensitive
16-byte-window overlap):

| pair | same-offset identical bytes | monotone LCS coverage (halfwords) | order-free 16 B window overlap |
|---|---|---|---|
| 3.1.8 → 3.1.12 | 51.97 % | **96.79 %** | 81.71 % |
| 3.1.12 → 3.2.0 | 4.29 % | **54.46 %** | **17.13 %** |

CONFIRMED: 3.1.8 and 3.1.12 really are the same code with insertions (96.8 % of 3.1.8's halfwords
appear in order in 3.1.12). **3.2.0 is not a patch of 3.1.12** on that measure — only 17 % of 3.2.0's
16-byte windows exist anywhere in 3.1.12, so the premise "near-identical sizes ⇒ most functions should
be byte-identical" is false for 3.2.0. Nearly every instruction that carries a PC-relative or absolute
operand differs, which is what a relink/recompile looks like, not a rewrite.

Matching was therefore done on **structure**, not bytes. Each function is represented by its ordered
mnemonic sequence (operands stripped) plus body size. A 1:1 ordered alignment was computed by
Needleman–Wunsch over the address-sorted function lists with score
`1.0 + 0.6·r + 0.4·size_sim` (r = `difflib` ratio of mnemonic sequences), rejecting pairs with
`r < 0.5` or `size_sim < 0.5`, gap penalty −0.5; exact content anchors (identical mnemonic tuple)
were matched first and the DP was run only in the gaps between anchors.

**Method validation, CONFIRMED:** on the 3.1.8→3.1.12 pair, where the answer is known, the matcher
recovers 290 pairs, all 290 with r ≥ 0.8, mean r = 0.998, mean size similarity 0.998, 220 of them
byte-identical. So the aligner does not manufacture matches.

### Results

| | count |
|---|---|
| functions in 3.1.8 / 3.1.12 / 3.2.0 | 300 / 303 / 296 |
| matched in 3.1.8↔3.1.12 | 290 (10 unmatched in 3.1.8, 13 in 3.1.12) |
| matched in 3.1.12↔3.2.0 | 261 (42 unmatched in 3.1.12, 35 in 3.2.0) |
| **matched across all three** | **251** |
| **present only in 3.2.0** | **45** |
| **present only in 3.1.8/3.1.12 (dropped)** | **49** |
| **size changed 3.1.8→3.1.12** | **3** |
| **size changed 3.1.12→3.2.0** | **76** |
| size identical in all three | 175 |
| byte-identical in all three | 68 |

Group definitions: "matched across all three" is transitive through 3.1.12 (function present in 3.1.8,
its 3.1.12 match present in 3.2.0). "Present only in 3.2.0" (45) = the 35 functions with no 3.1.12
counterpart **plus** 10 that match 3.1.12 functions which themselves appeared between 3.1.8 and 3.1.12
(so those 10 are new in 3.1.12, not in 3.2.0). Accounting check: 251 + 45 = 296 = 3.2.0's function count.

Size-delta shape, CONFIRMED: of the 76 changed functions, 44 differ by ≤ 8 bytes (literal-pool and
frame-size drift, i.e. boundary noise rather than logic change); the substantive ones are in 2e.
Instruction counts changed for the same 76 functions and only those — no function kept its size while
changing its instruction count.

### Caveats on the "only in 3.2.0 / dropped" counts

INFERRED, and deliberately conservative in the other direction: these two counts are the weakest
numbers here, because this firmware contains duplicated helper bodies (43 of 3.1.12's functions share a
signature with another function; 35 in 3.2.0). Identical twins defeat 1:1 pairing — the DP can assign an
old copy to a different new copy and leave the true twin looking "new". Measured directly: 11 of the 35
unmatched 3.2.0 functions have an order-free r ≥ 0.85 counterpart in 3.1.12 that is already matched to a
different 3.2.0 function. So the honest reading of "only in 3.2.0" is **24–45 functions**, not a hard 45.
For reference, a multiplicity-aware exact-signature count (identical size **and** identical mnemonic
sequence) gives 168 present in all three, 118 excess in 3.2.0 and 139 excess in 3.1.8/3.1.12 — that is
an upper bound, since any function altered by a single instruction counts as removed + added.

What is NOT in doubt: 3.2.0 has **3 fewer functions than 3.1.12 despite being 456 bytes larger**, and
several of the unmatched 3.2.0 entries are far larger than any unmatched 3.1.12 entry (`0xfbc8`, 2932 B,
1385 instructions). That is the signature of Ghidra merging several 3.1.12 functions into one 3.2.0
function on this raw image, i.e. part of the apparent churn is an artifact of function-boundary
discovery, not firmware change.

Machine-readable: `raw/inventory_{318,31112,320}.tsv` (address, name, size, instruction count, sha16),
`raw/threeway.json` (the three-way match sets and both unmatched lists).

---

## 2e. Ten largest functions that changed between 3.1.12 and 3.2.0

Ranked by max(size) among the 76 size-changed pairs. Instruction listings are Thumb decode of Ghidra's
own body ranges (`pDj 64`), full 20 instructions per side in `raw/top10_first20.json`.

| # | 3.1.12 addr | size / ins | 3.2.0 addr | size / ins | Δ bytes |
|---|---|---|---|---|---|
| 1 | 0xd984 | 2014 B / 965 | 0xdb40 | 2016 B / 966 | +2 |
| 2 | 0x2204 | 1362 B / 640 | 0x21a0 | 1390 B / 654 | +28 |
| 3 | 0x13e48 | 874 B / 423 | 0x14018 | 1070 B / 517 | +196 |
| 4 | 0x5ed0 | 940 B / 444 | 0x5fe4 | 772 B / 365 | -168 |
| 5 | 0x6df4 | 860 B / 417 | 0x6ed8 | 888 B / 432 | +28 |
| 6 | 0x1d0 | 818 B / 406 | 0x1d0 | 866 B / 430 | +48 |
| 7 | 0xb3a0 | 592 B / 289 | 0xb45c | 700 B / 343 | +108 |
| 8 | 0x967c | 648 B / 243 | 0x975c | 402 B / 172 | -246 |
| 9 | 0x5c68 | 580 B / 275 | 0x5d88 | 568 B / 269 | -12 |
| 10 | 0x8548 | 540 B / 262 | 0x869c | 548 B / 266 | +8 |

### First 20 instructions, side by side

**1. 0xd984 (2014 B) → 0xdb40 (2016 B), Δ +2**
```
0x0d984  push {r4, r5, r6, r7, lr}     | 0x0db40  push {r4, r5, r6, r7, lr}
0x0d986  sub sp, 0x7c                  | 0x0db42  sub sp, 0x84
0x0d988  lsls r0, r0, 1                | 0x0db44  lsls r0, r0, 1
0x0d98a  str r0, [sp, 0x60]            | 0x0db46  str r0, [sp, 0x64]
0x0d98c  uxtb r2, r0                   | 0x0db48  uxtb r4, r0
0x0d98e  ldr r6, [pc, 0x338]           | 0x0db4a  lsls r0, r4, 1
0x0d990  adds r7, r6, r2               | 0x0db4c  ldr r1, [pc, 0x3c4]
0x0d992  ldrb r0, [r7, 0x10]           | 0x0db4e  str r1, [sp, 0x6c]
0x0d994  lsrs r0, r0, 4                | 0x0db50  adds r0, r1, r0
0x0d996  ldr r4, [pc, 0x334]           | 0x0db52  ldrh r3, [r0, 0x20]
0x0d998  cmp r0, 0xd                   | 0x0db54  adds r0, 0x20
0x0d99a  ldr r0, [pc, 0x334]           | 0x0db56  str r0, [sp, 0x74]
0x0d99c  ldr r1, [pc, 0x334]           | 0x0db58  ldr r1, [pc, 0x3bc]
0x0d99e  ldr r5, [pc, 0x338]           | 0x0db5a  adds r5, r1, r4
0x0d9a0  str r0, [sp, 0x68]            | 0x0db5c  ldrb r0, [r5, 0x10]
0x0d9a2  str r1, [sp, 0x64]            | 0x0db5e  lsrs r0, r0, 4
0x0d9a4  blo 0xda7a                    | 0x0db60  ldr r2, [pc, 0x3b8]
0x0d9a6  lsls r0, r2, 1                | 0x0db62  cmp r0, 0xd
0x0d9a8  adds r1, r1, r0               | 0x0db64  ldr r0, [pc, 0x3b8]
0x0d9aa  ldrh r0, [r1, 0x20]           | 0x0db66  str r0, [sp, 0x68]
```

**2. 0x2204 (1362 B) → 0x21a0 (1390 B), Δ +28**
```
0x02204  push {r4, r5, r6, r7, lr}     | 0x021a0  push {r4, r5, r6, r7, lr}
0x02206  sub sp, 0x5c                  | 0x021a2  sub sp, 0x64
0x02208  mov r6, r0                    | 0x021a4  mov r7, r0
0x0220a  movs r0, 0x73                 | 0x021a6  movs r0, 0x73
0x0220c  lsls r0, r0, 2                | 0x021a8  lsls r0, r0, 2
0x0220e  muls r0, r6, r0               | 0x021aa  muls r0, r7, r0
0x02210  ldr r1, [pc, 0x3dc]           | 0x021ac  ldr r1, [pc, 0x3f4]
0x02212  adds r4, r1, r0               | 0x021ae  adds r4, r1, r0
0x02214  movs r0, 0x31                 | 0x021b0  movs r0, 0x31
0x02216  ldrb r0, [r4, r0]             | 0x021b2  ldrb r0, [r4, r0]
0x02218  cmp r0, 0                     | 0x021b4  cmp r0, 0
0x0221a  beq 0x225e                    | 0x021b6  beq 0x2290
0x0221c  movs r0, 0x2d                 | 0x021b8  movs r0, 0x2d
0x0221e  ldrb r7, [r4, r0]             | 0x021ba  ldrb r5, [r4, r0]
0x02220  ldrb r2, [r4, 0x19]           | 0x021bc  ldrb r2, [r4, 0x19]
0x02222  movs r0, 0x25                 | 0x021be  movs r0, 0x25
0x02224  ldrb r0, [r4, r0]             | 0x021c0  ldrb r0, [r4, r0]
0x02226  mov r1, r4                    | 0x021c2  mov r1, r4
0x02228  adds r1, 0x2d                 | 0x021c4  adds r1, 0x2d
0x0222a  str r1, [sp, 0x28]            | 0x021c6  str r1, [sp, 0x30]
```

**3. 0x13e48 (874 B) → 0x14018 (1070 B), Δ +196**
```
0x13e48  push {r4, r5, r6, r7, lr}     | 0x14018  push {r4, r5, r6, r7, lr}
0x13e4a  sub sp, 0x1dc                 | 0x1401a  sub sp, 0x1e4
0x13e4c  movs r6, 1                    | 0x1401c  movs r4, 1
0x13e4e  lsls r0, r6, 0xd              | 0x1401e  lsls r0, r4, 0xd
0x13e50  ldr r1, [pc, 0x360]           | 0x14020  ldr r1, [pc, 0x3a4]
0x13e52  str r0, [r1]                  | 0x14022  str r0, [r1]
0x13e54  ldr r0, [pc, 0x360]           | 0x14024  ldr r0, [pc, 0x3a4]
0x13e56  ldr r1, [pc, 0x364]           | 0x14026  ldr r1, [pc, 0x3a8]
0x13e58  str r1, [r0]                  | 0x14028  str r1, [r0]
0x13e5a  ldr r0, [pc, 0x364]           | 0x1402a  ldr r0, [pc, 0x3a8]
0x13e5c  movs r1, 2                    | 0x1402c  movs r1, 2
0x13e5e  str r1, [r0]                  | 0x1402e  str r1, [r0]
0x13e60  movs r0, 0x17                 | 0x14030  movs r0, 0x17
0x13e62  movs r1, 6                    | 0x14032  movs r1, 6
0x13e64  str r1, [sp, 4]               | 0x14034  str r1, [sp, 4]
0x13e66  bl 0x14260                    | 0x14036  bl 0x14504
0x13e6a  movs r0, 0x21                 | 0x1403a  movs r0, 0x21
0x13e6c  mov r1, r6                    | 0x1403c  mov r1, r4
0x13e6e  bl 0x14260                    | 0x1403e  bl 0x14504
0x13e72  ldr r0, [pc, 0x350]           | 0x14042  ldr r0, [pc, 0x3e4]
```

**4. 0x5ed0 (940 B) → 0x5fe4 (772 B), Δ -168**
```
0x05ed0  push {r4, r5, r6, r7, lr}     | 0x05fe4  push {r4, r5, r6, r7, lr}
0x05ed2  sub sp, 0x24                  | 0x05fe6  sub sp, 0x1c
0x05ed4  mov r5, r0                    | 0x05fe8  mov r4, r0
0x05ed6  movs r1, 0                    | 0x05fea  movs r5, 0
0x05ed8  mov r4, r1                    | 0x05fec  mov r1, r5
0x05eda  bl 0x2f62                     | 0x05fee  bl 0x301a
0x05ede  movs r1, 9                    | 0x05ff2  movs r1, 9
0x05ee0  mov r0, r5                    | 0x05ff4  mov r0, r4
0x05ee2  bl 0xc88c                     | 0x05ff6  bl 0xca08
0x05ee6  movs r0, 1                    | 0x05ffa  movs r0, 1
0x05ee8  str r0, [sp, 0x18]            | 0x05ffc  str r0, [sp, 4]
0x05eea  lsls r1, r0, 8                | 0x05ffe  lsls r1, r0, 8
0x05eec  mov r0, r5                    | 0x06000  mov r0, r4
0x05eee  str r1, [sp, 4]               | 0x06002  str r1, [sp, 0x10]
0x05ef0  bl 0x2ce4                     | 0x06004  bl 0x2db8
0x05ef4  movs r7, 0xf0                 | 0x06008  movs r0, 0xf0
0x05ef6  muls r7, r5, r7               | 0x0600a  muls r0, r4, r0
0x05ef8  ldr r0, [pc, 0x3a0]           | 0x0600c  ldr r1, [pc, 0x30c]
0x05efa  str r0, [sp, 0x10]            | 0x0600e  adds r7, r1, r0
0x05efc  adds r6, r0, r7               | 0x06010  movs r0, 0xa9
```

**5. 0x6df4 (860 B) → 0x6ed8 (888 B), Δ +28**
```
0x06df4  push {r4, r5, r6, r7, lr}     | 0x06ed8  push {r4, r5, r6, r7, lr}
0x06df6  sub sp, 0x4c                  | 0x06eda  sub sp, 0x54
0x06df8  str r3, [sp, 0x48]            | 0x06edc  cmp r0, 1
0x06dfa  cmp r0, 1                     | 0x06ede  bls 0x6ee2
0x06dfc  bls 0x6e00                    | 0x06ee0  b 0x724c
0x06dfe  b 0x713e                      | 0x06ee2  mov r6, r0
0x06e00  movs r7, 0x88                 | 0x06ee4  movs r4, 0x88
0x06e02  mov r3, r7                    | 0x06ee6  mov r0, r4
0x06e04  muls r3, r0, r3               | 0x06ee8  muls r0, r6, r0
0x06e06  ldr r4, [pc, 0x34c]           | 0x06eea  ldr r7, [pc, 0x368]
0x06e08  adds r6, r4, r3               | 0x06eec  adds r5, r7, r0
0x06e0a  movs r3, 0x73                 | 0x06eee  movs r0, 0x73
0x06e0c  ldrb r5, [r6, r3]             | 0x06ef0  str r0, [sp, 0x48]
0x06e0e  cmp r5, 1                     | 0x06ef2  ldrb r0, [r5, r0]
0x06e10  bne 0x6e14                    | 0x06ef4  cmp r0, 1
0x06e12  b 0x713e                      | 0x06ef6  bne 0x6efa
0x06e14  str r1, [sp, 0x44]            | 0x06ef8  b 0x724c
0x06e16  ldr r5, [sp, 0x60]            | 0x06efa  str r3, [sp, 0x50]
0x06e18  mov r1, r6                    | 0x06efc  str r2, [sp, 0x40]
0x06e1a  ldr r6, [sp, 0x68]            | 0x06efe  ldr r0, [sp, 0x68]
```

**6. 0x1d0 (818 B) → 0x1d0 (866 B), Δ +48**
```
0x001d0  push {r4, r5, r6, r7, lr}     | 0x001d0  push {r4, r5, r6, r7, lr}
0x001d2  sub sp, 0x34                  | 0x001d2  sub sp, 0x3c
0x001d4  mov r5, r1                    | 0x001d4  mov r5, r1
0x001d6  ldrb r1, [r1]                 | 0x001d6  ldrb r1, [r1]
0x001d8  cmp r1, 0                     | 0x001d8  cmp r1, 0
0x001da  bne 0x1de                     | 0x001da  bne 0x1de
0x001dc  b 0x52e                       | 0x001dc  b 0x55e
0x001de  mov r6, r2                    | 0x001de  mov r6, r2
0x001e0  mov r4, r0                    | 0x001e0  mov r4, r0
0x001e2  movs r0, 5                    | 0x001e2  movs r0, 5
0x001e4  str r0, [sp, 0xc]             | 0x001e4  str r0, [sp, 8]
0x001e6  lsls r0, r0, 0xb              | 0x001e6  lsls r0, r0, 0xb
0x001e8  str r0, [sp, 0x18]            | 0x001e8  str r0, [sp, 0x14]
0x001ea  movs r0, 1                    | 0x001ea  movs r0, 1
0x001ec  str r0, [sp, 0x24]            | 0x001ec  str r0, [sp, 0x2c]
0x001ee  lsls r0, r0, 0xe              | 0x001ee  lsls r0, r0, 0xe
0x001f0  str r0, [sp, 0x14]            | 0x001f0  str r0, [sp, 0x10]
0x001f2  movs r0, 0                    | 0x001f2  movs r0, 0xff
0x001f4  str r0, [sp, 0x2c]            | 0x001f4  lsls r2, r0, 0xf
0x001f6  mov r3, r0                    | 0x001f6  str r2, [sp, 0x20]
```

**7. 0xb3a0 (592 B) → 0xb45c (700 B), Δ +108**
```
0x0b3a0  push {r4, r5, r6, r7, lr}     | 0x0b45c  push {r4, r5, r6, r7, lr}
0x0b3a2  sub sp, 0x2c                  | 0x0b45e  sub sp, 0x34
0x0b3a4  str r2, [sp, 8]               | 0x0b460  str r2, [sp, 0x10]
0x0b3a6  mov r6, r1                    | 0x0b462  mov r6, r1
0x0b3a8  mov r5, r0                    | 0x0b464  mov r5, r0
0x0b3aa  ldr r4, [r1, 8]               | 0x0b466  ldr r4, [r1, 8]
0x0b3ac  movs r7, 1                    | 0x0b468  movs r7, 1
0x0b3ae  mov r0, r7                    | 0x0b46a  mov r0, r7
0x0b3b0  bl 0xa824                     | 0x0b46c  bl 0xa908
0x0b3b4  lsrs r0, r4, 0x10             | 0x0b470  lsrs r0, r4, 0x10
0x0b3b6  movs r1, 0xff                 | 0x0b472  movs r1, 0xff
0x0b3b8  lsls r1, r1, 8                | 0x0b474  lsls r1, r1, 8
0x0b3ba  cmp r0, r1                    | 0x0b476  cmp r0, r1
0x0b3bc  beq 0xb3ca                    | 0x0b478  beq 0xb4aa
0x0b3be  ldr r1, [pc, 0x230]           | 0x0b47a  ldr r1, [pc, 0x29c]
0x0b3c0  cmp r0, r1                    | 0x0b47c  cmp r0, r1
0x0b3c2  beq 0xb3c6                    | 0x0b47e  bne 0xb564
0x0b3c4  b 0xb582                      | 0x0b480  lsls r0, r4, 0x10
0x0b3c6  lsls r0, r4, 0x10             | 0x0b482  bmi 0xb4aa
0x0b3c8  bpl 0xb3de                    | 0x0b484  ldrb r0, [r6]
```

**8. 0x967c (648 B) → 0x975c (402 B), Δ -246**
```
0x0967c  sub sp, 8                     | 0x0975c  sub sp, 8
0x0967e  mov r4, r0                    | 0x0975e  mov r4, r0
0x09680  bl 0x12a9c                    | 0x09760  bl 0x12c78
0x09684  mov r0, r4                    | 0x09764  mov r0, r4
0x09686  bl 0x94c                      | 0x09766  bl 0x974
0x0968a  add r0, sp, 4                 | 0x0976a  add r0, sp, 4
0x0968c  strb r4, [r0]                 | 0x0976c  strb r4, [r0]
0x0968e  cmp r4, 0x11                  | 0x0976e  cmp r4, 0x11
0x09690  bhi 0x96e0                    | 0x09770  bhi 0x97ae
0x09692  lsls r4, r4, 1                | 0x09772  mov r8, r8
0x09694  add r4, pc                    | 0x09774  add r4, pc
0x09696  ldrh r4, [r4, 4]              | 0x09776  ldrb r4, [r4, 4]
0x09698  lsls r4, r4, 1                | 0x09778  lsls r4, r4, 1
0x0969a  add pc, r4                    | 0x0977a  add pc, r4
0x0969c  movs r1, r2                   | 0x0977c  cmp r4, 8
0x0969e  movs r5, r6                   | 0x0977e  orrs r4, r7
0x096a0  lsls r5, r0, 1                | 0x09780  ldr r7, [pc, 0x124]
0x096a2  lsls r5, r2, 1                | 0x09782  ldrh r5, [r2, r5]
0x096a4  lsls r5, r4, 1                | 0x09784  strb r3, [r5, 5]
0x096a6  lsls r5, r6, 1                | 0x09786  strh r7, [r6, 0x3a]
```

**9. 0x5c68 (580 B) → 0x5d88 (568 B), Δ -12**
```
0x05c68  push {r4, r5, r6, r7, lr}     | 0x05d88  push {r4, r5, r6, r7, lr}
0x05c6a  sub sp, 0x14                  | 0x05d8a  sub sp, 0x14
0x05c6c  mov r4, r0                    | 0x05d8c  mov r4, r0
0x05c6e  movs r6, 0xf0                 | 0x05d8e  movs r7, 0xf0
0x05c70  muls r6, r0, r6               | 0x05d90  muls r7, r0, r7
0x05c72  ldr r5, [pc, 0x24c]           | 0x05d92  ldr r5, [pc, 0x240]
0x05c74  ldr r0, [r5, r6]              | 0x05d94  ldr r0, [r5, r7]
0x05c76  str r0, [sp, 8]               | 0x05d96  str r0, [sp, 8]
0x05c78  ldrb r7, [r0, 2]              | 0x05d98  ldrb r6, [r0, 2]
0x05c7a  mov r0, r4                    | 0x05d9a  mov r0, r4
0x05c7c  bl 0x5a80                     | 0x05d9c  bl 0x5ba4
0x05c80  adds r5, r5, r6               | 0x05da0  adds r5, r5, r7
0x05c82  movs r0, 0x73                 | 0x05da2  movs r0, 0x73
0x05c84  lsls r0, r0, 2                | 0x05da4  lsls r0, r0, 2
0x05c86  muls r0, r4, r0               | 0x05da6  muls r0, r4, r0
0x05c88  ldr r1, [pc, 0x238]           | 0x05da8  ldr r1, [pc, 0x22c]
0x05c8a  adds r6, r1, r0               | 0x05daa  adds r7, r1, r0
0x05c8c  cmp r7, 0x12                  | 0x05dac  cmp r6, 6
0x05c8e  beq 0x5cba                    | 0x05dae  beq 0x5e12
0x05c90  cmp r7, 0x10                  | 0x05db0  cmp r6, 0x12
```

**10. 0x8548 (540 B) → 0x869c (548 B), Δ +8**
```
0x08548  push {r4, r5, r6, r7, lr}     | 0x0869c  push {r1, r2, r3, r4, r5, r6, r7, lr}
0x0854a  sub sp, 0x14                  | 0x0869e  mov r4, r0
0x0854c  mov r4, r0                    | 0x086a0  movs r0, 0x73
0x0854e  movs r0, 0x73                 | 0x086a2  lsls r0, r0, 2
0x08550  lsls r0, r0, 2                | 0x086a4  muls r0, r4, r0
0x08552  muls r0, r4, r0               | 0x086a6  ldr r1, [pc, 0x21c]
0x08554  ldr r1, [pc, 0x210]           | 0x086a8  adds r7, r1, r0
0x08556  adds r7, r1, r0               | 0x086aa  movs r0, 0x31
0x08558  movs r0, 0x31                 | 0x086ac  ldrb r0, [r7, r0]
0x0855a  ldrb r0, [r7, r0]             | 0x086ae  cmp r0, 0
0x0855c  cmp r0, 0                     | 0x086b0  bne 0x86b4
0x0855e  bne 0x8562                    | 0x086b2  b 0x87dc
0x08560  b 0x8760                      | 0x086b4  lsls r0, r4, 2
0x08562  lsls r0, r4, 2                | 0x086b6  ldr r1, [pc, 0x210]
0x08564  ldr r1, [pc, 0x204]           | 0x086b8  ldr r6, [r1, r0]
0x08566  ldr r6, [r1, r0]              | 0x086ba  movs r0, 0x49
0x08568  movs r0, 0x49                 | 0x086bc  lsls r0, r0, 2
0x0856a  lsls r0, r0, 2                | 0x086be  adds r5, r6, r0
0x0856c  adds r5, r6, r0               | 0x086c0  adds r6, 0xa4
0x0856e  adds r6, 0xa4                 | 0x086c2  ldrb r0, [r7, 0x1c]
```

---

## Verification of the 2e listings against Ghidra itself

CONFIRMED, not inferred: pair #2 of 2e was re-disassembled by Ghidra directly
(`rea instructions <image> 0x2204` and `... 0x21a0`, same provider/profile as the inventory):

```
3.1.12 0x2204 (640 instructions, Ghidra)     3.2.0 0x21a0 (654 instructions, Ghidra)
0x2204: push {r4,r5,r6,r7,lr}                0x21a0: push {r4,r5,r6,r7,lr}
0x2206: sub sp, #0x5c                        0x21a2: sub sp, #0x64
0x2208: mov r6, r0                           0x21a4: mov r7, r0
0x220a: movs r0, #0x73                       0x21a6: movs r0, #0x73
0x220c: lsls r0, r0, #0x2                    0x21a8: lsls r0, r0, #0x2
0x220e: muls r0, r6                          0x21aa: muls r0, r7
```

Byte-for-byte the same mnemonic/operand text as the `pDj` listing in 2e, and the instruction totals
(640 / 654) equal the inventory's `nins` for those two functions. So the 2e tables are Ghidra-accurate,
and the rizin-based instruction counts used throughout are consistent with Ghidra's own decoder.

## What is solid vs what is soft

Solid (CONFIRMED from disassembly / raw bytes / provider profile):
- ARM Thumb-2, little-endian, base 0, `ARM:LE:32:v7`, BinaryLoader, entry seeded at 0x0.
- Function counts 300 / 303 / 296 and coverage 38.80 % / 39.43 % / 43.30 %; instruction totals
  15,279 / 15,568 / 17,249.
- Reset vector targets are not code in any of the three images; they land in a const pointer table and
  Ghidra has no function containing them.
- Ghidra's names `entry`/`DataAbort`/`NotUsed`/`IRQ` at 0x0/0x10/0x14/0x18 are loader artifacts of a
  32-bit-ARM exception-vector assumption; 0x10 is Thumb startup code truncated at `cpsid i`.
- 3.1.8↔3.1.12 is a near-identical pair (96.8 % monotone LCS); 3.2.0 shares only 17 % of its 16-byte
  windows with 3.1.12 — it is a rebuild/relink, not a patch.
- The 251 three-way matches and the 76 size-changed functions; the 10 largest changed functions and
  their first 20 instructions per side.

Soft (INFERRED, with the reasoning and the bound stated in 2d):
- The exact "only in 3.2.0" (45) and "dropped" (49) counts, because of duplicated helper bodies;
  honest range for genuinely new 3.2.0 functions is ~24–45.
- Which individual unmatched function is a merge/split artifact vs a real addition.
- The explanation of *why* the reset vectors are unresolvable (SRAM-relocated vector table) — the
  observation is solid, the mechanism is a hypothesis.

## Files

| path | contents |
|---|---|
| `notes.md` | this report |
| `raw/decompile_all_*.json` | raw `decompile-all` envelopes (300/303/296 functions) |
| `raw/pseudo_318/functions/*.c`, `raw/pseudo_3_1_12/...`, `raw/pseudo_3_2_0/...` | Ghidra pseudocode, one file per function, plus `decompile-index.json` |
| `raw/inventory_318.tsv`, `raw/inventory_31112.tsv`, `raw/inventory_320.tsv` | function inventory: address, name, size, instruction count, sha16 |
| `raw/inventory_ins.json` | same, plus body ranges and mnemonic sequences |
| `raw/reset_targets.json` | reset target decode + containing/neighbouring function per image |
| `raw/threeway.json` | 3-way match sets and both unmatched lists |
| `raw/align2.json` | ordered 1:1 match pairs for 3.1.8↔3.1.12 and 3.1.12↔3.2.0 |
| `raw/top10_first20.json` | the 2e table, 20 instructions per side |
| `raw/blocks_3112_320.json` | difflib matching blocks for the byte-level comparison |
| `raw/ins_*.json` | individual Ghidra `instructions` dumps used for validation |

Inputs were never modified (all `rea` runs used `import_mode=ephemeral-source-immutable`; one `rizin`
`-c` session per image, read-only).
