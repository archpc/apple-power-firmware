
undefined8 FUN_000017cc(ushort *param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  ushort *puVar7;
  ushort *local_18;
  
  local_18 = param_1;
  for (iVar3 = 0; iVar3 != param_3; iVar3 = iVar3 + 1) {
    uVar1 = *(ushort *)(param_2 + iVar3 * 2);
    puVar2 = local_18;
    for (iVar6 = 0; iVar6 != 0x10; iVar6 = iVar6 + 1) {
      uVar5 = 0;
      puVar7 = puVar2;
      for (uVar4 = (uint)uVar1 * (uint)*(ushort *)(param_4 + iVar6 * 2); uVar4 != 0 || uVar5 != 0;
          uVar4 = uVar4 >> 0x10) {
        uVar5 = (uVar4 & 0xffff) + uVar5 + (uint)*puVar7;
        *puVar7 = (ushort)uVar5;
        uVar5 = uVar5 >> 0x10;
        puVar7 = puVar7 + 1;
      }
      puVar2 = puVar2 + 1;
    }
    local_18 = local_18 + 1;
  }
  return CONCAT44(param_3,param_2);
}

