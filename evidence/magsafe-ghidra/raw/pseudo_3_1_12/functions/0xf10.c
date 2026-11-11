// rea decompile_all
// name: FUN_00000f10
// address: 0xf10
// body: available
// range: 0xf10-0xf27 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00000f10(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  FUN_00012c44(&DAT_000131f7);
  FUN_00012c44(param_1);
  iVar2 = FUN_00000c20();
  if (iVar2 != 0) {
    if (*(char *)(iVar2 + 9) != '\0') {
      uVar4 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar4 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00000f84(iVar2);
      iVar3 = *(int *)(DAT_00000f7c + 0x4c);
      if ((((iVar3 != 0) && (iVar3 != iVar2)) && (*(char *)(iVar3 + 8) != '\0')) &&
         (*(char *)(DAT_00000f7c + 1) == '\0')) {
        *(undefined1 *)(DAT_00000f7c + 1) = 1;
        FUN_00000f84();
        *DAT_00000f78 = 0x10000000;
        InstructionSynchronizationBarrier(0xf);
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar4 & 1) == 1);
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00000f10(DAT_00000f80,0);
}

