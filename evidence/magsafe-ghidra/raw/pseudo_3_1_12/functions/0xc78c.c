// rea decompile_all
// name: FUN_0000c78c
// address: 0xc78c
// body: available
// range: 0xc78c-0xc81d inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0xc814 to 0xf10 FUN_00000f10 (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0xc81a to 0xf10 FUN_00000f10 (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000c78c(int param_1,int param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  
  puVar8 = DAT_0000c82c;
  uVar2 = DAT_0000c820;
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  if ((param_2 != 0xff) && (param_3 != 0)) {
    uVar5 = param_1 * 0x100 + param_2;
    iVar3 = DAT_0000c824;
    puVar4 = DAT_0000c828;
    for (iVar7 = 0; iVar7 != 0x20; iVar7 = iVar7 + 2) {
      if (*(ushort *)((int)DAT_0000c82c + iVar7) == uVar5) {
        FUN_000012a8(iVar3);
        *(short *)((int)puVar8 + iVar7) = (short)uVar2;
        *puVar4 = 0;
        break;
      }
      puVar4 = puVar4 + 1;
      iVar3 = iVar3 + 1;
    }
    iVar3 = 0;
    puVar4 = DAT_0000c828;
    while( true ) {
      if (iVar3 == 0x10) {
                    /* WARNING: Subroutine does not return */
        FUN_00000f10(DAT_0000c830);
      }
      if (*puVar8 == uVar2) break;
      puVar8 = puVar8 + 1;
      puVar4 = puVar4 + 1;
      iVar3 = iVar3 + 1;
    }
    *puVar4 = param_4;
    *puVar8 = (ushort)uVar5;
    iVar7 = FUN_00001178(param_3 * 1000,0,DAT_0000c834,iVar3);
    *(char *)(DAT_0000c824 + iVar3) = (char)iVar7;
    if (iVar7 == -1) {
                    /* WARNING: Subroutine does not return */
      FUN_00000f10(DAT_0000c838);
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar6 & 1) == 1);
  }
  return;
}

