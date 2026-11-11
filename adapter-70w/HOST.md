# HOST — where the adapter metadata comes from, and whether macOS updates it

Read-only. No SMC write, no adapter command. Serials are redacted.

## 1. Publisher of `AdapterDetails`

- **`AdapterDetails` and `AppleRawAdapterDetails` live on the `AppleSmartBattery`
  node**, whose parent is `AppleSmartBatteryManager`
  (`CFBundleIdentifier = com.apple.driver.AppleSmartBatteryManager`,
  `IOProviderClass = AppleSMC`). OBSERVED via `ioreg -w0 -l -c AppleSmartBattery`
  and `kmutil showloaded`.
- **`AppleSmartBatteryManager 161.0.0` is loaded** and its kernelcache fileset
  holds the exact key set seen in ioreg, in dictionary order, including
  `AdapterDetails | AppleRawAdapterDetails | AdapterID | FamilyCode |
  FwVersion | HwVersion | Model | Manufacturer | Name | UsbHvcMenu`.
  OBSERVED by decompressing the Preboot kernelcache (IMG4/LZFSE) and parsing
  `LC_FILESET_ENTRY`; see `evidence/host/findings.md` for the method.
- **`AppleARMPMU` has the same keys but instantiates nothing here.** OBSERVED:
  `IOKitDiagnostics` class counts give `AppleARMPMUPowerSource = 0`,
  `AppleARMPMUCharger = 0`, `AppleSMCChargerFunction = 0`, while
  `AppleSmartBattery = 1`. So the AppleARMPMU charger path is not the active
  producer on this host.

The kext strings show how the dictionary is filled: `Reading adapter details at
port %d`, `Failed to read nominal voltage rating key %c%c%c%c`,
`Port:%d AdapterID: %d`, `Port:%d Firmware ver: %s`, `Port:%d Serial: %s`,
`Port:%d Model: %s`, `Port:%d vendor: %s`, `Port:%d Name: %s`. OBSERVED in
`evidence/kernelcache.bin`. The reads are per-port, four-character-key lookups.

## 2. What the fields actually prove

| field | value | basis |
|---|---|---|
| `Model` / `AdapterID` | `"0x701C"` / `28700` | same number; equals the PID in HPM reg `0x43` (OBSERVED equality; copy path not shown) |
| `FwVersion` | `"01030030"` | updater logs the same accessory as `fw=1.3.30` (OBSERVED) |
| `HwVersion` | `"1.0"` | naming only; the UARP record says `hwRevision=unknown` (UNVERIFIED as a hardware revision) |
| `Watts` | `68` | the negotiated 20 V × 3.39 A contract, not the 70 W nameplate |
| `UsbHvcMenu` | 5/9/15/20 V, 2.96–3.39 A | byte-equal to reg `0x30` and `PortControllerPortPDO` |
| `SerialString`, `Manufacturer` | adapter serial, `Apple Inc.` | match the UARP accessory record |
| `FamilyCode` | `0xE000400A` (stored sign-extended) | encoding OPEN |

- **INFERRED, medium:** the fields are PD-derived in value (they are exactly
  what Discover Identity and source caps yield, and they agree numerically with
  the PD-facing registers), but no host trace shows the transfer. The SMC
  transport is not observable read-only.
- **REFUTED:** "the model number is exposed via `AdapterDetails`". `A2743`
  appears nowhere in ioreg, in the kext strings, or in the updater service; the
  dictionary carries the PID only.
- **Firmware string:** do not call `"01030030"` hexadecimal. The property is a
  string and both a zero-padded decimal reading (1030030) and a hex reading
  (0x01030030) fit it. The updater's `fw=1.3.30` for the same accessory shows
  the subsystems agree on one number but does not settle the decomposition.
  OPEN.

## 3. The updater stack

Examined read-only:
`…/MobileAccessoryUpdater.framework/XPCServices/UARPUpdaterServiceUSBPD.xpc`
and `…/Support/accessoryupdaterd`.

- **Selection is by Apple model number**, not VID/PID or transport:
  `AppleModelNumber %@ from accessory does not match expected model number %@`,
  `initWithModelNumber:`, `findByAppleModelNumber:`. VID/PID gates exist only for
  the MagSafe and Dongle classes; there is no adapter VID/PID gate. OBSERVED.
- **No literal `A2743`, `701C` or `28700`** in either on-disk binary (count 0).
  The supported set is not a compiled table there. OBSERVED.
- **`A2743` is, however, a compiled literal in CoreUARP** inside
  `dyld_shared_cache_arm64e.28` (one occurrence, in a cstring block next to
  `UARPUploaderUARP` selectors, alongside other `A####` model literals).
  CoreUARP has no executable on disk — only `Resources/` — which is why a grep
  of the two on-disk binaries missed it. So macOS does know the adapter as a
  UARP target. OBSERVED, verified by the parent.
- **The supported-accessory table was not located.** `uarpAccessories.plist`
  under `/private/var/db/accessoryupdater/` returns ENOENT, not EACCES, so the
  earlier statement that the table lives there is **unconfirmed**. The
  directory interior is mode 711 and unreadable as a normal user. **Blocked**.
- **Power-adapter classes exist:** `UARPPowerAdapter`, `UARPUSBPDUpdater`,
  `UARPAppleHPM`, `Apply staged assets to power adapter`,
  `Found a supported power adapter, check for update %@`,
  `Not supported power adapter (by hardware id) on this HPM %u`. OBSERVED
  strings.
- **Asset naming is `com.apple.MobileAsset.UARP.<model>`.** Local caches hold
  A2363, A2515, A2968, A3048; there is no A2743 cache. OBSERVED.

## 4. Positive evidence that macOS does try

`log show` records, observed on this host and reproduced by the parent:

```
accessoryupdaterd … accessory <UARPAccessoryID: … model=70W USB-C Power Adapter
  modelNumber=A2743 hwFusing=prod sn=<redacted> fw=1.3.30 stagedFW=0.0.0 >
accessoryupdaterd … Overriding asset location for A2743 from (null) to https://mesu.apple.com/assets/macos
accessoryupdaterd … Got the download meta data reply for
  com.apple.MobileAsset.UARP.A2743, response: 43 (MADownloadNotFoundOrDenied)
```

- The host recognises the adapter as a UARP-over-USB-PD accessory, applies a
  model rule, checks for an update, and never logs "not supported" for it. That
  refutes "macOS treats the 70 W brick as non-updatable hardware". OBSERVED.
- Delivery is blocked: the asset query returns `43` every time (3 occurrences in
  the 30-day window), `stagedFW` never leaves `0.0.0`, and no staging or apply
  message exists. OBSERVED.
- **Verdict: update-capable in the protocol sense, not update-delivered.**
  Whether Apple ever published an A2743 payload is OPEN; see `DISTRIBUTION.md`
  for the registry evidence.

## 5. Open questions

- Where the supported-accessory table actually lives: `uarpAccessories.plist`
  returned ENOENT, and the directory interior is unreadable without root. OPEN.
- Whether staging would occur over a CC-only VDM channel
  (`TransportsSupported = ()`, `Metadata = {}` on the MagSafe port).
- Which 4CC SMC keys feed each field, and whether the SMC or the HPM composes
  the adapter record.
