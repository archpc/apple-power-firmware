// rea decompile_all
// name: FUN_00009d38
// address: 0x9d38
// body: available
// range: 0x9d38-0x9d99 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0x9d96 to 0x967c FUN_0000967c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00009d38(void)

{
  int iVar1;
  
  if (*(int *)(DAT_00009db0 + 0x10) == 0) {
    *(undefined4 *)(DAT_00009db4 + 0x70) = DAT_00009db8;
    *DAT_00009d9c = 0x1000;
    FUN_00012bd8(0);
    *DAT_00009da0 = 0x1000;
    FUN_00012bd8(1);
    FUN_00012a48();
    iVar1 = DAT_00009dbc;
    if (*(char *)(DAT_00009dbc + 0x25) == '\0') {
      FUN_00012a48();
      *(undefined1 *)(iVar1 + 0x25) = 1;
    }
    *DAT_00009da4 = *DAT_00009da4 | 0x80000000;
    *DAT_00009da8 = (uint)*(ushort *)(iVar1 + 0x3a);
    *DAT_00009dac = *DAT_00009dac & 0xfffffff8 | 8;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000967c(0xf);
}

