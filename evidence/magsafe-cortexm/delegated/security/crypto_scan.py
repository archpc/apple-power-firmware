#!/usr/bin/env python3
"""Crypto-constant and version-constant scan over the three MagSafe images.

Offline. Inputs:
  firmware/images/A2363_*_base0.bin   (executable body, payload[0x180:])
  firmware/payload_*_bin              (full payload incl. 384-B C99 header)

Reports: (1) presence/absence of well-known crypto constants, (2) SHA-256 K/IV
table validation, (3) secp256r1 parameter-block validation, (4) ECDSA-range and
on-curve tests for the unexplained 64-byte header block, (5) version-constant
literal scan.
"""
import hashlib, zlib

BUILDS = ["3.1.8_10M569", "3.1.12_10M1543", "3.2.0_10M13722"]

SHA256_K = [0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,
0x923f82a4,0xab1c5ed5,0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,
0x80deb1fe,0x9bdc06a7,0xc19bf174,0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,
0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,0x983e5152,0xa831c66d,0xb00327c8,
0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,0x27b70a85,0x2e1b2138,
0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,0xa2bfe8a1,
0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,
0x682e6ff3,0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,
0xbef9a3f7,0xc67178f2]
SHA256_IV = [0x6a09e667,0xbb67ae85,0x3c6ef372,0xa54ff53a,0x510e527f,0x9b05688c,
             0x1f83d9ab,0x5be0cd19]
P256 = {
 "p":  0xffffffff00000001000000000000000000000000ffffffffffffffffffffffff,
 "b":  0x5ac635d8aa3a93e7b3ebbd55769886bc651d06b0cc53b0f63bce3c3e27d2604b,
 "Gx": 0x6b17d1f2e12c4247f8bce6e563a440f277037d812deb33a0f4a13945d898c296,
 "Gy": 0x4fe342e2fe1a7f9b8ee7eb4a7c0f9e162bce33576b315ececbb6406837bf51f5,
 "n":  0xffffffff00000000ffffffffffffffffbce6faada7179e84f3b9cac2fc632551,
}

def find_all(d, pat):
    out, i = [], -1
    while True:
        i = d.find(pat, i + 1)
        if i < 0:
            return out
        out.append(i)

def words_at(d, off, n):
    return [int.from_bytes(d[off+4*i:off+4*i+4], "little") for i in range(n)]

print("### 1. constant presence (u32 LE word search)")
probes = {"sha256 K0": 0x428a2f98, "sha256 IV0": 0x6a09e667,
          "crc32 poly": 0xedb88320, "p256 p[7]": 0xffffffff,
          "p256 Gx[0]": 0xd898c296, "aes sbox": 0x637c777b,
          "rsa e=65537": 0x00010001, "secp256k1 p": 0xfffffffe}
for v in BUILDS:
    d = open(f"firmware/images/A2363_{v}_base0.bin", "rb").read()
    print(f"-- {v} ({len(d)} B)")
    for name, w in probes.items():
        locs = find_all(d, w.to_bytes(4, "little"))
        if name != "p256 p[7]":          # 0xffffffff is everywhere, skip spam
            print(f"   {name:12s} {len(locs):3d} {[hex(x) for x in locs[:6]]}")

print("\n### 2. SHA-256 tables validated against FIPS 180-4")
for v in BUILDS:
    d = open(f"firmware/images/A2363_{v}_base0.bin", "rb").read()
    k0 = find_all(d, SHA256_K[0].to_bytes(4, "little"))
    iv0 = find_all(d, SHA256_IV[0].to_bytes(4, "little"))
    for off in k0:
        print(f"   {v} K[0]@{off:#x} 64/64 == FIPS K: {words_at(d,off,64)==SHA256_K}")
    for off in iv0:
        print(f"   {v} IV[0]@{off:#x} 8/8 == SHA-256 IV: {words_at(d,off,8)==SHA256_IV}")

print("\n### 3. secp256r1 parameter block (little-endian bignums)")
for v in BUILDS:
    d = open(f"firmware/images/A2363_{v}_base0.bin", "rb").read()
    for name, val in P256.items():
        locs = find_all(d, val.to_bytes(32, "little"))
        print(f"   {v} {name:2s} @ {[hex(x) for x in locs]}")

print("\n### 4. the unexplained 64 B at C99 header 0xa0..0xdf")
p, a, b, n = P256["p"], P256["p"] - 3, P256["b"], P256["n"]
for v in BUILDS:
    d = open(f"firmware/payload_{v.split('_')[0]}_{v.split('_')[1]}.bin", "rb").read() \
        if len(v.split('_')) > 2 else None
    d = open(f"firmware/payload_{v}.bin", "rb").read()
    blk = d[0xa0:0xe0]
    for bo in ("big", "little"):
        r, s = int.from_bytes(blk[:32], bo), int.from_bytes(blk[32:], bo)
        range_ok = 0 < r < n and 0 < s < n
        on_curve = (r < p and s < p and (s*s - (r*r*r + a*r + b)) % p == 0)
        print(f"   {v} {bo:6s} r<s<n:{range_ok}  on-curve(P-256):{on_curve}")

print("\n### 5. version-constant literals (u16 and u32)")
for v in BUILDS:
    d = open(f"firmware/images/A2363_{v}_base0.bin", "rb").read()
    for w in (0x3200, 0x0320, 0x0318, 0x031c, 0x0308, 0x3300):
        n4 = find_all(d, w.to_bytes(4, "little"))
        n2 = find_all(d, w.to_bytes(2, "little"))
        print(f"   {v} {w:#06x}: u32 sites {[hex(x) for x in n4]}  u16 sites {len(n2)}")
