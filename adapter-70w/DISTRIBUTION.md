# DISTRIBUTION — what was searched for 70 W adapter firmware

Read-only, metadata only. No binary downloaded, no credential used, no auth
bypass, no URL brute-forcing beyond the shapes already recorded.

## 1. Baseline that already existed

`evidence/firmware-acquisition-notes.md` and `FIRMWARE.md` §1 recorded: mesu
path shapes for `com_apple_MobileAsset_UARP_A2743` (all 403 "not found"), a
numeric sweep A2730–A2770 (only A2755 exists), a sweep of 281 known
`com.apple.MobileAsset.*` types (six UARP types, none an adapter), and one
Pallas type check. The notes never recorded the Pallas request schema.

## 2. Pallas type registry

Re-checked with a recorded, reusable schema
(`POST https://gdmf.apple.com/v2/assets`, JWT-wrapped payload, base64url field
2). RESPONSES ARE SELF-DISCRIMINATING: "AssetType not found" means the type does
not exist, "Active not found" means the type exists but nothing is published for
that audience.

| AssetType | result | reading |
|---|---|---|
| `UARP.A2743` | 404 `AssetType not found` (macos, ios, visionos audiences) | type absent |
| `UARP.A2517` | 404 `AssetType not found` | type absent |
| `UARP.A2452` (140 W control) | 404 `Active not found` | type exists |
| `UARP.A2363` (cable control) | 404 `Active not found` | type exists |
| `UARP.ZZZZ` (fake control) | 404 `AssetType not found` | matches A2743 |

A2743 behaves exactly like a fabricated type and unlike both real accessory
types. REPRODUCED in this session with the schema above. The parent re-verified
the mesu and MobileAsset paths but did not independently re-run Pallas; the
exact commands are in `evidence/distribution/findings.md`.

Correction to the prior record: the notes say Pallas returned 200 with an error
body; today the same logical queries return 404 with the same message. The old
command line was never recorded, so the status change cannot be attributed.

## 3. mesu and the CDN

Re-checked by the parent this session:

```
A2743 403 19 bytes    (all 11 recorded path shapes)
A2363 200 3702 bytes  (control)
A2452 200 3855 bytes  (control)
```

A 403 with a 19-byte `not found` body is Apple's absence signal, not a block.
No A2743 URL exists in any manifest, so nothing was guessed and the CDN has no
path to query. The A2363 control resolves to an 80,642-byte payload matching
its manifest `_DownloadSize`.

## 4. Host-side catalogs

`/System/Library/AssetsV2` holds four UARP accessory caches (A2363, A2515,
A2968, A3048) and no adapter type; no `*2743*` directory. Both `sucatalog`
files have zero matches for `UARP|A2743|Adapter`. No IPSW is present on disk.
`assetutil` on this host is the `.car` tool, not MobileAsset.

## 5. Verdict and exact scope

**No public 70 W adapter firmware is served.** Stated precisely:

> As of 2026-11-11, Apple publishes no `com.apple.MobileAsset.UARP.<model>`
> asset for the 70 W USB-C Power Adapter (A2743): absent from the mesu manifest
> tree and from the Pallas type registry, therefore absent from
> `updates.cdn-apple.com`; and no macOS IPSW, OTA catalog or MobileAsset cache
> on this host carries an adapter payload.

This is confirmed at high confidence **for that scope**. The earlier framing
"confirmed three ways" is REFUTED: it was one registry (mesu) probed several
ways plus one Pallas check.

What the negative does **not** cover, and therefore does not establish absence:

- a direct UARP-over-USB push from a host app, service or factory tool;
- firmware embedded in a macOS/iOS binary or in `usbcupdater` resources rather
  than a MobileAsset;
- a per-train asset type whose name does not encode the model
  (`UARP.<train>` rather than `UARP.<model>`);
- an accessory self-update path never surfaced publicly.

The 281-type sweep inherits the blind spot of the community list it came from.
