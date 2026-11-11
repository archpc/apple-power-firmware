// rea decompile_all
// name: FUN_000062a8
// address: 0x62a8
// body: available
// range: 0x62a8-0x62ef inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000062a8(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5,undefined2 param_6,undefined4 param_7,undefined2 param_8,
                 undefined1 param_9,undefined4 param_10,undefined2 param_11)

{
  int iVar1;
  
  iVar1 = DAT_000062f0 + param_1 * 0xf0;
  *(undefined2 *)(iVar1 + 0xb0) = param_8;
  *(undefined1 *)(iVar1 + 0xac) = param_3;
  *(undefined1 *)(iVar1 + 0xab) = param_2;
  *(undefined1 *)(iVar1 + 0xaa) = param_4;
  *(undefined4 *)(iVar1 + 0xb4) = param_7;
  *(undefined1 *)(iVar1 + 0xad) = param_5;
  *(undefined2 *)(iVar1 + 0xc0) = param_11;
  *(undefined4 *)(iVar1 + 0xbc) = param_10;
  *(undefined1 *)(iVar1 + 0xb8) = param_9;
  *(undefined2 *)(iVar1 + 0xae) = param_6;
  FUN_000031a0(param_1,0x24);
  return;
}

