# A2363 3.1.8 — independent reconstruction of the 0xa9bc switch on message type

Image: `firmware/images/A2363_3.1.8_10M569_base0.bin`
SHA-256 `db4baf86b068ad2a0bc7716a354d30a14fd2a778d7d2f26840e1f806dfd2400f`, 83 464 bytes (0x14608).
All addresses are **file offsets** and, by the base-zero convention in force here, also code
addresses. Base zero is corroborated *inside this function* by its own jump table: all 14 table
words are image-relative addresses that land on Thumb code (a real relocation to a non-zero
load base would make every one of them fall outside the image).

Tools: raw `struct` reads (Python), rizin 0.9.1 `-a arm -b 16` for instruction text, my own
Thumb branch-target scanner for reachability (`decode_dispatch.py`, checked in beside this file).
Ghidra's output was used only as a *claim source* to be checked, never as evidence.

Labels follow `README.md`. Summary of verdicts: task 1 **PASS**, task 2 **PASS with two
corrections (one REFUTED claim)**, task 3 **mostly supported, two decompiler claims REFUTED**,
task 4 **INFERRED/OPEN** (no in-image constant names a message type), task 5 **PASS with a
structural finding that reframes the object**.

---

## 1. The case table at 0xa9d8 — PASS

14 little-endian words, table occupies `0xa9d8..0xaa0f`; the table is *inline*, immediately
following the `mov pc,r0` at 0xa9d6 with no padding (bytes at 0xa9d6: `46 87 d0 ae 00 00 …`).

| slot | offset | value | in image | even (Thumb-safe) |
|---|---|---|---|---|
| 0 | 0xa9d8 | 0x0000aed0 | yes | yes, 4-aligned |
| 1 | 0xa9dc | 0x0000ae90 | yes | yes, 4-aligned |
| 2 | 0xa9e0 | 0x0000b154 | yes | yes, 4-aligned |
| 3 | 0xa9e4 | 0x0000af08 | yes | yes, 4-aligned |
| 4 | 0xa9e8 | 0x0000b154 | yes | yes |
| 5 | 0xa9ec | 0x0000b154 | yes | yes |
| 6 | 0xa9f0 | 0x0000b154 | yes | yes |
| 7 | 0xa9f4 | 0x0000b154 | yes | yes |
| 8 | 0xa9f8 | 0x0000b154 | yes | yes |
| 9 | 0xa9fc | 0x0000ae90 | yes | yes |
| 10 | 0xaa00 | 0x0000af50 | yes | yes |
| 11 | 0xaa04 | 0x0000b154 | yes | yes |
| 12 | 0xaa08 | 0x0000b154 | yes | yes |
| 13 | 0xaa0c | 0x0000af72 | yes | yes (halfword-aligned only) |
| — | 0xaa10 | 0xd0002c01 | **no** | **odd** |

**Six unique targets (OBSERVED):** `0xae90`, `0xaed0`, `0xaf08`, `0xaf50`, `0xaf72`, `0xb154`.
This matches the claim exactly, including the slot ordering.

**Word 15 at 0xaa10 is code, not a pointer (OBSERVED).** `0xd0002c01` is not an address; read as
two halfwords it is `0x2c01 cmp r4,#1` / `0xd000 beq 0xaa16`, and rizin decodes exactly that at
0xaa10-0xaa12. So the table is exactly 14 entries and execution resumes immediately after it.
Note also that `0xd0002c01` and the next word `0x48dee15e` are identical in 3.1.12 at
0xaa64/0xaa68 — the two bytes following the table are part of the same 8-byte code sequence in
both builds, which is independent confirmation that the table length is 14, not 15 or 16.

Index arithmetic (OBSERVED): `0xa9d0 lsls r0,r0,#2` with `r0 = msg-9`, `0xa9d2 adr r1,4`
(r1 = 0xa9d8), `0xa9d4 ldr r0,[r1,r0]`. So slot = `msg - 9` for `msg` in 9..22.

---

## 2. Function body: prologue, guard, dispatch — PASS, with two corrections

Prologue and guard (OBSERVED, bytes in parentheses):

```
0xa9bc  push {r4,r5,r6,r7,lr}   (b5f0)
0xa9be  sub  sp,#0x1c           (b087)
0xa9c0  mov  r5,r2              ; param_3
0xa9c2  mov  r4,r0              ; param_1
0xa9c4  mov  r0,r1              ; param_2 = message type
0xa9c6  subs r0,#9
0xa9c8  cmp  r0,#0xd
0xa9ca  ldr  r7,[pc,…] -> 0x20001a10
0xa9cc  ldr  r6,[pc,…] -> 0x200002b0
0xa9ce  bhi  0xaa1c             (d825, cond=1000 HI)
0xa9d0  lsls r0,r0,#2
0xa9d2  adr  r1,4   -> 0xa9d8
0xa9d4  ldr  r0,[r1,r0]
0xa9d6  mov  pc,r0              (4687)
```

The guard is unsigned `msg-9 <= 13`, i.e. **message types 9..22 (0x09..0x16)** — as claimed.
Everything else (2, 3, 0x28, 0x3d, 0x41 and any other value) leaves the guard and is handled by a
linear compare chain.

**Computed branch: only one, at 0xa9d6.** A whole-image scan for `mov pc, rN` (halfwords
0x4687/0x468f/0x46a7, Rd=pc) finds 22 sites; the only one inside 0xa9bc..0xacd7 is 0xa9d6.

**Correction 1 (REFUTED): there is no computed branch at 0xaa2a in 3.1.8.** Bytes at 0xaa28-0xaa2b
are `29 28 d1 00` = `cmp r1,#0x28` / `bne 0xaa2e`. 0xaa2a is the second half of an ordinary
conditional branch inside the linear compare chain. Exact path to it from the entry:

```
0xa9ce bhi 0xaa1c     (guard fails)
0xaa1c cmp r1,#0x41 ; 0xaa1e bne 0xaa22 ; 0xaa20 b 0xaba2   (case 0x41)
0xaa22 cmp r1,#3    ; 0xaa24 bne 0xaa28 ; 0xaa26 b 0xac42   (case 3)
0xaa28 cmp r1,#0x28 ; 0xaa2a bne 0xaa2e ; 0xaa2c b 0xac7a   (case 0x28)
0xaa2e cmp r1,#0x3d ; 0xaa30 bne 0xaa34 ; 0xaa32 b 0xaca2   (case 0x3d)
0xaa34 cmp r1,#2    ; 0xaa36 beq 0xaa3a ; 0xaa38 b 0xacd4   (case 2)
0xaa3a …            (case 2 body)
```

So 0xaa2a is reached by fallthrough from 0xaa28, and only when `msg != 0x28`.

Where the 0xaa2a figure *does* come from (OBSERVED): in **3.1.12** the byte-identical dispatcher
sits at `0xaa10` and *its* `mov pc,r0` is at **0xaa2a**, with the table at 0xaa2c. Every one of
the six targets there is exactly 3.1.8's plus 0x54 (0xae90→0xaee4, 0xaed0→0xaf24,
0xaf08→0xaf5c, 0xaf50→0xafa4, 0xaf72→0xafc6, 0xb154→0xb1a8), and the slots duplicate in the same
pattern. The parent's "computed branch at ~0xaa2a" is a **3.1.12 offset applied to the 3.1.8 image**.

There *are* two further computed branches in the function, but they are `add pc,rN` byte-table
dispatches, not `mov pc`:

* `0xad3a add pc,r3` with a **17-entry byte table at 0xad3c** (`08 6c 6c 6c 6c 6c 6c 6c 6c a6 af
  6c 6c 45 b8 c1 cb`), index `param_3[2] - 8`, guard `cmp r3,#0x10 / bls`, targets
  `0xad3e + 2*byte` = 0xad4e, 0xae16 (×8), 0xae8a, 0xae9c, 0xaeae, 0xaec0, 0xaed4, 0xadc8.
* `0xad7a add pc,r0` with a **10-entry byte table at 0xad84** (`18 50 17 5b 17 17 17 17 17 77`),
  index `(param_3[0] & 0x1f) - 3`, targets `0xad7e + 2*byte` = 0xadae, 0xae1e, 0xadac (×6), 0xae34, 0xae6c.

Both are reached only from inside the `msg == 0x41` handler (0xaba2 → … → 0xad2a for the
`param_3[5]` bit-7-clear "data message" path, 0xacd8/0xacdc for the other). The 3.1.8 analogue of
3.1.12's 0xaa2a is 0xa9d6; the analogues of these two are at 0xadc8/0xadbe + 0x54-ish shifts
(not chased further here).

**Correction 2 (REFUTED): the function is not 552 bytes.** Instruction flow runs from the
prologue at 0xa9bc to the shared epilogue

```
0xacd4  add sp,#0x1c   (b007)
0xacd6  pop {r4,r5,r6,r7,pc}   (bdf0)
```

i.e. **0xa9bc..0xacd7 = 0x31c = 796 bytes**, with 47 branch references to 0xacd4 from inside the
body (my scanner: 47, no external refs). 0xa9bc + 552 (0x228) = 0xabe4, which is the instruction
`b 0xad2a` in the middle of the `msg == 0x41` path — 552 is not an instruction or block boundary in
this image, nor is 0xaa10+0x228 a boundary in 3.1.12. Where 552 came from is **OPEN** (a Ghidra
body-vs-range figure is the likeliest origin).

---

## 3. Cross-check of `decomp3_318/f_a9bc.c` against my own decode

| decompiler claim | my instruction evidence | verdict |
|---|---|---|
| `if (param_2 - 9U < 0xe)` | 0xa9c6/0xa9c8/0xa9ce | **supported** |
| case 9 → 0xaed0, `uVar7 = 0x1c` | 0xaed0 `movs r2,#0x1c`; 0xaed2 `b 0xaee4` → 0xaee6 `bl 0xb73c` | **supported** |
| case 10 and 0x12 → 0xae90 | slots 1 and 9; 0xae90 `adds r0,r6,r0` … `movs r2,#0xe`; `b 0xaee4` | **supported** (but see §5: 0xae90 is a mid-block entry) |
| case 0xc → 0xaf08, `FUN_00006854(param_1, ppuVar5, local_1c, 1)` | 0xaf02 `ldr r0,[0xaf24]`=0x31130000; 0xaf04 `str r0,[sp,#0x14]`; 0xaf06 `movs r1,#0xc`; 0xaf08 `add r2,sp,#0x14`; 0xaf0a `movs r3,#1`; 0xaf0c `mov r0,r4`; 0xaf0e `b 0xacfc` → `bl 0x6854` | **supported**, except that the decompiler drops the literal argument `r1 = 0xc` |
| default path calls `FUN_0000a500(0)` then `FUN_00006828()` | 0xb154 `movs r0,#0`; 0xb156 `bl 0xa500`; 0xb15a `bl 0x6828` | **supported instruction-for-instruction** (frame caveat in §5) |
| default path writes `param_1[0x55]`, `*(DAT_0000ad7c+0x5c)` | 0xb17c `strb r5,[r4,#0x55]`; 0xb180 `str r0,[r7,#0x5c]` with `[r7]=0x20001a10` | **supported as text**, but `r5` and `[sp,#0xc]` are **not** the dispatcher's registers |
| case 0x13 → `return` | 0xaf50 `bx lr` (4770) | **supported as bytes**, **not supported as behaviour** — the 0x1c frame is never torn down (§5) |
| case 0x16 writes `param_1[0x18]` | 0xaf72 `cmp r0,#0`; 0xaf74 `beq 0xafce`; 0xaf76 `str r1,[r4,#0x60]`; 0xaf78 `pop {r4,r5,r7,pc}`. r4 = param_1, and 0x60 = 0x18×4 | **target supported, value REFUTED** |
| `param_1[0x18] = &PTR_FUN_0000a9d8` | the stored register is `r1` = param_2 = the message type (0x16); 0xa9d8 never appears in r1 on this path | **REFUTED** |
| `if (puVar3 != 0) … else (*(code *)&PTR_FUN_0000a9d8)(1)` | `r0` still holds the table entry (0xaf72) at 0xaf72, so `cmp r0,#0` can never take the `beq`; there is no second branch, no call through the table | **REFUTED** (Ghidra jointed the table word into a callable pointer) |
| case 3 "resets something": `FUN_00009df8(); FUN_00001fa0(); FUN_00007be4(1,0); FUN_00007be4(1,1)` then conditionally clears `*(DAT_0000af2c+0x14)`, `FUN_0000955c()`, `FUN_00001178(0x55730,0,0xbbb9,0)` | 0xac42 `bl 0x9df8`; 0xac46 `bl 0x1fa0`; 0xac4a-0xac5a `bl 0x7be4` twice with (1,0) and (1,1); 0xac5e `ldr r0,[0xaf2c]`=0x20001854; 0xac60 `ldrb r1,[r0,#0x14]`; `beq 0xacd4`; 0xac66 `strb r4(=0),[r0,#0x14]`; 0xac68 `bl 0x955c`; 0xac6c/0xac6e/0xac74 `bl 0x1178` with 0x55730,0,0xbbb9,0 | **supported exactly**. What is reset is one byte flag at 0x20001854+0x14 — **INFERRED** semantics |
| case 0x28 branches to `FUN_0000d904` | 0xac7a `cmp r4,#1`; 0xac7c `bne 0xacd4`; 0xac7e `ldr r4,[0xaf2c]`; 0xac80 `ldrb r0,[r4,#0x14]`; 0xac82 `cmp r0,#0`; 0xac84 `bne 0xac8c`; 0xac86 `movs r0,#0`; 0xac88 `bl 0xd904` | **supported** |
| case 0x28 tail: set flag, `FUN_00009e74()`, `*(0x20001940+0x34)=2`, `r0 = DAT_0000af14+6` | 0xac8c-0xac9e (`strb 1`, `bl 0x9e74`, `movs r2,#2`, `strb r2,[r1,#0x34]`, `ldr r0,[0xaf14]`=0x320001, `adds r0,#6`) | **supported** |
| case 0x3d → `FUN_000031a0(1,0x29)` | 0xaca2 `cmp r4,#0`; 0xaca4 `bne 0xacd4`; 0xaca6 `movs r0,#1`; 0xaca8 `movs r1,#0x29`; 0xacaa `bl 0x31a0` | **supported** |
| case 2 → `FUN_00001178(0x3567e0,0,0xbba9,0)`, `r0 = DAT_0000ad90` | 0xaa3a `cmp r4,#0`; 0xaa40/0xaa42 `ldr r0,[0xad94]`=0x3567e0, `ldr r2,[0xad98]`=0xbba9; 0xaa48 `bl 0x1178`; 0xaa4c `ldr r0,[0xad90]`=0x320001; 0xacd0 `bl 0xa450` | **supported** |
| inner `switch(uVar6)` with `uVar6 = param_3[2]`, guard `uVar6 <= 0x12` plus a 19-bit mask `0x4f8a6`, cases 8,9-0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18, and a `uVar6 == 2` special | 0xaaa4 `ldrb r1,[r5,#2]`; 0xaaa6 `cmp r1,#0x12`; 0xaab2 `ldr r1,[0xad9c]`=0x4f8a6 + `tst` (a 19-bit membership mask); 0xad3a `add pc,r3` with the 17-byte table at 0xad3c; blocks 0xae16 (`bl 0x2938`), 0xadd8 (`cmp r1,#6`), 0xadf2 (`cmp r1,#0x10`), 0xae00 (`cmp r2,#2`) | **supported** |
| `if (((uint)param_3[5] << 0x18) < 0)` | 0xaa92 `lsls r0,r1,#0x10`; 0xaa94 `bmi` — i.e. bit 7 of `param_3[5]` | **supported** (decompiler's shift amount is off by 8, sign bit is still bit 7 of that byte) |

Net: the decompiler's *control flow* is faithful; its *data flow around the jump table* is not
(`ppuVar5`/`PTR_FUN_0000a9d8` are fabricated, the value stored by case 0x16 is wrong, and the
`else (*(code*)&PTR_FUN_0000a9d8)(1)` branch does not exist).

---

## 4. Message-number mapping — INFERRED, mostly OPEN

**Numbering assumption, stated explicitly.** I use the USB-PD 3.x control-message type field as
standardised and as encoded in Linux `include/linux/usb/pd.h` (fetched and read during this task)
and Zephyr's `pd_ctrl_msg_type`:

```
1 GoodCRC   2 GotoMin   3 Accept   4 Reject   5 Ping   6 PS_RDY   7 Get_Source_Cap
8 Get_Sink_Cap   9 DR_Swap   10 PR_Swap   11 VCONN_Swap   12 Wait   13 Soft_Reset
14,15 Reserved   16 Not_Supported   17 Get_Source_Cap_Extended   18 Get_Status
19 FR_Swap   20 Get_PPS_Status   21 Get_Country_Codes   22 Get_Sink_Cap_Extended
23 Reserved   24 Get_Revision
```

Note that the numbering assumed in the task statement (`5=Accept, 6=Reject, 7=PS_RDY`) is **off by
one** against that table — Accept is 3, Reject 4, PS_RDY 6. This matters for the out-of-table
codes and is the reason I do not map code 3 to "Accept".

No constant in the image names a message type: the only literals this function uses are RAM
addresses (0x2000xxxx), the 0x320001 / 0x31130000 / 0x55730 / 0xbbb9 / 0xbba9 / 0x4f8a6 values, and
function addresses. **The mapping below is therefore INFERRED from the guard range alone.**

| msg | PD type (INFERRED) | slot | target | handler shape |
|---|---|---|---|---|
| 9 | DR_Swap | 0 | 0xaed0 | `bl 0xb73c(param_1, entry, 0x1c)` |
| 10 | PR_Swap | 1 | 0xae90 | test `byte[r6+msg]`, on nonzero `bl 0xb73c(...,0xe)` |
| 11 | VCONN_Swap | 2 | 0xb154 | reject/abort tail |
| 12 | Wait | 3 | 0xaf08 | `bl 0x6854(param_1, 0xc, &0x31130000, 1)` |
| 13 | Soft_Reset | 4 | 0xb154 | reject/abort tail |
| 14 | Reserved | 5 | 0xb154 | reject/abort tail |
| 15 | Reserved | 6 | 0xb154 | reject/abort tail |
| 16 | Not_Supported | 7 | 0xb154 | reject/abort tail |
| 17 | Get_Source_Cap_Extended | 8 | 0xb154 | reject/abort tail |
| 18 | Get_Status | 9 | 0xae90 | as msg 10 |
| 19 | FR_Swap | 10 | 0xaf50 | bare `bx lr` |
| 20 | Get_PPS_Status | 11 | 0xb154 | reject/abort tail |
| 21 | Get_Country_Codes | 12 | 0xb154 | reject/abort tail |
| 22 | Get_Sink_Cap_Extended | 13 | 0xaf72 | store msg type at `param_1[0x18]` |

Out-of-guard codes, with **no** PD meaning claimed:

| code | target | evidence | label |
|---|---|---|---|
| 2 | 0xaa3a | `bl 0x1178(0x3567e0,0,0xbba9,0)`, then `bl 0xa450(0x320001)` | **OPEN** — under the standard numbering 2 = GotoMin, which a cable-side controller would not receive as a *control* message of interest; more likely a device/UVDM control code |
| 3 | 0xac42 | 5 calls then a conditional flag clear at 0x20001854+0x14 | **OPEN** — 3 = Accept in PD, but the body (reset-like) does not fit Accept; consistent with a device "reset/soft-reconnect" request |
| 0x28 | 0xac7a | `param_1 == 1` guard, `bl 0xd904`, sets a state byte to 1 and 0x20001940+0x34 to 2 | **OPEN** — 40 has no PD control-message meaning at all |
| 0x3d | 0xaca2 | `bl 0x31a0(1,0x29)` | **OPEN** — 61 = 0x3d, no PD meaning |
| 0x41 | 0xaba2 | the whole data-message/payload path incl. both byte-table dispatches | **OPEN** — 65 |

Only these are *closed* by evidence: the guard range 9..22; slot ordering; the six targets.
Everything semantic (which PD message really arrives here, whether this is a PD control-message
switch at all rather than an Apple control-code switch that merely happens to cover 9..22) is
**OPEN**.

---

## 5. The six unique targets — and a structural finding that changes the framing

| target | bytes | first / last instruction | stack frame it assumes | reached from |
|---|---|---|---|---|
| 0xaed0 | 4 (0xaed0-0xaed3) | `movs r2,#0x1c` / `b 0xaee4` | dispatcher's (0x1c, uses no locals) | table slot 0 **and** `0xaecc bne` (inner-table block for `param_3[2]==0x18`) |
| 0xae90 | 12 (0xae90-0xae9b) | `adds r0,r6,r0` / `b 0xaee4` | dispatcher's (r6, `[sp,#0x10]`) | table slots 1, 9 only — **but it lands 6 bytes into the block that starts at 0xae8a**, skipping `mov r2,r1 / ldr r1,[sp,#0x10] / muls r0,r1,r0` |
| 0xaf08 | 6 (0xaf08-0xaf0d) | `add r2,sp,#0x14` / `b 0xacfc` | dispatcher's (`[sp,#0x14]`, `r4`) | table slot 3 and fallthrough from 0xaf02 |
| 0xaf50 | 2 (0xaf50) | `bx lr` (4770) | — | table slot 10 only |
| 0xaf72 | 8 (0xaf72-0xaf79) | `cmp r0,#0` / `pop {r4,r5,r7,pc}` | **`r4` = param_1, then a 4-register pop** | table slot 13 only (also fallthrough at 0xaf70 inside `FUN_0xaf54`) |
| 0xb154 | 14 (0xb154-0xb161) + `b 0xb17a`, epilogue 0xb17a-0xb185 | `movs r0,#0` / `add sp,#0x24; pop {r4,r5,r6,r7,pc}` | **0x24**, the frame of `FUN_0xb09c` (`push {r4,r5,r6,r7,lr}; sub sp,#0x24` at 0xb09c/0xb09e) | table slots 2,4,5,6,7,8,11,12; also fallthrough from 0xb152 inside `FUN_0xb09c` |

None of the six has a prologue of its own; all are out-of-line blocks of the enclosing frame or of
a *neighbouring* function.

**The finding (OBSERVED bytes, INFERRED meaning).** Four of the six entries are not usable case
bodies with this function's frame:

1. `0xaf50` is a bare `bx lr`. The dispatcher has `add sp,#0x1c; pop {r4,r5,r6,r7,pc}` at 0xacd4;
   returning via `bx lr` leaves sp 0x30 bytes low. It cannot return correctly.
2. `0xaf72` is the middle of `FUN_0xaf54`, and executes `pop {r4,r5,r7,pc}` — popping 4 words out
   of the dispatcher's 5-word saved-register area, so pc receives the saved `r6`.
3. `0xb154` ends with `add sp,#0x24`, 8 bytes more than the dispatcher allocated, and reads `r5`
   and `[sp,#0xc]` that the dispatcher never wrote on this path; it is the tail of `FUN_0xb09c`
   (frame 0x24), reached there by fallthrough in its own function.
4. `0xae90` skips the stride-multiply preamble at 0xae8a, so it indexes `byte[0x200002b0+msg]`
   instead of `byte[r6 + stride*port + r2]`.

Reachability, from my own scan of the whole image (branch targets computed from every halfword
boundary; plus raw word and halfword occurrences):

* `0xa9bc` — **0** references of any kind: no BL/B.W/B/Bcc target, no 32-bit word, no halfword.
  The parent's "no static inbound xref" is **independently confirmed**.
* `0xaf54`, `0xb09c`, `0xaff0`, `0xb1a4` — likewise **0** branch references and no pointer word, i.e.
  four prologue-bearing function entries that nothing in the image calls. (Intra-island labels
  0xaeec and 0xb17a *are* branched to, from 0xad5e and 0xb160 respectively, which is what makes the
  island a closed world: it can only be entered at its own entry points, and no live code reaches
  them.) The region 0xa9bc..0xb1a3 is therefore an entire island of functions that nothing in the
  image calls.
* The six table targets are therefore reached *only* through this table (plus intra-island
  fallthrough), never from live code.

**Conclusion (INFERRED):** as shipped in 3.1.8, the 0xa9bc dispatcher is unreachable dead code,
and it is self-inconsistent — its table resolves to three blocks of a foreign frame, one bare
`bx lr`, one mid-block entry, and only two (`0xaed0`, `0xaf08`) that would work inside its own
frame. Two explanations fit equally well and neither is settled:

* (i) a **stale copy**: an older dispatcher kept in the image (flash slot / superseded build)
  whose absolute relocation values now point at labels of the neighbouring, later-compiled
  functions;
* (ii) **cross-jumping / dead-path merging** by the toolchain over code that was provably never
  taken.

**OPEN.** What this does *not* change: the object is real, its guard and table are unambiguous, and
the case *bodies* are decodable. What it does change is the parent's framing — "the 3.1.8
control-message switch lives inside a 552-byte function at 0xa9bc" implies a liveness and a size
that the bytes do not support. If the live control-message dispatcher for 3.1.8 exists, it is not
provably this one; the other 13 `mov pc` sites in the census (e.g. 0x26c4, 0x36c0, 0x3ba4, 0x9640,
0xe1fa) are the remaining candidates.

---

## 6. Reproduction

```bash
python3 evidence/magsafe-cortexm/delegated/protocol/decode_dispatch.py \
        firmware/images/A2363_3.1.8_10M569_base0.bin 0xa9d8 14
/opt/homebrew/bin/rizin -a arm -b 16 -q -c 's 0xa9bc; pd 40' firmware/images/A2363_3.1.8_10M569_base0.bin
/opt/homebrew/bin/rizin -a arm -b 16 -q -c 's 0xae5c; pd 60' firmware/images/A2363_3.1.8_10M569_base0.bin
```

`table_318.txt` in this directory is the captured output of the first command.
