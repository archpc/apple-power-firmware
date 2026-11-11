# PROTOCOL — USB-PD and the Apple UVDM transport

Split deliberately into what was read out of code or registers (OBSERVED) and
what is inference from naming or structure (INFERRED). Nothing here was probed
by sending traffic to a device.

---

## 1. Layers actually present on the MagSafe port

```
MagSafe 3 connector
  └── CC (USB-PD, BMC)            TransportsActive = ("CC")
        ├── SOP   : power source (the adapter, 70 W)
        ├── SOP'  : cable / connector (PID 0x7800, bcdDevice 0x3200)
        └── SOP'' : not observed
  └── no USB2 / USB3 / DisplayPort on this port
```

`TransportsSupported = ()` with `TransportsActive = ("CC")` on
`Port-MagSafe 3@1`: the MagSafe port carries only configuration-channel traffic.
Any update transport must therefore ride on USB-PD itself.

## 2. Apple UVDM frame format (OBSERVED)

Recovered from `AppleHPM::hpmIECSSendVDM` at 0xfffffe00095205ec. This is Apple's
own unstructured-VDM framing, not the USB-PD 3.x UVDM header layout.

```
offset 0       1 byte    header = (sop & 3) << 4 | ceil(payload_len / 4)
offset 1..N    N bytes   payload, 1 <= N <= 28
offset N+1..N+4 4 bytes  4CC 0x56444D73 = "VDMs"
```

Rules read straight from the instruction stream:

- `payload_len` is rejected when `>= 0x1D` (29). Maximum payload is 28 bytes.
  The failure path returns `0xe00002c2` = `kIOReturnBadArgument` before any
  descriptor copy, so an oversized request never reaches the controller.
- The header packs the SOP selector in bits 5:4 and the VDO count in bits 3:0.
  Bits 7:6 are unused by this path.
- The payload is copied into a stack buffer one byte past the header byte, and
  the transfer length is `payload_len + 1`.
- The `VDMs` 4CC is appended by a **separate** call
  (vtable +0x8f0) with argument 5, after the payload write
  (vtable +0x8c0) succeeds. Two calls, one logical frame.
- A lock on `this+0x98` is held across the whole sequence, so frames are
  serialised per controller.

### Observed constant frame

`AppleHPMInterface::isCableKartCapable` emits, byte for byte:

```
21 | 01 A0 AC 05 | 56 44 4D 73
     ^^^^^^^^^^^   "VDMs"
     payload word 0x05ACA001 little-endian
```

- header 0x21 = SOP selector 2, VDO count 1 — matches `(sop=2)<<4 | ceil(4/4)`.
- payload `0x05ACA001` = Apple USB vendor ID `0x05AC` in bits 31..16, `0xA001`
  in bits 15..0.
- `0xA001` as a command/opcode name is INFERRED. The bytes are OBSERVED; the
  semantic label is not.

The formula reproduces the observed byte exactly: with SOP selector 2 and a
4-byte payload, `(2 << 4) | ceil(4/4)` = `0x21`. **REPRODUCED** for that datum,
checked by `scripts/regress_release.py` case R4.

An earlier revision claimed an inconsistency — that applying the formula to the
literal `8` yields `0x01` and therefore only `0x21` was trusted. That was my own
argument-substitution error: `8` is the payload bit count, not the SOP selector.
With the selector and length in their correct roles the arithmetic closes, so the
retraction stands and the formula is no longer marked unresolved. What remains
**OPEN** is whether the `sop & 3` field means what its name suggests for values
outside the observed selector set; one datum cannot settle the general mapping.

## 3. Discovery and capability state machine (OBSERVED, host side)

From `AppleHPMInterface::isCableKartCapable`:

1. Read the `Kart Error Status` property; publish it to status word
   `this+0x1204`.
2. Read register 0x49 (0x40 bytes) twice in a row. Both reads must succeed.
3. If `reg49[0] & 7 == 0` **and** neither `this[0x1227] & 1` (already
   discovered) nor `this[0x13b8] & 8` is set, emit the Discover-Identity UVDM
   above and set `this[0x1227] = 1`.
4. Poll register 0x49 up to 10 times, 500 ms apart, waiting for
   `reg49[0] & 7 != 0`. Total bounded wait 5 s.
5. On success, classify from `reg49[4]` bits 5:3: 3 = passive cable,
   4 = active cable; anything else falls through.
6. Return 1 only if `reg49[13] & 3 != 0`; otherwise set bits in the status word
   (0x40000 when a role mismatch forced discovery, 0x20000 for an unknown
   cable type, 0x10000 for the no-capability case) and return 0.

States worth noting:

- The discovery send is one-shot per controller due to the `this+0x1227` latch.
  A failed discovery is not retried until that flag clears.
- Register reads happen before and after the send; there is no ACK-driven state
  machine visible at this level. The 500 ms x 10 poll is the entire timeout
  model.
- `CableKartCapable` and `DeviceKartCapable` are separate predicates;
  `DeviceKartCapable` was not decompiled.

## 4. UVDM teardown path (OBSERVED)

`AppleHPMInterface::handleAppleUVDMEnumUpdated`:

1. Increments a per-interface counter and publishes it as
   `SOP UVDM Update Count`.
2. Walks children of `this+0x1188` looking for a child carrying the
   `IOPortTransportProtocolAppleUVDM` property.
3. Terminates every such child (vtable +0x630) and, if anything was terminated,
   stops the parent nub (vtable +0x5e0).

So the Apple UVDM transport is a **child nub** of the port interface, created
and destroyed dynamically. Its existence is the observable signal that the host
has an active UVDM channel to the accessory.

Related properties published by `AppleHPMInterface::genericStart`:
`hpmDisableAppleUVDMSOP`, `hpmDisableAppleUVDMSOPp` — per-SOP switches that
suppress publishing the SOP and SOP' UVDM nubs.

## 5. Power negotiation (OBSERVED, observed)

Advertised and selected fixed PDOs on the MagSafe port:

| voltage | current | power |
|---|---|---|
| 5 V | 2.960 A | 14.80 W |
| 9 V | 2.970 A | 26.73 W |
| 15 V | 2.980 A | 44.70 W |
| 20 V | 3.390 A | 67.80 W ← selected |

Separate `Brick ID` source at 5 V / 0.5 A / 2.5 W, priority
18446744073709551116, owned by `AppleSMCChargerUtil`. This is a distinct
low-power channel used before the main contract.

The contract is negotiated by the HPM and reported through IOKit. No
`Request`/`Accept` message contents are observable from userland on this host;
only the resulting contract.

## 7. UARP message header on the host stack (OBSERVED)

From `uarpd` message builder `FUN_1000400e4` (uarpd arm64e slice, sha256
`33a9fb5c...f298c7f`), decompiled directly:

```
puVar4 = (u16 *)puVar6[3];              // message buffer
*puVar4     = htons(messageType);       // +0
puVar4[1]   = payloadLength;            // intermediate
*(u16*)(buf + 2) = htons(payloadLength);// +2, payloadLength = totalLen - 6
*(u16*)(buf + 4) = 0;                   // +4, protocolVersion written as 0
```

Header is 6 bytes, three big-endian u16:

| off | field |
|---|---|
| +0 | messageType |
| +2 | payloadLength = totalLength − 6 |
| +4 | protocolVersion, written 0 by this builder |

The same function stores a monotonically incrementing sequence byte at buffer
offset `0x27` (`*(param_2 + 0x12) + 1`, or 1 for the first message), and copies
a u16 from `param_2 + 0x10` to buffer offset `0x28`. Those are the sequence and
window/ID fields that sit outside the 6-byte header described above; their exact
placement relative to the TLV payload is not yet mapped.

Correction to a prior subagent report: the builder writes `htons(messageType)`
and then `htons(totalLen-6)` at offset **2**, not at offset 0 and 2 as two
independent stores with the first overwritten. Net layout is the same; the
intermediate store is a decompiler artifact.

## 8. UARP opcode table — reported, not independently verified

A subagent reported a 39-entry jump table at uarpd `0x10003e334` (base
`0x10003c8d0`), indices 0x00–0x26, with `0xFFFF` handled separately as Vendor
Specific, and named the message types in order from `__cstring` at `0x1000dad0a`
(Sync, Version Discovery Req/Resp, Information Req/Resp, Asset Available
Notification, Data Req/Resp, Asset Data Transfer Notification, Asset Processing
Notification, Apply Staged Assets Req/Resp, Asset Rescinded Notification, four
Acks, Dynamic Asset Solicitation, PreProcessing, Downstream Endpoint
Discovery/Reachable/Unreachable/Message, No Firmware Update Available, Endpoint
Discovery Req/Resp, Component Discovery Req/Resp, Bulk Information Req/Ack/Resp).

I did **not** re-derive that table. Treat the opcode numbering as UNVERIFIED
until the jump table is read directly. What I did verify independently is that
uarpd builds paired request/response messages (case N building N+1) and that the
Apple vendor-specific payload carries a 3-byte tag `0x09 0xBC 0x63` followed by
a big-endian u16 type — also reported by the subagent, also not re-derived here.

## 9. Accessory transport: UARP over USB-PD, Accessory Mode 7, CFU

Two distinct USB-PD mechanisms exist in this stack, and they are not the same
thing:

1. **Kernel-side, unstructured VDM.** `AppleHPM::hpmIECSSendVDM` builds
   `[hdr][payload][4CC "VDMs"]` (sections 2–3 above). This is what the HPM uses
   for cable discovery and identity.
2. **Host-side, updater service.** `UARPUpdaterServiceUSBPD.xpc` implements the
   accessory update path. Verified present at
   `/System/Library/PrivateFrameworks/MobileAccessoryUpdater.framework/XPCServices/UARPUpdaterServiceUSBPD.xpc`,
   executable 3,721,808 bytes, `CFBundleIdentifier com.apple.UARPUpdaterServiceUSBPD`,
   `"UARP Updater" = true`.

Binary strings in that service, read directly (OBSERVED present):

```
%@ %d bytes on SOP %d for %@
, MagSafe = <%d>
, SOP Type = <%d>
, SOP Prime Delegate = <%@>
processAppleVDO:   processCapabilityVDO:   processEndpointVDO:
Enabled CFUp / Disabled CFUp      iecsCommand(CFUp)
CFUa read failed / CFUa write failed / CFUs write failed
kAccMode7FirmwareCommandStart / Manifest / Apply / Reset
kAccMode7Mode7FirmwareUpdateControl
```

Objective-C classes in that binary (OBSERVED, 12 classes):

```
UARPUSBPDAccessory (108)  UARPUSBPDUpdater (82)  UARPMagSafeCable (91)
UARPPowerAdapter (63)      UARPAppleHPM (79)      VUARPAccessory (33) ...
```

Plus an `UARPAppleHPM(AccMode7)` category with
`accMode7AddressSpaceRead:buffer:bufferLength:lengthRead:error:`,
`accMode7AddressSpaceWrite:...`, `accMode7SolicitLogs:modelName:serialNumber:error:`,
`accMode7StagedFwVersion:`, `accMode7FirmwareHasStagedAssets:`.

So the shipping design is: parse Discover-Identity VDOs (`processAppleVDO`,
`processCapabilityVDO`, `processEndpointVDO`), then enter Apple Accessory Mode 7
and drive the accessory with CFU commands (`CFUp` enable, `CFUa` address-space
access, `CFUs` status). The cable and the wall adapter are separate classes
(`UARPMagSafeCable`, `UARPPowerAdapter`), matching the API-level split.

Discrepancy to leave open: the subagent described the transport as
**structured** VDMs on SOP/SOP′; the kernel code I decompiled uses an
**unstructured** VDM with a `VDMs` 4CC. Both can be true — discovery may use one
form and the update channel the other — but this report does not prove which
form carries UARP TLVs. That is the single most important open protocol
question and is listed in `NEXT.md`.

Also note: `uarpd` itself contains no USB-PD, UCSI, UVDM or SVID code. Transport
is abstracted behind `UARPEndpointTransportTxProtocol`/`RxProtocol`; the USB-PD
binding lives in the updater service, not the daemon. A subagent's earlier
"no USB-PD code in uarpd" negative is correct and is not evidence of absence
elsewhere.

## 10. What is NOT established

- No UARP-over-USB-PD frame was observed on the wire. The kernel side shows a
  UVDM channel and a `VDMs` 4CC; it does not show UARP TLVs riding on it.
  Any claim that UARP uses this exact frame is INFERRED from the coexistence of
  `IOPortTransportProtocolAppleUVDM` and the host-side UARP stack, not proven.
- Message-ID / sequence handling, retry and error codes below the `VDMs` frame
  were not recovered. `setRxMIDBSOPStar` / `getRxMIDBSOPStar` exist
  (`AppleHPMDeviceHAL`), which implies a receive MIDB per SOP', but its use was
  not traced.
- `AppleHPMSOPType` numeric values beyond the observed `2` in the header and the
  literal `8` passed by the caller.
- `hpmIECSSendVDM` has no statically resolved callers; it is reached through a
  vtable, so its full call graph is unknown.
- The 4CC `VDMs` is written with argument 5 by vtable +0x8f0; whether that
  argument is a channel, a length or a flag is unresolved.
