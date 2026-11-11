// rea decompile_all
// name: FUN_0000ba50
// address: 0xba50
// body: available
// range: 0xba50-0xbac3 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


char FUN_0000ba50(int param_1,int param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  char local_18 [4];
  
  local_18[0] = '\0';
  iVar1 = *(int *)(param_1 + 8);
  if ((param_3 == 0) || (*(int *)(param_1 + 0x10) != param_2)) {
    (**(code **)(iVar1 + 0xc))(param_1,param_2,param_3,local_18);
    if (local_18[0] == '\0') {
      return '\0';
    }
    *(int *)(param_1 + 4) = iVar1;
  }
  else {
    *(int *)(param_1 + 8) = param_3;
    local_18[0] = '\x01';
    *(int *)(param_1 + 4) = iVar1;
    if (iVar1 == 0) goto LAB_0000baac;
  }
  if (*(code **)(iVar1 + 8) != entry) {
    (**(code **)(iVar1 + 8))(param_1,param_2,param_3,*(undefined4 *)(param_1 + 0xc));
  }
LAB_0000baac:
  pcVar2 = *(code **)(*(int *)(param_1 + 8) + 4);
  if (pcVar2 != entry) {
    (*pcVar2)(param_1,param_2,param_3,*(undefined4 *)(param_1 + 0xc));
  }
  return local_18[0];
}

