# USB-C power / MagSafe firmware update chain — static analysis notes

Host: macOS 27.2.1 (26B131), Apple Silicon **M5 Pro, Mac17,9**
Method: read-only static analysis (`rizin 0.9.1`, `otool`, `nm -m`, `strings`, `plutil`).
No binary, kext, NVRAM or firmware state was modified. Nothing was executed from the target binaries.

Analysis date: 2026-11-11. Analyst: subagent (usbcupdater/usbpowerd task).

## 0. Provenance / hashes

| Artifact | SHA-256 | Notes |
|---|---|---|
| `/usr/libexec/usbcupdater` | `6043edd7aba2e8c1b3b39f8f2eed4accce8ce97274358585fa563759666d23a5` | fat: x86_64, arm64e, arm64e.x1; 317200 B |
| `/usr/libexec/usbpowerd` | `03bd4d7d95c51945512e462a93c34c877b6a09a14960cd532e7ef5e7e45ff6ed` | fat: arm64e, arm64e.x1; 205088 B |
| `/usr/libexec/getPPDVersion` | `1eb073f568e6a3499e4c952c1c457afe2d8a5ed94e55e1136989f8670fd33a28` | fat: arm64e, arm64e.x1; 167280 B |
| `/usr/standalone/firmware/FUD/USBCAccessoryFirmwareUpdater/HPMUtil.efi` | `f3fa46e2a79c04452af2d13c1457af1e6975929dc3ee3063ebf9392f39b50f21` | PE32+ **x86-64** EFI app, 91832 B |
| `.../XPCServices/UARPUpdaterServiceUSBPD.xpc/Contents/MacOS/UARPUpdaterServiceUSBPD` | `f44bd9194d14dfdb0448249c3fb5f3fdf17ed7bc599a27235874da0a1f61aba3` | the real USB-PD/UARP accessory updater |
| `.../XPCServices/USBCAccessoryUpdaterService.xpc/Contents/MacOS/USBCAccessoryUpdaterService` | `ebdf70555aaba5c629ac5436c34c9adc9bfb63af7c4e2a0981fe75d575214290` | dongle/TB-adapter updater |

All disassembly dumps live in `evidence/dumps/` (`usbcupdater.main.asm`, `usbcupdater.fn_<addr>.asm`).
Fat-slice extraction used `lipo -thin arm64e` into the scratch dir; addresses below are arm64e VA
(image base `0x100000000`, `LC_MAIN entryoff 22928` → `main = 0x100005990`).

---

## 1. What the answer actually is (executive summary)

The premise "macOS decides whether a USB-C power adapter or MagSafe cable is firmware-updatable"
maps onto **three independent mechanisms**, not one:

1. **`usbcupdater` = the Mac's own USB-C port-controller firmware launcher** (AppleHPM "Ridge"
   silicon) and the legacy Thunderbolt-switch firmware launcher. It does **not** run a firmware
   update itself. It matches IORegistry hardware against a `Config.plist` personality table,
   builds a **bless(8) firmware-update invocation**, and prints a
   `FirmwareUpdateLauncher` plist to stdout. The actual flashing is done at **boot, in EFI, by
   `HPMUtil.efi` / `ThorUtil.efi`** — not by a kext, not over USB-PD, not over UARP. (CONFIRMED)
2. **`usbpowerd` is not a firmware or USB-PD daemon at all.** It is a **USB bus-current /
   power-pool arbitration daemon** (SMC power pool, `UsbBusCurrentPoolID`,
   `kUSBBusCurrentAllocation`). It opens **no IOKit user client** and originates **no USB-PD
   messages**. It has zero firmware/UARP strings. (CONFIRMED — see §3)
3. **Wall adapter / MagSafe cable firmware is handled elsewhere**, by
   `UARPUpdaterServiceUSBPD.xpc` — **UARP over USB-PD Structured VDMs** (SOP / SOP' / SOP'')
   with Apple Accessory Mode 7 + CFU. That binary contains the `UARPAppleHPM`,
   `UARPPowerAdapter`, `UARPMagSafeCable` classes. (CONFIRMED — see §5)
   `usbcupdater` never touches an adapter or a cable.

`getPPDVersion` is unrelated to any of this: it is **PrinterSupport** (PPD `FileVersion`
harvester). (CONFIRMED — see §4)

So: **adapter/cable eligibility and transport = `UARPUpdaterServiceUSBPD` + CoreUARP**, while
**`usbcupdater` = host HPM port-controller firmware via EFI payload**. Two different transports:
*UARP-over-USB-PD-VDM* (accessory) vs *bless → EFI payload → HPM I2C/SPI* (host silicon).

---

## 2. `/usr/libexec/usbcupdater` — launcher, not a flasher

### 2.1 Link surface (CONFIRMED, `otool -L`, `nm -u`)

Links only Foundation, CoreFoundation, IOKit, libobjc. **No private framework, no IOKit user
client** — imports are exclusively registry-read APIs (`IORegistryEntryFromPath`,
`IORegistryEntrySearchCFProperty`, `IOServiceMatching`, `IOServiceGetMatchingServices`,
`IORegistryEntryGetParentEntry`). Notably **no `exec*`/`posix_spawn`/`fork`** and no `NSTask`:
it therefore never runs `bless` itself — it only *emits* the invocation. (CONFIRMED)

Man page (`/usr/share/man/man8/usbcupdater.8`, CONFIRMED): "updates components required by the
USB-C subsystem… intended to be used by **FirmwareUpdateLauncher** and is not intended to be
called directly by the user".

### 2.2 CLI options (CONFIRMED, getopt_long table at `0x10000c000`, optstring `"vp:Xs"` at `0x100007ff7`)

| Short | Long | Arg | Effect |
|---|---|---|---|
| `-v` | `--verbose` | – | sets verbose flag (`var_694h`); dumps board ID, personality dir, per-personality `CONFIG_*` fields |
| `-p` | `--payload` | **yes** | payload root dir; personalities dir becomes `<arg>/USBCUpdater/` (`stringWithFormat:@"%@/%@"`, `0x100007ffd` + `"USBCUpdater"` `0x100008004`) |
| `-X` | `--preflight` | – | accepted; re-enters getopt loop (no observable side effect in this build) |
| `-s` | `--subupdater` | – | accepted; no observable side effect in this build |
| `-b` | `--bypassVersion` | – | sets the same byte (`selrefs+0x178`) that makes `func_0x100001ad8` compare plain `Version` instead of `Existing Min/Max Version` → bypasses the fw version-range gate |

Runtime bypass (CONFIRMED, `main` 0x100005c30–0x100005d00): reads `boot-args` from
`IODeviceTree:/options`; if it contains `usbcupdater_bypass_usbc_updates` (≠ `"0"`) it prints
`"USB-C Updates bypassed because usbcupdater_bypass_usbc_updates boot arg was set"` and exits 0.
`usbcupdater_bypassversioncheck` is the second accepted token (same parser, `0x100007fd8`).

### 2.3 Hardware identification (CONFIRMED, `func_0x1000008d0` / `func_0x100000a2c`)

* `board-id` ← `IORegistryEntryFromPath("IODeviceTree:/")` +
  `IORegistryEntrySearchCFProperty(plane="IODeviceTree", opts=1 /*recursive*/)`. Required to
  start with `"Mac-"`; the hex digits after it are parsed with `strtoull(base 16)` → `Board ID`.
  (e.g. `Mac-XXXXXXXXXXXX` → 48-bit board id.)
* `board-rev` ← same search, first byte only → `Board Revision`.
  Wrong prefix / missing → `board ID = 0`, prints
  `"No supported hardware on this platform?"` (`0x1000084c2`).

### 2.4 Personality table (`Config.plist`) — the eligibility database (CONFIRMED)

`func_0x100000b5c` builds `<personalities dir>/Config.plist` with two
`stringByAppendingPathComponent:` calls, reads it, and parses with
`NSPropertyListSerialization propertyListWithData:options:format:error:`.
Error strings: `"Error reading plist: No files to support boardID: %@"` (`0x100007b19`),
`"Error reading plist: No config file for this project"` (`0x100007b4e`),
`"Error reading plist: %@, format: %lu"` (`0x100007b83`).

**On this Mac the personalities tree does not exist** — `find / -iname '*USBCUpdater*'` yields
only the binary and the man page; `/usr/standalone/firmware/FUD/USBCAccessoryFirmwareUpdater/`
contains only `HPMUtil.efi`, no `Config.plist`. So `usbcupdater` on this machine reaches
error-exit; the personality data is supplied by the *installer/update payload* (the FUD payload
that ships with an update), not by the base system. (CONFIRMED absence, INFERRED provenance)

Personality schema — every key observed as a CFString (CONFIRMED, `__cfstring` 0x10000c0c0..ca80):

```
Personality Type      : "Thunderbolt" | "LegacyThunderbolt" | "USBC" | "LegacyUSBC"
MinBoardRevision      : int
MaxBoardRevision      : int
IOService             : "AppleHPMDevice" | "IOThunderboltSwitch"
Address / Port Address: int  (port index / PCI address)
UUID / Port UUID      : string
Revision / Port OTP Revision : int
Vendor ID / Device ID / Revision ID
  = "Ridge Silicon Vendor ID" / "Ridge Silicon Device ID" / "Ridge Silicon Revision" (mapped 1:1)
Device Model Name / ID / Revision
Firmware Mode, Ridge UID, ROM Version, EEPROM Revision, Version, Engineering Version
Existing Min Version / Existing Max Version     <-- fw version range gate
Firmware      : payload file name
Priority      : int
SetNVRAM      : { key: value }
ClearNVRAM    : [ key ]
```

IOKit keys read from the live node and compared to personality keys (CONFIRMED, string pairs at
`0x100007bb0`–`0x100007d4e`): `Vendor ID`→`Ridge Silicon Vendor ID`, `Device ID`→
`Ridge Silicon Device ID`, `Revision ID`→`Ridge Silicon Revision`, `Device Model Name/ID/Revision`,
`Firmware Mode`, `Ridge UID` (0x%llX), `ROM Version`, `EEPROM Revision`, `Version`,
`Engineering Version`, `Port Silicon Vendor ID/Device ID/Revision`, `Port OTP Revision`,
`Port Address`, `Port UUID`, plus `Depth`/`Route String` for `IOThunderboltSwitch`.

### 2.5 Matching + version gates (CONFIRMED)

`main` → `func_0x1000041cc` (orchestrator, 6084 B) calls, in order:

| callee | role |
|---|---|
| `func_0x100001544` | IOKit enumeration; `IOServiceMatching("AppleHPMDevice")`, `IOServiceMatching("IOThunderboltSwitch")`, walks plane `"IOService"` (0x100007d58) |
| `func_0x1000013c4` | match/assemble candidate set |
| `func_0x10000218c` | HPM port checks: `"** Missing port silicon revision key(s)"`, `"** Missing port OTP revision key(s) **"`, `"** Missing port UUID(s)"` (0x100007e83/eac/ed4) |
| `func_0x100002ea8` | same set for the USBC personality branch + version gate |
| `func_0x100001ad8` | **version gate** (see below) |
| `func_0x100003a18` | final filter (board revision + Address membership + priority) |

`func_0x100001ad8(personality, hardware)` — the eligibility decision:

```
minV = personality[ verbose ? "Existing Min Version" : "Version" ]
maxV = personality[ verbose ? "Existing Max Version" : "Version" ]
cur  = hardware["Version"]
if cur == NULL                       -> "** No current firmware version?"          -> reject
if minV not NSNumber                 -> "** minversion bad object type in personality" -> reject
if !(cur >= minV)                    -> "** Min firmware version not met.  Aborting"  -> reject
if maxV not NSNumber                 -> "** maxversion bad object type in personality" -> reject
if maxV < cur                        -> "** Max firmware version not met.  Aborting"  -> reject
if hardware["Engineering Version"] != 0  -> accept (short-circuits remaining checks)
then: personality["Address"] must intersect hardware["Address"]  (set membership, objc fast-enum)
```
Comparisons go through the NSNumber shims `func_0x1000020e8` (less-than) and
`func_0x100002044` (greater-than). So the *firmware version* gate is a numeric range
(`min ≤ current ≤ max`), and `Engineering Version != 0` is an explicit escape hatch, as is the
`-b` / `usbcupdater_bypassversioncheck` bypass. (CONFIRMED)

### 2.6 Output contract: the `FirmwareUpdateLauncher` plist (CONFIRMED)

Nothing is executed. `main` builds an `NSMutableDictionary` with the CFString key
`"BlessArguments"` (`0x1000084a0`) holding an `NSMutableArray` of argv strings, prints
`"Bless Invocation:"` then `"\n\nResulting FirmwareUpdateLauncher Plist:\n"`, serializes with
`dataWithPropertyList:format:options:error:` and `fwrite`s the raw XML bytes to **stdout**
(`0x1000071cc`–`0x100007230`). `FirmwareUpdateLauncher` (boot-time) consumes that plist.

argv construction:

```
/usr/sbin/bless  -verbose  -mount  /  -firmware  <util>  -folder TBTH  -options <...>  [ -f ]  -noreset
```
* `<util>` — `"HPMUtil.efi"` (0x1000083ee) when Personality Type ∈ {`USBC`, `LegacyUSBC`};
  `"ThorUtil.efi"` (0x1000083e1) when Personality Type ∈ {`Thunderbolt`, `LegacyThunderbolt`}.
  (CONFIRMED at 0x100006914–0x10000697c: compares 0x5a0/0x5e0/0x620/0x600 then appends 0x840/0x860.)
* Literal token order, per branch (CONFIRMED read of `addObject:` targets):
  * common prefix: `"/usr/sbin/bless"`, `"-verbose"`, `"-mount"`, `"/"`, `"-firmware"`,
    `<util>`, `"-folder"`, `"TBTH"`, `"-options"`
  * **USBC / LegacyUSBC branch** (`0x100006a9c`): `-g`, `-o`, `-sr`, `"%u"`(formatted u16),
    `"0"`, then `"-ee"` (when that u16 == 0) **or** `"-fs"` (otherwise), then
    `"efi-apple-payload%u-data"` (index `w28`), `"-payload"`, `<payload path>`
  * **Thunderbolt / LegacyThunderbolt branch** (`0x100006bf4`): `-g`, `-os`, `-o`, `u`, `-f`,
    then `"efi-apple-payload%u-data"`, `"-payload"`, `<payload path>`
  * suffix: `"-noreset"`
  Token *semantics* are **INFERRED / partly unknown**: `-g`/`-sr`, `-ee`/`-fs` look like
  port-address / silicon-revision and EEPROM-vs-flash selectors passed to the EFI util; `-os u`
  in the Thunderbolt branch is unexplained (no usage text exists in either binary).
* Payload path = `<payload dir>/<Firmware name>`; `efi-apple-payload%u-data` is the bless
  `-payload` *label* under which the EFI app is registered.

**Why EFI:** the payload directory is `/usr/standalone/firmware/FUD/USBCAccessoryFirmwareUpdater/`
and `HPMUtil.efi` is a **PE32+ x86-64 EFI application** (verified PE machine `0x8664`). Firmware
write to the HPM/Ridge part happens **pre-boot, from EFI, over the HPM's I2C/SPI path** — not from
macOS, not over USB-PD. This is the Intel/T2-era design; it is shipped unchanged on Apple Silicon,
but see §5 for the live Apple Silicon path. (CONFIRMED file format, INFERRED execution context)

---

## 3. `/usr/libexec/usbpowerd` — bus-current pool daemon (NOT USB-PD, NOT UARP)

### 3.1 What it is (CONFIRMED)

Single ObjC class `USBPowerDevice` (super `NSObject`). All 11 `__cfstring` entries are power
budget keys (`0x1000080e0`–`0x100008220`):

```
idVendor, idProduct, UsbBusCurrentPoolID, UsbSmcBusCurrentPoolID,
UsbPowerSinkCapability, kUSBBusCurrentAllocation, kUSBWakePortCurrentLimit,
kUSBFailedRequestedPower
"%@: power sink capability %d mA port limit %d mA"
"%@: failed power %d mA"
"%@@%@: power pool ID 0x%016llx"
```
Methods: `initWithIOService:queue:error:interestHandler:`, `updatePowerSinkCapability`,
`reducePowerSinkCapability`, `restorePowerSinkCapability`, `setPowerSinkCapability:`,
`lowPowerSinkCapability`, `highPowerSinkCapability`, `allocatedBusCurrent`, `maximumBusCurrent`,
`failedPower`, `powerPoolID`, `chargingPriorityDelay`, `resetWithError:`, `destroy`.

Imports (`otool -L`): Foundation, IOKit, **IOUSBHost**, libobjc, libSystem. IOKit imports are
registry + notification only: `IORegistryEntryCreateCFProperties`, `IORegistryEntrySetCFProperty`,
`IOServiceAddInterestNotification` (IOGeneralInterest), `IOServiceAddMatchingNotification`
(`com.apple.iokit.matching`, `IOServicePublish`, `IOServiceTerminate`), `IONotificationPort*`.

### 3.2 Interfaces opened (CONFIRMED — answering Q2 negatively)

* **No `IOConnectCallMethod` / `IOConnectCallStructMethod` / `IOServiceOpen` at all.**
* **No `IOAccessoryManagerUserClient`, no `AppleHPMUserClient`, no `IOAccessoryManager` string.**
* The only matching class strings are `IOUSBHostDevice` (`0x10000…`, LaunchEvents match) and
  `AppleBusPowerController` (parent node it reads the pool from).
* `allocatedBusCurrent` (`0x100001d14`): `IORegistryEntryGetParentEntry(svc,"IOService")` →
  `IORegistryEntryCreateCFProperty(parent,"kUSBBusCurrentAllocation")`.
* It posts/receives only `kIOUSBHostMessageReallocateExtraCurrent` (cstring `0x100004e06`) via the
  IOGeneralInterest handler, and logs `"attempting to reallocate power for %@"`,
  `"%@: power sink cannot increase"`, `"%@: scheduling reset"`, `"%@: scheduling power sink increase"`.

**Therefore usbpowerd originates no USB-PD messages** (no Discover Identity, no VDM, no SOP)
and plays no role in firmware-update eligibility. It arbitrates mA between USB devices against
an SMC power pool (`UsbBusCurrentPoolID` / `UsbSmcBusCurrentPoolID`), with per-device
`chargingPriorityDelay` and reset/restore timers. It is the "don't let 4 bus-powered devices
brown out the port" daemon. (CONFIRMED by absence of all PD/UARP/user-client strings and imports)

Its launchd job (`/System/Library/LaunchDaemons/com.apple.usbpowerd.plist`, CONFIRMED verbatim):

```
Label            com.apple.usbpowerd
Program          /usr/libexec/usbpowerd
ProcessType      Adaptive
EnablePressuredExit true
LaunchEvents.com.apple.iokit.matching."com.apple.usb.powerSinkDevice" = {
    IOProviderClass      = IOUSBHostDevice
    IOPropertyExistsMatch = [ "UsbPowerSinkCapability" ]
    IOMatchAll           = true
    IOMatchLaunchStream  = true
}
```
i.e. it is demand-launched for any USB host device that publishes a `UsbPowerSinkCapability`
property, and its only job is to keep the sum of granted mA inside the SMC port/pool budget.

No static launchd job references `UARPUpdaterServiceUSBPD` (only `sysdiagnosed` mentions the name
for log collection) — it is an on-demand XPC service vended by MobileAccessoryUpdater. (CONFIRMED)

---

## 4. `/usr/libexec/getPPDVersion` — irrelevant (PrinterSupport)

CONFIRMED: `otool -L` = Foundation, AppKit, **libcups.2.dylib**. Imports include
`_ppdOpenFile`, `_ppdFindAttr`. Embedded ident string:
`@(#)PROGRAM:getPPDVersion  PROJECT:PrinterSupport_Tools-3.0`.

Behaviour (`main` @ `0x100000880`): `argc==2` → `getPPDVersion <dir>`; `argc==3` and
`argv[1]=="-all"` → `getPPDVersion -all <dir>`; anything else → exit 1.
Enumerates `<dir>` with `NSFileManager contentsOfDirectoryAtPath:error:`, keeps entries whose
name `hasSuffix:` `".gz"`/ppd, `ppdOpenFile()` + `ppdFindAttr(ppd,"FileVersion",NULL)`, builds
`{filename: FileVersion}`, serializes with `NSPropertyListSerialization
dataWithPropertyList:` (XML) and `printf("%s", …)` to stdout. Output format string is literally
`"%s"` (`0x100000da8`) — i.e. an XML plist, no header/footer of its own.

There is **no USB, no firmware, no power** content. It is a print-driver installer helper and was
mis-grouped into this binary set. (CONFIRMED)

---

## 5. The real adapter / MagSafe cable updater: `UARPUpdaterServiceUSBPD.xpc`

Path: `/System/Library/PrivateFrameworks/MobileAccessoryUpdater.framework/XPCServices/UARPUpdaterServiceUSBPD.xpc`
Bundle id `com.apple.UARPUpdaterServiceUSBPD`, `"UARP Updater" = true`, built 2021, no
`MatchingDevices` in Info.plist (matching is dynamic).

### 5.1 Frameworks + classes (CONFIRMED)

`otool -L`: **CoreUARP**, UARPUpdaterService, IOKit, Foundation, libcompression, liblzma,
CoreAnalytics, libMobileGestalt.

Classes (from `__objc_classname`): `UARPAppleHPM`, `UARPPowerAdapter`, `UARPMagSafeCable`,
`UARPUSBPDAccessory`, `UARPUSBPDUpdater`, `UARPServiceMonitorBSDNotification`,
`UARPServiceMonitorMatchingRule`, `UARPUpdaterService`, plus CoreUARP's `UARPAccessory`,
`UARPAccessoryHardwareUSBPD`, `UARPSupportedAccessory`, `UARPSuperBinaryAsset*`.

CoreUARP symbols referenced: `kUARPSupportedAccessoryKeyUSBPDDeviceClassMagSafeCable`,
`kUARPSupportedAccessoryKeyUSBPDDeviceClassUSBCLightning`, `kUARPSupportedAccessoryKeyVendorNameApple`,
`kUARPStringBsdNotificationPowerAdapter`, `kUARPStringUSBCLightningDisconnectNotification`,
`UARPAccessoryUSBPDLocationTypeToString`.

### 5.2 Transport (CONFIRMED — answering Q4)

**UARP tunnelled over USB-PD Structured VDMs.** Text evidence, all from this binary:

* Endpoint roles: `"SOP Delegate = <%@>"`, `"SOP Prime Delegate = <%@>"`, `"SOP Type = <%d>"`,
  `"%@ %d bytes on SOP %d for %@"` → messages are addressed to SOP (port partner = adapter),
  **SOP' (cable e-marker)** and by extension SOP''.
* PD discovery: `processVDOs`, `processAppleVDO`(+`s`), `processCapabilityVDO`,
  `processEndpointVDO`, `"Failed to process Apple VDOs"`, `"Process Apple VDO failed"` — i.e.
  **Discover Identity** VDO parsing including Apple-defined VDOs, plus endpoint/capability VDOs.
* VDM I/O: `-[UARPAppleHPM sendVDM:buffer:length:flags:error:]`,
  `receiveVDM:…checkSequence:maxRetries:lengthReceived:error:`, retry statistics
  (`"RX VDM Average/Max/Min Retries"`, `"RX VDM Retried"`, `"RX VDM Expected 0x%08x, got 0x%08x"`)
  → chunked, sequenced, retried VDM messaging.
* Host-side HPM access: `_IOCreatePlugInInterfaceForService` + `IOServiceMatching("AppleHPMDevice")`
  → it does **not** open a raw user client; it loads the IOKit **plug-in** family interface
  (`UARPHPMProtocol`) for the AppleHPMDevice nub and sends VDMs through it. Logs
  `"Look for power adapters on all HPMs"`, `", SOP Type = <%d>"`, `", SOP Delegate = <%@>"`.

### 5.3 Multiple simultaneous accessories (CONFIRMED)

`"USB-PD Accessory Set (%d) is %@"`, per-accessory `"usbpd = %@"`, `"usbpd = %@, assetID = %@"`,
`"Found Power Adapter %@ %@"`, `"No power adapters"`, `"Force check for power adapters because
power adapter notification"`, `"Requesting Power adapter discovery after %u seconds"`,
`"Power assertion held for %@"` / `"Already released power assertion for USBPD"`
(keeps the Mac awake / port powered during flash).

### 5.4 Adapter vs MagSafe cable — the distinguishing code path (CONFIRMED)

Two dedicated classes, i.e. the branch point:

| | **wall / power adapter** | **MagSafe cable** |
|---|---|---|
| class | `UARPPowerAdapter` | `UARPMagSafeCable` |
| methods | `firmwareApply:`, `firmwareHasStagedAssets:`, `firmwareRescind:`, `solicitAnalytics:error:`, `solicitLogs:` | `queryHardwareVersion`, `querySerialNumber:` |
| transport | PD **SOP** to the adapter | PD **SOP'** to the cable e-marker |
| Apple switch | `", MagSafe = <%d>"` — a boolean carried in the accessory descriptor, distinguishing a MagSafe-attached power path from a plain USB-C adapter | |
| legacy path | `UARPAppleHPM(LegacyPA)` — `legacyPAFirmwareUpdateInitialize:`, `…WriteData:offset:error:`, `…VerifyStagedAsset:`, `…FirmwareUpdateCleanup:` for adapters that do **not** support Apple AccMode7 | (cables always use the AccMode7/CFU path) |

So: **same VDM transport, different addressed endpoint (SOP vs SOP') and different flash state
machine**. A MagSafe cable exposes hardware version + serial number and is updated through the
e-marker's CFU; a wall adapter either uses the modern AccMode7 CFU path or the `LegacyPA`
byte-stream path.

### 5.5 The flashing protocol: Apple Accessory Mode 7 + CFU (CONFIRMED strings)

Phase log strings, in order, expose the state machine:

```
USB-PD UARP updater started
USB-PD Init - Check Idle State
USB-PD Init - Check Transfer State
USB-PD Init - Init Complete
USB-PD Init - Set State -> Start
USB-PD Init - Flash Erase
USB-PD Write Block
USB-PD Verify Staged Asset
USB-PD Staged Asset Verified
USB-PD Apply Staged Asset
USB-PD Update Cleanup
USB-PD Rescind Staged Asset
```
Primitives: `setCFUp` (`"Enabled CFUp"`/`"Disabled CFUp"`, `"iecsCommand(CFUp) failed"`),
`readCFUa:remoteEndpoint:offset:buffer:bufferLength:lengthRead:error:`,
`writeCFUa:remoteEndpoint:offset:…`, `writeCFUs:remoteEndpoint:protocol:…`,
`doAtomic4CC:data:dataLength:extData:…` (4CC register access, `"doAtomic4CC failed"`,
`"4cc operation failed <0x%02x>, taskResult <0x%X>, iteration %d"`).
Firmware commands: `kAccMode7FirmwareCommandStart/Manifest/Apply/Reset`,
`kAccMode7Mode7FirmwareUpdateControl`, and wrappers
`accMode7FirmwareUpdateInitialize`, `…SendCommand:error:`, `…GetState:error:`,
`…HasStagedAssets`, `…Rescind`, `…UpdateAllowed`, `accMode7StagedFwVersion`,
`accMode7AddressSpaceRead/Write`, `accMode7SetLogLevel`, `accMode7ClearLogs`,
`accMode7SolicitLogs:modelName:serialNumber:`.
CFU = USB-PD "Component Firmware Update" addressed as CFUp (protocol/control), CFUa
(address space), CFUs (structured/segment).

### 5.6 Update eligibility on the accessory path (CONFIRMED + INFERRED)

Observed hooks:
* `UARPSupportedAccessory` + device-class keys (`MagSafeCable`, `USBCLightning`, `VendorNameApple`)
  — CoreUARP's compiled-in supported-accessory table is the allow-list. **INFERRED**: this table
  (not a plist on disk) holds VID/PID + device class + fusing/hardware-version constraints;
  CoreUARP ships only inside the dyld shared cache, so it could not be dumped on-disk.
* `-[UARPUSBPDUpdater disabledProductIdentifiers]` (0x…) — a block that filters out specific
  VID/PID pairs → explicit per-product disable list.
* `assetAvailablityUpdateForAccessoryID:assetID:` / `assetNotFound:` / `assetOnAssetServer:` /
  `assetOnDropbox:` / `assetOnLocalStorage:` — eligibility is *also* "is there an asset":
  assets arrive via `UARPAssetManager`/`UARPiCloud`/DAS (`dasActivityReceived`), so a device can
  be perfectly updatable yet get no update because no asset matches its `UARPAssetID`
  (vendor+product+hardware-version tuple).
* Hardware-identity queries that feed the asset ID: `queryHardwareVersion`, `querySerialNumber:`
  (cable), `accMode7StagedFwVersion` (adapter), plus fusing info
  (`UARPAccessoryHardwareFusingToString`).
* `"Unknown UARPAccessory %@, dropping it"` / `"Unknown UARPAccessoryID %@, dropping it"` — a
  device whose descriptor isn't in the table is silently dropped (not an error).

### 5.7 launchd / scheduling (CONFIRMED strings)

`USBPDPeriodicLaunchActivity` (XPC activity, `_XPC_ACTIVITY_REQUIRE_NETWORK_CONNECTIVITY`
imported for asset download), `bsdNotificationReceived:` reacting to
`kUARPStringBsdNotificationPowerAdapter` and `kUARPStringUSBCLightningDisconnectNotification`,
`assetSolicitationProgress:…bytesReceived:bytesTotal:`, `firmwareStagingProgress:…bytesSent:…`.
So updates are staged on a periodic activity while plugged in, and applied later.

---

## 6. The *other* accessory updater: `USBCAccessoryUpdaterService.xpc` (dongles, not power)

`com.apple.MobileAccessoryUpdater.USBCAccessoryUpdaterService`, `NSPrincipalClass =
USBCAccessoryFirmwareUpdater`, `"Groups" = ["Modal UI"]`, `RemoteFirmwareCheckInterval = 48` (hours).
This is the **dongle/TB-adapter** updater and is where an "embedded plist describing supported
accessories" actually exists. Full `MatchingDevices` table (CONFIRMED, verbatim from Info.plist):

| DeviceClass | DeviceClassName | Match |
|---|---|---|
| `…usbcupdater.ThunderboltType1Switch` | Thunderbolt 3 (USB-C) to Thunderbolt 2 Adapter | `IOProviderClass = IOThunderboltSwitchType1`, `IOMatchLaunchStream` |
| `…usbcupdater.ThunderboltType2Switch` | Thunderbolt 3 (USB-C) to Thunderbolt 2 Adapter | `IOProviderClass = IOThunderboltSwitchType2` |
| `…usbcupdater.USBCBillboard-HDMI` | USB-C Digital AV Multiport Adapter | `IOUSBDevice`, `idVendor=1452 (0x05AC)`, `idProduct=5216 (0x1460)` |
| `…usbcupdater.USBCBillboard-VGA` | USB-C VGA Multiport Adapter | `IOUSBDevice`, `idVendor=1452`, `idProduct=5217 (0x1461)` |
| `…usbcupdater.USBCHDMIAdapter` | USBCHDMIAdapter | `IOUSBHostDevice`, `idVendor=1452`, `idProduct=4119 (0x1017)`, `NeedsDeviceIdleCheck` |

All entries: `MatchingType = com.apple.iokit.matching`, `NeedsBootstrapping = true`,
`SilentUpdateNoUI = true`.

Bundled firmware images (CONFIRMED, `Contents/Resources/`):
`usbcfw-0x1460-2.35.bin` (131584 B) and `usbcfw-0x1657-3.56.bin` (506404 B) — naming is
`usbcfw-<productID in hex>-<version>.bin`; `0x1460` matches the Digital AV Multiport Adapter PID.
`0x1657` has no match in the table above → **INFERRED**: either a newer adapter matched by a
different rule, or a chip-ID-keyed image (PID 0x1657 = 5719).

Note there is **no power-adapter or MagSafe entry** in this table: proof that adapter/cable
firmware does not flow through the USB-C dongle updater either.

---

## 7. Corrections to the task premise (important)

| Premise | Reality |
|---|---|
| usbcupdater is "a launcher/CLI wrapper — identify what framework does the real work and what plist/service name it drives" | Right that it's a wrapper, but the "framework" is not a userspace framework: the work is an **EFI application** (`HPMUtil.efi`/`ThorUtil.efi`) invoked by **`bless -firmware`** at boot, driven by a printed **`BlessArguments`** plist consumed by `FirmwareUpdateLauncher`. No service name, no XPC, no kext. |
| usbcupdater handles adapters/MagSafe cables | It handles the **Mac's own AppleHPM port controller** ("Ridge"/"Port Silicon") and legacy **IOThunderboltSwitch**. Zero adapter/cable/PD strings in the binary. |
| usbpowerd opens IOAccessoryManagerUserClient / AppleHPMUserClient and negotiates USB-PD roles | **False.** No user client, no PD. It is an SMC **bus-current pool** arbiter. |
| getPPDVersion prints USB-C power info | **False.** PrinterSupport PPD `FileVersion` harvester. |
| UARP over USB-PD is one code path | It is, but it lives in **`UARPUpdaterServiceUSBPD.xpc`** (CoreUARP), with SOP→adapter / SOP'→cable split and an AccMode7-CFU vs `LegacyPA` split. |

---

## 8. Open questions / not recovered

* `Config.plist` personality data for this board — not present on-disk; lives in the FUD payload
  shipped by an update. Would need an extracted FUD/payload image to enumerate.
* CoreUARP supported-accessory table (VID/PID/device-class/fusing matrix) — only in the dyld
  shared cache; not dumped here.
* Exact `-g`/`-sr`/`-ee`/`-fs` token semantics for `HPMUtil.efi` — needs the EFI binary's arg
  parser (PE32+ x86-64; `strings` shows no usage text).
* `IOAccessoryManager.kext` has no on-disk Mach-O (kernel collection only) → the kernel side of
  the VDM transport (`IOAccessoryManagerUserClient` selectors) was not enumerable on this host.
