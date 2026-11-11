# REPORT — Apple USB-C power adapter, MagSafe 3, and the USB-PD/UARP stack

Host: MacBook Pro Mac17,9 (M5 Pro), macOS 27.2.1 build 26B131.
All work read-only. No firmware was flashed, no update triggered, no accessory
command was sent, nothing was installed. No privileged operation was performed.

Companion documents: `HARDWARE.md`, `FIRMWARE.md`, `PROTOCOL.md`, `DIFF.md`,
`SECURITY.md`, `NEXT.md`, `EXTRACTION-NOTES.md`.

---

## 1. Executive summary — the headline

Three separate firmware objects exist in this system and the industry habit of
calling them all "the charger firmware" is what makes this confusing:

| object | version | who owns it |
|---|---|---|
| HPM port controller | `FW003.115.00` | the Mac (four instances: RID 0, 1, 2, 5) |
| MagSafe 3 cable (A2363) | 3.2.0, bcdDevice 0x3200 | the cable, PID 0x7800 |
| 70 W adapter | `1030030` | the brick, ID 0x701c |

These are not equally established. The HPM and cable values are host-observed;
the adapter's `1030030` is host-reported only, because no adapter firmware could
be obtained. The cable's 3.2.0 comes from the in-file version quadruple of the
downloaded SuperBinary; it agrees with `bcdDevice 0x3200` in HPM register `0x49`,
but agreement between a header field and a register is consistency, not two
independent recoveries. So the previously "reported" 3.2.0 is now
OBSERVED rather than assumed.

The charger is on the **MagSafe port (RID 5)**, not on any USB-C port, at
**20 V × 3.390 A = 67.80 W**.

Two things remain **OPEN**: whether 3.2.0 is semantically equivalent to 3.1.12,
and whether any host-observable behavioural difference exists between revisions.

The standing limitation is coverage — 38.8 / 39.4 / 43.3 % of each image lies
inside analysed functions, and the paths that matter most lie outside it. No
statement here separates relocation, byte difference, structural correspondence,
semantic change and behavioural change into the wrong bucket.

## 2. What was actually accomplished

**Firmware obtained.** MagSafe 3 releases 3.1.8, 3.1.12 and 3.2.0 were acquired
from Apple's public CDN, each SHA-1 matched against Apple's own manifest
`_Measurement`, and hashed. This is the first time this project could compare
real versions rather than reported strings.

**Container format recovered from Apple's parser, not guessed.** The UARP
SuperBinary layout was read out of `/usr/libexec/uarpd`'s own
`expandSuperBinaryHeader` / `expandPayloadHeadersAndMetaData:offset:` and the
per-record decoder. The parser's own checks (header length must be `0x2c`,
table length a multiple of `0x28`, declared payload length `<=` file size) are
now known, not inferred.

**All four images extracted and validated.** `scripts/uarp_superbinary.py`
passes 6/6 checks on each, and the decisive arithmetic reconciles four-for-four:
`payloadDataOffset + payloadLength` equals the container's declared
`payloadLength` in every file.

**Executable code identified.** The MagSafe payloads are not raw images: each is
wrapped in a 384-byte `C99` header, and at offset `0x180` begins a Cortex-M
vector table (`SP = 0x20002000`) immediately followed by Thumb-2 startup code at
`0x10`. The base is **OPEN**, not established as `0x00000000`: the 140 W control
image shows a similar opening, but its pointers exceed its own payload, which rules
out a base-zero mapping for that image without ruling out other bases. It does not
corroborate the base-zero reading, and this report does not use it as support.

**UVDM framing recovered from the kernel.** `AppleHPM::hpmIECSSendVDM` builds
`[hdr][payload ≤ 28][4CC "VDMs"]` with `hdr = (sop & 3) << 4 | ceil(len/4)`.
The exact 9-byte Discover-Identity frame emitted by
`AppleHPMInterface::isCableKartCapable` was read out of the instruction stream:
`21 | 01 A0 AC 05 | 56 44 4D 73`.

**Register 0x49 decoded.** `getRXSOPpData` gave the field map; applying it to the
live dump yields `0x78003200` = PID `0x7800` + bcdDevice `0x3200`, matching
IOKit and the firmware version independently. Byte 4 bits 5:3 classify the cable
as passive (3), matching `ActiveCable = No`.

**Host stack mapped.** `uarpd` parses SuperBinary and builds UARP messages with
a 6-byte three-`u16` big-endian header. The USB-PD binding is not in `uarpd`; it
is in `UARPUpdaterServiceUSBPD.xpc`, which implements Discover-Identity VDO
parsing, Apple Accessory Mode 7, and CFU firmware commands, with distinct
`UARPMagSafeCable` and `UARPPowerAdapter` classes.

## 3. Corrections made to the starting brief

- `attachSOPpNub` **does not exist**. No such symbol. Those strings are log
  payloads inside `AppleHPMInterface::genericStart`, which is where sub-nub
  attach happens.
- Register `0x49` does **not** hold "the MagSafe identity" as a single field. It
  is a packed SOP′ identity page: entry count in byte 0 bits 2:0, vendor ID at
  bytes 1–2, cable type in byte 4 bits 5:3, and a byte-reversed VDO word.
  Register `0x4a` is the human-readable vendor string (`Apple` / `Apple Inc.`).
- `usbcupdater` does **not** update adapters or cables. It launches the Mac's own
  port-controller firmware via EFI. The accessory path is a different
  component entirely.
- `FW003.115.00` is the **HPM controller's** firmware, not the adapter's. It is
  not comparable to `1030030` in any way.
- The 70 W adapter firmware **is not publicly obtainable**, confirmed three
  independent ways. A 140 W image was used strictly as a format control and must
  never be substituted for it.
- `uarpd` contains no USB-PD code at all — but that is not evidence the transport
  is absent system-wide; it lives in the updater service.

## 4. What remains open

Stated as open, not resolved:

- Which VDM form carries UARP TLVs — kernel side is unstructured with a `VDMs`
  4CC; the updater service talks about SOP/SOP′ and VDOs. Both can be true.
- The meaning of the one changed Apple vendor constant (`0x05AC0002` →
  `0x05AC0000`) and of the two candidate tables of 15 and 13 cases in 3.2.0,
  which are not shown to be control-message dispatchers at all.
- What the three 32-byte `C99` header fields are; none equals a plain SHA-256 or
  CRC-32 of the image slice.
- Whether the accessory verifies a signature at all, and whether any
  anti-rollback exists. Both are UNVERIFIED and one of them (rollback) is
  blocked by the no-downgrade rule.
- Whether `accMode7AddressSpaceRead` can read accessory flash. The verb exists in
  Apple's code; authorization is untested.

**OPEN**, not closed: the entry-point question. The 4-word block at image offset 0
is SP plus three pointers of unconfirmed meaning. In 3.2.0 the word at offset `0x04`
is `0x0001111d`, whose Thumb target `0x1111c` holds `0x4005xxxx` peripheral
addresses, so that target is constant data and not a handler. Which code executes
first remains unsettled; offset `0x10` is the empirical start, not a proven entry.

Still open, and deliberately without a verdict: whether 3.2.0 is semantically
equivalent to 3.1.12. `DIFF.md` retracts two earlier claims (the "rebuild, not
patch" reading of 5.9 % window overlap, and a preliminary function pairing) and
documents why: Ghidra analysed these images as generic ARM v7, and its function
bodies cover only 38.8 / 39.4 / 43.3 % of the three images, leaving the
control-message switch and the Apple SVID literal sites outside the analysed set,
so the paths in question were never decompiled. What survives is the switch
census, the constant counts and the PDO table, each reported with its limit.

## 5. How far we can inspect this hardware without modifying it

Maximum reachable state today, no root, no accessory contact:

- Full IOKit/IOAccessoryManager view of ports, contracts, and identities.
- Full raw register file of all four HPM controllers via `/usr/bin/hpmdiagnose`,
  which is entitlement-gated but not root-gated.
- Complete MagSafe cable firmware images for three revisions, extracted to
  executable Cortex-M code, with container and load layout validated.
- Static understanding of the host UARP engine and the accessory update service.

Not reachable without sending the accessory a command: its running firmware
contents, its logs, and its own authentication result. That boundary is real and
is not an artifact of tooling.

## 6. Method notes worth carrying forward

- BootKC kext extraction needed a full segment repack, not a slice: kext segments
  are non-contiguous in the fileset. Offsets are validated against the output
  file, never wrapped. See `EXTRACTION-NOTES.md`.
- Accessory firmware must be parsed from Apple's own parser. Two rounds of
  guessing from hex produced a plausible but wrong TLV walk; the decompiled
  `expandSuperBinaryHeader` settled it in one pass and immediately explained the
  `0x28` record stride.
- Treat subagent findings as self-reports. Three claims were checked and
  corrected here: the `htons` store offset, the `attachSOPpNub` symbol, and the
  `usbcupdater` role. One claim (UARP-over-USB-PD in `UARPUpdaterServiceUSBPD`)
  was checked and confirmed.
