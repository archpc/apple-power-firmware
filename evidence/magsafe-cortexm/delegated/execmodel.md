# Delegated: Cortex-M execution model for A2363 3.1.8

Image: `firmware/images/A2363_3.1.8_10M569_base0.bin`, 83,464 bytes, imported base 0.
All addresses are FILE OFFSETS. Runtime addresses are never asserted.

Tooling: Ghidra 12.1.4 PUBLIC headless (`-processor ARM:LE:32:Cortex -cspec default`),
rizin 0.9.1 (`-a arm -b 16`). Ghidra projects live outside the repo at
`/Users/sein/gp_execmodel` (a project path containing `.hermes` is rejected:
`Path element starting with '.' is not permitted`); scripts run from
`/Users/sein/gp_execmodel/scripts` and are copied verbatim into this directory.

---

## 1. Clean-import smoke test — PASS

Command (fresh project `execmodel318_1`, no prior state, `-noanalysis`):

```
analyzeHeadless /Users/sein/gp_execmodel execmodel318_1 \
  -import firmware/images/A2363_3.1.8_10M569_base0.bin \
  -processor ARM:LE:32:Cortex -cspec default \
  -scriptPath scripts/ghidra -postScript SmokeOffset10.java <out>/smoke_318_clean.txt
```

Output (`smoke_318_clean.txt`, byte-identical to the earlier `smoke_318.txt`):

```
language=ARM:LE:32:Cortex
bytes@0x10=f0b585b072b64148
instr=push {r4,r5,r6,r7,lr}
nextAddr=0x12
```

- **OBSERVED**: loader log line `Using Language/Compiler: ARM:LE:32:Cortex:default`;
  the program's own `getLanguageID()` is `ARM:LE:32:Cortex` and compiler spec `default`.
- **REPRODUCED**: bytes at 0x10 are `f0 b5 85 b0 72 b6 41 48` and decode as the 32-bit
  Thumb-2 `push {r4,r5,r6,r7,lr}` (4 bytes, next address 0x12). The `push.w` encoding
  plus the following `sub sp,#0x14` / `cpsid i` / `ldr r0,[pc,#...]` is a normal
  Cortex-M reset-handler prologue shape.
- **OBSERVED**: memory block is exactly 0x0..0x14607 (83,464 bytes), image base 0 —
  the flat image maps 1:1 onto file offsets for the whole extent.

## 2. Vector header at offset 0 and the reset target — PASS

**OBSERVED** first 16 bytes (`header_318.txt`, cross-checked with a plain
`struct.unpack_from` read of the file):

| offset | word | interpretation |
|---|---|---|
| 0x00 | 0x20002000 | initial SP — inside SRAM (0x2000_0000 region) |
| 0x04 | 0x00010f7d | reset, Thumb bit set → target 0x10f7c |
| 0x08 | 0x00010fa1 | NMI, Thumb bit set → target 0x10fa0 |
| 0x0c | 0x00010fa1 | HardFault, Thumb bit set → target 0x10fa0 |

- **OBSERVED**: word[0] is a plausible SRAM stack top (0x20002000); the three exception
  words all carry bit0=1, i.e. Thumb-state code pointers — vector-table shape.
- **OBSERVED (Ghidra)**: the Raw Binary loader materialised 0x04/0x08/0x0c as `addr`
  pointer data units. `functionContaining(0x10f7c)` = NONE, `dataAt(0x10f7c)` = NONE,
  no function is created at the target after `disassemble()`.
- **OBSERVED (table)**: 0x10f7c is word 10 of a 23-word little-endian pointer/constant
  run spanning 0x10f54..0x10fac:

```
0x10f54 0x0000ffe0   0x10f80 0x200018d0  (SRAM)
0x10f58 0x0000ffff   0x10f84 0x4003003c  (APB)
0x10f5c 0x200019a4   0x10f88 0x00001129  (code ptr, Thumb)
0x10f60 0x20001940   0x10f8c 0xe000e408  (PPB)
0x10f64 0x200017f8   0x10f90 0xe000e100  (PPB, NVIC ISER)
0x10f68 0xe000e010   0x10f94 0x0000bb80  (48000, SysTick reload shape)
0x10f6c 0xe000ed1c   0x10f98 0x20001278  (SRAM)
0x10f70 0x2000002c   0x10f9c 0x40050000  (APB)
0x10f74 0x00000f71   0x10fa0 0x40050204  (APB)
0x10f78 0x00000f51   0x10fa4 0x40050304  (APB)
0x10f7c 0x20000190   0x10fa8 0x40050f00  (APB)
                    0x10fac 0x40050f80  (APB)
```

- **OBSERVED**: decoding at the reset target is nonsense in both decoders.
  Ghidra: `lsls r0,r2,#0x6` at 0x10f7c. rizin: `lsls r0,r2,6 / movs r0,0 / adds r0,r2,r3 /
  movs r0,0 / movs r4,r7 / ands r3,r0 ...` — a run of 1-word data-ish decodes with no
  control flow, no `push`/`sub sp`, no `bl`. Same at 0x10fa0 (`lsls r4,r0,8 / ands r5,r0 ...`).
- **OBSERVED**: rizin `aa; afl~10f` finds no function at either address.
- **INFERRED**: the reset/NMI/HardFault words point at a descriptor/init table (masks
  0xffe0/0xffff, SRAM buffers, SysTick/NVIC/APB register bases), not at handlers. That the
  vector header is filled with table offsets rather than handler addresses is consistent with
  a bootloader-relocated (SRAM) vector table; the mechanism remains a hypothesis.

**Answer to "is 0x10 the only statically identifiable entry?"** — **INFERRED yes** for
statically identifiable *boot* entries: the 4-word header is the only structure that names a
code state, and 0x10 is the only address it can plausibly supply that decodes as a handler
prologue (0x10f7c / 0x10fa0 are table data by the evidence above). `0x10` stays
**CANDIDATE** — nothing in the image proves it is the reset handler, only that it is the
one offset with Thumb prologue shape adjacent to the header. Caveat (**OBSERVED**): the
descriptor table itself contains three low-bit-set code pointers (0x00000f71 → 0xf70,
0x00000f51 → 0xf50, 0x00001129 → 0x1128), so the table does supply *call targets*. 0xf70
decodes as `pop {r4,r5,r7,pc}` (mid-function epilogue, not an entry); 0xf50 and 0x1128 are
interior/loop addresses (`cmp r2,0; beq ...`, `subs r4,r0,1; cmp; beq`). None is a prologue,
so they do not add statically identifiable entries either.


## 3. The ten `disasm=FAILED` seeds, classified independently — PASS

Method: read the raw halfwords at each seed and at seed-2, then decode with
`rizin -a arm -b 16 -e scr.color=0 -c 's <addr>; pd N'` from the aligned instruction
start. A seed is "forced to code" only if it is an instruction boundary; a seed that
lands between the two halfwords of a 32-bit Thumb instruction, or inside a literal
pool, must not become a function.

| seed | halfword at seed | what it actually is (decoded) | verdict |
|---|---|---|---|
| 0x10 | 0xb5f0 (`push.w` 1st half) | genuine `push {r4,r5,r6,r7,lr}`; FAILED only because the Raw Binary loader had a 4-byte `addr` unit at 0x10..0x13 with value 0xb085b5f0 | **code — clear+disassemble correct** |
| 0x2c6a | 0xffff | upper half of the literal `0xfffffc00` at 0x2c68; rizin: `invalid` at 0x2c68 | data (literal pool) |
| 0x2c78 | 0xffff | dword 0xfebfffff, next two words 0x200002b0 (SRAM ptr) then code at 0x2c80 `push {r7,lr}` | data (literal pool) |
| 0x3b72 | 0xfb16 | second half of `bl 0x31a0` that starts at 0x3b70 (`f7ff fb16`) | interior of a 32-bit BL |
| 0x3dca | 0xf9ea | second half of `bl 0x31a0` at 0x3dc8 | interior of a 32-bit BL |
| 0x59c4 | 0xfa0f | second half of `bl 0x6de4` at 0x59c2 | interior of a 32-bit BL |
| 0x5a72 | 0xfb96 | second half of `bl 0x31a0` at 0x5a70, inside FUN_00005a38 | interior of a 32-bit BL |
| 0x9adc | 0xf91b | second half of `bl 0x9d14` at 0x9ada | interior of a 32-bit BL |
| 0x9ae8 | 0xff1f | second half of `bl 0x9928` at 0x9ae6 | interior of a 32-bit BL |
| 0xe724 | 0xf278 | literal blob 0x0ffff278 / 0x03010800 / 0x000139a8 / ASCII `"AlCl"`; rizin `invalid` | data (literal/string blob) |

**Answer**: 9 of 10 are unresolved-or-misaligned and must not be forced — they are the
second halfword of a `BL` (6×), or a word inside a literal pool (3×). The tenth (0x10) is
real code and was handled correctly, but *not* by forcing: `seeds3_318.csv` carries
`0x10,clear,4,data`, and the script only clears when the existing unit starts at the seed,
is 4 bytes long and is typed `data` — the log proves it fired once
(`clear before: 0x10 addr b085b5f0` → `clear after: push {r4,r5,r6,r7,lr}`). So no seed was
blind-forced; the one code seed went through a type- and length-gated clear. **OBSERVED.**

## 4. Inventory reproducibility from a clean project — PASS

Command (fresh project `execmodel318_seed`, no prior database, same seeds file as the
original run):

```
analyzeHeadless /Users/sein/gp_execmodel execmodel318_seed \
  -import firmware/images/A2363_3.1.8_10M569_base0.bin \
  -processor ARM:LE:32:Cortex -cspec default \
  -scriptPath scripts/ghidra -postScript SeedCortexM.java \
  evidence/magsafe-cortexm/seeds3_318.csv <out>/inventory_rerun_318.json /Users/sein/gp_execmodel/decomp_rerun
```

Comparison with `inventory3_318.json`:

- `diff` of the two JSON files → **byte-identical** (`IDENTICAL_FILES`).
- JSON key sets equal: 444 / 444 functions, 0 only-in-A, 0 only-in-B.
- 0 size or name differences; total body bytes 38,760 on both sides.
- All `seed ...` log lines identical; 2 `clear` log lines identical.

**REPRODUCED**: the seeded pipeline is deterministic on a clean import. The documented
0x10 body-length instability (4 vs 8 bytes) did **not** manifest this run — both sides
record `{"addr":"0x10","size":4,"name":"MemManage"}`. No *other* difference was found.

Derived number worth carrying: seeded coverage is 38,760 / 83,464 = **46.44 %** of image
bytes (vs 38.8 % for the unseeded 300-function run), with 15 overlapping body entries and a
highest body end of 0x14466.

## 5. Coverage gap bound — PASS

Uncovered = all bytes in 0..0x14608 outside every function body: **44,930 bytes (53.83 %)** in
**341 ranges**. Each range was classified by `delegated/execmodel/gapclass.py` (copy of the
script that produced `gapclass318.json`):

1. prologue candidates from `bl_xref_318.json` (`push {...,lr}`);
2. for each candidate, decode up to 64 instructions with rizin and require a coherent body
   — a return (`pop {...,pc}`, `bx lr`) or an unconditional `b` before any `invalid`;
3. printable-ASCII runs ≥ 8 and pointer-word density as data signals.

Aggregate: **50 ranges / 22,716 bytes contain at least one coherent `push {...,lr}` body →
plausible undiscovered code**; 290 ranges / 17,782 bytes show no code signal; 1 range /
4,432 bytes is string data.

Largest ranges:

| range | len | verdict | decoded evidence |
|---|---|---|---|
| 0x10abc..0x129f0 | 7,988 | **code + embedded data** | 4 prologues, `0x10ac0 push {r4,r5,r6,lr}`, `0x10b30 push {r4,r5,r6,r7,lr}; sub sp,#0xdc` (500+ coherent instructions, no `invalid` until 0x10f50), `0x12938`, `0x129c8 push {r4,r5,r7,lr}` → `pop {r4,r5,r7,pc}` at 0x129d2. 5 BL targets inside (0x10b30, 0x12012, 0x1291c, 0x1297c, 0x12988); 0x12012/0x1291c/0x1297c are interior (`ldr r5,[sp,0x6c]`, `movs r0,0xd; bl 0x967c`), so they are branch targets, not entries. Embedded data: an `"NVM0"`-tagged descriptor at 0x10f4c — 0x10f4c=0x304d564e (`"NVM0"`), then masks/pointers 0x0003ffff, 0x0000ffe0, 0x0000ffff, SRAM 0x200019a4/0x20001940/0x200017f8, 0xe000e010 (SysTick), 0xe000ed1c, 0x4003003c, 0xe000e408, 0xe000e100, SysTick reload 0x0000bb80, APB 0x40050000/0x40050204/0x40050304/0x40050f00/0x40050f80. Code resumes at ~0x10fc0 (`bl 0xb60`, `cpsid i`, RMW of 0x40070304). |
| 0x12bf4..0x13d44 | 4,432 | **data (strings)** | 50 ASCII runs ≥ 8: `"Machine stack fault exception:"`, `"Unsupported: '%c'"`, `"0123456789ABCDEF"`, `"0123456789abcdef"`, `"0123456789abcdef"` and neighbours. 9 prologue-shaped byte pairs are all *false positives inside string data* — none survives coherence (first candidate 0x1304e decodes `push {r0,r2,r7,lr}` then `invalid` at 0x13050, `udf 2` at 0x13064). 41.7 % of bytes are 0x00 (padding). One ~256-byte high-entropy patch at ~0x130b4 (H≈7.2, max in the range) sits between the strings; its nature is OPEN. |
| 0xfd20..0x107d6 | 2,742 | **code (continuation)** | no prologue, but the function that Ghidra ends at 0xfd20 continues: `0xfd20 ldr r1,[sp,0x68]; cmp r0,0; beq; bl 0x107d6` — a coherent stream that only makes sense as the body of FUN_0000fc4c and its callees. 4 BL targets inside (0xfd5a, 0x10016, 0x1056c, 0x10768) all interior (`ldrb r1,[r3,r5]`, `movs r0,0x40`, `ldr r0,[sp,0x54]`, `ldr r1,[0x10a68]`). Reads as function bodies truncated by the analysis, not data. |
| 0xf3fa..0xf9e6 | 1,516 | data (no code signal) | 0 prologues, 0 BL targets, no ASCII runs; sits between `thunk_FUN_0000f9e6`@0xf3f8 and `FUN_0000f9e6`@0xf9e6 — consistent with a literal pool for the thunk (`ldr pc, [pc, #-4]`-style). |
| 0xe1fc..0xe756 | 1,370 | data (no code signal) | 0 prologues, 0 BL targets, 16.5 % zero bytes, bounded by `switchD`@0xe1fa and `caseD_f`@0xe756 — jump-table residue. |
| 0x7276..0x7754 | 1,246 | **code** | 6 prologues, all coherent: `0x728c push {r3,r4,r5,r6,r7,lr}`, `0x7360 push {r7,lr}; movs r2,3; bl 0x7904; pop {r7,pc}`, `0x736a`, `0x7374`, `0x73e4 push {r3,...,lr}`, `0x74a4 push {r4,...,lr}; sub sp,#0x1c`. 0 BL targets → reached only by pointer/fallthrough. |
| 0x4a68..0x4f08 | 1,184 | data (no code signal) | 0 prologues, 0 BL targets, sits between `FUN_00004a66` (ends `mov pc,r0` dispatch) and `FUN_00004f08`. |
| 0x44a6..0x4908 | 1,122 | **code** | 8 prologues, all coherent (`0x4528`, `0x4560`, `0x45dc`, `0x4644`, `0x470a`, `0x4730`, `0x4828`, `0x4890`), each ending in `pop {...,pc}` within 32 instructions. |
| 0xa130..0xa424 | 756 | **code** | 4 coherent prologues (0xa140, 0xa15c, 0xa1e0, 0xa250) + 2 BL targets. |
| 0x33ca..0x36ac | 738 | **code** | 7 coherent prologues (0x33dc, 0x341c, 0x34c8, 0x3520, ...). |

**Bound stated plainly**: the 53.83 % raw uncovered figure overstates the code gap. Of it,
**at least 22,716 bytes (27.2 % of the image) lie in ranges that contain a decodable
`push {...,lr}` body**, and 44,930 − 22,716 − 4,432 = **17,782 bytes carry no code signal**
(literal pools, jump-table residue, zero padding). The single biggest hole,
0x10abc..0x129f0 (7,988 bytes), is genuinely a code island: 0x10ac0 and 0x12938/0x129c8 have no
caller at all in the BL map, and the one in-island call into 0x10b30 comes from 0x10b02, itself
inside the gap — so the island is only self-referential plus
the `"NVM0"` configuration descriptor. That island is the largest concrete target for
further analysis; it is **OPEN** whether it is a bootloader/NVM routine block or application
code, and no semantic claim is made here.
