
undefined4 FUN_00008f0c(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 1;
  if (((byte)(*(char *)(DAT_00008f50 + 0x5c) + 1U) < 2) &&
     (*(int *)(DAT_00008f50 + 0x30) == DAT_00008f4c)) {
    iVar2 = DAT_00008f50 + param_2 + 0x30;
    uVar1 = 0;
    FUN_000001a2(iVar2,0,0x14);
    FUN_00000794(iVar2,param_1,0x13);
    FUN_00008efc();
  }
  return uVar1;
}

