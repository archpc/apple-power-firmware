# 0x43 / 0x47 / 0x48 / 0x49 / 0x4f and the active RDO — adversarial verification

Task: falsify claims A–F. Repo `archpc/apple-power-firmware`, branch `research/adapter-70w`,
read-only. Labels: OBSERVED / REPRODUCED / INFERRED / UNVERIFIED / REFUTED / OPEN.

**Method.** Read `adapter-70w/BRIEF.md`; `evidence/hpm-regs.json` (archived); both
`hpmdiagnose` texts; `~/.hermes/cache/scratch/hpm-live-2.txt` (fresh live dump); §1–§3 of
`evidence/applehpm-decompiled.md`; `grep PortController* evidence/ioreg-full.txt`; every
0x43/0x47/0x48/0x49/0x4a/0x4f buffer byte-indexed in Python.
`evidence/ioreg-full.txt:30829` carries four `PortController*` dictionaries (#1 USB-C,
#4 MagSafe), i.e. two *independent* RDO samples — which is what makes claim F testable.

## 1. Specification basis (cited, not remembered)

Fixed RDO, USB-PD 3.0 Table "Fixed request data object", reproduced verbatim by
ST UM2650 (STUSB4500 guide) Table 3 —
https://www.st.com/resource/en/user_manual/um2650-the-stusb4500-software-programing-guide-stmicroelectronics.pdf :
B31 Reserved(0) · **B30…28 Object position** (000b forbidden) · **B27 GiveBack** ·
**B26 Capability mismatch** · B25 USB comm capable · B24 No USB suspend ·
B23 Unchunked ext. msgs · B22…20 Reserved(0) · B19…10 Operating current ×10 mA ·
B9…0 Max operating current ×10 mA.
Two machine-readable implementations agree: Linux `include/linux/usb/pd.h`
(`RDO_OBJ_POS_SHIFT 28`, `RDO_GIVE_BACK BIT(27)`, `RDO_CAP_MISMATCH BIT(26)`,
`RDO_USB_COMM BIT(25)`, `RDO_NO_SUSPEND BIT(24)`) and
`_UCM_PD_REQUEST_DATA_OBJECT.FixedAndVariableRdo` (…`Reserved1:4, NoUsbSuspend:1,
UsbCommunicationCapable:1, CapabilityMismatch:1, GiveBackFlag:1, ObjectPosition:3`).
Fixed *PDO* (2nd half of F), same header: type B31:30, `PDO_FIXED_VOLT_SHIFT 10` (50 mV),
`PDO_FIXED_CURR_SHIFT 0` (10 mA), `PDO_FIXED_EXTPOWER BIT(27)`.

## 2. Claim F — RDO 0x45854D53 and the four PDOs

MagSafe controller (ioreg entry 4): `PortControllerActiveContractRdo` = 1166363987 =
**0x45854D53** →

```
B31=0  B30..28=0b100=4 (position)  B27=0 GiveBack clear  B26=1 CAPABILITY MISMATCH SET
B25=0  B24=1 No-suspend  B23=1 Unchunked  B22..20=0b000 (clean)  op=max=339*10=3390 mA
```

Second sample, USB-C controller (entry 1): `0x1384B12C` → B31=0, position **1**,
GiveBack 0, **CM 0**, USBComm 1, No-suspend 1, Unchunked 1, B22..20=0, op=max=3000 mA,
and its `PortControllerPortPDO` #1 is 5 V/3.00 A. On both samples the position field
selects exactly the PDO whose current equals op/max and every reserved field is clean —
five independent field agreements per sample, so the layout is established for this host.

`PortControllerPortPDO` = (134320424, 184617, 307498, 409939) = the four words in 0x30 RID 5
behind a count byte (`hpm-live-2.txt:457`: `04 | 28 91 01 08 | 29 D1 02 00 | 2A B1 04 00 | 53 41 06 00`).
That leading 0x04 equals `PortControllerNPDOs` = 4 — non-arbitrary proof it is a count:

| raw | V | A | flags |
|---|---|---|---|
| 0x08019128 | 5.00 | 2.96 | B27 externally powered |
| 0x0002D129 | 9.00 | 2.97 | — |
| 0x0004B12A | 15.00 | 2.98 | — |
| 0x00064153 | 20.00 | 3.39 | — |

**Claim F: PARTLY REFUTED.** Position 4 ✓ (B30..28); op 3390 ✓; max 3390 ✓ (= PDO 4);
No USB Suspend ✓; Unchunked ✓; PDO decode ✓ three-way. But
**"Capability Mismatch bit 27 clear" is REFUTED** (CM = B26 = **1**), and
**"GiveBack bit 26 set" is REFUTED** (GiveBack = B27 = **0**). Consequently BRIEF.md §6 —
"CM clear… the prior claim that CM is set at bit 26 is wrong on both bit number and
value" — is itself REFUTED; the prior claim was right on bit number and, here, on value.
The "host agrees because `PortControllerCapMismatch`=0" argument therefore does not hold:
MagSafe has RDO CM=1 with the property at 0, while the USB-C port has RDO CM=0 and
property 0. The property is not a plain mirror of the RDO bit. OPEN.

## 3. Claim A — 0x49 = RX SOP' identity

§3 arithmetic REPRODUCED by byte index: RID 5 `54 AC 05 00 1C …` [9..12]=`00 32 00 78` →
0x78003200 = PID 0x7800 / bcd 0x3200; archived RID 0 `54 AC 05 60 1C …`
[9..12]=`00 01 06 72` → 0x72060100 = PID 0x7206 / bcd 0x0100.

The PID half is corroborated **outside** the register: 0x4a RID 5 = `8A AC 05 00 78 "Apple"`
(PID 0x7800), archived 0x4a RID 0 = `8F AC 05 06 72 "Apple Inc."` (0x7206), and IOKit's
archived `Product ID (SOP1)` on MagSafe = 30720 = 0x7800. Three-way on the PID. The
**bcdDevice half has no independent witness** — UNVERIFIED.

Narrowing caveats:
- Half order is not the spec's: a Product VDO puts bcdDevice in B31:16 and PID in B15:0,
  the reverse of `out+0x2c = PID<<16 | bcd`. Read per spec you get bcd 0x7800 / PID 0x3200,
  contradicting IOKit — so the labels rest on the IOKit anchor, not on USB-PD layout.
- These are caches, not status: RID 2 (nothing attached) keeps VID 0x0000 but still shows
  `60 1C` at [3..4] and `43 26 0A` at [13..15]; archived RID 0 has 0x43 all-zero while
  0x49/0x4a still hold 0x7206; live RID 0 has 0x49 all-zero while 0x43/0x46/0x4a all carry
  0x751F. An all-zero 0x49 is **not** proof that no SOP' was read. `AC 05` also recurs at
  [27..28], so the 61-byte buffer holds more than the one record §3 maps.

Verdict: **SURVIVES for RID 5** (3× PID agreement; "RX SOP'" consistent with a passive-cable
count of 4 and with §1's cable-type field, buf[4] bits 5:3 = 0b011). Falsified by: a known
cable PID that disagrees; 0x49 populating where no e-marked cable exists; or a decompiled
0x43 reader using the same 61-byte struct.

## 4. Claim B — 0x43 is the same shape, for RX SOP

Word arithmetic ✓ (0x701C05AC / 0x751F05AC) and the partner identification is corroborated
twice: 0x701C = `system_profiler` AdapterDetails `Model` / `AdapterID` 28700; 0x751F = the
0x4a "iPhone" record in the same capture. "RX SOP" (received partner identity) SURVIVES.

**"Same record shape" FAILS.** 0x43 is 26 bytes vs 0x49's 61. §3 offsets on 0x43 give
`out+0x2c` = buf[9..12] = `00 00 00 03` → PID 0x0300 / bcd 0x0000 (nonsense), and
0x43[22..25] = `03 00 44 00` (RID 5) / `07 01 04 00` (RID 0) maps to no §3 field. Only bytes
0..4 are shared: [0] flags/count, [1..2] VID LE, [3..4] PID LE — `struct {u16 vid; u16 pid}`,
exactly what `out+0x24` spells as `VID | byte3<<16 | byte4<<24`. Byte 0 = 0x19 in both
attached captures (0x19&7 = 1) while 0x49 uses 0x54 (→4); an adapter ACK has more than one
VDO, so "&7 = VDO count" does not transfer. UNVERIFIED there.

## 5. Claim C — 0x47 is the local/TX Discover Identity response

"Local, per-controller identity" SURVIVES: 0x47 is byte-identical on RID 0/1/2
(`06 AC 05 40 D5 …`, PID 0xD540) despite different attachments, and differs on RID 5
(`03 AC 05 60 1C …`, PID 0x1C60) — USB-C HAL vs MagSafe HAL.

**"VDO count + native little-endian VDOs" FAILS.** As a spec VDO, 0xD54005AC has VID 0xD540
in B31:16 (invalid vendor ID); Apple's 0x05AC sits in B15:0. The bytes are
`{u16 vid=0x05AC; u16 pid=0xD540}` LE — the opposite half order to a wire VDO (the same
reversal §3 documents for 0x49). Same for the "VDO2".

**"VDO2 = 0x731D3115, low 16 bits = FW 003.115.00" FAILS three ways.** (i) As a Product VDO
it is bcdDevice 0x731D (invalid BCD) + PID 0x3115, and that VDO's low half is PID, not
firmware. (ii) The same 4 bytes sit at [9..12] *and* [33..36]; a 6-VDO array from byte 1 ends
at byte 24, so [33..36] cannot be VDO content at all. (iii) `PortControllerFwVersion` =
3216640 = 0x311500, so 0x3115 = FwVersion>>8, and 115₁₀ = 0x73 is the *top* byte of the word,
not part of 0x3115; the 0x311500 ↔ "003.115.00" mapping is nowhere established here (0x0f =
`00 15 31 00`, same bytes, so the pair is at least firmware-adjacent). UNVERIFIED.

"TX / Discover Identity response" specifically is OPEN: no transmit-path evidence and the
buffer is not ACK-shaped (count 6, three nonzero words, duplicated field outside the array).

## 6. Claims D and E

D — **SURVIVES.** 0x48 = 0x80 on RID 5; on RID 0 live it is 0x47's record with byte 0
0x06→0x56 (mask 0x50), a differing 4-byte field, plus a second header `43 AC 05 01 FF` at
[24]; RID 2 live holds a third partial record. A message-level NAK cannot share a slot with
61 bytes of identity data, so "0x80 = NAK" is unsupported; meaning stays OPEN. Bonus: RID 2's
0x48[11..16] = 0x4f[15..20] byte for byte → two overlapping windows on one VDM scratch
buffer (INFERRED, n=1).

E — **SURVIVES, REPRODUCED.** 0x4f = `65 20 49 6E 63 2E` ("e Inc.") at [9..14] on live RID 0
(`hpm-live-2.txt:83`), all-zero archived (`hpm-regs.json:283`), different on RID 2 (line 353)
and RID 5 (line 488). Full strings live in 0x4a ("Apple", "iPhone", "Apple Inc."), so
"truncated Adapter string" is not a stable property of 0x4f.

## 7. Verdicts and what would settle the rest

| claim | verdict |
|---|---|
| A 0x49 = RX SOP' (PID 0x7800 / 0x7206) | SURVIVES (PID 3-way); bcdDevice halves UNVERIFIED |
| B 0x43 = RX SOP (0x701C / 0x751F) | SURVIVES as partner identity; "same shape" REFUTED |
| C 0x47 = local identity (D540 / 1C60) | SURVIVES; as "TX ACK of LE VDOs, FW 0x3115" REFUTED / OPEN |
| D 0x48 meaning unknown, 0x80 ≠ NAK | SURVIVES, OPEN |
| E 0x4f volatile, "e Inc." present | SURVIVES |
| F pos 4, 3390/3390, No-suspend, Unchunked, PDOs | SURVIVE |
| F "CM bit 27 clear / GiveBack bit 26 set" | **REFUTED** — CM = B26 = **1**, GiveBack = B27 = **0** |

Settling the OPEN items: (1) decompile the 0x43 and 0x47 readers (the §3 method already
worked for 0x49) → exact offsets and whether byte 0 is a count; (2) a PD protocol-analyzer
capture of the Request and the Discover Identity ACK → settles CM/GiveBack and whether 0x47
is a TX payload; (3) re-read `PortControllerCapMismatch` while an RDO with CM=1 is active →
decides property-vs-bit; (4) an attachment with an independently known cable PID → closes
the bcdDevice half of A.
