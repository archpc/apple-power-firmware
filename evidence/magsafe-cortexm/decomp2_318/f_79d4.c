
void FUN_000079d4(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = DAT_00007a14;
  if (param_2 != 0) {
    uVar1 = DAT_00007a18;
  }
  iVar2 = *(int *)(DAT_00007a1c + param_1 * 4);
  *(uint *)(iVar2 + 0x18c) = *(uint *)(iVar2 + 0x18c) & uVar1;
  FUN_00008cec(param_1,param_2);
  param_2 = DAT_00007a20 + param_1 * 0x1cc + param_2;
  *(undefined1 *)(param_2 + 0x3a) = 4;
  *(undefined1 *)(param_2 + 0x38) = 4;
  return;
}

