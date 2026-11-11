// rea decompile_all
// name: FUN_00006d00
// address: 0x6d00
// body: available
// range: 0x6d00-0x6dc7 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00006d00(uint param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = DAT_00006ddc;
  if (1 < param_1) {
    return;
  }
  bVar1 = *(byte *)(DAT_00006ddc + param_1 * 0x1cc + 0x3e);
  iVar6 = *(int *)(DAT_00006de0 + param_1 * 4);
  if (bVar1 < 2) {
    *(uint *)(iVar6 + 0x144) = *(uint *)(iVar6 + 0x144) & DAT_00006dcc;
    *(uint *)(iVar6 + 4) = *(uint *)(iVar6 + 4) & 0xfffffffc;
  }
  else {
    *(uint *)(iVar6 + 0x144) = *(uint *)(iVar6 + 0x144) | DAT_00006dd0;
  }
  uVar3 = *(uint *)(iVar6 + 0xe4) & DAT_00006dc8;
  iVar2 = iVar2 + param_1 * 0x1cc;
  if (*(char *)(iVar2 + 0x10) != '\x02') {
    uVar4 = (int)&PTR_caseD_11_00006100 + uVar3;
    if (*(char *)(iVar2 + 0x10) != '\x01') goto LAB_00006da8;
    if (*(char *)(iVar2 + 0x20) != '\0') {
      if (bVar1 < 2) {
        if (*(char *)(iVar2 + 0x14) != '\x01') goto LAB_00006da8;
      }
      else if (*(char *)(iVar2 + 0x28) == '\0') goto LAB_00006da8;
      if (*(char *)(iVar2 + 0x24) == '\0') {
        iVar5 = 99;
      }
      else {
        iVar5 = 0x67;
      }
      uVar4 = iVar5 << 8 | uVar3;
      goto LAB_00006da8;
    }
    if ((*(char *)(iVar2 + 0x15) != '\x01') || ((1 < bVar1 && (*(char *)(iVar2 + 0x28) == '\0'))))
    goto LAB_00006da8;
  }
  uVar4 = uVar3 | 0x6300;
LAB_00006da8:
  *(uint *)(iVar6 + 0xe4) = uVar4;
  *(uint *)(iVar6 + 0xf4) =
       (uint)*(byte *)(iVar2 + 0x14) << 5 |
       (DAT_00006dd4 & *(uint *)(iVar6 + 0xf4)) + (uint)*(byte *)(iVar2 + 0x15) * 0x100 | 0x41;
  *(undefined4 *)(iVar6 + 0xf0) = DAT_00006dd8;
  return;
}

