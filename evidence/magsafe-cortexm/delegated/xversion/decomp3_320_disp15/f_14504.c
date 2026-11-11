
void FUN_00014504(uint param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  
  iVar1 = (param_1 >> 4) * 4;
  puVar2 = *(uint **)(DAT_00014548 + iVar1);
  *puVar2 = *puVar2 | 1 << (param_1 & 0xf);
  iVar3 = (param_1 & 0xf) * 3;
  puVar2[2] = param_2 << iVar3 | puVar2[2] & ~(7 << iVar3);
  iVar3 = (param_1 & 0xf) << 2;
  puVar2 = *(uint **)(DAT_0001454c + iVar1);
  *puVar2 = 10 << iVar3 | *puVar2 & ~(0xf << iVar3);
  return;
}

