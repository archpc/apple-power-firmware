# Liveness of the statically-unreachable islands — static analysis only

Scope: `firmware/images/A2363_3.1.8_10M569_base0.bin` (83,464 B). All addresses are
**FILE OFFSETS** (base-0 import). No firmware bytes were modified; no commit made.
Inputs read: `delegated/execmodel.md`, `DIFF.md` §11. Tools: Python on the raw image,
rizin 0.9.1 (`-a arm -b 16 -e scr.color=0`), and the **existing** decompilation corpus
`evidence/magsafe-cortexm/decomp3_318/` + `inventory3_318.json` + `bl_xref_318.json`.

**Tooling caveat (OBSERVED)**: Ghidra 12.1.4 is not present on this machine any more
(`analyzeHeadless` / `ghidraRun` not found anywhere on disk; only
`~/Library/ghidra/ghidra_12.1.4_PUBLIC/` user-settings remains). The Ghidra project
`/Users/sein/gp_execmodel/execmodel318_seed.gpr` still exists but cannot be opened
without the install, so task 2 was done from the **already-produced** decompiled C and
inventory rather than from a live database, with every load-bearing site re-verified by
rizin decode of the raw bytes. Reachability class used below: a function is "reachable"
if its entry appears in `bl_xref_318.json:bl_targets` (341 entries) or is `0x10`.

---

## L1. Delta / offset-table scan (task 1) — **REFUTED** for base+relative relocation

Script: `delegated/liveness/delta_scan.py`, output `delegated/liveness/delta_scan.json`.

Method. Build a map of every 32-bit little-endian word at every 2-byte offset (41,731
distinct words). Two independent tests per target `E`:

* **Test A (offset-table test, low false-positive by construction)** — find words
  `W1@p1`, `W2@p2` with `W1 - W2 == E` and both operands inside the image extent and
  `|p1-p2| <= 0x400` (i.e. co-located, one record). This is exactly the signature of an
  image-relative addend table (base stored once, `base+delta` stored beside it).
* **Test B (anchored base+delta)** — `W == E - X` where `X` is a *legitimate* anchor
  (one of the 444 function starts, a BL/B.W target from the xref maps, or an island
  block start) and `0 < W <= 0x14608`. A hit only counts if the anchor `X` itself is
  stored as a word within the same 0x400 window.

Targets: `0xa9bc`, `0xa9d8` (dispatcher + its table), `0xaed0`, `0xaf08`, `0xaf80`,
`0x10ac0`, `0x10b30`, `0x10fc0`, `0x1128`, `0x12012`, `0x12938`, `0x129c8`.

Negative-control methodology note (**OBSERVED**): a first, deliberately loose pass
(code set = every byte of every Ghidra function body; no co-location filter) returned
12,596 "hits" per target — e.g. word `0x13088`@0x544 interpreted as `0xa9bc - 0x86cc`.
Inspecting them showed pure arithmetic coincidence, so that formulation was discarded
before drawing any conclusion; the numbers reported below are the filtered ones.

Result (**OBSERVED**):

| target | Test A co-located pairs | Test B anchored hits | anchored hits whose base is also stored nearby |
|---|---|---|---|
| 0xa9bc | 0 | 43 | 0 |
| 0xa9d8 | 0 | 30 | 1 (`0x3a28=0x68ad` vs base `0x412c` — unrelated pair) |
| 0x10ac0 | 0 | 28 | 0 |
| 0x10b30 | 0 | 30 | 0 |
| 0x10fc0 | 0 | 21 | 0 |
| 0x1128 | 1 (trivial, see below) | 14 | 0 |
| 0x12012 | 0 | 18 | 0 |
| 0x12938 | 0 | 30 | 0 |
| 0x129c8 | 0 | 21 | 0 |

The single Test-A hit for `0x1128` is `0x10f88 = 0x00001129` against words of value
`0x1` — i.e. the already-known plain pointer in the `"NVM0"` descriptor block, not a
delta pair. **Conclusion: no image-relative offset table, no `base+delta` literal pool,
and no `base`-minus-`delta` word anywhere in the image refers to any island entry.**
The base+delta hypothesis is **REFUTED** as far as a word-based table can express it
(it cannot exclude a delta that is computed at runtime from a struct field, which no
static scan can see — that residue stays **OPEN**, see L4).

Control (**OBSERVED**): the only words in the whole image that point into the descriptor
block `0x10f4c..0x10fb8` are the three vector words `0x4=0x10f7d`, `0x8=0x10fa1`,
`0xc=0x10fa1`, plus one literal-pool word at `0x12978=0x10fa1` inside the large island.

---

## L2. Struct-field callback / function-pointer traffic (task 2)

### L2a. Stores to `+0x60` (all 13 in the image, by halfword pattern `STR r,[r,#0x60]`)

| site | containing function | reachable? | stored value / what it really is |
|---|---|---|---|
| `0x1d00` | `0x1cf0` | **yes** | `ldr r1,[0x1f30]` → `0x13a2c`; **installs an in-image table pointer** into `port_obj+0x60`, `port_obj = 0x200002b0 + n*0x1cc`. The same function (see L2c) also builds a real **code-pointer** table in SRAM |
| `0x6d30`,`0x6d38` | `0x6d00` | **yes** | `r1 = *(0x13898 + port*4) + 0xe4`; value is a register field RMW (`orrs r6,#0x80100000`) — **not** a code pointer |
| `0xae68` | island block (`0xae5c`) | no | `str r5,[r4,0x60]` = **clears** the field after a guarded `blx` |
| `0xaf76` | island block `0xaf54` | no | `str r1,[r4,0x60]`, `r4 = 0x20001854`, `r1` = caller-supplied 2nd arg (a `code *`) — **callback install** |
| `0xaf86` | island block `0xaf54` | no | `str r1,[0x20001854+0x60]` — same install on the other branch |
| `0xafd4` | island | no | guarded clear |
| `0xb720` | island | no | guarded clear |
| `0xe654` | outside inventory | no | not verified as code |
| `0x10e3c` | large island | no | `r1 = 0x40050000` (APB base) → `str r0,[r1,0x60]` is an **MMIO register write**, not a struct store |
| `0x12c64`,`0x12e58`,`0x12ee0` | string region | no | **false positives**: decode at `0x12c50` gives `ldrsh r5,[r5,r5]`, `lsls r4,r6,1` etc. — string bytes, no coherent body |

### L2b. Loads with indirect transfer (`ldr rX,[rY,#0x60]` → `blx rX` / `mov pc,rX`)

**OBSERVED**: 49 such sites by halfword pattern; 47 in reachable functions
(`0x3170 0x33a2 0x34e8 0x39ee 0x3a52 0x3ae8 0x3bea 0x3c9e 0x3d2a 0x40a6 0x44be 0x4504
0x4610 0x4666 0x46e4 0x506e 0x524a 0x5424 0x54f0 0x561a 0x5712 0x5980 0x5baa 0x5c04
0x5c9c 0x5fd4 0x6056 0x61aa 0x6416 0x6504 0x6684 0x6714 0x72dc 0x7842 0x7860 0x7e3c`),
2 inside the dispatcher island (`0xae5c`, `0xb71a`).

Every one of the 47 reachable sites resolves its base to the **port object array**
`0x200002b0 + port*0x1cc` (`movs r0,0x73; lsls; muls` = ×0x1cc; base literal pool word
`0x200002b0`, which also occurs 121× in the image) or to a runtime object derived from a
stack slot / in-image pointer table; **none** resolves to `0x20001854`, the object the
dispatcher island writes. Cross-check (**OBSERVED**): `0x20001854` appears as a word 87×
in the image, but none of the 47 sites' containing functions embeds that literal.

The call shape is two-level:

```
ldr r0,[r6,0x60]      ; port_obj->vtbl
ldr r3,[r0]           ; vtbl[0]
mov r0,r4 / movs r1,0xa / movs r2,0
blx r3                ; (port, msgcode, arg)   -- 0x317a, args = (r4, 0x0a, 0)
```

with deeper slots used elsewhere: `+0x10` (`0x33a2`, `0x3d2a`, `0x5bf6`), `+0x18`
(`0x6700`), `+0x1c` (`0x4fc0`), `+0x20` (`0x7854`), `+0x38` (`0x7b28`), `+0x40`
(`0x3b90`, `0x4058`), `+0x50` (`0x5ed0`), `+0x54` (`0x5b6c`), `+0x58` (`0x5b6c`,
`0x5bf8`). So `+0x60` really is a **vtable pointer** and slot 0 is a message dispatcher
called as `(port, msgcode, arg)` — exactly the signature of `FUN_0000a9bc`.

### L2c. The decisive structural fact: the installed vtable is **zero** in the image

**OBSERVED**: the pointer reachable code installs (`0x1cf0` → `0x13a2c`) points at a table
whose words `0x13a2c .. 0x13b00+` are **all zero** in the image (`0x13a2c`,`0x13a30`,…
= 0x00000000). `0x13a2c` occurs exactly once in the image — as that literal at `0x1f30`.
No reachable code writes any slot of *that* table: a corpus-wide search for LHS stores
through a `*(...(X+0x60)+k)` pointer returns nothing (only calls).

**OBSERVED — correction to a first-pass claim.** Reachable code *does* install in-image
**Thumb code pointers**, just not through `+0x60`. In the same initialiser `0x1cf0`
(`f_1cf0.c:44..57`), the word at `0x1efc` is `0x20000058`, and the function writes a
handler table there from its own literal pool:

```
puVar2 = 0x20000058          ; SRAM ops table
puVar2[8] = 0x83a1           ; 0x1f40, odd => Thumb code 0x83a0
*puVar2   = 0x87ef           ; 0x1f44, odd => 0x87ee
puVar2[1] = 0x88b1           ; 0x1f4c, odd => 0x88b0   (port != 0 branch)
puVar2[9] = 0x87e5           ; 0x1f48, odd => 0x87e4
```

So building a function-pointer table in SRAM by storing odd literal-pool words **is** a
mechanism this firmware uses from reachable code (398 odd in-image words exist in the
image; only these are provably stored as handlers). An earlier grep of the decompilation
for `= &FUN_` / `= &LAB_` missed it because these stores go through `PTR_LAB_…`/`PTR_FUN_…`
pointer *variables*; the corpus has exactly 2 such lines (`f_1cf0.c:50`,
`f_cfc8.c:43`), so the corrected statement is: **reachable code installs code pointers
into SRAM tables (0x20000058, demonstrated), and into `+0x60` only a data/table pointer
(0x13a2c, demonstrated) — never an island address.** No word equal to `0xa9bc`, `0xaf54`,
`0x10ac0`, `0x10b30`, `0x12938` or `0x129c8` (odd or even) exists anywhere in the image.

**INFERRED (not established)**: the port vtables are function-pointer tables that the
firmware fills at run time (the image copy is a zero template). If that reading is right,
the vtable slots — including slot 0, whose signature matches the dispatcher — are
invisible to static xref, which would explain the "zero inbound references" result for
the dispatcher island without making it dead code. It does **not** prove the island fills
a slot: no static edge ties `0xa9bc` to any table. Note also that the firmware demonstrably
has this pattern elsewhere in a place static analysis *can* see: `f_cfc8.c` loads
`PTR_FUN_00001fd0_1_0000d1d8` and calls it, and `f_9634.c:39` indexes
`(&PTR_FUN_00009644)[param_1]` — i.e. function-pointer tables in the image do normally
carry non-zero entries, so a table that is zero in the image is anomalous and needs the
runtime-fill explanation.

### L2d. What the island itself does with the field

**OBSERVED** (rizin decode, `0xaf54..0xaf88`): the island contains a setter/clearer:

```
0xaf54 push {r4,r5,r7,lr}          ; function entry, cmp r0,0 guard
0xaf5c ldr  r4,[0xafdc]            ; 0x200002b0
0xaf6e ldr  r4,[0xafe0]            ; 0x20001854
0xaf70 ldrb r0,[r4,0x11]
0xaf72 cmp  r0,0
0xaf74 beq  0xafce
0xaf76 str  r1,[r4,0x60]           ; install caller-supplied code* at obj+0x60
...
0xaf84 ldr  r2,[0xafe0]            ; 0x20001854
0xaf86 str  r1,[r2,0x60]           ; same on the other branch
0xaf80 blx  r1                     ; and call it with r0=1 when clearing
```

and a consumer at `0xae5c`: `ldr r1,[r4,0x60]; cmp r1,0; bne; blx r1; str r5,[r4,0x60]`
(guarded call, then clear). Also `0x12960: bl 0x10` — the large island calls the
startup/init routine at `0x10`.

**This corrects the reading in DIFF §11b** that `r1` at `str r1,[r4,#0x60]` "survives from
`adr r1,#4` at `0xa9d2`": `0xaf76` is in a **separate function with its own prologue at
`0xaf54`**, entered from elsewhere; `r1` there is that function's second argument (the
Ghidra decompilation independently types it `code *param_2` and writes
`*(code **)(unaff_r4 + 0x60) = param_2`). The decompiler's `param_1[0x18] = &PTR_FUN_
0000a9d8` in `f_a9bc.c:50` belongs to **case 0x16**, where `param_1` is the port object
(`[0x18]` in `undefined**` units = byte offset 0x60) — i.e. case 22 installs the *jump
table* `0xa9d8` into `+0x60` and the clear path calls `(*(code *)0xa9d8)(1)` = `0xaed0(1)`.
**INFERRED**: `+0x60` in the island's semantics is a "current callback / current table"
slot, both installed and invoked by the island, and never written by reachable code for
`0x20001854`.

---

## L3. The `"NVM0"` descriptor block and the startup routine (task 3)

### L3a. Decoded block `0x10f4c..0x10fb4` (**OBSERVED**)

```
0x10f4c 0x304d564e  "NVM0" magic
0x10f50 0x0003ffff 0x10f54 0x0000ffe0 0x10f58 0x0000ffff   <- three masks, not addresses
0x10f5c 0x200019a4 0x10f60 0x20001940 0x10f64 0x200017f8   <- SRAM pointers
0x10f68 0xe000e010 (SysTick CTRL)   0x10f6c 0xe000ed1c    <- PPB
0x10f70 0x2000002c 0x10f74 0x00000f71 0x10f78 0x00000f51   <- SRAM ptr; 2 Thumb code ptrs
0x10f7c 0x20000190 0x10f80 0x200018d0 0x10f84 0x4003003c   <- SRAM; APB
0x10f88 0x00001129 (Thumb code ptr) 0x10f8c 0xe000e408 0x10f90 0xe000e100 (NVIC ISER)
0x10f94 0x0000bb80 (48000)  0x10f98 0x20001278
0x10f9c 0x40050000 0x10fa0 0x40050204 0x10fa4 0x40050304
0x10fa8 0x40050f00 0x10fac 0x40050f80 0x10fb0 0x80000800 0x10fb4 0xfffeffff
```

Shape: **not** `(address, value)` pairs and not a walkable init list. It is a flat
descriptor: `"NVM0"` tag, three field masks (`0x3ffff`, `0xffe0`, `0xffff`), then a run of
absolute addresses (SRAM buffers, SysTick/NVIC/PPB, five APB `0x4005xxxx` bases) with
three Thumb code points (`0xf70`, `0xf50`, `0x1128`) and two scalars (`48000`, `0x80000800`)
interleaved. The masks at the head and the `& 0xffe0 / & 0xffff / & 0x3ffff` pattern are
consistent with address-alignment/width fields of a relocation or patch descriptor.
**INFERRED, unproven**: "NVM0" suggests a non-volatile-memory image descriptor used by a
programming/patch path, which would fit a bootloader-side structure.

### L3b. Is it referenced? (**OBSERVED**, decisive)

Exhaustive word scan: the **only** in-image pointers into `0x10f4c..0x10fb8` are the
three vector words (`0x4`, `0x8`, `0xc`) and `0x12978` (a literal-pool word inside the
large island). No code anywhere loads a literal into this block, and the two Thumb
targets it contains (`0xf50`, `0xf70`, `0x1128`) decode as interior/epilogue code, not
prologues (consistent with `execmodel.md` §2).

### L3c. Startup at `0x10` (**OBSERVED**)

First 90 instructions: `push {r4..r7,lr}; sub sp,#0x14; cpsid i`, then a sequence of
straight-line **register writes** — `0x40020100←0x800cc8`, `0x40020200←0xdd000000`,
`0x40020300←0xded`, `0x40040100←0x21 / +8←0x301b6`, `0x40040200←0x40 …`, `0x40040300`,
`0x40100030←0x12` — interleaved with `bl 0xb50`, `bl 0xb60`, `bl 0xb58`, and a
read-modify-write of `0x40030f08`. **It never reads the header or the `"NVM0"` block**:
no literal in `0x0..0x10` or `0x10f4c..0x10fb8` is loaded, there is no copy loop, and
`0xe000ed08` (SCB->VTOR) is **absent from the whole image** — no vector-table relocation.
So the startup path neither consumes the descriptor block nor installs any relocated
vector table. `0x10` remains a **CANDIDATE** entry, unchanged from `execmodel.md` §2.

---

## L4. Verdict per island

| island | mechanism tested | verdict |
|---|---|---|
| dispatcher `0xa9bc..0xb1a3` | base+delta table, pointer word, `+0x60` callback reachable from live code | **No evidence of static reachability.** L1 finds no delta/table reference (0 pairs, 0 co-located anchored hits). L2 finds no reachable site calling through `0x20001854+0x60` (0/47) and no store of *any* island address anywhere (no word in the image equals `0xa9bc`, `0xaf54`, `0xae5c`, `0x12960`…). The firmware does demonstrably install code pointers from reachable code (SRAM ops table at `0x20000058` ← `0x83a1/0x87ef/0x88b1/0x87e5`, L2c) and does install a table pointer into port objects' `+0x60` (← `0x13a2c`), so the *mechanism class* is real and in use; the island is simply never a participant in it. The remaining runtime-only routes: (a) slot 0 of a port vtable whose image copy at `0x13a2c` is all zero — **INFERRED**, unproven; (b) a callback installed by the island's own `0xaf54` setter and invoked by the island's own `0xae5c` consumer — self-contained, creates no inbound edge. |
| same, as dead code | stale/duplicated copy | **Not refuted either.** 3.1.12 has a counterpart at `0xaa10` (§11b), i.e. the block is maintained across builds, which argues against pure linker residue but does not prove execution. Kept **OPEN**, not "dead". |
| large island `0x10abc..0x129f0` (`0x10ac0`, `0x10b30`, `0x12938`, `0x129c8`) | same mechanisms | **No evidence of static reachability. One positive structural link found**: the island's own literal pool holds `0x10fa1` (the `"NVM0"` block), it writes a peripheral at `0x10e3c` (`0x40050000+0x60`) like ordinary driver code, and it calls the init routine at `0x10` (`0x12960 bl 0x10`). So it is real, coherent driver/bootloader-grade code that *uses* the image's descriptor structure — but it has no static caller in either direction, and the descriptor block it points at is itself referenced by nothing else except the vector header. **OPEN**: plausible bootloader/NVM programming block reachable only through a mechanism outside this image (e.g. an SRAM-loaded dispatcher, a boot-mode entry, or a computed jump); no evidence for any specific one. |
| `0x12938`, `0x129c8` specifically | — | same as above; both remain prologue-verified code with no inbound edge. |

**Bounds on these verdicts.** Static analysis cannot see: values written by code that is
itself only reachable at run time, tables that are zero in the image and filled in RAM
(proven to exist for `+0x60`), and any entry supplied from outside the image. Absence of
a static edge is therefore evidence about *this image's literal/reference structure*, not
proof of non-execution. Nothing here upgrades the earlier **INFERRED** statements to
established; the one new **REFUTED** item is the base+delta/offset-table relocation
hypothesis, and the one correction is that `0xaf76`'s stored `r1` is a function argument,
not a table base surviving from `0xa9d2`.

Artifacts: `delegated/liveness/delta_scan.py`, `delta_scan.json`, `ScanPtrStore.java`
(Ghidra-side enumerator, left unused because Ghidra is absent — kept for the parent to run
if the install is restored).
