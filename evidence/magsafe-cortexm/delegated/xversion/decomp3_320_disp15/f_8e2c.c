
void FUN_00008e2c(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0x500000;
  }
  else {
    uVar2 = 0xa00000;
  }
  iVar1 = *(int *)(DAT_00008e54 + param_1 * 4);
  *(uint *)(iVar1 + 0x18c) = *(uint *)(iVar1 + 0x18c) & 0xbfffffff | uVar2;
  return;
}

