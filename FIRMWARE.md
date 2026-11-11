# FIRMWARE — acquisition, container format, extraction

## 1. What was acquired

MagSafe 3 (model A2363) firmware, three historical revisions, plus one 140 W
adapter image as a control. All from `updates.cdn-apple.com` via the public
`com.apple.MobileAsset.UARP.<model>` manifest. Nothing was flashed.

| file | fw | bytes | sha256 |
|---|---|---|---|
| `A2363_magsafe3_3.2.0_10M13722.zip` | 3.2.0 | 80,642 | `db7a18efcd347a162d36095c67a2012429d0021c8c137b124c4a5adf786ee881` |
| `A2363_magsafe3_3.1.12_10M1543.zip` | 3.1.12 | 76,296 | `8251b8470846e3fda7699c5e115636a749238685d5cf074e50487f20165a059e` |
| `A2363_magsafe3_3.1.8_10M569.zip` | 3.1.8 | 76,190 | `0fa48ad507a7c08683fa22470e8aa73978e5fcbf92621f4c6ba5767a0b1ff138` |
| `A2452_140W_1.4.90_10M13554.zip` | 1.4.90 | 60,640 | `47415a0f7cad9e185d9d483b86ce5e140c59922761f13745dc267039151d2a72` |

Provenance: each SHA-1 matches Apple's own `_Measurement` field in the manifest
that served it (`shasum -a 1` reproduced in `firmware/MANIFEST.txt`). The 3.2.0
manifest was fetched live; 3.1.8 and 3.1.12 came from archived copies of the
same manifest pointing at still-live CDN URLs. Exact URLs, HTTP status, byte
counts and timestamps are in `firmware/MANIFEST.txt` and
`evidence/firmware-acquisition-notes.md`.

**The 70 W adapter (fw 1030030) has no publicly obtainable firmware.** Negative
result confirmed three ways: `mesu.apple.com` returns 403 "not found" for
`UARP_A2743` across 11 path shapes; Apple's Pallas registry (`gdmf /v2/assets`)
returns `AssetType not found for: ...UARP.A2743`, the same answer it gives for a
deliberately fake `UARP.ZZZZ`; and a sweep of A2730–A2770 plus a 281-type sweep
found no 70 W manifest. `1030030` therefore remains a host-reported value with
no binary to compare against.

The A2452 (140 W) image is included **only as a format control**. Its payload
tag is `BRCK`, its version is 1.4.90, and its firmware is a different MCU image.
It must never be treated as the 70 W adapter's firmware.

## 2. Container format — recovered from Apple's parser

Recovered from `/usr/libexec/uarpd` (arm64e slice sha256
`33a9fb5cdd97a19d09cee6f8fa2276345104b1d5a6d3c686d0677a444f298c7f`), not
inferred from hex:

- `UARPSuperBinaryLayer3::expandSuperBinaryHeader` @ `0x1000820c8`
- `UARPSuperBinaryLayer3::expandPayloadHeadersAndMetaData:offset:` @ `0x10008231c`
- per-record decode `FUN_100041a1c` @ `0x100041a1c`

What the decompiled code enforces:

- header size must equal `0x2c`, else parse fails
- `payloadLength` must be `<=` the asset length
- the payload-header table length must be a multiple of `0x28` (40)

### SuperBinary header, 44 bytes at offset 0, big-endian u32

| off | field |
|---|---|
| 0x00 | formatVersion (2) |
| 0x04 | headerLength, must be 0x2c |
| 0x08 | payloadLength — span of header + payloads, checked `<=` file size |
| 0x0c | versionMajor |
| 0x10 | versionMinor |
| 0x14 | versionRelease |
| 0x18 | versionBuild |
| 0x1c..0x2b | four further fields, names not recovered |

The four version words feed `UARPComponentVersion initWithMajorVersion:...`, so
this triple is the authoritative in-file version.

### Payload header table at 0x2c, N × 40 bytes

| off | field |
|---|---|
| 0x00 | recordLength (== 0x28) |
| 0x04 | payload4cc (4 raw chars) |
| 0x08 | versionMajor |
| 0x0c | versionMinor |
| 0x10 | versionRelease |
| 0x14 | versionBuild |
| 0x18 | payloadMetaDataOffset |
| 0x1c | payloadMetaDataLength |
| 0x20 | payloadDataOffset |
| 0x24 | payloadLength |

### Metadata TLVs

`{u32 type, u32 length, value[length]}`, appearing twice: once at SuperBinary
level after the payload table, and once per payload.

Observed tags: `0xccd28103` (always len 4) and `0x00000003` (len 4). Both carry
value 0 on the MagSafe images and 1 on the 140 W adapter. Their meaning is
**not recovered**; do not guess that they are compression flags.

## 3. Extraction and validation

`scripts/uarp_superbinary.py` implements the above. Every offset and length is
range-checked; a payload is only written if all checks pass.

Result, all four files:

```
A2363 3.1.8   format=2 hdrlen=0x2c payloadLength=0x147e8 version=3.1.8.0   6/6 checks
A2363 3.1.12  format=2 hdrlen=0x2c payloadLength=0x14868 version=3.1.12.0  6/6 checks
A2363 3.2.0   format=2 hdrlen=0x2c payloadLength=0x14a3c version=3.2.0.0   6/6 checks
A2452 1.4.90  format=2 hdrlen=0x2c payloadLength=0xea84  version=1.4.90.0   6/6 checks
```

The checks that passed, per file: formatVersion==2; headerLength==0x2c;
payloadLength <= file size; payload data end <= payloadLength; metadata range
inside the file; container version triple == payload record version triple.

Independent arithmetic confirmation, the strongest single check:

```
3.1.8   payloadDataOffset 0x60 + length 0x14788 = 0x147e8 = header payloadLength
3.1.12  payloadDataOffset 0x60 + length 0x14808 = 0x14868 = header payloadLength
3.2.0   payloadDataOffset 0x6c + length 0x149d0 = 0x14a3c = header payloadLength
A2452   payloadDataOffset 0x84 + length 0xea00  = 0xea84  = header payloadLength
```

Four-for-four on offset+length reconciling with the container's own declared
extent.

Payload tags: `2363` for the MagSafe cable, `BRCK` for the 140 W adapter. The
4CC is the payload selector (`payloadWith4cc:` in the same class).

## 4. Inner container on the MagSafe payload

The MagSafe payload is **not** directly executable. All three begin:

```
43 39 39 00   "C99\0"   inner container tag
00 08 01 03   3.1.8       byte[1] = minor, byte[2] = major, byte[3] = 3
00 0c 01 03   3.1.12      (3.1.8 -> minor 8, 3.1.12 -> minor 0x0c, 3.2.0 -> major 2)
00 00 02 03   3.2.0
00 04 00 00   constant
```

then 20 bytes of high-entropy material, a `u32 0x20` followed by a 32-byte blob,
then further fixed 16/32-byte fields, and 0x180 (384) bytes of header total.
The 32-byte blob at `0x24` is identical in 3.1.8 and 3.1.12 and differs in
3.2.0, which is consistent with a per-build key, nonce or digest — **not
established**.

The 140 W `BRCK` payload has no such wrapper; it starts directly with a vector
table.

## 5. Executable image identification (OBSERVED)

At payload offset `0x180` the MagSafe payloads contain a 4-word Cortex-M vector
table followed immediately by Thumb code:

| version | SP | reset | NMI | HardFault |
|---|---|---|---|---|
| 3.1.8 | 0x20002000 | 0x00010f7d | 0x00010fa1 | 0x00010fa1 |
| 3.1.12 | 0x20002000 | 0x00010ffd | 0x00011021 | 0x00011021 |
| 3.2.0 | 0x20002000 | 0x0001111d | 0x00011141 | 0x00011141 |

- `SP = 0x20002000` implies 8 KB of SRAM at `0x20000000` used by this build.
- All vector targets fall inside the image, so load base is `0x00000000`.
- NMI/HardFault are consistently reset + 0x24.
- Code at image offset `0x10` is unambiguous Thumb-2 startup:
  `push {r4,r5,r6,r7,lr} / sub sp,#0x14 / cpsid i / <MMIO stores>`, followed by
  clock/power register programming and a `bl` into early code.

**Correction, and the entry point is NOT settled.** An earlier revision of this
document attributed a byte-copy leaf at `0x111c` to the 3.2.0 reset target. That
was an address error: the vector `0x0001111d` clears to `0x1111c`, and image
offset `0x1111c` is constant data, while `0x111c` is ordinary code that is not
referenced by the vector at all. Neither offset is a plausible reset handler.
So the 4-word block at offset 0 is best described as **SP plus three pointers of
unconfirmed meaning**, and it may not be a conventional Cortex-M vector table.
The entry path begins at `0x10` empirically; which code the processor actually
runs first is unresolved, and resolving it requires a correctly configured
analysis, not another reading of these four words.

The 140 W control image shows a superficially similar opening from offset 0:
`SP=0x20002000`, then `0x0000ec89`, `0x0000ec71`, `0x0000ec71`, code at `0x10`.
**It does not corroborate the base-0 reading.** That image's payload length is
`0xea00`, and `0xec89` / `0xec71` are larger than it, so under a base of zero
they address nothing. That rules out a base-zero mapping for this image; it does
**not** rule out every mapping — a nonzero base, for instance `0x400`, would put
both offsets inside the image (`0xE889`, `0xE871`). Nothing here establishes what
that base is. The correct conclusion is narrow: the control image provides no
independent support for the assumed base-zero layout, and an earlier revision
overstated this as "cannot address the payload under any base".

Extracted images: `firmware/images/A2363_<version>_base0.bin`.

## 6. Hash fields in the C99 header

Three 32-byte fields sit at header offsets `0x24`, `0x98`(+4), `0xb8`, `0x110`.
None equals SHA-256 of the image region `[0x180:]`, of the whole payload, or
CRC-32 of either. The header field at `0x100` reads as 81076 / 81204 / 81668
little-endian, which is close to but not equal to the image length. Header
`0x10c` is a constant 1152.

Conclusion: the hash and length fields are computed over something other than
the naive image slice (likely per-section, or over a normalized form). **Not
recovered.** No claim is made about integrity checking in this firmware beyond
the observation that these fields exist and that Apple's update path verifies
something we have not yet identified.

## 7. Limits of this document

- The 70 W adapter firmware could not be obtained, so no adapter-side analysis
  is possible from binaries. Adapter behaviour in this report is host-observed
  only.
- `0xccd28103` and `0x00000003` TLV semantics unknown.
- C99 header semantics other than the version bytes are unknown.
- The reset vector is stored at image offset `0x04`: `0x00010f7d` (3.1.8),
  `0x00010ffd` (3.1.12), `0x0001111d` (3.2.0). The Thumb target is `0x10f7c`,
  `0x10ffc`, `0x1111c` respectively. The bytes at `0x1111c` are `00 0f 05 40
  80 0f 05 40`, i.e. 32-bit peripheral addresses (`0x4005xxxx`), so the target is
  constant data and not a handler. Which code executes first is **OPEN**.
- The region addressed by the Apple SVID literal sites is **UNVERIFIED** as a UVDM
  builder; the identification is a subagent claim that was not re-derived.
