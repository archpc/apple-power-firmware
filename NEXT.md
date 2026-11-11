# NEXT — state after the MagSafe semantic-diff waves (2026-11-11)

Resolved since the last revision (see DIFF.md sections 11-14 for evidence):

- Execution model: Cortex-M Thumb analysis (ARM:LE:32:Cortex), seeded
  inventories 444/436/423 functions, reproducible; 0x10 = CANDIDATE startup;
  vector-table words provably not code. Audited (delegated/review/).
- The C99 header is a two-record SHA-256/CRC-32 hash chain; base0 images =
  payload[0x180:]. SHA-256 + secp256r1 present in all builds.
- Cross-version: calibrated matcher (threshold 0.9830, within-build hard
  negatives); 124/155 non-stub pairs identical modulo relink, 31 substantive
  (incl. a signed->unsigned compare change); second-stage 17-case switch
  successor verified (0xad2a/0xad7e/0xab64, ldrb->ldrh).
- Dispatcher islands are very likely stale copies (zero inbound edges, even
  mov pc table targets); the live PD handler's location is OPEN.

Still open, with what would settle each:

1. **Live PD handler / island reachability.** The callback/vtable mechanism
   exists (13-entry vtable installed at port_obj+0x60, runtime-filled) but
   never targets the islands statically. A runtime image dump (requires
   Accessory Mode 7 readback — explicit approval gate) would relocate
   everything; static analysis alone is exhausted here.
2. **Soft->hard reset escalation.** Bounded negative statically (no decoded
   path from timer machinery to a CC/PHY write). A passive CC capture during
   an unanswered Soft_Reset would settle it.
3. **Anti-rollback.** No version threshold found statically; testing requires
   offering an older build to a newer device (policy-blocked without a
   recovery story).
4. **3.2.0 outer dispatcher counterpart.** The 14-case 9-22 table has no
   3.2.0 counterpart in the analysed set; the uncovered islands (56.2%
   coverage leaves ~37 kB) are the first place to look, and would need
   better function discovery there, not new hardware.
5. **CFU consumption below the app image** (PD PHY/ROM). Not visible
   statically; needs a CC capture during a real update.
6. **Header fields 0xa0..0xdf and the 0x17c trailer** — unexplained; the
   64 bytes are range-valid as ECDSA (r,s) but not on-curve.
7. **30 'probable' (0.85-band) pairs** remain UNVERIFIED; the literal-multiset
   validator is confounded (recorded); callee-multiset comparison is the
   candidate replacement.

No hardware is available for items 2/5; item 1 needs the approval gate;
items 4/6/7 are pure static work and are the recommended next steps.
