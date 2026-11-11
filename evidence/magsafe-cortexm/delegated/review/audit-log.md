# Independent audit log — MagSafe A2363 (auditor-written, before reading audit targets)

Rule followed: all observations below were produced from clean imports and my own
disassembly BEFORE opening DIFF.md or delegated/*.md.

## Step 1 — image hash verification
```
shasum -a 256 firmware/images/A2363_*.bin
grep -E 'A2363_(3\.1\.8|3\.1\.12|3\.2\.0)' SHA256SUMS | shasum -a 256 -c -
```
OBSERVED / REPRODUCED: all three images OK.
- 3.1.8  db4baf86b068ad2a0bc7716a354d30a14fd2a778d7d2f26840e1f806dfd2400f
- 3.1.12 611f6930e85c3f195424af618fb2834e41f9c3f57e04cc2ffe9d8da5f7bcde02
- 3.2.0  6d158f971ab7632a30ecd1060ef0131368e2d5e746fc5c529f9b111b6df0050e
(git branch research/magsafe-semantic-diff; working tree clean.)

## Step 2 — clean base-0 import of 3.1.8
Command (Ghidra 12.1.4 headless, /tmp project, outside dot paths):
```
GH=/Users/sein/.hermes/tools/ghidra/ghidra_12.1.4_PUBLIC/support/analyzeHeadless
JAVA_HOME=$(brew --prefix openjdk@21) $GH /tmp/magsafe-audit probe318 \
  -import firmware/images/A2363_3.1.8_10M569_base0.bin \
  -processor ARM:LE:32:Cortex -cspec default -scriptPath /tmp -noanalysis \
  -postScript AuditProbe.java
```
OBSERVED:
- LANGID=ARM:LE:32:Cortex, LANGDESC=ARM/little/32/Cortex, COMPILER=default
- image range 0x0..0x14607 (83464 bytes, matches file size)
- bytes @0x10: f0 b5 85 b0 72 b6 41 48 → `push {r4,r5,r6,r7,lr}` (Thumb-2 encoding f0 b5 = push.w? -> Ghidra prints push {r4-r7,lr})
- reset-vector word @0x10f7c: bytes 90 01 00 20 = 0x20000190 (initial SP). Does NOT
  decode as a function prologue: Ghidra yields `lsls r0,r2,#0x6` (garbage), no function.
  CONFIRMED: vector table word is data, not code.

## Step 3 — seeded run, 3.1.8, clean project
```
rm -rf /tmp/magsafe-audit/s318*
$GH /tmp/magsafe-audit s318 -import firmware/images/A2363_3.1.8_10M569_base0.bin \
  -processor ARM:LE:32:Cortex -cspec default -scriptPath scripts/ghidra \
  -postScript SeedCortexM.java evidence/magsafe-cortexm/seeds3_318.csv \
  evidence/magsafe-cortexm/delegated/review/inventory3_318_audit.json \
  evidence/magsafe-cortexm/delegated/review/decomp3_318_audit
```
OBSERVED: `DONE functions=444`. Diff vs evidence/magsafe-cortexm/inventory3_318.json:
444 vs 444, identical addr set, identical names, identical sizes (0 diffs).
Sum of function-body bytes = 38760 / 83464 image bytes = 46.4% (rest = data,
literal pools, padding, vector table). No "clear ABORTED" lines in the log
(105 log lines: seeds + clear lines).
NOTE: one seeded name is `caseD_c` (0xee72) — the name comes from Ghidra switch
analysis, not from the seed CSV.

## Step 4 — rizin decode (3.1.8, -a arm -b 16, file offsets)
```
rizin -q -e scr.color=0 -a arm -b 16 -c 'e asm.arch=arm; s 0xa9bc; pd 24' <img>
rizin -q -e scr.color=0 -c 'pxw 64 @ 0xa9d8' <img>
```
OBSERVED at 0xa9bc (14 instructions):
  0xa9bc push {r4,r5,r6,r7,lr}
  0xa9be sub  sp, 0x1c
  0xa9c0 mov  r5, r2
  0xa9c2 mov  r4, r0
  0xa9c4 mov  r0, r1
  0xa9c6 subs r0, #9
  0xa9c8 cmp  r0, #0xd
  0xa9ca ldr  r7, [0xad7c]   ; =0x20001a10
  0xa9cc ldr  r6, [0xad80]   ; =0x200002b0
  0xa9ce bhi  0xaa1c         ; default for type > 0x16
  0xa9d0 lsls r0, r0, #2     ; 4-byte table entries
  0xa9d2 adr  r1, 4 -> 0xa9d8
  0xa9d4 ldr  r0, [r1, r0]
  0xa9d6 mov  pc, r0         ; CONFIRMED computed dispatch
Table @0xa9d8, 14 words (0xa9d8..0xaa0f):
  aed0 ae90 b154 af08 b154 b154 b154 b154 b154 ae90 af50 b154 b154 af72
Word 15 @0xaa10 = 0xd0002c01  → NOT a pointer. CONFIRMED (table is exactly 14).
ANOMALY (my own observation): 14th word = 0xaf72 lands inside function 0xaf54
(push {r4,r5,r7,lr} at 0xaf54), at `cmp r0,0` preceded by an r4 load at 0xaf6e;
entering there from the dispatcher would run `str r1,[r4,0x60]; pop {r4,r5,r7,pc}`
with a dispatcher frame and r4=arg0. 3.1.12 shows the same shape (word 14 =
0xafc6 inside function 0xafa8). Flagged for Phase 2 comparison.

0xaa2a in 3.1.8 = `bne 0xaa2e`, preceded by `cmp r1,#0x28` at 0xaa28. It is a
conditional branch in the secondary (out-of-jump-table) compare chain, NOT a
computed branch. CONFIRMED. (In 3.1.12 the identical byte position 0xaa2a is
`mov pc,r0` — same 2 bytes, different meaning due to differing table base.)

3.1.12 dispatcher entry 0xaa10:
  push {r4,r5,r6,r7,lr}; sub sp,0x1c; ... subs r0,#9; cmp r0,#0xd;
  bhi 0xaa70; lsls r0,#2; adr r1,4 -> 0xaa2c; ldr r0,[r1,r0]; mov pc,r0.
Table @0xaa2c: af24 aee4 b1a8 af5c b1a8 b1a8 b1a8 b1a8 b1a8 aee4 afa4 b1a8 b1a8 afc6
Word 15 @0xaa44 = 0xd0002c01 → not a pointer. Same guard, same shape. CONFIRMED.

xref search for 0xa9bc in 3.1.8 (BL decode of all 1920 BL sites via bl_xref.py,
plus raw scans): no BL, no B.W, no 32-bit pointer word, no halfword 0xa9bc, no
thumb-flagged pointer 0xa9bd. => dispatcher has NO static reference. OBSERVED.

## Step 5 — decompiler claims vs my own Thumb decode (3.1.8)
(a) default/unhandled-type slot 0xb154 (referenced by table words 2,4,5,6,7,8,11,12):
```
0xb154 movs r0,0        -> FUN_0000a500(0)
0xb156 bl   0xa500
0xb15a bl   0x6828      -> FUN_00006828()
```
CONFIRMED at instruction level. Nuance: this is the *jump-table default
(unhandled type)* slot; the out-of-range secondary chain at 0xaa1c does NOT go
to 0xb154 — it returns via 0xacd4 for unmatched types.
(b) case 0x28: 0xaa28 cmp r1,#0x28; 0xaa2a bne; 0xaa2c b 0xac7a;
0xac7a cmp r4,#1 / bne; 0xac7e ldr r4,[0xaf2c]=0x20001854; 0xac80 ldrb r0,[r4,#0x14];
cmp 0; 0xac86 movs r0,0; 0xac88 bl 0xd904. CONFIRMED that the case calls
FUN_0000d904, but only conditionally ([0x20001854+0x14]==0).
(c) store near 0xaf76: bytes 21 66 b0 bd = `str r1,[r4,#0x60]` ; `pop {r4,r5,r7,pc}`.
IMPORTANT: r1 is NOT the message type here.
  - switch path: 0xa9d2 `adr r1,4` sets r1 = 0xa9d8 (table base), and nothing in
    0xa9d6..0xaf76 reloads r1 → stores 0xa9d8.
  - fall-through path: 0xaf6e ldr r4,[0xafe0]=0x20001854; 0xaf70 ldrb r0,[r4,#0x11];
    0xaf72 cmp r0,0; 0xaf76 str r1 → here r1 is 0xaf54's 2nd argument, which the
    sibling block at 0xaf7a/0xaf80 (`blx r1`) shows is a CALLBACK POINTER.
  So the instruction stores r1 = {table base | callback}, neither of which is the
  "message type". My independent view: the claim as worded is REFUTED; the
  decompiler rendering `param_1[0x18] = &PTR_FUN_0000a9d8` is faithful to the
  switch path. Also note 0xaf72 is inside function 0xaf54 (prologue push
  {r4,r5,r7,lr} at 0xaf54, matching pop at 0xaf78) yet is a switch-table target —
  structurally impossible as a genuine case entry; see Step 4 anomaly. Status OPEN
  pending the documents' exact wording.
Data check: 3.1.8 function at 0xaf72 exists in the seeded inventory (size 18,
FUN_0000af72); 0xaf54 is NOT a function in that inventory (swallowed).

## Step 6 — cross-version reproduction (3.1.12)
```
$GH /tmp/magsafe-audit s3112 -import firmware/images/A2363_3.1.12_10M1543_base0.bin \
  -processor ARM:LE:32:Cortex -cspec default -scriptPath scripts/ghidra \
  -postScript SeedCortexM.java evidence/magsafe-cortexm/delegated/xversion/seeds3_3112.csv \
  evidence/magsafe-cortexm/delegated/review/inventory3_3112_audit.json \
  evidence/magsafe-cortexm/delegated/review/decomp3_3112_audit
```
OBSERVED: `DONE functions=436`.
Diff vs delegated/xversion/inventory3_3112.json: 436 vs 436, identical address
sets, identical sizes, 0 diffs. Body bytes 37748/83592 = 45.2%. 98 seed lines.
(Their inventory3_3112.json.log has no DONE line — the count has to be taken
from the inventory length, not from the log.)
