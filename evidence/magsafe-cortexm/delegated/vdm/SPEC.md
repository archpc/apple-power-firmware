# Which VDM form carries UARP TLVs to the MagSafe cable (host-side static only)

Scope: host binaries `kexts/com.apple.driver.AppleHPM.macho`
(sha256 `22b4e60f…71901d`), `UARPUpdaterServiceUSBPD` evidence as recorded in
`evidence/usbcupdater-notes.md` and `adapter-70w/evidence/dump/software-readpath.md`,
and the three A2363 images `firmware/images/A2363_{3.1.8,3.1.12,3.2.0}_base0.bin`
plus `firmware/payloads/A2452/BRCK_1.4.90.0.bin` (already extracted).
No device contact, no flashing, no protection bypass. Offsets are file/vaddr as noted.

Label legend: OBSERVED = read from bytes/disassembly; INFERRED = reasoned, not proven;
OPEN = not settled by this evidence.

---

## 1. Verdict

**OBSERVED — the kernel has two different senders, and only one is the `VDMs` frame.**

| sender | vaddr | what it puts on the link |
|---|---|---|
| `AppleHPM::hpmIECSSendVDM(ull, AppleHPMSOPType, IOMemoryDescriptor*, u8, u32)` | `0xfffffe00095205ec` | `[hdr][payload ≤28 B]` then a **hard-coded** 4CC `0x56444D73` "VDMs" via a second vtable call (+0x8f0, arg 5) |
| `AppleHPM::hpmIECSCommand(ull, u32 4CC, u32 flags, u32 lock)` | `0xfffffe0009521a0c` | the 4CC is **byte-reversed and written as data**, then a status poll waiting for `0x444D4321` ("!CMD") |

`hpmIECSCommand` disassembly (`0xfffffe0009521b34`–`0xfffffe0009521b6c`):

```
rev   w8, w23                 ; w23 = arg3 = the 4CC  -> bytes 43 46 55 61 style order
str   w8, [sp]
...   vtable +0x8c0 (this, route, 8, buf, 4, arg4)   ; 4-byte 4CC write
mov   w27, 0x4321  ; movk w27, 0x444d, lsl 16        ; 0x444D4321 = "!CMD"
loop: vtable +0x8d0 (route, 8, out, buf, arg4) ; cmp out,0x444D4321
```

So the transport is generic: **any 4CC can be pushed as a 4-byte command word with a
"!CMD" acknowledgement**, and `VDMs` is just one tag among them. This is the structural
fact that answers the question: the `VDMs` 4CC is a *tag for the VDM/identity command
class*, not the envelope for firmware update.

**OBSERVED — the UARP path never constructs the `VDMs` frame.** It goes through the
4CC mailbox with CFU tags:

```
adapter-70w/evidence/dump/software-readpath.md:106-110
0x10001610c  mov w2,0x4643 ; movk w2,0x6155,lsl 16   ; "CFUa"
0x10001611c  bl doAtomic4CC
```

and `UARPAppleHPM` also holds `setCFUp` (`"iecsCommand(CFUp) failed"`), `writeCFUa:`,
`writeCFUs:remoteEndpoint:protocol:` (`evidence/usbcupdater-notes.md:376-379`).

**OBSERVED — the kext contains no CFU literal at all.** 32-bit scan of
`kexts/com.apple.driver.AppleHPM.macho` (26 659 051 B):

```
CFUp 0x70554643 -> 0 hits     CFUa 0x61554643 -> 0 hits
CFUs 0x73554643 -> 0 hits     ASCII "CFU"     -> 0 hits
"VDMs" 0x734D4456 -> 0 hits as a data literal, but 8 sites build it with
                     movz/movk (0x37734, 0x3fc6c, 0x486b0, 0x48c0c, 0x48c28,
                      0x48c58, 0x48ca0, 0x59b78 = movz #0x4456 + movk #0x734d)
```

i.e. the kext never names `CFUp/CFUa/CFUs`; those arrive as **runtime arguments** of the
plug-in `doAtomic4CC` entry, which resolves to `AppleHPM::atomic4CC` @
`0xfffffe0009522600` (`__ZN8AppleHPM9atomic4CCEhPhS0_S0_S0_S0_ttyyj`) and its
descriptor twin `AppleHPM::hpmAtomic4CC(uchar, IOMemoryDescriptor* ×5, u16, u16, ull, uint)`
@ `0xfffffe0009522200`. The `VDMs` tag by contrast is only ever emitted from the kext's
own code.

**Conclusion (OBSERVED + INFERRED-high):** UARP firmware-update TLVs are carried as
**Apple-proprietary 4CC-tagged mailbox/VDM command transactions with 4CC ∈
{`CFUp` (control), `CFUa` (address space), `CFUs` (firmware stream)}**, addressed per
endpoint, with the TLV bytes as the transaction data. They are **not** carried in the
`VDMs` 4CC frame, and **not** in a USB-PD 3.x structured VDM (SVID 0x05AC + SVDM header).
The only SVID-0x05AC structured object on the host side is the *payload word*
`0x05ACA001` inside a `VDMs` frame — a Discover-Identity request, not a TLV carrier
(`PROTOCOL.md` §2, `evidence/applehpm-decompiled.md:60-68`).

The `"UARP over USB-PD Structured VDMs"` phrasing in `evidence/usbcupdater-notes.md:42`
is therefore **misleading as byte-level description**: the transport is Apple's IECS/4CC
mailbox, whose *contents* can include VDO-shaped words. Label that note INFERRED
(terminology) and treat the 4CC mechanism as the OBSERVED transport.

---

## 2. SOP vs SOP': which endpoint is updated

**OBSERVED — the SOP selector is bits 5:4 of the frame header, and the one observed
cable discovery uses selector 2.**

```
PROTOCOL.md §2 / applehpm-decompiled.md:44-55
0xfffffe00094ede2c  mov  w8, #0x4456
0xfffffe00094ede30  movk w8, #0x734d, LSL #16
0xfffffe00094ede38  mov  w8, #0x5               ; 4CC length/arg
0xfffffe00094ede44  movk w8, #0xaca0, LSL #16   ; payload 0xACA00121 -> 21 01 A0 AC
0xfffffe00094ede70  mov  w1, #0x8               ; payload bit count
```

header byte `0x21` = `(2<<4)|1`, and the enclosing routine logs
`AppleHPMInterface::isCableKartCapable … role is wrong, issuing discovery on sop'`
(`evidence/applehpm-strings.txt:915`; same string for `AppleTCController` at line 1956).
**INFERRED (high):** in this 2-bit Apple encoding, selector 2 = SOP' (the cable e-marker);
selector 0/1 would then be SOP / reserved. One datum, so the full mapping stays OPEN
(as `PROTOCOL.md` already flags).

**OBSERVED — the UARP CFU descriptor carries an explicit endpoint field and a separate
SOP-type field** (`software-readpath.md:112-121`):

| bits | field | evidence |
|---|---|---|
| 31..30 | SOP type, from ivar `_sopType` (`ldr w10,[x0,8]`) | `0x1000160c8` |
| 20..18 | `remoteEndpoint` (3 bit) — **every caller passes 1** | `ubfiz w10,w3,0x12,3` |
| 16 | direction, 1 = read | `orr w5,w8,0x10000` |
| 28..24 | payload length | `lsl w8,w8,0x18` |

**OBSERVED (class split, not bytes):** `UARPMagSafeCable` vs `UARPPowerAdapter` exist side
by side in `UARPUpdaterServiceUSBPD`; the notes record the delegating strings
`"SOP Delegate = <%@>"`, `"SOP Prime Delegate = <%@>"`, `"SOP Type = <%d>"` and state
SOP→adapter, SOP'→cable (`usbcupdater-notes.md:318-320, 349`).

**So:** the cable is addressed at **SOP' (e-marker)** on a **separate controller/endpoint
from the adapter's SOP**, and `remoteEndpoint = 1` in every observed CFUa/CFUs caller.
What is **OPEN** is the numeric value actually stored in `_sopType` for the cable object —
that ivar is set by code above the analysed IMPs and was not read out here. The
"which endpoint" answer is therefore OBSERVED at the class/selector level
(selector 2 = SOP' in the one cable-facing frame; SOP'→MagSafe in the class split) and
INFERRED at the CFU descriptor level.

---

## 3. Cable side: what the A2363 images actually contain

Images: `A2363_3.1.8_10M569_base0.bin` (83 464 B), `3.1.12` (83 592 B), `3.2.0` (84 048 B),
all plaintext Thumb-2, `base0` = vaddr 0.

### 3.1 The cable parses Apple VDMs — OBSERVED

Dispatcher at **`0xb34c`** (3.1.8), first VDO in `[msg+8]`:

```
0xb356  ldr   r4, [r1, 8]            ; first received 32-bit word
0xb360  lsrs  r0, r4, 0x10           ; bits 31:16 = SVID
0xb362  movs  r1, 0xff ; lsls r1, r1, 8      ; 0xFF00 = USB-IF SVID
0xb366  cmp   r0, r1  ; beq 0xb376
0xb36a  ldr   r1, [0xb59c]           ; [0xb59c]=0x000005AC  (Apple SVID)
0xb36c  cmp   r0, r1  ; beq 0xb372
0xb370  b     0xb52e                 ; unknown SVID -> drop
0xb372  lsls  r0, r4, 0x10
0xb374  bpl   0xb38a                 ; bit15 clear -> unstructured UVDM
0xb376  lsls  r0, r4, 0x18 ; lsrs r0, r0, 0x1e   ; bits 7:6 must be 0
0xb384  bl    0xb64c                 ; -> unstructured handler
0xb392  ldr   r4, [r6, 8]
0xb394  movs  r1, 0xf ; ands r0, r4, r1         ; VDM command = bits 3:0
0xb3a6  bl    0x10aa8                ; command 0xF branch
```

Also in the same function's constant area: `[0xb5a0]=0x05AC0010`,
`[0xbb9c]=0x05AC8003` (SVID 0x05AC + SVDM header 0x8003), `[0xbb94]=0xFF008001`
(USB-IF SVID + Discover Identity), `[0xbaf0]=0x000005AC`, `[0xbcc0]=0x000005AC`.

**So the cable can be shown to receive:**
- a 32-bit word, SVID in bits 31:16, Apple `0x05AC` matched explicitly (**byte-order
  corrected**: `lsrs #16` on the word as stored),
- the structured/unstructured split on bit 15,
- SVDM command in bits 3:0 with a table of canned headers.

### 3.2 The unstructured (UVDM) handler — OBSERVED, and it keys on VDO count, not 4CC

```
0xb64c  push {r4-r7,lr} ; sub sp,0x2c
0xb650  movs r7, 0x1f
0xb652  mov  r4, r1 ; ands r4, r7        ; r4 = header & 0x1f = VDO count
0xb656  subs r3, r4, 1 ; cmp r3, 4 ; bhi 0xb6fa  ; accept counts 1..5 only
0xb668  ldr  r1, [0xb700]                ; [0xb700]=0x00013AA8  length table
0xb66c  ldr  r2, [0xb704]                ; [0xb704]=0x00013AC0  pointer table
0xb676  bl   0x170                       ; memcpy(dst, table_ptr, len)
0xb67c  cmp  r4, 5 ; beq 0xb6c0
0xb680  cmp  r4, 4 ; beq 0xb6a2
0xb684  cmp  r4, 1 ; bne 0xb6ee
```

The count field is `payload_len/4` in Apple's own frame layout (`PROTOCOL.md` §2:
`(sop&3)<<4 | ceil(len/4)`), and this handler accepts exactly 1..5. **There is no 4CC
compare anywhere in it**: the trailing `VDMs`/tag word is not interpreted by the cable
application. The cable dispatches on *VDO count* and copies from two static tables.

### 3.3 The cable composes an Apple Discover-Identity SVDM — OBSERVED (all three images)

3.1.8, function at `0xc2b8`:

```
0xc2be  ldr   r2, [0xc2f4]        ; [0xc2f4]=0x200011D8 (per-port struct base)
0xc2c0  adds  r1, r2, r1          ; entry = base + idx*0x30
0xc2c2  ldr   r1, [r1, 4] ; ldrb r1, [r1, 0x14]   ; per-port VDM state byte
0xc2c6  cmp   r1, 1 ; beq 0xc2da
0xc2cc  bne   0xc2e2              ; >1 -> send 0 words
0xc2ce  ldr   r1, [0xc2ec]        ; [0xc2ec]=0x05AC0005
0xc2d0  str   r1, [sp, 4]
0xc2d2  ldr   r1, [0xc2f0]        ; [0xc2f0]=0x05AC8106
0xc2d4  str   r1, [sp]            ; word0 = SVID 0x05AC | SVDM hdr 0x8106
0xc2d6  movs  r2, 2               ; two VDOs
0xc2e6  bl    0xc2f8              ; pack + queue
```

`0x05AC8106` = SVID `0x05AC` in 31:16, header `0x8106` = structured VDM, version 1.0,
object position 0, command type 1 (Discover Identity). `0x05AC0005` is an ID-Header-VDO
shape (VID `0x05AC` in 31:16). `0xc2f8` packs the words and calls `0x295c` with
length 0x0C and callback `0xc7f5`.

Same constant pair at all three versions, with a stable +0x54 / +0x1F4 code shift:

```
3.1.8   0xc2ce  ... 8c bd | 05 00 ac 05 | 06 81 ac 05 | d8 11 00 20
3.1.12  0xc344  ... 8c bd | 05 00 ac 05 | 06 81 ac 05 | d8 11 00 20
3.2.0   0xc4e4  ... 8c bd | 05 00 ac 05 | 06 81 ac 05 | 4c 11 00 20
```

Raw `ac 05` byte-pair counts: 26 / 26 / 23.

### 3.4 What is absent — OBSERVED

```
"VDMs"  b'VDMs'  -> 0 hits in all three images
"CFU"   b'CFU'   -> 0 hits in all three images
"UARP"  b'UARP'  -> 0 hits in all three images
```

(consistent with `DIFF.md` §7 for `VDMs`; the CFU/UARP searches are this task's).
No 4CC dispatch table, no `CFUp/CFUa/CFUs` handler, and no code path that reads a 4CC out
of a received buffer.

**Therefore the cable can be shown to receive** structured and unstructured VDM words
with SVID `0x05AC`/`0xFF00`, dispatched by SVDM command nibble or by VDO count (1..5),
and **cannot be shown to receive** UARP/CFU transactions, `VDMs`-tagged frames
distinguished as such, or any 4CC-keyed command. Whether a CFU transaction is consumed by
the cable's PD PHY / a masked ROM area rather than this application image is **OPEN** —
these three images are the application payload (`2363` 4CC) and their code range ends at
`0x14404`.

---

## 4. Contrast: A2452 140 W (`BRCK` 1.4.90)

Payload already present at `firmware/payloads/A2452/BRCK_1.4.90.0.bin` (59 904 B,
`layout.json` 4CC `BRCK`), so no archive was opened.

```
"ac 05" -> 16 hits (0x338, 0xe52, 0xea6, 0xeaa, 0x138e, 0x1432, 0x16ea, 0x16f6, ...)
"06 81" -> 2 hits (0x11c5, 0xcf37) — both are instruction bytes, not literals:
          0x11c5: 20 46 a0 06 81 42   = mov r0,r4 ; lsls r0,r4,#0x1a ; cmp r1,r0
          0xcf37: 00 06 81 0f         = lsls r0,r0,#0x18 ; lsrs r1,r0,#0x1e
"VDMs"/"CFU"/"UARP" -> 0 hits
```

So the 140 W adapter payload carries `0x05AC` identity words but **no `0x05AC8106`
Discover-Identity composition site** and no 4CC/UARP artefacts. INFERRED: the adapter's
identity response is table-driven (its `0x05AC` words sit at low offsets 0x338–0x16f6,
i.e. in a descriptor block, not in a `.text` literal pool), which is a different shape
from the cable's code-built SVDM. This is a contrast datum, not a claim that the adapter
lacks UARP — the adapter updates over SOP with the same CFU 4CCs per the host notes.

---

## 5. Bounded answer

| statement | label |
|---|---|
| Host has a dedicated `VDMs`-tagged frame sender (`hpmIECSSendVDM`) with `sop` in bits 5:4, payload ≤ 28 B, 4CC `0x56444D73` appended by a second call | OBSERVED |
| Host has a generic 4CC command sender (`hpmIECSCommand`) that byte-reverses the 4CC and waits for `"!CMD"` 0x444D4321 | OBSERVED |
| UARP TLVs move as `CFUp`/`CFUa`/`CFUs` 4CC transactions through `doAtomic4CC` → plug-in → `AppleHPM::atomic4CC`/`hpmAtomic4CC` | OBSERVED (primitive, 4CC values, call chain) |
| The `VDMs` frame is *not* the UARP carrier; no `VDMs`/CFU literal exists in the kext for CFU | OBSERVED |
| UARP-over-PD is "structured VDMs" in the USB-PD sense (SVID 0x05AC + SVDM header) | REFUTED at byte level; the phrase is terminology only |
| Cable addressed at SOP' (e-marker), adapter at SOP | OBSERVED at class/selector level, INFERRED at descriptor level (`_sopType` value not read) |
| Cable receives Apple SVID VDMs: SVID compare `0x05AC`, structured bit 15, command bits 3:0, UVDM handler by VDO count 1..5 | OBSERVED (3.1.8 disassembly; same constant pools in 3.1.12 / 3.2.0) |
| Cable composes SVID `0x05AC` + `0x8106` Discover-Identity response | OBSERVED, identical idiom in all three versions |
| Cable implements CFU/UARP handling | NOT SHOWN — zero `CFU`/`VDMs`/`UARP` bytes, no 4CC parse |
| Value of `_sopType` for the cable CFU path | OPEN |
| Whether CFU is consumed outside the app image (PD PHY / ROM) | OPEN |

### What a CC-line capture would settle

A single passive capture on CC during a cable update settles everything the static
evidence leaves open in one shot: the actual PD message headers show whether the host
speaks SOP' (bit pattern `sop=2` in Apple's own header, or PD `SOP'` in a real PD frame),
whether the CFU traffic appears as a USB-PD **structured VDM** (SVID 0x05AC in bits 31:16
of word 0, SVDM header in 15:0, command type in bits 10:8) or as Apple's **4CC mailbox**
form (a 4-byte word `CFUp`/`CFUa`/`CFUs` appearing as data, `"!CMD"`-style acks,
`VDMs` tag after the payload), and whether the TLV bytes sit in 28-byte UVDM payloads or in
20/24-byte CFUa chunks. It would also show the cable's replies, which is the only way to
tell whether the cable application answers CFU at all or whether the answer comes from
below it. One capture, three questions closed: SOP vs SOP', SVDM vs 4CC, and who acks.
