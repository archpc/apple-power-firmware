
void FUN_000007bc(char *param_1,char *param_2,int param_3)

{
  int iVar1;
  
  while( true ) {
    if (param_3 == 0) {
      return;
    }
    if (*param_2 == '\0') break;
    *param_1 = *param_2;
    param_3 = param_3 + -1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  iVar1 = 0;
  do {
    param_1[iVar1] = '\0';
    iVar1 = iVar1 + 1;
  } while (param_3 != iVar1);
  return;
}

