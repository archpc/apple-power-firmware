# NEXT — prioritized experiments, blockers, equipment

Ordered by value per unit of risk. Nothing here is authorized by this report;
each item needs its own go-ahead. Items 1–3 need no new hardware.

---

## Tier 1 — finish the static analysis already in progress

**1. Complete the MagSafe firmware function diff (3.1.8 / 3.1.12 / 3.2.0).**
Owner: in flight. Needs the Ghidra function inventory and cross-version match.
Blocks `DIFF.md`. Success = a table of functions that changed between 3.1.12 and
3.2.0 with addresses, sizes, and a stated behavioural inference for the largest
changes. No hardware, no risk.

**2. Resolve the reset-handler question.** The 3.2.0 reset vector is
`0x0001111d`; code exists at image offset `0x111c` and also at `0x10`
(unambiguous startup). Determine which is the true entry by following the
function graph, i.e. find who calls `0x10` and whether `0x111c` is entered only
via the vector. Cheap, static, resolves an ambiguity currently marked open.

**3. Read the uarpd opcode jump table directly.** Currently UNVERIFIED at second
hand. Read the 39-entry table at `0x10003e334` (base `0x10003c8d0`) and the
33-entry vendor-TLV table at `0x10003e5b4`, map indices to the `__cstring`
names, and publish the enumerated list. This is the difference between "a
subagent says there are 39 opcodes" and a citable table.

**4. Map the `C99` inner header.** 384 bytes, three 32-byte opaque fields, one
length-like field at `0x100`, a constant 1152 at `0x10c`, and a 4-byte trailer at
`0x17c`. Candidate meanings: per-section hashes, a nonce, a key handle, a
signature over the image. Test: compute SHA-256 / SHA-1 / CRC-32 over candidate
sub-ranges (whole image, code-only up to the `0x100` length, per-section) and
compare against each 32-byte field. If a match appears, that field is a hash and
the integrity story becomes concrete. Pure offline work.

**5. Settle the VDM form question.** Kernel uses unstructured VDM with a `VDMs`
4CC; the updater service mentions SOP/SOP′ and VDO parsing. Determine from
`UARPUpdaterServiceUSBPD` which form carries UARP TLVs by reading
`-[UARPAppleHPM iecsCommand:]` and the `CFUp`/`CFUa` call path. Static only.
This is the highest-value protocol question outstanding.

## Tier 2 — needs explicit authorization, still noninvasive

**6. Ask the accessory for its version through Accessory Mode 7.** The host
service has `accMode7StagedFwVersion:` and `accMode7AddressSpaceRead:`. A single
read of the version/identity address space is non-destructive in principle, but
it requires driving the accessory into a firmware-update mode, which the current
operating rules treat as an update path. Requires: explicit approval, a written
command sequence, and a rollback story. Highest information gain of anything
remaining; do not attempt unilaterally.

**7. Passive CC-line capture.** A USB-PD analyzer (e.g. a Total Phase
Advanced USB Power Delivery Analyzer, or a Twinkie-based sniffer) on the MagSafe
CC pair would turn every "INFERRED" in `PROTOCOL.md` into observed traffic:
actual discover-identity VDOs, actual VDM headers, and whether the `VDMs` 4CC
appears on the wire at all. Requires hardware purchase and a breakout that does
not disturb the MagSafe connector. Not attempted; no software path exists.

## Tier 3 — blocked on things we cannot get

**8. 70 W adapter firmware.** Blocked hard. Apple's Pallas registry has no
`UARP.A2743` asset type, and `mesu` has no manifest. Further URL guessing is
wasted effort; the answer is that this asset is not distributed publicly. If the
adapter is updatable at all, the payload is either bundled inside a macOS
update or fetched through an authenticated path we have not identified. Adapter
analysis therefore has to proceed from host-side observation only.

**9. Anti-rollback behaviour.** Blocked by policy: testing it means offering
3.1.8 to a 3.2.0 device. Would need an explicit exception and a recovery plan
(and there is no public recovery image for a bricked cable).

**10. Adapter-side MCU architecture.** The 140 W `BRCK` image shows the same
Cortex-M shape (`SP=0x20002000`), but it is a different product. Nothing about
the 70 W adapter's MCU can be concluded from it.

## Equipment that would change the answers

| item | unlocks |
|---|---|
| USB-PD protocol analyzer with CC tap | real VDM/UVDM capture, replaces inference |
| USB-C breakout + scope | PD BMC waveform, reset pulse timing |
| second MagSafe 3 cable (spare) | any experiment with brick risk |
| spare 70 W adapter | same |

## Unresolved questions, stated plainly

- Which VDM form carries UARP TLVs over this link.
- Whether the accessory verifies a signature, and where the key lives.
- What the three 32-byte `C99` header fields are.
- What TLV `0xccd28103` and `0x00000003` mean.
- Whether `accMode7AddressSpaceRead` can read accessory flash.
- Whether any anti-rollback exists on either the cable or the adapter.
- Register `0x47` field layout (host side, low priority, cosmetic).
