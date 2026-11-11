// rea decompile_all
// name: FUN_00002a5c
// address: 0x2a5c
// body: available
// range: 0x2a5c-0x2bdd inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined8 FUN_00002a5c(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined1 uVar9;
  
  if (param_1 < 2) {
    uVar4 = param_2 >> 0x1c & 7;
    uVar5 = 0xc;
    if (((int)param_2 < 0) || (uVar4 != 0)) {
      if ((int)param_2 < 0) {
        iVar8 = 0x179;
      }
      else {
        iVar8 = 0x29;
      }
      if (uVar4 <= *(byte *)(DAT_00002be8 + param_1 * 0x1cc + iVar8)) {
        iVar8 = DAT_00002be8 + param_1 * 0x1cc;
        if ((int)param_2 < 0) {
          uVar4 = param_2 >> 0x1c | 8;
        }
        uVar4 = uVar4 - 1;
        uVar3 = *(uint *)(iVar8 + uVar4 * 4 + 0x9c);
        if (uVar3 >> 0x1e < 3) {
          uVar4 = param_2;
          if ((param_2 & 0xfffffff) >> 0x1a != 0) {
            uVar4 = param_2 >> 10;
          }
          if ((uVar3 & 0x3ff) < (uVar4 & 0x3ff)) {
            uVar5 = 0xc;
            goto LAB_00002b62;
          }
        }
        else {
          if (*(byte *)(iVar8 + 0x3e) < 2) {
            (*(code *)**(undefined4 **)(iVar8 + 0x60))
                      (param_1,0x3a,0,(code *)**(undefined4 **)(iVar8 + 0x60),param_2,param_3,
                       param_4);
            goto LAB_00002b62;
          }
          uVar9 = 1;
          if (((uVar3 & 0x30000000) == 0x10000000) && ((param_2 & 0x600) == 0)) {
            uVar4 = *(uint *)(iVar8 + (uVar4 & 0xff) * 4 + 0x9c);
            uVar3 = (param_2 & 0x1fffff) >> 9;
            if (((uVar3 < (uVar4 >> 6 & 0x3fc)) || ((DAT_00002be0 & uVar4 >> 0xf) < uVar3)) ||
               (uVar6 = (param_2 & 0x7f) * 5, 500 < uVar6)) goto LAB_00002b62;
            iVar1 = FUN_0000089c((uVar4 & 0xff) * DAT_00002be4,uVar3 * 0x19);
            iVar2 = FUN_00000964(iVar1,5);
            if ((uint)(iVar1 - iVar2) <= uVar6 && uVar6 - (iVar1 - iVar2) != 0) goto LAB_00002b62;
            *(undefined1 *)(iVar8 + 0x177) = uVar9;
          }
          else {
            if (((uVar3 & 0x30000000) != 0x20000000) || ((param_2 & 0x600) != 0)) goto LAB_00002b62;
            uVar4 = *(uint *)(iVar8 + (uVar4 & 0xff) * 4 + 0x9c);
            uVar3 = uVar4 & 0x3ff;
            uVar6 = 600;
            if (uVar3 != 0) {
              uVar6 = 800;
            }
            uVar7 = (param_2 & 0x1fffff) >> 9;
            if (uVar7 < 600) {
              if (uVar7 < 0x168) goto LAB_00002b62;
              uVar4 = uVar4 >> 10 & 0x3ff;
            }
            else if ((uVar7 != 600) || (uVar4 = uVar4 >> 10 & 0x3ff, uVar4 <= uVar3)) {
              uVar4 = uVar3;
            }
            if (((uVar6 < uVar7) || (uVar3 = (param_2 & 0x7f) * 5, 500 < uVar3)) ||
               (iVar8 = FUN_00000964(uVar4,5),
               uVar4 - iVar8 <= uVar3 && uVar3 - (uVar4 - iVar8) != 0)) goto LAB_00002b62;
          }
        }
        uVar5 = 0;
      }
    }
  }
  else {
    uVar5 = 2;
  }
LAB_00002b62:
  return CONCAT44(param_2,uVar5);
}

