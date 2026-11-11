// rea decompile_all
// name: FUN_000012d0
// address: 0x12d0
// body: available
// range: 0x12d0-0x1329 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000012d0(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  iVar4 = DAT_0000132c;
  iVar7 = DAT_0000132c + 0x110;
  uVar8 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar8 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  iVar5 = *(int *)(DAT_0000132c + 0x114);
  uVar6 = 0;
  do {
    if (*(byte *)(DAT_0000132c + 0x111) == uVar6) {
LAB_00001320:
      *param_1 = -1;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        enableIRQinterrupts((uVar8 & 1) == 1);
      }
      return;
    }
    if (*(char *)(iVar5 + uVar6) == *param_1) {
      bVar3 = *(byte *)(DAT_0000132c + 0x111) - 1;
      *(byte *)(DAT_0000132c + 0x111) = bVar3;
      uVar1 = *(undefined1 *)(iVar5 + uVar6);
      *(undefined1 *)(iVar5 + uVar6) = *(undefined1 *)(iVar5 + (uint)bVar3);
      *(undefined1 *)(*(int *)(iVar4 + 0x114) + (uint)*(byte *)(iVar4 + 0x111)) = uVar1;
      FUN_000010cc(iVar7,uVar6,DAT_00001330,0,param_4);
      *(char *)(*(int *)(iVar4 + 0x114) + (uint)*(byte *)(iVar4 + 0x111)) = *param_1;
      FUN_0000126c();
      goto LAB_00001320;
    }
    uVar6 = uVar6 + 1;
  } while( true );
}

