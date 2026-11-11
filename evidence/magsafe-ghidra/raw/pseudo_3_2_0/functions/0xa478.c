// rea decompile_all
// name: FUN_0000a478
// address: 0xa478
// body: available
// range: 0xa478-0xa4df inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000a478(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar2 = DAT_0000a4e0;
  uVar7 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar7 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  iVar3 = DAT_0000a4e0 + 0x110;
  if (((uint)*(byte *)(DAT_0000a4e0 + 0x111) != (uint)*(byte *)(DAT_0000a4e0 + 0x110)) &&
     (uVar5 = (uint)*(byte *)(*(int *)(DAT_0000a4e0 + 0x114) + (uint)*(byte *)(DAT_0000a4e0 + 0x111)
                             ), uVar5 != 0xff)) {
    iVar6 = DAT_0000a4e0 + 0x18 + uVar5 * 4;
    *(undefined4 *)(iVar6 + 0xa8) = 0;
    *(undefined4 *)(iVar6 + 0x68) = param_1;
    FUN_00001132(iVar3,uVar5,DAT_0000a4e4);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar7 & 1) == 1);
  }
  puVar4 = (undefined4 *)(iVar2 + 0x70);
  for (uVar7 = 0; uVar7 < *(uint *)(iVar2 + 0x5c); uVar7 = uVar7 + 1) {
    (*(code *)puVar4[-4])(iVar2 + 0x18,param_1,*puVar4,0);
    puVar4 = puVar4 + 1;
  }
  return;
}

