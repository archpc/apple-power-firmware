// rea decompile_all
// name: FUN_00005c8c
// address: 0x5c8c
// body: available
// range: 0x5c8c-0x5d2d inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00005c8c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  code *pcVar2;
  char *pcVar3;
  
  pcVar3 = *(char **)(DAT_00005d34 + param_1 * 0xf0);
  if (*pcVar3 == '\x01') {
    if (pcVar3[2] == '\x0f') {
      iVar1 = DAT_00005d34 + param_1 * 0xf0;
      *(undefined2 *)(iVar1 + 0xb0) = 0;
      *(short *)(iVar1 + 0xaa) = (short)DAT_00005d30;
      *(undefined1 *)(iVar1 + 0xa9) = 0;
      FUN_00002db8(param_1,0x800);
      iVar1 = DAT_00005d38 + param_1 * 0x1cc;
      (**(code **)(*(int *)(iVar1 + 0x60) + 0x54))(param_1,pcVar3,DAT_00005d3c);
      FUN_000030f0(param_1,9,0x14);
      FUN_00002db8(param_1,0x100);
      *(undefined1 *)(iVar1 + 0x45) = 0x24;
      return;
    }
    if ((int)((uint)(byte)pcVar3[5] << 0x18) < 0) {
      pcVar2 = *(code **)(*(int *)(DAT_00005d38 + param_1 * 0x1cc + 0x60) + 0x58);
      (*pcVar2)(param_1,pcVar3,DAT_00005d40,pcVar2,param_4);
      return;
    }
    iVar1 = *(int *)(DAT_00005d38 + param_1 * 0x1cc + 0x60);
    if (pcVar3[1] == '\0') {
      pcVar2 = *(code **)(iVar1 + 0x60);
    }
    else {
      pcVar2 = *(code **)(iVar1 + 0x5c);
    }
    (*pcVar2)(param_1,pcVar3);
  }
  return;
}

