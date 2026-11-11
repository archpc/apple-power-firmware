
void FUN_0000bdf0(uint param_1,int param_2,code *param_3)

{
  byte bVar1;
  bool bVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  uint local_60;
  undefined4 local_5c [2];
  undefined1 local_54;
  uint local_50;
  undefined4 local_44;
  uint local_34 [7];
  ushort local_18;
  
  uVar9 = *(uint *)(param_2 + 8);
  uVar12 = 1;
  FUN_0000a7d0(1);
  iVar7 = DAT_0000c0e8;
  iVar5 = DAT_0000c0d0;
  uVar10 = DAT_0000c0c4;
  if (-1 < (int)(uVar9 << 0x10)) {
    uVar10 = *(uint *)(param_2 + 8);
    iVar5 = FUN_0000bcd4(DAT_0000c0e8 + param_1 * 0x20,uVar10 >> 0x10);
    if (iVar5 == -1) {
      local_44._0_2_ = CONCAT11(3,(char)local_44);
      goto LAB_0000bfc4;
    }
    iVar7 = iVar7 + param_1 * 0x20;
    if (*(char *)(iVar7 + iVar5 * 0x10 + 0x15) == '\0') {
      return;
    }
    if ((uVar10 & 0xf) == 0xf) {
      if (uVar10 != DAT_0000c0cc) {
        return;
      }
      goto LAB_0000be3c;
    }
    param_1 = (uint)*(byte *)(iVar7 + iVar5 * 0x10 + 0xc);
    uVar12 = 0;
    goto LAB_0000bf44;
  }
  if (*(char *)(DAT_0000c0d0 + 0x19) == '\x02') {
    FUN_0000c400(param_1,param_1 != 1,param_2,param_3);
    return;
  }
  if ((DAT_0000c0c8 + 0xc0 & uVar9) == 0xff000000) {
    if (param_1 == 1) {
      local_50 = uVar9 & DAT_0000c0c4 + 0xc0;
      *(uint *)(DAT_0000c0d0 + 100) = local_50;
      *(code **)(iVar5 + 0x68) = param_3;
      local_54 = 0x1e;
      local_60 = local_60 & 0xffffff00;
      local_5c[0] = CONCAT31(local_5c[0]._1_3_,1);
      iVar5 = FUN_0000295c(0,0xc,&local_60,DAT_0000c0d4);
      puVar3 = DAT_0000c0d8;
      if (iVar5 == 0) {
        return;
      }
      uVar10 = 0;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        uVar10 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_000012a8(DAT_0000c0d8);
      uVar4 = FUN_00001178(500,0,DAT_0000c0dc,0);
      *puVar3 = uVar4;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        enableIRQinterrupts((uVar10 & 1) == 1);
        return;
      }
      return;
    }
    FUN_000001a2(&local_60,0,0x1c);
    local_60 = uVar10 & uVar9 | 0x40;
    if ((uVar9 & 0x1f) == 2) {
      local_44 = CONCAT31(local_44._1_3_,1);
      local_5c[0] = *(undefined4 *)(DAT_0000c0e4 + param_1 * 4);
    }
    else if ((uVar9 & 0x1f) == 1) {
      local_44 = CONCAT31(local_44._1_3_,3);
      FUN_00000170(local_5c,DAT_0000c0e0 + param_1 * 0xc);
    }
    else {
      local_60 = uVar10 & uVar9 | 0x80;
    }
    local_44 = CONCAT31((int3)(local_44 >> 8),(char)local_44 + '\x01') & 0xffff00ff;
    goto LAB_0000bfc4;
  }
  if ((uVar9 & DAT_0000c0c8) == 0xff000000) {
    return;
  }
  uVar10 = *(uint *)(param_2 + 8);
  iVar5 = FUN_0000bcd4(DAT_0000c0e8 + param_1 * 0x20,uVar10 >> 0x10);
  local_18 = local_18 & 0xff00;
  FUN_000001a2(local_34,0,0x1c);
  if (iVar5 == -1) {
    if ((uVar10 & 0xff) >> 6 != 0) {
      return;
    }
    if ((uVar10 & 0x1f) == 6) {
      return;
    }
    local_18 = 1;
    local_34[0] = uVar10 & 0xffffffbf | 0x80;
    goto LAB_0000bfc4;
  }
  uVar9 = uVar10 & 0x1f;
  uVar8 = uVar10 >> 8 & 7;
  uVar11 = 1 << uVar8;
  iVar7 = iVar7 + param_1 * 0x20;
  pbVar6 = (byte *)(iVar7 + iVar5 * 0x10 + 0xc);
  if (uVar9 == 5) {
    if ((uVar10 & 0xff) >> 6 == 0) {
      iVar7 = iVar7 + iVar5 * 0x10;
      if ((uVar8 != 7) && ((*(byte *)(iVar7 + 0x15) & uVar11) != uVar11)) {
LAB_0000c072:
        local_18._0_1_ = 1;
        goto LAB_0000c076;
      }
      if (uVar8 != 7) {
        if (uVar8 != 1) goto LAB_0000c024;
        FUN_0000c6dc(*pbVar6);
      }
      pbVar6 = (byte *)(iVar7 + 0x15);
      local_18._0_1_ = 1;
      local_34[0] = uVar10 & 0xffffff7f | 0x40;
      if ((uVar10 & 0x700) == 0x700) {
        *pbVar6 = 0;
      }
      else {
        *pbVar6 = *pbVar6 & ~(byte)uVar11;
        local_18._0_1_ = 1;
      }
LAB_0000c086:
      local_18 = (ushort)(byte)local_18;
      goto LAB_0000bfc4;
    }
  }
  else if (uVar9 == 4) {
    if ((uVar10 & 0xff) >> 6 == 0) {
      iVar7 = iVar7 + iVar5 * 0x10;
      bVar1 = *(byte *)(iVar7 + 0x15);
      if ((uVar11 & bVar1) != 0) goto LAB_0000c072;
      if ((uVar10 & 0x700) == 0x100) {
        *(undefined1 *)(DAT_0000c0ec + (uint)*pbVar6 * 0x30 + 0x2a) = 9;
        local_18._0_1_ = 1;
        *(byte *)(iVar7 + 0x15) = bVar1 | (byte)uVar11;
        goto LAB_0000c076;
      }
    }
  }
  else if ((uVar9 == 3) && ((uVar10 & 0xff) >> 6 == 0)) {
    local_18._0_1_ = 2;
    local_34[1] = 2;
LAB_0000c076:
    local_34[0] = uVar10 & 0xffffff7f | 0x40;
    goto LAB_0000c086;
  }
LAB_0000c024:
  uVar10 = *(uint *)(param_2 + 8);
  param_1 = (uint)*pbVar6;
  if (((uVar10 & 0xff) >> 6 != 0) || ((uVar10 & 0x1f) == 6)) {
    if ((*(uint *)(param_2 + 0xc) & 0xf) == 0xf) {
      if (uVar10 != DAT_0000c0cc) {
        return;
      }
LAB_0000be3c:
      FUN_00010aa8(param_2);
      return;
    }
LAB_0000bf44:
    FUN_0000c448(param_1,param_2,param_3,uVar12);
    return;
  }
  local_44 = CONCAT22(local_44._2_2_,1);
  local_60 = uVar10 & 0xffffffbf | 0x80;
LAB_0000bfc4:
  (*param_3)(param_1);
  return;
}

