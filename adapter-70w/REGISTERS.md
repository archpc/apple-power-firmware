# REGISTERS — HPM identity registers and the active power contract

All bytes are from `hpmdiagnose` captures (archived `evidence/hpm-regs.json`,
live `adapter-70w/evidence/registers/hpm-regs-live.json`, serial masked).
`scripts/registers.py` re-derives every value below and asserts the cross-checks.

Register space is per HPM controller. RID 5 drives MagSafe and has the 70 W
adapter attached; RID 0 had an iPhone attached at re-check and nothing at the
archive time; RIDs 1/2 had nothing attached. That difference is what separates
host-side state from attachment state.

## 1. The identity map

| reg | length | stable? | reading | label |
|---|---|---|---|---|
| `0x30` | 57 | per attachment | source-capability PDO list | OBSERVED |
| `0x43` | 26 | per attachment | **attached partner** VID/PID | OBSERVED bytes, layout INFERRED |
| `0x47` | 49 | stable per controller | **host controller** VID/PID | OBSERVED bytes, layout INFERRED |
| `0x48` | 61 | volatile | identity-shaped on attached ports, `0x80` on MagSafe | OPEN |
| `0x49` | 61 | per attachment | **cable (SOP')** identity | OBSERVED, reconstruction from Apple's parser |
| `0x4a` | 54 | per attachment | VID/PID + manufacturer string | OBSERVED |
| `0x4f` | 29 | volatile | string/VDM scratch | OPEN |

### `0x30` — source capabilities

RID 5 reads `04 | 28 91 01 08 | 29 D1 02 00 | 2A B1 04 00 | 53 41 06 00`.
The leading byte's low three bits are the PDO count: `0x04` here equals
`PortControllerNPDOs = 4`, and RID 0 with an iPhone reads `0x81`, i.e. one PDO.
The four words decode as fixed supplies:

| word | voltage | max current | flags |
|---|---|---|---|
| `0x08019128` | 5.00 V | 2.96 A | Unchunked extended messages |
| `0x0002D129` | 9.00 V | 2.97 A | — |
| `0x0004B12A` | 15.00 V | 2.98 A | — |
| `0x00064153` | 20.00 V | 3.39 A | — |

Three independent representations agree byte-for-byte: this register,
`PortControllerPortPDO` in ioreg, and the IOKit `PowerSourceOptions` the host
publishes. REPRODUCED by `registers.py`.

### `0x43` — attached partner identity

RID 5 (adapter): `19 AC 05 1C 70 00 …` → bytes 1..2 = `0x05AC` (Apple VID),
bytes 3..4 = `0x701C` (PID). RID 0 (iPhone): `19 AC 05 1F 75 …` → `0x05AC`,
`0x751F`. Nothing attached: all zero.

This is **not** an adapter-only register and **not** the `0x49` record shape.
It is 26 bytes, not 61; applying the `0x49` offsets lands on `00 00 00 03`.
Byte 0 is `0x19` in both attached captures; whether it is a count, a length or a
status is UNVERIFIED. The trailing bytes are uninterpreted. What is established
is that bytes 1..4 carry the partner's VID and PID, and that the PID matches
`AdapterDetails.Model` exactly.

### `0x47` — host controller identity

RID 0/1/2: `06 AC 05 40 D5 00 00 00 00 15 31 1D 73 3C 00 00 6D …`
RID 5: `03 AC 05 60 1C 00 00 00 00 15 31 1D 73 …`

Byte 0 is 6 on the USB-C controllers and 3 on the MagSafe controller; the
bytes are identical on three ports with nothing attached, so this is the host's
own identity, not an attachment record. Bytes 1..2 are VID `0x05AC`; bytes 3..4
are PID `0xD540` (USB-C HAL) or `0x1C60` (MagSafe HAL).

This is not a spec VDO array. Read as one little-endian word, `AC 05 40 D5` is
`0xD54005AC`, which would put an invalid vendor ID in the high half; the
register stores VID then PID as consecutive little-endian u16. The word
`0x731D3115` at bytes 9..12 is duplicated verbatim at bytes 33..36 — outside any
6-entry array ending at byte 24 — so it is a struct field, not VDO content. Its
low half `0x3115` corresponds to `PortControllerFwVersion = 0x00311500`
(HPM firmware 003.115.00), but the decomposition is INFERRED and the "bcdDevice"
reading is REFUTED (high half `0x731D` is not valid BCD).

### `0x48` — unresolved

`0x80` followed by zeros on RID 5. On attached RID 0 it holds 61 bytes that look
like `0x47`'s record with a different leading byte and a second header at
offset 24; RID 2 holds a third partial record. A message-level NAK cannot share
a slot with 61 bytes of identity data, so the earlier "`0x80` = NAK" reading is
UNSUPPORTED. Meaning OPEN. One observation, n=1: RID 2's `0x48[11..16]` equals
`0x4f[15..20]` byte for byte, suggesting overlapping windows on one scratch
buffer.

### `0x49` — cable (SOP') identity

`evidence/applehpm-decompiled.md` §3 recovers the parser
`AppleHPMDeviceHAL::getRXSOPpData`: count = `buf[0] & 7` saturating at 6,
vendor ID from bytes 1..2, cable type from `buf[4]` bits 5:3, and a product
word from bytes 12, 11, 10, 9.

RID 5: `54 AC 05 00 1C …` → count 4, VID `0x05AC`, cable type 3 (passive),
product `0x78003200` = PID `0x7800` / bcdDevice `0x3200`. The PID is anchored
three ways: this register, the `0x4a` string record, and IOKit
`Product ID (SOP1) = 30720`. The bcdDevice half has no independent witness —
UNVERIFIED. Note the half order is the reverse of a spec Product VDO (which puts
bcdDevice high, PID low); the labels rest on the IOKit anchor, not on USB-PD
layout.

Archived RID 0: `54 AC 05 60 1C …` → product `0x72060100` = PID `0x7206`,
bcd `0x0100`, consistent with that port's `0x4a` `"Apple Inc."` record.

These are caches, not live status: an all-zero `0x49` is not proof that no SOP'
was read (live RID 0 has `0x49` zero while `0x43`/`0x4a` carry the iPhone).

### `0x4a` and `0x4f` — strings

`0x4a` holds a marker byte, VID, PID and a manufacturer string at offset 28:
`8A AC 05 00 78 "Apple"` on RID 5; `8F AC 05 06 72 "Apple Inc."` on archived
RID 0; `8B AC 05 1F 75 "iPhone"` on live RID 0.

`0x4f` is 29 bytes and volatile. It contained ASCII `Adap` in the archived RID 5
capture, is all-zero in the archived RID 0 capture, and contains `e Inc.` in the
live RID 0 capture. The earlier statement that it is "a truncated Adapter
string" is **REFUTED** as a stable property; it is a scratch/VDM window whose
framing is OPEN.

## 2. The active contract RDO

`PortControllerActiveContractRdo = 1166363987 = 0x45854D53` on the MagSafe
controller. Fixed-RDO field layout (USB-PD 3.x, reproduced by ST UM2650 Table 3
and by `RDO_GIVE_BACK BIT(27)` / `RDO_CAP_MISMATCH BIT(26)` in Chromium EC's
`usb_pd.h`):

| field | bits | value |
|---|---|---|
| object position | 31..28 | 4 (the 20 V PDO) |
| GiveBack | 27 | 0 (clear) |
| Capability Mismatch | 26 | **1 (set)** |
| USB Communications Capable | 25 | 0 |
| No USB Suspend | 24 | 1 |
| Unchunked Extended Messages | 23 | 1 |
| Operating current | 19..10 | 3390 mA |
| Max operating current | 9..0 | 3390 mA |

A second, independent sample exists in the same ioreg: the USB-C controller
reports `0x1384B12C` → position 1, CM clear, GiveBack clear, USB Comm capable,
operating = max = 3000 mA, matching its 5 V/3.00 A PDO. Each sample agrees with
its own PDO table on five fields, which is what establishes the layout for this
host.

**Discrepancy, OPEN:** `PortControllerCapMismatch = 0` for the MagSafe
controller although the RDO sets CM. The property is therefore not a plain
mirror of the RDO bit; it may be a counter, a latched error, or scoped to a
different exchange.

## 3. What would change these readings

- **Decompile the `0x43` and `0x47` readers** (the `0x49` method already worked)
  to settle byte 0 and the trailing fields. Not done here.
- **A PD protocol-analyzer capture** of the Request and the Discover Identity
  ACK to confirm the RDO flags on the wire and whether `0x47` is a transmit
  payload.
- **Re-read `PortControllerCapMismatch` while a CM-set RDO is active** to decide
  property versus bit.
- **An attachment with a known cable PID** to close the `0x49` bcdDevice half.
