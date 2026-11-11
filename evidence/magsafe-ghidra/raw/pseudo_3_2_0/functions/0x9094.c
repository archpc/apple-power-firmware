// rea decompile_all
// name: FUN_00009094
// address: 0x9094
// body: available
// range: 0x9094-0x90dd inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00009094(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  
  lVar4 = FUN_00000e80();
  FUN_000090e0(0xaa);
  FUN_000090e0(0x80);
  FUN_0000910c(param_1);
  while( true ) {
    iVar2 = (int)((ulonglong)lVar4 >> 0x20);
    uVar3 = (uint)lVar4;
    if (lVar4 == 0) break;
    bVar1 = (byte)lVar4;
    if ((int)(-(uint)(0x7f < uVar3) - iVar2) < 0 !=
        (SBORROW4(0,iVar2) != SBORROW4(-iVar2,(uint)(0x7f < uVar3)))) {
      bVar1 = bVar1 | 0x80;
    }
    FUN_0000910c(bVar1,0x7f - uVar3);
    lVar4 = CONCAT44(iVar2 >> 7,(uVar3 >> 7) + iVar2 * 0x2000000);
  }
  return;
}

