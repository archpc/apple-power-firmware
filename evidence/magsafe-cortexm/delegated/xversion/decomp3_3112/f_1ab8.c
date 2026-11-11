
void FUN_00001ab8(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  puVar1 = (uint *)(param_1 + 0x1c);
  uVar3 = 0;
  for (iVar2 = 7; -1 < iVar2; iVar2 = iVar2 + -1) {
    uVar4 = *puVar1;
    *puVar1 = (uVar4 >> 1) + uVar3 * -0x80000000;
    uVar3 = uVar4 & 1;
    puVar1 = puVar1 + -1;
  }
  return;
}

