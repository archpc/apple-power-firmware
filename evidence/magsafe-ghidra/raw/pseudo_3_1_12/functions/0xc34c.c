// rea decompile_all
// name: FUN_0000c34c
// address: 0xc34c
// body: available
// range: 0xc34c-0xc3b5 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000c34c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_40 [4];
  undefined1 local_3c;
  undefined4 local_38;
  undefined1 local_34;
  undefined4 local_30 [7];
  
  iVar1 = DAT_0000c3bc;
  iVar3 = 0;
  for (iVar2 = param_3; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)((int)local_30 + iVar3) = *(undefined4 *)(param_2 + iVar3);
    iVar3 = iVar3 + 4;
  }
  *(undefined1 *)(DAT_0000c3bc + 0x1c9) = 1;
  local_34 = 0;
  local_3c = (undefined1)param_3;
  local_40[0] = 0;
  local_38 = 0;
  iVar2 = FUN_0000295c(param_1,0xc,local_40,DAT_0000c3c0);
  if (iVar2 == 0) {
    *(undefined1 *)(iVar1 + DAT_0000c3b8) = 1;
  }
  else {
    *(undefined1 *)(iVar1 + DAT_0000c3b8) = 0;
    *(undefined1 *)(iVar1 + 0x1c9) = 0;
    *(undefined4 *)(DAT_0000c3c4 + param_1 * 0x30 + 0x2c) = 4;
    FUN_0000c254(param_1,4,1,0);
  }
  return;
}

