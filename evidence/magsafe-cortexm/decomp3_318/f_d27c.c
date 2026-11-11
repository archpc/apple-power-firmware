
undefined4 FUN_0000d27c(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  do {
    if (iVar2 + 4 == 0x24) {
      return 1;
    }
    piVar1 = (int *)(param_1 + iVar2);
    iVar3 = DAT_0000d29c + iVar2;
    iVar2 = iVar2 + 4;
  } while (*(int *)(iVar3 + 0x48) == *piVar1);
  return 0;
}

