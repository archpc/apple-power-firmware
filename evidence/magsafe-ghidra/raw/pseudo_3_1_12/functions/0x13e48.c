// rea decompile_all
// name: FUN_00013e48
// address: 0x13e48
// body: available
// range: 0x13e48-0x141b1 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00013e48(void)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  int local_1ac [3];
  uint local_1a0;
  int local_130;
  uint local_12c [2];
  undefined1 auStack_124 [8];
  int local_11c;
  int local_118;
  int local_30;
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  *DAT_000141b4 = 0x2000;
  *DAT_000141b8 = DAT_000141bc;
  *DAT_000141c0 = 2;
  FUN_00014260(0x17);
  FUN_00014260(0x21,1);
  puVar2 = DAT_000141c4;
  *DAT_000141c4 = 0xc;
  *puVar2 = DAT_000141c8 | *puVar2;
  puVar2[0x10] = 0;
  puVar2[0x12] = 0xa0000;
  *DAT_000141cc = 0x80000007;
  puVar2[0x11] = 1;
  puVar3 = DAT_000141d0;
  *DAT_000141d0 = 0x80000007;
  puVar3[1] = 4;
  puVar2[0x14] = 4;
  puVar3 = DAT_000141d4;
  *DAT_000141d4 = 0;
  puVar3[0x10] = 0;
  puVar3 = DAT_000141d8;
  DAT_000141d8[0x10] = 0;
  *puVar3 = 0;
  puVar3 = DAT_000141dc;
  DAT_000141dc[0x10] = 0;
  *puVar3 = 0;
  *puVar2 = *puVar2 | 0x80000000;
  *DAT_000141e0 = DAT_000141e4;
  *DAT_000141e8 = 0xffffffff;
  FUN_00013e24(DAT_000141ec);
  (*(code *)&SUB_ce10e000)(local_12c,0x1000,0x100);
  iVar6 = (*(code *)&SUB_36086834)(local_12c,0xfc);
  if (iVar6 != local_30) {
LAB_00014132:
    puVar3 = DAT_0001420c;
    *DAT_0001420c = 6;
    FUN_00014238();
    *puVar3 = 0x20;
    *puVar3 = 0;
    *puVar3 = 0x10;
    *puVar3 = 0;
    FUN_00014238();
    puVar2 = DAT_00014214;
    uVar10 = DAT_00014210;
    while( true ) {
      *puVar2 = *puVar2 | uVar10 + 5;
      *puVar2 = *puVar2 & 0xfffeffff;
      *puVar3 = 5;
      *puVar3 = 0;
      FUN_00014238();
      if ((puVar2[0xf] & 1) == 0) break;
      FUN_00013e24(0x1e0);
    }
    *DAT_00014218 = 0x80000000;
    FUN_00013e24(0x12c0);
    *DAT_0001421c = *DAT_0001421c | 0x300000;
    FUN_00013e24(DAT_00014220);
    *DAT_00014224 = DAT_00014228 | *DAT_00014224 & uVar10;
    return;
  }
  iVar6 = 0x20000;
  if (local_118 != 0) {
    iVar6 = local_11c;
  }
  iVar16 = iVar6 + 0x100;
  iVar7 = 0;
LAB_00013f20:
  if (iVar7 != 4) {
    (*(code *)&SUB_ce10e000)(local_1ac,iVar16,0x80);
    iVar13 = local_130;
    iVar8 = (*(code *)&SUB_36086834)(local_1ac,0x7c);
    iVar17 = DAT_0001422c;
    if (iVar8 == iVar13) {
      FUN_00014420(DAT_0001422c,iVar16,local_1ac[0] + 0x80);
      for (iVar13 = 0; iVar13 != 4; iVar13 = iVar13 + 1) {
        (*(code *)&SUB_ce10e000)(local_12c,iVar6 + 8 + iVar13 * 0x24);
        iVar8 = 0;
        do {
          if (iVar8 + 4 == 0x24) {
            if (local_1a0 >> 0x18 != 0) goto LAB_00014124;
            uVar10 = local_1ac[0] + local_1a0;
            uVar15 = local_1a0 - 0x80;
            iVar17 = iVar16;
            goto LAB_00013f9c;
          }
          iVar1 = iVar8 + -4;
          iVar9 = iVar17 + iVar8;
          iVar8 = iVar8 + 4;
        } while (*(int *)(iVar9 + 0x48) == *(int *)(auStack_124 + iVar1));
      }
    }
  }
  goto LAB_00014132;
LAB_00013f9c:
  uVar5 = DAT_00014230;
  if (uVar10 <= uVar15) goto LAB_00014124;
  (*(code *)&SUB_ce10e000)(DAT_00014230,iVar17,0x100);
  iVar13 = FUN_00013e06(uVar5,uVar15,0x100);
  if (iVar13 != 0) {
    uVar14 = 0;
    local_20 = 0;
    local_24 = 0;
    if (uVar15 < 0x20000) {
      FUN_00013dc4(auStack_124,DAT_00014230,0x100);
      puVar2 = DAT_000141f0;
      local_12c[0] = DAT_000141f8;
      local_12c[1] = 0xff;
      *DAT_000141f0 = (uint)local_12c;
      puVar12 = puVar2 + -1;
      *puVar12 = 0x80000004;
      uVar11 = *puVar2;
      if (DAT_000141f4 < *puVar2) {
LAB_0001400a:
        uVar14 = uVar11 & 0xff;
      }
      else if ((uVar11 & DAT_000141f4 + 1) != 0xa0000000) {
        uVar11 = *DAT_000141f0;
        goto LAB_0001400a;
      }
      local_20 = uVar14;
      if (uVar14 == 0) {
        FUN_00013e38();
        local_18 = DAT_00014234;
        puVar2 = DAT_000141f0;
        local_1c = DAT_000141fc;
        *DAT_000141f0 = (uint)&local_1c;
        *puVar12 = 0x80000016;
        puVar4 = DAT_000141f0;
        local_24 = *puVar2;
        if (DAT_000141f4 < *puVar2) {
LAB_00014054:
          local_24 = local_24 & 0xff;
        }
        else {
          if ((local_24 & DAT_000141f4 + 1) != 0xa0000000) {
            local_24 = *DAT_000141f0;
            goto LAB_00014054;
          }
          local_24 = 0;
        }
        if (local_24 == 0) {
          *DAT_000141f0 = DAT_00014200;
          *puVar12 = 0x80000015;
          local_20 = *puVar4;
          if (*puVar4 <= DAT_000141f4) {
            if ((local_20 & DAT_000141f4 + 1) == 0xa0000000) {
              local_20 = 0;
              goto LAB_0001408e;
            }
            local_20 = *DAT_000141f0;
          }
          local_20 = local_20 & 0xff;
        }
LAB_0001408e:
        puVar2 = DAT_000141f0;
        if (local_20 == 0) {
          local_12c[0] = DAT_00014204 | (uVar15 >> 8) << 0x10;
          *DAT_000141f0 = (uint)local_12c;
          *puVar12 = 0x80000005;
          local_20 = *puVar2;
          if (*puVar2 <= DAT_000141f4) {
            if ((local_20 & DAT_000141f4 + 1) == 0xa0000000) {
              local_20 = 0;
              goto LAB_000140d2;
            }
            local_20 = *DAT_000141f0;
          }
          local_20 = local_20 & 0xff;
        }
LAB_000140d2:
        puVar2 = DAT_000141f0;
        if (local_24 == 0) {
          local_1c = DAT_00014208;
          *DAT_000141f0 = (uint)&local_1c;
          *puVar12 = 0x80000017;
          local_24 = *puVar2;
          if (DAT_000141f4 < *puVar2) {
LAB_0001410a:
            local_24 = local_24 & 0xff;
          }
          else {
            if ((local_24 & DAT_000141f4 + 1) != 0xa0000000) {
              local_24 = *DAT_000141f0;
              goto LAB_0001410a;
            }
            local_24 = 0;
          }
          if (local_24 != 0) {
            local_20 = local_24;
          }
        }
        FUN_00013e40();
      }
    }
    else {
      local_20 = 4;
    }
  }
  iVar17 = iVar17 + 0x100;
  uVar15 = uVar15 + 0x100;
  goto LAB_00013f9c;
LAB_00014124:
  iVar16 = iVar16 + local_1ac[0] + 0x80;
  iVar7 = iVar7 + 1;
  goto LAB_00013f20;
}

