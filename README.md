# Apple USB-C / MagSafe 3 power-path research

A read-only investigation of the power path on an Apple Silicon MacBook Pro: the
USB-C PD controllers, the MagSafe 3 cable, and the host-side update stack. No
device was modified, no firmware was flashed, no accessory command was sent.

**Scope of what is published here:** documentation, extraction and analysis
scripts, manifests and hashes. Proprietary Apple firmware is **not** redistributed;
it is retained locally with acquisition notes and hashes.

## Evidence labels

Every factual statement in the research documents carries one of six labels:

| label | meaning |
|---|---|
| **OBSERVED** | read directly at a cited offset, register or property |
| **REPRODUCED** | a checked-in script deterministically re-derives it |
| **INFERRED** | reasoned from evidence, not proven |
| **UNVERIFIED** | asserted without independent checking |
| **REFUTED** | checked and shown false |
| **OPEN** | unsettled on the available evidence |

No statement in this repository asserts a semantic or behavioural conclusion
about firmware that the evidence does not establish. `CONFIRMED` and `VERIFIED`
are retired as labels; where they appear in `REVIEW-FABLE.md` they are quoted
from the pre-migration documents.

## Verified accomplishments

- **Host power path mapped** (OBSERVED): four HPM controllers at RID 0, 1, 2, 5;
  the charger sits on RID 5 / `Port-MagSafe 3@1`; contract 20 V × 3.390 A =
  67.80 W; `AuthenticationRequired = No` on that port.
- **Three firmware objects distinguished** (OBSERVED): HPM controller
  `FW003.115.00`, MagSafe cable 3.2.0 (PID `0x7800`, bcdDevice `0x3200`), adapter
  `1030030` (ID `0x701c`). These are not revisions of one image.
- **UARP SuperBinary container format recovered from Apple's own parser**
  (OBSERVED): 44-byte header, 40-byte payload records, TLV metadata; all four
  acquired files pass six range checks and `dataOffset + dataLength` reconciles
  with the declared extent 4/4 (`FIRMWARE.md` §3).
- **Three MagSafe releases acquired and extracted** to Cortex-M Thumb images
  (REPRODUCED): 3.1.8, 3.1.12, 3.2.0, each SHA-1 matching Apple's manifest
  `_Measurement`; per-image SHA-256 in `SHA256SUMS`.
- **Power-negotiation table identical across all three releases** (REPRODUCED):
  5.00 / 9.00 / 15.00 / 20.00 V @ 3.00 A, two copies per image, addresses move.
- **One Apple SVID literal changes** across the releases (OBSERVED):
  `0x05AC0002` → `0x05AC0000`. Meaning OPEN.
- **Dispatcher census** (REPRODUCED): 14 / 14 / 10 `mov pc` dispatch sites; a
  14-case table present in both 3.1.x builds and not detected in 3.2.0.
- **Host UARP message header** (OBSERVED): 6 bytes, three big-endian `u16`.

## Limitations

- **Ghidra coverage is 38.8 / 39.4 / 43.3 %** of image bytes. The control-message
  switch and the Apple SVID literal sites fall *outside* the analysed set, so the
  two paths that matter were never decompiled. Per-function matching is therefore
  not reported at all; both calibrated runs were void (`DIFF.md` §10).
- **No semantic or behavioural comparison** between 3.1.12 and 3.2.0 is offered.
  It is OPEN.
- **The 70 W adapter firmware is not publicly obtainable** (OBSERVED via Apple's
  Pallas registry and CDN enumeration). `1030030` remains a host-reported value.
- **Load base for the accessory images is OPEN.** The pointer block at offset 0 is
  SP plus three pointers of unconfirmed meaning; the 140 W control image does not
  corroborate a base-zero mapping, though it does not rule out other bases either
  (`FIRMWARE.md` §5).
- Register `0x47` field layout, `C99` header hash fields, and TLV `0xccd28103` /
  `0x00000003` semantics are all OPEN.

## Layout

```
README.md              this file
REPORT.md              architecture, findings, corrections, limitations
HARDWARE.md            device inventory, controller mapping, register decoding
FIRMWARE.md            acquisition, SuperBinary format, extraction, image ID
PROTOCOL.md            USB-PD / UVDM / UARP transport observations
DIFF.md                cross-version comparison and verdicts
SECURITY.md            trust model, access control, readback feasibility
NEXT.md                prioritized experiments, blockers, equipment
EXTRACTION-NOTES.md    BootKC extraction method and validation
DISPOSITION.md         every Fable review finding and its resolution
TESTING.md             what the checks assert and how to run them
REVIEW-FABLE.md        independent documentation audit (retained verbatim)
publication/           one copy of each build: current/ shipped, prior/ superseded
fixtures/              judgement fixtures (sources only; PDFs live in publication/)
scripts/               extraction, analysis and verification scripts
evidence/              captured outputs, dumps, census and match data
firmware/              NOT COMMITTED: proprietary images, see FIRMWARE.md
SHA256SUMS             hashes of extracted images
```

## Reproduction

Checks require the local firmware images, which are not committed. With them
present under `firmware/`:

```bash
python3 scripts/verify_docs.py .          # all deterministic checks
python3 scripts/diff_verify.py firmware/images
python3 scripts/literal_sets.py evidence/magsafe-ghidra/raw \
        0x0B0F0 pseudo_3_1_12 0x0B18C pseudo_3_2_0
python3 scripts/dispatcher_census.py firmware/images evidence/dispatcher-census.json
python3 scripts/coverage.py evidence/magsafe-ghidra/raw firmware/images
shasum -a 256 -c SHA256SUMS
```

Without the images, the six document-consistency checks still run and the numeric
checks report SKIP with a named reason.

## Provenance

Firmware was downloaded from `updates.cdn-apple.com` via the public
`com.apple.MobileAsset.UARP.<model>` manifests. Exact URLs, HTTP status, byte
counts, timestamps and Apple's own `_Measurement` SHA-1 for each file are in
`firmware/MANIFEST.txt` and `FIRMWARE.md` §1. Two of the three manifests are
archive copies pointing at still-live CDN URLs; that is stated where it applies.

Local cryptographic material here is hashes only. No credentials, tokens or
personal paths are published.
