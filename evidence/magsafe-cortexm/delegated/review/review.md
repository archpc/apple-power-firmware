# Review — independent audit of delegated MagSafe Cortex-M work

Scope: DIFF.md §11 and `delegated/{execmodel,protocol,xversion}.md`.
Method: independent verification first (`audit-log.md`, written before the
documents were opened), then comparison. Nothing outside `review/` was modified.

Artifacts here:
- `audit-log.md` — raw Phase-1 observations, step by step (hashes, clean imports,
  seeded runs, rizin decodes, xref scans, decompiler spot checks).
- `findings.md` — consolidated PASS / FAIL / OPEN verdict table with offsets and
  reproducible commands.
- `inventory3_318_audit.json`, `decomp3_318_audit/` — my 3.1.8 run (444 fns).
- `inventory3_3112_audit.json`, `decomp3_3112_audit/` — my 3.1.12 run (436 fns).
- `match_result_audit.json` — rerun of `xversion/match.py` on current inputs.

Headline:
- 20 of 23 audited claims PASS; the execution model, seed hygiene (no data
  forced to code), dispatcher structure, table boundaries and dead-island
  conclusion all reproduce exactly from clean imports.
- FAIL 1: DIFF §11b / protocol.md Step 3 — the store at `0xaf76` stores
  `r1`, and `r1 = 0xa9d8` (table base) on the switch path because `adr r1,4`
  at `0xa9d2` clobbers it; on the `0xaf54` fall-through path it is a callback
  pointer. It is never the message type. Ghidra's `param_1[0x18] = &table` is
  instruction-faithful; the "correction" is the error.
- FAIL 1b: the same paragraph's "the `(*(code*)&table)(1)` branch does not
  exist" — `0xafce movs r0,#1; 0xafd0 blx r1` exists; it is dead, not absent.
- FAIL 2: §11d / xversion Step 4 "all three" block (182 sigs, 225/223/213,
  max multiplicity 10, 235 pairs, 195 unmatched) is stale: it was produced
  from a 430-function 3.2.0 inventory; current inputs (423) give
  181 / 224/222/209, 7, 234, 189. Pair-level 379 and 183/224/211 do reproduce.
- Minor: protocol.md `0xaa28` byte quote is byte-swapped (`29 28 d1 00` vs
  actual `28 29 00 d1`); "22 `mov pc,rN`" is actually 18; "all 14 values are
  valid Thumb entry points" contradicts its own Step 5 for `0xaf72`.
- §11a's "0x10 body length 4 vs 8 B" instability did not reproduce (4 B both
  sides) — UNVERIFIED, not refuted.
