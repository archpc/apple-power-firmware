
void FUN_00008f64(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (param_1 & 0xf) * 3;
  iVar1 = *(int *)(DAT_00008f88 + (param_1 >> 4) * 4);
  *(uint *)(iVar1 + 8) = param_2 << iVar2 | *(uint *)(iVar1 + 8) & ~(7 << iVar2);
  return;
}

