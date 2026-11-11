
bool FUN_0000d85c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = param_3;
  uStack_14 = param_4;
  FUN_00001394(&uStack_18);
  iVar1 = DAT_0000d884;
  bVar2 = *(int *)(DAT_0000d884 + 0x50) == 0;
  if (bVar2) {
    *(undefined4 *)(DAT_0000d884 + 0x50) = param_1;
    *(undefined4 *)(iVar1 + 0x54) = param_2;
  }
  FUN_000013a8(&uStack_18);
  return bVar2;
}

