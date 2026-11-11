// rea decompile_all
// name: FUN_00009128
// address: 0x9128
// body: available
// range: 0x9128-0x917b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00009128(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_14;
  
  iVar2 = DAT_00009184;
  iVar1 = DAT_0000917c;
  uVar3 = (uint)*(byte *)(DAT_00009184 + 6);
  if ((uVar3 != 0) && (*(char *)(DAT_00009184 + 5) == '\0')) {
    if (*(int *)(DAT_00009184 + 100) + uVar3 >> 0x10 == 0) {
      local_14 = param_4;
      FUN_00009fac(*(int *)(DAT_00009184 + 100) + 0x30000,DAT_00009188 + 0x20,uVar3,param_4,param_3)
      ;
      *(uint *)(iVar2 + 100) = *(int *)(iVar2 + 100) + (uint)*(byte *)(iVar2 + 6);
    }
    else {
      *(undefined1 *)(DAT_00009184 + 5) = 1;
      *(int *)(iVar2 + 100) = iVar1 + 1;
      local_14 = param_4 & 0xffffff00;
      FUN_00009fac(DAT_00009180,&local_14,1,param_4,param_3);
      FUN_000096f8(1);
    }
    *(undefined1 *)(iVar2 + 6) = 0;
  }
  return;
}

