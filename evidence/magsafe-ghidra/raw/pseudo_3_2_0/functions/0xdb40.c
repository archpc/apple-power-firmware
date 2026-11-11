// rea decompile_all
// name: FUN_0000db40
// address: 0xdb40
// body: available
// range: 0xdb40-0xdf11 inclusive
// range: 0xdf30-0xe33d inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0000db40(char param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  ushort *puVar19;
  int iVar20;
  undefined4 *puVar21;
  undefined4 uVar22;
  undefined4 *local_50;
  ushort *local_48;
  uint local_38;
  ushort *local_2c;
  byte local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_18 [4];
  
  iVar4 = DAT_0000df24;
  puVar3 = DAT_0000df20;
  iVar11 = DAT_0000df18;
  iVar12 = DAT_0000df14;
  bVar5 = param_1 << 1;
  uVar16 = (uint)bVar5;
  iVar6 = DAT_0000df14 + uVar16 * 2;
  uVar15 = (uint)*(ushort *)(iVar6 + 0x20);
  puVar7 = (ushort *)(iVar6 + 0x20);
  iVar6 = DAT_0000df18 + uVar16;
  if (*(byte *)(iVar6 + 0x10) >> 4 < 0xd) {
    uVar9 = DAT_0000df1c;
    if (uVar15 != DAT_0000df1c) goto LAB_0000dc38;
LAB_0000dc72:
    uVar14 = (uint)*(byte *)(DAT_0000df24 + 0x26);
    iVar8 = DAT_0000df28 + 1;
    uVar9 = uVar14 * iVar8 + DAT_0000df28;
    local_38 = (uint)*(ushort *)(DAT_0000df24 + 0x32);
    uVar15 = DAT_0000df1c;
    if ((uVar9 & 0xffff) < local_38) {
      uVar15 = uVar14 + 1;
      *(char *)(DAT_0000df24 + 0x26) = (char)uVar15;
      if (1 < (uVar15 & 0xff)) {
        uVar15 = 0;
        *(undefined1 *)(iVar4 + 0x26) = 0;
        *(undefined2 *)(iVar4 + 0x32) = 0;
        local_38 = 0;
      }
      if ((iVar8 * (uVar15 & 0xff) + DAT_0000df28 & 0xffff) < local_38) {
        return 1;
      }
      *(ushort *)(iVar4 + 0x32) = (ushort)local_38 + 0x20;
      local_20 = 0x1f;
      iVar10 = FUN_00009fac((uVar9 - 0x1f & 0xffff) + 0x4000);
      if (iVar10 != 0) {
        return iVar10;
      }
      local_20 = 0x7f;
      iVar20 = local_38 + 0x4000;
      iVar10 = FUN_00009fac(iVar20,&local_20,1);
      iVar17 = 0;
      if (iVar10 != 0) {
        return -1;
      }
      iVar10 = DAT_0000df2c + 0x20;
      local_48 = (ushort *)(iVar12 + 0x20);
      local_50 = puVar3;
      while( true ) {
        if (iVar17 == 0x12) {
          return -1;
        }
        if ((uVar14 * iVar10 + DAT_0000df2c & 0xffff) == (uint)*local_48) break;
        local_48 = local_48 + 1;
        local_50 = local_50 + 1;
        iVar17 = iVar17 + 1;
      }
      local_2c = (ushort *)(iVar12 + 0x20);
      for (iVar12 = 0; iVar12 != 0x12; iVar12 = iVar12 + 1) {
        if ((iVar17 != iVar12) && (uVar15 = (uint)*local_2c, uVar15 != DAT_0000e344)) {
          uVar9 = (uint)*(byte *)(iVar4 + 0x26) * iVar10;
          if ((uVar15 < (uVar9 & 0xe000)) || ((DAT_0000e34c + uVar9 + 0x1f & 0xffff) < uVar15)) {
            uVar1 = *(ushort *)(iVar4 + 0x32);
            uVar9 = (uint)uVar1;
            if ((iVar8 * (uint)*(byte *)(iVar4 + 0x26) + DAT_0000e348 & 0xffff) < uVar9) {
              return -1;
            }
            *(ushort *)(iVar4 + 0x32) = uVar1 + 0x20;
            local_20 = 0x1f;
            iVar13 = FUN_00009fac(uVar15 + 0x4000,&local_20,1);
            if (iVar13 != 0) {
              return -1;
            }
            if (uVar9 == DAT_0000e344) {
              return -1;
            }
            uVar2 = *local_2c;
            local_18[0] = 0x7f;
            iVar13 = FUN_00009fac(uVar9 + 0x4000,local_18,1);
            if (iVar13 != 0) {
              return -1;
            }
            FUN_000001a0(&local_20,0xff);
            local_20 = (byte)iVar12;
            iVar13 = FUN_00009fac(&LAB_00004000_1 + uVar9,&local_20,5);
            if (iVar13 != 0) {
              return -1;
            }
            local_18[0] = 0x3f;
            iVar13 = FUN_00009fac(uVar9 + 0x4000,local_18,1);
            if (iVar13 != 0) {
              return -1;
            }
            local_20 = 7;
            iVar13 = FUN_00009fac(uVar2 + 0x4000,&local_20,1);
            if (iVar13 != 0) {
              return -1;
            }
            *local_2c = uVar1;
            *(undefined1 *)(iVar11 + iVar12 + 0x10) = 0;
          }
        }
        local_2c = local_2c + 1;
      }
      local_20 = 0x1f;
      iVar12 = FUN_00009fac(*local_48 + 0x4000,&local_20,1);
      if (iVar12 != 0) {
        return -1;
      }
      uVar22 = *local_50;
      uVar1 = *local_48;
      local_18[0] = 0x7f;
      iVar12 = FUN_00009fac(iVar20,local_18,1);
      if (iVar12 != 0) {
        return -1;
      }
      FUN_000001a0(&local_20,0xff);
      local_1c = (undefined1)((uint)uVar22 >> 0x18);
      local_1d = (undefined1)((uint)uVar22 >> 0x10);
      local_1e = (undefined1)((uint)uVar22 >> 8);
      local_1f = (undefined1)uVar22;
      local_20 = (byte)iVar17;
      iVar12 = FUN_00009fac(&LAB_00004000_1 + local_38,&local_20,5);
      if (iVar12 != 0) {
        return -1;
      }
      local_18[0] = 0x3f;
      iVar12 = FUN_00009fac(iVar20,local_18,1);
      if (iVar12 != 0) {
        return -1;
      }
      local_20 = 7;
      iVar12 = FUN_00009fac(uVar1 + 0x4000,&local_20,1);
      if (iVar12 != 0) {
        return -1;
      }
      *local_48 = (ushort)local_38;
      *(undefined1 *)(iVar11 + iVar17 + 0x10) = 0;
      if (2 < uVar14) {
        return -1;
      }
      iVar12 = FUN_0000a020(uVar14 * iVar10 + 0x4000,iVar10);
      if (iVar12 != 0) {
        return 1;
      }
      local_38 = (uint)*(ushort *)(iVar4 + 0x32);
      uVar15 = DAT_0000e344;
      if (((uint)*(byte *)(iVar4 + 0x26) * iVar8 + DAT_0000e348 & 0xffff) < local_38) {
        return 1;
      }
    }
    *puVar7 = (ushort)local_38;
    *(ushort *)(iVar4 + 0x32) = (ushort)local_38 + 0x20;
    if (local_38 == uVar15) {
      return -1;
    }
    uVar22 = puVar3[uVar16];
    local_18[0] = 0x7f;
    iVar12 = FUN_00009fac(local_38 + 0x4000);
    if (iVar12 != 0) {
      return iVar12;
    }
    FUN_000001a0(&local_20,0xff,5);
    local_1c = (undefined1)((uint)uVar22 >> 0x18);
    local_1d = (undefined1)((uint)uVar22 >> 0x10);
    local_1e = (undefined1)((uint)uVar22 >> 8);
    local_1f = (undefined1)uVar22;
    local_20 = bVar5;
    iVar12 = FUN_00009fac(&LAB_00004000_1 + local_38,&local_20,5);
    if (iVar12 != 0) {
      return -1;
    }
    local_18[0] = 0x3f;
    iVar11 = FUN_00009fac(local_38 + 0x4000,local_18,1);
    iVar12 = -1;
    uVar9 = DAT_0000df1c;
  }
  else {
    if (uVar15 == DAT_0000df1c) goto LAB_0000dc72;
    uVar18 = (uint)*(byte *)(DAT_0000df24 + 0x26);
    iVar8 = DAT_0000df28 + 1;
    uVar9 = uVar18 * iVar8 + DAT_0000df28;
    uVar1 = *(ushort *)(DAT_0000df24 + 0x32);
    uVar14 = (uint)uVar1;
    if (uVar14 <= (uVar9 & 0xffff)) {
      *(ushort *)(DAT_0000df24 + 0x32) = uVar1 + 0x20;
      local_20 = 0x1f;
      iVar12 = FUN_00009fac(uVar15 + 0x4000);
      if (iVar12 != 0) {
        return iVar12;
      }
      if (uVar14 == DAT_0000df1c) {
        return -1;
      }
      uVar22 = DAT_0000df20[uVar16];
      uVar2 = *puVar7;
      local_18[0] = 0x7f;
      iVar12 = FUN_00009fac(uVar14 + 0x4000,local_18,1);
      if (iVar12 != 0) {
        return -1;
      }
      FUN_000001a0(&local_20,0xff);
      local_1c = (undefined1)((uint)uVar22 >> 0x18);
      local_1d = (undefined1)((uint)uVar22 >> 0x10);
      local_1e = (undefined1)((uint)uVar22 >> 8);
      local_1f = (undefined1)uVar22;
      local_20 = bVar5;
      iVar12 = FUN_00009fac(&LAB_00004000_1 + uVar14,&local_20,5);
      if (iVar12 != 0) {
        return -1;
      }
      local_18[0] = 0x3f;
      iVar12 = FUN_00009fac(uVar14 + 0x4000,local_18,1);
      if (iVar12 != 0) {
        return -1;
      }
      local_20 = 7;
      iVar12 = FUN_00009fac(uVar2 + 0x4000,&local_20,1);
      uVar9 = DAT_0000df1c;
      if (iVar12 != 0) {
        return -1;
      }
      *puVar7 = uVar1;
      *(undefined1 *)(iVar6 + 0x10) = 0;
      goto LAB_0000dc38;
    }
    uVar15 = uVar18 + 1;
    *(char *)(DAT_0000df24 + 0x26) = (char)uVar15;
    if (1 < (uVar15 & 0xff)) {
      uVar15 = 0;
      *(undefined1 *)(iVar4 + 0x26) = 0;
      *(undefined2 *)(iVar4 + 0x32) = 0;
      uVar14 = 0;
    }
    if ((iVar8 * (uVar15 & 0xff) + DAT_0000df28 & 0xffff) < uVar14) {
      return 1;
    }
    *(ushort *)(iVar4 + 0x32) = (ushort)uVar14 + 0x20;
    local_20 = 0x1f;
    iVar10 = FUN_00009fac((uVar9 - 0x1f & 0xffff) + 0x4000);
    if (iVar10 != 0) {
      return iVar10;
    }
    local_20 = 0x7f;
    iVar20 = uVar14 + 0x4000;
    iVar10 = FUN_00009fac(iVar20,&local_20,1);
    iVar17 = 0;
    if (iVar10 != 0) {
      return -1;
    }
    iVar10 = DAT_0000df2c + 0x20;
    puVar19 = (ushort *)(iVar12 + 0x20);
    puVar21 = DAT_0000df20;
    while( true ) {
      if (iVar17 == 0x12) {
        return -1;
      }
      if ((uVar18 * iVar10 + DAT_0000df2c & 0xffff) == (uint)*puVar19) break;
      puVar19 = puVar19 + 1;
      puVar21 = puVar21 + 1;
      iVar17 = iVar17 + 1;
    }
    local_2c = (ushort *)(iVar12 + 0x20);
    iVar12 = 0;
    while( true ) {
      local_20 = 0x1f;
      if (iVar12 == 0x12) break;
      if ((iVar17 != iVar12) && (uVar15 = (uint)*local_2c, uVar15 != DAT_0000e344)) {
        uVar9 = (uint)*(byte *)(iVar4 + 0x26) * iVar10;
        if ((uVar15 < (uVar9 & 0xe000)) || ((DAT_0000e34c + uVar9 + 0x1f & 0xffff) < uVar15)) {
          uVar1 = *(ushort *)(iVar4 + 0x32);
          uVar9 = (uint)uVar1;
          if ((iVar8 * (uint)*(byte *)(iVar4 + 0x26) + DAT_0000e348 & 0xffff) < uVar9) {
            return -1;
          }
          *(ushort *)(iVar4 + 0x32) = uVar1 + 0x20;
          iVar13 = FUN_00009fac(uVar15 + 0x4000,&local_20,1);
          if (iVar13 != 0) {
            return -1;
          }
          if (uVar9 == DAT_0000e344) {
            return -1;
          }
          uVar2 = *local_2c;
          local_18[0] = 0x7f;
          iVar13 = FUN_00009fac(uVar9 + 0x4000,local_18,1);
          if (iVar13 != 0) {
            return -1;
          }
          FUN_000001a0(&local_20,0xff);
          local_20 = (byte)iVar12;
          iVar13 = FUN_00009fac(&LAB_00004000_1 + uVar9,&local_20,5);
          if (iVar13 != 0) {
            return -1;
          }
          local_18[0] = 0x3f;
          iVar13 = FUN_00009fac(uVar9 + 0x4000,local_18,1);
          if (iVar13 != 0) {
            return -1;
          }
          local_20 = 7;
          iVar13 = FUN_00009fac(uVar2 + 0x4000,&local_20,1);
          if (iVar13 != 0) {
            return -1;
          }
          *local_2c = uVar1;
          *(undefined1 *)(iVar11 + iVar12 + 0x10) = 0;
        }
      }
      local_2c = local_2c + 1;
      iVar12 = iVar12 + 1;
    }
    iVar12 = FUN_00009fac(*puVar19 + 0x4000,&local_20,1);
    if (iVar12 != 0) {
      return -1;
    }
    uVar22 = *puVar21;
    uVar1 = *puVar19;
    local_18[0] = 0x7f;
    iVar12 = FUN_00009fac(iVar20,local_18,1);
    if (iVar12 != 0) {
      return -1;
    }
    FUN_000001a0(&local_20,0xff);
    local_1c = (undefined1)((uint)uVar22 >> 0x18);
    local_1d = (undefined1)((uint)uVar22 >> 0x10);
    local_1e = (undefined1)((uint)uVar22 >> 8);
    local_1f = (undefined1)uVar22;
    local_20 = (byte)iVar17;
    iVar12 = FUN_00009fac(&LAB_00004000_1 + uVar14,&local_20,5);
    if (iVar12 != 0) {
      return -1;
    }
    local_18[0] = 0x3f;
    iVar12 = FUN_00009fac(iVar20,local_18,1);
    if (iVar12 != 0) {
      return -1;
    }
    local_20 = 7;
    iVar12 = FUN_00009fac(uVar1 + 0x4000,&local_20,1);
    if (iVar12 != 0) {
      return -1;
    }
    *puVar19 = (ushort)uVar14;
    *(undefined1 *)(iVar11 + iVar17 + 0x10) = 0;
    if (2 < uVar18) {
      return -1;
    }
    iVar11 = FUN_0000a020(uVar18 * iVar10 + 0x4000,iVar10);
    iVar12 = 1;
    uVar9 = DAT_0000e344;
  }
  if (iVar11 != 0) {
    return iVar12;
  }
LAB_0000dc38:
  puVar3[uVar16] = puVar3[uVar16] + 1;
  uVar16 = (uint)*(byte *)(iVar6 + 0x10);
  uVar14 = uVar16 + 1;
  *(char *)(iVar6 + 0x10) = (char)uVar14;
  uVar15 = (uint)*puVar7;
  if (uVar15 == uVar9) {
    return 1;
  }
  uVar9 = uVar14 & 0xff;
  iVar12 = 8 - uVar9;
  if (8 < uVar9) {
    iVar12 = 0;
  }
  uVar18 = 0xff;
  for (uVar14 = uVar14 - (iVar12 + uVar16 & 0x1f8); (uVar14 & 0xff) != 0; uVar14 = uVar14 - 1) {
    uVar18 = uVar18 >> 1;
  }
  uVar14 = (iVar12 + uVar16 & 0xff) >> 3;
  if (uVar9 - uVar16 != 1) {
    iVar12 = uVar16 - 8;
    if (uVar16 < 8) {
      iVar12 = 0;
    }
    uVar16 = (iVar12 + 7U & 0xff) >> 3;
    if (uVar14 != uVar16) {
      iVar12 = 0;
      while (iVar12 < (int)(uVar14 - uVar16)) {
        local_20 = 0;
        iVar11 = FUN_00009fac((uVar16 + iVar12 & 0xff) + (uint)*puVar7 + 0x4006,&local_20,1);
        iVar12 = iVar12 + 1;
        if (iVar11 != 0) {
          return iVar11;
        }
      }
      uVar15 = (uint)*puVar7;
    }
  }
  local_20 = (byte)uVar18;
  iVar12 = FUN_00009fac(uVar14 + uVar15 + 0x4006,&local_20,1);
  return iVar12;
}

