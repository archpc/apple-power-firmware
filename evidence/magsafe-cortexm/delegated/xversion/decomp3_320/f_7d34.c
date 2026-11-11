
void FUN_00007d34(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 < 2) {
    uVar1 = DAT_00007d5c;
    if (param_2 != 0) {
      uVar1 = DAT_00007d60;
    }
    iVar2 = *(int *)(DAT_00007d64 + param_1 * 4);
    *(uint *)(iVar2 + 0x18c) = *(uint *)(iVar2 + 0x18c) & uVar1;
    FUN_00008e58();
  }
  return;
}

