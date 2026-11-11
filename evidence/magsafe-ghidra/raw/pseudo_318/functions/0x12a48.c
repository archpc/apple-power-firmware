// rea decompile_all
// name: FUN_00012a48
// address: 0x12a48
// body: available
// range: 0x12a48-0x12a8d inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00012a48(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_00012a90;
  DAT_00012a90[-8] = DAT_00012a94;
  *puVar1 = DAT_00012a98;
  uVar3 = DAT_00012aa0;
  puVar2 = DAT_00012a9c;
  *DAT_00012a9c = DAT_00012aa0;
  puVar2[1] = 7;
  puVar2 = DAT_00012aa4;
  *DAT_00012aa4 = uVar3;
  puVar2[1] = 1;
  puVar2 = DAT_00012aa8;
  *DAT_00012aa8 = 0;
  puVar2[0x10] = 0;
  puVar2 = DAT_00012aac;
  DAT_00012aac[0x10] = 0;
  *puVar2 = 0;
  puVar2 = DAT_00012ab0;
  DAT_00012ab0[0x10] = 0;
  *puVar2 = 1;
  *(short *)(DAT_00012ab4 + 0x3a) = (short)*puVar2;
  *puVar1 = *puVar1 & 0xf3ffffff;
  return;
}

