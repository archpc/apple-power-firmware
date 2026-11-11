# SECURITY — trust model and attack surface

Scope note: this is an observation report, not a vulnerability assessment. No
payload was sent to any accessory, no update was triggered, no fault was
injected. Anything labelled UNVERIFIED is a hypothesis with a stated test.

---

## 1. Update trust model, as observed

Layers, outermost first:

| layer | mechanism | status |
|---|---|---|
| 1 | asset delivery over HTTPS from `updates.cdn-apple.com` | OBSERVED |
| 2 | asset authenticity: SHA-1 `_Measurement` in Apple's signed MobileAsset manifest | OBSERVED — all four acquired files match |
| 3 | inner bundle signature: `_CodeSignature/CodeResources` inside `Firmware.acsw` | OBSERVED present |
| 4 | container: UARP SuperBinary, self-describing, no signature field recovered | OBSERVED absence of a signature field in the recovered layout |
| 5 | accessory-side acceptance: whether the cable verifies anything before applying | UNVERIFIED |

Layer 2 is the load-bearing one we can actually check: the SHA-1 recorded in
Apple's own manifest equals `sha1(payload zip)` for all four files. That binds a
downloaded image to Apple's manifest, and the manifest is fetched over TLS from
Apple. It does **not** bind the image to the accessory — the accessory has to do
that itself, and we have not established how.

Layer 3 is a bundle-level integrity manifest. It covers the `.uarp` file inside
the `.acsw` bundle; it is a codesign resource envelope, not an accessory
signature.

Layer 4: the recovered SuperBinary layout (see `FIRMWARE.md` §2) has no
signature or certificate TLV. The only unexplained fields are two 4-byte TLVs
(`0xccd28103`, `0x00000003`) and an opaque 384-byte `C99` inner header. So
whatever authenticity the accessory enforces is **not** in the container
structure we recovered. This is a real negative result: the shipped asset is not
an IMG4/IM4P-signed image.

Hypothesis (UNVERIFIED): authority is transferred at the protocol layer, i.e.
the accessory only accepts a flash write while it is in Accessory Mode 7 having
been driven through `kAccMode7FirmwareCommandManifest` by a host that the
accessory has authenticated, or the accessory verifies a signature carried
inside the `C99` header's 32-byte fields. Both are testable; see `NEXT.md`.

## 2. Authentication state on the live cable

From IOKit on the MagSafe port (`Port-MagSafe 3@1`):

```
AuthenticationRequired = No
AuthenticationStatus   = 0   ("Idle")
AuthorizationRequired  = No
AuthorizationStatus    = 0   ("Not Required")
HPDAsserted            = No
```

OBSERVED: power delivery over MagSafe 3 on this machine does not require the
cable to authenticate, and no authentication occurred during the session.

That is a statement about **power**, not about firmware update. The presence of
`challengeCrypto` in AppleHPM (see below) means an authentication path exists in
the stack; it simply was not exercised for this cable and port.

## 3. Crypto surface in the kernel driver

`AppleHPMInterface::challengeCrypto` is present and logs:

```
Start hpmv1 = 0x%x
Starting HPMV2 execution
HPMV2 buffer[0] = 0x%08x
Warning: truncating input, length is too long
Warning: CRYm returned !CMD, aborting
CRYm exeucted and took ~%u ms
```

OBSERVED (strings + call sites in `evidence/applehpm-strings.txt`): there are
two protocol generations, HPMV1 and HPMV2, driven through a `CRYm` mailbox
command executed by the controller hardware, with a timing measurement. The
crypto itself runs on the HPM, not on the host CPU.

Not recovered: the challenge/response sizes, the key schedule, whether the
result is verified on the host, and what it gates. Multiple call sites exist
(17 log anchors), so it is not a single-purpose routine.

## 4. Access control on the diagnostic surface

`/usr/bin/hpmdiagnose` performs a full read of every HPM register file **without
root**. It is not a privilege bug: the binary is platform-signed
(`Platform identifier=27`) and carries

```
com.apple.USBCEntitlement = true
com.apple.security.iokit-user-client-class = AppleHPMUserClient
```

OBSERVED via `codesign -d --entitlements`. `AppleHPMUserClient` is gated by
`com.apple.USBCEntitlement`, which third-party software cannot obtain. So:

- The capability is broad (whole register file, all four controllers).
- The gate is code-signing identity, not uid. Running as root without the
  entitlement would not be enough; running as a normal user with an Apple-signed
  binary is.
- Consequence for this project: readback we already have is the *maximum*
  unprivileged visibility, and it is only available through Apple's own tool.

## 5. Readback feasibility — the concrete answer

Three distinct readback questions, three different answers:

1. **Register readback (host controllers).** Available today, unprivileged,
   through `/usr/bin/hpmdiagnose`. OBSERVED and already captured. This gives
   HPM firmware identity, cable/adapter identity, PDO state, and ~114 registers
   per controller.
2. **Accessory firmware readback (the cable / the brick).** No public tool, no
   public protocol documentation, and no unprivileged path. However the host
   service `UARPUpdaterServiceUSBPD` contains
   `-[UARPAppleHPM(AccMode7) accMode7AddressSpaceRead:buffer:bufferLength:lengthRead:error:]`
   alongside `accMode7AddressSpaceWrite:`. OBSERVED that a read primitive
   exists in Apple's own code at the protocol layer. Whether the accessory's
   Accessory Mode 7 command set honours a read for its own flash is UNVERIFIED.
   This is the single most promising noninvasive avenue and it requires an
   explicitly authorized experiment, because reaching it means driving the
   accessory into a mode the user's rules treat as an update path.
3. **Passive USB-PD capture.** Requires external hardware on the CC line. No
   software-only path exists on this host; there is no PD analyzer interface
   exposed. Not attempted.

What is explicitly *not* implied: the presence of an update protocol does not
imply readback. A CFU-style protocol can offer write-only staging with no
read-back of the running image. The existence of `accMode7AddressSpaceRead` in
the host is evidence the protocol has an address-space read verb; it is not
evidence the accessory authorizes it for flash.

## 6. Update path and where it actually runs

Two unrelated update paths exist and are easy to conflate:

- **`/usr/libexec/usbcupdater`** does **not** update adapters or cables. It
  emits a `BlessArguments` plist that boot-time `FirmwareUpdateLauncher`
  consumes to run `HPMUtil.efi` / `ThorUtil.efi` under EFI, flashing the Mac's
  own USB-C port-controller firmware. CLI: `-v`, `-p <payload>`, `-X`
  (preflight), `-s` (subupdater), `-b` (bypass version); boot-args
  `usbcupdater_bypass_usbc_updates`, `usbcupdater_bypassversioncheck`.
  Reported by subagent, spot-checked against strings.
- **`UARPUpdaterServiceUSBPD.xpc`** is the adapter/cable path: USB-PD VDO
  discovery, Accessory Mode 7, CFU commands.

Conflating these two is the most likely source of a wrong conclusion about
"adapter firmware update", so they are kept separate everywhere in this report.

## 7. Downgrade / anti-rollback

Not established. What exists:

- The container carries an explicit version quadruple in two places (header and
  payload record), and Apple's parser rejects a mismatch in structure but not a
  version regression.
- `uarpd` exposes `UARPSuperBinaryLayer3` properties including `assetVersion`,
  and `UARPAssetSubscription` selection by max version (`assetWithMaxVersion` in
  `uarpassetmanagerd`) — that is *selection* preference, not enforcement.
- No monotonic counter, no nonce, no "minimum version" constant was recovered
  from either side.

A regression test would need to offer 3.1.8 to a device running 3.2.0. That is a
downgrade attempt, which the operating rules prohibit. It stays UNVERIFIED and
is listed as blocked in `NEXT.md`.

## 8. Verified findings, ranked by confidence

1. OBSERVED — the accessory firmware container is an unsigned-by-structure
   SuperBinary; the only authenticity binding we can verify is the SHA-1 in
   Apple's manifest.
2. OBSERVED — MagSafe 3 power delivery requires no authentication on this host.
3. OBSERVED — HPM register readback is available unprivileged but only through
   an Apple-signed, entitlement-gated binary.
4. OBSERVED — the host updater service contains an address-space read verb for
   the accessory protocol.
5. OBSERVED — the MagSafe payload is wrapped in an additional 384-byte `C99`
   header that the 140 W adapter image does not use, so the two devices do not
   share an update container format at the payload level.
6. UNVERIFIED — that the accessory verifies any signature at all before applying.
7. UNVERIFIED — that `accMode7AddressSpaceRead` can read accessory flash.
8. UNVERIFIED — any anti-rollback behaviour.

## 9. Explicit non-claims

No vulnerability is claimed. Nothing here should be read as "the update path is
unsigned" — only that the container format we recovered carries no signature and
that the enforcement point has not been located. The absence of evidence in the
files we analysed is not evidence of absence in the accessory's own firmware,
which we could not obtain for the adapter and have not yet analysed for the
cable.
