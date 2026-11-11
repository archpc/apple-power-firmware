
void FUN_00008e58(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = DAT_00008e88;
  if (param_2 != 0) {
    uVar2 = DAT_00008e8c;
  }
  iVar1 = *(int *)(DAT_00008e90 + param_1 * 4);
  *(uint *)(iVar1 + 0x18c) = *(uint *)(iVar1 + 0x18c) & uVar2;
  if (param_2 == 0) {
    uVar2 = 0x100000;
  }
  else {
    uVar2 = 0x200000;
  }
  *(uint *)(iVar1 + 0x18c) = *(uint *)(iVar1 + 0x18c) | uVar2;
  return;
}

