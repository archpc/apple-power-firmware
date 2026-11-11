# Delegated protocol work — log

Append-only. One entry per step. Detailed write-up:
`evidence/magsafe-cortexm/delegated/protocol/dispatcher_318.md`.
Reproducer: `evidence/magsafe-cortexm/delegated/protocol/decode_dispatch.py`,
captured table dump: `.../protocol/table_318.txt`.

Subject: A2363 3.1.8 `firmware/images/A2363_3.1.8_10M569_base0.bin`
(SHA-256 `db4baf86…d2400f`, 83 464 bytes). File offsets == addresses (base 0).

## Step 1 — case table @ 0xa9d8  → PASS

14 little-endian words at 0xa9d8..0xaa0f. All 14 values lie inside the image (max 0x14608) and are
even, so all are valid Thumb entry points (0xaf72 is halfword- but not word-aligned; that is legal
for Thumb). Six unique targets, exactly as claimed: 0xaed0, 0xae90, 0xaf08, 0xaf50, 0xaf72, 0xb154,
appearing in slots 0 / {1,9} / 3 / 10 / 13 / {2,4,5,6,7,8,11,12} respectively.

Slot 15 (word at 0xaa10) = 0xd0002c01 → not an address, and it is **code**: `2c01 cmp r4,#1` /
`d000 beq 0xaa16`, decoded by rizin at 0xaa10-0xaa12. The same two words (`d0002c01`,
`48dee15e`) appear immediately after 3.1.12's table at 0xaa64/0xaa68, so the table length is 14 in
both builds. Claim confirmed, with the extra note that the table is inline (no padding) and is
followed straight away by code.

Index arithmetic: `lsls r0,r0,#2` on `msg-9`, `adr r1,4` → 0xa9d8, `ldr r0,[r1,r0]`.

## Step 2 — body 0xa9bc…, guard, dispatch  → PASS with two corrections

```
0xa9bc push {r4,r5,r6,r7,lr} (b5f0)   0xa9be sub sp,#0x1c (b087)
0xa9c0 mov r5,r2   0xa9c2 mov r4,r0   0xa9c4 mov r0,r1
0xa9c6 subs r0,#9  0xa9c8 cmp r0,#0xd 0xa9ce bhi 0xaa1c (d825)
0xa9d0 lsls r0,r0,#2  0xa9d2 adr r1,4  0xa9d4 ldr r0,[r1,r0]  0xa9d6 mov pc,r0 (4687)
```
Guard = unsigned `msg-9 <= 13` → 9..22, confirmed.

**Correction A (REFUTED): 0xaa2a is not a computed branch in 3.1.8.** Bytes 0xaa28-0xaa2b are
`29 28 d1 00` = `cmp r1,#0x28` / `bne 0xaa2e`. Path: 0xa9ce bhi → 0xaa1c (cmp #0x41) → 0xaa22
(cmp #3) → 0xaa28 (cmp #0x28) → 0xaa2a. The 0xaa2a figure is **3.1.12's** `mov pc,r0` (3.1.12
dispatcher at 0xaa10, table 0xaa2c, all six targets = 3.1.8's + 0x54).

The only computed branches in the 3.1.8 function are `add pc,r3` at **0xad3a** (17-byte table at
0xad3c, index `param_3[2]-8`) and `add pc,r0` at **0xad7a** (10-byte table at 0xad84), both inside
the `msg == 0x41` handler path. Whole-image scan: 22 `mov pc,rN` halfwords, only 0xa9d6 in this
function.

**Correction B (REFUTED): not 552 bytes.** The body runs to the shared epilogue
`0xacd4 add sp,#0x1c; 0xacd6 pop {r4,r5,r6,r7,pc}` → **0xa9bc..0xacd7 = 0x31c = 796 bytes**, with 47
internal branch references to 0xacd4. 0xa9bc+0x228 = 0xabe4 is `b 0xad2a`, mid-flow.

## Step 3 — decompiler cross-check  → control flow supported, table data flow REFUTED

`decomp3_318/f_a9bc.c` matches the instruction stream for: guard form, case 9 (`movs r2,#0x1c`),
case 10/0x12, case 0xc (`bl 0x6854` with r1=0xc, r2=&0x31130000, r3=1 — decompiler drops r1),
default path (`bl 0xa500` with r0=0 at 0xb156, `bl 0x6828` at 0xb15a), case 3 (5 calls then
conditional clear of byte at 0x20001854+0x14, `bl 0x955c`, `bl 0x1178(0x55730,0,0xbbb9,0)`), case
0x28 (`bl 0xd904` guarded by that same byte, then flag=1, `bl 0x9e74`, byte 2 at 0x20001940+0x34),
case 0x3d (`bl 0x31a0(1,0x29)`), case 2, and the whole inner `switch(param_3[2])` with the 17-entry
byte table.

REFUTED decompiler claims, all around the jump table:
* `param_1[0x18] = &PTR_FUN_0000a9d8` — the store at 0xaf76 is real (`str r1,[r4,#0x60]`, 0x60 =
  0x18×4) but the **value is r1 = the message type (0x16)**, not the table address.
* `if (puVar3 != 0) … else (*(code*)&PTR_FUN_0000a9d8)(1)` — no second branch exists; r0 holds
  0xaf72 at 0xaf72 so `cmp r0,#0` always falls through.
* `ppuVar5`/`PTR_FUN_0000a9d8` as a data object: fabricated.

## Step 4 — message mapping  → INFERRED, mostly OPEN

Numbering assumption: USB-PD 3.x control types per Linux `pd.h` / Zephyr — 1 GoodCRC, 2 GotoMin,
3 Accept, 4 Reject, 5 Ping, 6 PS_RDY, 7 Get_Source_Cap, 8 Get_Sink_Cap, 9 DR_Swap, 10 PR_Swap,
11 VCONN_Swap, 12 Wait, 13 Soft_Reset, 14/15 Reserved, 16 Not_Supported, 17 Get_Source_Cap_Ext,
18 Get_Status, 19 FR_Swap, 20 Get_PPS_Status, 21 Get_Country_Codes, 22 Get_Sink_Cap_Ext,
23 Reserved, 24 Get_Revision. (The task statement's `5=Accept,6=Reject,7=PS_RDY` is off by one.)

Inferred mapping 9..22 → DR_Swap, PR_Swap, VCONN_Swap, Wait, Soft_Reset, —, —, Not_Supported,
Get_Source_Cap_Ext, Get_Status, FR_Swap, Get_PPS_Status, Get_Country_Codes, Get_Sink_Cap_Ext.
No in-image constant names any message type; the only closed facts are the guard range and the
slot→target map. Out-of-guard 2, 3, 0x28, 0x3d, 0x41 have no PD control-message meaning → OPEN
(device-specific control codes).

## Step 5 — the six targets  → PASS, plus a structural finding

| target | bytes | shape | frame | refs |
|---|---|---|---|---|
| 0xae90 | 12 | mid-block entry (6 bytes past block start 0xae8a) → `b 0xaee4` → `bl 0xb73c` | dispatcher's | table slots 1,9 |
| 0xaed0 | 4 | `movs r2,#0x1c; b 0xaee4` | dispatcher's | table slot 0 + 0xaecc |
| 0xaf08 | 6 | `add r2,sp,#0x14 … b 0xacfc` | dispatcher's | table slot 3 + fallthrough 0xaf02 |
| 0xaf50 | 2 | `bx lr` | none | table slot 10 |
| 0xaf72 | 8 | mid-function, `cmp r0,#0; str r1,[r4,#0x60]; pop {r4,r5,r7,pc}` | `FUN_0xaf54` (4-reg) | table slot 13 |
| 0xb154 | 14 + tail | `bl 0xa500; bl 0x6828; … add sp,#0x24; pop {r4,r5,r6,r7,pc}` | `FUN_0xb09c` (**0x24**) | table slots 2,4-8,11,12 + fallthrough 0xb152 |

No prologue of its own for any of the six. Three entries assume a foreign frame or skip a
preamble, and 0xaf50 is a bare `bx lr` that never undoes the 0x1c frame → those paths cannot
execute coherently. Independent reachability scan: **0** branch refs, **0** word and **0** halfword
occurrences of 0xa9bc anywhere in the image; the prologue-bearing entries 0xaf54/0xb09c/0xaff0/0xb1a4
also have zero callers. So 0xa9bc..0xb1a3 is a closed island.

**INFERRED:** as shipped, this dispatcher is unreachable dead code and is internally inconsistent.
Two candidate causes, both OPEN: a stale/duplicated copy kept in the image whose table words were
relocated against a neighbouring build, or toolchain cross-jumping over provably untaken code.
The parent's framing ("the 3.1.8 control-message switch") therefore over-claims liveness; the
bytes of the guard, table and case bodies stand, the liveness does not. If a live control-message
dispatcher exists in 3.1.8 it is one of the other 13 `mov pc` sites — OPEN.
