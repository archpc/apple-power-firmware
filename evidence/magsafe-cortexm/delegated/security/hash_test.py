#!/usr/bin/env python3
"""Hash-hypothesis test against the C99 inner header (evidence, offline).

Compares SHA-256 / SHA-1 / MD5 / SHA-512 / CRC-32 over a battery of candidate
byte ranges against every 32-byte window and the 4-byte trailer in the 384-byte
"C99" header of each MagSafe payload.
"""
import hashlib, zlib, sys, json, os

IMGS = {
    "3.1.8":  "firmware/payload_3.1.8_10M569.bin",
    "3.1.12": "firmware/payload_3.1.12_10M1543.bin",
    "3.2.0":  "firmware/payload_3.2.0_10M13722.bin",
}
IMG0 = {
    "3.1.8":  "firmware/images/A2363_3.1.8_10M569_base0.bin",
    "3.1.12": "firmware/images/A2363_3.1.12_10M1543_base0.bin",
    "3.2.0":  "firmware/images/A2363_3.2.0_10M13722_base0.bin",
}

def crc32(b):
    return zlib.crc32(b) & 0xFFFFFFFF

def digests(b):
    return {
        "sha256": hashlib.sha256(b).digest(),
        "sha1": hashlib.sha1(b).digest(),
        "md5": hashlib.md5(b).digest(),
        "sha512": hashlib.sha512(b).digest(),
        "crc32le": crc32(b).to_bytes(4, "little"),
        "crc32be": crc32(b).to_bytes(4, "big"),
    }

out = {}
for ver, path in IMGS.items():
    d = open(path, "rb").read()
    img = open(IMG0[ver], "rb").read()
    L = len(d)
    assert d[0x180:] == img, (ver, "base0 mismatch")
    lenf = int.from_bytes(d[0x100:0x104], "little")
    const104 = int.from_bytes(d[0x104:0x108], "little")
    c108 = d[0x108:0x10c]
    c10c = int.from_bytes(d[0x10c:0x110], "little")
    trail = d[0x17c:0x180]
    print(f"=== {ver}: payload {L:#x}, image {len(img):#x}, "
          f"len@0x100={lenf} ({lenf:#x}), @0x104={const104:#x}, "
          f"@0x108={c108.hex()}, @0x10c={c10c}, trailer@0x17c={trail.hex()}")
    print(f"    deltas: L-lenf={L-lenf}  lenf-0x180={lenf-0x180}  "
          f"L-lenf-0x180={L-lenf-0x180}")

    hdr = d[:0x180]

    ranges = {
        "payload_whole[0:L]": d,
        "image[0x180:L]": d[0x180:],
        "hdr[0:0x100]": d[0:0x100],
        "hdr[0:0x180]": d[0:0x180],
        "hdr[0:0x24]": d[0:0x24],
        "hdr[0x04:0x100]": d[0x04:0x100],
        "img_len_field[0x180:+lenf]": d[0x180:0x180+lenf],
        "img[0:lenf]": img[:lenf],
        "img[0:L-0x180]": img,
        "payload[0:lenf]": d[:lenf],
        "payload[0:0x180+lenf]": d[:0x180+lenf],
        "hdr_zeros_after_0x24[0:0x180]": d[:0x24] + b"\0"*(0x180-0x24),
        "hdr_no_hashfields": d[:0x24] + b"\0"*32 + d[0x44:0x9c] + b"\0"*(0x180-0x9c),
        "img_excl_last32": img[:-32],
    }
    res = {}
    for name, blob in ranges.items():
        dg = digests(blob)
        res[name] = {k: v.hex() for k, v in dg.items()}
        for k, v in dg.items():
            # whole-header / anywhere-in-header containment test
            hit = hdr.find(v)
            if hit >= 0:
                print(f"    *** HIT {k}({name}) at header offset {hit:#04x}")
            # 32-byte header windows
            if len(v) >= 16:
                for w in range(0x20, 0x180 - len(v) + 1, 4):
                    if d[w:w+len(v)] == v:
                        print(f"    *** WINDOW {k}({name}) == hdr[{w:#04x}:+{len(v)}]")
            # 4-byte trailer
            if v == trail:
                print(f"    *** TRAILER {k}({name}) == 0x17c")

    # self-referential: field values are themselves part-covered?
    # test whether field@0x110 hashed over img matches any field
    fields = {
        "0x24": d[0x24:0x44], "0x9c": d[0x9c:0xbc], "0xa0": d[0xa0:0xc0],
        "0xb8": d[0xb8:0xd8], "0xc0": d[0xc0:0xe0], "0xd8": d[0xd8:0xf8],
        "0x110": d[0x110:0x130],
    }
    print("    field entropy check / equality between fields:")
    seen = {}
    for k, v in fields.items():
        for k2, v2 in fields.items():
            if k2 > k and v == v2:
                print(f"      fields {k} and {k2} IDENTICAL")
        seen[k] = v.hex()[:16]
    # cross-image: is any field shared with another build?
    out[ver] = {"len": L, "lenfield": lenf, "fields": {k: v.hex() for k,v in fields.items()},
                "trailer": trail.hex(), "digests": res,
                "c104": const104, "c108": c108.hex(), "c10c": c10c}
    print()

# cross-build comparison of header fields
vs = list(IMGS)
for k in ("0x24", "0x9c", "0xa0", "0xb8", "0xc0", "0xd8", "0x110"):
    vals = [out[v]["fields"][k] for v in vs]
    print(f"field {k}: " + (" ".join("SAME" if x == vals[0] else "diff" for x in vals))
          + f"  [{vs[0]}..]")

json.dump(out, open("evidence/magsafe-cortexm/delegated/security/hash_test.json", "w"), indent=1)
print("\nwrote evidence/magsafe-cortexm/delegated/security/hash_test.json")
