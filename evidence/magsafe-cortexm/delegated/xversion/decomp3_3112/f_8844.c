
undefined8 FUN_00008844(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  uint *puVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  uVar6 = 0x110;
  if (param_2 != 1) {
    uVar6 = 0;
  }
  iVar5 = *(int *)(DAT_0000893c + param_1 * 4);
  puVar2 = (uint *)(iVar5 + 0x18c);
  iVar9 = DAT_00008940 + param_1 * 0x1cc;
  uVar7 = (uint)*(byte *)(iVar9 + 0x15);
  bVar10 = (*(uint *)(iVar5 + 0x18c) & 0x110) != uVar6;
  if (bVar10) {
    *puVar2 = *puVar2 & 0xfffffeef;
    *puVar2 = *puVar2 | uVar6;
  }
  if (uVar7 == 1) {
    pbVar3 = (byte *)(DAT_00008944 + (uint)*(byte *)(iVar9 + 0x35) * 4);
    pbVar1 = pbVar3 + 1;
  }
  else {
    if (param_3 == 0) {
      iVar8 = 1;
    }
    else {
      iVar8 = 2;
    }
    pbVar1 = (byte *)(DAT_00008944 + 0xc + iVar8);
    pbVar3 = (byte *)(DAT_00008944 + 0xc + param_3);
  }
  uVar6 = (uint)*pbVar1 << 9 | (uint)*pbVar3 << 5;
  if ((*puVar2 & 0xee0) == uVar6) {
    uVar6 = uVar7;
    if (!bVar10) goto LAB_000088ea;
  }
  else {
    *puVar2 = *puVar2 & 0xfffff11f;
    *puVar2 = *puVar2 | uVar6;
  }
  FUN_00000b60(0x960);
  uVar6 = (uint)*(byte *)(iVar9 + 0x15);
LAB_000088ea:
  iVar9 = 2;
  if (uVar7 != 1) {
    iVar9 = param_3;
  }
  iVar8 = 2;
  if (param_3 == 0) {
    iVar8 = 1;
  }
  if (uVar6 == 1) {
    iVar8 = 1;
  }
  iVar4 = 3;
  uVar7 = *(uint *)(iVar5 + 0xa4) & 0x60000;
  if (uVar7 != 0x40000) {
    iVar8 = iVar9;
  }
  iVar5 = iVar8;
  if (uVar6 == 1) {
    iVar5 = 0;
  }
  if (uVar7 != 0) {
    iVar5 = iVar8;
  }
  if (param_3 == 0) {
    iVar4 = 2;
  }
  if ((uVar7 ^ 0x60000) + uVar6 == 0) {
    iVar5 = iVar4;
  }
  return CONCAT44(param_2,iVar5);
}

