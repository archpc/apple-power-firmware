// rea decompile_all
// name: FUN_0000869c
// address: 0x869c
// body: available
// range: 0x869c-0x88bf inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined8 FUN_0000869c(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  byte *pbVar11;
  int local_20;
  
  iVar10 = DAT_000088c4 + param_1 * 0x1cc;
  local_20 = param_2;
  if (*(char *)(iVar10 + 0x31) == '\0') {
    uVar4 = 0;
    goto LAB_000087dc;
  }
  iVar8 = *(int *)(DAT_000088c8 + param_1 * 4);
  puVar7 = (uint *)(iVar8 + 0x124);
  puVar9 = (uint *)(iVar8 + 0xa4);
  if (*(char *)(iVar10 + 0x1c) == '\x01') {
    *(undefined4 *)(iVar8 + 0x11c) = 0x10;
    *(uint *)(iVar8 + 300) = *(uint *)(iVar8 + 300) | 0x10;
    if (*(char *)(iVar10 + 0x15) != '\x01') {
      *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) & 0xfffff0ff;
      *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) | 0xf00;
      *(undefined4 *)(iVar8 + 0x11c) = 0x60;
      *(uint *)(iVar8 + 300) = *(uint *)(iVar8 + 300) | 0x60;
      sVar1 = *(short *)(iVar10 + 0x3a);
      sVar3 = FUN_000088d4(param_1);
      if (sVar1 == sVar3) {
        FUN_00002d70(param_1);
        FUN_00002d54(param_1);
        return CONCAT44(param_2,(uint)*(ushort *)(DAT_000088cc + param_1 * 0x5c + 0x46));
      }
      goto LAB_000088a8;
    }
    if (*(char *)(iVar10 + 0x1f) != '\x04') {
      *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) & 0xfffffcff;
      *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) | 0x200;
      uVar4 = 0x20;
      *(undefined4 *)(iVar8 + 0x11c) = 0x20;
      *(uint *)(iVar8 + 300) = *(uint *)(iVar8 + 300) | 0x20;
      if (-1 < (int)(*puVar9 << 0xe)) goto LAB_000087dc;
      uVar6 = *puVar7;
      goto LAB_000088ac;
    }
    uVar5 = 1;
  }
  else {
    if (*(char *)(iVar10 + 0x15) == '\x01') {
      *(uint *)(iVar8 + 0x18c) = *(uint *)(iVar8 + 0x18c) & 0xfffffeff;
      *(uint *)(iVar8 + 0x18c) = *(uint *)(iVar8 + 0x18c) | 0x10;
      uVar6 = DAT_000088c0 + 0x20;
      *(uint *)(iVar8 + 0x18c) = *(uint *)(iVar8 + 0x18c) & uVar6;
      iVar2 = DAT_000088d0;
      local_20 = DAT_000088d0;
      uVar4 = (uint)*(byte *)(DAT_000088d0 + (uint)*(byte *)(iVar10 + 0x35) * 4);
      *(uint *)(iVar8 + 0x18c) = uVar4 << 9 | *(uint *)(iVar8 + 0x18c) | uVar4 << 5;
      FUN_00000b80();
      uVar4 = *puVar9 & 0x40000;
      pbVar11 = (byte *)(iVar10 + 0x35);
      if ((int)(*puVar9 << 0xe) < 0) {
        if (uVar4 != 0) goto LAB_0000885e;
        *(uint *)(iVar8 + 0x18c) = *(uint *)(iVar8 + 0x18c) & 0xfffff1ff;
        *(uint *)(iVar8 + 0x18c) =
             *(uint *)(iVar8 + 0x18c) | (uint)*(byte *)(iVar2 + (uint)*pbVar11 * 4 + 1) << 9;
        *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) & DAT_000088c0;
        *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) | 0x900;
        FUN_00000b80(0x1e0);
        *(undefined4 *)(iVar8 + 0x11c) = 0x70;
        *(uint *)(iVar8 + 300) = *(uint *)(iVar8 + 300) | 0x60;
        if ((*puVar9 & 0x20000) == 0) goto LAB_000088a8;
        uVar4 = *puVar9;
        if ((uVar4 & 0x40000) == 0) goto LAB_000087dc;
LAB_000088ba:
        uVar4 = *puVar7;
        uVar6 = 0x40;
      }
      else {
        if (uVar4 == 0) {
LAB_0000885e:
          *(uint *)(iVar8 + 0x18c) = *(uint *)(iVar8 + 0x18c) & uVar6;
          uVar4 = (uint)*(byte *)(iVar2 + (uint)*pbVar11 * 4 + 1);
          *(uint *)(iVar8 + 0x18c) = uVar4 << 9 | *(uint *)(iVar8 + 0x18c) | uVar4 << 5;
          *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) & DAT_000088c0;
          *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) | 0x500;
          FUN_00000b80(0x1e0);
          *(undefined4 *)(iVar8 + 0x11c) = 0x70;
          *(uint *)(iVar8 + 300) = *(uint *)(iVar8 + 300) | 0x60;
          if ((*puVar9 & 0x20000) != 0) {
            uVar4 = *puVar9;
joined_r0x0000878e:
            if ((uVar4 & 0x40000) != 0) goto LAB_000087dc;
            goto LAB_000088ba;
          }
        }
        else {
          *(uint *)(iVar8 + 0x18c) = *(uint *)(iVar8 + 0x18c) & 0xffffff1f;
          *(uint *)(iVar8 + 0x18c) =
               *(uint *)(iVar8 + 0x18c) | (uint)*(byte *)(iVar2 + (uint)*pbVar11 * 4 + 1) << 5;
          *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) & DAT_000088c0;
          *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) | 0x600;
          FUN_00000b80(0x1e0);
          *(undefined4 *)(iVar8 + 0x11c) = 0x70;
          *(uint *)(iVar8 + 300) = *(uint *)(iVar8 + 300) | 0x60;
          if ((*puVar9 & 0x20000) == 0) {
            uVar4 = *puVar9;
            goto joined_r0x0000878e;
          }
        }
LAB_000088a8:
        uVar4 = *puVar7;
        uVar6 = 0x20;
      }
LAB_000088ac:
      *puVar7 = uVar6 | uVar4;
      return CONCAT44(local_20,uVar4);
    }
    uVar5 = 0;
  }
  uVar4 = FUN_000085f8(param_1,uVar5);
LAB_000087dc:
  return CONCAT44(local_20,uVar4);
}

