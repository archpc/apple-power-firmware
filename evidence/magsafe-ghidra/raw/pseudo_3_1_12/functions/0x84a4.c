// rea decompile_all
// name: FUN_000084a4
// address: 0x84a4
// body: available
// range: 0x84a4-0x8537 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000084a4(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(DAT_0000853c + param_1 * 4);
  if (param_2 == 0) {
    uVar2 = 3;
  }
  else {
    uVar2 = (uint)*(byte *)(DAT_00008540 + param_1 * 0x1cc + 0x35);
  }
  *(uint *)(iVar3 + 0x18c) = *(uint *)(iVar3 + 0x18c) & 0xfffffeff;
  *(uint *)(iVar3 + 0x18c) = *(uint *)(iVar3 + 0x18c) | 0x10;
  uVar1 = DAT_00008538;
  *(uint *)(iVar3 + 0x18c) = *(uint *)(iVar3 + 0x18c) & DAT_00008538 + 0x20;
  uVar2 = (uint)*(byte *)(DAT_00008544 + uVar2 * 4);
  *(uint *)(iVar3 + 0x18c) = uVar2 << 9 | *(uint *)(iVar3 + 0x18c) | uVar2 << 5;
  *(uint *)(iVar3 + 0x114) = *(uint *)(iVar3 + 0x114) & uVar1;
  *(uint *)(iVar3 + 0x114) = *(uint *)(iVar3 + 0x114) | 0xa00;
  FUN_00000b60(0x3c0);
  *(undefined4 *)(iVar3 + 0x11c) = 0x70;
  *(uint *)(iVar3 + 300) = *(uint *)(iVar3 + 300) | 0x60;
  if (*(int *)(iVar3 + 0xa4) << 0xe < 0) {
    uVar2 = 0x20;
  }
  else {
    if (-1 < *(int *)(iVar3 + 0xa4) << 0xd) {
      return;
    }
    uVar2 = 0x40;
  }
  *(uint *)(iVar3 + 0x124) = *(uint *)(iVar3 + 0x124) | uVar2;
  return;
}

