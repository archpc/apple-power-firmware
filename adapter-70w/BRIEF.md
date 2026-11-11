# adapter-70w — shared brief for delegated tasks

Repo: `archpc/apple-power-firmware`, branch `research/adapter-70w`, workspace
`~/.hermes/artifacts/apple-power-firmware/`.

Read-only investigation. No flashing, no adapter command, no SMC write, no
privileged operation, no hardware modification. Do not switch branches, do not
commit, do not edit any file except your own findings file. Redact serial
numbers and any personal identifier you encounter.

Evidence labels (from the repo README): OBSERVED, REPRODUCED, INFERRED,
UNVERIFIED, REFUTED, OPEN. Every factual statement carries one. No unsupported
verdicts.

## What the parent has already verified

Sources: `evidence/hpm-regs.json`, `evidence/hpmdiagnose-raw.txt`,
`evidence/hpmdiagnose-run2.txt`, a fresh live `/usr/bin/hpmdiagnose` capture and
live `ioreg`.

1. Register `0x30` on RID 5 is RX Source Caps: four fixed PDOs
   (5 V/2.96 A, 9 V/2.97 A, 15 V/2.98 A, 20 V/3.39 A), byte-for-byte equal to
   `PortControllerPortPDO` and to the IOKit `PowerSourceOptions`. OBSERVED,
   three-way.
2. Register `0x43` is a **live per-port partner-identity record**, not an
   adapter-only register. Empirically bytes 1..2 are VID (LE) and 3..4 are PID
   (LE): RID 5 with the 70 W adapter `19 AC 05 1C 70 ...` → `0x05AC`/`0x701C`;
   RID 0 with an iPhone `19 AC 05 1F 75 ...` → `0x05AC`/`0x751F`; nothing
   attached → all zero. It is **not** the 61-byte `0x49` shape: the 0x49
   offsets applied to it yield nonsense, byte 0 is `0x19` in both attached
   captures, and the trailing bytes are uninterpreted. OBSERVED for bytes and
   VID/PID; record shape OPEN.
3. Register `0x47` is a **stable local (host) identity record**: byte 0 counts
   entries (6 on RIDs 0/1/2, 3 on RID 5), then VID `0x05AC` and PID `0xD540`
   (USB-C HAL) or `0x1C60` (MagSafe HAL) as two little-endian u16 at offsets
   1..2 and 3..4, then two `15 31 1D 73` words. Read as one LE word the halves
   swap and the VID comes out `0xD540`, so this is a register-specific layout,
   not a spec ID Header VDO. Identical on RIDs 0/1/2 with nothing attached, so
   it is not an attachment record. OBSERVED bytes; layout INFERRED.
4. `0x4a` and `0x4f` are **volatile string/VDM buffers**. `0x4a` ends in ASCII
   `Apple` on RID 5 and `iPhone` on RID 0 at re-check. `0x4f` is 29 bytes and
   contained `Adap` in the archived capture but different bytes live; RID 0 live
   contains `e Inc.`. Earlier statement that `0x4f` is "a truncated Adapter
   string" is **not reproducible as a stable fact**.
5. `0x48` is also volatile: `0x80` on RID 5, non-zero on attached RID 0/2,
   zero on unattached ports. Its meaning is OPEN; do not assert NAK.
6. Active contract RDO on RID 5 = `0x45854D53`, USB-PD fixed-RDO layout
   (GiveBack B27, Capability Mismatch B26, USB Comm B25, No USB Suspend B24,
   Unchunked B23): object position 4, 3390 mA operating and max,
   **GiveBack clear, Capability Mismatch SET**, USB Comm capable clear,
   No USB Suspend set, Unchunked set. The earlier note in this file that had
   the two flags swapped was wrong; the Fable session's original bit-26
   Capability Mismatch reading was right. `PortControllerCapMismatch` = 0 in
   the same ioreg dictionary does not agree with the RDO bit: OPEN.
7. Adapter metadata shown by `system_profiler` comes from the
   `AdapterDetails`/`AppleRawAdapterDetails` dictionaries on `AppleSmartBattery`,
   not from a direct register read by us: `Model="0x701C"`, `AdapterID=28700`,
   `FwVersion="01030030"`, `HwVersion="1.0"`, serial, `FamilyCode`, `Watts=68`,
   `UsbHvcMenu` with the same four PDOs. The property stores `FwVersion` as the
   string `"01030030"`; `system_profiler` prints `1030030`. Whether the eight
   characters are zero-padded decimal (value 1030030) or hex (value 0x01030030)
   is **OPEN**: both readings fit the string and neither is established. Do not
   report the version as hex. OBSERVED for the property values only.
8. Live `Port-MagSafe 3@1` now reports `Metadata = {}` whereas the archived
   capture had `{"Product ID (SOP1)"=30720,"Vendor ID (SOP1)"=1452}`. Treat
   port metadata as time-varying.

## Deliverable format

Each findings file: question, method (exact commands), primary evidence with
file:line or command references, findings with labels, confidence, unresolved
issues, reproducible method. Append after each step so a kill cannot erase work.
