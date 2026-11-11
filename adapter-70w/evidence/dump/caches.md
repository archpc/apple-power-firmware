# caches — is any complete A2743 adapter image on this host?

Read-only sweep, macOS 27.2.1, user `sein`, no root, no download, no edit. Run 2026-11-11 ~13:05–13:25 EST. Labels: OBSERVED, REPRODUCED, INFERRED, UNVERIFIED, REFUTED, OPEN. Scope is *on disk* only; publication questions are `DISTRIBUTION.md`.

## Step 1 — asset stores

| path | state |
|---|---|
| `/System/Library/AssetsV2` | `drwxr-xr-x root:wheel`, 97 entries, readable |
| `/Library/Apple/System/Library/AssetsV2` | **ENOENT**; that tree's `PrivateFrameworks` has no UARP copy either (8 frameworks, none matching) |
| `/private/var/MobileAsset`, `…/MobileAssetV2`, `/private/var/{db,tmp}/com.apple.MobileAsset*` | **ENOENT** — no such store on this build |
| `/var/db/accessoryupdater` | `drwxr-x--x _accessoryupdater:_accessoryupdater`, **listing denied** |
| `~/Library/Caches/*uarp|accessor|obile*` | no such entries |

UARP entries present (all `root:wheel drwxr-xr-x`): `com_apple_MobileAsset_UARP_A2363` (160 B, 11-11 11:38), `_A2515` (128 B), `_A2968` (256 B), `_A3048` (256 B), plus three non-UARP `MobileAccessoryUpdate_*` trees (keyboard, trackpad). **No `…_UARP_A2743` directory exists** (ENOENT). OBSERVED.

Shape a real image takes: `_UARP_A2968/<sha1>.asset/AssetData/Firmware.acsw/` → `firmware.uarp` **16,113,537 B** + `BuildManifest.plist` 23,263 B, `Restore.plist` 961 B, `META-INF/`; three such `.asset` dirs for A2968. **No analogous A2743 `.asset` dir anywhere.**

**The A2743 hit is a failure record (OBSERVED, decisive).** `/System/Library/AssetsV2/staging/com_apple_MobileAsset_UARP_A2743.xml` — `-rw-r--r-- root:wheel`, **19 bytes**, mtime `2026-11-11T11:38:15`. Full content:

```
<h1>not found</h1>
```

That is Apple's 19-byte absence body (cf. `DISTRIBUTION.md` §3) written into the manifest slot. A real staging manifest is ~8.6 KB of plist XML (A2968 = 8,650 B); A2363/A2515 staging manifests are **0 B** ("nothing offered"). `grep -l 2743` over all 21 staging manifests → no match. REFUTED as a catalog. Other `*2743*` filename hits are substrings, not the model: a PKITrustStore cert digest (`…462743…`), a Siri hash `2e57a58e27433c…`, an analytics UUID `…-A274307CC1ED`. REFUTED.

## Step 2 — staged asset / partial download

No `*.tmp`, `*.download`, `*.partial` under AssetsV2 (depth 3); only `*.xml.purged`, none A2743. Recent writes are manifests, `locks/`, A2968 `.asset` mtimes. `accessoryupdaterd` A2743 lookups over 30 d are exactly three, all failing — `10:08:22.692`, `10:08:40.540`, `11:38:15.070` — each `com.apple.MobileAsset.UARP.A2743, response: 43 (MADownloadNotFoundOrDenied)`.

**REPRODUCED correlation:** the third line's second (`11:38:15`) equals the staging file's mtime, so that 19-byte body was written by that failed lookup.

State in every record: `A2743 … fw=1.3.30 stagedFW=0.0.0`; `HW Revision (null) -> unknown`; `Overriding asset location for A2743 from (null) to https://mesu.apple.com/assets/macos`. **No** `Apply staged assets to power adapter`, no `stagedFW=1.3.x`, no byte-count or staging message. The A2363 control in the same window reaches `response: 0 (MADownloadSuccessful)` — the harness *can* stage; it has nothing to stage for A2743.

`mdfind A2743` → one hit outside the store: `~/Backups/mail-icloud-2026-10/maildir/INBOX/cur/0007276.5f9a6b878f4980ea.honkM2,S` (48,723 B). Inspected: a FreeTaxUSA marketing email whose only match is Postfix queue ID `D4ADE9A2743.B74B420E00C4`; no attachments, no base64 parts. REFUTED. `mdfind UARP.A2743` → 0 results. **Negative, explicit:** no file on this host carries `A2743` or `701C` in an adapter/firmware sense, and no partial download survives anywhere.

## Step 3 — the updater's own resources

`UARPUpdaterServiceUSBPD.xpc` (3,721,808 B, x86_64+arm64e+arm64e.x1, sha256 `f44bd9194d14dfdb…`) — complete file list is `Info.plist`, `version.plist`, `Resources/InfoPlist.loctable` (4,397 B), 40 empty `.lproj`, the executable, `_CodeSignature`. **No firmware dir, no model-table plist.** Contrast sibling `ThunderboltAccessoryUpdaterService.xpc`: 13 × 516,096 B `Mac-0x00xx-B2_*.bin` + `Config.plist` mapping `Device Model ID` → `Firmware` filename, 4.2 MB — that is the embedded-image shape, and USBPD has none of it. Literals (5,340 strings extracted, so extraction is sound): `A2743` 0, `701C` 0, `28700` 0, `UARP.A2743` 0, any `A2[0-9]{3}` 0. Sections: `__text` 0x7E4D0, `__const` 0x76D90, `__cstring` 0x346A, `__DATA` filesize 16,384 B — no unexplained blob.

`Support/` = `accessoryupdaterd` (5,195,504 B, sha256 `c0d19fd0feb46dbc…`), `auearlyboot`, `fudHelperAgent`, `FirmwareUpdater.icns`. No `Resources/`, no `.uarp`. Literals `A2743`/`701C`/`28700`/`A2363`/`UARP.A2743` all 0; `uarpAccessories` 1 (the plist *name* only). `MobileAccessoryUpdater.framework/Resources` → `EA90Strings.plist`, Info, version; no firmware. **`CoreUARP.framework` ships no executable on disk**: `Versions/A/` = only `Resources/` (Info 1,291 B, version 469 B) + `_CodeSignature/` — cache-only, hence Step 4.

`/usr/libexec/{uarpd,uarpassetmanagerd,uarphidd,uarppersonalizationd,usbcupdater}`: `A2743`/`701C` = 0 in all five. Model literals that *do* exist: `uarpd` (3,784,912 B) has 14 (`A2512 A2513 A2580 A2617 A2618 A2619 A2698 A2699 A2700 A2871 A2872 A2924 A2931 A2952`); `uarphidd` (339,760 B) has 6 (`A2140 A2458 A2463 A2675 A2728 A2755`). These binaries *do* carry model literals where Apple chose to, so A2743's absence there is deliberate, not an extraction artifact. `UARPKit`/`UARPUpdaterService`/`UARPAssetManager`/`UARPiCloud` `Resources/` = Info + version only.

Whole-disk: `find /System/Library /usr/libexec /Library/Apple \( -name '*.acsw' -o -name 'firmware.uarp' \)` excluding AssetsV2 → **zero**. Every `.acsw` on this host is A2363/A2515/A2968/A3048.

## Step 4 — dyld shared cache and kernelcache

**kernelcache** (`evidence/kernelcache.bin`, 123,961,344 B, sha256 `2d5bd65de9a4e6b6…`): provenance verified — `kernelcache.lzfse` (32,575,947 B) hashes to `16398f6296e617a4…`, matching the raw Preboot kernelcache (32,585,486 B) at `/System/Volumes/Preboot/9063E54E-…/boot/BBF65A7E…/System/Library/Caches/com.apple.kernelcaches/kernelcache`. `A2743`/`701C`/`UARP.A2743` = 0/0/0; `uarp` = 1, only `com.apple.uarpupdaterservice.display`. No model table, no payload.

**dyld cache location:** `/System/Library/dyld/` **does not exist**; it lives at `/System/Volumes/Preboot/Cryptexes/OS/System/Library/dyld/` — 84 files, 2.4 GB, `root:admin`. Bare `dyld_shared_cache_arm64e` is a 753,664 B stub; payload is in `.01`…`.81` + `.dylddata`/`.dyldlinkedit`.

**The model string IS in the cache (OBSERVED).** `grep -ral A2743` over 2.4 GB (51 s) hits 5 files; 4 are byte coincidences. Real one: `dyld_shared_cache_arm64e.28`, **offset 76,622,492 of 131,334,144** — a C-string literal `A2743`:

```
76621048 A2452   76621054 Apple Vision Pro Battery   76621079 A2781
76621292 A3054   76621298 USB-C Dongle               76622492 A2743
76622540 .uarp   76622686 uarpFirmwareForAccessory
```

`A[0-9]{4}` full-match within ±30 KB → **77 model numbers**, incl. A2363, A2452, A2968, A3048, A2512–A2514, A2871/A2872, A2952, A2698–A2700, A2617–A2619, A2931, A2743. Owning image is **CoreUARP**: `/System/Library/PrivateFrameworks/CoreUARP.framework` sits at 76,608,788, i.e. 13,704 B earlier in the same cstring section, beside `SupportedAccessoriesUARP.plist`. **This corrects `HOST.md` §3** ("no literal A2743 in either binary"): true for `UARPUpdaterServiceUSBPD` and `accessoryupdaterd`, but the supported-model table *does* contain A2743 — inside CoreUARP, which has no on-disk Mach-O. It is a bare model-number list; `70W USB-C Power Adapter` has 0 hits there.

**The plists it loads are absent.** Strings name the inputs: `SupportedAccessoriesUARP.plist`, `…-Internal.plist`, `…-InternalFuture.plist`, `/var/db/accessoryupdater/dropbox`, `/usr/standalone/firmware/accessoryupdater/UARP`. `find` for `SupportedAccessoriesUARP*` across `/System/Library /Library /usr/standalone /private/var` → **zero**; the table is compiled in, not a plist. Both firmware drop paths → **ENOENT** (verified that `stat` on a known path *does* traverse the `711` parent). `uarpAccessories.plist` also returns **ENOENT**, not EACCES, so `HOST.md` §3's "table lives in `uarpAccessories.plist`" is **not confirmed**; directory listing is denied, so that stays OPEN.

**`/usr/standalone/firmware`:** DP865 (31 M), FUD, MCDP29XX, PFX, S4E (5.7 M), SLAM (7.6 M), t302 (13 M), t303 (7.1 M), iBridge1_1Customer.bundle (61 M), nfrestore. Exactly one `.uarp`: `PFX/PFX_J180dAP.uarp`, 1,475,250 B, sha256 `0a387af623b50a0e…`; grep `a2743|701c|power adapter` → 0. Touch/display payload. **Other gaps closed:** `/Library/Apple/System/Library/` has no `AssetsV2`; `~/Library/Caches` has no uarp/accessory dir; `PreinstalledAssetsV2` = 2 entries, no UARP; `find /private/var/folders -name '*.tmp' -newermt 2026-11-01` → zero; `find /System/Library /Library \( -iname '*firmware*' -o -iname '*.uarp' \) -size +1M` excl. AssetsV2 → zero.

## Step 5 — conclusion

**No complete image, no partial image, nothing at all.** Every artifact that mentions A2743 on this host is a *record of failing to obtain one*.

| question | verdict |
|---|---|
| complete A2743 image on disk | **none** — no `.asset`, no `firmware.uarp`, no `.acsw` |
| partial / in-progress download | **none** — no `.tmp`/`.partial`, no recent `.asset` write |
| staged or cached bytes | **none** — staging slot holds the 19-byte 403 body |
| firmware in a binary | **none** — largest section ≈487 KB, no blob |
| in kernelcache | **none** — 0 model literals, 1 UARP service name |
| in dyld cache | **model string only, no payload** |

Substantive find: **A2743 is a compiled member of CoreUARP's supported-accessory table** (1 of 77 literals in `dyld_shared_cache_arm64e.28`). macOS treats the brick as an addressable UARP target and has no asset to give it. This resolves `OPEN.md`'s "does the supported set list A2743?" **affirmatively** — the table is not a plist on disk, it is inside CoreUARP. INFERRED (high) that the same table is what lets `accessoryupdaterd` log a model rule without a "not supported" line.

**Scope searched:** AssetsV2 (97 entries, depth 3, incl. `staging/`, `PreinstalledAssetsV2/`); `/Library/Apple/System/Library{,/AssetsV2}`; `/private/var/{MobileAsset*,db,tmp}`; `/var/db/accessoryupdater` (+`dropbox/`); `~/Library/Caches`, `/private/var/folders`; six UARP/accessory frameworks and all their XPC bundles; five `/usr/libexec` daemons; `/usr/standalone/firmware` (10 trees); kernelcache; the full 2.4 GB dyld cache; `mdfind` plus strings/grep for model, PID and asset-type literals.

**Unreadable:** only the `/var/db/accessoryupdater` interior (mode `711`, owned `_accessoryupdater`, no root) — named files inside returned ENOENT, so no evidence of a hidden image, but absence there is **UNVERIFIED**. CoreUARP's Mach-O is absent from disk by design and was inspected via the cache instead. Everything else was readable.

**Residual blind spots:** (a) `/var/db/accessoryupdater` interior; (b) bytes held in `accessoryupdaterd` memory at a past instant — not a disk question; (c) files purged before the sweep — `*.xml.purged` proves MobileAsset deletes manifests, so a transient download *could* have existed and been erased, though `stagedFW` never left `0.0.0` in any of the three logged cycles and no residue remains.
