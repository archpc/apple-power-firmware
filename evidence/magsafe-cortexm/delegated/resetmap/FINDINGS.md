# RESET HANDLING AND MESSAGE-TYPE SEMANTICS — static, three builds (A2363 MagSafe 3)

Scope: 3.1.8 (`A2363_3.1.8_10M569_base0.bin`, 83,464 B), 3.1.12
(`A2363_3.1.12_10M1543_base0.bin`, 83,592 B), 3.2.0
(`A2363_3.2.0_10M13722_base0.bin`, 84,048 B). Flat base0 images; **addresses below
are file offsets**, as everywhere else in this dossier. No device was touched.

Tooling: `rizin 0.9.1` with `e asm.arch=arm; e asm.bits=16` (Thumb decode) for all
disassembly quoted here; cross-checks against the seeded Ghidra decompilations in
`evidence/magsafe-cortexm/decomp3_318/` and
`delegated/xversion/decomp3_{3112,320}/`. Raw captures: `tables.txt` (same dir).

Labels: **OBSERVED** = instruction/byte verified in the image by me in this pass.
**INFERRED** = reading of those bytes not proven by a naming constant.
**OPEN** = not decidable from the image alone.

---

## 0. Message-type numbering used (verified, not assumed)

USB-PD control-message types, confirmed against `include/linux/usb/pd.h`
(`PD_CTRL_*` enum) during this pass:

| # | type | # | type |
|---|---|---|---|
| 1 | GoodCRC | 12 | Wait |
| 2 | GotoMin | 13 | **Soft_Reset** |
| 3 | **Accept** | 14 | Data_Reset |
| 4 | Reject | 15 | Data_Reset_Complete |
| 5 | Ping | 16 | Not_Supported |
| 6 | PS_RDY | 17 | Get_Source_Cap_Ext |
| 7 | Get_Source_Cap | 18 | Get_Status |
| 8 | Get_Sink_Cap | 19 | FR_Swap |
| 9 | DR_Swap | 20 | Get_PPS_Status |
| 10 | PR_Swap | 21 | Get_Country_Codes |
| 11 | VCONN_Swap | 22 | Get_Sink_Cap_Ext |
|  |  | 24 | Get_Revision (PD3.1) |

The 3.1.x outer table's guard `subs r0,#9; cmp r0,#0xd` ⇒ types 9–22 map onto
DR_Swap…Get_Sink_Cap_Ext **exactly**, which is the strongest single argument that
this table is a PD control-type dispatch (the range endpoints align with the
spec's contiguous control block, 13 = Soft_Reset lands inside it). Type numbering
beyond 22 (0x28=40, 0x3d=61, 0x41=65) cannot be a PD control type — PD control
types stop at 22 (24 in PD3.1).

---

## 1. Soft_Reset (item 1) — the "dominant target" is the switch default, not a handler

### 1.1 Table decode (OBSERVED)

3.1.8 table `0xa9d8`, 14 words, verbatim:

```
0xa9d8  aed0 ae90 b154 af08   b154 b154 b154 b154
0xa9e8  b154 ae90 af50 b154   b154 af72 d0002c01
```

`0xd0002c01` is the 14th slot's neighbour data, not a pointer (as previously
recorded). Entry index = type − 9:

| type | 9 | 10 | 11 | 12 | **13** | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| target | aed0 | ae90 | **b154** | af08 | **b154** | **b154** | **b154** | **b154** | **b154** | ae90 | af50 | **b154** | **b154** | af72 |

`0xb154` is taken by 8 of 14 types (11, **13**, 14, 15, 16, 17, 20, 21). In the
decompiled body those 8 types are literally the `default:` arm of the C switch
(`f_a9bc.c` line 33), i.e. **0xb154 is the dispatcher's default/fallthrough
target, not a per-type handler.** Consequence, and this is the load-bearing
correction to the premise: the table contains **no Soft_Reset-specific code
path at all**. Type 13 is indistinguishable in the table from types 11/14/15/16/
17/20/21. (OBSERVED)

3.1.12 is the same shape: entry `0xaa10`, guard `subs r0,#9; cmp r0,#0xd`,
table `0xaa2c` = `af24 aee4 b1a8 af5c` `b1a8 ×5` `aee4 afa4 b1a8` `b1a8 afc6 d0002c01`,
i.e. the same 8 entries pointing at `0xb1a8`,
which is the 3.1.8 `0xb154` fragment shifted +0x54, instruction-for-instruction
(`movs r0,0; bl 0xa554; bl 0x6828; ldr r5,[sp,8]; …`). Case grouping and
callee deltas are unchanged. (OBSERVED)

### 1.2 What `0xb154` actually does (OBSERVED, decode)

```
b154  movs r0, #0
b156  bl   0xa500          ; FUN_0000a500(0)
b15a  bl   0x6828          ; -> 0x31a0(1, 0x10)
b15e  ldr  r5, [sp, #8]
b160  b    0xb17a
b17a  movs r0, #0x55
b17c  strb r5, [r4, #0x55]     ; r4 = param_1 (port arg)
b17e  ldr  r0, [sp, #0xc]
b180  str  r0, [r7, #0x5c]     ; r7 = 0x20001a10
b182  add  sp, #0x24
b184  pop  {r4, r5, r6, r7, pc}
```

Memory-level meaning of the three callees:

- `FUN_0000a500(0)` — source-capability rebuild. It reads a PDO/APDO array
  (`[0x20000ce4+0x118]+0x11c`, VDO count from the header word or byte), runs the
  selection loop over `FUN_0000a4c0` (per-PDO decode), and installs the result
  with `FUN_00002a60(1, buf)` → **copies 7 words (28 B) to `0x200002b0+0x268`
  and stores the count at `+0x1d6`**. 28 B = one PD Source_Capabilities payload
  without header. (Struct/size/address OBSERVED; "this is the Source_Caps
  buffer" INFERRED, high confidence.)
- `FUN_00006828` → `FUN_000031a0(1, 0x10)`: writes **0x10 into the per-port
  state byte `0x200002b0 + port*0x1cc + 0x45`**, calls `0xc838(port, 9)`
  (a keyed `u16` lookup of `(port<<8)|id` over a 32-entry table at
  `0x200019a4` — a timer-id registry), then `0x2ce4(port,0x100)` = **BIC** on
  the event word at `port+0x48` and `0x2908(port,4)` = **OR 4** on the same word
  (both via the IRQ-masked `0x8da2`/`0x8d88` primitives). (OBSERVED)
- two stores of `[sp,#8]` and `[sp,#0xc]`.

So the default arm = *recompute source caps → install → set port state 0x10 →
clear event bit 0x100, set event bit 4*. There is **no transmit call in this arm
at all** (no `bl 0xb73c`, the message-send wrapper), **no timer arm**, **no write
to any CC/PHY register**. For a Source receiving Soft_Reset the spec-mandated
reply is *Accept then Source_Capabilities*; the caps half is present, the Accept
half is not.

### 1.3 Two structural anomalies in the same arm (OBSERVED bytes, INFERRED reading)

1. **Frame mismatch.** The dispatcher allocates `push {r4,r5,r6,r7,lr}` (0x14) +
   `sub sp,#0x1c` = **0x30**. `0xb154`'s tail frees `add sp,#0x24` + `pop`
   of 5 words (0x14) = **0x38**. Entering `0xb154` by `mov pc,r0` from `0xa9d6`
   therefore over-pops by 8 bytes and returns to the wrong address.
2. **Uninitialised locals.** `[sp,#8]` and `[sp,#0xc]` lie inside the dispatcher's
   own 0x1c-byte frame, which on the table path is never written before the jump
   (the only sp writes between entry and `mov pc,r0` are the push and the `sub`).
   The arm stores those slots into `param_1+0x55` and `0x20001a10+0x5c`.
   Ghidra names them `local_28`/`local_24`; its inlined copy of the same code
   shows the same uninitialised use.
3. Even addresses in the table. All 14 entries are even and dispatch is
   `mov pc, r0`; on ARMv7-M a direct write of an even address to PC is an
   INVSTATE fault. A live M-profile build would store `target|1` or use `tbb`
   (3.2.0's second stage does use a table, `ldrh`-indexed).

All three say the same thing: `0xb154` is a **fragment of a differently-compiled
function left in the table**, and the "dominant target" is not a live Soft_Reset
handler. This is consistent with, and adds a third independent reason for, the
§11b/§12a **liveness OPEN** verdict on island `0xa9bc..0xb1a3`. It does not
*prove* deadness (the callback/vtable installation path is unobservable).

### 1.4 Soft-Accept / Soft-Reset sequence, and soft→hard escalation

Searched for, in both 3.1.x images, across the analysed function set plus the
surrounding coherent-code region:

- a transmit of type 3 (Accept) as an immediate argument to the send wrapper
  `0xb73c(port, type, …)`: **not found**.
- a sequence "send Accept → arm timer → reset protocol state": **not found**.
  `0xb73c` does arm a timer (`FUN_00001178(0x7530, 0, 0x2da1, 0)` = 30,000 ticks,
  id 0x2da1) around a queue call, but that is the per-transmit timeout of the
  sender, not a soft-reset escalation.
- a timer-expiry path that writes a CC/PHY control register or a hard-reset state:
  **not found**. The timer machinery is `0x1178` (arm) / `0xa450` (release) over
  the tables at `0x20000190` and `0x20000ce4`, IRQ-masked with `cpsid i`; the
  callbacks are function pointers installed at run time and none of the static
  sites reachable from the dispatcher island point at a register-touching body.

Verdict item 1: **Soft_Reset is not decoded as a distinct behaviour (OBSERVED);
no soft-Accept→Soft-Reset sequence exists in the decoded code (OBSERVED absence,
scoped to the analysed set); soft→hard escalation is OPEN — bounded negative, no
positive evidence either way.** The one positive hint that 3.1.x *has* a
hard-reset state concept is the FSM name in §2.

---

## 2. Hard_Reset / Hard_Signaled (item 2)

### 2.1 OBSERVED, new, and the strongest datum in this section

A debug state-name pool exists in both 3.1.x images. 3.1.8 at `0x12d3c`:

```
"SPM FSM"
spm_charger_detached
spm_host_detached
spm_host_src_altmode_enumeration
spm_host_src_hardreset          <-- 0x12d94 (3.1.8), 0x12e14 (3.1.12)
spm_host_src_in_contract
apple_uvdm_state_disabled / _dfp_enumerate / _ufp_enumerate_end / _state_operation
uvdm fsm
"Failed to allocate timer" / "Failed to allocate ntimer"
cm_host_detached / cm_host_rd_poll / cm_host_rd_detected / cm_host_present / cm_sleep
cm fsm
```

**`spm_host_src_hardreset` is absent from 3.2.0.** 3.2.0's pool at `0x12fa0`
holds only four SPM states, and in a different order:

```
"SPM FSM"
spm_charger_detached
spm_host_detached
spm_host_src_in_contract
spm_host_src_altmode_enumeration
```

So: 3.1.8 and 3.1.12 carry an FSM state literally named *host source hard reset*;
3.2.0 removed that state (or renamed it away) while keeping the pool and the other
states. (OBSERVED strings, both directions; the state's *numeric* value is not
recovered.)

Caveat on liveness (OPEN): I found **no absolute-pointer reference** to any string
in that 3.1.8 block (0x12c00–0x13000) anywhere in the image, including `"SPM FSM"`
itself; the same holds for 3.2.0's block. Consistent with a relative-offset name
table, with a name-lookup built at run time, or with the block being a duplicated/
stale copy. Given §11e already documents a duplicated-string/AI-offset landscape,
I do **not** claim the name is consumed by live code.

### 2.2 Negatives (OBSERVED)

- No `vSafe0V`, `vSafe`, `VBUS`, `TCPC`, `CC1`, `CC2`, `PHY` string in *any* of the
  three images. Full-text scan of the printable-string set: the only PD-adjacent
  names are the FSM states above (`spm_charger_detached`, `spm_host_detached`,
  `spm_host_src_in_contract`, `cm_host_detached`).
- No constant run, no Rp/Rp CC-toggle sequence, and no PHY/control-register write
  was found in the region reachable from the dispatcher island. A frequency scan
  of 32-bit words in `0x40000000..0x5fffffff` is dominated by code words
  (`0x46c04770` = `bx lr; nop`, etc.), i.e. no MMIO base is used often enough to
  name a peripheral from literals; a peripheral-literal census is not a usable
  handle on this image. (Method note, so nobody re-runs it expecting a result.)

Verdict item 2: **Hard_Reset handling exists only as a state *name* in 3.1.x
(OBSERVED), removed in 3.2.0 (OBSERVED). The code that would signal a hard reset
— CC toggle, PHY control write, vSafe0V transition — is not identified anywhere
in the three images: OPEN.** Do not read the string as proof of a functional
hard-reset path.

---

## 3. 3.2.0 unmatched switches vs the 3.1.x 9–22 dispatcher (item 3)

### 3.1 Per-switch decode (all OBSERVED)

| | `0x4b78` | `0x50fc` | `0x4eca` | 3.1.8 `0xa9bc` |
|---|---|---|---|---|
| index source | **arg r1** (`subs r0,r1,#2; cmp r0,#7; bls`) | **arg r1** (`subs r0,r1,#2; cmp r0,#0xc; bls`) | **`[[r0]]+1`** — byte inside a pointed-to struct | **arg r1** (`subs r0,r1,#9; cmp r0,#0xd`) |
| span | 2–9 (8 cases) | 2–14 (13 cases) | 3–17 (15 cases) | 9–22 (14 cases) |
| table | `0x4b94` (word) | `0x5168` (word) | `0x4ee4` (word) | `0xa9d8` (word) |
| unique targets | 5 | 8 | 8 | 6 |
| dominant target / share | `0x5574` 4/8 | `0x5704` 6/13 | `0x554a` 6/15 | `0xb154` 8/14 |
| port struct | `0x200002a8` + `0x73*4` | `0x20000644` + `0xf0*port` | — | `0x200002b0` + `0x1cc*port` |
| BL callers in image | none | none | none | none |

Table contents verbatim (indices = type − low bound), see `tables.txt`:

- `0x4b94`: `5034 5574 5574 5574 5076 5574 50ae 50d0`
- `0x5168`: `56a2 561c 56da 56ee 5710 5704 5752 5704 5704 5704 576a 5704 5704`
- `0x4ee4`: `550a 551a 554a 552c 554a 53ac 53ac 5504 5504 554a 554a 554a 554a 553c 5542`

`0x50fc` shape is the closest analogue to the 3.1.x outer table: 13–14 cases,
6–8 unique targets, one dominant arm ≈ 50 % of the range, and it is the only one
of the three that takes `(port, type)` with a `0xf0`-stride port object the way
`0x31a0`/`0x6828` do elsewhere in 3.2.0. But its range is shifted: 2–14, not 9–22.

### 3.2 Did 3.2.0 SPLIT the 9–22 dispatcher into control + data switches?

Evidence against the split hypothesis, per switch:

- **`0x4b78` (2–9).** Under PD numbering 2–9 = GotoMin…DR_Swap. That is not a
  partition member of 9–22; it *starts below 9*. A control/data split of 9–22
  would have to start at 9. Its dominant arm `0x5574` is outside the switch body
  itself (`mov r0,r4; bl 0x5b5c` then a bounds compare), i.e. a shared
  copy/"other" tail, not a message handler.
- **`0x50fc` (2–14).** Same objection: starts at 2. Its case set includes 3
  (Accept) and 13 (Soft_Reset), which are exactly the two types a *split-out
  control* switch would want — but it also covers 2 and 4–14 inclusive, and the
  pre-switch code at `0x5136` special-cases `type == 2` against
  `port[0x10] == 2` first, which reads like an event/role guard, not a message
  dispatch.
- **`0x4eca` (3–17).** Its index is **not an argument** but a byte read out of a
  pointed-to object (`ldr r0,[r0]; ldrb r0,[r0,1]`). A dispatcher whose index
  comes from a struct byte is dispatching on *stored message state*, not on a
  received header — plausibly "replay the cached message type" after a queue pop.
  Under PD numbering 3–17 spans Accept…Get_Source_Cap_Ext, i.e. it crosses the
  control/data boundary rather than splitting it.

Conclusion (INFERRED, medium confidence): **"3.2.0 split the 9–22 dispatcher into
a data-message switch plus a control-message switch" is NOT supported.** None of
the three spans is a partition of 9–22; two of them start at 2 and the third
crosses the 15/16 control-data boundary. The better-supported reading is three
independent handlers in different layers (a port-level type handler, an
object-level type handler, and a cached-message re-dispatch), each with its own
internal numbering. Whether any of them *replaces* the 9–22 table's function is
**OPEN** — note the callee-overlap figures already recorded (1/19, 1/20, 1/12)
and that none of the four switching entries has a single `bl` caller in the image
(`bl_xref_320.json`: absent for `0x4b78`, `0x50fc`, `0x4eca`, `0xab64`), so all
are reached by pointer — the same liveness shadow that hangs over 3.1.x.

---

## 4. Out-of-table cases 2, 3, 0x28, 0x3d, 0x41 in 3.1.x (item 4)

Reached by a compare chain after the table's `bhi 0xaa1c` (3.1.8), all at
`0xaa1c..0xad28`. Bodies at instruction level:

| type | guard | body (memory-level) |
|---|---|---|
| **3** (Accept) | none | `FUN_00009df8()`; `FUN_00001fa0()`; `FUN_00007be4(1,0)`; `FUN_00007be4(1,1)` — the last two OR/AND a mask word (`0xfdffffff` / `0xfeffffff`) into a table at `0x13898`, i.e. clear one bit each in two mask words; then `if (*(0x20001854+0x14))` → clear that flag, `FUN_0000955c()`, `FUN_00001178(DAT_af28,0,DAT_af30,0)` = **arm a timer** |
| **2** (GotoMin) | none | `FUN_00001178(DAT_ad94,0,DAT_ad98,0)` = **arm a timer**; then `FUN_0000a450(DAT_ad90)` = **release/detach that timer slot** |
| **0x28** | `param_1 == 1` | `if (!*(0x20001854+0x14)) FUN_0000d904(0)` (the large handler); set `0x20001854+0x14 = 1` (one-shot latch); `FUN_00009e74()`; `*(DAT_af34+0x34) = 2` (state byte := 2); `FUN_0000a450(DAT_af14+6)` |
| **0x3d** | `param_1 == 0` | `FUN_000031a0(1, 0x29)` → **port-1 state byte := 0x29 (41)** + `0xc838(1,9)` + event bits `~0x100`/`|4` |
| **0x41** | `*param_3 == 0` | `memset(0x20001a10+0x28, 0, 0x2c)` (clears a 44-byte sub-record); `*(…+0x34) = 0x1e` (state := 30); then the **second-stage switch** on `*(param_3+2)` (`0xad2a`, 17 cases span 8–24) |

Readings (INFERRED, no constant names any of them):

- **2 and 3** carry PD type *numbers* but their bodies are timer arm/release and
  mask-bit clears — internal scheduling, not message semantics. A PD message
  handler that receives GotoMin and only re-arms a timer is possible for a Source
  (GotoMin → reduce to vSafe5V), but nothing in the body touches a PDO, a
  voltage, or a transmit. I read them as **internal event codes that happen to be
  numbered 2 and 3**, not as PD types. Medium confidence.
- **0x28, 0x3d, 0x41** are outside PD's control-type range (≤ 22, ≤ 24 in 3.1) and
  each writes a *state byte* (2, 0x29, 0x1e) or clears a structure. These are
  **device-specific control codes** (INFERRED, high confidence on the range
  argument alone).
- The guards `param_1 == 1` / `param_1 == 0` treat the first argument as a **port
  index**, while the 9–22 arms use the same register both as a port index
  (`0x200002b0 + param_1*0x1cc`) and as a pointer (`param_1[0x18]`). Both usages
  cannot hold simultaneously; that inconsistency is one more sign this island's
  decompilation is not a coherent live function, and I do **not** build any claim
  on the argument's type beyond "small index in the out-of-table arms".

---

## 5. What a CC capture would settle

Only wire-level evidence can close the reset question; none of the three images
is reachable statically (§11b, §12a, and §3.2 above all say the same). A single
saleae/PhyWhisper capture of the MagSafe CC line during a forced reset would
settle:

1. **Whether a Soft_Reset is ever emitted or answered.** SOP traffic containing
   control type 13 and, within tSoftReset-ish, a type-3 Accept from the adapter
   plus a fresh Source_Capabilities — that would prove the caps-rebuild arm in
   §1.2 is the Soft_Reset reply and that the Accept is sent by code we have not
   found (or not at all).
2. **Whether soft→hard escalation exists at all.** After a Soft_Reset that is not
   Accepted, a PD hard reset appears on CC as a ~**Rp/Rp (or Rd/Rd) both-ends
   drive for tHardReset ≈ 5 ms** followed by a re-attach and a fresh
   Source_Capabilities. Seeing that pattern *after* an unanswered Soft_Reset is
   the only direct proof of the escalation path that item 1 leaves OPEN; not
   seeing it, across repeated resets, bounds the design as "soft reset only".
3. **Which of the 3.2.0 switches is the message-type dispatcher.** A capture that
   exercises each control type 2–22 in turn, correlated with the state byte
   written at `port+0x45` (`0x45` offsets observed in §1.2/§3), would map
   type → arm empirically and resolve the split question in §3.2 without further
   static work.
4. **whether 3.2.0 still handles GotoMin/hard-reset at all** — the state name
   `spm_host_src_hardreset` is gone from 3.2.0 (§2.1); a capture of a 3.2.0 unit
   under a hard-reset stimulus distinguishes "state renamed" from "feature
   removed".

---

## 6. Claim register

| # | claim | label |
|---|---|---|
| 1 | 3.1.8 `0xa9d8` has 14 entries; 8 point at `0xb154`; 13 → `0xb154` | OBSERVED |
| 2 | `0xb154` is the C `default:` arm, not a case-13 handler | OBSERVED |
| 3 | `0xb154` body = caps rebuild + state 0x10 + event bits `~0x100`,`|4`; no transmit, no timer, no register write | OBSERVED |
| 4 | `0xb154` returns through a 0x38-byte epilogue against a 0x30-byte frame, and stores two never-initialised slots | OBSERVED (bytes) / INFERRED (corruption) |
| 5 | Same structure in 3.1.12 (`0xaa10`/`0xaa2c`/`0xb1a8`), +0x54 shift | OBSERVED |
| 6 | No transmit of Accept and no timer→hard-reset path found in decoded 3.1.x | OBSERVED absence (scoped) |
| 7 | soft→hard escalation exists | **OPEN** (bounded negative) |
| 8 | `spm_host_src_hardreset` state name exists in 3.1.8 + 3.1.12, absent in 3.2.0 | OBSERVED |
| 9 | that name is consumed by live code | **OPEN** (no absolute-pointer xref) |
| 10 | hard-reset signalling code (CC toggle / vSafe0V / PHY write) identified | **OPEN — not found** |
| 11 | 3.2.0 spans 2–9 / 2–14 / 3–17 with dominant shares 4/8, 6/13, 6/15 | OBSERVED |
| 12 | 3.2.0 split the 9–22 dispatcher into control+data switches | **not supported** (INFERRED against) |
| 13 | 2 / 3 are PD types; 0x28 / 0x3d / 0x41 are device-specific codes | INFERRED |
| 14 | none of `0x4b78`/`0x50fc`/`0x4eca`/`0xab64` has a BL caller | OBSERVED |
