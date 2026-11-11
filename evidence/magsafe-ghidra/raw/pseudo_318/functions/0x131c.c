// rea decompile_all
// name: FUN_0000131c
// address: 0x131c
// body: available
// range: 0x131c-0x135b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000131c(undefined4 *param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  *param_2 = 0;
  iVar2 = DAT_0000135c;
  param_2[1] = *(undefined4 *)(DAT_0000135c + 0x4c);
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    *(undefined4 *)param_1[1] = param_2;
  }
  puVar4 = (undefined4 *)*param_1;
  if ((undefined4 *)*param_1 == (undefined4 *)0x0) {
    *param_1 = param_2;
    puVar4 = param_2;
  }
  param_1[1] = param_2;
  while( true ) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar3 & 1) == 1);
    }
    if (puVar4[1] == *(int *)(iVar2 + 0x4c)) break;
    software_interrupt(1);
    uVar3 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar3 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    puVar4 = (undefined4 *)*param_1;
  }
  return;
}

