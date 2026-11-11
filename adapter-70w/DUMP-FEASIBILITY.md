# DUMP — can the A2743's onboard firmware be obtained?

Question: obtain a verified copy of the firmware running on the attached A2743
(VID `0x05AC`, PID `0x701C`), not the MagSafe cable image and not a host update
package. Read-only. Nothing was flashed, erased, unlocked or sent to the
adapter.

**Bottom line: no acquisition path is open today.** There is no image on disk,
no public payload, and no software read that can be exercised without sending
undocumented CFU reads to the live adapter. The one documented full-flash read
is SWD, which requires opening a sealed mains adapter. Each blocker is named
below with the evidence that establishes it.

## 1. What would be dumped

The CCG3PA2 has **2 × 64 KB flash** (datasheet 002-18400 p.1, p.5). The
bootloader occupies a fixed area written only over SWD; the application
firmware occupies the rest. A complete dump is therefore up to 128 KB, and a
useful dump must distinguish bootloader from application — a vector table at
`0x00000000` and a reset handler in the application region are the cheap way to
tell them apart.

## 2. Route A — host cache or update package

**No image exists on this host.** OBSERVED.

- `/System/Library/AssetsV2/staging/com_apple_MobileAsset_UARP_A2743.xml` exists
  and is **19 bytes**, content `<h1>not found</h1>`, mtime matching the third
  `response: 43 (MADownloadNotFoundOrDenied)` log line. It is a failed-fetch
  record, not a catalog.
- No `…_UARP_A2743` asset directory; the A2363 and A2515 staging manifests are
  0 B and the working A2968/A3048 manifests are 8,650 B of XML, so 19 bytes of
  HTML is unambiguous.
- No `.tmp`, `.partial`, `.download`, `firmware.uarp` or `.acsw` for A2743
  anywhere outside the asset store, and none at all inside it.
- `UARPUpdaterServiceUSBPD.xpc` bundles no firmware and no model plist. Its
  sibling Thunderbolt service does bundle 13 firmware files, so the absence is
  structural, not an extraction artifact.
- Public distribution is absent: mesu 403/19 B, Pallas `AssetType not found`,
  no CDN path (`DISTRIBUTION.md`).

Route A is closed for the foreseeable future. The host knows the model — `A2743`
is a compiled literal in CoreUARP inside `dyld_shared_cache_arm64e.28` — but it
has no bytes to hand it.

## 3. Route B — software read over the PD link

**A read primitive exists, and it is not gated on update mode host-side.**
OBSERVED statically in `UARPUpdaterServiceUSBPD` (arm64e), addresses in
`evidence/dump/software-readpath.md`.

```
accMode7AddressSpaceRead: 0x100002b30
  -> readCFUa:            0x10001609c   (4CC "CFUa")
  -> doAtomic4CC:         0x100015c64   (IOCreatePlugInInterfaceForService)
```

- The only host-side gates are `bufferLength != 0` and `[self isConnnected]`
  (sic). No state ivar, and `GetState` is never called from the read path.
- Mode 7 entry is performed by **writes** to space 1 (`SendCommand` writes 4 B
  to `0x400`; values 1 = control, 2 = Start, 4 = Apply). `Initialize` calls
  `GetState` first and waits for state 1 — i.e. the host expects reads to work
  *before* Mode 7 entry.
- `-hardwareVersion` reads page 27 with no update session at all.
- Address model: 16-bit `(space << 10) | offset` → **64 KiB, 64 pages of 1 KiB**.
  Chunk size 24 B (20 B when SOP type is 0). No page allowlist and no upper-page
  check.
- Pages actually used by the binary: 1 (state/command), 27 (hardware-version
  VDO), 28 (logs and log control), 40 (analytics). **No path walks application
  flash**; firmware movement is write-only via the `CFUs` stream.

**Passive evidence that the primitive works outside update mode — for the
cable.** `accessoryupdaterd` logs `HW Revision updated (null) -> 6` for the
attached A2363 cable, and `UARPMagSafeCable -queryHardwareVersion` reads page 27
through this path with no update session. The mechanism is therefore live for
that accessory class. For the A2743 it logs `unknown`, but
**`UARPPowerAdapter` implements no `hardwareVersion` or `queryHardwareVersion`**
(its method list is `initWithHPM:supportsAccMode7:`, `activeFwVersion`,
`prepareFirmwareVersion`, `solicitLogs`, `solicitAnalytics`, …). The `unknown`
is a default, not evidence that a read was attempted or failed. **Page 27 on the
adapter is untested.**

Two hard limits follow from that arithmetic:

1. The address space is **64 KiB**, exactly half the 128 KB flash. At most one
   bank can be addressed through this model, and the binary offers no banking
   control. A "full dump" through this path is not possible even if reads work.
2. A 64 KiB read is ~2,730 transactions at 24 B each through an entitlement-
   gated IOKit interface.

**The unresolved question is accessory-side, not host-side:** whether the A2743
answers `CFUa` reads on pages outside 1/27/28/40, and whether those reads return
executing flash or only the update address space. That cannot be decided
statically. Settling it requires sending CFU reads to the adapter.

**Why this is not done unilaterally.** The transport is gated by
`com.apple.USBCEntitlement` plus `AppleHPMUserClient` — held by Apple's signed
`hpmdiagnose` and the updater XPC, not obtainable by third-party code. Reaching
the primitive therefore means driving Apple's own service, and the reads
themselves are undocumented. Both are outside the standing rule against sending
undocumented commands to the live adapter without explicit approval.

## 4. Route C — physical SWD

**Documented, full-flash, and blocked by the enclosure.** OBSERVED from vendor
documentation (`evidence/dump/silicon.md`).

- SWD is the only debug interface (no JTAG). Flash is memory-mapped at
  `0x00000000` and "the firmware or external programmer can read its content
  directly from the given address" (002-22328 p.8, p.11, p.32). Word reads, no
  unlock, no SROM API.
- SWD is gated by a **one-byte chip-protection field** in supervisory flash
  (p.43 Table A-1): OPEN = full DAP access; PROTECTED = reads NACKed, and the
  only documented route back to OPEN **erases all user-region flash**; KILL =
  "completely locks the SWD-pins", irreversible.
- **Which state Apple programs is OPEN.** No vendor document states it. If the
  part is PROTECTED, a dump is impossible, not merely difficult; if KILL,
  permanently so. A failed attempt on a PROTECTED part can destroy the very
  image being sought.
- The CC-line bootloader is **update-only** by documentation: the CCG3PA2
  order code carries the "DFP CC with Direct Feedback Bootloader" and no I2C or
  USB alternative; no read command appears in any of the six vendor documents.
  Absence from public docs is not proof of absence on the wire, so this is
  INFERRED write-only.
- The vendor's own adapter reference design labels the SWD header "Not needed
  for final production" (p.15 Fig 8), which is consistent with a protection
  state designed to prevent exactly this.

Physical read needs four QFN contacts plus XRES in a short acquisition window,
with the board exposed. On this product that means opening a sealed,
mains-powered adapter. **Prohibited by the task rules and unsafe.**

## 5. Capability matrix

| route | read? | needs | blocker | status |
|---|---|---|---|---|
| host cache / asset | no | Apple to publish a payload | asset never served | CLOSED |
| CFUa over PD (space 1/27/28/40) | yes | approval + entitlement-gated service | undocumented read on live device | NOT AUTHORIZED |
| CFUa over PD (other pages / flash) | unknown | same, plus accessory-side support | unknown semantics; 64 KiB map | OPEN |
| CC bootloader | no | — | update-only by design | CLOSED |
| SWD | yes, full | opened enclosure, OPEN protection state | sealed mains product; state unknown | PROHIBITED / OPEN |
| config-table read | 1 KB config only | application firmware feature | not the image | NOT USEFUL |

## 6. Safest feasible acquisition, in order

1. **Passive, zero risk — implemented.** A daily watcher checks the mesu
   manifest and `/System/Library/AssetsV2` for an A2743 asset and stays silent
   unless one appears (cron `db05dacab515`, script
   `~/.hermes/scripts/a2743-asset-watch.sh`, log
   `~/.hermes/cache/a2743-asset-watch.log`). If Apple publishes, capture the
   asset and verify against its manifest `_Measurement`.
2. **Page 27 — untested on the adapter.** The cable proves the primitive works
   outside update mode; the adapter class never queries it, so `unknown` proves
   nothing. A single 4-byte read of page 27 on a spare unit remains the smallest
   experiment. It is blocked today because no non-Apple process can pass the
   entitlement check.
3. **Approval-gated, bounded — the only remaining software experiment:** one
   read of a single page outside 1/27/28/40, on a spare unit, to learn whether
   the map is a flash window. Stop at the first error; never enter Mode 7 and
   never write. Requires a client that can pass the entitlement check, which
   does not currently exist outside Apple's binaries — so this is blocked in
   practice as well as by policy.
4. **Physical, only with a spare and explicit approval:** SWD dump on an
   unpowered, isolated board after confirming the protection byte is readable
   as OPEN. If PROTECTED, abandon: recovering to OPEN erases the image.

## 7. Verification of any image obtained

- SHA-256 of the raw dump, recorded in `adapter-70w/`; the binary stays local,
  never in Git.
- Size must be 64 KiB or 128 KiB and match the flash geometry.
- Initial SP and reset vector in the first 8 bytes must land inside SRAM and the
  application region respectively; a dump that fails this is not a valid image.
- Entropy and string pass to separate code from configuration/unused flash.
- If the bytes came from an update asset, require the container's own hash to
  match Apple's manifest `_Measurement`.

## 8. What would falsify these conclusions

- A host file containing a valid A2743 image (falsifies Route A being closed).
- A successful `CFUa` read of a page outside 1/27/28/40 on a live unit
  (falsifies "no software read path"; does not by itself prove flash is read).
- A read of page 1 returning flash-like data rather than a state block
  (falsifies the "update address space only" reading).
- A CCG3PA2 unit read as OPEN over SWD (falsifies the production-protection
  inference, not the enclosure blocker).
