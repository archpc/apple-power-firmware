# Delegated: security mechanisms, static bounds

Scope: offline analysis of `firmware/payload_*.bin` and
`firmware/images/A2363_*_base0.bin`. No device interaction. Labels: OBSERVED =
read directly from bytes/instructions, REPRODUCED = re-derived by a script whose
output is saved here, OPEN = unresolved.

Scripts/outputs in this directory: `hash_test.py/.log`, `field_matrix.py/.log`.

---

## Step 1 — C99 header hashes: RECOVERED (supersedes FIRMWARE.md §6)

FIRMWARE.md §6 concluded the 32-byte fields match no naive slice. That is
superseded: five hash relationships reproduce exactly in **all three builds**
(`field_matrix.log`). The header is not a flat structure — the payload is a
chain of **records**, each `{u32 bodyLen, u32 flags=8, u32 crc32(body),
u32 field12, u8 sha256[32], pad}`:

| record | start | bodyLen | body range | sha256 field |
|---|---|---|---|---|
| 3 | `0x100` | `0x13cb4 / 0x13d34 / 0x13f04` | `0x180 .. 0x13e34 / 0x13eb4 / 0x14084` | `0x110` |
| 4 | `tail` | `0x8d4 / 0x8d4 / 0x8cc` | `tail+0x80 .. EOF` | `tail+0x10` |

Verified equalities (REPRODUCED, 3/3 builds):

| field | value |
|---|---|
| `0x0c` | `sha256(payload[0x100 : tail])` — whole record 3, header + body |
| `0x110` | `sha256(payload[0x180 : tail])` — record 3 body (code) only |
| `0x108` | `crc32(payload[0x180 : tail])` — same range, LE |
| `0x30` | `sha256(payload[tail : EOF])` — whole record 4 |
| `0xe0` | `sha256(payload[0 : 0xa0])` — header self-hash over its own first 0xa0 B |
| `tail+0x8` | `crc32(payload[tail+0x80 : EOF])` (LE) |
| `tail+0x10` | `sha256(payload[tail+0x80 : EOF])` |

`0x100`/`tail+0` are the body lengths. Record 3's body is the executable image
and equals `A2363_*_base0.bin` byte-for-byte (`hash_test.log` asserts
`payload[0x180:] == base0.bin`). Record 4 is a 2.2 kB trailing record whose
own body hash is also present, i.e. the image is two integrity-wrapped records,
not one.

Explicit negatives (REPRODUCED, 3/3 builds, `hash_test.log`,
`field_matrix.log`): no field equals SHA-256/SHA-1/MD5/SHA-512/SHA-384/CRC-32/
Adler-32 of the whole payload, of `payload[0:0x100]`, of `payload[0:0x180]`,
of `payload[0x0c:0x1c]`, of `payload[0:lenf]` (the header-inclusive prefix), of
`base0.bin` with the trailing record stripped, of header-with-fields-zeroed, or
of any ordered pair of the structural boundaries tested (0, 4, 8, 0xc, 0x20,
0x2c, 0x30, 0x50, 0x9c, 0xa0, 0xc0, 0xe0, 0x100, 0x104, 0x108, 0x10c, 0x110,
0x130, 0x17c, 0x180, tail, tail+0x80, EOF). Nor are any of the fields a
4-byte prefix/suffix of such a digest.

**Still unexplained (OPEN):**
- `0xa0..0xdf` = two 32-byte blocks, high entropy, differ in every build,
  match none of the above digests. Candidate readings: a 64-byte ECDSA P-256
  `(r,s)` signature, a per-build key/nonce, or two hashes over a normalised
  form. **Not established.** `0x9c` is a u32 tag immediately before them
  (`0x637bbc7b / 0xab3fe321 / 0x6bbc695a`) that also matches no CRC or digest
  prefix tested.
- `0x10c` = `0x480` in record 3 but `0x20` in record 4, where `0x20` is
  plausibly the digest length. The record layouts are otherwise identical, so
  record 3's `0x480` is either a flag word or a load attribute. OPEN.
- `0x104` = `0x08000000` (LE) in every record; `0x2c` = `0x20000000`, the SRAM
  base implied by `SP = 0x20002000`. Both are load/attribute-like, not hashes.
- `0x17c` (4-byte trailer) and `tail+0x7c` (`b72173db` identical in 3.1.8 and
  3.1.12, `4491a6de` in 3.2.0) are **not** CRC-32 of anything tested. OPEN.
- The trailing record 4 body is only 2,260 B and its content is unchanged
  between 3.1.8 and 3.1.12 (`sha256` identical), so the *whole* record 4 hash
  `0x30` is identical across those two builds while `0x0c/0x110/0x108` differ.

### What this does and does not prove

PROVEN: the header carries a complete, internally consistent SHA-256 + CRC-32
integrity tree over both records, with a self-hash over the header's own prefix.
That is a *corruption-detection* structure. It is **not** authenticity: a hash
alone, stored in the same unauthenticated container, is forgeable by anyone who
can rewrite the image. Whether the accessory recomputes any of these fields
before applying a write, and whether `0xa0/0xc0` gate that, needs live evidence
(see verdicts at the end).

---

## Step 2 — Anti-rollback: no numeric version threshold exists in code (OPEN)

Method: (a) literal search for every plausible version encoding as a 16- and
32-bit word in all three images; (b) full linear Thumb-2 inventory of immediate
operands (`rizin -a arm -b 16 -c 'pD 0x14608 @ 0'`, 39,364/39,362/39,411
instruction lines per build) for `cmp`/`cmp.w`/`movw`/`movt`.

Results (REPRODUCED, `crypto_scan.log` §5):

- **No 32-bit literal** equal to `0x3200`, `0x0320`, `0x0318`, `0x031c`,
  `0x0308`, `0x3300` exists in any image. The u16 hits (6–29 per value) are not
  data: e.g. bytes `20 03` are the instruction `movs r?, #0x20`; `0x0320` is
  therefore instruction-encoding noise, not a stored version.
- **Zero `cmp.w` instructions** in any build. Every `cmp` immediate in the
  decoded stream is ≤ `0xFF` (72/68 distinct values; max 255), i.e. the ISA form
  `cmp rX, #imm8`. No compare against a 12-bit or larger constant is emitted.
- `movw` appears exactly once (3.1.8, `0xd800`) and zero times in 3.2.0; `movt`
  appears zero times in all three builds. So no code synthesises a 16/32-bit
  constant in a register by immediate means.
- The three images therefore contain no static instruction that compares a value
  against a version-like numeric threshold (`0x0318/0x0320/0x3200`).

Structural context (OBSERVED):

- The running code cannot read its own version from its own address space: the
  version bytes live at payload `[0x04:0x08]` inside the 384-byte C99 header,
  while the loaded image begins at payload `0x180`. A rollback check would have
  to read raw flash through the NVM controller (Step 4) or a stored copy.
- One `u32 0x480` — the same value as record 3's field 12 — occurs exactly once
  per image, at `0x12970` (3.1.8) / `0x129f0` (3.1.12) / `0x12bcc` (3.2.0),
  adjacent to `0x20000000` and to a pointer `0x10fa1` that looks like the image's
  own vector word. That is the only in-image echo of the container header found;
  its role is OPEN.

Verdict: **OPEN — no evidence found, and a bounded negative.** A monotonic
version check could still exist as byte-granular compares (`cmp rX, #3` for
major / `#0xc` for minor) or as a register-register compare of a flash-loaded
word; both are indistinguishable from ordinary arithmetic at 46–56 % coverage.
Absence of a *numeric* threshold is a real result; absence of *any* rollback
protection is **not** claimed.

## Step 3 — Crypto constants: CRC-32, SHA-256 and P-256 are all present (OBSERVED)

`crypto_scan.py/.log`, all figures reproduced in all three builds.

| primitive | evidence | status |
|---|---|---|
| CRC-32 | reflected polynomial `0xEDB88320` as a data word at `0x1302c` / `0x130ac` / `0x13270`, with a `ldr rX,[pc,#imm]` encoding targeting the word at `0x12fa2` (3.1.8) and `0x13022` (3.1.12); no equivalent reference found for 3.2.0's copy at `0x13270` | PRESENT (reference OBSERVED as an encoding; the surrounding linear decode is partly misaligned, so the enclosing routine is not confirmed) |
| SHA-256 | full FIPS 180-4 round-constant table, 64/64 words verified, **twice per image**: `0x130ec` (3.1.8) in record 3 and `0x144e8` in record 4; the 8-word IV likewise twice (`0x130cc`, `0x145e8`) | PRESENT, two copies |
| secp256r1 (P-256) | complete parameter block, each value byte-exact against NIST P-256, stored as 32-byte little-endian bignums: `p`@`0x131ec`, `b`@`0x13210`, `Gx`@`0x13230`, `Gy`@`0x13250`, `n`@`0x13270` (3.1.8); +0x80 in 3.1.12, +0x1c4 in 3.2.0 | PRESENT |
| RSA | no. The two `0x00010001` hits (`0xe44`, `0x89a8`) are instruction bytes, not data; no modulus, no `0x04010001`-style tables | ABSENT |
| AES | no S-box (`0x637c777b` absent), no T-tables | ABSENT |
| secp256k1 | no (probe hits are single `0xfffffffe` words inside the P-256 constants — one word is not a curve) | ABSENT |

Anomalies noted, not interpreted: 40 u32 words sit between the CRC polynomial
word and the SHA-256 IV (`0x13030..0x130cb`, beginning `F00F9344 D6D6A3E8
CB61B38C`); they are **not** the standard 256-entry CRC table (checked). Record 4
carries its own SHA-256 tables, so the trailing 2.2 kB record is a second
crypto-bearing module, not padding.

Byte-histogram: no compressed or encrypted blob. Every 1 kB block is high
diversity except the three constant-table blocks (`0x12c00`, `0x13800`, one more
per build), which are low diversity *because* they are tables.

Function mapping: the whole crypto block sits at `0x130xx–0x134xx`, which has
**no entry in `inventory3_318.json`** — the highest-addressed analysed
functions below it are `0xd85c`, `0xd888` and `0xd904` (2,014 B), and nothing in
the inventory starts above `0xdbde`. So the enclosing function is **not
identified**; consistent with DIFF.md §11e's unanalysed islands.

Consequence for Step 1's unknown 64 bytes: `0xa0..0xdf` was range-tested as an
ECDSA pair and tested for being an embedded public key.
- `0 < r < n` and `0 < s < n` hold in **both** byte orders in all three builds
  (necessary condition for ECDSA P-256 — weak, since a random 32-byte value
  satisfies `< n` with probability ≈ 1).
- `(x, y)` on the P-256 curve: **FALSE** in both byte orders, all three builds.
  So the block is **not** an embedded P-256 public key (REFUTED).
- A 64-byte `(r,s)` signature therefore remains the best-fitting reading, and is
  unverifiable offline (no key material of any kind is in the image). OPEN.

## Step 4 — Update path: `0xd904` is a flash program/erase driver (OBSERVED)

`evidence/magsafe-cortexm/decomp3_318/f_d904.c` (3.1.8, 2,014 B; moves to
`0xd984`/`0xdb40` in the later builds — DIFF.md §2e's top changed pair).
Memory operations only:

1. Walks a fixed table of **18** `ushort` entries (`DAT_0000dc54`, stride 2) and
   an 18-entry parallel word table, indexed by `param_1` (a slot/record number).
   Per entry it reads a 16-bit *target address* and a 32-bit *value*.
2. Programs through `FUN_00009fa4(addr, buf, len)`, which splits every transfer
   so it never crosses a **256-byte** boundary (`0x100 - (addr & 0xff)`), i.e.
   page-bounded writes, and loops to completion.
3. `FUN_00009edc` is the leaf programmer: guard `addr >> 0x12 == 0` (target must
   be < `0x40000`), then writes command byte **2**, then three address bytes
   (bits 23..16, 15..8, 7..0) and each data byte to a fixed port, with a
   per-byte busy poll `while (0xe < (status & 0x1f))`. The port is
   `DAT_00009f44 = 0x40070240` (read from `0x9f44`, 3.1.8); the polled status
   word is `0x40070208` (`port - 0x38`). It brackets the transfer with
   `FUN_00009f48` (unlock/commit: sets then clears bit 16 of a `0x4007xxxx`
   word, writes 5 then 0, polls `bit0` with `FUN_00000b60(0x1e0)` delays) and
   saves/restores IRQ state around every byte.
4. Records are written as **5-byte** units (`FUN_00009fa4(addr, buf, 5)`):
   a 1-byte index plus a 4-byte value.
5. `FUN_0000a018` is the erase side: it requires `addr & 0xfff == 0` (4 kB
   aligned) and issues command **0x20** (sector erase), **0x52** (32 kB) or
   **0xD8** (64 kB) depending on alignment and remaining length — the STM32-like
   sector/block erase command set.

So the largest changed function is a table-driven flash **program** routine
(index+u32 records, 256-byte-bounded byte-wise programming with status polling,
4 kB/32 kB/64 kB erase), not a protocol handler. It performs no hashing and
compares nothing: all integrity checking, if any, is in its callers. Whether a
caller verifies before programming is not established — `0xd904`'s callers are
outside the analysed set.

## Step 5 — Verdicts and what live evidence would close each

| # | question | verdict | evidence |
|---|---|---|---|
| 1a | header carries integrity fields | **OBSERVED yes** — SHA-256 + CRC-32 + header self-hash, 5 relations, 3/3 builds | `field_matrix.log` |
| 1b | fields are per-section, not per-image | **OBSERVED** — record-3 body hash ≠ whole-payload hash; record 4 hashed separately | same |
| 1c | hash covers the whole image | **REFUTED** — coverage stops at record 3 body end (`lenf`); record 4 verified only by its own header | same |
| 1d | integrity ⇒ authenticity | **OPEN, and doubtful** | see below |
| 2 | anti-rollback exists | **OPEN** — no numeric version threshold anywhere in code; byte-wise compare not excludable | Step 2 |
| 3a | crypto primitives present | **OBSERVED** — CRC-32, SHA-256 (×2), P-256; no RSA/AES/secp256k1 | `crypto_scan.log` |
| 3b | 64 B at `0xa0` is a public key | **REFUTED** — not on the P-256 curve | `crypto_scan.log` §4 |
| 3c | 64 B at `0xa0` is an ECDSA signature | **OPEN (best fit)** — range-valid, unverifiable without a key | same |
| 4 | update path is flash program/erase | **OBSERVED** — command 2 program, 0x20/0x52/0xD8 erase, 4 kB alignment, 0x40070240 port | Step 4 |

Live-device evidence that would close the open items — no static analysis can:

1. **Does the cable verify before programming?** Flash a record-3 body with one
   byte flipped and hashes *not* recomputed, then observe whether the accessory
   NACKs, stalls or refuses. Repeat with the hashes recomputed (CRC-32 and
   SHA-256 both) — if the second write is accepted and the first is not, the
   integrity fields are enforced, which upgrades 1d from "doubtful" to "checked
   but unauthenticated".
2. **Is `0xa0..0xdf` a signature?** Corrupt `r`, `s`, or both while leaving the
   digests intact. Three arms (r-only, s-only, both) discriminate a signature
   check from a dead field. Also try a *valid* signature produced with a
   guessed key and see whether it is rejected.
3. **Anti-rollback:** request a write of 3.1.8 over 3.2.0 from Accessory Mode 7
   and record the response bytes/timing; then 3.1.12 over 3.2.0. Acceptance of
   the older image is a direct refutation. A refusal needs a control (same
   request, same version) to exclude a generic NACK.
4. **Where is the stored version?** Read the accessory's NVM via the debug
   interface (if any exists) before and after an update, looking for a 16/32-bit
   word that changes at the same moment as bcdDevice.
5. **Is SHA-256 reachable?** Since the crypto block has no analysed caller,
   confirm by dynamic trace (breakpoint on the `0x40070240` port writes while
   feeding a known image) that the SHA-256/CRC code actually runs during an
   update rather than being dead weight.
6. **Public-key provenance:** if any signature check exists, its key must come
   from somewhere — the image has none, so it would be in the accessory's ROM or
   programmed at manufacture. Only a device readout (or Apple documentation)
   can settle that.
