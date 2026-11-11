# OPEN — unresolved questions and what would settle them

Ordered by value per unit of cost. Nothing here is authorized by this document.

## Static, no hardware

1. **Decompile the `0x43` and `0x47` readers in AppleHPM.** The same method that
   recovered `getRXSOPpData` for `0x49` should settle whether `0x43` byte 0 is a
   count, what the 26-byte trailing fields are, and whether `0x47` is a
   transmit payload. Cheap and decisive; not done here. Falsifier for the
   current reading: a reader that indexes different offsets.
2. **`PortControllerCapMismatch` semantics.** The property is 0 while the RDO
   sets Capability Mismatch. Re-read it while a CM-set RDO is active, and look
   for the counter or latch that feeds it.
3. **`FwVersion` decomposition.** `"01030030"` against the updater's
   `fw=1.3.30`. One firmware string, two renderings, no established mapping.
   A second adapter with a different firmware would discriminate.
4. **`0x48` and `0x4f` framing.** Both are volatile windows. A capture set with
   several known attachments (cable-only, adapter-only, phone) would show which
   fields track the partner and which are scratch.

## Needs a decision or privilege

5. **Supported-accessory table.** `A2743` is a CoreUARP literal, so the model is
   known, but the table path is unconfirmed (`uarpAccessories.plist` returned
   ENOENT) and `/var/db/accessoryupdater` is unreadable without root. Blocked by
   privilege; reading it would need explicit approval and root.
6. **CFUa read outside the known pages.** The primitive is ungated host-side but
   reachable only through `accessoryupdaterd`, which rejects clients without the
   Apple-private `com.apple.accessoryupdater.uarp` entitlement. Page 27 is
   already read on connect (cable 6, adapter unknown), so the open question is
   whether any page maps flash. Blocked by entitlement before policy; would need
   an Apple-signed caller and explicit approval, on a spare unit.

## Needs hardware or a second unit

7. **PD protocol-analyzer capture on the CC pair.** Would confirm the RDO flags
   on the wire and whether `0x47` is transmitted at all. Requires a tap that does
   not disturb the MagSafe connector.
8. **A second A2743 with different firmware**, to separate constants from
   version-dependent fields and to settle item 3.

## Single-source claims to keep labelled

9. **Controller `CYPDC1185B2` / CCG3PA2** rests on one teardown publisher.
   A second teardown or a regulatory photo set would upgrade it.
10. **A3543's PID `0x7026`** comes from a public readout, not from this host.
11. **Exact controller order code** (`-32D` as printed is not a valid code).

## Explicitly not pursued

- Opening the mains-powered adapter.
- Flashing, downgrading, or triggering an update.
- Any authenticated Apple endpoint.
