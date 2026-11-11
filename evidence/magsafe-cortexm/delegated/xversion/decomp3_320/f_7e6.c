
int FUN_000007e6(char *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar1 = 0;
  if ((*param_1 != '\0') && (param_2 != 0)) {
    iVar2 = 0;
    do {
      iVar1 = iVar2 + 1;
      if (param_1[iVar2 + 1] == '\0') {
        return iVar1;
      }
      bVar3 = param_2 + -1 != iVar2;
      iVar2 = iVar1;
    } while (bVar3);
  }
  return iVar1;
}

