# DISPOSITION — resolution of the independent review

`REVIEW-FABLE.md` is retained verbatim as the external audit. This file is the
author's response: every claim the review classified, and what was done about it.

Legend for **disposition**: `FIXED` (document corrected), `RELABELLED` (evidence
label or scope corrected only), `RESTATED` (claim narrowed to what the evidence
supports), `RETAINED` (review agrees; no action), `MARKED OPEN` (unsettled, now
labelled OPEN), `DISPUTED` (review finding not accepted, with reason).

## Critical and High findings

| id | finding | action | where |
|---|---|---|---|
| C1 | §4a issues a semantic verdict it says it withholds | RESTATED: §4a demoted to OPEN; "semantic difference", "logic differs", "handler changed" deleted; control-comparison and mis-pairing reasons added | DIFF §4a |
| C2 | absent table shape promoted to a source-level change | RESTATED: reduced to a detector result; "replaced by", "not attributable to the compiler", `CODE_CHANGED` removed | DIFF §4, §8 |
| H1 | constant table lists `28` as both shared and new | FIXED: sets re-extracted from pseudocode; `28` is 3.2.0-only; counts reconcile 11/7/1 plus two trivial | DIFF §4a, `scripts/literal_sets.py` |
| H2 | §4b conflates byte identity, rewrite and builder status | RESTATED: 96-byte identity kept as OBSERVED; "rewritten" withdrawn; "not in the builder" withdrawn; region no longer called a builder | DIFF §4b |
| H3 | reset target address wrong; 140 W corroboration false | FIXED: entry point reopened, `0x1111c` vs `0x111c` stated, 140 W caveat corrected to "rules out base zero only" | FIRMWARE §5 |
| H4 | UVDM "frame format" marked `CONFIRMED` and "on-wire" | RESTATED: retitled a write sequence; SOP mapping marked unresolved; "unstructured" downgraded to INFERRED | PROTOCOL §2 |
| H5 | "3.2.0 CONFIRMED, recovered twice" has one source | RESTATED: single-source statement; adapter `1030030` no longer called independently confirmed | REPORT §1 |
| H6 | regional coverage columns not comparable | FIXED: regional columns removed; only whole-image figures kept; definition stated | DIFF §3 |
| H7 | "hard-reset handling changed" from a switch that excludes hard reset | REFUTED and withdrawn: a 9–22 MessageType switch cannot address Hard_Reset | DIFF §4, §8 |

## Claim audit — all 40 reviewed claims

| # | claim | review class | disposition |
|---|---|---|---|
| 1 | charger on MagSafe port, 20 V / 3.390 A / 67.80 W | SUPPORTED | RETAINED |
| 2 | HPM `FW003.115.00` distinct from adapter firmware | SUPPORTED | RETAINED |
| 3 | cable 3.2.0 "CONFIRMED, recovered twice" | OVERSTATED | RESTATED |
| 4 | "each independently confirmed" including `1030030` | CONTRADICTORY | FIXED |
| 5 | register `0x49` map and `0x78003200` | SUPPORTED | RETAINED |
| 6 | three releases acquired, SHA-1 matches manifest | SUPPORTED | RETAINED |
| 7 | SuperBinary layout and parser checks | SUPPORTED | RETAINED |
| 8 | extraction validated, offset + length 4/4 | SUPPORTED | RETAINED |
| 9 | payload is Thumb at base 0 behind 384-byte header | OVERSTATED | RELABELLED |
| 10 | entry-point question closed, entry `0x10` | CONTRADICTORY | FIXED |
| 11 | 140 W image corroborates the MagSafe reading | CONTRADICTORY | FIXED |
| 12 | UVDM "CONFIRMED", "on-wire" | OVERSTATED | RESTATED |
| 13 | header formula gives `0x21` from argument 8 | CONTRADICTORY | FIXED |
| 14 | kernel VDM is unstructured | UNRESOLVED | MARKED OPEN |
| 15 | `isCableKartCapable` discovery sequence | SUPPORTED | RETAINED |
| 16 | UARP header 6 bytes, three BE u16 | SUPPORTED | RETAINED |
| 17 | uarpd opcode table | UNRESOLVED | MARKED OPEN |
| 18 | updater service "implements" Mode 7 / CFU | OVERSTATED | RESTATED |
| 19 | 70 W firmware "not obtainable", three ways | OVERSTATED | RESTATED |
| 20 | coverage figures; equivalence undeterminable | SUPPORTED | RETAINED |
| 21 | 14-case fingerprint present in 3.1.x, not detected in 3.2.0 | SUPPORTED | RETAINED |
| 22 | "not attributable to compiler"; `CODE_CHANGED`; "two new dispatchers" | OVERSTATED | FIXED |
| 23 | "the shared handler changed"; "semantic difference" | CONTRADICTORY | FIXED |
| 24 | constant-set comparison 11 shared / 7 lost / 1 gained | CONTRADICTORY | FIXED (H1) |
| 25 | 96-byte region byte-identical at `+0x1C0` | SUPPORTED | RELABELLED |
| 26 | `0x05AC0002` site "substantially rewritten" | OVERSTATED | RESTATED |
| 27 | change is "not in the builder itself" | CONTRADICTORY | FIXED |
| 28 | region is a "UVDM builder" | CONTRADICTORY | FIXED |
| 29 | `0x05AC0002` 1→0, `0x05AC0000` 6→7 | SUPPORTED | RETAINED |
| 30 | PDO content identical in all six copies | SUPPORTED | RETAINED |
| 31 | hard-reset handling "structure changed" | CONTRADICTORY | REFUTED |
| 32 | soft-reset escalation open | UNRESOLVED | RETAINED as OPEN |
| 33 | 3.2.0 semantically equivalent? | UNRESOLVED | RETAINED as OPEN |
| 34 | void matcher runs are not evidence | SUPPORTED | RETAINED |
| 35 | §4a pairing scores 0.713 / 0.896 | UNRESOLVED | FIXED: figures dropped |
| 36 | container "unsigned-by-structure", CONFIRMED | OVERSTATED | RESTATED |
| 37 | MagSafe power needs no authentication here | SUPPORTED | RETAINED |
| 38 | `hpmdiagnose` reads all registers without root | SUPPORTED | RETAINED |
| 39 | signature check, anti-rollback, Mode 7 flash read | UNRESOLVED | RETAINED as OPEN |
| 40 | BootKC extraction byte-identical for four sections | SUPPORTED | RETAINED |

## Medium and Low items

| item | action |
|---|---|
| M1 script-to-output mapping undocumented; `match2.json` unaccounted | DIFF §10 lists every failure and its cause; scripts are checked in |
| M2 verdict vocabulary (`RELOCATED`/`RECOMPILED`/`CODE_CHANGED`) misused | vocabulary removed from verdicts; observational wording used instead |
| M3 "exactly one" / "semantic level" overstated | narrowed to "one literal changes; meaning OPEN" |
| M6 70 W negative rests on a shared model assumption | stated as an assumption in the acquisition notes |
| M7 manifest provenance: two of three are archive copies | stated explicitly in FIRMWARE §1 and README |
| M8 UARP field names inferred; Mode 7 from strings only | labelled INFERRED / OBSERVED-strings |
| M9 no single label scale | six-label scale defined in README and applied to all research docs |
| §11 truncated sentence; §5 "eight other cases"; section numbering | corrected |

## Review findings not accepted

None. Every Critical and High finding was either fixed or restated, and two of
the author's own claims were refuted by the review's arithmetic (H1, H3) and
corrected with re-derived numbers rather than re-worded prose.

## Effect on conclusions

The review did not overturn any surviving conclusion, because after correction
there are few: the host power path, the container format, the PDO table identity,
the literal counts, and the dispatcher census. Everything about what changed
between 3.1.12 and 3.2.0 is OPEN, and the documents now say so in one voice.
