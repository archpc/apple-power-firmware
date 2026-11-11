
void FUN_00008df8(uint param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = 1 << (param_1 & 0xf);
  iVar1 = (param_1 >> 4) * 4;
  if (param_2 == 0) {
    puVar2 = *(uint **)(DAT_00008e20 + iVar1);
    uVar3 = *puVar2 & ~uVar3;
  }
  else {
    puVar2 = *(uint **)(DAT_00008e20 + iVar1);
    uVar3 = *puVar2 | uVar3;
  }
  *puVar2 = uVar3;
  return;
}

