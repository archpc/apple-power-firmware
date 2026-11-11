// rea decompile_all
// name: FUN_00007288
// address: 0x7288
// body: available
// range: 0x7288-0x72f1 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined8 FUN_00007288(uint param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (1 < param_1) {
    return CONCAT44(param_2,2);
  }
  uVar2 = FUN_00000b70();
  pcVar1 = DAT_000072f4;
  (*DAT_000072f4)(param_1);
  (*pcVar1)(param_1,4);
  (*pcVar1)(param_1,7);
  FUN_00008c8c(param_1);
  iVar3 = DAT_000072f8 + param_1 * 0x88;
  *(undefined1 *)(iVar3 + 0x73) = 0;
  *(undefined4 *)(iVar3 + 0x80) = 0;
  *(undefined1 *)(iVar3 + 0x84) = 0;
  FUN_00000b78(uVar2);
  *(undefined1 *)(iVar3 + 0x74) = 5;
  FUN_0000c908(param_1,7,0x14,DAT_000072fc);
  *(undefined1 *)(iVar3 + 0x73) = 1;
  uVar2 = FUN_00008cc8(param_1);
  return CONCAT44(param_2,uVar2);
}

