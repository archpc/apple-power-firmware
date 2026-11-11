
int FUN_0000d984(char param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  int iVar4;
  byte bVar5;
  undefined *puVar6;
  undefined *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined *puVar11;
  undefined *puVar12;
  ushort *puVar13;
  uint uVar14;
  undefined4 *puVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  undefined *puVar20;
  int iVar21;
  undefined *puVar22;
  ushort *puVar23;
  undefined *puVar24;
  undefined4 uVar25;
  byte bVar26;
  undefined4 *local_44;
  ushort *local_24;
  byte local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_18 [4];
  
  iVar4 = DAT_0000dcd8;
  iVar9 = DAT_0000dcd4;
  puVar3 = DAT_0000dcd0;
  puVar11 = DAT_0000dccc;
  iVar8 = DAT_0000dcc8;
  bVar5 = param_1 << 1;
  uVar14 = (uint)bVar5;
  iVar21 = DAT_0000dcc8 + uVar14;
  if (*(byte *)(iVar21 + 0x10) >> 4 < 0xd) {
    iVar10 = DAT_0000dcd4 + uVar14 * 2;
    local_24 = (ushort *)(iVar10 + 0x20);
    if ((undefined *)(uint)*(ushort *)(iVar10 + 0x20) != DAT_0000dccc) goto LAB_0000da88;
LAB_0000dac0:
    puVar6 = PTR_LAB_00005ffe_1_0000dcdc + 1;
    uVar19 = (uint)*(byte *)(DAT_0000dcd8 + 0x1e);
    puVar12 = (undefined *)(uint)*(ushort *)(DAT_0000dcd8 + 0x34);
    if ((undefined *)((uint)(PTR_LAB_00005ffe_1_0000dcdc + uVar19 * (int)puVar6) & 0xffff) < puVar12
       ) {
      uVar17 = uVar19 + 1;
      *(char *)(DAT_0000dcd8 + 0x1e) = (char)uVar17;
      if (1 < (uVar17 & 0xff)) {
        uVar17 = 0;
        *(undefined2 *)(iVar4 + 0x34) = 0;
        *(undefined1 *)(iVar4 + 0x1e) = 0;
        puVar12 = (undefined *)0x0;
      }
      if ((undefined *)
          ((uint)(PTR_LAB_00005ffe_1_0000dcdc + (int)puVar6 * (uVar17 & 0xff)) & 0xffff) < puVar12)
      {
        return 1;
      }
      *(ushort *)(iVar4 + 0x34) = (ushort)puVar12 + 0x20;
      local_20 = 0x1f;
      puVar22 = PTR_LAB_0000dce0 + 0x20;
      puVar7 = PTR_LAB_0000dce0 + uVar19 * (int)puVar22;
      iVar10 = FUN_00009fa4(((uint)puVar7 & 0xffff) + 0x4000);
      if (iVar10 != 0) {
        return -1;
      }
      local_20 = 0x7f;
      puVar20 = puVar12 + 0x4000;
      iVar10 = FUN_00009fa4(puVar20,&local_20,1);
      if (iVar10 != 0) {
        return -1;
      }
      puVar23 = (ushort *)(iVar9 + 0x20);
      local_44 = puVar3;
      uVar17 = 0;
      while( true ) {
        if (uVar17 == 0x12) {
          return -1;
        }
        if (((uint)puVar7 & 0xffff) == (uint)*puVar23) break;
        puVar23 = puVar23 + 1;
        local_44 = local_44 + 1;
        uVar17 = uVar17 + 1;
      }
      if ((uVar17 & 0xff) == 0x12) {
        return -1;
      }
      puVar13 = (ushort *)(iVar9 + 0x20);
      uVar25 = 7;
      uVar16 = 0;
      while( true ) {
        local_20 = 0x1f;
        if (uVar16 == 0x12) break;
        if ((uVar17 != uVar16) && (puVar7 = (undefined *)(uint)*puVar13, puVar7 != puVar11)) {
          uVar18 = (uint)*(byte *)(iVar4 + 0x1e) * (int)puVar22;
          if ((puVar7 < (undefined *)(uVar18 & 0xe000)) ||
             ((undefined *)((uint)(PTR_LAB_0000e0e0 + uVar18 + 0x1f) & 0xffff) < puVar7)) {
            uVar2 = *(ushort *)(iVar4 + 0x34);
            puVar24 = (undefined *)(uint)uVar2;
            if ((undefined *)
                ((uint)(PTR_LAB_00005ffe_1_0000e0e4 + (int)puVar6 * (uint)*(byte *)(iVar4 + 0x1e)) &
                0xffff) < puVar24) {
              return -1;
            }
            *(ushort *)(iVar4 + 0x34) = uVar2 + 0x20;
            iVar9 = FUN_00009fa4(puVar7 + 0x4000,&local_20,1,uVar17,puVar20,uVar25);
            if (iVar9 != 0) {
              return -1;
            }
            if (puVar24 == puVar11) {
              return -1;
            }
            uVar1 = *puVar13;
            local_18[0] = 0x7f;
            iVar9 = FUN_00009fa4(puVar24 + 0x4000,local_18,1);
            if (iVar9 != 0) {
              return -1;
            }
            FUN_000001a2(&local_20,0xff);
            local_20 = (byte)uVar16;
            iVar9 = FUN_00009fa4(puVar24 + 0x4001,&local_20,5);
            if (iVar9 != 0) {
              return -1;
            }
            local_18[0] = 0x3f;
            iVar9 = FUN_00009fa4(puVar24 + 0x4000,local_18,1);
            if (iVar9 != 0) {
              return -1;
            }
            local_20 = (byte)uVar25;
            iVar9 = FUN_00009fa4(uVar1 + 0x4000,&local_20,1);
            if (iVar9 != 0) {
              return -1;
            }
            *(undefined1 *)(iVar8 + uVar16 + 0x10) = 0;
            *puVar13 = uVar2;
            puVar11 = PTR_DAT_0000e18c;
          }
        }
        puVar13 = puVar13 + 1;
        uVar16 = uVar16 + 1;
      }
      iVar9 = FUN_00009fa4(*puVar23 + 0x4000,&local_20,1,uVar17,puVar20,uVar25);
      bVar26 = (byte)uVar25;
      if (iVar9 != 0) {
        return -1;
      }
      uVar25 = *local_44;
      uVar2 = *puVar23;
      local_18[0] = 0x7f;
      iVar9 = FUN_00009fa4(puVar20,local_18,1);
      if (iVar9 != 0) {
        return -1;
      }
      FUN_000001a2(&local_20,0xff);
      local_1c = (undefined1)((uint)uVar25 >> 0x18);
      local_1d = (undefined1)((uint)uVar25 >> 0x10);
      local_1e = (undefined1)((uint)uVar25 >> 8);
      local_1f = (undefined1)uVar25;
      local_20 = (byte)uVar17;
      iVar9 = FUN_00009fa4(puVar20 + 1,&local_20,5);
      if (iVar9 != 0) {
        return -1;
      }
      local_18[0] = 0x3f;
      iVar9 = FUN_00009fa4(puVar20,local_18,1);
      local_20 = bVar26;
      if (iVar9 != 0) {
        return -1;
      }
      iVar9 = FUN_00009fa4(uVar2 + 0x4000,&local_20,1);
      if (iVar9 != 0) {
        return -1;
      }
      *(undefined1 *)(iVar8 + uVar17 + 0x10) = 0;
      *puVar23 = (ushort)puVar12;
      if (2 < uVar19) {
        return -1;
      }
      iVar8 = FUN_0000a018(uVar19 * (int)puVar22 + 0x4000,puVar22);
      if (iVar8 != 0) {
        return 1;
      }
      puVar12 = (undefined *)(uint)*(ushort *)(iVar4 + 0x34);
      puVar11 = PTR_DAT_0000e18c;
      if ((undefined *)
          ((uint)(PTR_LAB_00005ffe_1_0000e190 + (uint)*(byte *)(iVar4 + 0x1e) * (int)puVar6) &
          0xffff) < puVar12) {
        return 1;
      }
    }
    *local_24 = (ushort)puVar12;
    *(ushort *)(iVar4 + 0x34) = (ushort)puVar12 + 0x20;
    if (puVar12 == puVar11) {
      return -1;
    }
    uVar25 = puVar3[uVar14];
    local_18[0] = 0x7f;
    iVar8 = FUN_00009fa4(puVar12 + 0x4000);
    if (iVar8 != 0) {
      return iVar8;
    }
    FUN_000001a2(&local_20,0xff,5);
    local_1c = (undefined1)((uint)uVar25 >> 0x18);
    local_1d = (undefined1)((uint)uVar25 >> 0x10);
    local_1e = (undefined1)((uint)uVar25 >> 8);
    local_1f = (undefined1)uVar25;
    local_20 = bVar5;
    iVar8 = FUN_00009fa4(puVar12 + 0x4001,&local_20,5);
    if (iVar8 != 0) {
      return -1;
    }
    local_18[0] = 0x3f;
    iVar9 = FUN_00009fa4(puVar12 + 0x4000,local_18,1);
    iVar8 = -1;
    puVar11 = PTR_DAT_0000e18c;
  }
  else {
    iVar10 = DAT_0000dcd4 + uVar14 * 2;
    puVar6 = (undefined *)(uint)*(ushort *)(iVar10 + 0x20);
    local_24 = (ushort *)(iVar10 + 0x20);
    if (puVar6 == DAT_0000dccc) goto LAB_0000dac0;
    puVar11 = PTR_LAB_00005ffe_1_0000dcdc + 1;
    uVar19 = (uint)*(byte *)(DAT_0000dcd8 + 0x1e);
    uVar2 = *(ushort *)(DAT_0000dcd8 + 0x34);
    puVar12 = (undefined *)(uint)uVar2;
    if (puVar12 <=
        (undefined *)((uint)(PTR_LAB_00005ffe_1_0000dcdc + uVar19 * (int)puVar11) & 0xffff)) {
      *(ushort *)(DAT_0000dcd8 + 0x34) = uVar2 + 0x20;
      local_20 = 0x1f;
      iVar8 = FUN_00009fa4(puVar6 + 0x4000);
      if (iVar8 != 0) {
        return iVar8;
      }
      if (puVar12 == DAT_0000dccc) {
        return -1;
      }
      uVar25 = puVar3[uVar14];
      uVar1 = *local_24;
      local_18[0] = 0x7f;
      iVar8 = FUN_00009fa4(puVar12 + 0x4000,local_18,1);
      if (iVar8 != 0) {
        return -1;
      }
      FUN_000001a2(&local_20,0xff);
      local_1c = (undefined1)((uint)uVar25 >> 0x18);
      local_1d = (undefined1)((uint)uVar25 >> 0x10);
      local_1e = (undefined1)((uint)uVar25 >> 8);
      local_1f = (undefined1)uVar25;
      local_20 = bVar5;
      iVar8 = FUN_00009fa4(puVar12 + 0x4001,&local_20,5);
      if (iVar8 != 0) {
        return -1;
      }
      local_18[0] = 0x3f;
      iVar8 = FUN_00009fa4(puVar12 + 0x4000,local_18,1);
      if (iVar8 != 0) {
        return -1;
      }
      local_20 = 7;
      iVar8 = FUN_00009fa4(uVar1 + 0x4000,&local_20,1);
      puVar11 = DAT_0000dccc;
      if (iVar8 != 0) {
        return -1;
      }
      *local_24 = uVar2;
      *(undefined1 *)(iVar21 + 0x10) = 0;
      goto LAB_0000da88;
    }
    uVar17 = uVar19 + 1;
    *(char *)(DAT_0000dcd8 + 0x1e) = (char)uVar17;
    if (1 < (uVar17 & 0xff)) {
      uVar17 = 0;
      *(undefined2 *)(iVar4 + 0x34) = 0;
      *(undefined1 *)(iVar4 + 0x1e) = 0;
      puVar12 = (undefined *)0x0;
    }
    if ((undefined *)((uint)(PTR_LAB_00005ffe_1_0000dcdc + (int)puVar11 * (uVar17 & 0xff)) & 0xffff)
        < puVar12) {
      return 1;
    }
    *(ushort *)(iVar4 + 0x34) = (ushort)puVar12 + 0x20;
    local_20 = 0x1f;
    puVar7 = PTR_LAB_0000dce0 + 0x20;
    puVar6 = PTR_LAB_0000dce0 + uVar19 * (int)puVar7;
    iVar10 = FUN_00009fa4(((uint)puVar6 & 0xffff) + 0x4000);
    if (iVar10 != 0) {
      return -1;
    }
    local_20 = 0x7f;
    puVar22 = puVar12 + 0x4000;
    iVar10 = FUN_00009fa4(puVar22,&local_20,1);
    if (iVar10 != 0) {
      return -1;
    }
    puVar23 = (ushort *)(iVar9 + 0x20);
    uVar17 = 0;
    puVar15 = puVar3;
    while( true ) {
      if (uVar17 == 0x12) {
        return -1;
      }
      if (((uint)puVar6 & 0xffff) == (uint)*puVar23) break;
      puVar23 = puVar23 + 1;
      puVar15 = puVar15 + 1;
      uVar17 = uVar17 + 1;
    }
    if ((uVar17 & 0xff) == 0x12) {
      return -1;
    }
    puVar13 = (ushort *)(iVar9 + 0x20);
    uVar16 = 0;
    while( true ) {
      local_20 = 0x1f;
      if (uVar16 == 0x12) break;
      if ((uVar17 != uVar16) && (puVar6 = (undefined *)(uint)*puVar13, puVar6 != PTR_DAT_0000e18c))
      {
        uVar18 = (uint)*(byte *)(iVar4 + 0x1e) * (int)puVar7;
        if ((puVar6 < (undefined *)(uVar18 & 0xe000)) ||
           ((undefined *)((uint)(PTR_LAB_0000e194 + uVar18 + 0x1f) & 0xffff) < puVar6)) {
          uVar2 = *(ushort *)(iVar4 + 0x34);
          puVar20 = (undefined *)(uint)uVar2;
          if ((undefined *)
              ((uint)(PTR_LAB_00005ffe_1_0000e190 + (int)puVar11 * (uint)*(byte *)(iVar4 + 0x1e)) &
              0xffff) < puVar20) {
            return -1;
          }
          *(ushort *)(iVar4 + 0x34) = uVar2 + 0x20;
          iVar9 = FUN_00009fa4(puVar6 + 0x4000,&local_20,1);
          if (iVar9 != 0) {
            return -1;
          }
          if (puVar20 == PTR_DAT_0000e18c) {
            return -1;
          }
          uVar1 = *puVar13;
          local_18[0] = 0x7f;
          iVar9 = FUN_00009fa4(puVar20 + 0x4000,local_18,1);
          if (iVar9 != 0) {
            return -1;
          }
          FUN_000001a2(&local_20,0xff);
          local_20 = (byte)uVar16;
          iVar9 = FUN_00009fa4(puVar20 + 0x4001,&local_20,5);
          if (iVar9 != 0) {
            return -1;
          }
          local_18[0] = 0x3f;
          iVar9 = FUN_00009fa4(puVar20 + 0x4000,local_18,1);
          if (iVar9 != 0) {
            return -1;
          }
          local_20 = 7;
          iVar9 = FUN_00009fa4(uVar1 + 0x4000,&local_20,1);
          if (iVar9 != 0) {
            return -1;
          }
          *(undefined1 *)(iVar8 + uVar16 + 0x10) = 0;
          *puVar13 = uVar2;
        }
      }
      puVar13 = puVar13 + 1;
      uVar16 = uVar16 + 1;
    }
    iVar9 = FUN_00009fa4(*puVar23 + 0x4000,&local_20,1);
    if (iVar9 != 0) {
      return -1;
    }
    uVar25 = *puVar15;
    uVar2 = *puVar23;
    local_18[0] = 0x7f;
    iVar9 = FUN_00009fa4(puVar22,local_18,1);
    if (iVar9 != 0) {
      return -1;
    }
    FUN_000001a2(&local_20,0xff);
    local_1c = (undefined1)((uint)uVar25 >> 0x18);
    local_1d = (undefined1)((uint)uVar25 >> 0x10);
    local_1e = (undefined1)((uint)uVar25 >> 8);
    local_1f = (undefined1)uVar25;
    local_20 = (byte)uVar17;
    iVar9 = FUN_00009fa4(puVar22 + 1,&local_20,5);
    if (iVar9 != 0) {
      return -1;
    }
    local_18[0] = 0x3f;
    iVar9 = FUN_00009fa4(puVar22,local_18,1);
    if (iVar9 != 0) {
      return -1;
    }
    local_20 = 7;
    iVar9 = FUN_00009fa4(uVar2 + 0x4000,&local_20,1);
    if (iVar9 != 0) {
      return -1;
    }
    *(undefined1 *)(iVar8 + uVar17 + 0x10) = 0;
    *puVar23 = (ushort)puVar12;
    puVar11 = PTR_DAT_0000e18c;
    if (2 < uVar19) {
      return -1;
    }
    iVar9 = FUN_0000a018(uVar19 * (int)puVar7 + 0x4000,puVar7);
    iVar8 = 1;
  }
  if (iVar9 != 0) {
    return iVar8;
  }
LAB_0000da88:
  puVar3[uVar14] = puVar3[uVar14] + 1;
  uVar14 = (uint)*(byte *)(iVar21 + 0x10);
  uVar19 = uVar14 + 1;
  *(char *)(iVar21 + 0x10) = (char)uVar19;
  puVar6 = (undefined *)(uint)*local_24;
  if (puVar6 == puVar11) {
    return 1;
  }
  uVar17 = uVar14;
  if ((uVar19 & 0xff) < 8) {
    uVar17 = 0;
  }
  uVar18 = 0xff;
  for (uVar16 = uVar19 - (uVar17 & 0xf8); (uVar16 & 0xff) != 0; uVar16 = uVar16 - 1) {
    uVar18 = uVar18 >> 1;
  }
  uVar17 = uVar17 >> 3;
  if ((uVar19 & 0xff) - uVar14 != 1) {
    uVar19 = uVar14;
    if (7 < uVar14) {
      uVar19 = 8;
    }
    uVar14 = ((uVar14 - uVar19) + 7 & 0xff) >> 3;
    if (uVar17 != uVar14) {
      uVar19 = 0;
      while ((uVar17 - uVar14 & ~((int)(uVar17 - uVar14) >> 0x1f)) != uVar19) {
        local_20 = 0;
        iVar8 = FUN_00009fa4((uVar14 + uVar19 & 0xff) + (uint)*local_24 + 0x4006,&local_20,1);
        uVar19 = uVar19 + 1;
        if (iVar8 != 0) {
          return iVar8;
        }
      }
      puVar6 = (undefined *)(uint)*local_24;
    }
  }
  local_20 = (byte)uVar18;
  iVar8 = FUN_00009fa4(puVar6 + uVar17 + 0x4006,&local_20,1);
  return iVar8;
}

