# resetmap — reset handling & message-type semantics, static pass

Scope: 3.1.8 / 3.1.12 / 3.2.0 A2363 images, flat base0, addresses = file offsets.
Tooling: rizin 0.9.1 Thumb (`e asm.arch=arm; e asm.bits=16`); cross-checked against
`decomp3_318/` and `delegated/xversion/decomp3_{3112,320}/`. No device commands.
Full write-up + claim register: `resetmap/FINDINGS.md`; raw captures:
`resetmap/tables.txt`.

Step log (steps were batched, findings recorded here in order):

**S1 — numbering.** Verified the PD control-type enum against
`include/linux/usb/pd.h` (fetched this pass), not memory: 1 GoodCRC, 2 GotoMin,
3 Accept, 4 Reject, 5 Ping, 6 PS_RDY, 7 Get_Source_Cap, 8 Get_Sink_Cap,
9 DR_Swap, 10 PR_Swap, 11 VCONN_Swap, 12 Wait, **13 Soft_Reset**, 14 Data_Reset,
15 Data_Reset_Complete, 16 Not_Supported, 17 Get_Source_Cap_Ext, 18 Get_Status,
19 FR_Swap, 20 Get_PPS_Status, 21 Get_Country_Codes, 22 Get_Sink_Cap_Ext,
24 Get_Revision. So 9–22 is exactly the contiguous control block ⇒ the 3.1.x
outer table's guard `subs #9; cmp #0xd` is a plausible control-type dispatch.
OBSERVED (enum) / INFERRED (the mapping).

**S2 — 3.1.8 table + the 0xb154 arm.** Table `0xa9d8` re-read: 14 words,
`b154` in 8 slots (types 11, 13, 14, 15, 16, 17, 20, 21). `0xb154` is the C
`default:` arm, not a case-13 handler ⇒ **no Soft_Reset-specific code path
exists in the table**. Body decode: `FUN_0000a500(0)` rebuilds + installs the
7-word (28 B) source-capability buffer at `0x200002b0+0x268`; `0x6828` →
`0x31a0(1,0x10)` sets per-port state byte `port+0x45 := 0x10`, keyed
`(port<<8)|9` timer lookup, event word `port+0x48` := `~0x100`, `|4`; then two
stores and return. No transmit, no timer arm, no CC/PHY write. OBSERVED.

**S3 — arm integrity.** Frame arithmetic: dispatcher frame 0x30 (0x14 push +
0x1c sub); `0xb154` epilogue frees 0x38 (`add sp,#0x24` + 5-reg pop) ⇒ +8 B
over-pop if entered by `mov pc`. It also stores `[sp,#8]`/`[sp,#0xc]`, slots the
dispatcher never writes on that path (uninitialised locals). All 14 table entries
are even while dispatch is `mov pc,r0` (INVSTATE on ARMv7-M). Three independent
signs the arm is a foreign fragment ⇒ adds to the §11b/§12a liveness OPEN.
OBSERVED bytes / INFERRED consequence.

**S4 — 3.1.12 counterpart.** `0xaa10`, table `0xaa2c`, same guard, same 8-slot
`0xb1a8` arm, instruction-identical to `0xb154` under the +0x54 shift. Same
conclusion. OBSERVED.

**S5 — hard reset.** New: string pool at 3.1.8 `0x12d3c` / 3.1.12 `0x12e14` is a
state-name list headed `"SPM FSM"` containing **`spm_host_src_hardreset`**; 3.2.0's
pool at `0x12fa0` keeps the pool and four SPM states but **drops the hardreset
name** (order also changed). Negatives: no `vSafe0V`/`VBUS`/`TCPC`/`CC1`/`CC2`/`PHY`
string in any of the three images; no CC-toggle or PHY-control write found.
Caveat: no absolute-pointer reference to any name in those blocks ⇒ name may be
dead/duplicated ⇒ label OBSERVED for presence/absence, OPEN for liveness.

**S6 — 3.2.0 switches.** `0x4b78` (arg-indexed, 2–9, 5 unique, dominant
`0x5574` 4/8, table `0x4b94`); `0x50fc` (arg-indexed `(port,type)`, 2–14,
8 unique, dominant `0x5704` 6/13, table `0x5168`, port struct `0x20000644` +
0xf0·port); `0x4eca` (**struct-byte** index `[[r0]]+1`, 3–17, 8 unique, dominant
`0x554a` 6/15, table `0x4ee4`). None of the spans is a partition of 9–22 (two start
at 2; the third crosses the 15/16 boundary) ⇒ **"split into control+data
switches" is not supported**; three layer-distinct handlers is the better fit.
No BL caller for `0x4b78`/`0x50fc`/`0x4eca`/`0xab64` (`bl_xref_320.json`).
OBSERVED (tables/spans) / INFERRED (reading).

**S7 — out-of-table cases 2, 3, 0x28, 0x3d, 0x41.** Bodies are timer arm/release
(2, 3), mask-word bit clears + timer re-arm (3), one-shot latch + state byte
writes 2 / 0x1e (0x28, 0x41), state byte `0x29` via `0x31a0(1,0x29)` (0x3d), and
`memset(0x20001a10+0x28,0,0x2c)` before the second-stage switch (0x41). 2 and 3
carry PD numbers but no PD semantics in body; 0x28/0x3d/0x41 are outside PD's type
range ⇒ device-specific control codes. INFERRED. Also noted: these arms compare
`param_1` to 0/1 (port index) while the 9–22 arms also use it as a pointer — an
inconsistency that blocks any claim about the argument type.

**Net verdicts.** Soft_Reset handling as such: **does not exist in the table**
(OBSERVED); soft-Accept→Soft_Reset sequence: **not found** (OBSERVED absence,
scoped); soft→hard escalation: **OPEN** (bounded negative); hard-reset code:
**OPEN — only a state name, dropped in 3.2.0** (OBSERVED presence/absence);
3.2.0 split hypothesis: **not supported** (INFERRED against); out-of-table code
classification: **INFERRED**.
