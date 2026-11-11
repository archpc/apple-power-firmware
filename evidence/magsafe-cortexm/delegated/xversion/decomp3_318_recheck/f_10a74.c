
undefined4 FUN_00010a74(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_00010aa4;
  iVar3 = *(int *)(DAT_00010aa4 + 0x14);
  uVar2 = 0;
  if (((uint)(iVar3 + DAT_00010aa0) >> 0x11 == 0) && ((uint)(iVar3 + param_1) >> 0x10 < 3)) {
    FUN_00009fa4(iVar3,param_2,param_1);
    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + param_1;
    uVar2 = 1;
  }
  return uVar2;
}

