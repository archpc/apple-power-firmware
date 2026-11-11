
undefined4 FUN_0000b062(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 1) {
    iVar1 = FUN_0000b940();
  }
  else {
    iVar1 = FUN_0000b8d0();
  }
  iVar2 = FUN_00000830(param_2 * param_3,100);
  if (iVar1 < iVar2 + param_2) {
    return 0;
  }
  return 1;
}

