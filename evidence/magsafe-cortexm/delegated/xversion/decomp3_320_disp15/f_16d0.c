
undefined4 FUN_000016d0(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = param_3 * 4 + -4;
  puVar2 = (uint *)(param_2 + iVar3);
  puVar1 = (uint *)(param_1 + iVar3);
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) {
      return 0;
    }
    uVar4 = *puVar2;
    uVar5 = *puVar1;
    if (uVar4 < uVar5) break;
    puVar2 = puVar2 + -1;
    puVar1 = puVar1 + -1;
    if (uVar5 < uVar4) {
      return 0xffffffff;
    }
  }
  return 1;
}

