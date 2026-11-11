
undefined4 FUN_0000b152(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 1) {
    iVar1 = FUN_0000bab4();
  }
  else {
    iVar1 = FUN_0000ba44();
  }
  iVar2 = FUN_0000084c(param_2 * param_3,100);
  if (iVar1 < iVar2 + param_2) {
    return 0;
  }
  return 1;
}

