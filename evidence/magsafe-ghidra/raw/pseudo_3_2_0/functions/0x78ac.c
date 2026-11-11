// rea decompile_all
// name: FUN_000078ac
// address: 0x78ac
// body: available
// range: 0x78ac-0x7915 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000078ac(uint param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_00007918 + param_1 * 0x1cc;
  if (*(char *)(iVar3 + 0xe) == '\x01') {
    iVar2 = *(int *)(DAT_0000791c + param_1 * 4);
    *(uint *)(iVar2 + 0x18c) =
         (*(uint *)(iVar2 + 0x18c) & 0xfffffffb) + (uint)(*(char *)(iVar3 + 0x1a) != '\0') * 4;
    FUN_00008d54(param_1);
    FUN_00002ee8(param_1);
    if (*(char *)(iVar3 + 0x15) == '\x01') {
      uVar1 = 0xe;
    }
    else {
      uVar1 = 10;
    }
    *(undefined1 *)(iVar3 + 0x45) = uVar1;
    *(undefined4 *)(iVar3 + 0x48) = 4;
    if (param_1 < 2) {
      *(undefined1 *)(DAT_00007920 + param_1 * 0x88 + 0x73) = 0;
      return;
    }
  }
  else {
    *(undefined1 *)(iVar3 + 0x22) = 1;
  }
  return;
}

