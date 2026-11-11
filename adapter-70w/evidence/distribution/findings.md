# Distribution check — 70 W adapter (A2743) firmware availability

Question: does the existing negative result ("no public 70 W adapter firmware")
hold across the named registries, and was any legitimate public path missed?
Read-only, metadata only, no binary downloads, no credentials, repo unmodified.
Session 2026-11-11. Sources: repo-root `evidence/firmware-acquisition-notes.md`
(root `evidence/`, not `adapter-70w/evidence/`) and `FIRMWARE.md` §1.

## Step 1 — baseline: what was already tried

OBSERVED (prior session, 15:23–15:31 UTC, statuses as recorded):

| # | Path | Result | Status |
|---|---|---|---|
| 1 | mesu `com_apple_MobileAsset_UARP_A2743` × 11 path shapes (`""`,`macos/`,`iOS/`,`bridgeos/`,`watch/`,`audio/`,`tv/`,`visionos/`,`xros/`,`iOS12DeveloperBeta/`,`AirPods2022Seed/`), `.EA` variants, and name guesses `PowerAdapter`,`UARP_Adapter`,`UARP_USBPD`,`UARP_PowerAdapter` | 19-byte `not found` | 403 |
| 2 | mesu numeric sweep `UARP.A2730`–`A2770` | only `A2755` exists (3408 B) | 200 / 403 |
| 3 | 281 known `com.apple.MobileAsset.*` types, manifests grepped `70W\|Power Adapter\|MagSafe` | 6 UARP types (A2363, A2452, A2571, A2676, A2384, A2140); no 70 W | 200 / 403 |
| 4 | Pallas `POST gdmf/v2/assets`, `UARP.A2743` | `AssetType not found for: …UARP.A2743` | 200 (JWT error body) |
| 4a | Pallas controls `UARP.A2363` / `UARP.ZZZZ` / 131-audience sweep | `Active not found` for A2363; `AssetType not found` for ZZZZ (same as A2743); 0 hits in `raw/uarp_audience_hits.json` | 200 / 200 / 404 |

Also recorded: `GET gdmf/v2/pmv` 200 (88,597 B, OS releases only); `GET /v2/assets`
400 ("GET request not allowed"); `POST /v2/pmv` 403; `mesu.apple.com/` 404;
mesu TimeZoneUpdate control 200; `updates.cdn-apple.com` payload 200.

Caveats in the notes that bound the claim: a mesu 403 is **"not found", not
"blocked"** (a real absence signal); Pallas cannot serve accessory payloads
without the private audience (0/131), so it is only a *type-existence* registry;
the 281-type universe came from a **community list**, so unknown names are missed.

INFERRED — the claim is "confirmed three ways", but substance is one registry
(mesu) probed three ways plus one Pallas type check. Steps 2–4 test that framing.

## Step 2 — live Pallas re-check

```
POST https://gdmf.apple.com/v2/assets   (Content-Type/Accept: application/json, UA: pallasutil)
{"ClientVersion":2,"CertIssuanceDay":"2023-12-10","AssetType":"com.apple.MobileAsset.UARP.<M>",
 "AssetAudience":"<uuid>","ProductType":"MacBookPro18,3","HWModelStr":"J314sAP","ProductVersion":"26.2","BuildVersion":"25C56"}
```
Responses JWT-wrapped; payload field 2 base64url-decoded. Control `GET /v2/pmv` 200, 88,597 B.

OBSERVED — Apple's message is self-discriminating ("type missing" vs "type present, nothing published"):

| AssetType | Audience | HTTP | Message |
|---|---|---|---|
| `UARP.A2743` | macos `60b55e25…` | 404 | `AssetType not found for: …UARP.A2743` |
| `UARP.A2743` | ios `01c1d682…` | 404 | `AssetType not found for: …UARP.A2743` |
| `UARP.A2743` | visionos `c59ff9d1…` | 404 | `AssetType not found for: …UARP.A2743` |
| `UARP.A2517` | macos `60b55e25…` | 404 | `AssetType not found for: …UARP.A2517` |
| `UARP.A2452` (140 W ctl) | macos `60b55e25…` | 404 | `Active not found for a7781f80-…#60b55e25-…` → exists |
| `UARP.A2363` (cable ctl) | macos `60b55e25…` | 404 | `Active not found for 0e9d314b-…#60b55e25-…` → exists |
| `UARP.ZZZZ` (fake ctl) | macos `60b55e25…` | 404 | `AssetType not found` → matches A2743 |

REPRODUCED — A2743/A2517 behave exactly like the fake type and unlike both real
accessory types. Prior Pallas finding independently confirmed, now under a
recorded, reusable request schema.

OBSERVED corrections to the prior record: (i) prior notes say 200 with the error
body; today identical logical queries return **404** with the same body — status
changed, message unchanged; (ii) the request schema is absent from the notes, and
naïve bodies (`{"AssetType":…}`, `{"AssetType":…,"Audience":…}`) now get
`400 Error Parsing JSON request`, with repeat offenders drawing plain-text
`403 Forbidden`. The prior exact call is not reproducible as written.

INFERRED — no adapter-typed MobileAsset exists for A2743 or A2517. A2517 was
queried only because the task named it; nothing here ties it to the 70 W brick
(doc 102378 is the sole A2743=70 W source) — mapping OPEN.

## Step 3 — mesu / CDN, documented strings only

OBSERVED — REPRODUCED this session, same 11 path shapes, `A2743`: all **403**.
The bare `""` shape returned the 111-B stale-edge variant on first hit and the
19-B `<h1>not found</h1>` on re-fetch; `macos/ iOS/ bridgeos/ watch/ audio/ tv/
visionos/ xros/ iOS12DeveloperBeta/ AirPods2022Seed/` each returned 403 / 19 B.

Controls (same shape, `assets/macos/…::<model>.xml`): `A2363` 200/3702 B,
`A2452` 200/3855 B, `A2755` 200/3408 B, `A2517` 403/19 B.

CDN: no A2743 URL exists in any manifest or `raw/` (`grep -ri A2743
evidence/manifests raw` → no file; 9 hits all in prose), so there is nothing to
query and no URL shapes were guessed. A2363 control HEAD → 200,
`binary/octet-stream`, `Content-Length: 80642` (matches `_DownloadSize`).

## Step 4 — host-side catalogs

OBSERVED — `/System/Library/AssetsV2` holds four UARP accessory caches and no
adapter type: `A2363` (3.2.0), `A2515` (2.1.3), `A2968` (0.9.1), `A3048`
(0.9.1). No `*2743*` directory; `/private/var/MobileAsset*` absent on this host.
`raw/index.sucatalog` and `raw/index-26-1.sucatalog`: 0 matches for
`UARP|A2743|Adapter`. `raw/ipsw_tree.json` is a GitHub tree of the `ipsw` tool
source (0 matches for UARP/A2743/70W), not an IPSW asset list; no `.ipsw` on disk
under `~/Downloads` or `~/.hermes/artifacts`. `assetutil` here is the `.car`
tool, not MobileAsset (usage text only, nothing relevant enumerated).

## Conclusion

**(a) CONFIRMED across the named registries** — mesu (REPRODUCED, 11 shapes,
403-not-found), Pallas (REPRODUCED, type absent, control-discriminated), CDN
(no path published), host caches (absent). Confidence: **high** for this scope.

Exact scope of the negative claim (use this wording):
> As of 2026-11-11, Apple publishes no `com.apple.MobileAsset.UARP.<model>` asset
> for the 70 W USB-C Power Adapter (A2743) — absent from the mesu manifest tree and
> from the Pallas type registry, therefore absent from `updates.cdn-apple.com`; and
> no macOS IPSW/OTA/Sucatalog or MobileAsset cache here carries an adapter payload.

What the negative does **not** cover (OPEN, not evidence of absence): direct
UARP-over-USB push from a host app or factory tool; firmware embedded in
macOS/iOS binaries or `usbcupdater` resources rather than a MobileAsset; a
per-train type name that does not encode the model (`UARP.<train>`); accessory
self-update paths never surfaced publicly. The 281-type sweep inherits the
community list's blind spot.

REFUTED sub-claim: "confirmed three ways" — methodologically it was one registry
probed repeatedly; the count is now genuinely two registries plus host caches.
Unresolved: prior Pallas 200 vs today's 404 (Apple-side status change, or a
different body that returned 200) — not resolvable without the old command line,
which was never recorded. A2517↔70 W mapping unverified. Reproduce with the curl
blocks in Steps 2–3 as written; decode JWT field 2.
