
undefined4 FUN_0000173e(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  
  iVar3 = param_3 * 4 + -4;
  puVar1 = (uint *)(param_2 + iVar3);
  puVar4 = (uint *)(param_1 + iVar3);
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) {
      return 0;
    }
    uVar2 = *puVar1;
    uVar5 = *puVar4;
    if (uVar2 < uVar5) break;
    puVar1 = puVar1 + -1;
    puVar4 = puVar4 + -1;
    if (uVar5 < uVar2) {
      return 0xffffffff;
    }
  }
  return 1;
}

