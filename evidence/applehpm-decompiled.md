# AppleHPM decompilation evidence (kernel side)

Artifact: `kexts/com.apple.driver.AppleHPM.macho`
sha256 `22b4e60f6e9a5b7cd33a8246d8d539962651b58c7760f7aaff22ecfd5171901d`
Provider: Ghidra 12.1.4 via REA MCP, analysis profile digest
`f3062cbed3d0b86eb009d30048874e92674d62f29bd57cc59128285964a544ca`.
Kernel-mapped addresses are preserved verbatim (__TEXT vmaddr 0xfffffe00074b6440,
__TEXT_EXEC vmaddr 0xfffffe00094cb090).

All quotes below are Ghidra decompiler output, not original source.

---

## 1. `AppleHPMInterface::isCableKartCapable()` @ 0xfffffe00094edc7c

Evidence `ev_7083f5ffe6076b6262cb20868e2c474805ff4b4b3701f530e375803373d22725`,
procedure_info `ev_7b8cd37622af5b976f89b886e24486153dbc11f92a13f68cb525818529433fc8`,
assembly `ev_cdb7eb61157b1eefd2f664f2574a027b86f1fe96bb2c00881b9b39b593bd72b1`.
1396 bytes, 59 basic blocks, body 0xfffffe00094edc7c..0xfffffe00094ee1ef.

Reads register **0x49** with length 0x40 through vtable slot +0xdf8, twice, then
polls it up to 10 times at 500 ms intervals until `reg49[0] & 7 != 0`.

Semantics recovered from assembly, not inferred from the pseudocode:

| site | meaning |
|---|---|
| `ldrb w8,[sp,#0x40]; tst w8,#0x7` | byte 0 bits 2:0 = number of valid SOP' entries |
| `ldrb w8,[sp,#0x44]; ubfx w21,w8,#0x3,#0x3` | byte 4 bits 5:3 = cable type |
| cable type 3 | "passive cable detected" |
| cable type 4 | "active cable detected" |
| `ldrb w8,[sp,#0x4d]; tst w8,#0x3` | byte 13 bits 1:0 gate a return value of 1 |
| store to `this+0x1204` | status word; ORs 0x40000 / 0x20000 / 0x10000 |

Returns 1 only when `buf[13] & 3 != 0` after a successful >=4-entry read,
otherwise 0.

It also publishes the `Kart Error Status` property and writes it to
`this+0x1204` before any register access.

### Discover-Identity emission (constant payload, confirmed in assembly)

```
0xfffffe00094ede2c: mov  w8, #0x4456
0xfffffe00094ede30: movk w8, #0x734d, LSL #16     ; 0x734D4456 -> bytes 56 44 4D 73 "VDMs"
0xfffffe00094ede34: str  w8, [sp, #0x3c]
0xfffffe00094ede38: mov  w8, #0x5
0xfffffe00094ede3c: strb w8, [sp, #0x38]          ; 0x05
0xfffffe00094ede40: mov  w8, #0x121
0xfffffe00094ede44: movk w8, #0xaca0, LSL #16     ; 0xACA00121 -> bytes 21 01 A0 AC
0xfffffe00094ede48: str  w8, [sp, #0x34]
0xfffffe00094ede64: add  x2, sp, #0x3c            ; "VDMs"
0xfffffe00094ede68: add  x3, sp, #0x34            ; 9-byte payload
0xfffffe00094ede70: mov  w1, #0x8                 ; SOP selector
0xfffffe00094ede74: mov  w4, #0x1
0xfffffe00094ede7c: blraa x8, x16                 ; vtable slot +0xb18
```

Contiguous 9-byte frame at sp+0x34:

```
21 01 A0 AC 05 56 44 4D 73      header, 0x05ACA001 (LE), "VDMs"
```

That is `header=0x21`, one payload word `0x05ACA001`, then the 4CC tag `VDMs`.
`0x05ACA001` carries Apple's USB vendor ID 0x05AC in bits 31..16 and 0xA001 in
bits 15..0. Whether 0xA001 names "Discover Identity" is INFERRED; the value is
CONFIRMED as a literal.

`this+0x1227` is set to 1 after the send, i.e. a one-shot latch that stops
repeated discovery attempts.

---

## 2. `AppleHPM::hpmIECSSendVDM()` @ 0xfffffe00095205ec

Evidence `ev_acc364c74b1209b98ec1ac9abea06f851a31ab1a2dd8028c4dfa6cd6076ef463`.
Symbol: `__ZN8AppleHPM14hpmIECSSendVDMEy15AppleHPMSOPTypeP18IOMemoryDescriptorhj`,
i.e. `hpmIECSSendVDM(unsigned long long, AppleHPMSOPType, IOMemoryDescriptor*, unsigned char, unsigned int)`.

```
if (param_4 != 0 && param_5 < 0x1d) {                    // payload length must be < 29
  auStack_78[0] = (byte)((param_3 & 3) << 4 | ((param_5 + 3 & 0xfc) >> 2));
  (*(param_4 + 0x208))(param_4, 0, (ulong)auStack_78 | 1, param_5);   // payload at +1
  uVar1 = (*(this + 0x8c0))(this, param_1, 9, auStack_78, (param_5 + 1) & 0xff, param_6);
  if ((int)uVar1 == 0)
    uVar1 = (*(this + 0x8f0))(this, param_1, 0x56444d73, param_6, 5);
}
```

Recovered frame layout:

```
byte 0 : (sop & 3) << 4 | ceil(payload_len / 4)
byte 1..N : payload, 1 <= N <= 28
          : 4CC 0x56444D73 = "VDMs"
```

- `sop` is masked to 2 bits here. `param_3 = 2` produces header 0x20, which is
  what the observed 0x21 begins with (0x20 | 1 VDO).
- The length ceiling is a hard gate: payloads of 29 bytes or more are rejected
  with `0xe00002c2` (kIOReturnBadArgument) and nothing is transmitted.
- Two separate calls: `this+0x8c0` writes the payload with the header,
  `this+0x8f0` appends the `VDMs` 4CC with argument 5.
- No caller is resolved for this function. `procedure_callers` returned an empty
  set with `relationship_coverage.status = complete`; it is reached through a
  vtable, so direct-call analysis cannot establish its callers.

---

## 3. `AppleHPMDeviceHAL::getRXSOPpData()` @ 0xfffffe000951d72c

Evidence `ev_714711d46bf049a869c768daacab8cd081166397bea99f10ec6efff737556703`.
Symbol `__ZN17AppleHPMDeviceHAL13getRXSOPpDataEP24HPMType1RXSOPandSOPpData`.

Reads register 0x49 with a 0x40-byte length (pointer at `local_71 = 0x40`), then
reconstructs a `HPMType1RXSOPandSOPpData`:

```
count = buf[0] & 7;  if (count == 7) count = 6;      // saturating, 3 bits
out+0x04 = *(u16*)(buf+1)                             // 0x05AC on this host
out+0x09 = count
out+0x24 = u16(buf+1) | byte(buf+3) << 16 | byte(buf+4) << 24
out+0x28 = buf[5..7] , buf[8]
out+0x2c = buf[12]<<24 | buf[11]<<16 | buf[10]<<8 | buf[9]
out+0x30 = buf[16..20] , buf[13..15]
out+0x38 = buf[21..24]
```

Register 0x49 therefore stores VDO words **byte-reversed** relative to the
reconstructed values. Applying the recovered formula to the live RID 5 dump
(`evidence/hpmdiagnose-raw.txt`, register 0x49):

```
buf[0]    = 0x54          -> count = 4
buf[1..2] = AC 05         -> vendor ID 0x05AC
buf[4]    = 0x1C          -> bits 5:3 = 3 = passive cable
buf[9]    = 0x00
buf[10]   = 0x32
buf[11]   = 0x00
buf[12]   = 0x78
out+0x2c  = 0x78 << 24 | 0x00 << 16 | 0x32 << 8 | 0x00 = 0x78003200
```

`0x78003200` = product ID 0x7800 in bits 31..16, bcdDevice 0x3200 in bits 15..0.
That is exactly the MagSafe 3 cable identity reported independently by IOKit
(`Product ID (SOP1) = 30720`, `Vendor ID (SOP1) = 1452`) and the reported
firmware 3.2.0 from bcdDevice 0x3200. Cross-validated, so CONFIRMED for this host.

---

## 4. `AppleHPMInterface::handleAppleUVDMEnumUpdated()` @ 0xfffffe00094f6580

Evidence `ev_ad9458449d14ee910c8017485c64674c46129cccf3d5083c89e3eacb1a898bc1`.

```
this[0x125a] += 1;                                   // SOP UVDM update counter
if ((this[0x1401] & 1) == 0 && this[0x1188] != 0) {
  publishProperty("SOP UVDM Update Count", counter);
  for (child = this[0x1188]->firstChild(); child; child = next)
    if (child->property("IOPortTransportProtocolAppleUVDM") != 0 && <gate>() == 0) {
      log("AppleHPM terminating AUVDM");
      child->terminate(0);                            // vtable +0x630
      terminated = true;
    }
  if (terminated) this[0x1188]->stop(...);            // vtable +0x5e0
}
```

This is the teardown path for the Apple UVDM transport sibling: whenever the
UVDM enumeration updates, every child carrying the
`IOPortTransportProtocolAppleUVDM` property is terminated and the parent nub is
stopped. It is the counterpart of the `hpmDisableAppleUVDMSOP` /
`hpmDisableAppleUVDMSOPp` properties emitted by `genericStart`.

---

## Corrections to earlier assumptions

- **`attachSOPpNub` is not a function.** No such symbol exists (searched
  `attach` literally; only IORegistryEntry::attachToChild / attachToParent and
  IOService::attach are present). The strings "Attaching and starting SOP" and
  "Attaching and starting SOPp" are `_os_log_fmt` payloads inside
  `AppleHPMInterface::genericStart`, which is where the sub-nub attach happens.
  The attach logic must be read out of `genericStart`, not a separate routine.
- The HPM's own firmware version and the accessory firmware version are
  different objects: `FW Version = <00153100>` on the port nub is the HPM
  controller's firmware (0x00.0x15.0x31 = 003.115.00), not the adapter's
  1030030.
