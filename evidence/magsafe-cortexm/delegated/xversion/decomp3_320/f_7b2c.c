
void FUN_00007b2c(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = DAT_00007b6c;
  if (param_2 != 0) {
    uVar1 = DAT_00007b70;
  }
  iVar2 = *(int *)(DAT_00007b74 + param_1 * 4);
  *(uint *)(iVar2 + 0x18c) = *(uint *)(iVar2 + 0x18c) & uVar1;
  FUN_00008e2c(param_1,param_2);
  param_2 = DAT_00007b78 + param_1 * 0x1cc + param_2;
  *(undefined1 *)(param_2 + 0x3a) = 4;
  *(undefined1 *)(param_2 + 0x38) = 4;
  return;
}

