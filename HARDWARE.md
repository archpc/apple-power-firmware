# HARDWARE — USB-C / MagSafe 3 power path on this host

Host: MacBook Pro Mac17,9, Apple M5 Pro, macOS 27.2.1 build 26B131.
All observations below were taken live on this machine with unprivileged
commands (`ioreg`, `system_profiler`, `/usr/bin/hpmdiagnose`) and are OBSERVED
unless labelled otherwise.

Evidence files: `evidence/ioreg-full.txt`, `evidence/ioaccessorymanager.txt`,
`evidence/hpmdiagnose-raw.txt`, `evidence/hpm-regs.json`.

---

## 1. Controller inventory

Four HPM (Host Power Management / USB-PD controller) instances exist. Three are
published as USB-C ports, one drives MagSafe 3.

| RID | SPMI address | ioreg class | published port | port type |
|---|---|---|---|---|
| 0 | 0x0c | AppleHPMDeviceHALType3@C | `Port-USB-C@1` (AppleHPMInterfaceType10) | USB-C (2) |
| 1 | 0x0a | AppleHPMDeviceHALType3@A | `Port-USB-C@2` | USB-C (2) |
| 2 | 0x0c | AppleHPMDeviceHALType3@C | `Port-USB-C@3` | USB-C (2) |
| 5 | 0x08 | AppleHPMDeviceHALType4/5 family | `Port-MagSafe 3@1` (AppleHPMInterfaceType11) | MagSafe 3 (17) |

RIDs 0/1/2 sit on `nub-spmi-a0@8A188000` / `nub-spmi-a1@8A1A8000` under
`AppleSoCIO`; RID 5 is `hpm5@8`. The `RID` numbering is Apple's router ID, not a
port index: there is no RID 3 or 4 on this machine, and RID 5 is the MagSafe
controller. `hpmdiagnose` enumerates exactly RID 0, 1, 2, 5.

Port numbers: USB-C ports are `PortNumber` 1, 2, 3; MagSafe is `PortNumber` 1
with `PortType` 17 and `IOAccessoryPrimaryDevicePort = 261`.

## 2. Firmware identity is three separate objects

Do not conflate these. The user-supplied note that "HPM identification is
FW003.115.00, distinct from adapter firmware" is OBSERVED and the distinction
is larger than two objects.

| object | value | source |
|---|---|---|
| HPM controller firmware | `FW003.115.00` | register 0x2f ASCII `SN2012025 HW00A4 FW003.115.00 ZACE3-J714P01`; `FW Version = <00153100>`; `FirmwareVersion = "003.0115"` |
| HPM hardware rev | `HW00A4`, board `ZACE3-J714P01` (P05 on RID 5) | register 0x2f |
| HPM silicon IDs | VID 40 (0x28), DID 33628197, revision ID 164, `Version` 3216640 (0x00311500) | ioreg properties on AppleHPMDeviceHALType3 |
| USB-C power adapter | `ID 0x701c`, HW 1.0, FW `1030030`, 70 W, serial `F16HS109YFA000000P`, family `0xe000400a` | `system_profiler SPPowerDataType`, `AC Charger Information` |
| MagSafe 3 cable | VID 0x05AC, PID 0x7800, bcdDevice 0x3200 | register 0x49 reconstruction; IOKit `Product ID (SOP1)=30720`, `Vendor ID (SOP1)=1452` |
| Battery gauge | `bq40z651`, FW 0x00000b00, HW rev 0x0100 | `SPPowerDataType` model information |

`FW003.115.00` is the HPM's own firmware. `1030030` is the adapter's. They are
not revisions of the same image and must never be compared as such.

## 3. Which port is the charger on

The charger is on **RID 5 / MagSafe 3**, not on any USB-C port:

- RID 5 register 0x11 contains ASCII `S109YFA000000P`, matching the adapter
  serial `F16HS109YFA000000P`.
- `Port-MagSafe 3@1` has `ConnectionActive = Yes`, `Plug Event Count = 2`,
  `TransportsActive = ("CC")`; all three USB-C ports have
  `ConnectionActive = No`.
- `Port-MagSafe 3@1` `FeaturesSupported = ("Power In")` only — the MagSafe
  port does no USB data, no DisplayPort, no USB3.

## 4. Negotiated power contract (OBSERVED)

From `Port-MagSafe 3@1/Power In/USB-PD` (`IOPortFeaturePowerSource`):

```
PowerSourceOptions (fixed PDOs):
  5 V  / 2.960 A / 14.80 W
  9 V  / 2.970 A / 26.73 W
 15 V  / 2.980 A / 44.70 W
 20 V  / 3.390 A / 67.80 W
WinningPowerSourceOption: 20 V / 3.390 A / 67.80 W
```

A second source node `Port-MagSafe 3@1/Power In/Brick ID` advertises
`5 V / 0.500 A / 2.50 W` at the lowest priority (18446744073709551116). That is
the low-power identity channel used to interrogate the brick before the main
contract is established.

The adapter is a 70 W unit negotiated at 67.8 W, consistent with
`Wattage (W): 68` in `SPPowerDataType`.

## 5. HPM register space

`hpmdiagnose` dumps the whole register file per RID without privileges. Registers
0x00–0x7f plus two named records `HChk` and `ADCr`; 114 registers on
RIDs 0/1/2, 113 on RID 5 (no `ADCr`).

Determinism: two consecutive runs were compared. Registers 0x11, 0x42, 0x6a,
0x74, 0x7b change (live timers/counters). The identity registers 0x47, 0x49,
0x4a, 0x2f are stable. Anything derived from a volatile register must be
re-sampled, not cached.

### 5.1 Register 0x2f — HPM identification record (OBSERVED)

RID 0/1/2: `SN2012025 HW00A4 FW003.115.00 ZACE3-J714P01`
RID 2: `... ZACE3-J714P2`
RID 5: `... ZACE3-J714P5`

Fixed 64-byte ASCII field. The trailing digit is the instance suffix.

### 5.2 Register 0x49 — SOP' (cable) identity page (OBSERVED structure)

Read by the driver with length 0x40. Field semantics recovered from
`AppleHPMDeviceHAL::getRXSOPpData` and `AppleHPMInterface::isCableKartCapable`
(see `evidence/applehpm-decompiled.md`).

| offset | width | meaning | RID 5 value |
|---|---|---|---|
| 0 | 3 bits (low) | count of valid SOP' VDO entries, saturates at 6 | 0x54 & 7 = 4 |
| 1..2 | u16 LE | vendor ID | 0x05AC |
| 4 | bits 5:3 | cable type: 3 = passive, 4 = active | 3 = passive |
| 9..12 | VDO word, byte-reversed | product ID 0x7800 / bcdDevice 0x3200 | 0x78003200 |
| 13 | bits 1:0 | gate for the "capable" return value | — |

`0x78003200` = (0x7800 << 16) | 0x3200. This independently corroborates both
the IOKit-reported PID 0x7800 and the reported firmware 3.2.0.

Passive classification matches IOKit: `Port-MagSafe 3@1` reports
`ActiveCable = No`. Two independent sources agree, so OBSERVED.

### 5.3 Register 0x4a — SOP' vendor string (OBSERVED)

RID 5, 54 bytes:

```
40 00 ... (26 bytes) ... 8a AC 05 00 78 41 70 70 6C 65
                          ^  ^^^^^  ^^^^^  "Apple"
                          |  VID     PID
                          marker
```

`AC 05` = 0x05AC little-endian, `00 78` = 0x7800 little-endian, then the
manufacturer string `Apple`. RID 0 carries `AC 05 06 72` + `Apple Inc.`, i.e.
PID 0x7206 — a different attached device identity on that port. RIDs 1 and 2
have this register all-zero (nothing attached).

### 5.4 Register 0x47 — identity summary, static per controller (UNVERIFIED meaning)

Identical on RIDs 0, 1 and 2 (`06 AC 05 40 D5 ...` + two `15 31 1D 73`
timestamps), different on RID 5 (`03 AC 05 60 1C ...`). Contains the Apple VID
0x05AC in both. Because it is byte-identical across three ports that have
nothing attached, it is host-side or sticky state, not a live attachment record.
Do not use it to identify the attached accessory. Field semantics unresolved.

### 5.5 Other notable registers

- 0x11: live; starts with adapter/port status nibbles, changes between runs.
- 0x16/0x17: 11-byte mode blocks; 0x17 `03 1B 0E 00 01 02 02 F0 00 03 00` is
  identical on all four RIDs — static configuration.
- 0x28/0x29: 64-byte status bitmaps, mostly static.
- 0x2c/0x2d: 48/52-byte records containing the controller UUID
  (e.g. `F3B36E2C-F945-4610-17CD-3B5F94352A1C` on RID 0). The same UUID appears
  in register 0x05.
- 0x6a, 0x71, 0x79, 0x7d, 0x7f, `HChk`, `ADCr`: live measurement/counter data.
- 0x4f: 29-byte record ending in ASCII `Adap...` — a truncated "Adapter" string.
- 0x35/0x36 on RID 5: `53 4D 85 45 53 41 06 00 20 2E ...` (`SM` + `ESA`),
  consistent with SMC mailbox traffic.

## 6. IOAccessoryManager surface

`Port-MagSafe 3@1` properties of interest:

```
IOUserClientClass      = IOAccessoryManagerUserClient  (held by accessoryd, pid 668)
IOAccessoryManagerType = 3
PortType               = 17
ConnectionActive       = Yes
TransportsSupported    = ()
TransportsActive       = ("CC")
AuthenticationRequired = No
AuthenticationStatus   = 0  ("Idle")
AuthorizationRequired  = No
UserAuthorizationStatus= 0  ("Not Required")
HPDAsserted            = No
Metadata               = {"Product ID (SOP1)"=30720, "Vendor ID (SOP1)"=1452}
BuiltIn                = Yes
```

`AuthenticationRequired = No` on the MagSafe port means the cable is not
required to authenticate for power delivery. That is a concrete, verified
statement about the trust boundary; it says nothing about whether an
authentication path exists for other purposes.

## 7. Unprivileged access — what a normal user can actually do

- `ioreg` and `system_profiler`: full port, contract and identity metadata.
- `/usr/bin/hpmdiagnose`: full raw register file for every HPM, no elevation.
  It is platform-signed (`Platform identifier=27`) and carries
  `com.apple.USBCEntitlement` plus
  `com.apple.security.iokit-user-client-class = AppleHPMUserClient`. Access to
  `AppleHPMUserClient` is gated by that entitlement, which third-party code
  cannot obtain, so the capability is available only through Apple's own signed
  binary even though it needs no root.

## 8. Not verified

- The physical mapping of RID 0/1/2 to silkscreened port labels. RID 5 is
  inferred to be the MagSafe controller from its published `Port-MagSafe 3@1`
  child and the adapter serial in register 0x11.
- Whether RID 0's PID 0x7206 identity is currently attached hardware or stale
  state; the port reports `ConnectionActive = No`.
- Register 0x47 field layout.
- Spare/debug register semantics beyond the fields named above.
