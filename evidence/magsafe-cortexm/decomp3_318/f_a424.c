
int FUN_0000a424(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar1 = FUN_00000880(400,param_1);
    do {
      iVar2 = iVar1;
      iVar1 = iVar2 + 1;
    } while ((uint)(iVar2 * param_1) < 300);
    return iVar2;
  }
  return 0;
}

