
bool FUN_0000d484(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = iVar1;
    if (iVar2 + 4 == 0x24) break;
    iVar1 = iVar2 + 4;
  } while (*(int *)(DAT_0000d4a4 + iVar2 + 0x48) == *(int *)(param_1 + iVar2));
  return iVar2 == 0x20;
}

