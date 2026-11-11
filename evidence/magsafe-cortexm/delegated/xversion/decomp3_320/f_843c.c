
undefined4 FUN_0000843c(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  
  iVar5 = DAT_000084b4 + param_1 * 0x5c;
  bVar1 = *(byte *)(iVar5 + 0x50);
  iVar2 = *(int *)(DAT_000084b8 + param_1 * 4);
  if (bVar1 != 0) {
    if (param_2 == 0) {
      iVar7 = (uint)((*(uint *)(iVar2 + 0xa0) & 0x18) == 0) * 8;
      iVar4 = 8;
    }
    else {
      iVar7 = 0;
      iVar4 = 0x10;
    }
    uVar6 = iVar7 - 1;
    pbVar3 = (byte *)(iVar5 + 0x51);
    puVar8 = (undefined4 *)(iVar7 * 4 + iVar2 + 0x10);
    do {
      uVar6 = uVar6 + 1;
      if ((uint)(iVar4 + iVar7) <= uVar6) break;
      *puVar8 = *(undefined4 *)(*(int *)(iVar5 + 0x40) + (uint)*pbVar3 * 4);
      *pbVar3 = *pbVar3 + 1;
      puVar8 = puVar8 + 1;
    } while (*pbVar3 < bVar1);
    if ((uint)(iVar4 + iVar7) <= uVar6) {
      return 1;
    }
  }
  return 0;
}

