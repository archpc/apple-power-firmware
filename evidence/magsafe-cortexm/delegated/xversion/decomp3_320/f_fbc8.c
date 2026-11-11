
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000fbc8(void)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int extraout_r2;
  int extraout_r2_00;
  int extraout_r2_01;
  int extraout_r2_02;
  int extraout_r2_03;
  ushort *extraout_r2_04;
  uint uVar17;
  uint uVar18;
  ushort *extraout_r3;
  ushort *extraout_r3_00;
  ushort *extraout_r3_01;
  uint extraout_r3_02;
  int extraout_r3_03;
  uint extraout_r3_04;
  uint extraout_r3_05;
  ushort *puVar19;
  ushort *extraout_r3_06;
  ushort *extraout_r3_07;
  uint uVar20;
  int iVar21;
  ushort *puVar22;
  int iVar23;
  ushort *puVar24;
  uint uVar25;
  undefined8 uVar26;
  ulonglong uVar27;
  undefined1 uVar28;
  int local_8c;
  undefined1 *local_84;
  int local_74;
  int local_6c;
  int local_64;
  ushort *local_60;
  ushort *local_5c;
  ushort *local_58;
  ushort *local_4c;
  undefined4 *local_48;
  uint local_44;
  undefined4 *local_40;
  undefined4 *local_3c;
  int local_38;
  uint local_30;
  int local_2c;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_18 [4];
  
  local_3c = DAT_0000fff4;
  iVar14 = DAT_0000ff90;
  local_2c = DAT_0000ff8c;
  iVar15 = DAT_0000ff88;
  if (*(char *)(DAT_0000ff88 + 0x28) == '\0') {
    uVar25 = DAT_0000fff4[0x10];
    uVar7 = uVar25 - DAT_0000fff4[0x11];
    if (uVar25 < (uint)DAT_0000fff4[0x11]) {
      uVar7 = 0;
    }
    uVar26 = CONCAT44(*(uint *)(DAT_0000ff88 + 100),uVar7);
    if (*(uint *)(DAT_0000ff88 + 100) < uVar7) {
      uVar26 = FUN_000107d6();
      local_2c = extraout_r2_01;
    }
    iVar23 = (int)((ulonglong)uVar26 >> 0x20) - (int)uVar26;
    if (iVar23 == 0) {
      FUN_000107d6();
      local_2c = extraout_r2_02;
    }
    uVar7 = DAT_0000fffc;
    puVar6 = DAT_0000fff4;
    if (iVar23 + (uint)*(byte *)(local_2c + 0x20) < 0xd1) {
      if (*(ushort *)(iVar14 + 0x40) != DAT_0000fffc) {
        bVar2 = *(byte *)(local_2c + 0x20);
        uVar7 = (uint)bVar2 + iVar23;
        *(char *)(local_2c + 0x20) = (char)uVar7;
        local_3c[0x10] = local_3c[0x10] + iVar23;
        uVar27 = (ulonglong)CONCAT14(bVar2,(uint)*(ushort *)(iVar14 + 0x40));
        if (*(ushort *)(iVar14 + 0x40) == DAT_0000fffc) {
          uVar27 = FUN_000107d6();
          uVar7 = extraout_r3_04;
        }
        iVar15 = (int)(uVar27 >> 0x20);
        uVar25 = (uint)uVar27;
        uVar17 = uVar7 & 0xff;
        iVar23 = uVar17 - 8;
        if (uVar17 < 8) {
          iVar23 = 0;
        }
        uVar20 = 0xff;
        for (uVar7 = uVar7 - (iVar23 + 7U & 0x1f8); (uVar7 & 0xff) != 0; uVar7 = uVar7 - 1) {
          uVar20 = uVar20 >> 1;
        }
        uVar7 = (iVar23 + 7U & 0xff) >> 3;
        if (uVar17 - iVar15 != 1) {
          iVar15 = iVar15 + -8;
          if (uVar27 < 0x800000000) {
            iVar15 = 0;
          }
          uVar17 = (iVar15 + 7U & 0xff) >> 3;
          if (uVar7 != uVar17) {
            iVar15 = 0;
            while (iVar15 < (int)(uVar7 - uVar17)) {
              local_20 = 0;
              iVar23 = FUN_00009fac((uVar17 + iVar15 & 0xff) + (uint)*(ushort *)(iVar14 + 0x40) +
                                    0x4006,&local_20,1);
              iVar15 = iVar15 + 1;
              if (iVar23 != 0) {
                uVar12 = FUN_000107d6();
                return uVar12;
              }
            }
            uVar25 = (uint)*(ushort *)(iVar14 + 0x40);
          }
        }
        local_20 = (char)uVar20;
        FUN_00009fac(uVar7 + uVar25 + 0x4006,&local_20,1);
        uVar12 = FUN_000107d6();
        return uVar12;
      }
    }
    else {
      DAT_0000fff4[0x10] = iVar23 + uVar25 + -1;
      uVar4 = *(ushort *)(iVar14 + 0x40);
      if (uVar4 != uVar7) {
        uVar25 = (uint)*(byte *)(iVar15 + 0x26);
        iVar23 = _LAB_00010000 + 1;
        uVar7 = uVar25 * iVar23 + _LAB_00010000;
        uVar3 = *(ushort *)(iVar15 + 0x32);
        uVar17 = (uint)uVar3;
        if ((uVar7 & 0xffff) < uVar17) {
          uVar20 = uVar25 + 1;
          *(char *)(iVar15 + 0x26) = (char)uVar20;
          if (1 < (uVar20 & 0xff)) {
            uVar20 = 0;
            *(undefined1 *)(iVar15 + 0x26) = 0;
            *(undefined2 *)(iVar15 + 0x32) = 0;
            uVar17 = 0;
          }
          if ((iVar23 * (uVar20 & 0xff) + _LAB_00010000 & 0xffff) < uVar17) {
            uVar7 = FUN_000107d6();
          }
          *(short *)(iVar15 + 0x32) = (short)uVar17 + 0x20;
          local_20 = 0x1f;
          iVar15 = FUN_00009fac((uVar7 - 0x1f & 0xffff) + 0x4000);
          if (iVar15 != 0) {
            FUN_000107d6();
          }
          local_20 = 0x7f;
          iVar15 = FUN_00009fac(uVar17 + 0x4000,&local_20,1);
          if (iVar15 != 0) {
            FUN_000107d6();
          }
          uVar7 = uVar25 * (_LAB_00010004 + 0x20) + _LAB_00010004 & 0xffff;
          puVar19 = (ushort *)(iVar14 + 0x20);
          iVar15 = 0;
          do {
            if (iVar15 == 0x12) {
              uVar7 = FUN_000107d6();
              puVar19 = extraout_r3_00;
            }
            if (uVar7 == *puVar19) {
              uVar7 = FUN_000107ec();
              puVar19 = extraout_r3_01;
            }
            puVar19 = puVar19 + 1;
            iVar15 = iVar15 + 1;
          } while( true );
        }
        *(ushort *)(iVar15 + 0x32) = uVar3 + 0x20;
        local_20 = 0x1f;
        iVar15 = FUN_00009fac(uVar4 + 0x4000);
        if (iVar15 != 0) {
          uVar12 = FUN_000107d6();
          return uVar12;
        }
        if (uVar17 == DAT_00010408) {
          uVar12 = FUN_000107d6();
          return uVar12;
        }
        uVar4 = *(ushort *)(iVar14 + 0x40);
        uVar12 = puVar6[0x10];
        local_18[0] = 0x7f;
        iVar15 = FUN_00009fac(uVar17 + 0x4000,local_18,1);
        if (iVar15 == 0) {
          FUN_000001a0(&local_20,0xff);
          local_1c = (undefined1)((uint)uVar12 >> 0x18);
          local_1d = (undefined1)((uint)uVar12 >> 0x10);
          local_1e = (undefined1)((uint)uVar12 >> 8);
          local_1f = (undefined1)uVar12;
          local_20 = 0x10;
          iVar15 = FUN_00009fac(&LAB_00004000_1 + uVar17,&local_20,5);
          if (iVar15 != 0) {
            uVar12 = FUN_000107d6();
            return uVar12;
          }
          local_18[0] = 0x3f;
          iVar15 = FUN_00009fac(uVar17 + 0x4000,local_18,1);
          if (iVar15 == 0) {
            local_20 = 7;
            iVar15 = FUN_00009fac(uVar4 + 0x4000,&local_20,1);
            if (iVar15 == 0) {
              *(ushort *)(iVar14 + 0x40) = uVar3;
              *(undefined1 *)(local_2c + 0x20) = 0;
              uVar12 = FUN_0000ff42();
              return uVar12;
            }
            uVar12 = FUN_000107d6();
            return uVar12;
          }
          uVar12 = FUN_000107d6();
          return uVar12;
        }
        uVar12 = FUN_000107d6();
        return uVar12;
      }
    }
    local_4c = (ushort *)(uint)*(byte *)(iVar15 + 0x26);
    local_38 = DAT_0001040c + 1;
    uVar7 = (int)local_4c * local_38 + DAT_0001040c;
    local_30 = (uint)*(ushort *)(iVar15 + 0x32);
    if (local_30 <= (uVar7 & 0xffff)) {
      uVar7 = FUN_00010ac0();
      local_4c = (ushort *)extraout_r3_05;
    }
    uVar25 = (int)local_4c + 1;
    *(char *)(iVar15 + 0x26) = (char)uVar25;
    local_44 = 0x26;
    if (1 < (uVar25 & 0xff)) {
      uVar25 = 0;
      *(undefined1 *)(iVar15 + 0x26) = 0;
      *(undefined2 *)(iVar15 + 0x32) = 0;
      local_30 = 0;
    }
    if ((local_38 * (uVar25 & 0xff) + DAT_0001040c & 0xffff) < local_30) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    *(short *)(iVar15 + 0x32) = (short)local_30 + 0x20;
    local_20 = 0x1f;
    iVar23 = FUN_00009fac((uVar7 - 0x1f & 0xffff) + 0x4000);
    if (iVar23 != 0) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    local_60 = (ushort *)0x7f;
    local_20 = 0x7f;
    local_74 = local_30 + 0x4000;
    iVar23 = FUN_00009fac(local_74,&local_20,1);
    if (iVar23 != 0) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    local_64 = DAT_00010410 + 0x20;
    local_8c = (int)local_4c * local_64;
    puVar19 = (ushort *)(iVar14 + 0x20);
    local_58 = (ushort *)0x0;
    while( true ) {
      if (local_58 == (ushort *)((int)&MemManage + 2)) {
        uVar12 = FUN_000107d6();
        return uVar12;
      }
      if ((local_8c + DAT_00010410 & 0xffff) == (uint)*puVar19) break;
      puVar19 = puVar19 + 1;
      local_3c = local_3c + 1;
      local_58 = (ushort *)((int)local_58 + 1);
    }
    puVar22 = (ushort *)(iVar14 + 0x20);
    local_48 = DAT_000107dc;
    for (puVar24 = (ushort *)0x0; local_5c = puVar19, puVar24 != (ushort *)((int)&MemManage + 2);
        puVar24 = (ushort *)((int)puVar24 + 1)) {
      if ((local_58 != puVar24) && (uVar7 = (uint)*puVar22, uVar7 != DAT_000107e0)) {
        uVar25 = (uint)*(byte *)(iVar15 + 0x26) * local_64;
        if ((uVar7 < (uVar25 & 0xe000)) || ((DAT_000107e4 + uVar25 + 0x1f & 0xffff) < uVar7)) {
          uVar4 = *(ushort *)(iVar15 + 0x32);
          uVar25 = (uint)uVar4;
          if ((local_38 * (uint)*(byte *)(iVar15 + 0x26) + DAT_000107e8 & 0xffff) < uVar25) {
            uVar12 = FUN_000107d6();
            return uVar12;
          }
          *(ushort *)(iVar15 + 0x32) = uVar4 + 0x20;
          local_20 = 0x1f;
          iVar23 = FUN_00009fac(uVar7 + 0x4000,&local_20,1);
          if (iVar23 != 0) {
            uVar12 = FUN_000107d6();
            return uVar12;
          }
          if (uVar25 == DAT_000107e0) {
            uVar12 = FUN_000107d6();
            return uVar12;
          }
          uVar12 = *local_48;
          uVar3 = *puVar22;
          local_18[0] = 0x7f;
          local_6c = uVar25 + 0x4000;
          iVar23 = FUN_00009fac(local_6c,local_18,1);
          if (iVar23 != 0) {
            uVar12 = FUN_000107d6();
            return uVar12;
          }
          FUN_000001a0(&local_20,0xff);
          local_1c = (undefined1)((uint)uVar12 >> 0x18);
          local_1d = (undefined1)((uint)uVar12 >> 0x10);
          local_1e = (undefined1)((uint)uVar12 >> 8);
          local_1f = (undefined1)uVar12;
          local_20 = SUB41(puVar24,0);
          iVar23 = FUN_00009fac(&LAB_00004000_1 + uVar25,&local_20,5);
          if (iVar23 != 0) {
            uVar12 = FUN_000107d6();
            return uVar12;
          }
          local_18[0] = 0x3f;
          iVar23 = FUN_00009fac(local_6c,local_18,1);
          if (iVar23 != 0) {
            uVar12 = FUN_000107d6();
            return uVar12;
          }
          local_20 = 7;
          iVar23 = FUN_00009fac(uVar3 + 0x4000,&local_20,1);
          if (iVar23 != 0) {
            uVar12 = FUN_000107d6();
            return uVar12;
          }
          *puVar22 = uVar4;
          *(undefined1 *)((int)puVar24 + local_2c + 0x10) = 0;
        }
      }
      puVar22 = puVar22 + 1;
      local_48 = local_48 + 1;
    }
LAB_000109e6:
    local_84 = &local_1f;
    local_20 = 0x1f;
    iVar23 = FUN_00009fac(*puVar19 + 0x4000,&local_20,1);
    if (iVar23 != 0) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    uVar12 = *local_3c;
    uVar4 = *local_5c;
    local_18[0] = SUB41(local_60,0);
    iVar23 = FUN_00009fac(local_74,local_18,1);
    if (iVar23 != 0) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    FUN_000001a0(&local_20,0xff);
    local_1c = (undefined1)((uint)uVar12 >> 0x18);
    local_1d = (undefined1)((uint)uVar12 >> 0x10);
    local_1e = (undefined1)((uint)uVar12 >> 8);
    local_1f = (undefined1)uVar12;
    local_20 = SUB41(local_58,0);
    iVar23 = FUN_00009fac(local_74 + 1,&local_20,5);
    if (iVar23 != 0) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    local_18[0] = 0x3f;
    iVar23 = FUN_00009fac(local_74,local_18,1);
    if (iVar23 != 0) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    local_20 = 7;
    iVar23 = FUN_00009fac(uVar4 + 0x4000,&local_20,1);
    if (iVar23 != 0) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    *local_5c = (ushort)local_30;
    *(undefined1 *)((int)local_58 + local_2c + 0x10) = 0;
    if (2 < local_4c) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    iVar23 = FUN_0000a020(local_8c + 0x4000,local_64);
    if (iVar23 != 0) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    uVar4 = *(ushort *)(iVar15 + 0x32);
    uVar7 = (uint)uVar4;
    if (((uint)(PTR_LAB_00005ffe_1_00010c0c + (uint)*(byte *)(iVar15 + local_44) * local_38) &
        0xffff) < uVar7) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    uVar12 = *(undefined4 *)(DAT_00010c14 + 0x40);
    *(ushort *)(iVar14 + 0x40) = uVar4;
    *(ushort *)(iVar15 + 0x32) = uVar4 + 0x20;
    if (uVar7 == DAT_00010c08) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    local_18[0] = 0x7f;
    iVar15 = FUN_00009fac(uVar7 + 0x4000);
    if (iVar15 != 0) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    FUN_000001a0(&local_20,0xff);
    local_1c = (undefined1)((uint)uVar12 >> 0x18);
    local_1d = (undefined1)((uint)uVar12 >> 0x10);
    local_1e = (undefined1)((uint)uVar12 >> 8);
    local_1f = (undefined1)uVar12;
    local_20 = 0x10;
    iVar15 = FUN_00009fac(&LAB_00004000_1 + uVar7,&local_20,5);
    if (iVar15 != 0) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    local_18[0] = 0x3f;
    uVar26 = FUN_00009fac(uVar7 + 0x4000,local_18,1);
    if ((int)uVar26 != 0) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    FUN_0000ff42(0,(int)((ulonglong)uVar26 >> 0x20),local_2c);
    local_20 = SUB41(local_4c,0);
    iVar15 = FUN_00009fac(*extraout_r3_07 + 5,&local_20,1);
    uVar12 = ram0x00000005;
    if (iVar15 != 0) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    uVar4 = *local_58;
    local_18[0] = SUB41(local_5c,0);
    iVar15 = FUN_00009fac(local_74,local_18,1);
    if (iVar15 != 0) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    FUN_000001a0(&local_20,0xff);
    local_1c = (undefined1)((uint)uVar12 >> 0x18);
    local_1d = (undefined1)((uint)uVar12 >> 0x10);
    local_1e = (undefined1)((uint)uVar12 >> 8);
    local_1f = (undefined1)uVar12;
    local_20 = (undefined1)local_38;
    iVar15 = FUN_00009fac(local_74 + 1,&local_20,5);
    if (iVar15 != 0) {
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    local_18[0] = 0x3f;
    iVar15 = FUN_00009fac(local_74,local_18,1);
    if (iVar15 == 0) {
      local_20 = SUB41(local_84,0);
      iVar15 = FUN_00009fac(uVar4 + 5,&local_20,1);
      if (iVar15 != 0) {
        uVar12 = FUN_000107d6();
        return uVar12;
      }
      *local_58 = (ushort)local_6c;
      *(undefined1 *)(local_2c + local_38 + 0x10) = 0;
      if (local_44 < 3) {
        uVar26 = FUN_0000a020(0xc,local_64);
        if ((int)uVar26 == 0) {
          FUN_0000ff42(0,(int)((ulonglong)uVar26 >> 0x20),local_2c);
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        uVar12 = FUN_000107d6();
        return uVar12;
      }
      uVar12 = FUN_000107d6();
      return uVar12;
    }
    uVar12 = FUN_000107d6();
    return uVar12;
  }
  uVar1 = *(undefined1 *)(DAT_0000ff88 + 5);
  local_30 = 1;
  *(undefined1 *)(DAT_0000ff88 + 5) = 1;
  if (*(int *)(iVar15 + 100) == 0) {
    FUN_000107ba();
    local_2c = extraout_r2;
  }
  local_40 = DAT_0000ff94;
  *(undefined1 *)(iVar15 + 6) = 0;
  FUN_0000a020(0x30000,DAT_0000fff8 + 0x20);
  *(undefined4 *)(iVar15 + 100) = 0;
  FUN_000096f8(0);
  uVar25 = local_40[0x11];
  uVar7 = local_40[0x10];
  iVar23 = uVar7 - uVar25;
  if (uVar7 < uVar25) {
    iVar23 = 0;
  }
  iVar8 = local_2c;
  if (uVar7 <= uVar25) {
    FUN_000107ba();
    iVar8 = extraout_r2_00;
  }
  uVar7 = DAT_0000fffc;
  puVar6 = DAT_0000fff4;
  local_38 = 0x21;
  if (iVar23 + (uint)*(byte *)(iVar8 + 0x21) < 0xd1) {
    if (*(ushort *)(iVar14 + 0x42) != DAT_0000fffc) {
      bVar2 = *(byte *)(iVar8 + 0x21);
      uVar7 = (uint)bVar2 + iVar23;
      *(char *)(iVar8 + 0x21) = (char)uVar7;
      local_40[0x11] = local_40[0x11] + iVar23;
      uVar27 = (ulonglong)CONCAT14(bVar2,(uint)*(ushort *)(iVar14 + 0x42));
      if (*(ushort *)(iVar14 + 0x42) == DAT_0000fffc) {
        uVar27 = FUN_000107ba();
        uVar7 = extraout_r3_02;
      }
      iVar15 = (int)(uVar27 >> 0x20);
      uVar25 = (uint)uVar27;
      uVar17 = uVar7 & 0xff;
      iVar23 = uVar17 - 8;
      if (uVar17 < 8) {
        iVar23 = 0;
      }
      uVar20 = 0xff;
      for (uVar7 = uVar7 - (iVar23 + 7U & 0x1f8); (uVar7 & 0xff) != 0; uVar7 = uVar7 - 1) {
        uVar20 = uVar20 >> 1;
      }
      uVar7 = (iVar23 + 7U & 0xff) >> 3;
      if (uVar17 - iVar15 != 1) {
        iVar15 = iVar15 + -8;
        if (uVar27 < 0x800000000) {
          iVar15 = 0;
        }
        uVar17 = (iVar15 + 7U & 0xff) >> 3;
        if (uVar7 != uVar17) {
          iVar15 = 0;
          while (iVar15 < (int)(uVar7 - uVar17)) {
            local_20 = 0;
            iVar23 = FUN_00009fac((uVar17 + iVar15 & 0xff) + (uint)*(ushort *)(iVar14 + 0x42) +
                                  0x4006,&local_20,1);
            iVar15 = iVar15 + 1;
            if (iVar23 != 0) {
              uVar12 = FUN_000107ba();
              return uVar12;
            }
          }
          uVar25 = (uint)*(ushort *)(iVar14 + 0x42);
        }
      }
      local_20 = (char)uVar20;
      FUN_00009fac(uVar7 + uVar25 + 0x4006,&local_20,1);
      uVar12 = FUN_000107ba();
      return uVar12;
    }
  }
  else {
    local_3c = DAT_0000fff4;
    DAT_0000fff4[0x11] = iVar23 + uVar25 + -1;
    uVar4 = *(ushort *)(iVar14 + 0x42);
    if (uVar4 != uVar7) {
      local_4c = (ushort *)(uint)*(byte *)(iVar15 + 0x26);
      iVar23 = _LAB_00010000 + 1;
      uVar7 = (int)local_4c * iVar23 + _LAB_00010000;
      uVar3 = *(ushort *)(iVar15 + 0x32);
      local_44 = (uint)uVar3;
      if (local_44 <= (uVar7 & 0xffff)) {
        *(ushort *)(iVar15 + 0x32) = uVar3 + 0x20;
        local_20 = 0x1f;
        iVar15 = FUN_00009fac(uVar4 + 0x4000);
        if (iVar15 != 0) {
          uVar12 = FUN_000107ba();
          return uVar12;
        }
        if (local_44 == DAT_00010408) {
          uVar12 = FUN_000107ba();
          return uVar12;
        }
        uVar4 = *(ushort *)(iVar14 + 0x42);
        uVar12 = puVar6[0x11];
        local_18[0] = 0x7f;
        iVar15 = FUN_00009fac(local_44 + 0x4000,local_18,1);
        if (iVar15 != 0) {
          uVar12 = FUN_000107ba();
          return uVar12;
        }
        FUN_000001a0(&local_20,0xff);
        local_1c = (undefined1)((uint)uVar12 >> 0x18);
        local_1d = (undefined1)((uint)uVar12 >> 0x10);
        local_1e = (undefined1)((uint)uVar12 >> 8);
        local_1f = (undefined1)uVar12;
        local_20 = 0x11;
        iVar15 = FUN_00009fac(&LAB_00004000_1 + local_44,&local_20,5);
        if (iVar15 == 0) {
          local_18[0] = 0x3f;
          iVar15 = FUN_00009fac(local_44 + 0x4000,local_18,1);
          if (iVar15 != 0) {
            uVar12 = FUN_000107ba();
            return uVar12;
          }
          local_20 = 7;
          iVar15 = FUN_00009fac(uVar4 + 0x4000,&local_20,1);
          if (iVar15 == 0) {
            *(ushort *)(iVar14 + 0x42) = uVar3;
            *(undefined1 *)(local_2c + 0x21) = 0;
            uVar12 = FUN_0000fe26();
            return uVar12;
          }
          uVar12 = FUN_000107ba();
          return uVar12;
        }
        uVar12 = FUN_000107ba();
        return uVar12;
      }
      uVar25 = (int)local_4c + 1;
      *(char *)(iVar15 + 0x26) = (char)uVar25;
      if (1 < (uVar25 & 0xff)) {
        uVar25 = 0;
        *(undefined1 *)(iVar15 + 0x26) = 0;
        *(undefined2 *)(iVar15 + 0x32) = 0;
        local_44 = 0;
      }
      if ((iVar23 * (uVar25 & 0xff) + _LAB_00010000 & 0xffff) < local_44) {
        uVar7 = FUN_000107ba();
      }
      *(ushort *)(iVar15 + 0x32) = (ushort)local_44 + 0x20;
      local_20 = 0x1f;
      iVar8 = FUN_00009fac((uVar7 - 0x1f & 0xffff) + 0x4000);
      if (iVar8 != 0) {
        FUN_000107ba();
      }
      local_64 = 0x7f;
      local_20 = 0x7f;
      iVar9 = local_44 + 0x4000;
      iVar8 = FUN_00009fac(iVar9,&local_20,1);
      if (iVar8 != 0) {
        FUN_000107ba();
      }
      local_6c = _LAB_00010004 + 0x20;
      local_8c = (int)local_4c * local_6c;
      uVar7 = local_8c + _LAB_00010004 & DAT_0000fff8;
      local_60 = (ushort *)(iVar14 + 0x20);
      iVar8 = 0;
      while( true ) {
        uVar26 = CONCAT44(iVar8,uVar7);
        if (iVar8 == (int)&MemManage + 2) {
          uVar26 = FUN_000107ba();
          local_60 = extraout_r3;
        }
        puVar19 = (ushort *)((ulonglong)uVar26 >> 0x20);
        uVar7 = (uint)uVar26;
        if (uVar7 == *local_60) break;
        local_60 = local_60 + 1;
        local_3c = local_3c + 1;
        iVar8 = (int)puVar19 + 1;
      }
      puVar22 = (ushort *)(iVar14 + 0x20);
      local_74 = 0xe000;
      puVar24 = (ushort *)0x0;
      while( true ) {
        if (puVar24 == (ushort *)((int)&MemManage + 2)) break;
        if ((puVar19 != puVar24) && (uVar7 = (uint)*puVar22, uVar7 != DAT_000107e0)) {
          uVar25 = (uint)*(byte *)(iVar15 + 0x26) * local_6c;
          local_5c = puVar22;
          local_58 = puVar24;
          if ((uVar7 < (uVar25 & 0xe000)) || ((DAT_000107e4 + uVar25 + 0x1f & 0xffff) < uVar7)) {
            uVar4 = *(ushort *)(iVar15 + 0x32);
            uVar25 = (uint)uVar4;
            if ((iVar23 * (uint)*(byte *)(iVar15 + 0x26) + DAT_000107e8 & 0xffff) < uVar25) {
              uVar12 = FUN_000107ba();
              return uVar12;
            }
            *(ushort *)(iVar15 + 0x32) = uVar4 + 0x20;
            local_20 = 0x1f;
            iVar8 = FUN_00009fac(uVar7 + 0x4000,&local_20,1);
            if (iVar8 != 0) {
              uVar12 = FUN_000107ba();
              return uVar12;
            }
            if (uVar25 == DAT_000107e0) {
              uVar12 = FUN_000107ba();
              return uVar12;
            }
            uVar3 = *puVar22;
            local_18[0] = 0x7f;
            iVar8 = FUN_00009fac(uVar25 + 0x4000,local_18,1);
            if (iVar8 != 0) {
              uVar12 = FUN_000107ba();
              return uVar12;
            }
            FUN_000001a0(&local_20,0xff);
            local_20 = SUB41(puVar24,0);
            iVar8 = FUN_00009fac(&LAB_00004000_1 + uVar25,&local_20,5);
            if (iVar8 != 0) {
              uVar12 = FUN_000107ba();
              return uVar12;
            }
            local_18[0] = 0x3f;
            iVar8 = FUN_00009fac(uVar25 + 0x4000,local_18,1);
            if (iVar8 != 0) {
              uVar12 = FUN_000107ba();
              return uVar12;
            }
            local_20 = 7;
            iVar8 = FUN_00009fac(uVar3 + 0x4000,&local_20,1);
            if (iVar8 != 0) {
              uVar12 = FUN_000107ba();
              return uVar12;
            }
            *puVar22 = uVar4;
            *(undefined1 *)((int)puVar24 + local_2c + 0x10) = 0;
          }
        }
        puVar22 = puVar22 + 1;
        puVar24 = (ushort *)((int)puVar24 + 1);
      }
      local_20 = 0x1f;
      iVar23 = FUN_00009fac(*local_60 + 0x4000,&local_20,1);
      if (iVar23 != 0) {
        uVar12 = FUN_000107ba();
        return uVar12;
      }
      uVar12 = *local_3c;
      local_3c = (undefined4 *)(uint)*local_60;
      local_18[0] = 0x7f;
      iVar23 = FUN_00009fac(iVar9,local_18,1);
      if (iVar23 != 0) {
        uVar12 = FUN_000107ba();
        return uVar12;
      }
      FUN_000001a0(&local_20,0xff);
      local_1c = (undefined1)((uint)uVar12 >> 0x18);
      local_1d = (undefined1)((uint)uVar12 >> 0x10);
      local_1e = (undefined1)((uint)uVar12 >> 8);
      local_1f = (undefined1)uVar12;
      local_20 = (undefined1)((ulonglong)uVar26 >> 0x20);
      iVar23 = FUN_00009fac(&LAB_00004000_1 + local_44,&local_20,5);
      if (iVar23 != 0) {
        uVar12 = FUN_000107ba();
        return uVar12;
      }
      local_18[0] = 0x3f;
      iVar23 = FUN_00009fac(iVar9,local_18,1);
      if (iVar23 != 0) {
        uVar12 = FUN_000107ba();
        return uVar12;
      }
      local_20 = 7;
      iVar23 = FUN_00009fac(local_3c + 0x1000,&local_20,1);
      if (iVar23 != 0) {
        uVar12 = FUN_000107ba();
        return uVar12;
      }
      *local_60 = (ushort)local_44;
      *(undefined1 *)((int)puVar19 + local_2c + 0x10) = 0;
      if (2 < local_4c) {
        uVar12 = FUN_000107ba();
        return uVar12;
      }
      uVar26 = FUN_0000a020(local_8c + 0x4000,local_6c);
      if ((int)uVar26 != 0) {
        uVar12 = FUN_000107ba();
        return uVar12;
      }
      FUN_0000fe26(0,(int)((ulonglong)uVar26 >> 0x20),local_2c);
      puVar19 = extraout_r3_06;
      goto LAB_000109e6;
    }
  }
  iVar23 = 0x26;
  uVar17 = (uint)*(byte *)(iVar15 + 0x26);
  iVar8 = _LAB_00010000 + 1;
  uVar7 = uVar17 * iVar8 + _LAB_00010000;
  uVar25 = (uint)*(ushort *)(iVar15 + 0x32);
  if (uVar25 <= (uVar7 & 0xffff)) {
    uVar7 = FUN_0001074a();
    iVar23 = extraout_r2_03;
  }
  uVar20 = uVar17 + 1;
  *(char *)(iVar15 + iVar23) = (char)uVar20;
  if (1 < (uVar20 & 0xff)) {
    uVar20 = 0;
    *(undefined1 *)(iVar15 + iVar23) = 0;
    *(undefined2 *)(iVar15 + 0x32) = 0;
    uVar25 = 0;
  }
  if ((iVar8 * (uVar20 & 0xff) + _LAB_00010000 & 0xffff) < uVar25) {
    uVar7 = FUN_000107ba();
  }
  *(ushort *)(iVar15 + 0x32) = (ushort)uVar25 + 0x20;
  local_20 = 0x1f;
  iVar9 = FUN_00009fac((uVar7 - 0x1f & 0xffff) + 0x4000);
  if (iVar9 != 0) {
    FUN_000107ba();
  }
  local_20 = 0x7f;
  iVar9 = uVar25 + 0x4000;
  iVar10 = FUN_00009fac(iVar9,&local_20,1);
  if (iVar10 != 0) {
    FUN_000107ba();
  }
  iVar11 = _LAB_00010004 + 0x20;
  iVar16 = uVar17 * iVar11;
  uVar7 = iVar16 + _LAB_00010004 & DAT_0000fff8;
  puVar19 = (ushort *)(iVar14 + 0x20);
  iVar10 = 0;
  while( true ) {
    if (iVar10 == 0x12) {
      uVar7 = FUN_000107ba();
      puVar19 = extraout_r2_04;
      iVar10 = extraout_r3_03;
    }
    if (uVar7 == *puVar19) break;
    puVar19 = puVar19 + 1;
    local_40 = local_40 + 1;
    iVar10 = iVar10 + 1;
  }
  local_4c = (ushort *)(iVar14 + 0x20);
  uVar12 = 7;
  iVar21 = 0;
  do {
    if (iVar21 == 0x12) {
      local_20 = 0x1f;
      iVar21 = FUN_00009fac(*puVar19 + 0x4000,&local_20,1,iVar10,iVar16,uVar12);
      uVar28 = (undefined1)uVar12;
      if (iVar21 != 0) {
        uVar12 = FUN_000107ba();
        return uVar12;
      }
      uVar12 = *local_40;
      uVar4 = *puVar19;
      local_18[0] = 0x7f;
      iVar21 = FUN_00009fac(iVar9,local_18,1);
      if (iVar21 == 0) {
        FUN_000001a0(&local_20,0xff);
        local_1c = (undefined1)((uint)uVar12 >> 0x18);
        local_1d = (undefined1)((uint)uVar12 >> 0x10);
        local_1e = (undefined1)((uint)uVar12 >> 8);
        local_1f = (undefined1)uVar12;
        local_20 = (undefined1)iVar10;
        iVar21 = FUN_00009fac(&LAB_00004000_1 + uVar25,&local_20,5);
        if (iVar21 == 0) {
          local_18[0] = 0x3f;
          iVar9 = FUN_00009fac(iVar9,local_18,1);
          if ((iVar9 == 0) &&
             (local_20 = uVar28, iVar9 = FUN_00009fac(uVar4 + 0x4000,&local_20,1), iVar9 == 0)) {
            *puVar19 = (ushort)uVar25;
            *(undefined1 *)(local_2c + iVar10 + 0x10) = 0;
            if ((uVar17 < 3) && (iVar9 = FUN_0000a020(iVar16 + 0x4000,iVar11), iVar9 == 0)) {
              uVar4 = *(ushort *)(iVar15 + 0x32);
              uVar7 = (uint)uVar4;
              if (uVar7 <= ((uint)*(byte *)(iVar15 + iVar23) * iVar8 + DAT_000107e8 & 0xffff)) {
                uVar12 = DAT_000107dc[0x11];
                *(ushort *)(iVar14 + 0x42) = uVar4;
                *(ushort *)(iVar15 + 0x32) = uVar4 + 0x20;
                if (uVar7 != DAT_000107e0) {
                  local_18[0] = 0x7f;
                  iVar14 = FUN_00009fac(uVar7 + 0x4000);
                  if (iVar14 == 0) {
                    FUN_000001a0(&local_20,0xff);
                    local_1c = (undefined1)((uint)uVar12 >> 0x18);
                    local_1d = (undefined1)((uint)uVar12 >> 0x10);
                    local_1e = (undefined1)((uint)uVar12 >> 8);
                    local_1f = (undefined1)uVar12;
                    local_20 = 0x11;
                    iVar14 = FUN_00009fac(&LAB_00004000_1 + uVar7,&local_20,5);
                    if (iVar14 == 0) {
                      local_18[0] = 0x3f;
                      uVar26 = FUN_00009fac(uVar7 + 0x4000,local_18,1);
                      if ((int)uVar26 == 0) {
                        FUN_0000fe26(0,(int)((ulonglong)uVar26 >> 0x20),local_2c);
                      }
                    }
                  }
                }
              }
            }
          }
        }
        *(undefined1 *)(iVar15 + 5) = 0;
        uVar7 = 0;
        bVar5 = (bool)isCurrentModePrivileged();
        if (bVar5) {
          uVar7 = isIRQinterruptsEnabled();
        }
        disableIRQinterrupts();
        FUN_00009094(9);
        FUN_0000918c();
        bVar5 = (bool)isCurrentModePrivileged();
        if (bVar5) {
          enableIRQinterrupts((uVar7 & 1) == 1);
        }
        *(undefined1 *)(iVar15 + 5) = uVar1;
        return 0;
      }
      uVar12 = FUN_000107ba();
      return uVar12;
    }
    if ((iVar10 != iVar21) && (uVar7 = (uint)*local_4c, uVar7 != DAT_00010408)) {
      uVar18 = (uint)*(byte *)(iVar15 + iVar23) * iVar11;
      uVar20 = uVar18 & 0xe000;
      if ((uVar7 < uVar20) ||
         (uVar20 = DAT_00010410, (DAT_00010410 + uVar18 + 0x1f & 0xffff) < uVar7)) {
        uVar4 = *(ushort *)(iVar15 + 0x32);
        uVar18 = (uint)uVar4;
        if ((iVar8 * (uint)*(byte *)(iVar15 + iVar23) + DAT_0001040c & 0xffff) < uVar18) {
          uVar12 = FUN_000107ba();
          return uVar12;
        }
        *(ushort *)(iVar15 + 0x32) = uVar4 + 0x20;
        local_20 = 0x1f;
        iVar13 = FUN_00009fac(uVar7 + 0x4000,&local_20,1,uVar20,iVar16,uVar12);
        if (iVar13 != 0) {
          uVar12 = FUN_000107ba();
          return uVar12;
        }
        if (uVar18 == DAT_00010408) {
          uVar12 = FUN_000107ba();
          return uVar12;
        }
        uVar3 = *local_4c;
        local_18[0] = 0x7f;
        iVar13 = FUN_00009fac(uVar18 + 0x4000,local_18,1);
        if (iVar13 != 0) {
          uVar12 = FUN_000107ba();
          return uVar12;
        }
        FUN_000001a0(&local_20,0xff);
        local_20 = (undefined1)iVar21;
        iVar13 = FUN_00009fac(&LAB_00004000_1 + uVar18,&local_20,5);
        if (iVar13 != 0) {
          uVar12 = FUN_000107ba();
          return uVar12;
        }
        local_18[0] = 0x3f;
        iVar13 = FUN_00009fac(uVar18 + 0x4000,local_18,1);
        if (iVar13 != 0) {
          uVar12 = FUN_000107ba();
          return uVar12;
        }
        local_20 = (undefined1)uVar12;
        iVar13 = FUN_00009fac(uVar3 + 0x4000,&local_20,1);
        if (iVar13 != 0) {
          uVar12 = FUN_000107ba();
          return uVar12;
        }
        *local_4c = uVar4;
        *(undefined1 *)(local_2c + iVar21 + 0x10) = 0;
      }
    }
    local_4c = local_4c + 1;
    iVar21 = iVar21 + 1;
  } while( true );
}

