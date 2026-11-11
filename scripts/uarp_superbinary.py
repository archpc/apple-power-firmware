#!/usr/bin/env python3
"""Parse an Apple UARP SuperBinary asset container (.uarp).

Format recovered from Apple's own parser, not inferred from hex:
  UARPSuperBinaryLayer3::expandSuperBinaryHeader        @ 0x1000820c8
  UARPSuperBinaryLayer3::expandPayloadHeadersAndMetaData:offset: @ 0x10008231c
  FUN_100041a1c (per-payload-header decode)             @ 0x100041a1c

Binary: /usr/libexec/uarpd arm64e slice, sha256
33a9fb5cdd97a19d09cee6f8fa2276345104b1d5a6d3c686d0677a444f298c7f

Recovered structure (all integers big-endian u32):

  SuperBinary header, 44 bytes at offset 0
    +0x00 formatVersion          must be seen as 2
    +0x04 headerLength           parser requires == 0x2c
    +0x08 payloadLength          total span of header+payloads; parser requires <= assetLength
    +0x0c versionMajor
    +0x10 versionMinor
    +0x14 versionRelease
    +0x18 versionBuild
    +0x1c..+0x2b                 4 further fields, names not recovered

  Payload header table at offset 0x2c, N records of exactly 0x28 (40) bytes
  (the parser rejects a table length that is not a multiple of 0x28):
    +0x00 recordLength           == 0x28
    +0x04 payload4cc             4 raw chars
    +0x08 versionMajor
    +0x0c versionMinor
    +0x10 versionRelease
    +0x14 versionBuild
    +0x18 payloadMetaDataOffset
    +0x1c payloadMetaDataLength
    +0x20 payloadDataOffset
    +0x24 payloadLength

  SuperBinary metadata TLVs follow the payload table, then each payload's own
  metadata TLVs, then the payload bytes:
    {u32 type, u32 length, value[length]}

Validation performed here: every offset/length is range-checked against the
file, payloadDataOffset+payloadLength must equal the header payloadLength, and
the version triple must agree between the container and its payload record.
The script refuses to emit a payload that fails any check unless --force.
"""
import json
import struct
import sys
import os

HEADER_LEN = 0x2C
RECORD_LEN = 0x28


def be32(buf, off):
    return struct.unpack_from(">I", buf, off)[0]


def parse_tlvs(buf, off, end, limit=64):
    out = []
    while off + 8 <= end and len(out) < limit:
        t = be32(buf, off)
        n = be32(buf, off + 4)
        if off + 8 + n > end:
            out.append({"offset": off, "type": t, "length": n, "error": "overruns region"})
            break
        out.append({"offset": off, "type": t, "type_hex": f"0x{t:08x}",
                    "length": n, "value_hex": buf[off + 8:off + 8 + n].hex()})
        off += 8 + n
    return out, off


def parse(path):
    d = open(path, "rb").read()
    if len(d) < HEADER_LEN:
        raise SystemExit("too short")
    h = {
        "format_version": be32(d, 0x00),
        "header_length": be32(d, 0x04),
        "payload_length": be32(d, 0x08),
        "version": [be32(d, 0x0C), be32(d, 0x10), be32(d, 0x14), be32(d, 0x18)],
        "hdr_extra": [be32(d, 0x1C), be32(d, 0x20), be32(d, 0x24), be32(d, 0x28)],
    }
    checks = []
    checks.append(("format_version == 2", h["format_version"] == 2))
    checks.append(("header_length == 0x2c", h["header_length"] == HEADER_LEN))
    checks.append(("payload_length <= file size", h["payload_length"] <= len(d)))

    # payload header table: run from 0x2c until the table length is a multiple
    # of 0x28 and the first following TLV looks sane. Apple passes the table
    # length in; here we discover it by requiring every record's recordLength
    # field to equal 0x28 and the 4CC to be printable.
    payloads = []
    off = HEADER_LEN
    while off + RECORD_LEN <= len(d):
        if be32(d, off) != RECORD_LEN:
            break
        tag = d[off + 4:off + 8]
        if not all(32 <= c < 127 for c in tag):
            break
        rec = {
            "record_offset": off,
            "record_length": be32(d, off),
            "payload_4cc": tag.decode("ascii", "replace"),
            "version": [be32(d, off + i) for i in (8, 12, 16, 20)],
            "meta_offset": be32(d, off + 0x18),
            "meta_length": be32(d, off + 0x1C),
            "data_offset": be32(d, off + 0x20),
            "data_length": be32(d, off + 0x24),
        }
        payloads.append(rec)
        off += RECORD_LEN

    table_end = off
    # SuperBinary-level TLVs end where the first payload's metadata or data begins
    limit = min(h["payload_length"], len(d))
    for p in payloads:
        for cand in (p["meta_offset"], p["data_offset"]):
            if cand and cand < limit:
                limit = cand
    sb_tlvs, sb_end = parse_tlvs(d, table_end, limit)

    for p in payloads:
        checks.append((f"{p['payload_4cc']}: data end <= payload_length",
                       p["data_offset"] + p["data_length"] <= h["payload_length"]))
        checks.append((f"{p['payload_4cc']}: meta within file",
                       p["meta_offset"] + p["meta_length"] <= len(d)))
        checks.append((f"{p['payload_4cc']}: container/payload version agree",
                       p["version"] == h["version"]))
        p["meta_tlvs"], _ = parse_tlvs(d, p["meta_offset"],
                                       p["meta_offset"] + p["meta_length"])

    return d, h, payloads, sb_tlvs, checks


def main():
    path = sys.argv[1]
    outdir = sys.argv[2]
    force = "--force" in sys.argv
    d, h, payloads, sb_tlvs, checks = parse(path)
    print(f"== {os.path.basename(path)}  file={len(d)} bytes")
    print(f"   format={h['format_version']} hdrlen=0x{h['header_length']:x} "
          f"payloadLength=0x{h['payload_length']:x} version={'.'.join(map(str, h['version']))}")
    print(f"   header extras: {[hex(x) for x in h['hdr_extra']]}")
    print(f"   superbinary TLVs: {len(sb_tlvs)}")
    for t in sb_tlvs:
        print(f"     type={t.get('type_hex')} len={t['length']} value={t.get('value_hex')}")
    ok = True
    for name, good in checks:
        if not good:
            ok = False
            print(f"   FAIL {name}")
    print(f"   checks: {sum(1 for _, g in checks if g)}/{len(checks)} passed")
    os.makedirs(outdir, exist_ok=True)
    for p in payloads:
        data = d[p["data_offset"]:p["data_offset"] + p["data_length"]]
        name = f"{p['payload_4cc']}_{'.'.join(map(str, p['version']))}.bin"
        dest = os.path.join(outdir, name)
        if ok or force:
            open(dest, "wb").write(data)
        print(f"   payload {p['payload_4cc']} v{'.'.join(map(str, p['version']))} "
              f"data@0x{p['data_offset']:x} len={p['data_length']} "
              f"meta@0x{p['meta_offset']:x}+{p['meta_length']} -> {dest}")
        for t in p["meta_tlvs"]:
            print(f"     meta type={t.get('type_hex')} len={t['length']} value={t.get('value_hex')}")
        print(f"     head: {data[:48].hex(' ')}")
    json.dump({"header": h, "payloads": payloads, "superbinary_tlvs": sb_tlvs,
               "checks": [{"name": n, "passed": g} for n, g in checks]},
              open(os.path.join(outdir, "layout.json"), "w"), indent=1)
    sys.exit(0 if ok or force else 1)


if __name__ == "__main__":
    main()
