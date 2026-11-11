# adapter-70w — the 70 W USB-C Power Adapter on the MagSafe port

Scope: the adapter itself, separated from the MagSafe 3 cable and from the host
HPM controllers. Read-only. No adapter command, no flash, no SMC write, no
privileged operation. Proprietary firmware is not redistributed; nothing here is
a payload.

Evidence labels are the six used repo-wide: **OBSERVED**, **REPRODUCED**,
**INFERRED**, **UNVERIFIED**, **REFUTED**, **OPEN**.

## What this branch establishes

1. **The attached unit is the A2743 70 W adapter** (OBSERVED, Apple support
   102378 names "Apple 70W USB-C Power Adapter (Model A2743)"). The host sees
   `VID 0x05AC / PID 0x701C`. A 2026 refresh, A3543, carries the same "70W"
   marketing name but a different PID (`0x7026`) and PD 3.2 AVS, so the four
   fixed PDOs and no-AVS profile identify this unit as A2743 (INFERRED,
   medium-high). See `IDENTITY.md`.
2. **The controller is an Infineon EZ-PD CCG3PA2**, marked `CYPDC1185B2`
   (OBSERVED, single source: ChargerLAB teardown). No independent teardown,
   regulatory filing or datasheet marking corroborates it. Exact order-code
   suffix OPEN. See `IDENTITY.md`.
3. **The HPM identity registers are three different things.** `0x43` is the
   attached partner identity (adapter `0x05AC:0x701C`, iPhone `0x05AC:0x751F`
   in the same capture set). `0x47` is the host controller's own identity
   (`0xD540` USB-C HAL, `0x1C60` MagSafe HAL). `0x49` is the cable's SOP'
   identity (`PID 0x7800`, product VDO `0x78003200`). See `REGISTERS.md`.
4. **The negotiated RDO is `0x45854D53`**: object position 4 (the 20 V PDO),
   operating and max 3390 mA, **Capability Mismatch set (B26)**, GiveBack clear
   (B27), No USB Suspend and Unchunked set. `PortControllerCapMismatch = 0` in
   the same dictionary does not agree with the bit; OPEN.
5. **Adapter metadata comes from the SMC-backed battery stack, not from a
   direct HPM read.** `AdapterDetails` is published on `AppleSmartBattery` by
   `AppleSmartBatteryManager` (`IOProviderClass = AppleSMC`). The strings
   `Reading adapter details at port %d` and `Failed to read … key %c%c%c%c`
   in that kext show per-port 4CC key reads. See `HOST.md`.
6. **macOS treats the adapter as a UARP accessory and runs a real update
   cycle.** `accessoryupdaterd` logs
   `modelNumber=A2743 … fw=1.3.30 stagedFW=0.0.0`, overrides the asset location
   to `mesu.apple.com`, and triggers an asset check. Delivery always fails with
   `response: 43 (MADownloadNotFoundOrDenied)`. See `HOST.md`.
7. **No public firmware is served for A2743** across mesu, Pallas and the CDN,
   and no local MobileAsset cache carries one. Scope and the exact wording of
   the negative are in `DISTRIBUTION.md`. The earlier "confirmed three ways"
   framing is REFUTED: it was one registry probed repeatedly.
8. **The onboard firmware cannot be obtained today.** No image on disk, no
   asset, no public payload. The only software read primitive (`CFUa` over the
   PD link) is not gated on update mode host-side but is undocumented, needs an
   entitlement-gated service, and addresses at most 64 KiB of a 128 KB flash.
   The only documented full-flash read is SWD, gated by a chip-protection byte
   and requiring the sealed mains adapter to be opened. The host already reads
   the accessor's page 27 on connect (cable: 6, adapter: unknown), and the
   transport is entitlement-gated to Apple-signed processes. See
   `DUMP-FEASIBILITY.md`.

## Audit of the previous Fable session

The prior session produced hypotheses but no committed documents. Each is
resolved here; none was adopted without re-derivation.

| prior claim | disposition | basis |
|---|---|---|
| `0x43` carries adapter VID/PID `0x05AC:0x701C` | **CONFIRMED, narrowed** | bytes 1..2 / 3..4 LE; same layout yields `0x751F` with an iPhone attached |
| `0x47` is an identity record with PID `0xD540`/`0x1C60` | **CONFIRMED, narrowed** | stable across unattached ports; not a spec VDO array (halves swap) |
| `0x48 = 0x80` would be a NAK | **UNSUPPORTED → OPEN** | the same slot carries 61 bytes of identity data on an attached port |
| `0x4f` is a truncated "Adapter" string | **REFUTED** | volatile; `Adap` in one capture, `e Inc.` on another port live |
| RDO bit 26 = Capability Mismatch is set | **CONFIRMED** | USB-PD fixed RDO: B26 CM, B27 GiveBack; `0x58` in B27..20 sets B26 |
| adapter metadata may come via SMC/charger path | **SUPPORTED** | kext key-read strings + `AppleSmartBatteryManager` publisher |
| updater has a power-adapter discovery and Mode 7 flow | **SUPPORTED** | strings and unified-log records, not a live update |
| A2743 is the 70 W model | **CONFIRMED** | Apple support 102378 |

Two claims were corrected in the opposite direction: the adapter's firmware
string is **not** established as hex, and the host's `PortControllerCapMismatch`
property does not mirror the RDO bit.

## Layout

```
README.md        this file
IDENTITY.md      adapter model, regulatory IDs, controller evidence
REGISTERS.md     HPM 0x30/0x43/0x47/0x48/0x49/0x4a/0x4f and the active RDO
HOST.md          metadata provenance and the updater architecture
DISTRIBUTION.md  what was searched for firmware and the exact negative scope
DUMP-FEASIBILITY.md  whether the onboard image can be read, and the blockers
OPEN.md          unresolved questions, blockers, what would settle each
BRIEF.md         shared brief used by the delegated work
scripts/registers.py       reproducible register/PDO/RDO decoder
evidence/hardware/         adapter identity research
evidence/registers/        decoder outputs + adversarial verification
evidence/host/             provenance and updater findings
evidence/distribution/     registry queries and status codes
```

## Reproduction

```bash
python3 adapter-70w/scripts/registers.py evidence/hpm-regs.json \
        --out adapter-70w/evidence/registers/decode-archived.json
python3 adapter-70w/scripts/registers.py \
        adapter-70w/evidence/registers/hpm-regs-live.json \
        --out adapter-70w/evidence/registers/decode-live.json
python3 scripts/verify_docs.py .
```

The decoder exits non-zero if any self-check fails. It currently passes 9/9 on
both captures. Live captures were taken with `/usr/bin/hpmdiagnose` (read-only,
unprivileged) and are stored with serial fields masked.
