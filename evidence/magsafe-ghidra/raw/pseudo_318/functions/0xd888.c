// rea decompile_all
// name: FUN_0000d888
// address: 0xd888
// body: available
// range: 0xd888-0xd8f7 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000d888(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  if (param_1 == 1) {
    FUN_00000b50();
    *DAT_0000d8fc = *DAT_0000d8fc & 0xfffffffb;
    WaitForInterrupt();
    FUN_00000b58();
  }
  else if ((param_1 == 2) && (iVar3 = FUN_0000a788(), iVar2 = DAT_0000d900, -1 < iVar3)) {
    iVar3 = *DAT_0000d8f8;
    *(byte *)(DAT_0000d900 + 0x33) = (byte)((uint)iVar3 >> 0x1f);
    if (iVar3 < 0) {
      FUN_00012b30();
    }
    FUN_000129f0();
    if (*(char *)(iVar2 + 0x33) != '\0') {
      FUN_00012af0();
    }
    if ((*(char *)(iVar2 + 0xc) == '\x01') && (iVar3 = FUN_00001ff0(), iVar3 == 0)) {
      FUN_00002178();
      FUN_0000ba30();
      *(undefined1 *)(iVar2 + 0xc) = 0;
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  return;
}

