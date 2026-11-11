
undefined4 FUN_0000904c(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 1;
  if (((byte)(*(char *)(DAT_00009090 + 0x5c) + 1U) < 2) &&
     (*(int *)(DAT_00009090 + 0x30) == DAT_0000908c)) {
    iVar2 = DAT_00009090 + param_2 + 0x30;
    uVar1 = 0;
    FUN_000001a0(iVar2,0,0x14);
    FUN_000007bc(iVar2,param_1,0x13);
    FUN_0000903c();
  }
  return uVar1;
}

