// rea decompile_all
// name: FUN_0000d904
// address: 0xd904
// body: available
// range: 0xd904-0xdc47 inclusive
// range: 0xdc64-0xe059 inclusive
// range: 0xe068-0xe10b inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0000d904(char param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  ushort *puVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  ushort *puVar23;
  undefined4 uVar24;
  byte bVar25;
  undefined4 *local_44;
  ushort *local_24;
  byte local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_18 [4];
  
  iVar4 = DAT_0000dc58;
  iVar10 = DAT_0000dc54;
  puVar3 = DAT_0000dc50;
  uVar17 = DAT_0000dc4c;
  iVar9 = DAT_0000dc48;
  bVar5 = param_1 << 1;
  uVar13 = (uint)bVar5;
  iVar21 = DAT_0000dc48 + uVar13;
  if (*(byte *)(iVar21 + 0x10) >> 4 < 0xd) {
    iVar11 = DAT_0000dc54 + uVar13 * 2;
    local_24 = (ushort *)(iVar11 + 0x20);
    if (*(ushort *)(iVar11 + 0x20) != DAT_0000dc4c) goto LAB_0000da08;
LAB_0000da40:
    iVar11 = DAT_0000dc5c + 1;
    uVar19 = (uint)*(byte *)(DAT_0000dc58 + 0x1e);
    uVar6 = (uint)*(ushort *)(DAT_0000dc58 + 0x34);
    if ((uVar19 * iVar11 + DAT_0000dc5c & 0xffff) < uVar6) {
      uVar16 = uVar19 + 1;
      *(char *)(DAT_0000dc58 + 0x1e) = (char)uVar16;
      if (1 < (uVar16 & 0xff)) {
        uVar16 = 0;
        *(undefined2 *)(iVar4 + 0x34) = 0;
        *(undefined1 *)(iVar4 + 0x1e) = 0;
        uVar6 = 0;
      }
      if ((iVar11 * (uVar16 & 0xff) + DAT_0000dc5c & 0xffff) < uVar6) {
        return 1;
      }
      *(ushort *)(iVar4 + 0x34) = (ushort)uVar6 + 0x20;
      local_20 = 0x1f;
      iVar22 = DAT_0000dc60 + 0x20;
      uVar16 = uVar19 * iVar22 + DAT_0000dc60 & 0xffff;
      iVar7 = FUN_00009fa4(uVar16 + 0x4000);
      if (iVar7 != 0) {
        return -1;
      }
      local_20 = 0x7f;
      iVar20 = uVar6 + 0x4000;
      iVar7 = FUN_00009fa4(iVar20,&local_20,1);
      if (iVar7 != 0) {
        return -1;
      }
      puVar23 = (ushort *)(iVar10 + 0x20);
      local_44 = puVar3;
      uVar18 = 0;
      while( true ) {
        if (uVar18 == 0x12) {
          return -1;
        }
        if (uVar16 == *puVar23) break;
        puVar23 = puVar23 + 1;
        local_44 = local_44 + 1;
        uVar18 = uVar18 + 1;
      }
      if ((uVar18 & 0xff) == 0x12) {
        return -1;
      }
      puVar12 = (ushort *)(iVar10 + 0x20);
      uVar24 = 7;
      uVar16 = 0;
      while( true ) {
        local_20 = 0x1f;
        if (uVar16 == 0x12) break;
        if ((uVar18 != uVar16) && (uVar8 = (uint)*puVar12, uVar8 != uVar17)) {
          uVar14 = (uint)*(byte *)(iVar4 + 0x1e) * iVar22;
          if ((uVar8 < (uVar14 & 0xe000)) || ((DAT_0000e060 + uVar14 + 0x1f & 0xffff) < uVar8)) {
            uVar2 = *(ushort *)(iVar4 + 0x34);
            uVar14 = (uint)uVar2;
            if ((iVar11 * (uint)*(byte *)(iVar4 + 0x1e) + DAT_0000e064 & 0xffff) < uVar14) {
              return -1;
            }
            *(ushort *)(iVar4 + 0x34) = uVar2 + 0x20;
            iVar10 = FUN_00009fa4(uVar8 + 0x4000,&local_20,1,uVar18,iVar20,uVar24);
            if (iVar10 != 0) {
              return -1;
            }
            if (uVar14 == uVar17) {
              return -1;
            }
            uVar1 = *puVar12;
            local_18[0] = 0x7f;
            iVar10 = FUN_00009fa4(uVar14 + 0x4000,local_18,1);
            if (iVar10 != 0) {
              return -1;
            }
            FUN_000001a2(&local_20,0xff);
            local_20 = (byte)uVar16;
            iVar10 = FUN_00009fa4(&LAB_00004000_1 + uVar14,&local_20,5);
            if (iVar10 != 0) {
              return -1;
            }
            local_18[0] = 0x3f;
            iVar10 = FUN_00009fa4(uVar14 + 0x4000,local_18,1);
            if (iVar10 != 0) {
              return -1;
            }
            local_20 = (byte)uVar24;
            iVar10 = FUN_00009fa4(uVar1 + 0x4000,&local_20,1);
            if (iVar10 != 0) {
              return -1;
            }
            *(undefined1 *)(iVar9 + uVar16 + 0x10) = 0;
            *puVar12 = uVar2;
            uVar17 = DAT_0000e10c;
          }
        }
        puVar12 = puVar12 + 1;
        uVar16 = uVar16 + 1;
      }
      iVar10 = FUN_00009fa4(*puVar23 + 0x4000,&local_20,1,uVar18,iVar20,uVar24);
      bVar25 = (byte)uVar24;
      if (iVar10 != 0) {
        return -1;
      }
      uVar24 = *local_44;
      uVar2 = *puVar23;
      local_18[0] = 0x7f;
      iVar10 = FUN_00009fa4(iVar20,local_18,1);
      if (iVar10 != 0) {
        return -1;
      }
      FUN_000001a2(&local_20,0xff);
      local_1c = (undefined1)((uint)uVar24 >> 0x18);
      local_1d = (undefined1)((uint)uVar24 >> 0x10);
      local_1e = (undefined1)((uint)uVar24 >> 8);
      local_1f = (undefined1)uVar24;
      local_20 = (byte)uVar18;
      iVar10 = FUN_00009fa4(iVar20 + 1,&local_20,5);
      if (iVar10 != 0) {
        return -1;
      }
      local_18[0] = 0x3f;
      iVar10 = FUN_00009fa4(iVar20,local_18,1);
      local_20 = bVar25;
      if (iVar10 != 0) {
        return -1;
      }
      iVar10 = FUN_00009fa4(uVar2 + 0x4000,&local_20,1);
      if (iVar10 != 0) {
        return -1;
      }
      *(undefined1 *)(iVar9 + uVar18 + 0x10) = 0;
      *puVar23 = (ushort)uVar6;
      if (2 < uVar19) {
        return -1;
      }
      iVar9 = FUN_0000a018(uVar19 * iVar22 + 0x4000,iVar22);
      if (iVar9 != 0) {
        return 1;
      }
      uVar6 = (uint)*(ushort *)(iVar4 + 0x34);
      uVar17 = DAT_0000e10c;
      if (((uint)*(byte *)(iVar4 + 0x1e) * iVar11 + DAT_0000e110 & 0xffff) < uVar6) {
        return 1;
      }
    }
    *local_24 = (ushort)uVar6;
    *(ushort *)(iVar4 + 0x34) = (ushort)uVar6 + 0x20;
    if (uVar6 == uVar17) {
      return -1;
    }
    uVar24 = puVar3[uVar13];
    local_18[0] = 0x7f;
    iVar9 = FUN_00009fa4(uVar6 + 0x4000);
    if (iVar9 != 0) {
      return iVar9;
    }
    FUN_000001a2(&local_20,0xff,5);
    local_1c = (undefined1)((uint)uVar24 >> 0x18);
    local_1d = (undefined1)((uint)uVar24 >> 0x10);
    local_1e = (undefined1)((uint)uVar24 >> 8);
    local_1f = (undefined1)uVar24;
    local_20 = bVar5;
    iVar9 = FUN_00009fa4(&LAB_00004000_1 + uVar6,&local_20,5);
    if (iVar9 != 0) {
      return -1;
    }
    local_18[0] = 0x3f;
    iVar10 = FUN_00009fa4(uVar6 + 0x4000,local_18,1);
    iVar9 = -1;
    uVar17 = DAT_0000e10c;
  }
  else {
    iVar11 = DAT_0000dc54 + uVar13 * 2;
    uVar6 = (uint)*(ushort *)(iVar11 + 0x20);
    local_24 = (ushort *)(iVar11 + 0x20);
    if (uVar6 == DAT_0000dc4c) goto LAB_0000da40;
    iVar11 = DAT_0000dc5c + 1;
    uVar19 = (uint)*(byte *)(DAT_0000dc58 + 0x1e);
    uVar2 = *(ushort *)(DAT_0000dc58 + 0x34);
    uVar17 = (uint)uVar2;
    if (uVar17 <= (uVar19 * iVar11 + DAT_0000dc5c & 0xffff)) {
      *(ushort *)(DAT_0000dc58 + 0x34) = uVar2 + 0x20;
      local_20 = 0x1f;
      iVar9 = FUN_00009fa4(uVar6 + 0x4000);
      if (iVar9 != 0) {
        return iVar9;
      }
      if (uVar17 == DAT_0000dc4c) {
        return -1;
      }
      uVar24 = puVar3[uVar13];
      uVar1 = *local_24;
      local_18[0] = 0x7f;
      iVar9 = FUN_00009fa4(uVar17 + 0x4000,local_18,1);
      if (iVar9 != 0) {
        return -1;
      }
      FUN_000001a2(&local_20,0xff);
      local_1c = (undefined1)((uint)uVar24 >> 0x18);
      local_1d = (undefined1)((uint)uVar24 >> 0x10);
      local_1e = (undefined1)((uint)uVar24 >> 8);
      local_1f = (undefined1)uVar24;
      local_20 = bVar5;
      iVar9 = FUN_00009fa4(&LAB_00004000_1 + uVar17,&local_20,5);
      if (iVar9 != 0) {
        return -1;
      }
      local_18[0] = 0x3f;
      iVar9 = FUN_00009fa4(uVar17 + 0x4000,local_18,1);
      if (iVar9 != 0) {
        return -1;
      }
      local_20 = 7;
      iVar9 = FUN_00009fa4(uVar1 + 0x4000,&local_20,1);
      uVar17 = DAT_0000dc4c;
      if (iVar9 != 0) {
        return -1;
      }
      *local_24 = uVar2;
      *(undefined1 *)(iVar21 + 0x10) = 0;
      goto LAB_0000da08;
    }
    uVar6 = uVar19 + 1;
    *(char *)(DAT_0000dc58 + 0x1e) = (char)uVar6;
    if (1 < (uVar6 & 0xff)) {
      uVar6 = 0;
      *(undefined2 *)(iVar4 + 0x34) = 0;
      *(undefined1 *)(iVar4 + 0x1e) = 0;
      uVar17 = 0;
    }
    if ((iVar11 * (uVar6 & 0xff) + DAT_0000dc5c & 0xffff) < uVar17) {
      return 1;
    }
    *(ushort *)(iVar4 + 0x34) = (ushort)uVar17 + 0x20;
    local_20 = 0x1f;
    iVar22 = DAT_0000dc60 + 0x20;
    uVar6 = uVar19 * iVar22 + DAT_0000dc60 & 0xffff;
    iVar7 = FUN_00009fa4(uVar6 + 0x4000);
    if (iVar7 != 0) {
      return -1;
    }
    local_20 = 0x7f;
    iVar20 = uVar17 + 0x4000;
    iVar7 = FUN_00009fa4(iVar20,&local_20,1);
    if (iVar7 != 0) {
      return -1;
    }
    puVar23 = (ushort *)(iVar10 + 0x20);
    uVar16 = 0;
    puVar15 = puVar3;
    while( true ) {
      if (uVar16 == 0x12) {
        return -1;
      }
      if (uVar6 == *puVar23) break;
      puVar23 = puVar23 + 1;
      puVar15 = puVar15 + 1;
      uVar16 = uVar16 + 1;
    }
    if ((uVar16 & 0xff) == 0x12) {
      return -1;
    }
    puVar12 = (ushort *)(iVar10 + 0x20);
    uVar6 = 0;
    while( true ) {
      local_20 = 0x1f;
      if (uVar6 == 0x12) break;
      if ((uVar16 != uVar6) && (uVar18 = (uint)*puVar12, uVar18 != DAT_0000e10c)) {
        uVar8 = (uint)*(byte *)(iVar4 + 0x1e) * iVar22;
        if ((uVar18 < (uVar8 & 0xe000)) || ((DAT_0000e114 + uVar8 + 0x1f & 0xffff) < uVar18)) {
          uVar2 = *(ushort *)(iVar4 + 0x34);
          uVar8 = (uint)uVar2;
          if ((iVar11 * (uint)*(byte *)(iVar4 + 0x1e) + DAT_0000e110 & 0xffff) < uVar8) {
            return -1;
          }
          *(ushort *)(iVar4 + 0x34) = uVar2 + 0x20;
          iVar10 = FUN_00009fa4(uVar18 + 0x4000,&local_20,1);
          if (iVar10 != 0) {
            return -1;
          }
          if (uVar8 == DAT_0000e10c) {
            return -1;
          }
          uVar1 = *puVar12;
          local_18[0] = 0x7f;
          iVar10 = FUN_00009fa4(uVar8 + 0x4000,local_18,1);
          if (iVar10 != 0) {
            return -1;
          }
          FUN_000001a2(&local_20,0xff);
          local_20 = (byte)uVar6;
          iVar10 = FUN_00009fa4(&LAB_00004000_1 + uVar8,&local_20,5);
          if (iVar10 != 0) {
            return -1;
          }
          local_18[0] = 0x3f;
          iVar10 = FUN_00009fa4(uVar8 + 0x4000,local_18,1);
          if (iVar10 != 0) {
            return -1;
          }
          local_20 = 7;
          iVar10 = FUN_00009fa4(uVar1 + 0x4000,&local_20,1);
          if (iVar10 != 0) {
            return -1;
          }
          *(undefined1 *)(iVar9 + uVar6 + 0x10) = 0;
          *puVar12 = uVar2;
        }
      }
      puVar12 = puVar12 + 1;
      uVar6 = uVar6 + 1;
    }
    iVar10 = FUN_00009fa4(*puVar23 + 0x4000,&local_20,1);
    if (iVar10 != 0) {
      return -1;
    }
    uVar24 = *puVar15;
    uVar2 = *puVar23;
    local_18[0] = 0x7f;
    iVar10 = FUN_00009fa4(iVar20,local_18,1);
    if (iVar10 != 0) {
      return -1;
    }
    FUN_000001a2(&local_20,0xff);
    local_1c = (undefined1)((uint)uVar24 >> 0x18);
    local_1d = (undefined1)((uint)uVar24 >> 0x10);
    local_1e = (undefined1)((uint)uVar24 >> 8);
    local_1f = (undefined1)uVar24;
    local_20 = (byte)uVar16;
    iVar10 = FUN_00009fa4(iVar20 + 1,&local_20,5);
    if (iVar10 != 0) {
      return -1;
    }
    local_18[0] = 0x3f;
    iVar10 = FUN_00009fa4(iVar20,local_18,1);
    if (iVar10 != 0) {
      return -1;
    }
    local_20 = 7;
    iVar10 = FUN_00009fa4(uVar2 + 0x4000,&local_20,1);
    if (iVar10 != 0) {
      return -1;
    }
    *(undefined1 *)(iVar9 + uVar16 + 0x10) = 0;
    *puVar23 = (ushort)uVar17;
    uVar17 = DAT_0000e10c;
    if (2 < uVar19) {
      return -1;
    }
    iVar10 = FUN_0000a018(uVar19 * iVar22 + 0x4000,iVar22);
    iVar9 = 1;
  }
  if (iVar10 != 0) {
    return iVar9;
  }
LAB_0000da08:
  puVar3[uVar13] = puVar3[uVar13] + 1;
  uVar6 = (uint)*(byte *)(iVar21 + 0x10);
  uVar19 = uVar6 + 1;
  *(char *)(iVar21 + 0x10) = (char)uVar19;
  uVar13 = (uint)*local_24;
  if (uVar13 == uVar17) {
    return 1;
  }
  uVar17 = uVar6;
  if ((uVar19 & 0xff) < 8) {
    uVar17 = 0;
  }
  uVar18 = 0xff;
  for (uVar16 = uVar19 - (uVar17 & 0xf8); (uVar16 & 0xff) != 0; uVar16 = uVar16 - 1) {
    uVar18 = uVar18 >> 1;
  }
  uVar17 = uVar17 >> 3;
  if ((uVar19 & 0xff) - uVar6 != 1) {
    uVar19 = uVar6;
    if (7 < uVar6) {
      uVar19 = 8;
    }
    uVar6 = ((uVar6 - uVar19) + 7 & 0xff) >> 3;
    if (uVar17 != uVar6) {
      uVar13 = 0;
      while ((uVar17 - uVar6 & ~((int)(uVar17 - uVar6) >> 0x1f)) != uVar13) {
        local_20 = 0;
        iVar9 = FUN_00009fa4((uVar6 + uVar13 & 0xff) + (uint)*local_24 + 0x4006,&local_20,1);
        uVar13 = uVar13 + 1;
        if (iVar9 != 0) {
          return iVar9;
        }
      }
      uVar13 = (uint)*local_24;
    }
  }
  local_20 = (byte)uVar18;
  iVar9 = FUN_00009fa4(uVar17 + uVar13 + 0x4006,&local_20,1);
  return iVar9;
}

