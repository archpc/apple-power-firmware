// rea decompile_all
// name: FUN_000012a8
// address: 0x12a8
// body: available
// range: 0x12a8-0x1311 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined8 FUN_000012a8(char *param_1)

{
  undefined1 uVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar4 = DAT_00001314;
  uVar5 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar5 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  iVar6 = *(int *)(DAT_00001314 + 0x114);
  uVar7 = 0;
  do {
    if (*(byte *)(DAT_00001314 + 0x111) == uVar7) {
LAB_00001306:
      *param_1 = -1;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        enableIRQinterrupts((uVar5 & 1) == 1);
      }
      return CONCAT44(0x114,uVar5);
    }
    if (*(char *)(iVar6 + uVar7) == *param_1) {
      bVar3 = *(byte *)(DAT_00001314 + 0x111) - 1;
      *(byte *)(DAT_00001314 + 0x111) = bVar3;
      uVar1 = *(undefined1 *)(iVar6 + uVar7);
      *(undefined1 *)(iVar6 + uVar7) = *(undefined1 *)(iVar6 + (uint)bVar3);
      *(undefined1 *)(*(int *)(iVar4 + 0x114) + (uint)*(byte *)(iVar4 + 0x111)) = uVar1;
      FUN_000010a4(iVar4 + 0x110,uVar7,DAT_00001318,0);
      *(char *)(*(int *)(iVar4 + 0x114) + (uint)*(byte *)(iVar4 + 0x111)) = *param_1;
      FUN_00001244();
      goto LAB_00001306;
    }
    uVar7 = uVar7 + 1;
  } while( true );
}

