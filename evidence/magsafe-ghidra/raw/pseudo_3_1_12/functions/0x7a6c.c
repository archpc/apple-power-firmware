// rea decompile_all
// name: FUN_00007a6c
// address: 0x7a6c
// body: available
// range: 0x7a6c-0x7aef inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00007a6c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_00007af0 + param_1 * 0x1cc;
  iVar3 = *(int *)(iVar1 + 0x60);
  iVar4 = param_2;
  FUN_00002f50(param_1);
  FUN_00007be4(param_1,0);
  FUN_00007be4(param_1,1);
  iVar2 = *(int *)(DAT_00007af4 + param_1 * 4);
  *(uint *)(iVar2 + 400) = *(uint *)(iVar2 + 400) & 0xfffffbff;
  (**(code **)(iVar3 + 0x18))(param_1,0,*(code **)(iVar3 + 0x18),0x400,iVar4);
  (**(code **)(iVar3 + 0x18))(param_1,1);
  if (param_2 == 0) {
    (**(code **)(iVar3 + 0x10))(param_1,0);
    (**(code **)(iVar3 + 0x38))(param_1,0);
    FUN_0000c93c(param_1,0xf,0x18);
    *(undefined1 *)(iVar1 + 0x2d) = 0;
    *(undefined1 *)(iVar1 + 0x42) = 0;
    *(undefined4 *)(iVar1 + 0x4c) = 0;
    *(undefined1 *)(iVar1 + 0x1d) = 0;
    *(undefined1 *)(iVar1 + 0x1c) = 0;
    *(undefined1 *)(iVar1 + 0x19) = 1;
  }
  return;
}

