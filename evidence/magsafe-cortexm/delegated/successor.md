
## Successor analysis: 3.2.0 switch landscape vs 3.1.x 14-case dispatcher

Images used: `firmware/images/A2363_3.1.8_10M569_base0.bin`,
`A2363_3.1.12_10M1543_base0.bin`, `A2363_3.2.0_10M13722_base0.bin` (base-0
imports, so file offsets equal Ghidra addresses). Note the non-`_base0`
`firmware/payload_*.bin` files are offset by a container header — decode only
against `_base0`.

### Step 1 — switch decode, guards, tables, boundaries (OBSERVED)

| build | entry | guard | index reg / source | span | cases | table | table words | unique targets | word after last |
|---|---|---|---|---|---|---|---|---|---|
| 3.1.8 | 0xa9bc | `subs r0,#9; cmp r0,#0xd` | r1 (2nd arg) | 9–22 | 14 | 0xa9d8 | 6 uniq | 6 | 0xd0002c01 (not a ptr) |
| 3.1.12 | 0xaa10 | same | r1 (2nd arg) | 9–22 | 14 | 0xaa2c | 6 uniq | 6 | 0xd0002c01 (not a ptr) |
| 3.2.0 | 0x4b78 | `subs r0,r1,#2; cmp r0,#7` | r1 (2nd arg) | 2–9 | 8 | 0x4b94 | `5034 5574 5574 5574 5076 5574 50ae 50d0` | 5 | 0x00892173 (not a ptr) |
| 3.2.0 | 0x50fc→switch at 0x5158 | `subs r0,r1,#2; cmp r0,#0xc` | r1 (2nd arg) | 2–14 | 13 | 0x5168 | 9 uniq, dominant 0x5704 ×4 | 9 | 0x2e03461f (not a ptr) |
| 3.2.0 | 0x4eca | `subs r1,r0,#3; cmp r1,#0xe` | `[r0]`→`[..+1]` (byte of struct) | 3–17 | 15 | 0x4ee4 | 8 uniq, dominant 0x554a ×5 | 8 | 0x200002a8 |

Boundary checks: 0x4b94+32=0x4bb4 → 0x00892173 (data/imm, not code); the 0x4b78
function's own trivially-dispatched code continues at 0x4bb8. 0x5168+52=0x519c →
0x2e03461f (not code). 0x4ee4+60=0x4f20 → 0x200002a8, which is exactly the
literal loaded by `ldr r0,[0x4f20]` in the 0x4b78 function at 0x4b8c — i.e. the
0x4eca table ends flush against a *known literal pool word of another function*,
not against a case target. All three table lengths are therefore consistent;
none is truncated.

Also OBSERVED: 0x4b78 and 0x50fc share the identical prologue
`push {r4,r5,r6,r7,lr}; sub sp,#0x34`; 3.1.x uses `push {r4,r5,r6,r7,lr};
sub sp,#0x1c`. 0x4eca has no prologue (loads `[r0]`, `[r0,#1]` immediately) and
`mov r1,r6; mov pc,r2` (index held in r1, table in r2) — a different dispatch
idiom from the 3.1.x `adr r1,#4; ldr r0,[r1,r0]; mov pc,r0`.

### Step 1b — the switch landscape is incomplete (OBSERVED)

Scanning both images for the two dispatch idioms (`mov pc,rN` = `0x4687|N<<3`,
`add pc,rN` = `0x448f|N<<3`) finds, beyond the three inventoried 3.2.0 switches,
two more dispatch sites in *uncovered* 3.2.0 code (no Ghidra function
contains them, so no decomp exists):

- `0xa958`: `add r1,pc; ldrb r1,[r1,4]; lsls r1,r1,1; add pc,r1` — byte table.
- `0xab64`: `subs r3,#8; cmp r3,#0x10; bls; lsls; add r3,pc; ldrh r3,[r3,4];
  lsls; add pc,r3` — halfword table, 17 cases, span 8–24.

3.2.0 total: 10 `mov pc,r0` sites (0x267a, 0x3700, 0x38cc, 0x4218, 0x4594,
0x5166, 0x51f6, 0x590e, 0x6bb4, 0xecf8), plus 0x4b92 (`mov pc,r1`) and 0x4ee2
(`mov pc,r2`), plus `add pc,` sites at 0xa962 and 0xab76. 3.1.8/3.1.12: 15
`mov pc,r0` sites each plus inner `add pc,r3` at 0xad3a / 0xad8e.

### Step 2 — structural comparison with the 3.1.x dispatcher (OBSERVED + INFERRED)

Comparison unit for 3.1.x is the whole island `0xa9bc..0xb1a3` (958 decoded
instructions; 3.1.12 `0xaa10..0xb1f7` is instruction-for-instruction identical,
mnemonic SequenceMatcher ratio 0.999) — it contains the 14-case outer switch,
the out-of-table compare chain *and* a second, byte-table switch at `0xad2a`.

**(a) register carrying the message id**

| switch | index register | source |
|---|---|---|
| 3.1.8 0xa9bc / 3.1.12 0xaa10 | r1 | 2nd parameter (message id) |
| 3.2.0 0x4b78 | r1 | 2nd parameter |
| 3.2.0 0x50fc (dispatch 0x5158) | r1 | 2nd parameter |
| 3.2.0 0x4eca | r0 | `[[r0]+1]` — byte of a pointed-to struct |
| 3.1.8 0xad2a / 3.2.0 0xab64 (inner) | r3←r2 | payload byte, not a parameter |

**(b) case-to-target grouping shape**

| switch | cases | unique targets | dominant target (share) |
|---|---|---|---|
| 3.1.8 outer | 14 | 6 | 0xb154, 8/14 |
| 3.1.12 outer | 14 | 6 | 0xb1a8, 8/14 |
| 0x4b78 | 8 | 5 | 0x5574, 4/8 |
| 0x50fc | 13 | 9 | 0x5704, 4/13 |
| 0x4eca | 15 | 8 | 0x554a, 5/15 |
| **0xab64 (3.2.0, uncovered)** | **17** | **8** | **0xaf44, 10/17** |
| 3.1.8 0xad2a inner | 17 | 8 | 0xae16, 10/17 |
| 3.1.12 0xad7e inner | 17 | 8 | 0xae6a, 10/17 |

The grouping is not just similar in aggregate: the per-case pattern of
`0xab64` is *identical* to the 3.1.x inner switch, case by case —
`[distinct, dom×8, distinct, distinct, dom×2, distinct, distinct, distinct,
distinct]` — and the raw tables agree on every entry modulo the encoding:

```
3.1.8  @0xad3c (bytes)    08 6c 6c 6c 6c 6c 6c 6c 6c a6 af 6c 6c 45 b8 c1 cb
3.1.12 @0xad90 (bytes)    08 6c 6c 6c 6c 6c 6c 6c 6c a6 af 6c 6c 45 b8 c1 cb
3.2.0  @0xab78 (halfwords) 10 1e5 1e5 1e5 1e5 1e5 1e5 1e5 1e5 220 22a 1e5 1e5 1c0 234 23e 249
```

Every non-dominant offset grew by 0x179…0x17e in address order (0x1e5−0x6c =
0x179, 0x220−0xa6 = 0x17a, … 0x249−0xcb = 0x17e): the same case bodies, in the
same order, each a few bytes larger. Corresponding targets land at
+0x12e…+0x138 (0xaf44 vs 0xae16 … 0xb00c vs 0xaed4), monotone. The only idiom
change is `ldrb`→`ldrh` (the offsets outgrew 8 bits) and `add pc,r3` moving
0xad3a→0xab76. **This is the same switch, carried across 3.1.8→3.1.12→3.2.0.**
INFERRED, but no other pairing in the corpus reproduces a 17-entry table with
identical grouping and a monotone displacement field.

By contrast, none of the three inventoried 3.2.0 switches reproduces the
3.1.x outer 14-case table: case counts 8/13/15, unique targets 5/9/8, and the
guard bases differ (2, 2, 3 versus 9). 0x4b78 is the closest *sibling*: same
`push {r4,r5,r6,r7,lr}` prologue family, same `adr r1,#4; ldr rX,[r1,r0];
mov pc,rX` idiom, same "guard on a parameter then table" entry position — but
its guard base is 2 and its span is 8 cases, so it dispatches a different
index space, and its out-of-range branch (`bhi`→0x50f4) goes straight to the
epilogue, whereas 3.1.x falls through to a compare chain.

**(c) handler callee sets** (BL/BLX targets, deduped)

| unit | unique callees |
|---|---|
| 3.1.8 island 0xa9bc..0xb1a4 | 33 |
| 3.1.12 island 0xaa10..0xb1f8 | 33 (same set modulo the known non-uniform shift) |
| 0x4b78 region (0x4b78–0x4eca + 0x4f20–0x50f6) | 19 |
| 0x50fc region (0x50fc–0x5830) | 20 |
| 0x4eca region | 12 |

Cross-version callee identity: using the exact-signature all-three triples from
`xversion/match_result.json`, only 3 of the 33 island callees have an all-three
counterpart (0x2db0→0x2e68, 0x31a0→0x3258, 0xa450→0xa478); of those only
0x3258 is called by any 3.2.0 switch. **Overlap: 1/19 (0x4b78), 1/20 (0x50fc),
1/12 (0x4eca)** — and 0x3258 is a ubiquitous helper also called from 0x4eca,
0x50fc and unrelated code. Mnemonic-sequence similarity against the 3.1.8
island: normalized SequenceMatcher ratio 0.014/0.016/0.011, longest common
subsequence 11/15/7 tokens of 629/875/291 (1.7 %, 1.7 %, 2.4 %). The
correspondence between the three inventoried switches and the 3.1.x dispatcher
is therefore **at the noise floor** — no handler-set conservation at all.

### Step 3 — SVID literal cross-check (OBSERVED; negative anchor)

All three payloads carry the same literal set; the counts reproduce DIFF §4b.
Which functions load them (16-bit `ldr rX,[pc,#imm]` scan, literal address
resolved, then mapped through each build's Ghidra inventory):

| build | literal | value | loader insns | containing Ghidra function |
|---|---|---|---|---|
| 3.1.8 | 0xc2ec | 0x05AC0005 | 0xc2ce, 0xc2da | **none** (uncovered; builder starts 0xc2b8) |
| 3.1.8 | 0xc2f0 | 0x05AC8106 | 0xc2d2 | **none** (same builder) |
| 3.1.8 | 0xc5e8 | 0x05AC0005 | 0xc5b2, 0xc5bc, 0xc5c6 | FUN_0000c564 (130 B) |
| 3.1.8 | 0xc618 | 0x05AC0000 | 0xc608 | FUN_0000c5f0 (40 B) |
| 3.1.12 | 0xc340 / 0xc344 | 0x05AC0005 / 0x05AC8106 | 0xc322, 0xc32e / 0xc326 | **none** (builder at 0xc30c) |
| 3.1.12 | 0xc63c / 0xc66c | 0x05AC0005 / 0x05AC0000 | 0xc606… / 0xc65c | FUN_0000c5b8 / FUN_0000c644 |
| 3.2.0 | 0xc4e0 / 0xc4e4 | 0x05AC0005 / 0x05AC8106 | 0xc4c2, 0xc4ce / 0xc4c6 | **FUN_0000c4ac (52 B)** |
| 3.2.0 | 0xc7fc | 0x05AC0005 | 0xc7c6, 0xc7d0, 0xc7da | FUN_0000c778 (130 B) |
| 3.2.0 | 0xc82c | 0x05AC0000 | 0xc81c | FUN_0000c804 (40 B) |
| 3.2.0 | 0xc8fc | 0x05AC0000 | 0xc872 | FUN_0000c834 (198 B) |
| 3.2.0 | 0x13804 | 0x05AC0000 | 0x13524 | **none** (uncovered) |

The SVID pair builder is trackable: 3.1.8 `0xc2b8` (≈50 B, uncovered) →
3.1.12 `0xc30c` → 3.2.0 `0xc4ac` (52 B, *covered* in 3.2.0, 0xc4ac–0xc4e0 the
three literal-pool words). Its callee 0xc2f8→0xc338? →(3.2.0) same shape, and
the sibling block 0xc5e8/0xc618 (3.1.8) → 0xc7fc/0xc82c (3.2.0) is at a
consistent +0x214 displacement. So the Apple-SVID code forms a coherent
cross-version neighbourhood at 0xc4ac–0xc8fc in 3.2.0.

That neighbourhood anchors **none** of the switches. Distances from
FUN_0000c4ac: 0x4b78 −0x7934, 0x50fc −0x73b0, 0x4eca −0x75e2, 0xab64 −0x1948.
More decisive: in 3.1.8 the dispatcher island does **not** call the SVID
builder — its 33 BL targets contain no address in 0xc000–0xc6ff. The SVID path
was never inside the dispatcher's callee set in the base version, so the SVID
literal set cannot arbitrate between 3.2.0 switches at all. This is a negative
result, not an anchor (REFUTED: "SVID literals anchor the 3.2.0 dispatcher").

### Step 4 — verdict

**The successors of the 3.1.x dispatcher are not among the three inventoried
3.2.0 switches.** Evidence, all INFERRED except where noted:

1. **0x4b78** — closest *sibling*, not the successor. Same prologue family,
   same `adr`+`ldr [rN,rM]`+`mov pc` idiom, same "guard the second parameter at
   function entry" placement, r1 as index (OBSERVED). But guard base 2 and 8
   cases against base 9 and 14 cases; out-of-range goes to the epilogue instead
   of a compare chain; callee overlap 1/20 with the island, mnemonic LCS 1.7 %
   (noise floor). It dispatches a *different, smaller* index space.
2. **0x50fc** — same index register and `adr`+`mov pc` idiom (OBSERVED), but
   the dispatch sits mid-function after per-port struct extraction from
   `0x20000644 + n*0xf0`/`0x200002a8 + n*0x1cc`, its out-of-range path is an
   early `return`, its 13 cases have 9 unique targets (the 3.1.x shape is
   "few targets, many cases"), and its case bodies *emit* PD message ids 0x3d /
   0x3e through the per-port vtable. Callee overlap 1/20, LCS 1.7 %.
3. **0x4eca** — not a candidate by shape: index is `[[r0]+1]` (a struct byte,
   not a parameter), no prologue, 15 cases over span 3–17 with 8 unique
   targets, 12 callees, LCS 2.4 %. It overlaps 0x50fc's callee set
   (0x5b5c, 0x5d88, 0xb9dc, 0xca08) — it belongs to the same per-port state
   machinery as 0x50fc, not to the 3.1.x message-id dispatcher.

**The one real successor found is at 0xab64, and it is the *second-stage*
switch, not the 14-case outer table** (INFERRED, high confidence). 3.1.8
`0xad2a` / 3.1.12 `0xad7e` / 3.2.0 `0xab64` are the same 17-case
payload-type switch: identical guard `subs #8; cmp #0x10`, identical r3←r2
index chain, identical `add pc` table fetch, identical per-case grouping
(1,8,1,1,2,1,1,1,1 with 8 unique targets and a 10/17 dominant), and the
non-dominant table offsets increase monotonically by 0x179…0x17e in address
order — the same case bodies in the same order, each slightly larger. The only
change is `ldrb`→`ldrh` because the offsets outgrew 8 bits. That site lies in
**uncovered 3.2.0 code** (no Ghidra function contains 0xab64; nearest covered
function ends 0xa946), which is exactly why DIFF §11c's three-switch inventory
missed it, and it sits beside a further uncovered dispatch at 0xa958.

So: **outer 14-case control-message table — "none established"** (REFUTED for
each of 0x4b78 / 0x50fc / 0x4eca); **dispatcher island successor — 3.2.0
0xab64's containing region, INFERRED from switch-table isomorphism, pending a
decompilation of 0xa958–0xb020.** No address chain (pointer word, literal, BL)
links it to 3.1.x, so it is not OBSERVED succession; note also that the whole
3.1.x island still has zero static inbound edges (DIFF §11b), so "successor"
here means "same code lineage", not "live handler".

#### What a CC-line capture would settle (no experiment run here)

A capture on the connector's CC line (BMC decoding of USB-PD traffic on both
directions, with timestamps) would settle the four things static analysis
cannot: (i) whether 3.2.0 still handles the 9–22 message-id space at all, and
under which numbering, by showing which message types the device answers or
initiates (the 2–9 / 2–14 / 3–17 spans cannot be reconciled without an observed
type stream); (ii) which value is the dispatch key — the function parameter
(r1, as in 3.1.x, 0x4b78 and 0x50fc) or a received-packet byte (`[[r0]+1]`, as
in 0x4eca) — by correlating the observed message type with the code path that
reacts to it; (iii) whether the uncovered island at 0xa958–0xb020 ever executes,
which is the whole basis of the 0xab64 verdict and is otherwise unfalsifiable
statically (the same liveness gap as DIFF §11b); and (iv) whether the 0x3d/0x3e
messages emitted by 0x50fc's bodies correspond to the 3.1.x 0x3d out-of-table
case, i.e. whether 0x50fc is the transmit-side counterpart of the old receive
dispatcher rather than its successor. A single capture containing one
Get_Source_Cap/Discover_Identity exchange plus one vendor (0x3d/0x3e) exchange
would be sufficient to discriminate all four.
