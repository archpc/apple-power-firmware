# Independent audit — MagSafe A2363 Cortex-M analysis

Auditor: independent pass. Every Phase-1 observation was produced from clean
imports and my own decodes **before** DIFF.md or `delegated/*.md` were opened
(see `audit-log.md`, written incrementally). All addresses are file offsets
(base-0 import). Image hashes verified against `SHA256SUMS` first: all three OK.

Tooling: Ghidra 12.1.4 headless at
`/Users/sein/.hermes/tools/ghidra/ghidra_12.1.4_PUBLIC/support/analyzeHeadless`,
`JAVA_HOME=$(brew --prefix openjdk@21)`, projects in `/tmp/magsafe-audit`;
rizin 0.9.1, `-e scr.color=0 -a arm -b 16`.

## Verdict summary

| # | Claim | Verdict |
|---|---|---|
| 1 | Three image SHA-256s match `SHA256SUMS` | **PASS** |
| 2 | Clean 3.1.8 import is `ARM:LE:32:Cortex`/`default`, `0x10` = `push {r4-r7,lr}` | **PASS** |
| 3 | Reset word `0x10f7c` does not decode as a prologue (data) | **PASS** |
| 4 | Seeded 3.1.8 run = 444 functions, inventory identical to `inventory3_318.json` | **PASS** |
| 5 | Coverage 46.4 % (38,760 / 83,464) | **PASS** |
| 6 | `0xa9bc` prologue+guard (`subs r0,#9` / `cmp r0,#0xd`), `mov pc,r0` at `0xa9d6` | **PASS** |
| 7 | 14-word table at `0xa9d8`; `0xaa10` = `0xd0002c01` is not a pointer | **PASS** |
| 8 | `0xaa2a` in 3.1.8 is `cmp r1,#0x28`+`bne`, not a computed branch | **PASS** (doc's byte quote is byte-swapped) |
| 9 | 3.1.12 dispatcher `0xaa10`, table `0xaa2c`, same guard | **PASS** |
| 10 | No static reference (BL/B.W/word/halfword) to `0xa9bc` | **PASS** |
| 11 | Default/unhandled slot `0xb154` calls `FUN_0000a500(0)` then `FUN_00006828` | **PASS** |
| 12 | Case `0x28` reaches `FUN_0000d904` | **PASS** (conditional on `[0x20001854+0x14]==0`) |
| 13 | "Store at `0xaf76` writes the message type (r1), not the table address" | **FAIL** — see §C |
| 14 | "The `(*(code*)&table)(1)` branch does not exist" | **FAIL as worded** — code exists at `0xafce`; unreachable, not absent |
| 15 | Seeded 3.1.12 run = 436 functions, inventory identical | **PASS** |
| 16 | Coverage table 444/436/423 and 46.4/45.2/56.2 % | **PASS** |
| 17 | Case targets enter foreign frames / island unreachable, liveness OPEN | **PASS** |
| 18 | protocol.md "22 `mov pc,rN` halfwords in the image" | **FAIL** — 18 |
| 19 | xversion 3.1.12→3.2.0 pair counts 183 sigs, 224/211, 49.9 % | **PASS** |
| 20 | §11d/xversion "182 sigs in all three, 225/223/213, mult 10, 235 pairs/195 unmatched" | **FAIL (not reproducible)** — stale 430-function 3.2.0 run |
| 21 | 3.2.0 switch claims (`0x4b78` 2–9/8, `0x50fc` 2–14/13, `0x4eca` 3–17/15) | **PASS** |
| 22 | execmodel seed classification, vector-table map, 46.44 % coverage | **PASS** (spot-checked); gap-range census **OPEN** |
| 23 | Evidence labels used correctly | **PASS with two exceptions** (§C, §D) |

## A. Reproduced commands

```
cd /Users/sein/.hermes/artifacts/apple-power-firmware
GH=$HOME/.hermes/tools/ghidra/ghidra_12.1.4_PUBLIC/support/analyzeHeadless

# hashes
grep -E 'A2363_(3\.1\.8|3\.1\.12|3\.2\.0)' SHA256SUMS | shasum -a 256 -c -

# 3.1.8 seeded, clean project
JAVA_HOME=$(brew --prefix openjdk@21) $GH /tmp/magsafe-audit s318 \
  -import firmware/images/A2363_3.1.8_10M569_base0.bin \
  -processor ARM:LE:32:Cortex -cspec default -scriptPath scripts/ghidra \
  -postScript SeedCortexM.java evidence/magsafe-cortexm/seeds3_318.csv \
  evidence/magsafe-cortexm/delegated/review/inventory3_318_audit.json \
  evidence/magsafe-cortexm/delegated/review/decomp3_318_audit
# -> DONE functions=444

# 3.1.12 the same way with xversion/seeds3_3112.csv -> DONE functions=436

# decode
rizin -q -e scr.color=0 -a arm -b 16 \
  -c 'e asm.arch=arm; s 0xa9bc; pd 24' firmware/images/A2363_3.1.8_10M569_base0.bin
rizin -q -e scr.color=0 -c 'pxw 64 @ 0xa9d8' firmware/images/A2363_3.1.8_10M569_base0.bin
```

## B. Structural facts I confirmed independently (3.1.8)

```
0xa9bc push {r4,r5,r6,r7,lr}   0xa9be sub sp,#0x1c
0xa9c0 mov r5,r2  0xa9c2 mov r4,r0  0xa9c4 mov r0,r1
0xa9c6 subs r0,#9 0xa9c8 cmp r0,#0xd 0xa9ce bhi 0xaa1c
0xa9d0 lsls r0,r0,#2  0xa9d2 adr r1,4  -> 0xa9d8
0xa9d4 ldr r0,[r1,r0] 0xa9d6 mov pc,r0
```
Table `0xa9d8..0xaa0f` = `aed0 ae90 b154 af08 b154 b154 b154 b154 b154 ae90 af50 b154 b154 af72`
(6 unique targets; 8 slots to `0xb154`); `0xaa10 = 0xd0002c01`.

Inbound-reference scan for `0xa9bc` in 3.1.8 (all 1,920 BL sites decoded with
`scripts/ghidra/bl_xref.py`, plus raw scans): no BL, no B.W, no 32-bit word,
no halfword `a9bc`, no Thumb-flagged pointer `a9bd`. The island is statically
unreferenced — the documents say the same (`OPEN` liveness), and that part is
correct.

**Anomaly both documents do note but under-state (my observation):** table word
14 (`0xaf72`) is `cmp r0,#0; beq 0xafce; str r1,[r4,#0x60]; pop {r4,r5,r7,pc}`,
i.e. it lies *inside* the function that starts at `0xaf54`
(`push {r4,r5,r7,lr}` … matching `pop {r4,r5,r7,pc}`). Entered from the
dispatcher it pops a frame it never pushed. Ghidra resolves this by inventing
`FUN_0000af72` (18 B). protocol.md lists this as "frame: FUN_0xaf54 (4-reg)";
the underlying reading is right, the semantic consequence is the same.

## C. FAIL — the `0xaf76` store (DIFF §11b, protocol.md Step 3)

Documents: "`param_1[0x18] = &table` is wrong — the store at `0xaf76` writes
the message type (`r1`), not the table address."

Instruction at `0xaf76` is `str r1,[r4,#0x60]` (bytes `21 66`). Two reachable
paths, neither of which leaves the message type in `r1`:

* **switch path** (the one the decompiler models): `0xa9d2 adr r1,4` writes
  `r1 = 0xa9d8` (table base) *before* `0xa9d6 mov pc,r0`; nothing between
  `0xa9d6` and `0xaf76` reloads `r1`. Value stored = `0xa9d8`.
* **fall-through path** through `0xaf54`: `r1` is that function's second
  argument, which the sibling block at `0xaf7a`/`0xaf80` (`blx r1`) shows is a
  **callback pointer**.

Both rizin and my own clean Ghidra decompile (`decomp3_318_audit/f_a9bc.c`,
generated before reading the target) agree: `param_1[0x18] = &PTR_FUN_0000a9d8`.
The decompiler's dataflow is faithful to the machine code; the "message type"
correction is wrong. (It would be right only if `adr r1,4` did not exist.)

Same paragraph: "`if (puVar3 != 0) … else (*(code*)&table)(1)` — no second
branch exists". It does exist: `0xafce movs r0,#1; 0xafd0 blx r1;
0xafd2 movs r0,#0; 0xafd4 str r0,[r4,#0x60]`. It is simply never taken on the
switch path because `r0` holds the non-null table entry `0xaf72`. The correct
finding is "the branch is dead / the callee value is nonsense", not "the
branch does not exist". This is the one place where the documents turn a
correct observation (broken island) into an incorrect instruction-level claim.

## D. FAIL — stale cross-version numbers (DIFF §11d, xversion.md Step 4)

Documented reproducer: `python3 xversion/match.py xversion/match_result.json`.
Re-running it today on the checked-in inputs reproduces the *pair* rows
(3.1.8→3.1.12: 379 shared signatures, 430/428; 3.1.12→3.2.0: 183, 224/211,
49.9 % of 423) but not the "all three" block, because `match_result.json` was
produced against a **430-function** 3.2.0 inventory, while
`mnems_320.json`/`inventory3_320.json` now hold **423**:

| quantity | document | my rerun |
|---|---|---|
| 3.2.0 functions | 430 | 423 |
| signatures in all three | 182 | 181 |
| 3.2.0 / 3.1.12 / 3.1.8 functions covered | 213 / 223 / 225 | 209 / 222 / 224 |
| 3.2.0 max multiplicity | 10 | 7 |
| size-changed 3.1.12→3.2.0 | 1 | 0 |
| tier-2 pairs / 3.2.0 unmatched | 235 / 195 | 234 / 189 |

The many-to-many caveat itself is sound (28 duplicated sequences, max
multiplicity 14 in 3.1.x — reproduced). But the quoted "182 / 225 / 223 / 213"
and "235 / 195" are stale artifacts and should be regenerated or marked with
the build that produced them.

## E. Minor errors

* protocol.md Step 2 quotes bytes `0xaa28..0xaa2b` as `29 28 d1 00`; actual
  bytes are `28 29 00 d1` (halfwords `0x2928 cmp r1,#0x28`, `0xd100 bne`).
  Instruction reading is right, byte order in the quote is not.
* protocol.md: "22 `mov pc,rN` halfwords" in the image; a 16-bit `mov pc,rN`
  scan finds **18** (`0x26c4 … 0xa9d6 … 0xeb7e`), of which exactly one
  (`0xa9d6`) is in this function — the load-bearing part holds. 22 is likely a
  mix-up with `add pc,rN` (26 such sites) or an older count.
* protocol.md Step 1: "all 14 values … valid Thumb entry points" while the same
  document (Step 5) correctly calls `0xaf72` a mid-function entry. Entry
  *alignment* is fine; "valid entry point" is too strong.
* §11a says two 3.1.8 runs differ only in the `0x10` body length (4 vs 8 B).
  My clean run gives 4 B (`MemManage`), identical to the checked-in inventory;
  the 4-vs-8 instability is therefore **UNVERIFIED** (not reproduced), not
  refuted.

## F. What holds up well

* Execution-model section is solid: language/compiler ID, image extent
  `0x0..0x14607`, `0x10` prologue, `0x10f7c` data (bytes `90 01 00 20` =
  `0x20000190`), and the 23-word descriptor run at `0x10f54..0x10fac` — my
  independent dump matches all 23 words, including `0x10f7c` as word 10.
* Seed hygiene: the clear is gated (start/length/type) in `SeedCortexM.java`;
  my run logged no aborted clears and produced byte-identical inventories.
  Spot-checked seed classes: `0x10` = `f0 b5` real code; `0x3b72` = `0xfb16`,
  second half of `bl 0x31a0` at `0x3b70`; `0x2c6a` = `0xffff`, upper half of
  `0xfffffc00` at `0x2c68`. No data was forced to code.
* 3.2.0 switch inventory independently confirmed: `0x4b78` `subs r0,r1,#2;
  cmp r0,#7` (2–9, 8 words at `0x4b94`, next `0x00892173`); `0x5158 subs r0,r1,#2;
  cmp r0,#0xc` then `adr r1,4 → 0x5168` (13 words, next `0x2e03461f`);
  `0x4eca ldr r0,[r0]; ldrb r0,[r0,#1]; subs r1,r0,#3; cmp r1,#0xe` (3–17,
  15 words at `0x4ee4`, next `0x200002a8`).
* The dead-island conclusion is well supported and honestly labelled.

## G. OPEN / not verified by me

* The 44,930 B / 341-range coverage-gap census (`gapclass`) — not re-run.
* Table lengths of the inner `add pc,r3` / `add pc,r0` switches (17 B at
  `0xad3c`, 10 B at `0xad84`) — decode locations confirmed, table extents not.
* 3.2.0 coverage 56.2 % taken from `inventory3_320.json` (423 / 47,208 B);
  I did not re-run the 3.2.0 seeded pipeline.
* Any runtime/execution claim: none is verifiable statically, and the
  documents label them INFERRED/OPEN correctly.
