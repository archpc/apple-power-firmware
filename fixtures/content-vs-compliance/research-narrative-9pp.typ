= Executive summary
#lead[Three firmware objects share the phrase "the charger firmware" and nothing else. This report separates them on a live Apple Silicon MacBook Pro, extracts the MagSafe 3 cable's three public releases, recovers the container format from Apple's own parser, and establishes what did and did not change between them — read-only throughout.]

#verdict[The host power path, the container format and the cross-version byte facts are established. No host-observable behaviour change is demonstrated, and semantic equivalence between 3.1.12 and 3.2.0 stays `OPEN`.]

#key-findings((
  (title: "Three objects, one name", detail: [HPM controller firmware `FW003.115.00`, cable 3.2.0 (PID `0x7800`, bcdDevice `0x3200`) and adapter `1030030` are distinct. Only the first two are host-verifiable; the adapter value is reported, not read.]),
  (title: "Container recovered, not guessed", detail: [The UARP SuperBinary layout came out of Apple's own parser in `uarpd`: a 44-byte header, 40-byte payload records, and six range checks that all four acquired files pass.]),
  (title: "One literal changed", detail: [`0x05AC0002` disappears and `0x05AC0000` gains an occurrence in 3.2.0. The power-negotiation table is byte-identical in all six copies across all three builds.]),
  (title: "The dispatcher idiom moved", detail: [A 14-case `mov pc` table is present in both 3.1.x builds and absent from 3.2.0, which shows 10 detected sites of the same mechanism with different tables.]),
))

#metrics((
  ("3", "cable releases extracted"),
  ("4", "HPM controllers mapped"),
  ("38.8 %", "of image inside analysed functions"),
))

= The three objects

Calling all of this "charger firmware" is what makes the topic confusing. They are
three different processors with three different update paths.

#data-table(
  caption: [Firmware objects in the power path],
  source: [Source: IORegistry and `IOAccessoryManager` captures in `evidence/`, `hpmdiagnose` register dumps, and `AppleHPM` decompilation.],
  head: ("Object", "Identifier", "How it was read"),
  rows: (
    ("HPM controller", "`FW003.115.00`", [From the kext's own strings and register file]),
    ("MagSafe 3 cable", "3.2.0 / PID `0x7800` / `0x3200`", [Register `0x49` and the in-file version]),
    ("70 W adapter", "`1030030` / ID `0x701c`", [Host-reported only: no adapter firmware obtained]),
  ),
  widths: (1.1fr, 1.5fr, 2.4fr),
)

The distinction matters for any security claim. The host can read the cable's
version out of the negotiation it already performs; it cannot read the adapter's
flash, and nothing in the acquired data shows otherwise.

= The host power path

Four HPM instances exist: three USB-C ports at RID 0, 1, 2 and the MagSafe port at
RID 5. The charger is on RID 5, and the winning power option is 20 V at 3.390 A,
which is 67.80 W.

#note(kind: "Access", tone: "muted")[The full HPM register file is readable without root by `hpmdiagnose`; access is gated by the `com.apple.USBCEntitlement` entitlement, not by privilege. That is the practical ceiling of noninvasive inspection, and it is higher than the usual "needs root" assumption.]

What the host exposes is a contract: a set of fixed power options, one of which is
selected. That is a negotiation result, not a firmware property, and the two should
never be tabulated as the same kind of fact.

= Acquiring the firmware

Apple publishes accessory firmware under `com.apple.MobileAsset.UARP.<model>` on
`updates.cdn-apple.com`. Each download was verified against the SHA-1 Apple itself
publishes in `_Measurement`, before anything was unpacked.

#data-table(
  caption: [Acquired cable releases],
  source: [Source: `firmware/MANIFEST.txt`; SHA-1 truncated here, full values and URLs in the manifest.],
  head: ("Asset", "SHA-1 (truncated)"),
  rows: (
    ("A2363\_magsafe3\_3.1.8\_10M569.zip", [3722c634e671…]),
    ("A2363\_magsafe3\_3.1.12\_10M1543.zip", [a10fd2efd5cc…]),
    ("A2363\_magsafe3\_3.2.0\_10M13722.zip", [4db70dec4835…]),
    ("A2452\_140W\_1.4.90\_10M13554.zip", [60b42b01ce02…]),
  ),
  widths: (3fr, 1.2fr),
)

The 70 W adapter is the exception, and the negative is scoped rather than absolute:
three enumeration methods failed — `mesu` path probes, a Pallas lookup including a
deliberately fake control type, and a broad type sweep. That is evidence about
Apple's public catalogue, not proof the firmware does not exist.

= Container format

The layout was recovered from Apple's parser (`expandSuperBinaryHeader` and the
payload-header walker in `uarpd`), not inferred from hex. That distinction is why
the extraction is trustworthy: the structure is the one the host enforces.

A 44-byte header carries the payload extent; each payload is described by a 40-byte
record with 4CC-tagged TLV metadata. On all four acquired files,
`dataOffset + dataLength` equals the declared extent, and six range checks pass.

#note(kind: "Method", tone: "muted")[An earlier attempt walked the file as generic TLVs and produced a plausible, wrong structure. Recovering the parser changed the answer. Guessing a container format from byte patterns is the failure mode this step avoids.]

= Image anatomy

Each payload opens with a 384-byte `C99` wrapper, then four words: stack pointer
`0x20002000` and three pointers. In 3.2.0 the word at offset `0x04` is
`0x0001111d`, whose Thumb target `0x1111c` holds `0x4005xxxx` peripheral addresses,
so the target is constant data, not a reset handler.

The load base is `OPEN`. The 140 W control image has a similar opening, but its
pointers `0xec89` and `0xec71` exceed its own `0xea00` payload, which rules out a
base-zero mapping for that image without ruling out other bases — a base of `0x400`
would place both inside. It is not corroboration, and it is not used as any.

= What changed, and what the numbers can say

Three measurements survive scrutiny, and each is deliberately narrow.

#data-table(
  caption: [Cross-version observations],
  source: [Source: `scripts/diff_verify.py`, `scripts/dispatcher_census.py`, `scripts/coverage.py`; all re-derivable.],
  head: ("Observation", "3.1.8", "3.1.12", "3.2.0"),
  rows: (
    ("Fixed PDO table", [5/9/15/20 V @ 3 A], [same], [same]),
    ("`0x05AC0002` occurrences", [1], [1], [0]),
    ("`0x05AC0000` occurrences", [6], [6], [7]),
    ("`mov pc` dispatch sites", [14], [14], [10]),
    ("14-case table", [present], [present], [absent]),
    ("Bytes inside functions", [38.8 %], [39.4 %], [43.3 %]),
  ),
  widths: (2.2fr, 0.9fr, 0.9fr, 0.9fr),
)

Aligned 16-byte window overlap is 73.1 % between the 3.1.x pair and 5.9 % between
3.1.12 and 3.2.0. That measures byte layout, not logic: reordered functions,
moved literal pools and different register allocation all lower it with unchanged
source. Reading it as "a rewrite" was an error, and it is withdrawn.

= The three 2026 claims, examined

- **Hard-reset handling changed** — `REFUTED`. The switch that could carry such a
  claim covers message types 9 to 22, and Hard_Reset has no MessageType: it is a
  vSafe0V protocol action. A message switch cannot speak to it.
- **Soft-reset escalation** — `OPEN`. No ladder was found in any of the three
  images. Absence in the analysed 39 % is not absence in the firmware.
- **Power negotiation changed** — not supported. The PDO table is identical in all
  six copies; only its address moves, so a fixed-offset read returns garbage.

= The host stack

`uarpd` carries the message format: a six-byte header of three big-endian `u16`
fields, a vendor tag `09 BC 63` followed by a type and value, and a 39-entry opcode
table. The updater's Mode 7 address-space read exists in the binary, but reaching it
means driving the accessory into update mode — an authorised experiment, not a
routine step. Whether that verb can touch flash is `OPEN`.

= Security posture

The trust boundary that can be stated today is narrow: the host verifies the
manifest hash before applying anything, and the accessory image carries no
signature this analysis could identify. Whether a signature is enforced below that
hash, whether anti-rollback exists, and what the three 32-byte `C99` header fields
are, all remain `OPEN`. Nothing here is reported as a vulnerability.

= Limits

Coverage is 38.8 / 39.4 / 43.3 % of the images, and the paths that matter — the
control-message switch and the Apple SVID literal sites — sit outside the analysed
set. Per-function matching is not reported at all: both calibrated runs were void,
and their causes are recorded. The adapter firmware was never obtained, so adapter
behaviour is host-observed only.

= Method

Evidence came from IORegistry and `IOAccessoryManager` captures, a deterministic
`hpmdiagnose` dump, Apple's public manifests, and static analysis. One label scale
throughout: `OBSERVED`, `REPRODUCED`, `INFERRED`, `UNVERIFIED`, `REFUTED`, `OPEN`.

#note(kind: "Scope", tone: "muted")[All hardware interaction was read-only: no flashing, no update trigger, no accessory command. Proprietary images are not redistributed; hashes and acquisition notes are.]

= Appendix A — claim register

Every claim is checked across the research documents by `scripts/verify_claims.py`,
which fails on a missing statement, a conflicting label in the same paragraph, a
withdrawn phrase in a conclusion, or a broken evidence reference.

// claim: C01
- *C01* [OBSERVED] The charger negotiates 20 V at 3.390 A (67.80 W) on the MagSafe port.
// claim: C02
- *C02* [OBSERVED] Four HPM controllers are present at RID 0, 1, 2 and 5; RID 5 carries the MagSafe port.
// claim: C03
- *C03* [OBSERVED] HPM controller firmware FW003.115.00, the MagSafe cable at 3.2.0 and the adapter value 1030030 are three distinct objects, not revisions of one image.
// claim: C04
- *C04* [REPRODUCED] The UARP SuperBinary container is a 44-byte header with 40-byte payload records; dataOffset plus dataLength reconciles in all four files.
// claim: C05
- *C05* [OBSERVED] Three MagSafe 3 releases were acquired and each SHA-1 matches Apple's manifest \_Measurement.
// claim: C06
- *C06* [REPRODUCED] The power-negotiation table content (5/9/15/20 V at 3.00 A) is identical in all builds while its address moves.
// claim: C07
- *C07* [OBSERVED] Exactly one Apple SVID literal changes across the three releases: 0x05AC0002 disappears and 0x05AC0000 gains an occurrence.
// claim: C08
- *C08* [REPRODUCED] Between 3.1.12 and 3.2.0 the compared bodies share 11 non-trivial literals, lose 7 and gain 1; 28 is present only in 3.2.0.
// claim: C09
- *C09* [REFUTED] The vector word at 0x0001111d points to 0x1111c, which is constant data and not a reset handler.
// claim: C10
- *C10* [OBSERVED] The 140 W control image's pointers 0xec89 and 0xec71 exceed its 0xea00 payload, which rules out a base-zero mapping only; a non-zero base such as 0x400 would place them inside.
// claim: C11
- *C11* [REPRODUCED] The frame header formula (sop\<\<4)|ceil(bytes/4) reproduces the observed 0x21 for SOP selector 2 and a 4-byte payload; the meaning of the sop field outside the observed selector set is open.
// claim: C12
- *C12* [OBSERVED] A 14-case mov-pc dispatch table with 6 unique targets and 8 of 14 cases to one target is present in both 3.1.x builds and is not detected in 3.2.0.
// claim: C12b
- *C12b* [OPEN] The 15-case and 13-case tables in 3.2.0 are candidates only; no correspondence to the 3.1.x switch is shown.
// claim: C13
- *C13* [REFUTED] Claims that 3.2.0 replaced or reorganised the dispatcher, or is a rebuild rather than a patch, are withdrawn.
// claim: C14
- *C14* [UNVERIFIED] The Apple SVID literal sites are not established as a UVDM builder; that identification remains unverified.
// claim: C15
- *C15* [REFUTED] The 5.9 % / 73.1 % aligned-window overlap figures measure layout; the inference from them to a rewrite is refuted.
// claim: C16
- *C16* [REPRODUCED] Ghidra function coverage is 38.8 / 39.4 / 43.3 % of image bytes, and the switch and literal sites lie outside the analysed set.
// claim: C17
- *C17* [REFUTED] Hard-reset handling change is refuted: Hard\_Reset has no MessageType, so a 9-22 message-type switch cannot speak to it.
// claim: C18
- *C18* [OPEN] No soft-to-hard reset escalation ladder was found; the question stays open across all three images.
// claim: C19
- *C19* [OBSERVED] 70 W adapter firmware was not found by three enumeration methods (mesu path probes, Pallas lookup with a control type, and a broad type sweep); this is a scoped negative, not proof of nonexistence.
// claim: C20
- *C20* [OPEN] Signature enforcement below the manifest hash, anti-rollback, and whether the Mode 7 read verb can touch flash are all open.
// claim: C21
- *C21* [OBSERVED] hpmdiagnose reads the full HPM register file unprivileged; access is entitlement-gated, not root-gated.
// claim: C22
- *C22* [OPEN] Semantic equivalence of 3.2.0 to 3.1.12 is undeterminable at the achieved coverage and is open.
// claim: C23
- *C23* [OPEN] The entry-point question is OPEN: offset 0x10 is the empirical start, not a proven entry, and 0x1111c holds peripheral addresses.
// claim: C24
- *C24* [REFUTED] The 140 W control image does not corroborate a base-zero layout for the MagSafe images.
// claim: C25
- *C25* [OBSERVED] The three firmware objects are not equally established: the adapter value is host-reported only, and the cable version is a single in-file source consistent with register 0x49.
// claim: C26
- *C26* [REPRODUCED] 3.2.0 contains 10 detected mov-pc dispatch sites, not 15.
