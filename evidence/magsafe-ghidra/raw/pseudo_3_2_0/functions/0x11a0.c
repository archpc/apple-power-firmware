// rea decompile_all
// name: FUN_000011a0
// address: 0x11a0
// body: available
// range: 0x11a0-0x1231 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0x122e to 0xf3c FUN_00000f3c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_000011a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined8 uVar9;
  longlong lVar10;
  
  iVar4 = DAT_00001238;
  iVar2 = DAT_00001234;
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  iVar3 = DAT_00001234 + 0x110;
  uVar6 = (uint)*(byte *)(DAT_00001234 + 0x111);
  if (uVar6 == *(byte *)(DAT_00001234 + 0x110)) {
    uVar7 = 0xff;
  }
  else {
    uVar7 = (uint)*(byte *)(*(int *)(DAT_00001234 + 0x114) + uVar6);
  }
  if (*(byte *)(DAT_00001238 + 2) < uVar6) {
    *(byte *)(DAT_00001238 + 2) = *(byte *)(DAT_00001234 + 0x111);
  }
  if (uVar7 != 0xff) {
    iVar4 = *(int *)(iVar4 + 0x40);
    iVar8 = iVar2 + uVar7 * 0x10;
    *(undefined4 *)(iVar8 + 8) = param_3;
    uVar9 = FUN_00000866(iVar4,iVar4 >> 0x1f,param_1,param_2);
    iVar4 = (int)((ulonglong)uVar9 >> 0x20);
    lVar10 = FUN_00000e38();
    lVar10 = lVar10 + CONCAT44(iVar4 >> 0xd,((uint)uVar9 >> 0xd) + iVar4 * 0x80000);
    *(int *)(iVar2 + uVar7 * 0x10) = (int)lVar10;
    *(undefined4 *)(iVar8 + 0xc) = param_4;
    *(int *)(iVar8 + 4) = (int)((ulonglong)lVar10 >> 0x20);
    FUN_00001132(iVar3,uVar7,DAT_0000123c,0);
    FUN_0000126c();
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
    return (int)(char)uVar7;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00000f3c(DAT_00001240);
}

