// rea decompile_all
// name: FUN_00009964
// address: 0x9964
// body: available
// range: 0x9964-0x99bb inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0x99b2 to 0x967c FUN_0000967c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x99b8 to 0x967c FUN_0000967c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00009964(void)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = DAT_000099c4;
  if (*(int *)(DAT_000099c4 + 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0000967c(0xe);
  }
  uVar6 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar6 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  FUN_00009944();
  piVar4 = DAT_000099bc;
  cVar1 = *(char *)(iVar5 + 0x40);
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    enableIRQinterrupts((uVar6 & 1) == 1);
  }
  bVar3 = cVar1 - 1;
  if (99 < bVar3) {
                    /* WARNING: Subroutine does not return */
    FUN_0000967c(4);
  }
  while (-1 < *piVar4 << 0x1b) {
    piVar4[0xe] = 0x55;
  }
  FUN_000099c8((int)(char)bVar3);
  if (cVar1 == '2') {
    FUN_00000f28(iVar5 + 0x58);
  }
  *DAT_000099c0 = *DAT_000099c0;
  return;
}

