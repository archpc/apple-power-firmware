# MagSafe 3 (A2363) firmware — behavioral evidence

Scope: narrow behavioral evidence for four targets. Whole-image function inventory and
size-based diff are handled by a separate agent and are NOT duplicated here.

Images (read-only, never modified):

| label  | file | size | sha256 |
|---|---|---|---|
| 3.1.8  | A2363_3.1.8_10M569_base0.bin   | 83464 (0x14608) | db4baf86b068ad2a0bc7716a354d30a14fd2a778d7d2f26840e1f806dfd2400f |
| 3.1.12 | A2363_3.1.12_10M1543_base0.bin | 83592 (0x14688) | 611f6930e85c3f195424af618fb2834e41f9c3f57e04cc2ffe9d8da5f7bcde02 |
| 3.2.0  | A2363_3.2.0_10M13722_base0.bin | 84048 (0x14850) | 6d158f971ab7632a30ecd1060ef0131368e2d5e746fc5c529f9b111b6df0050e |

Toolchain: `rea` CLI via `npx -y rea-agents@6.7.0` (standalone process, no MCP), plus an
independent capstone 5.0.7 (in `<home>/.hermes/cache/scratch/reaenv`) linear-sweep
disassembler in `tools/` so every claim is checkable against raw bytes. Helpers:
`tools/fwsearch.py`, `tools/thumb.py`, `tools/dis_all.py`. Raw dumps in `raw/`.

Global image facts (measured, not assumed):
- Entropy 6.907 / 6.908 / 6.913 bits/byte, 9.3–9.5 % zero bytes, zero 0xFF padding runs
  >= 16 bytes. Consistent with code-dominated flat image, not compressed.
- Vector table at 0x0: SP=0x20002000, reset handler = 0x00010F7D (3.1.8).
- Pure Thumb-1: **zero** `movw`/`movtb` (MOVW/MOVT) instructions in all three images, so
  every 32-bit constant is reached through a PC-relative literal pool.
- Code region 0x000000–0x0012C00, string/data region starts 0x0012C00, more code and
  tables after 0x0013200.

---

## Target 1 — USB-PD message handling / vendor-defined messages

### 1a. Literal signatures: NEGATIVE, with the search stated

Command (Python, exact byte patterns on the raw file):

```
pats = {'VDMs': bytes.fromhex('56444d73'), 'VDM': bytes.fromhex('56444d'),
        'PD type run 01..0d (bytes)': bytes(range(1,0x0e)),
        'PD type run 01..21 (bytes)': bytes(range(1,0x22)),
        'PD type run 01..26 (bytes)': bytes(range(1,0x27)),
        'PD type run 01..0d (halfwords LE)': b''.join(struct.pack('<H',i) for i in range(1,0x0e))}
```

| pattern | 3.1.8 | 3.1.12 | 3.2.0 |
|---|---|---|---|
| ASCII `VDMs` (56 44 4D 73) | 0 | 0 | 0 |
| ASCII `VDM` (56 44 4D) | 0 | 0 | 0 |
| byte run 0x01..0x0D | 0 | 0 | 0 |
| byte run 0x01..0x21 | 0 | 0 | 0 |
| byte run 0x01..0x26 | 0 | 0 | 0 |
| halfword run 0x0001..0x000D (LE) | 0 | 0 | 0 |

**CONFIRMED NEGATIVE:** there is no ASCII `VDM`/`VDMs` marker, and no contiguous table of
USB-PD message-type codes 0x01..0x26 in any of the three images. The PD message-type space
is not materialised as a data table.

### 1b. Apple SVID 0x05AC — CONFIRMED, 12 literal-pool constants per image

Scan: every 4-byte-aligned word in the code region (0x0..0x12C00) where
`(w & 0xFFFF) == 0x05AC` or `(w >> 16) == 0x05AC`.

The SVID sits in **bits 31:16** with a 16-bit vendor code in bits 15:0 — the layout of a
USB-PD VDO carrying Apple's VID. Values are identical in 3.1.8 and 3.1.12 and differ in
exactly one entry in 3.2.0:

| # | 3.1.8 pool addr / value | 3.1.12 | 3.2.0 |
|---|---|---|---|
| 1 | 0x0B59C `0x000005AC` | 0x0B5F0 `0x000005AC` | 0x0B718 `0x000005AC` |
| 2 | 0x0B5A0 `0x05AC0010` | 0x0B5F4 `0x05AC0010` | 0x0B71C `0x05AC0010` |
| 3 | 0x0BAF0 `0x000005AC` | 0x0BB44 `0x000005AC` | 0x0BC64 `0x000005AC` |
| 4 | 0x0BB9C `0x05AC8003` | 0x0BBF0 `0x05AC8003` | 0x0BD10 `0x05AC8003` |
| 5 | 0x0BCC0 `0x000005AC` | 0x0BD14 `0x000005AC` | 0x0BE18 `0x000005AC` |
| 6 | 0x0C0CC `0x05AC03EF` | 0x0C120 `0x05AC03EF` | 0x0C2C0 `0x05AC03EF` |
| 7 | 0x0C2EC `0x05AC0005` | 0x0C340 `0x05AC0005` | 0x0C4E0 `0x05AC0005` |
| 8 | 0x0C2F0 `0x05AC8106` | 0x0C344 `0x05AC8106` | 0x0C4E4 `0x05AC8106` |
| 9 | 0x0C558 `0x05AC0012` | 0x0C5AC `0x05AC0012` | 0x0C76C `0x05AC0012` |
| 10 | 0x0C5E8 `0x05AC0005` | 0x0C63C `0x05AC0005` | 0x0C7FC `0x05AC0005` |
| 11 | 0x0C618 `0x05AC0000` | 0x0C66C `0x05AC0000` | 0x0C82C `0x05AC0000` |
| 12 | 0x0C6D0 `0x05AC0002` | 0x0C724 `0x05AC0002` | 0x0C8FC **`0x05AC0000`** |

Entry 12 is the only SVID-bearing constant that changed between 3.1.x and 3.2.0
(`...0002` -> `...0000`). Whether that is a command-code change or a flag-bit clear is
**INFERRED** — see the caveat at the end of 1c.

### 1c. UVDM transmit builder — CONFIRMED (3.1.8, bytes read)

At `0x00C2B8` there is a function that selects 1 or 2 data objects and calls an assembler:

```
00c2b8  e0b5      push  {r5, r6, r7, lr}
00c2ba  3021      movs  r1, #0x30
00c2bc  4143      muls  r1, r0, r1
00c2be  0d4a      ldr   r2, [pc, #0x34]   ; [0xc2f4]=0x200011d8
00c2c0  5118      adds  r1, r2, r1
00c2c2  4968      ldr   r1, [r1, #4]
00c2c4  097d      ldrb  r1, [r1, #0x14]        ; state byte
00c2c6  0129      cmp   r1, #1
00c2c8  07d0      beq   #0xc2da
00c2ca  0029      cmp   r1, #0
00c2cc  09d1      bne   #0xc2e2
00c2ce  0749      ldr   r1, [pc, #0x1c]   ; [0xc2ec]=0x05ac0005
00c2d0  0191      str   r1, [sp, #4]          ; VDO[1]
00c2d2  0749      ldr   r1, [pc, #0x1c]   ; [0xc2f0]=0x05ac8106
00c2d4  0091      str   r1, [sp]             ; VDO[0]
00c2d6  0222      movs  r2, #2               ; 2 data objects
00c2d8  04e0      b     #0xc2e4
00c2da  0449      ldr   r1, [pc, #0x10]   ; [0xc2ec]=0x05ac0005
00c2dc  0091      str   r1, [sp]             ; VDO[0]
00c2de  0122      movs  r2, #1               ; 1 data object
00c2e2  0022      movs  r2, #0               ; 0 data objects
00c2e4  6946      mov   r1, sp
00c2e6  00f007f8  bl    #0xc2f8                ; assemble + send
```

The callee at `0x00C2F8` copies `r2` words from `[r1]` into a stack buffer at `sp+0x10`:

```
00c2f8  f0b5      push  {r4, r5, r6, r7, lr}
00c2fa  8db0      sub   sp, #0x34
00c2fc  0026      movs  r6, #0
00c2fe  1346      mov   r3, r2
00c300  002b      cmp   r3, #0
00c302  06d0      beq   #0xc312
00c304  02ac      add   r4, sp, #8
00c306  a419      adds  r4, r4, r6
00c308  8d59      ldr   r5, [r1, r6]
00c30a  2561      str   r5, [r4, #0x10]     ; VDO -> message buffer
00c30c  5b1e      subs  r3, r3, #1
00c30e  361d      adds  r6, r6, #4
00c310  f6e7      b     #0xc300
```

**CONFIRMED:** a vendor-defined-message tx path exists: per-port state is read from a
0x30-byte-stride structure (`muls r1, r0, #0x30`), a state byte at `[port+4]+0x14`
selects 0/1/2 VDOs, and the VDOs are Apple-SVID words. The same builder reads
`0x05AC0005` in the one-object branch and `0x05AC8106` as the first of two objects.

Field decode of `0x05AC8106` as a Structured-VDM header (bit15=Structured, bits10:8 =
command type 1, bits7:0 = 0x06) is **INFERRED** — it parses consistently but I could not
resolve the command semantics from the image. `0x05AC8003` likewise parses as
bit15=Structured + command 0x03. The unstructured-looking constants (`0x05AC0010`,
`0x05AC0012`, `0x05AC0005`, `0x05AC03EF`) have bit15 clear, so they are not Structured-VDM
headers; treat the low halfword as an opaque Apple vendor code unless corroborated.

### 1d. 33-entry code-pointer table (unresolved, reported as-is)

A run of 33 consecutive Thumb code pointers (all odd, all < text end) exists in each image:

- 3.1.8 `0x00132FC`, 3.1.12 `0x001337C`, 3.2.0 `0x00134B4`
- first entries 3.1.8: `03668 0366c 037d8 0385c 0389c 03948 039a0 03a1c 03a6c ...`
- first entries 3.2.0: `03720 03724 03818 0389c 038dc 03988 039e0 03a5c 03aac ...`

33 entries happens to equal the USB-PD control-message span 0x01..0x21, but **I could not
confirm this is a PD message-type dispatch**: no instruction in any image loads the table
base as a literal, there is no `cmp #0x21`, no `and #0x1f`, and no `add rX, pc` (ADR) form
reaching it. It is equally consistent with a generic app-level vector/API table.
**Status: UNPROVEN — do not cite as a PD dispatch table.** Also present: 19-entry table
(3.1.8 0x001339C) and 28-entry table (3.1.8 0x00135A8), likewise unreferenced.

### 1e. State-machine name strings (context, CONFIRMED present)

A contiguous name pool at 0x0012D44 (3.1.8) / 0x0012FA0 (3.2.0) contains
`SPM FSM`, `spm_charger_detached`, `spm_host_detached`, `spm_host_src_altmode_enumeration`,
[`spm_host_src_hardreset` — 3.1.x only], `spm_host_src_in_contract`,
`apple_uvdm_state_disabled`, `apple_uvdm_state_dfp_enumerate`,
`apple_uvdm_ufp_enumerate_start`, `apple_uvdm_ufp_enumerate_end`,
`apple_uvdm_state_operation`, `uvdm fsm`.

These names are **not referenced by any 32-bit pointer** in any image (scan: every word in
the image whose value resolves to a printable C string yielded no pointer into the
`spm_*`/`apple_uvdm_*` names). So the pool is a name table walked sequentially or only
consumed by a tracing path; it is not a dispatch table. See Target 2 for the one-entry
difference.

---

## Target 2 — reset handling (Soft_Reset vs Hard_Reset)

### 2a. Premise correction (important for evaluating the third-party claim)

The task framing states "Soft_Reset is message type 0x0D and Hard_Reset is 0x01 in the
control-message space". That is wrong for USB-PD. In USB-PD 3.0/3.1 Table 6-5 the control
message types are 0x01 = **GoodCRC**, 0x02 GotoMin, 0x03 Accept, 0x04 Reject, 0x05 Ping,
0x06 PS_RDY, 0x07 Get_Source_Cap, 0x08 Get_Sink_Cap, 0x09 DR_Swap, 0x0A PR_Swap,
0x0B VCONN_Swap, 0x0C Wait, **0x0D Soft_Reset**, 0x0E Data_Reset, 0x0F
Data_Reset_Complete, 0x10 Not_Supported, ... **Hard_Reset is not a control message at
all** — it is a protocol-layer action (drive vSafe0V for tHardReset) with no MessageType
code. So "0x01" cannot be Hard_Reset. Any claim built on hard-reset == 0x01 is
mis-specified; the search below uses Soft_Reset = 0x0D and treats hard reset as an action.

### 2b. CONFIRMED — a real PD control-message dispatcher exists in 3.1.8 / 3.1.12

3.1.8, function entry `0x00A9BC`, bytes read from the image:

```
00a9bc  f0b5      push  {r4, r5, r6, r7, lr}
00a9be  87b0      sub   sp, #0x1c
00a9c0  1546      mov   r5, r2
00a9c2  0446      mov   r4, r0
00a9c4  0846      mov   r0, r1
00a9c6  0938      subs  r0, #9        ; index = MessageType - 9
00a9c8  0d28      cmp   r0, #0xd      ; accept indices 0..13  => types 9..22
00a9ca  ec4f      ldr   r7, [pc, #0x3b0]   ; [0xad7c]=0x20001a10
00a9cc  ec4e      ldr   r6, [pc, #0x3b0]   ; [0xad80]=0x200002b0
00a9ce  25d8      bhi   #0xaa1c             ; out of range -> default
00a9d0  8000      lsls  r0, r0, #2
00a9d2  01a1      adr   r1, #4              ; r1 = 0x00a9d8 (table base)
00a9d4  0858      ldr   r0, [r1, r0]
00a9d6  8746      mov   pc, r0
```

Jump table at `0x00A9D8`, 14 entries, types 9..22 (raw bytes, little-endian 4-byte words):

| idx | type | message | target |
|---|---|---|---|
| 0 | 0x09 DR_Swap | | 0x00AED0 |
| 1 | 0x0A PR_Swap | | 0x00AE90 |
| 2 | 0x0B VCONN_Swap | | 0x00B154 |
| 3 | 0x0C Wait | | 0x00AF08 |
| 4 | **0x0D Soft_Reset** | | **0x00B154** |
| 5 | 0x0E Data_Reset | | 0x00B154 |
| 6 | 0x0F Data_Reset_Complete | | 0x00B154 |
| 7 | 0x10 Not_Supported | | 0x00B154 |
| 8 | 0x11 Get_Source_Cap_Extended | | 0x00B154 |
| 9 | 0x12 Get_Status | | 0x00AE90 |
| 10 | 0x13 Get_PPS_Status | | 0x00AF50 |
| 11 | 0x14 Get_Country_Code | | 0x00B154 |
| 12 | 0x15 Get_Sink_Cap_Extended | | 0x00B154 |
| 13 | 0x16 Get_Source_Info | | 0x00AF72 |

Raw table bytes at 3.1.8 `0x00A9D8`:
`d0ae0000 90ae0000 54b10000 08af0000 54b10000 54b10000 54b10000 54b10000
 54b10000 90ae0000 50af0000 54b10000 54b10000 72af0000`

3.1.12: same function at entry `0x00AA10`, `subs r0,#9` at `0x00AA1A`, `cmp r0,#0xd` at
`0x00AA1C`, ADR at `0x00AA26`, table at `0x00AA2C`, identical shape
(targets shifted +0x54: 0x0AF24 0AEE4 0B1A8 0AF5C 0B1A8 ... 0AFC6).

**CONFIRMED:** Soft_Reset (0x0D) is *not* specially handled in 3.1.x — index 4 points at
`0x00B154`, the same shared handler used for 0x0B/0x0E/0x0F/0x10/0x11/0x14/0x15. That
handler begins `movs r0,#0; bl 0xa500; bl 0x6828` i.e. a generic state/timer reset, not a
dedicated soft-reset routine.

### 2c. CONFIRMED — that dispatcher is GONE in 3.2.0

- `subs r0, #9`: 2 occurrences in 3.1.8 (`0x005FFA`, `0x00A9C6`), 2 in 3.1.12, and
  **zero occurrences anywhere in 3.2.0** (grep `subs *r0, #9$` over the full linear
  disassembly).
- The 14-entry table at 0x00A9D8 has **no counterpart** in 3.2.0: the ADR-dispatch table
  inventory drops from 17 tables (3.1.8 and 3.1.12, identical lists) to **13 tables** in
  3.2.0. The 14-entry PD-message table is one of the four that disappear.
- `cmp rX,#0xd` sites: 10 in 3.1.8, 10 in 3.1.12, **9** in 3.2.0. The missing one is the
  `cmp r0,#0xd` at 3.1.8 `0x00A9C8` (the dispatch range check).

3.2.0 `cmp rX,#0xd` sites: `003f22 0051be 00538c 0068c2 00a326 00a40a 00c398 00d798 00db62`.
3.1.8: `003f32 00508a 00526a 0067da 00a2c0 00a3be 00a9c8 00c1a0 00d58c 00d918`.

### 2d. CONFIRMED — 3.2.0 gained two new dispatchers with no 3.1.x counterpart

New in 3.2.0 only (not in 3.1.8 or 3.1.12 at any address):

```
; site 0x004EDC, 15 entries, table 0x004EE4
004ece  c11e      subs  r1, r0, #3
004ed0  0224      movs  r4, #2
004ed2  0e29      cmp   r1, #0xe        ; indices 0..14  => selector value 3..17
004ed6  00d9      bls   #0x4eda
004eda  8900      lsls  r1, r1, #2
004edc  01a2      adr   r2, #4          ; table = 0x004EE4
004ede  5258      ldr   r2, [r2, r1]
004ee2  9746      mov   pc, r2
```
table 0x004EE4: `0550a 0551a 0554a 0552c 0554a 053ac 053ac 05504 05504 0554a 0554a 0554a 0554a 0553c 05542`

```
; site 0x005162, 13 entries, table 0x005168
005158  881e      subs  r0, r1, #2
00515a  0c28      cmp   r0, #0xc        ; indices 0..12  => selector value 2..14
00515e  91e0      b         #0x5284     ; (out of range)
005160  8000      lsls  r0, r0, #2
005162  01a1      adr   r1, #4          ; table = 0x005168
005164  0858      ldr   r0, [r1, r0]
005166  8746      mov   pc, r0
```
table 0x005168: `056a2 0561c 056da 056ee 05710 05704 05752 05704 05704 0576a 05704 05704 057c8`

The 15-entry range 3..17 spans 0x03 Accept .. 0x11 Get_Source_Cap_Extended and **includes
0x0D**. The 13-entry range 2..14 spans 0x02..0x0E and **also includes 0x0D**. Whether
either is a PD message dispatcher is **INFERRED, not proven** — the selectors are read
from bytes (`ldrb r0,[r0,#1]` for the 15-entry case) and I found no PD header masking
(`and #0x1f`, `>>5`) feeding them. They are, however, genuinely new control-flow in 3.2.0
covering the reset-message values.

Also new/changed in 3.2.0 near the reset path: `0x0051BC ldr r0,[sp,#0x2c]; cmp r0,#0xd;
bne` then an indirect vtable call with method index 0x13 (`ldr r3,[r0]; movs r1,#0x13;
blx r3`), and immediately above it the same object called with method index 0x14.

### 2e. CONFIRMED — SPM FSM hardreset state removed in 3.2.0

Byte-level comparison of the state-name pool (see 1e):

3.1.8 `0x0012D8C`: `696f 6e00 7370 6d5f 686f 7374 5f73 7263` = `ion\0spm_host_src`
3.1.8 `0x0012D94`: `5f68 6172 6472 6573 6574 0073 706d 5f68` = `_hardreset\0spm_h`
3.2.0 between `spm_host_src_in_contract\0` (ends 0x0012FE8) and
`spm_host_src_altmode_enumeration\0` (starts 0x0012FE8): the two strings are **adjacent**.
`spm_host_src_hardreset` does not exist anywhere in the 3.2.0 file
(`d.find(b'spm_host_src_hardreset\x00') == -1`).

State-name order also changed:

| 3.1.8 / 3.1.12 | 3.2.0 |
|---|---|
| charger_detached | charger_detached |
| host_detached | host_detached |
| host_src_altmode_enumeration | **host_src_in_contract** |
| **host_src_hardreset** | **host_src_altmode_enumeration** |
| host_src_in_contract | (no hardreset entry) |

A state-enumeration reorder plus deletion is a real, checkable behavioral difference in the
host/source negotiation FSM. It is consistent with "3.2.0 changed hard-reset handling", but
it is a *name-table* difference — **INFERRED**, not proof of what the code does differently.

### 2f. NOT FOUND — the escalation ladder

Explicitly searched for and **did not find**:

- any byte/word constant pair in which 0x0D and 0x01 are compared within one function to
  select a reset type (there are 9–10 `cmp #0xd` sites; none has a sibling `cmp #1`
  feeding a reset action);
- any retry counter (`ldrb` + `adds #1` + `strb` + `cmp #N`) whose overflow branch reaches a
  hard-reset/vSafe0V routine;
- no vSafe0V / tHardReset timing constant could be identified (no named PD timing constants
  survive in the image).

**Status: no soft-reset -> hard-reset escalation ladder was found. This is a negative
result, not an absence of effort.**

---

## Target 3 — power negotiation (PDO tables)

### 3a. Method and false-positive control

A naive scan "any 4-byte word that decodes as a plausible fixed PDO" returns **929 / 923 /
865** hits for the three images (nearly all are ordinary Thumb instructions). That scan is
useless and is not used as evidence. Instead I required a **run of >= 3 consecutive
4-byte-aligned words, each decoding as a fixed PDO with monotonically increasing voltage**
(2.5–30 V, 0.1–5 A). That yields 8 runs per image, of which one shape is the real table
(see 3b); the other runs are coincidental code.

### 3b. CONFIRMED — a 4-entry fixed PDO table, byte-identical in all three versions

Header bytes immediately before the table (all three images):
`03 07 01 01 01 01 01 00`

Table bytes, 3.1.8 at `0x00136E4` (also duplicated at `0x00137D4`):

```
000136d0: 0307 0101 0101 0100 0000 0000 0000 0000
000136e0: 0000 0000 2c91 0126 2cd1 0200 2cb1 0400
000136f0: 2c41 0600 0000 0000 0000 0000 0000 0000
00013700: 5a90 0126 5a30 429a 0000 0000 0000 0000
```

| offset | raw word | bits31:30 | V (50 mV) | A (10 mA) | decode |
|---|---|---|---|---|---|
| 0x136E4 | `0x2601912C` | 00 fixed | 100 | 300 | **5.00 V / 3.00 A** |
| 0x136E8 | `0x0002D12C` | 00 fixed | 180 | 300 | **9.00 V / 3.00 A** |
| 0x136EC | `0x0004B12C` | 00 fixed | 300 | 300 | **15.00 V / 3.00 A** |
| 0x136F0 | `0x0006412C` | 00 fixed | 400 | 300 | **20.00 V / 3.00 A** |

Decode shown is `V = ((w >> 10) & 0x3FF) * 50 mV`, `I = (w & 0x3FF) * 10 mA`, PDO type =
`w >> 30`. Only the 5 V entry carries capability flags (`0x26..` = bit29 Dual-Role Power
set, bit26 USB Communications Capable set, bit25 Dual-Role Data set); the 9/15/20 V entries
have bits31:16 clear.

Same table, other images (byte-for-byte identical values):

- 3.1.12: `0x0013764` and `0x0013854`
- 3.2.0:  `0x0013894` and `0x0013984`

Neighbouring words (same 32-byte record, all versions): `0x2601905A` decodes as
5.00 V / 0.90 A, and `0x9A42305A` has bits31:30 = `10`, i.e. an **Augmented** PDO (PPS),
not a fixed one.

**Verdict: the advertised fixed-PDO set is 5/9/15/20 V at 3.00 A and it did not change
between 3.1.8, 3.1.12 and 3.2.0.**

### 3c. CONFIRMED NEGATIVE — no 20 V / 3.39 A operating point

Searched for the 70 W point exactly as specified (20 V = 400 = 0x190 in 50 mV units,
3.39 A = 339 = 0x153 in 10 mA units), i.e. word `0x00064153` / `0x??64153` and the byte
sequence `53 41 06`:

| search | 3.1.8 | 3.1.12 | 3.2.0 |
|---|---|---|---|
| 4-aligned word with `(w & 0x3FFFFF) == 0x00064153` | 0 | 0 | 0 |
| byte sequence `53 41 06` (any offset) | 0 | 0 | 0 |
| any fixed PDO word with current field == 0x153 | 1 (`0x2800FD53` @0x0F4FC, 3.15 V) | 0 | 0 |

The single 3.1.8 hit `0x2800FD53` decodes as 3.15 V / 3.39 A — a 3 V rail, not the 20 V
point, and it is absent from both later images. **There is no 20 V / 3.39 A / 70 W PDO in
any of the three images.** The only 20 V entry present is 20.00 V / 3.00 A (= 60 W).

### 3d. Caveat on the PDO table's use

No 32-bit pointer anywhere in any image equals the table address or its header
(`find_word` for 0x136D0 / 0x136E4 / 0x137D4 in 3.1.8, and the equivalents in the other
two: all empty). The blob is therefore reached by offset from a base structure, or read by
the bootloader — **the bytes and decode are CONFIRMED; "this table drives PD
source-capability advertisement" is INFERRED** from its exact 5/9/15/20 V ladder and the
adjacent PPS word.

---

## Target 4 — version / build / hardware-revision strings

### 4a. Answer up front: there is no literal version or build string

The images contain **no** ASCII build number, no "3.1.8"/"3.1.12"/"3.2.0", no "10M569" /
"10M1543" / "10M13722", no "A2363", no protocol-version string, and no date stamp. Searched
with `strings -n 4` plus regex filters (`^[0-9]+\.[0-9]+`, `10M[0-9]+`, `A2363`, `MagSafe`,
`USB-C`, `Apple`, `v?[0-9]\.[0-9]`) across all three files: the only hits are the three
literal tokens `Apple Inc.USB-C to MagSafe 3 Cable (2 m)`, `Cypress`, `xApple`.

Versioning is **numeric and assembled at runtime**:

- `0x0012EE5` (3.1.8) / `0x0012F65` (3.1.12) / `0x001312B` (3.2.0):
  format string **`%s%d.%d.%d`**
- `0x0012F21` / `0x0012FA1` / `0x0013166`: **`"FWVersion": %u,`**
- `0x0012F32` / `0x0012FB2` / `0x0013177`: **`"HWVersion": %u,`**

So the firmware reports FW/HW versions as *integers* at runtime; the human-readable
`3.2.0` is produced by `%s%d.%d.%d` from those fields, not stored.

### 4b. CONFIRMED — full human-readable string inventory (3.2.0, offsets exact)

Kernel / fault block (`0x0012E64`–`0x0012F9B`), identical text in all three images
(only the base offset shifts):

| offset | string |
|---|---|
| 0x12E64 | `Unsupported: '%c'` |
| 0x12E76 | `0123456789ABCDEF` |
| 0x12E87 | `0123456789abcdef` |
| 0x12E98 | `Machine stack fault exception:` |
| 0x12EB8 | `  Thread function address: ` |
| 0x12ED7 | `Machine hard fault exception:` |
| 0x12EF6 | `  Kernel mode` |
| 0x12F05 | `Thread: ` |
| 0x12F0E | `    Stacked SP: ` |
| 0x12F33 | `dumping core...` |
| 0x12F49 | `Watchdog` |
| 0x12F53 | `Attempt to ready null task` |
| 0x12F6E | `Thread table exhausted.` |
| 0x12F86 | `Kernel panic: ` |
| 0x12F95 | `Lock fault` |

FSM / subsystem name pool (`0x0012FA0`–`0x0013130`), 3.2.0:

| offset | string |
|---|---|
| 0x12FA0 | `SPM FSM` |
| 0x12FA8 | `spm_charger_detached` |
| 0x12FBD | `spm_host_detached` |
| 0x12FCF | `spm_host_src_in_contract` |
| 0x12FE8 | `spm_host_src_altmode_enumeration` |
| 0x13009 | `apple_uvdm_state_disabled` |
| 0x13023 | `apple_uvdm_state_dfp_enumerate` |
| 0x13042 | `apple_uvdm_ufp_enumerate_start` |
| 0x13061 | `apple_uvdm_ufp_enumerate_end` |
| 0x1307E | `apple_uvdm_state_operation` |
| 0x13099 | `uvdm fsm` |
| 0x130A2 | `Failed to allocate timer` |
| 0x130BB | `Failed to allocate ntimer` |
| 0x130D5 | `cm_host_detached` |
| 0x130E6 | `cm_host_rd_poll` |
| 0x130F6 | `cm_host_rd_detected` |
| 0x1310A | `cm_host_present` |
| 0x1311A | `cm_sleep` |
| 0x13123 | `cm fsm` |
| 0x1312B | `%s%d.%d.%d` |

Analytics JSON template (`0x0013138`–`0x0013236`), 3.2.0 — this is the telemetry payload the
cable builds, and it is the best description of what the firmware monitors:

```
0x13138  "com.apple.ChargingCable.connectAnalytics": {
0x13166  "FWVersion": %u,
0x13177  "HWVersion": %u,
0x13188  "HostConnectCount": %u,
0x131a0  "CorrosionPrevention": %u,
0x131bb  "ChgCLMVoltFault": %u,
0x131d2  "OverTempFault": %u,
0x131e8  "OverVoltCLMCmd": %u,
0x131fd  "VoltDiffFault": %u,
0x13212  "HardFault": %u,
0x13223  "OtherFault": %u}}
```

Identity / descriptor tokens:

| token | 3.1.8 | 3.1.12 | 3.2.0 |
|---|---|---|---|
| `xApple` | 0x135A3 | 0x13623 | 0x13767 |
| `Cypress` | 0x13888 | 0x13908 | 0x13A38 |
| `Apple Inc.USB-C to MagSafe 3 Cable (2 m)` | 0x13B91 | 0x13C11 | 0x13DE1 |

The product string is plain ASCII, **not** UTF-16LE (searched `d.find(t.encode('utf-16-le'))`
-> -1 in all three), so it is a config/metadata string, not a USB string descriptor.

### 4c. CONFIRMED — version-adjacent metadata is byte-identical

The Cypress firmware-metadata record is identical in all three builds:

```
3.1.8  @0x13888:  b404 d0f6 4379 7072 6573 7300 1400 0000 4180 00ff b404 0080
                  0000 0000 0000 d0f6 0414 0a02 0814 0a02 3201 0000
3.1.12 @0x13908:  (identical bytes)
3.2.0  @0x13a38:  (identical bytes)
```

So none of the `0x0414 0a02` / `0x0814 0a02` / `0x0132` fields distinguish the three
releases — the version difference is not recorded in a readable flash field I could locate.

### 4d. CONFIRMED — the one genuine string difference between releases

`spm_host_src_hardreset` (exact bytes `73 70 6d 5f 68 6f 73 74 5f 73 72 63 5f 68 61 72 64
72 65 73 65 74 00`):

| | present | offset |
|---|---|---|
| 3.1.8 | YES | 0x0012D94 |
| 3.1.12 | YES | 0x0012E14 |
| 3.2.0 | **NO** | `d.find(b'spm_host_src_hardreset\x00') == -1` |

Every other human-readable string is present in all three releases; the only additions in
3.2.0 are the reordering noted in 2e plus noise from code bytes. Full set-difference of
"real text" runs (>=5 printable chars, >=2 lowercase letters) between 3.1.12 and 3.2.0
yields exactly one meaningful removal: `spm_host_src_hardreset`. Everything else in that
diff is Thumb instruction bytes that happen to be printable.

---

## Summary — verdict per target

| target | verdict |
|---|---|
| **1. USB-PD / VDM** | **PARTIAL.** No `VDM`/`VDMs` marker and no PD message-type table (all searches 0 hits). But Apple SVID **0x05AC appears in 12 literal-pool constants** per image, and a confirmed UVDM tx builder at `0x00C2B8` selects 0/1/2 VDOs by port state and pushes `0x05AC8106`+`0x05AC0005`. One constant changed in 3.2.0 (`0x05AC0002` -> `0x05AC0000`). 33-entry code-pointer table exists but is unreferenced — **not** established as a PD dispatch table. |
| **2. reset handling** | **PARTIAL, with a real structural change.** A genuine PD control-message dispatcher exists in 3.1.x (`subs r0,#9` / `cmp r0,#0xd`, 14-entry table at `0x00A9D8`, types 9–22, Soft_Reset 0x0D -> shared handler `0x00B154`) and is **absent in 3.2.0**; 3.2.0 instead has two new dispatchers (15- and 13-entry) covering value ranges that include 0x0D. `spm_host_src_hardreset` state removed in 3.2.0. **No soft->hard escalation ladder found** — negative result. Also: the claim's premise "Hard_Reset = 0x01" is wrong (0x01 is GoodCRC; Hard Reset has no MessageType). |
| **3. power negotiation** | **FOUND, and unchanged.** One real fixed-PDO table: **5.00 / 9.00 / 15.00 / 20.00 V at 3.00 A**, byte-identical in all three builds (3.1.8 `0x136E4` + dup `0x137D4`). **No 20 V / 3.39 A / 70 W point exists** in any image. |
| **4. version/build strings** | **NEGATIVE for literal versions, POSITIVE for inventory.** No ASCII build/version/hardware-revision string anywhere; versions are numeric via `"FWVersion": %u` and rendered by `%s%d.%d.%d`. Full string inventory captured above; only cross-release string diff is the removed `spm_host_src_hardreset`. |

Net assessment of the third-party claim ("3.2.0 changed hard-reset handling, soft-reset
escalation, and power negotiation"):

- **hard-reset handling changed** — *supported* by two independent confirmed facts (state
  name removed + state order changed; PD dispatcher replaced). Not proven at instruction
  semantics level.
- **soft-reset escalation changed** — *not supported*; no escalation ladder exists in any
  of the three images, so there was nothing to change.
- **power negotiation changed** — *not supported*; the only PDO table in the images is
  byte-identical across 3.1.8, 3.1.12 and 3.2.0.

## Reproducing

```
cd <artifact-root>/evidence/magsafe-behavior
<home>/.hermes/cache/scratch/reaenv/bin/python tools/dis_all.py <image>.bin > raw/<image>.dis.txt
npx -y rea-agents@6.7.0 --help        # rea CLI, standalone (no MCP binding touched)
```

`raw/` contains the strings dumps (`*.strings.txt`) and annotated linear disassemblies
(`*.dis.txt`) for all three images. Inputs were opened read-only; nothing under
`firmware/images/` was modified.


