// rea decompile_all
// name: FUN_0000b73c
// address: 0xb73c
// body: available
// range: 0xb73c-0xb7b7 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000b73c(int param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar6 = DAT_0000b7bc;
  *(char *)(DAT_0000b7bc + 0x16) = (char)param_2;
  *(char *)(iVar6 + 0x15) = (char)param_3;
  puVar3 = DAT_0000b7c4;
  iVar2 = DAT_0000b7c0;
  uVar7 = param_2;
  uVar5 = param_3;
  if ((param_1 == 1) && (*(char *)(DAT_0000b7c0 + 0x34) != '\0')) {
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_000012a8(DAT_0000b7c4);
    uVar4 = FUN_00001178(DAT_0000b7b8,0,PTR_LAB_00002da0_1_0000b7c8,0,uVar7,uVar5);
    *puVar3 = uVar4;
    *(undefined1 *)(iVar6 + 3) = 1;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
  }
  iVar6 = FUN_0000295c(param_2,param_3,iVar2 + 0x28,PTR_DAT_0000b7cc,uVar7,uVar5);
  if (iVar6 != 0) {
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_000012a8(puVar3 + 2);
    uVar4 = FUN_00001178(1000,0,PTR_LAB_0000bc94_1_0000b7d0,0);
    puVar3[2] = uVar4;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
  }
  return;
}

