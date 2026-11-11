# 70 W adapter — hardware identity and controller evidence

Question: what is the commercial identity of the "Apple 70W USB-C Power Adapter" seen on RID 5
(VID 0x05AC, PID 0x701C), what regulatory IDs does it carry, and what does any public source
explicitly show about its internal PD controller? Scope: web/regulatory research only; no
disassembly, no purchase, no adapter command. Read-only; no repo file touched but this one.
"OBSERVED" = the cited source states or displays it; local register facts are quoted from
`adapter-70w/BRIEF.md`, not re-derived. Labels: OBSERVED / REPRODUCED / INFERRED / UNVERIFIED /
REFUTED / OPEN.

## Step 1 — commercial identity: A2743, 70 W, Salcomp

Method: `web_search "Apple 70W USB-C Power Adapter A2743 model number part number"`; `web_extract`
of Apple support 102378 / 109509, Apple store `mkfp4am/a`, Apple KR `mxn53kh/a` and `mkfp4kh/a`,
and the ChargerLAB teardown.

- **A2743 is the 70 W USB-C adapter.** OBSERVED, high. Apple support 102378: "Tested with Apple 70W
  USB-C Power Adapter (Model A2743) with USB-C to MagSafe 3 Cable (Model A2363)."
  → https://support.apple.com/en-us/102378
- **It is the 70 W class adapter Apple names for MacBook Air / 14-inch MacBook Pro.** OBSERVED,
  high. Support 109509, "MacBook Air models introduced in 2022 or later": "Apple 70W USB-C Power
  Adapter and USB-C to MagSafe 3 Cable". → https://support.apple.com/en-us/109509
- **Part MXN53, model A2743, released 2023-06** (Apple's own Korean product-info table, part
  MXN53KH/A): "동일모델의 출시년월: 2023년 6월 … 모델명: A2743 … 인증정보: R-R-Scp-A2743,
  SU10774-23001". OBSERVED, high.
  → https://www.apple.com/kr_smb_5003936/shop/product/mxn53kh/a/70w-usb-c-전원-어댑터
- **Rated output as printed on the unit.** OBSERVED (label photo), medium-high. ChargerLAB: "It
  supports input of 100-240V~50/60Hz 1.8A. The maximum output voltage and current are 20.6V and
  3.4A, exactly 70W, and the manufacturer is Salcomp." (20.6 V × 3.4 A = 70.04 W, which is why a
  20 V / 3.39 A contract shows as `Watts=68`.)
  → https://www.chargerlab.com/teardown-of-brand-new-apple-70w-gan-usb-c-power-adapter-a2743/
- **ODM = Salcomp.** OBSERVED in the same label photo; consistent with the Salcomp planar
  transformer in that teardown and the KC holder code "Scp" in R-R-Scp-A2743. INFERRED (medium)
  that "Scp" means Salcomp — Apple does not state the mapping.
### Caveat: two model numbers now carry the "70W" name

- **A3543 is the 2026 refresh.** OBSERVED, high. Apple KR product-info table for the current "70W
  전원 어댑터", part MKFP4KH/A: "동일모델의 출시년월: 2026년 10월 … 모델명: A3543 … 인증정보:
  R-R-Scp-A3543, SU10774-26001". → https://www.apple.com/kr/shop/product/mkfp4kh/a/70w-전원-어댑터
  It uses AC Connector 2 (pill-shaped, post-regulation; support 102193), not AC Connector 1.
  → https://support.apple.com/en-us/102193
- **Apple's US page contradicts itself.** OBSERVED, high. `apple.com/shop/product/mkfp4am/a/70w-power-adapter`
  is titled "70W Power Adapter", $59, Tech Specs "AC Connector 2 / USB‑C", but its footnote says
  "Tested with Apple 70W USB-C Power Adapter (Model A2743)". Same base part MKFP4, two model
  numbers across Apple regions. OPEN which model MKFP4 ships today.
- **Which model the host sees is settled in Step 4** (A2743, medium-high).

## Step 2 — regulatory IDs and FCC: no FCC filing exists

Method: `web_extract https://fccid.io/A2743` → "No exact FCC ID page was found for A2743"; `https://fccid.io/search?q=A2743` →
21 fuzzy hits, all Apple laptops (BCGA3114, BCGA3468, BCGA3375 …) or unrelated vendors, none an adapter; FCC OET search
`apps.fcc.gov/oetcf/eas/reports/GenericSearch.cfm` with grantee=`BCG` product=`A2743`, then product=`A2743` alone.

- **No FCC filing for A2743.** OBSERVED, high; negative result from two independent databases. FCC
  OET returned its explicit page: "There are no applications on file that match the search criteria
  specified: Grantee Code: BCG Product Code: A2743" — and the same for product code alone, so it
  is not filed under an ODM grantee code either.
- **No FCC ID is printed on the product, and none should be.** INFERRED, high. An external AC
  adapter is an unintentional radiator authorized by Supplier's Declaration of Conformity, which
  grants no FCC ID; consistent with the empty filing record and with the label photo (model,
  electrical ratings and certification marks only). The SDoC-vs-FCC-ID rule is general FCC
  practice, not quoted from a filing here.
- **Regulatory IDs that do exist are non-US.** OBSERVED, high. Korea KC `R-R-Scp-A2743` plus
  efficiency registration `SU10774-23001` (Apple KR table, above). China CCC, quoted by ChargerLAB
  from the CCC register: "The model number is A2743, manufactured by Salcomp (Shenzhen) Co., Ltd.,
  and the certification date is June 6, 2023 … output is 5V3A / 9V3A / 15V3A / 20.6V3.4A"
  (secondary — the register itself was not queried).
  → https://www.chargerlab.com/a-closer-look-at-the-brand-new-apple-70w-usb-c-power-adapter
- **Consequence:** there are no FCC internal photos or schematics to mine; chip identification must
  come from teardown photography. OBSERVED, high.
## Step 3 — public teardown evidence for the PD controller

Method: `web_search "Apple 70W USB-C power adapter A2743 teardown chargerlab internal controller
chip"`; `web_extract` of the ChargerLAB A2743 teardown, `ednchina.com/technews/21761.html` (Chinese
original), `technews/41917.html` (A3543 teardown), Infineon datasheet 002-18400; `web_search
"CYPDC1185B2"` for order codes. No iFixit teardown of this adapter was found.

- **PD/protocol controller = Infineon EZ-PD CCG3PA2, marked CYPDC1185B2.** OBSERVED (single
  source), medium-high. ChargerLAB, 2023-06-16: "The protocol chip is from Infineon CCG3PA2 series.
  It integrates a 32-bit M0 processor and has multiple protection functions. Model is
  CYPDC1185B2-32D."
  → https://www.chargerlab.com/teardown-of-brand-new-apple-70w-gan-usb-c-power-adapter-a2743/
  Chinese original, same teardown: "协议芯片来自英飞凌，型号CYPDC1185B2-32D，属于CCG3PA2系列，
  内置32位M0处理器" → https://www.ednchina.com/technews/21761.html — one publisher (充电头网 /
  ChargerLAB), so one source, not two.
- **Family facts from the vendor datasheet.** OBSERVED, high: "EZ-PD™ CCG3PA2 is Cypress' highly
  integrated USB Type-C port controller … targeted for cable and power adapters applications … a
  32-bit Arm Cortex-M0 processor, 2×64-KB flash, a complete Type-C USB-PD transceiver … in 32-pin
  QFN and 30-ball CSP packages" (doc 002-18400 Rev *G).
  → infineon.com/assets/row/public/documents/non-assigned/49/infineon-ez-pd-ccg3pa2-datasheet-usb-type-c-port-controller-datasheet-en.pdf
- **The "-32D" suffix as printed is not a valid order code.** OBSERVED, medium: distributors list
  `CYPDC1185B2-32LQXQ` and `CYPDC1185B2-32LQXQT` (DigiKey); no "-32D" code appears in the
  datasheet ordering information. INFERRED, medium: "-32D" is a typo or truncated marking string
  for the 32-pin QFN part. Exact suffix OPEN.
- **Primary PWM controller is a separate Apple-custom part.** OBSERVED: "The master control chip is
  customized by Apple and marked with APSLCA01." That is the flyback controller, not the PD
  controller — do not conflate them.
- **Not inferred from other adapters.** The 143 W iMac adapter reports "Protocol Chip: Infineon
  CYPDC1185B2", and the 2026 70 W (A3543) reports "CYPDC1185B2-32E … EZ-PD CCG3PA 系列". Cited as
  family context only. → chargerlab.com/teardown-of-apple-143w-power-adapter-for-all-new-24-imac/
- **A2743 BOM, for the record.** OBSERVED, single source: no PFC stage; GaN Systems
  GS-065-011-1-L; AOS AONS1R6A70 / AONS660A70F; SR controller marked "D92vJ"; AOS AONS66917 SR
  FET; EL1014 optocoupler; Salcomp planar transformer; VBUS FET marked "0336".

**Controller status: family identified, exact order code OPEN, single-source.** No independent
teardown or regulatory document corroborates the CCG3PA2 claim.

## Step 4 — what remains unknown; PID 0x701C

Method: `web_search` for `"0x701C" Apple adapter USB PD identity`, `"05ac" "701c"`, `"A2743" "701C" 设备ID`; local `usb.ids` from
`http://www.linux-usb.org/usb.ids` with `grep -n -i 701c usb.ids` plus block context; `web_extract
https://theapplewiki.com/wiki/USB_Product_IDs`.

- **No public record maps 05AC:701C to any product.** OBSERVED, high. `usb.ids` line 2246 reads
  `701c  G-Shot G512 Still Camera`, but it sits in the block `0458 KYE Systems Corp. (Mouse
  Systems)` — a camera, not an Apple device. REFUTED that this entry describes the adapter: same
  number, different vendor. Apple Wiki's USB PID list has no 0x701C. A search snippet that looked
  like it placed 701c under 05AC was a cross-block artefact.
- **0x701C is a PD Discover Identity value, not a USB descriptor.** INFERRED, high: an AC adapter
  never enumerates on USB; the value is the Product VDO in the Discover Identity ACK (SOP), which
  is why it surfaces in HPM register 0x43 and as `AdapterDetails.Model="0x701C"` (decimal 28700 =
  `AdapterID`), and why USB-IF/usb.ids has no use for it.
- **A comparable public reading exists for the sibling model.** OBSERVED, high. A3543 teardown
  POWER-Z readout: "显示名称为70W USB-C Power Adapter … 设备ID为0x7026，VID为0x05AC，固件版本
  01010013，硬件版本1.0" (device ID 0x7026, VID 0x05AC, firmware 01010013, hardware 1.0).
  → https://www.ednchina.com/technews/41917.html
- **Hence the attached unit is A2743, not A3543.** INFERRED, medium-high. Host: PID 0x701C,
  `FwVersion=0x01030030`, `HwVersion=1.0`. A3543 is publicly 0x7026 / 0x01010013, and Apple sells
  only these two 70 W single-port models. Supporting, not decisive: A2743 is PD 3.0 with four fixed
  PDOs and no AVS (ChargerLAB: "only supports PD3.0 and DCP", PDOs "5V/9V/15V 3A, 20V 3.4A"),
  while A3543 adds PD 3.2 SPR AVS 9–15 V / 15–20 V, which the four-PDO `Rx Source Caps` do not show.
- **OPEN:** exact order code/marking on the A2743 die (photo caption only, no die shot, no Apple or
  Infineon document); whether 0x701C is keyed to model, firmware branch or unit (n=2); what firmware
  0x01030030 corresponds to publicly (no release notes); whether 0x701C appears on other Apple
  adapters (no table found); which model Apple ships today under MKFP4AM/A.
## Reproducible method

1. `web_search "Apple 70W USB-C Power Adapter A2743 model number part number"`; open
   `support.apple.com/en-us/102378` and `/109509`.
2. Regulatory IDs: read the Korean store "상품정보표시" block — A2743 → `R-R-Scp-A2743,
   SU10774-23001` (2023-06); A3543 → `R-R-Scp-A3543, SU10774-26001` (2026-10).
3. FCC: `fccid.io/A2743` (no page) → `fccid.io/search?q=A2743` (no adapter) →
   `apps.fcc.gov/oetcf/eas/reports/GenericSearch.cfm`, grantee `BCG` + product `A2743`, then
   product alone; both "There are no applications on file".
4. Controller: search "… teardown … chargerlab", read the "Teardown" section and BOM list of the
   A2743 article; verify the family against datasheet 002-18400 and distributor order codes.
5. PID: `grep -n -i 701c usb.ids` **and check the enclosing vendor block** (the hit is under 0458,
   not 05AC); compare with the A3543 POWER-Z readout (0x7026 / 01010013) at
   `ednchina.com/technews/41917.html`.
