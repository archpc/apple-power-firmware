// rea decompile_all
// name: FUN_00002b28
// address: 0x2b28
// body: available
// range: 0x2b28-0x2c65 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00002b28(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint local_18;
  
  FUN_0000a500(0);
  iVar3 = DAT_00002c7c + param_1 * 0x1cc;
  puVar4 = (uint *)(iVar3 + 0x9c);
  uVar1 = 0;
  local_18 = 0;
  uVar6 = 0;
  do {
    if (uVar6 == 7) {
      if (local_18 < 7) {
        puVar5 = (undefined4 *)(iVar3 + local_18 * 4 + 0x9c);
        for (iVar7 = local_18 - 7; iVar7 != 0; iVar7 = iVar7 + 1) {
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
        }
      }
      *(undefined1 *)(iVar3 + 0x15b) = uVar1;
      *(char *)(iVar3 + 0x29) = (char)local_18;
      uVar6 = DAT_00002c74;
      if (1 < *(byte *)(iVar3 + 0x3e)) {
        uVar6 = switchD_000026c4::caseD_2;
      }
      *(uint *)(iVar3 + 0x9c) =
           (uint)(*(byte *)(iVar3 + 10) >> 7) * 0x8000000 + (*(uint *)(iVar3 + 0x9c) & 0xf6bfffff) &
           uVar6;
      return;
    }
    if ((*(byte *)(iVar3 + 10) >> (uVar6 & 0xff) & 1) != 0) {
      uVar8 = *puVar4;
      uVar9 = uVar8 >> 0x1e;
      if ((uVar9 < 3) || (1 < *(byte *)(iVar3 + 0x3e))) {
        if (uVar9 == 2) {
          if ((uVar8 & 0x3ff) < 0x1f5) goto LAB_00002bf2;
          uVar9 = uVar8 & DAT_00002c68 | 500;
LAB_00002bd0:
          uVar1 = 1;
        }
        else {
          if (uVar9 == 1) {
            uVar9 = (uVar8 >> 10 & 0x3ff) * 1000;
            if (uVar9 < (uVar8 & 0x3ff)) {
              uVar9 = uVar9 & 0x3f8 | uVar8 & DAT_00002c68;
              goto LAB_00002bd0;
            }
          }
          else if (uVar9 == 0) {
            if (500 < (uVar8 & 0x3ff)) {
              uVar9 = (uVar8 & DAT_00002c70) + 500;
              goto LAB_00002bd0;
            }
            uVar2 = (uVar8 & 0x3ff) * 0x6e;
            uVar9 = uVar8;
            if (DAT_00002c6c <= uVar2 && uVar2 - DAT_00002c6c != 0) {
              uVar9 = uVar8 & 0xffcfffff;
            }
            if ((uVar8 & 0x3fffff) >> 0x14 != 0) goto LAB_00002bf4;
          }
LAB_00002bf2:
          uVar9 = uVar8;
        }
LAB_00002bf4:
        *(uint *)(iVar3 + local_18 * 4 + 0x9c) = uVar9;
        local_18 = local_18 + 1;
      }
    }
    puVar4 = puVar4 + 1;
    uVar6 = uVar6 + 1;
  } while( true );
}

