# Firmware acquisition notes — Apple 70W USB-C adapter & MagSafe 3 cable

Read-only research. Nothing flashed, nothing installed, no credentials entered.
All work under `<artifact-root>/` (outside any git repo).

Session: 2026-11-11, ~15:23–15:31 UTC. macOS host, curl 8.x with a Safari desktop User-Agent.

---

## 1. Endpoint reachability (exact HTTP status codes)

| URL | Status | Notes |
|---|---|---|
| `https://gdmf.apple.com/v2/pmv` (GET) | **200** | 88,597 B JSON, OS release catalog only |
| `https://gdmf.apple.com/v1/pmv` | 404 | v1 retired |
| `https://gdmf.apple.com/v2/assets` (GET) | **400** | Rejects GET; JWT-wrapped error "GET request not allowed: /v2/assets" |
| `https://gdmf.apple.com/v2/assets` (POST) | **200 / 404** | Pallas asset query — this is the live one |
| `https://gdmf.apple.com/v2/pmv` (POST) | 403 | "Request method not allowed: POST: /v2/pmv" (GET-only) |
| `https://mesu.apple.com/` | 404 | No directory browsing |
| `https://mesu.apple.com/assets/macos/com_apple_MobileAsset_TimeZoneUpdate/...xml` | **200** | Control path proves mesu serves assets anonymously |
| `https://updates.cdn-apple.com/<asset path>` | **200** | Payload CDN, `binary/octet-stream`, no auth |

**Important correction to the briefing's assumption:** `mesu.apple.com` is *not* gated.
A missing asset type returns `403` with body `<h1>not found</h1>` (19 bytes) — this looks
like an auth failure but is a not-found. A path that exists returns `200`. Do not read a 403
from mesu as "blocked". (One CDN edge served the same not-found with `Content-Length: 111`
and a stale `Date`; the body is still the 19-byte `not found`.)

Responses from gdmf are **JWT-wrapped** (`ES256`, x5c chain, payload field 2 = base64url JSON).
The error strings are the useful part: Apple distinguishes
`"AssetType not found for: <type>"` (type does not exist) from
`"Active not found for <uuid>#<audience>"` (type exists, nothing published for that audience).

## 2. Asset-type discovery

Apple publishes accessory firmware as MobileAsset type `com.apple.MobileAsset.UARP.<model>`,
one type per hardware model number. These are **not** in any catalog index; the only
enumerable source was the community-maintained list of asset types, then direct probing.

Probed 281 known `com.apple.MobileAsset.*` type names against mesu (both `<type>` and
`macos/<type>` path shapes) and grepped every reachable manifest for
`70W|Power Adapter|MagSafe`. Result set:

| Asset type | DeviceName in manifest | Firmware |
|---|---|---|
| `UARP.A2363` | USB-C to MagSafe 3 Cable (2 m) | **3.2.0** (10M13722) |
| `UARP.A2452` | 140W USB-C Power Adapter | 1.4.90 (10M13554) |
| `UARP.A2571` | 35W USB-C Power Adapter | 1.3.66 (10M1009) |
| `UARP.A2676` | 35W USB-C Power Adapter | 1.7.76 (10M1033) |
| `UARP.A2384` | MagSafe Battery Pack | 2.7.11 (10M804) |
| `UARP.A2140` | A2140 (unidentified) | 258.0.0 |

**No asset type exists for the 70W adapter.** Model number for the 70W USB-C Power Adapter
is **A2743** (confirmed by Apple support doc 102378: "Tested with Apple 70W USB-C Power
Adapter (Model A2743) with USB-C to MagSafe 3 Cable (Model A2363)").

## 3. MagSafe 3 cable — CONFIRMED, 3 versions acquired

Model A2363, which is exactly the MagSafe 3 cable (USB PID 0x7800, bcdDevice 0x3200).

Manifest `com_apple_MobileAsset_UARP_A2363` (live, 2026-11-11) → asset 3.2.0.
Historical manifests recovered from the Wayback Machine (the two snapshots that exist):

- `20220421025905` → firmware **3.1.8**, build 10M569
- `20230319145709` → firmware **3.1.12**, build 10M1543

All three were downloaded from `updates.cdn-apple.com` and **SHA-1 verified against the
`_Measurement` field of the manifest that advertised them** — all three match exactly:

| Version | Build | Bytes | SHA-1 (matches Apple) | SHA-256 |
|---|---|---|---|---|
| 3.1.8 | 10M569 | 76,190 | `3722c634e671d4129d9f00e25877bedffe9ffc4b` | `0fa48ad507a7c08683fa22470e8aa73978e5fcbf92621f4c6ba5767a0b1ff138` |
| 3.1.12 | 10M1543 | 76,296 | `a10fd2efd5cc942adc53c166f5ae26524d809fb1` | `8251b8470846e3fda7699c5e115636a749238685d5cf074e50487f20165a059e` |
| 3.2.0 | 10M13722 | 80,642 | `4db70dec4835757fe02152e5e3ef29f41581f666` | `db7a18efcd347a162d36095c67a2012429d0021c8c137b124c4a5adf786ee881` |

Container format: outer = **plain zip, stored (compression method 0)**, no encryption.
Inner payload = `AssetData/Firmware.acsw/A2363FirmwareMobileAsset.uarp`, a
**UARP "firmware asset" container** — not IMG4/IM4P/DER/IMG3/xar/bz2/lzss.
Magic bytes: `00 00 00 02 00 00 00 2c 00 01 4a 3c ...` (u32 tag=2, u32 len=0x2c, then
u32 payload length). Each zip also carries an Apple `_CodeSignature/` with
`CodeDirectory`, `CodeResources`, `CodeSignature` and `CodeRequirements`, and an
`Info.plist` whose `CFBundleShortVersionString` is the firmware version verbatim:

```
Info.plist (3.2.0):
  CFBundleIdentifier       = com.apple.accessory.updater.payload.A2363
  CFBundleName             = A2363-FirmwareUpdate-3.2.0
  CFBundleShortVersionString = 3.2.0
  FirmwareImageFile        = A2363FirmwareMobileAsset.uarp
```

**CONFIRMED**: the 3.2.0 zip is authentic Apple output — Apple's own manifest SHA-1 matches,
the payload is Apple-codesigned, and the version string 3.2.0 matches the reported
firmware independently.

## 4. 70W USB-C Power Adapter (A2743) — NOT PUBLICLY OBTAINABLE

This is a negative result, and it is solid. Four independent checks:

1. **mesu, every path shape** — `com_apple_MobileAsset_UARP_A2743` returns `403`/`not found`
   under `""`, `macos/`, `iOS/`, `bridgeos/`, `watch/`, `audio/`, `tv/`, `visionos/`,
   `xros/`, `iOS12DeveloperBeta/`, `AirPods2022Seed/`. Also tried `.EA` suffix variants,
   `PowerAdapter`, `UARP_Adapter`, `UARP_USBPD`, `UARP_PowerAdapter` — all `not found`.
2. **Numeric sweep** of `UARP.A2730`–`A2770`: only `A2755` exists (3408 B manifest). A2743 absent.
3. **Full 281-type sweep** for any manifest mentioning `70W` — none.
4. **Pallas (gdmf `/v2/assets`, POST)** — `UARP.A2743` returns
   `"AssetType not found for: com.apple.MobileAsset.UARP.A2743"`, i.e. Apple's registry has
   no such type. Control: `UARP.A2363` returns `"Active not found"` (type exists), and a
   deliberately fake `UARP.ZZZZ` returns `"AssetType not found"` — matching A2743.
   (Audience brute force: 0/131 known audience UUIDs return 200 for UARP types, so Pallas
   is not a usable path for accessory firmware at all without the private audience UUID.)

Interpretation: Apple does not publish a UARP firmware asset for the 70W adapter. The
firmware `1030030` reported by `SPPowerDataType` for product-ID field `0x701c` has no
public payload. Likely explanations, all unverified: the 70W brick is a fixed-function
USB-PD supply whose "firmware version" is burned at manufacture and never updated OTA; or
it updates through a channel not exposed as a public MobileAsset.

**Do not substitute the 140W asset for it.** The 140W adapter is a different product
(model A2452, firmware 1.4.90, build 10M13554) with its own asset type and its own
signed payload. It was downloaded only as a control to prove the catalog serves 140W
but not 70W. Its firmware must never be written to or reported as the 70W's.

## 5. Secondary sources (UNVERIFIED, textual only)

- MacRumors, 2026-10-05, "Apple Releases MagSafe 3 Charging Cable Firmware Update" —
  reports a 3.2.0 cable update, first since Feb 2023. Consistent with the binary
  acquisition above (3.2.0, posted 2026-09-23). Now upgraded to CONFIRMED by the binary.
- Support doc 102378 — confirms A2743 = 70W adapter, A2363 = MagSafe 3 cable.
- No source surfaced any text matching the literal string `1030030` for the 70W adapter;
  searches returned only Apple retail pages. Treat `1030030` as parent-supplied and unverified.

## 6. Files

- `firmware/` — 4 verified .zip payloads + `MANIFEST.txt` + `extracted/` inner .uarp images
- `evidence/manifests/` — the 4 source manifests, unmodified, as provenance
- `raw/` — probe scratch (catalogs, per-model manifests, audience list)
