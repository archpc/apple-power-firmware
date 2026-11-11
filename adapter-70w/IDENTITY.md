# IDENTITY — which adapter this is, and what is known about its controller

Separate from the cable (`0x7800`) and from the HPM controllers (`0xD540`,
`0x1C60`). All local register facts are in `REGISTERS.md`.

## 1. Commercial identity

- **A2743 is the 70 W USB-C Power Adapter.** OBSERVED, high. Apple support
  102378: "Tested with Apple 70W USB-C Power Adapter (Model A2743) with USB-C to
  MagSafe 3 Cable (Model A2363)." https://support.apple.com/en-us/102378
- **Part MXN53, released 2023-06, Korean product-info table** lists
  "모델명: A2743 … 인증정보: R-R-Scp-A2743, SU10774-23001". OBSERVED, high
  (Apple KR product page for MXN53KH/A).
- **Rated output 20.6 V × 3.4 A = 70.04 W, ODM Salcomp.** OBSERVED from the
  label photo in the ChargerLAB teardown ("maximum output voltage and current
  are 20.6V and 3.4A, exactly 70W, and the manufacturer is Salcomp").
  This explains `Watts=68`: the host reports the negotiated 20 V × 3.39 A
  contract, not the nameplate rating.
- **The host identifies it as `0x05AC:0x701C`.** OBSERVED, two independent
  local sources: `AdapterDetails.Model="0x701C"` / `AdapterID=28700` and HPM
  register `0x43` bytes `19 AC 05 1C 70`. See `HOST.md` and `REGISTERS.md`.

### A second model carries the same marketing name

- **A3543 is a 2026 refresh** using AC Connector 2 (Apple KR product table for
  MKFP4KH/A: "2026년 10월 … 모델명: A3543 … R-R-Scp-A3543"). OBSERVED, high.
  Apple's US page for part MKFP4 is titled "70W Power Adapter" but footnotes
  "Model A2743", so the base part number spans two model numbers by region.
  OPEN which model MKFP4 currently ships.
- A public POWER-Z readout of an A3543 is reported to show PID `0x7026`,
  firmware `0x01010013` and PD 3.2 SPR AVS. **UNVERIFIED** here (secondary
  source, not independently reproduced). If true, it discriminates the two
  units: the host's `0x701C`, four fixed PDOs, no AVS, no EPR PDOs is the
  A2743 profile. INFERRED, medium-high.

## 2. Regulatory identifiers

- **No FCC filing exists for A2743.** OBSERVED, high, negative from two
  databases: `fccid.io/A2743` has no exact page, and the FCC OET search returns
  "There are no applications on file that match the search criteria specified:
  Grantee Code: BCG Product Code: A2743", also with the product code alone.
  Consequence: there are no FCC internal photos or schematics to mine;
  chip identification can only come from teardown photography.
- **Non-US IDs do exist.** Korea KC `R-R-Scp-A2743` and efficiency registration
  `SU10774-23001` (Apple's Korean table, primary). China CCC registration is
  quoted by ChargerLAB from the CCC register (secondary; the register itself was
  not queried): model A2743, manufacturer Salcomp (Shenzhen), certification
  2023-06-06, output 5V3A / 9V3A / 15V3A / 20.6V3.4A.

## 3. Controller evidence

- **PD/protocol controller: Infineon EZ-PD CCG3PA2, marked `CYPDC1185B2`.**
  OBSERVED but **single source**: ChargerLAB, 2023-06-16, "The protocol chip is
  from Infineon CCG3PA2 series … Model is CYPDC1185B2-32D." The Chinese
  "original" at ednchina is the same publisher, not an independent teardown.
- **Family facts from the vendor datasheet** (OBSERVED, high): CCG3PA2 is a
  USB Type-C port controller for cable and power-adapter applications with a
  32-bit Arm Cortex-M0, 2×64 KB flash and a PD transceiver, in 32-pin QFN and
  30-ball CSP. This bounds what the part can be; it does not confirm the
  marking.
- **The printed `-32D` suffix is not a valid order code.** Distributors list
  `CYPDC1185B2-32LQXQ` / `-32LQXQT`. INFERRED: typo or truncated marking for
  the 32-pin QFN. Exact suffix OPEN.
- **A separate Apple-custom part, marked `APSLCA01`, is the primary PWM
  controller**, not the PD controller. Do not conflate the two.
- **Not transferred from other products.** The 143 W iMac adapter and the 2026
  A3543 are also reported to use `CYPDC1185B2` family parts. That is family
  context, not evidence for this board.

## 4. What remains unknown

- Exact controller order code and package (single-source marking).
- Whether the adapter MCU runs the Apple-custom code that would implement a UARP
  responder; no payload exists to check (`DISTRIBUTION.md`).
- What PID `0x701C` maps to publicly. No record found: `usb.ids` line 2246
  `701c G-Shot G512` sits in vendor `0458` (KYE), not `05AC`, and is REFUTED as
  an Apple mapping. Apple Wiki's PID list has no `0x701C`.
