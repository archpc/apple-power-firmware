// rea decompile_all
// name: FUN_00006de4
// address: 0x6de4
// body: available
// range: 0x6de4-0x6eab inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00006de4(uint param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = DAT_00006ec0;
  if (1 < param_1) {
    return;
  }
  bVar1 = *(byte *)(DAT_00006ec0 + param_1 * 0x1cc + 0x3e);
  iVar6 = *(int *)(DAT_00006ec4 + param_1 * 4);
  if (bVar1 < 2) {
    *(uint *)(iVar6 + 0x144) = *(uint *)(iVar6 + 0x144) & DAT_00006eb0;
    *(uint *)(iVar6 + 4) = *(uint *)(iVar6 + 4) & 0xfffffffc;
  }
  else {
    *(uint *)(iVar6 + 0x144) = *(uint *)(iVar6 + 0x144) | DAT_00006eb4;
  }
  uVar3 = *(uint *)(iVar6 + 0xe4) & DAT_00006eac;
  iVar2 = iVar2 + param_1 * 0x1cc;
  if (*(char *)(iVar2 + 0x10) != '\x02') {
    uVar4 = uVar3 + 0x6100;
    if (*(char *)(iVar2 + 0x10) != '\x01') goto LAB_00006e8c;
    if (*(char *)(iVar2 + 0x20) != '\0') {
      if (bVar1 < 2) {
        if (*(char *)(iVar2 + 0x14) != '\x01') goto LAB_00006e8c;
      }
      else if (*(char *)(iVar2 + 0x28) == '\0') goto LAB_00006e8c;
      if (*(char *)(iVar2 + 0x24) == '\0') {
        iVar5 = 99;
      }
      else {
        iVar5 = 0x67;
      }
      uVar4 = iVar5 << 8 | uVar3;
      goto LAB_00006e8c;
    }
    if ((*(char *)(iVar2 + 0x15) != '\x01') || ((1 < bVar1 && (*(char *)(iVar2 + 0x28) == '\0'))))
    goto LAB_00006e8c;
  }
  uVar4 = uVar3 | 0x6300;
LAB_00006e8c:
  *(uint *)(iVar6 + 0xe4) = uVar4;
  *(uint *)(iVar6 + 0xf4) =
       (uint)*(byte *)(iVar2 + 0x14) << 5 |
       (DAT_00006eb8 & *(uint *)(iVar6 + 0xf4)) + (uint)*(byte *)(iVar2 + 0x15) * 0x100 | 0x41;
  *(undefined4 *)(iVar6 + 0xf0) = DAT_00006ebc;
  return;
}

