// rea decompile_all
// name: FUN_0000669c
// address: 0x669c
// body: available
// range: 0x669c-0x6739 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000669c(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  *(undefined1 *)(DAT_00006740 + param_1 * 0xf0 + 0xa5) = 0;
  iVar2 = DAT_00006744 + param_1 * 0x1cc;
  *(undefined1 *)(iVar2 + 0x15b) = 0;
  *(undefined4 *)(iVar2 + 0x104) = 0;
  *(undefined1 *)(iVar2 + 0x19) = 0;
  if (param_1 < 2) {
    for (; uVar3 != 3; uVar3 = uVar3 + 1) {
      FUN_00006dc0(param_1,uVar3 & 0xff);
    }
    iVar1 = DAT_00006748 + param_1 * 0x88;
    *(undefined4 *)(iVar1 + 0x80) = 0;
    *(undefined1 *)(iVar1 + 0x84) = 0;
    *(undefined1 *)(iVar1 + 0x7c) = 0;
    *(undefined1 *)(iVar1 + 0x73) = 0;
  }
  FUN_00006de4(param_1);
  *(undefined1 *)(DAT_0000674c + param_1 * 0x5c + 0x55) = 0;
  uVar3 = DAT_0000673c;
  iVar1 = *(int *)(DAT_00006750 + param_1 * 4);
  *(uint *)(iVar1 + 0x118) = DAT_0000673c + 0x7f;
  *(undefined4 *)(iVar1 + 0x14c) = 0xe00;
  if (1 < *(byte *)(iVar2 + 0x3e)) {
    *(uint *)(iVar1 + 0x154) = *(uint *)(iVar1 + 0x154) | 0x200;
  }
  *(uint *)(iVar1 + 0x128) = *(uint *)(iVar1 + 0x128) | uVar3;
  return;
}

