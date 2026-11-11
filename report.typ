= Executive summary
#lead[Read-only investigation of the power path on an Apple Silicon MacBook Pro: the USB-C PD controllers, the MagSafe 3 cable, and the host update stack. Three firmware objects are involved and are routinely conflated; they were separated, and the cable's three public releases were extracted and compared at byte and function level.]

#verdict[The host power path, the UARP container format and the cross-version byte facts are established. No host-observable behavioural difference between cable releases is demonstrated, and semantic equivalence remains `OPEN`.]

#key-findings((
  (title: "C01 — observed", detail: [The charger negotiates 20 V at 3.390 A (67.80 W) on the MagSafe port.]), (title: "C04 — reproduced", detail: [The UARP SuperBinary container is a 44-byte header with 40-byte payload records; dataOffset plus dataLength reconciles i]), (title: "C06 — reproduced", detail: [The power-negotiation table content (5/9/15/20 V at 3.00 A) is identical in all builds while its address moves.]), (title: "C12 — observed", detail: [A 14-case mov-pc dispatch table with 6 unique targets and 8 of 14 cases to one target is present in both 3.1.x builds an]),
))

#metrics((
  ("23", "claims reconciled"), ("9", "mandatory regressions"), ("0", "unresolved contradictions"),
))

= Method

Evidence came from IORegistry and IOAccessoryManager captures, a deterministic `hpmdiagnose` register dump, Apple's own public firmware manifests, and static analysis of the extracted images. Labels are one scale: `OBSERVED`, `REPRODUCED`, `INFERRED`, `UNVERIFIED`, `REFUTED`, `OPEN`.

#note(kind: "Scope", tone: "muted")[All hardware interaction was read-only. No firmware was flashed, no update was triggered, no accessory command was sent. Proprietary images are not redistributed with this report; hashes and acquisition notes are.]

= Claim register
Every claim below is checked across all eleven research documents by `scripts/verify_claims.py`, which fails on a missing statement, a conflicting label in the same paragraph, a withdrawn phrase in a conclusion, or a broken evidence reference.

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

= Corrections

The independent audit found arithmetic and labelling errors; each is corrected at the data level, not re-worded.

#data-table(
  caption: [Corrected and withdrawn claims],
  source: [Source: `DIFF.md` §1 and §4a, `DISPOSITION.md`; each row re-derived from the extracted images or the pseudocode.],
  head: ("Claim", "Status", "Corrected statement"),
  rows: (
    ("C06", [REPRODUCED], [The power-negotiation table content (5/9/15/20 V at 3.00 A) is identical in all builds while its address moves.]),
    ("C08", [REPRODUCED], [Between 3.1.12 and 3.2.0 the compared bodies share 11 non-trivial literals, lose 7 and gain 1; 28 is present only in 3.2.0.]),
    ("C09", [REFUTED], [The vector word at 0x0001111d points to 0x1111c, which is constant data and not a reset handler.]),
    ("C10", [OBSERVED], [The 140 W control image's pointers 0xec89 and 0xec71 exceed its 0xea00 payload, which rules out a base-zero mapping only; a non-zero base such as 0x40]),
    ("C13", [REFUTED], [Claims that 3.2.0 replaced or reorganised the dispatcher, or is a rebuild rather than a patch, are withdrawn.]),
    ("C15", [REFUTED], [The 5.9 % / 73.1 % aligned-window overlap figures measure layout; the inference from them to a rewrite is refuted.]),
    ("C16", [REPRODUCED], [Ghidra function coverage is 38.8 / 39.4 / 43.3 % of image bytes, and the switch and literal sites lie outside the analysed set.]),
    ("C17", [REFUTED], [Hard-reset handling change is refuted: Hard\_Reset has no MessageType, so a 9-22 message-type switch cannot speak to it.]),
  ),
  widths: (0.7fr, 0.9fr, 3.4fr),
)

= Limitations

- Function coverage is 38.8 / 39.4 / 43.3 % of the three images, and the control-message switch and Apple SVID literal sites sit outside the analysed set.
- Per-function matching is not reported: both calibrated runs were void, and the causes are recorded rather than hidden.
- The 70 W adapter firmware is not publicly obtainable, so adapter behaviour is host-observed only.
- The load base for the accessory images, the C99 header fields, and any signature or anti-rollback enforcement below the manifest hash are `OPEN`.

The unproven remainder is stated as scope, never as equivalence.
