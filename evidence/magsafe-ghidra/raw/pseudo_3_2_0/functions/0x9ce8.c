// rea decompile_all
// name: FUN_00009ce8
// address: 0x9ce8
// body: available
// range: 0x9ce8-0x9d1f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0x9d1c to 0x975c FUN_0000975c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00009ce8(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar1 = DAT_00009d20;
  if (*(char *)(DAT_00009d20 + 0x23) == '\0') {
    iVar3 = FUN_0000ceb8();
    if (iVar3 < 0x51) {
      if (*(byte *)(iVar1 + 0x10) < 0x15) {
        cVar2 = *(byte *)(iVar1 + 0x10) + 1;
      }
      else {
        cVar2 = '\x15';
      }
      *(char *)(iVar1 + 0x10) = cVar2;
      return;
    }
  }
  else {
    *(undefined1 *)(DAT_00009d20 + 0x23) = 0;
  }
  if (*(byte *)(iVar1 + 0x10) < 0x14) {
    FUN_00000bcc();
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000975c(7);
}

