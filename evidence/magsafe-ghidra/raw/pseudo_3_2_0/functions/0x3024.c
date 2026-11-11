// rea decompile_all
// name: FUN_00003024
// address: 0x3024
// body: available
// range: 0x3024-0x3087 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00003024(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  code *pcVar2;
  int iVar3;
  undefined1 auStack_50 [60];
  
  iVar3 = DAT_00003088 + param_1 * 0x1cc;
  *(undefined1 *)(iVar3 + 0x1c9) = 0;
  if (*(char *)(iVar3 + 0x2f) == '\x01') {
    pcVar2 = *(code **)(iVar3 + 100);
    if (param_2 != 3) {
      *(undefined1 *)(iVar3 + 0x2f) = 0;
    }
    if (pcVar2 != entry) {
      if (param_3 == 0) {
        puVar1 = (undefined1 *)0x0;
      }
      else {
        puVar1 = auStack_50;
        FUN_00000170(puVar1,param_3,0x3c);
      }
      (*pcVar2)(param_1,param_2,puVar1);
      if (param_2 != 3) {
        *(undefined4 *)(iVar3 + 100) = 0;
      }
    }
  }
  return;
}

