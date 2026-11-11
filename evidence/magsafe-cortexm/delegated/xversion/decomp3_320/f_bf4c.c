
void FUN_0000bf4c(uint param_1,int param_2,code *param_3)

{
  byte bVar1;
  bool bVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int local_70;
  uint local_60;
  undefined4 local_5c [2];
  undefined1 local_54;
  uint local_50;
  undefined4 local_44;
  uint local_34 [7];
  ushort local_18;
  
  uVar12 = *(uint *)(param_2 + 8);
  FUN_0000a908(1);
  iVar5 = DAT_0000c2c8;
  iVar6 = DAT_0000c2c4;
  uVar9 = DAT_0000c2b8;
  if (-1 < (int)(uVar12 << 0x10)) {
    uVar9 = *(uint *)(param_2 + 8);
    iVar5 = FUN_0000be2c(DAT_0000c2c4 + param_1 * 0x20,uVar9 >> 0x10);
    if (iVar5 + 1 == 0) {
      local_44._0_2_ = CONCAT11(3,(char)local_44);
      goto LAB_0000c154;
    }
    local_70 = iVar6 + param_1 * 0x20;
    if (*(char *)(local_70 + iVar5 * 0x10 + 0x15) == '\0') {
      return;
    }
    if ((uVar9 & 0xf) == 0xf) {
      if (uVar9 != DAT_0000c2c0) {
        return;
      }
      uVar9 = 0xf;
      iVar6 = iVar5 + 1;
      goto LAB_0000bf9c;
    }
    param_1 = (uint)*(byte *)(local_70 + iVar5 * 0x10 + 0xc);
    local_70 = 0;
    goto LAB_0000c0c6;
  }
  local_70 = 1;
  if (*(char *)(DAT_0000c2c8 + 0x21) == '\x02') {
    FUN_0000c5f8(param_1,param_1 != 1,param_2,param_3);
    return;
  }
  if ((DAT_0000c2bc + 0xc0 & uVar12) == 0xff000000) {
    if (param_1 == 1) {
      local_50 = uVar12 & DAT_0000c2b8 + 0xc0;
      *(uint *)(DAT_0000c2c8 + 0x5c) = local_50;
      *(code **)(iVar5 + 0x60) = param_3;
      local_54 = 0x1e;
      local_60 = local_60 & 0xffffff00;
      local_5c[0] = CONCAT31(local_5c[0]._1_3_,1);
      iVar6 = FUN_0000290c(0,0xc,&local_60,DAT_0000c2cc);
      puVar3 = DAT_0000c2d0;
      if (iVar6 == 0) {
        return;
      }
      uVar9 = 0;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        uVar9 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_000012d0(DAT_0000c2d0);
      uVar4 = FUN_000011a0(500,0,DAT_0000c2d4,0);
      *puVar3 = uVar4;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        enableIRQinterrupts((uVar9 & 1) == 1);
        return;
      }
      return;
    }
    FUN_000001a0(&local_60,0,0x1c);
    local_60 = uVar9 & uVar12 | 0x40;
    if ((uVar12 & 0x1f) == 2) {
      local_44 = CONCAT31(local_44._1_3_,1);
      local_5c[0] = *(undefined4 *)(DAT_0000c2dc + param_1 * 4);
    }
    else if ((uVar12 & 0x1f) == 1) {
      local_44 = CONCAT31(local_44._1_3_,3);
      FUN_00000170(local_5c,DAT_0000c2d8 + param_1 * 0xc);
    }
    else {
      local_60 = uVar9 & uVar12 | 0x80;
    }
    local_44 = CONCAT31((int3)(local_44 >> 8),(char)local_44 + '\x01') & 0xffff00ff;
    goto LAB_0000c154;
  }
  if ((uVar12 & DAT_0000c2bc) == 0xff000000) {
    return;
  }
  uVar9 = *(uint *)(param_2 + 8);
  iVar7 = FUN_0000be2c(DAT_0000c2c4 + param_1 * 0x20,uVar9 >> 0x10);
  local_18 = local_18 & 0xff00;
  FUN_000001a0(local_34,0,0x1c);
  if (iVar7 == -1) {
    if ((uVar9 & 0xff) >> 6 != 0) {
      return;
    }
    if ((uVar9 & 0x1f) == 6) {
      return;
    }
    local_18 = 1;
    local_34[0] = uVar9 & 0xffffffbf | 0x80;
    goto LAB_0000c154;
  }
  uVar10 = uVar9 & 0x1f;
  uVar12 = uVar9 >> 8 & 7;
  uVar13 = 1 << uVar12;
  iVar6 = iVar6 + param_1 * 0x20;
  pbVar8 = (byte *)(iVar6 + iVar7 * 0x10 + 0xc);
  if (uVar10 == 5) {
    if ((uVar9 & 0xff) >> 6 == 0) {
      iVar6 = iVar6 + iVar7 * 0x10;
      if (((*(byte *)(iVar6 + 0x15) & uVar13) != uVar13) && (uVar12 != 7)) {
        bVar1 = 1;
        local_34[0] = uVar9 & 0xffffff7f | 0x40;
        goto LAB_0000c2b2;
      }
      if ((uVar12 == 7) || (uVar12 == 1)) {
        if (uVar12 != 7) {
          if (uVar12 != 1) goto LAB_0000c20a;
          uVar12 = (uint)*pbVar8;
          iVar11 = DAT_0000c2e0 + uVar12 * 0x30;
          *(undefined1 *)(iVar11 + 10) = 1;
          iVar7 = FUN_0000ca50(uVar12,0x99);
          if (iVar7 != 0) {
            FUN_0000ca08(uVar12,0x99);
          }
          *(undefined1 *)(iVar5 + 0x21) = 0;
          iVar5 = DAT_0000c2e4;
          *(undefined4 *)(DAT_0000c2e4 + uVar12 * 0x14) = DAT_0000c2e8;
          *(undefined1 *)(iVar11 + 0x2b) = 0;
          iVar5 = iVar5 + uVar12 * 0x14;
          *(undefined4 *)(iVar5 + 0x10) = 1;
          *(int *)(iVar5 + 0xc) = iVar11;
          *(undefined4 *)(iVar5 + 8) = DAT_0000c2ec;
          *(undefined4 *)(iVar5 + 4) = 0;
          *(undefined2 *)(iVar11 + 0x28) = 0;
        }
        pbVar8 = (byte *)(iVar6 + 0x15);
        bVar1 = 1;
        local_34[0] = uVar9 & 0xffffff7f | 0x40;
        if ((uVar9 & 0x700) == 0x700) {
          *pbVar8 = 0;
          bVar1 = 1;
        }
        else {
          *pbVar8 = *pbVar8 & ~(byte)uVar13;
        }
        goto LAB_0000c2b2;
      }
    }
  }
  else if (uVar10 == 4) {
    if ((uVar9 & 0xff) >> 6 == 0) {
      iVar6 = iVar6 + iVar7 * 0x10;
      bVar1 = *(byte *)(iVar6 + 0x15);
      if ((uVar13 & bVar1) == 0) {
        if ((uVar9 & 0x700) != 0x100) goto LAB_0000c20a;
        *(undefined1 *)(DAT_0000c2e0 + (uint)*pbVar8 * 0x30 + 0x2a) = 9;
        *(byte *)(iVar6 + 0x15) = bVar1 | (byte)uVar13;
      }
      bVar1 = 1;
      local_34[0] = uVar9 & 0xffffff7f | 0x40;
LAB_0000c2b2:
      local_18 = (ushort)bVar1;
      goto LAB_0000c154;
    }
  }
  else if ((uVar10 == 3) && ((uVar9 & 0xff) >> 6 == 0)) {
    bVar1 = 2;
    local_34[1] = 2;
    local_34[0] = uVar9 & 0xffffff7f | 0x40;
    goto LAB_0000c2b2;
  }
LAB_0000c20a:
  param_1 = (uint)*pbVar8;
  uVar9 = *(uint *)(param_2 + 8);
  if (((uVar9 & 0xff) >> 6 != 0) || ((uVar9 & 0x1f) == 6)) {
    if ((*(uint *)(param_2 + 0xc) & 0xf) == 0xf) {
      iVar6 = param_2;
      if (uVar9 != DAT_0000c2c0) {
        return;
      }
LAB_0000bf9c:
      FUN_00010c4c(param_2,iVar6,uVar9,local_70);
      return;
    }
LAB_0000c0c6:
    FUN_0000c640(param_1,param_2,param_3,local_70);
    return;
  }
  local_44 = CONCAT22(local_44._2_2_,1);
  local_60 = uVar9 & 0xffffffbf | 0x80;
LAB_0000c154:
  (*param_3)(param_1);
  return;
}

