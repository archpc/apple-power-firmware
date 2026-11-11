
uint FUN_00001730(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = 0;
  for (iVar2 = 0; iVar2 != 0x20; iVar2 = iVar2 + 4) {
    uVar4 = *(uint *)(param_1 + iVar2);
    uVar3 = *(int *)(param_2 + iVar2) + uVar1;
    *(uint *)(param_1 + iVar2) = uVar4 - uVar3;
    if (uVar3 != 0) {
      uVar1 = (uint)(uVar4 < uVar3);
    }
  }
  return uVar1;
}

