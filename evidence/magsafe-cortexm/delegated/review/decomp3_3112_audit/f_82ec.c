
undefined4 FUN_000082ec(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  
  iVar5 = DAT_0000835c + param_1 * 0x5c;
  bVar1 = *(byte *)(iVar5 + 0x50);
  iVar2 = *(int *)(DAT_00008360 + param_1 * 4);
  if (bVar1 != 0) {
    if (param_2 == 0) {
      uVar6 = (uint)((*(uint *)(iVar2 + 0xa0) & 0x18) == 0) * 8;
      iVar3 = 8;
    }
    else {
      uVar6 = 0;
      iVar3 = 0x10;
    }
    uVar4 = iVar3 + uVar6;
    pbVar7 = (byte *)(iVar5 + 0x51);
    do {
      if (uVar4 <= (uVar6 & 0xff)) {
        return 1;
      }
      *(undefined4 *)(iVar2 + (uVar6 & 0xff) * 4 + 0x10) =
           *(undefined4 *)(*(int *)(iVar5 + 0x40) + (uint)*pbVar7 * 4);
      *pbVar7 = *pbVar7 + 1;
      uVar6 = uVar6 + 1;
    } while (*pbVar7 < bVar1);
  }
  return 0;
}

