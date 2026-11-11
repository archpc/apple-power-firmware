# SILICON — CCG3PA2 readback and debug access, from vendor documentation

Question: what read and debug access does the Infineon EZ-PD CCG3PA2 (marked `CYPDC1185B2`) permit, and could it yield a full flash dump of an A2743 adapter? Method: vendor PDFs from infineon.com, extracted with PyMuPDF 1.26.5, quoted by the document's own page numbers. No hardware, no programmer, no adapter action.

## Documents

| doc | number / rev | path under `infineon.com/assets/row/public/documents/` |
|---|---|---|
| EZ-PD CCG3PA2 Datasheet | **002-18400 Rev. \*G**, 2018-07-25 | `non-assigned/49/infineon-ez-pd-ccg3pa2-datasheet-usb-type-c-port-controller-datasheet-en.pdf` |
| CCGx (CYPDxxxx) Programming Specifications | **002-22328 Rev. \*G** | `30/436/infineon-ccgx-cypdxxxx-programming-specifications-programming-specifications-en.pdf` |
| AN218179 Getting Started with EZ-PD CCG3PA | **002-18179 Rev. \*\*** | `30/42/infineon-an218179-getting-started-with-ez-pdtm-ccg3pa-applicationnotes-en.pdf` |
| AN218238 HW guidelines, CCG3PA in power adapters | 002-18238 Rev. \*B | `30/42/infineon-an218238-…-applicationnotes-en.pdf` |
| EZ-PD Configuration Utility user manual | 002-22139 Rev. \*N | `30/96/infineon-ez-pd-configuration-utility-user-manual-software-en.pdf` |
| EZ-PD CCGx Host SDK user guide | 002-24327 Rev. \*H | `30/316/infineon-ez-pd-ccgx-host-sdk-user-guide-productqualificationreport-en.pdf` |

No CCG3PA2 Technical Reference Manual found: 002-22328 p. 5 points at "the target's datasheet and … the Technical Reference Manual" without naming one for CCG3PA2, and datasheet rev. \*C history (p. 35) records "Removed 'Firmware and Configuration Settings'". **OPEN**: whether a CCG3PA2 TRM is public. AN218238 covers CYPD3174/3175 in 24-QFN/16-SOIC — a different package and die variant, so its pin guidance is not transferable here.

Base URL: `https://www.infineon.com/assets/row/public/documents/`. Primary sources in full: `https://www.infineon.com/assets/row/public/documents/non-assigned/49/infineon-ez-pd-ccg3pa2-datasheet-usb-type-c-port-controller-datasheet-en.pdf` (561,275 bytes, `last-modified: 2025-01-16`, PDF metadata title "EZ-PD™ CCG3PA2 USB-C port controller") and `https://www.infineon.com/assets/row/public/documents/30/436/infineon-ccgx-cypdxxxx-programming-specifications-programming-specifications-en.pdf`.

## 1. Debug interface and flash

Datasheet p. 5: "The CPU also includes a serial wire debug (SWD) interface, which is a 2-wire form of JTAG. The debug configuration used for EZ-PD CCG3PA2 has four break-point (address) comparators and two watchpoint (data) comparators." 002-22328 p. 11: "The target silicon integrates the standard Cortex-M0 debug access port (DAP) block provided by Arm. … The target silicon does not support the JTAG interface."

Flash: datasheet p. 1 "2×64-KB flash", p. 5 "two banks of 64-KB flash". 002-22328 p. 5 Table 1-1, CCG3PA column: silicon ID `20xxxxB0`, **row 128 B**, **1 macro**, 256 rows/macro, `SET_IMO_48MHz` required, `TEST_MODE` at `0x40030014`; footnote e "NA for CCG3PA product family; only CCG3 product family has two macros."

**OBSERVED, high.** SWD is the only debug interface. The datasheet has no security, readout-restriction or fuse chapter at all — the protection model lives only in the programming spec (§3).

## 2. Read paths — three, and only one is unconditional

**(a) SWD direct memory read — full 128 KB.** 002-22328 p. 8: "Flash memory is mapped directly to the CPU's address space starting at 0x00000000. Therefore, the firmware or external programmer can read its content directly from the given address." p. 11: "reading from flash is an immediate operation that is carried out directly from the specified address. Reading works on a word basis (4-byte); writing works on a row basis." p. 32: "Reading from the flash is achieved by direct access to the memory space of the CPU. No SROM API is required; simply read from the flash address starting at 0x00000000." No unlock, no password. **OBSERVED, high** — valid in OPEN protection state only.

**(b) CC-line bootloader — update, not readback.** AN218179 p. 9: "The CC bootloader is used to upgrade the CCG3PA application firmware. It is allocated in a fixed area. The bootloader memory area can only be written using the SWD interface." Datasheet p. 29 Table 43: `CYPDC1185B2-32LQXQT` bootloader = "**DFP CC with Direct Feedback Bootloader**" — CC is the only bootloader offered for this order code; no I2C or USB entry. 002-22139 p. 53: CCG3PA is "single firmware … flash access (firmware or configuration update) supported through a dedicated boot-loader application. The USB PD port functionality is not supported in boot-loader mode". No command returning flash contents is documented in any of the six documents. **INFERRED (write-only)**; the wire protocol is proprietary and absence from public docs is not proof.

**(c) Configuration-table read — real, but a firmware feature.** 002-22139 p. 57 (§4.7 "Reading configuration from device"): "To read the Type-C configuration stored on the EZ-PD controller connected to the computer and display it, follow the menu path File > Read from Device." Scope is the config table (1 KB, 002-24327 p. 113), not the image. Decisive caveat, 002-24327 p. 141: "firmware update and **flash read functionality is provided by the application firmware itself**. Also, the bootloader is a fixed binary application which cannot be updated to include additional functionality." **OBSERVED.** Whether Apple's firmware implements any read service is **OPEN**.

## 3. What disables SWD — a flash byte, not a fuse

002-22328 p. 8: "chip-level protection … consists of one byte that restricts access to the chip's resources (register, SRAM, and flash) by an external programmer or debugger. For example, in PROTECTED mode, the programmer cannot read or write either flash or SRAM; in KILL mode, the SWD interface is locked in silicon and the chip cannot be reprogrammed."

Appendix A, p. 43 Table A-1, verbatim:
- **OPEN** (0x01): "Silicon is shipped to customers in OPEN mode. An external debugger can access all the needed resources for full-functional debugging of an application. Flash, SRAM, supervisory flash, and registers are available via the DAP."
- **PROTECTED** (0x02): "Access to Flash, SRAM, and most of the registers is disabled, so SWD transactions are NACKed for master. This is true for read and write requests on the SWD bus. In this mode it is possible to read the silicon ID and move the chip back to OPEN mode."
- **KILL** (0x04): "KILL mode completely locks the SWD-pins from an external programmer. Firmware cannot be updated … enable it only for production programming of a final application."

p. 44 Figure A-1: "PROTECTED > OPEN: Erases all User Region flash." … "There is no way to leave the KILL mode." **OBSERVED, high.** For a PROTECTED part the only documented route back to a readable state destroys the user region first; KILL is terminal. A dump from either state is impossible, not merely slow.

Location: "supervisory row of macro 0 at offset 0x7F" (p. 43), read at `(0x0FFFF000 + RowSize - 4) >> 24 & 0x0F` (p. 36), written with `SROM_CMD_WRITE_PROTECTION` only alongside a row-protection update (p. 33). "fuse", "OTP", "one-time" → zero hits in 002-22328. Row protection is not read protection, p. 7: it "prevents a row from being written but does not prevent a row's data from being read."

**OPEN**: which state Apple programs into A2743 units. No vendor document states it, and it is only observable on a unit — which §5 rules out.

## 4. 32-pin QFN pins the datasheet actually names

From 002-18400 Table 2 (p. 9–11) and Figure 3 (p. 13), QFN pin / CSP ball:

| pin | ball | name | datasheet wording |
|---|---|---|---|
| 3 | D4 | XRES | "Chip RESET pin" |
| 15 | C1 | SWD_DAT_0/P0.0 | "default operation at chip power up is SWD_DAT_0 which is the data signal for chip programming and debug" |
| 16 | B1 | SWD_CLK_0/P0.1 | "default operation … SWD_CLK_0 which is the clock signal for chip programming and debug" |
| 18 | A1 | P2.2/SBU1/GPIO_20VT/SWD_DAT_1 | default "GPIO port 2, pin 2"; reconfiguration list is GPIO_20VT, I2C_SDA_1, TCPWM_line_0 — **SWD_DAT_1 is not in it** |
| 19 | A2 | P2.3/SBU2/GPIO_20VT/SWD_CLK_1 | same pattern |
| 23/29/30/31/EPAD | B2/B4/E6/C5 | VBUS_IN/VSS/VDDD/VDDIO | 3.0–24.5 V, gnd, 2.7–5.5 V, 1.71–5.5 V |

Pins 15 and 16 are OVT, "Tolerant to voltages above VDDIO with a maximum of 7 VDC"; Table 4 p. 16 gives `VSWD_PIN_ABS` "Max SWD voltage — 24.5". Those two figures disagree for the same pins — **OBSERVED** inconsistency, and the conservative reading (7 V) should govern any inference. The datasheet never states a voltage, enable condition or sequence for `SWD_*_1` on 18/19; what that pair is for is **UNVERIFIED**.

## 5. Physical-access implication

The documented read (§2a) needs four contacts on the QFN: SWD_DAT_0 (15), SWD_CLK_0 (16), XRES (3) and a ground reference — plus, per 002-22328 p. 20, "a hard reset condition … generated by toggling either the XRES pin or the power supply", a 400 µs window in which the CPU "waits … for a special connection sequence on the SWD port", and "Setting TEST_MODE = 1 will prevent any customer firmware from starting." Pins 15/16 are sub-millimetre QFN pads inside a sealed, mains-powered enclosure: reaching them means opening the adapter. That is prohibited and out of scope (`README.md`; `OPEN.md`, "Explicitly not pursued").

The datasheet's own adapter reference design (p. 15, Figure 8) routes exactly these pins out, and the callout reads "**To Programming Header (Not needed for final production)**" — Cypress expects the header to be omitted from a shipping product. Whether A2743 retains accessible pads is **OPEN** and unobservable without opening it.

## Capability table

| interface | read? | write? | preconditions | source |
|---|---|---|---|---|
| SWD (SWDIO/SWCLK, Cortex-M0 DAP) | **yes**, full 128 KB, 4-byte words | yes | OPEN chip protection; XRES/power-cycle acquire within 400 µs; 4 pads on the QFN | 002-22328 p. 8, 11, 32; 002-18400 p. 9–13 |
| CC-line bootloader (DFP CC) | **no** documented read | yes (firmware + config) | PD contract; device jumps to bootloader, PD port down | 002-18400 p. 29; AN218179 p. 9; 002-22139 p. 53 |
| I2C / HPI | **no** documented flash read; config-table read only if running FW implements it | yes | I2C access to P0.0/P0.1, P1.0/P1.1 or P2.2/P2.3; firmware support | 002-24327 p. 139, 141 |
| UART / SPI (SCB) | not documented as a programming path | not documented | — | 002-18400 p. 6 |
| Config Utility "Read from Device" | **yes**, config table (~1 KB) only | yes | target firmware implements the read service | 002-22139 p. 57; 002-24327 p. 141 |

## Confirmed vs speculation

**Confirmed (vendor-documented):** SWD is the sole debug port and reads all of flash when the part is OPEN; a full dump therefore requires physical access to pins 15/16 plus XRES; a PROTECTED part NACKs flash reads and can only be returned to OPEN by erasing the user region; KILL locks SWD irreversibly; the CC bootloader is an update path with no published read command; the config-table read is implemented by application firmware, not by silicon.

**Speculation / not established:** that A2743 is actually CCG3PA2 (single-source teardown, per `IDENTITY.md`); that Apple leaves the part OPEN; that any Apple firmware read service exists; that SWD_1 on SBU1/SBU2 is usable as a debug port. None is supported by a vendor document, and all require a unit — the prohibited step.

**Net:** documented readback exists, but only through an interface that requires opening the adapter, and only if the part is not PROTECTED or KILL. No documented interface yields a dump without that access.
