
void FUN_00008e4c(uint param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = (param_1 & 0xf) << 2;
  puVar1 = *(uint **)(DAT_00008e6c + (param_1 >> 4) * 4);
  *puVar1 = param_2 << iVar2 | *puVar1 & ~(0xf << iVar2);
  return;
}

