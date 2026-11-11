# Delegated research log — VDM form / UARP transport

Append-only log for delegated sub-studies. Each entry: question, method, findings with
labels, files written.

---

## 2026-11-11 — Which VDM form carries UARP TLVs to the MagSafe cable?

**Question (NEXT.md item 5):** host kernel emits unstructured VDM with a `VDMs` 4CC, while
`UARPUpdaterServiceUSBPD` speaks SOP/SOP' and parses VDOs. Which form carries UARP firmware
TLVs, and what do the cable-side entry points look like?

**Deliverable:** `evidence/magsafe-cortexm/delegated/vdm/SPEC.md`.

### Findings

1. **OBSERVED** — the kext has *two* senders. `AppleHPM::hpmIECSSendVDM`
   @`0xfffffe00095205ec` builds `[hdr=(sop&3)<<4|len/4][payload ≤28 B]` and appends the
   4CC `0x56444D73` "VDMs" through a *separate* vtable call (+0x8f0, arg 5).
   `AppleHPM::hpmIECSCommand` @`0xfffffe0009521a0c` takes an arbitrary 4CC, `rev`s it
   (`0xfffffe0009521b34`) and writes it as 4 data bytes, then polls for
   `0x444D4321` "!CMD" (100 ms × retries). The 4CC is therefore a *command tag*, and
   `VDMs` is one tag among many.
2. **OBSERVED** — UARP never uses the `VDMs` frame. `readCFUa` builds
   `mov w2,0x4643 ; movk w2,0x6155,lsl 16` ("CFUa") and calls `doAtomic4CC`
   (`adapter-70w/evidence/dump/software-readpath.md:106-110`); siblings are `setCFUp`
   ("iecsCommand(CFUp) failed"), `writeCFUa:`, `writeCFUs:`.
3. **OBSERVED** — byte scan of `kexts/com.apple.driver.AppleHPM.macho`: `CFUp`(0x70554643),
   `CFUa`(0x61554643), `CFUs`(0x73554643), ASCII `CFU` → **0 hits each**; `VDMs` as a data
   literal also 0, but 8 code sites build it with `movz #0x4456 / movk #0x734d`
   (0x37734, 0x3fc6c, 0x486b0, 0x48c0c, 0x48c28, 0x48c58, 0x48ca0, 0x59b78). CFU 4CCs
   arrive as runtime arguments of `AppleHPM::atomic4CC` @`0xfffffe0009522600` /
   `AppleHPM::hpmAtomic4CC` @`0xfffffe0009522200`.
   *Correction to an earlier grep in this session:* a naive LE-u32 search for "CFUp" using
   0x46555043 matches `"CPUF"` inside `enableCPUFastPLLRelock` etc. — false positives; the
   correct value is 0x70554643 and it has zero hits.
4. **OBSERVED** — CFUa/CFUs descriptor bitfields (`software-readpath.md:112-121`):
   bits31..30 `_sopType`, 20..18 `remoteEndpoint` (**all callers pass 1**), 16 direction,
   28..24 length. Cable-facing discovery frame uses header `0x21` (selector 2) and is logged
   "issuing discovery on sop'" (`applehpm-strings.txt:915`). **INFERRED (high):** selector 2
   = SOP'; adapter on SOP, cable on SOP' per the `UARPPowerAdapter` / `UARPMagSafeCable`
   split. `_sopType`'s stored value for the cable is **OPEN** (set above the analysed IMPs).
5. **OBSERVED (cable, 3.1.8)** — real SVID dispatch at `0xb34c`: `lsrs r0,r4,#0x10` then
   compare against `0xFF00` (`movs 0xff; lsls 8`) and `[0xb59c]=0x5AC`; bit15 chooses
   structured (`0xb38a`, SVDM command = bits 3:0) vs unstructured (`bl 0xb64c`).
   Unstructured handler `0xb64c`: `header & 0x1f` = VDO count, accepts 1..5, `memcpy` from
   tables at `[0xb700]=0x13AA8` / `[0xb704]=0x13AC0`, dispatch on count 1/4/5 — **no 4CC
   compare**.
6. **OBSERVED (cable, all three versions)** — identity composition at `0xc2ce`: words
   `0x05AC8106` (SVID 0x05AC + SVDM hdr, Discover Identity) and `0x05AC0005` (ID Header
   VDO), 1 or 2 words selected by a per-port state byte `[entry+4]+0x14`, then
   `bl 0xc2f8` → `0x295c`. Identical pool bytes in 3.1.8 (`0xc2ec`), 3.1.12 (`0xc344`),
   3.2.0 (`0xc4e4`).
7. **OBSERVED (absence, cable)** — `VDMs`, `CFU`, `UARP` byte strings: 0 hits in all three
   images. No 4CC table, no 4CC parse. Cable code range ends `0x14404`.
8. **OBSERVED (A2452, `firmware/payloads/A2452/BRCK_1.4.90.0.bin`, 59 904 B, present —
   no archive opened)** — 16 × `ac 05`, but the two `06 81` hits (0x11c5, 0xcf37) are
   instruction bytes (`lsls`/`lsrs`), *not* a `0x05AC8106` composition; no
   `VDMs`/`CFU`/`UARP`. INFERRED: adapter identity is table-driven, different shape from the
   cable's code-built SVDM.

### Verdict

UARP TLVs ride **Apple's 4CC mailbox transactions (`CFUp`/`CFUa`/`CFUs`)** addressed to
SOP' for the cable — **not** the `VDMs`-tagged frame and **not** a USB-PD structured VDM.
The `"UARP over USB-PD Structured VDMs"` wording in `evidence/usbcupdater-notes.md:42` is
terminology, not a byte-level description (mark INFERRED). The cable demonstrably parses
Apple SVID VDMs (0x05AC, structured/unstructured, command nibble, VDO count 1..5) but
nothing in its application image references a 4CC → CFU handling is **NOT SHOWN**; whether
it happens below the app image is **OPEN**.

**Settling experiment:** one passive CC-line capture during a cable update — message
endpoint (SOP vs SOP'), envelope (SVDM header vs `CFUp/CFUa` 4CC data word), and chunk size
(28-byte UVDM vs 20/24-byte CFUa) all fall out of the same trace.

### Files

- `evidence/magsafe-cortexm/delegated/vdm/SPEC.md` (answer)
- `evidence/magsafe-cortexm/delegated/vdm/dis_*.json` (linear `pdj` sweeps — mostly
  misaligned, superseded; keep only as provenance)
- `evidence/magsafe-cortexm/delegated/vdm/funcdis_3.1.8_10M569.json` (function-range
  disassembly, 9 785 insns)

### Method notes for reuse

- `nm -nm` works on the kernel kext and gives mangled C++ symbols with vaddrs — far faster
  than `rizin -c is` on a 26 MB Mach-O (whose string scan also warns/skips).
- Disassemble per function start from the seeded inventory; a linear `pd 42000 @ 0` sweep of
  a Cortex-M image is ~99 % junk (41 827/42 000 "invalid") because data is interleaved.
- RIP-relative loads print as `ldr rX, [0x0000c2ec]` (8 hex digits), so xref hunting must
  match that form, and a *pool address* with zero refs means dead or indirectly-indexed data
  — not "unused".
- Grep repo evidence for `remoteEndpoint`/`sopType` before decompiling; the 70 W study had
  already tabulated the CFUa descriptor.
