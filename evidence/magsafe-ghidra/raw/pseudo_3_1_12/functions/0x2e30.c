// rea decompile_all
// name: FUN_00002e30
// address: 0x2e30
// body: available
// range: 0x2e30-0x2edd inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00002e30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_00008ab0(param_1,0,param_3,param_4,param_4);
  FUN_00008b1c(param_1);
  iVar1 = *(int *)(DAT_00002ee8 + param_1 * 4);
  iVar3 = 0x118;
  *(uint *)(iVar1 + 0x128) = DAT_00002ee0 & *(uint *)(iVar1 + 0x128);
  *(undefined4 *)(iVar1 + 0x118) = DAT_00002ee4;
  FUN_0000c93c(param_1,0,0xe);
  iVar1 = DAT_00002eec + param_1 * 0x1cc;
  *(undefined1 *)(iVar1 + 0x21) = 0;
  *(undefined1 *)(iVar1 + 0x24) = 0;
  *(undefined1 *)(iVar1 + 0x20) = 0;
  *(undefined1 *)(iVar1 + 0x22) = 0;
  iVar2 = DAT_00002ef0 + param_1 * 0xf0;
  *(undefined2 *)(iVar2 + 0xa8) = 0;
  *(undefined2 *)(iVar2 + 0xa6) = 0;
  *(undefined1 *)(iVar2 + 0xa4) = 0;
  *(undefined1 *)(iVar1 + 0x2c) = 0;
  *(undefined1 *)(iVar1 + 0x45) = 0;
  *(undefined4 *)(iVar1 + iVar3) = 0;
  iVar3 = 0x43;
  *(undefined4 *)(iVar1 + 0x10c) = 0;
  *(undefined4 *)(iVar1 + 0x11c) = 0;
  *(undefined4 *)(iVar1 + 0x104) = 0;
  *(undefined4 *)(iVar1 + 0x48) = 0;
  *(undefined1 *)(iVar1 + 0x25) = 0;
  FUN_00002ef8(param_1);
  *(undefined1 *)(iVar1 + 0x176) = 0;
  *(undefined2 *)(iVar1 + 0x174) = 0;
  *(undefined1 *)(iVar1 + iVar3) = 0;
  *(undefined1 *)(iVar2 + 0xe5) = 0;
  *(undefined1 *)(iVar2 + 0xed) = 0;
  *(undefined1 *)(DAT_00002ef4 + param_1) = 0;
  return;
}

