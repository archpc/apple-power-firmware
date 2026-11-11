// rea decompile_all
// name: FUN_00002bec
// address: 0x2bec
// body: available
// range: 0x2bec-0x2d39 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00002bec(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar7 = 0;
  FUN_0000a4e8(0);
  iVar2 = param_1 * 0x1cc + DAT_00002d50;
  puVar6 = (uint *)(iVar2 + 0x9c);
  uVar1 = 0;
  uVar5 = 0;
  do {
    if (uVar5 == 7) {
      if (uVar7 < 7) {
        puVar4 = (undefined4 *)(iVar2 + uVar7 * 4 + 0x9c);
        for (uVar5 = uVar7; uVar5 < 7; uVar5 = uVar5 + 1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
      }
      *(undefined1 *)(iVar2 + 0x15b) = uVar1;
      *(char *)(iVar2 + 0x29) = (char)uVar7;
      uVar5 = DAT_00002d48;
      if (1 < *(byte *)(iVar2 + 0x3e)) {
        uVar5 = DAT_00002d4c;
      }
      *(uint *)(iVar2 + 0x9c) =
           (uint)(*(byte *)(iVar2 + 10) >> 7) * 0x8000000 + (*(uint *)(iVar2 + 0x9c) & 0xf7ffffff) &
           uVar5;
      return;
    }
    if (((*(byte *)(iVar2 + 10) >> (uVar5 & 0xff) & 1) != 0) &&
       ((uVar3 = *puVar6, 1 < *(byte *)(iVar2 + 0x3e) || (uVar3 >> 0x1e < 3)))) {
      uVar8 = uVar3 >> 0x1e;
      uVar9 = uVar3;
      if (uVar8 == 2) {
        if (500 < (uVar3 & 0x3ff)) {
          uVar9 = uVar3 & DAT_00002d3c | 500;
LAB_00002c7a:
          uVar1 = 1;
        }
      }
      else if (uVar8 == 1) {
        uVar8 = (uVar3 >> 10 & 0x3ff) * 1000;
        if (uVar8 < (uVar3 & 0x3ff)) {
          uVar1 = 1;
          uVar9 = uVar8 & 0x3f8 | uVar3 & DAT_00002d3c;
        }
      }
      else if (uVar8 == 0) {
        if (500 < (uVar3 & 0x3ff)) {
          uVar9 = (uVar3 & DAT_00002d44) + 500;
          goto LAB_00002c7a;
        }
        uVar8 = (uVar3 & 0x3ff) * 0x6e;
        if (DAT_00002d40 <= uVar8 && uVar8 - DAT_00002d40 != 0) {
          uVar9 = uVar3 & 0xffcfffff;
        }
        if ((uVar3 & 0x3fffff) >> 0x14 == 0) {
          uVar9 = uVar3;
        }
      }
      *(uint *)(iVar2 + uVar7 * 4 + 0x9c) = uVar9;
      uVar7 = uVar7 + 1;
    }
    puVar6 = puVar6 + 1;
    uVar5 = uVar5 + 1;
  } while( true );
}

