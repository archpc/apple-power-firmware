
int FUN_00000774(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (*param_1 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = param_1[1];
    if (param_3 <= param_1[1]) {
      iVar1 = param_3;
    }
    FUN_00000170(*param_1,param_2,iVar1);
    *param_1 = *param_1 + iVar1;
    param_1[1] = param_1[1] - iVar1;
  }
  return iVar1;
}

