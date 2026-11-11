
undefined4 FUN_00001822(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if (iVar2 + 4 == 0x24) {
      return 1;
    }
    piVar1 = (int *)(param_1 + iVar2);
    iVar2 = iVar2 + 4;
  } while (*piVar1 == 0);
  return 0;
}

