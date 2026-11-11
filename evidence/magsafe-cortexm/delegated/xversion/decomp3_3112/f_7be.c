
int FUN_000007be(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  
  cVar1 = *param_1;
  iVar2 = 0;
  if ((param_2 != 0) && (cVar1 != '\0')) {
    iVar2 = 0;
    do {
      bVar3 = cVar1 == '\0';
      cVar1 = param_1[iVar2 + 1];
      param_2 = param_2 - (~(uint)bVar3 & 1);
      iVar2 = iVar2 + 1;
      if (param_2 == 0) {
        return iVar2;
      }
    } while (cVar1 != '\0');
  }
  return iVar2;
}

