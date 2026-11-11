# software-readpath — is there a firmware READ path usable in normal (non-update) mode?

Question: does `UARPUpdaterServiceUSBPD` expose a read path to an A2743 in normal operating
mode, and what does that path actually read? Static only: no run, no frame, no sudo.

## Method

`lipo -thin arm64e` (base 0x100000000, `__objc_stubs` @0x10007fcc0), then
`rizin -q -e bin.cache=true -c 'aa; icm UARPAppleHPM' -c 's <IMP>; af; pdf'` and `otool -oV`.
Selector resolution: each `__objc_stubs` slot is `adrp x1,pg; ldr x1,[x1,#off]; …braa x16,x17`
against a chained-fixup selref (`0x8000…|offset`), target = `0x100000000+(imm & 0xFFFFFFFFF)`.
432/864 stub slots resolved; every IMP was cross-checked against the class method lists.
(`rizin` prints some IMPs as `method.UARPMagSafeCable.*` — it names the stub after the first
class implementing the selector; those IMPs belong to `UARPAppleHPM`.)

## Symbols (OBSERVED)

| IMP | # | method |
|---|---|---|
| 0x100002b30 | 15 | `UARPAppleHPM(AccMode7) accMode7AddressSpaceRead:buffer:bufferLength:lengthRead:error:` |
| 0x100002c30 | 16 | `… accMode7AddressSpaceWrite:buffer:bufferLength:error:` |
| 0x100002974 | 13 | `… accMode7FirmwareUpdateGetState:error:` |
| 0x10000122c | 2 | `… accMode7FirmwareUpdateInitialize:` |
| 0x100002ab4 | 14 | `… accMode7FirmwareUpdateSendCommand:error:` |
| 0x10001609c | 47 | `UARPAppleHPM readCFUa:remoteEndpoint:offset:buffer:bufferLength:lengthRead:error:` |
| 0x100015c64 | 44 | `… doAtomic4CC:data:dataLength:extData:dataOut:dataOutLength:dataOutLengthRead:extDataOut:error:` |
| 0x100001bf8 | 9 | `… accMode7SolicitLogs:modelName:serialNumber:error:` |
| 0x10000246c | 12 | `… accMode7SolicitAnalytics:error:` |
| 0x100011b1c | — | `UARPMagSafeCable -queryHardwareVersion`, reached from `-hardwareVersion` 0x100011a40 |

`UARPMagSafeCable -accMode7AddressSpaceRead:` (0x100011f54) is a two-instruction forwarder
`ldr x0,[x0,0x18]; b 0x10007fd20` — i.e. `[self->_hpm accMode7AddressSpaceRead:…]`.

## 2. Does the read require Mode 7 / firmware-update state?

**No host-side state check exists on the read path.** OBSERVED.

`accMode7AddressSpaceRead` (0x100002b30) is a 24-byte chunking loop with one guard:

```
0x100002b54  cbz  w4, 0x100002bd4          ; bufferLength == 0 -> *lengthRead = 0, return 1
0x100002b6c  lsl  w25, w2, 0xa             ; space << 10
0x100002b7c  sub  w9, w22, w24
0x100002b80  cmp  w8, w22 ; csel w6, w9, w26(0x18), hi      ; chunk = min(24, remaining)
0x100002b94  and  w4, w8, 0xffff           ; address = (space<<10 | accum) & 0xffff
0x100002b98  add  x7, var_54h              ; lengthRead out
0x100002b90  str  x20, [sp]                ; error out
0x100002ba8  bl   readCFUa                 ; stub 0x100081fe0
```
No state ivar is read and `GetState` is never called; the only `self` dereference is
`self->_log` at 0x100002bf0. `readCFUa` (0x10001609c) is equally ungated — its only `self`
reads are `ldr w10,[x0,8]` (`_sopType`, 0x1000160c8) and `_log` (0x100016140).

The only gate in the whole call chain is in `doAtomic4CC` (0x100015c64):

```
0x100015cb8  mov x0,x19 ; bl 0x1000812e0    ; stub -> "isConnnected" (sic)
0x100015cc0  tbz w0, #0, 0x100015de0        ; not connected -> error path
0x100015d5c  mov w0,0xa ; bl _sleepMS       ; 10 ms; cmp w28,0xa at 0x100015d68 = 10 attempts
0x100015d20  cmp w27,0xe00002c7 ; ccmp w27,0xe00002c2   ; retryable IOReturns
```

A state machine exists, but it is entered by *writes*, and `GetState` is what probes it:
`SendCommand` 0x100002ad4 = write 4 B to space 1; `GetState` 0x10000299c = read 12 B from
space 1; `Initialize` 0x100001284 calls `GetState` **first**, and only then
(`0x100001294 b.eq 0x1000013e4` for state==1, else `0x10000139c bl SendCommand` w2=1) writes
the entry command, polling `GetState` every 100 ms up to 300 times (`0x1000013a8…0x1000013d4`)
until state==1, then sends w2=2. Command values: 1 = enter/control
(`kAccMode7Mode7FirmwareUpdateControl`), 2 = Start, 4 = Apply (`0x100001a4c mov w2,4`).
So Mode 7 entry is a 4-byte write of `1` to address 0x400, issued only *after* a successful
read of the same page. **INFERRED (high):** the host expects address-space reads to work
before Mode 7 entry; that is the only consistent reading of the call order.

Independent of any update session, `-hardwareVersion` → `-queryHardwareVersion`
(0x100011b1c) → `accMode7AddressSpaceRead(space=0x1b, len=4)`, with no `GetState` or
`SendCommand` anywhere in that path. OBSERVED.

## 3. Address spaces, offsets, bounds

```
0x100002b6c / 0x100002c68   lsl w25, w2, 0xa      ; space << 10
0x100002b94 / 0x100002c90   and w4, w8, 0xffff    ; 16-bit address = (space<<10) + offset
```
Model: **64 KiB, 64 pages of 1 KiB** — bits[15:10] page, bits[9:0] offset.

| page (addr) | len | caller | contents |
|---|---|---|---|
| 1 (0x0400) | 12 R / 4 W | `GetState` 0x10000299c (w2=1,w4=0xc); `SendCommand` 0x100002ad4 | update state block / command word |
| 27 (0x6C00) | 4 | `queryHardwareVersion` 0x100011b44 (`mov w2,0x1b; w4=4`) | hardware-version VDO |
| 28 (0x7000) | 4 / ≤1 KiB | `SolicitLogs` 0x100001d1c (W 4 B @0x7000), 0x100001d5c (R `0x7000\|(n&0x3ff)`); `SetLogLevel` 0x10000237c (0x7004); `ClearLogs` 0x100002414 (0x7008, payload `'ClLg'`=`0x674c/0x6c43`) | log stream + log control regs |
| 40 (0xA000) | 24 B/chunk | `SolicitAnalytics` 0x10000252c (`orr w8,w25,w23`, `w23=0xa000`) | analytics stream |

Bounds (OBSERVED): payload per transaction is 24 B, or 20 B when `_sopType == 0`
(`0x1000160c0 mov w8,0x18`; `0x1000160d4 csel w8,w11(0x14),w8,eq`; `0x1000160d8 csel w8,w7,w8,lo`;
write side `0x100002c6c mov w26,0x14`). Log stream ceiling `0x100001e2c cmp w27,0x10,lsl 12`
(0x10000) with `0x100001d30 cmp w19,0x3e8 ; csel w20,(0x400-w19),0x18,hi` keeping chunks
inside one 1 KiB page. **No allowlist**: `space` is shifted and masked to 16 bits and nothing
else — no table lookup, no upper-page check, so a caller can encode any address 0x0000–0xFFFF.
Nothing maps application flash: no code path walks a flash range, and the only page outside the
four above appears in the *write* path as a header word (`0x100001674 mov w8,0x800 ;
bfxil w8,w21,0,0xa` → `0x800 | (offset & 0x3FF)`) for the `CFUs` firmware stream
(INFERRED: staged-asset stream tag, not a readable page).

## 4. Transport and framing

Reads are `CFUa` 4CC transactions, not USB transfers.

```
0x10001610c  mov w2,0x4643 ; movk w2,0x6155,lsl 16   ; 4CC "CFUa" (bytes 43 46 55 61)
0x10001611c  bl doAtomic4CC
```
Request descriptor (32-bit, built 0x1000160c0–0x100016108, OBSERVED):

| bits | field | evidence |
|---|---|---|
| 15..0 | address (page<<10 \| offset) | `orr w10,w10,w4` |
| 16 | direction, 1 = read | `orr w5,w8,0x10000` — absent in `writeCFUa` (0x1000161f8) |
| 20..18 | remoteEndpoint (callers pass 1) | `ubfiz w10,w3,0x12,3` |
| 24..22 | 3-bit aux field, 0 in every AccMode7 path | `bfi w10,w2,0x16,3`; callers `mov w2,0` |
| 28..24 | payload length | `lsl w8,w8,0x18` |
| 31..30 | SOP type | `ldr w10,[x0,8]` + `lsl w30` |

Response, decoded from the 4-byte `dataOut` word: `0x100016128 tbnz w8,#0x17` → bit 23 = failure;
`0x100016130 ubfx w8,w8,0x18,5` → bits 28..24 = bytes transferred (cf. the string
`"%s: CFUa read failed with response: 0x%08x"`).

`doAtomic4CC` then performs an IOKit-bound call, not a USB copy: `0x100015cd0 ldr x0,[self,0x20]`
(`_deviceInterface`, an `IOCreatePlugInInterfaceForService` object; the binary imports
`_IOCreatePlugInInterfaceForService`/`_IODestroyPlugInInterface`), `0x100015cd8 ldr x8,[x8,0x68]`,
`0x100015d08 blraaz x8`, with `0xe00002c7`/`0xe00002c2` handled at 0x100015d20.
**INFERRED (medium-high):** the HPM kext turns this 4CC mailbox op into the PD VDM to the
accessory endpoint; that conversion lies outside this binary and is not quoted here.

Not on this path: `iecsRead`/`iecsWrite`/`iecsCommand` (0x1000152c0 / 0x1000153dc / 0x10001545c)
and `sendVDM:`/`receiveVDM:` (0x1000154d0 / 0x10001559c) exist on the class but are never
reached from any AccMode7 read; `setCFUp:` (0x100015ebc) is the separate enable gate.

## 5. Verdict

- **No application-flash read path exists in this binary.** OBSERVED: the only read primitive
  is `readCFUa`/`accMode7AddressSpaceRead`; every caller uses page 1, 27, 28 or 40. Firmware
  data movement is write-only (`CFUs`: 0x100001714 in `…WriteData` → `writeCFUs` 0x100015f94).
- **The read primitive is not gated on Mode 7 by the host.** OBSERVED: only `bufferLength != 0`
  and `isConnnected` are checked; `GetState` reads page 1 *before* the Mode 7 entry write, and
  `-hardwareVersion` reads page 27 with no update session at all.
- **The remaining blocker is accessory-side.** Whether an A2743 answers a `CFUa` read of
  page 1/27/28/40 (or any other page) while not in firmware-update mode is decided by the
  adapter's PD firmware, which is not in this binary → **OPEN**. Named blockers: (a) accessory
  acceptance of `CFUa` outside Mode 7; (b) no page in the host map corresponds to application
  flash; (c) the 64 KiB / 1 KiB window model is a hard structural limit. Confidence: high that
  the host applies no Mode 7 gate to reads; high that no flash-read feature is implemented.

## What would falsify this

- A decompilation of `UARPPowerAdapter`/`UARPUSBPDUpdater` suppressing AccMode7 calls when a
  mode flag is clear (a caller-side gate above the IMPs analysed here).
- Any page constant outside {1, 27, 28, 40} reaching `accMode7AddressSpaceRead`; or a second
  flat-address API (e.g. `iecsRead`) reaching this accessory; or runtime evidence (out of scope)
  that `CFUa` reads return bit 23 set in normal mode but clear after the 0x400 write.
