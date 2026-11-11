
uint FUN_00001706(int *param_1,uint *param_2,int *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = 0;
  for (; param_4 != 0; param_4 = param_4 + -1) {
    iVar2 = *param_3;
    param_3 = param_3 + 1;
    uVar3 = iVar2 + uVar1;
    uVar4 = *param_2;
    param_2 = param_2 + 1;
    if (uVar3 != 0) {
      uVar1 = (uint)(uVar4 < uVar3);
    }
    *param_1 = uVar4 - uVar3;
    param_1 = param_1 + 1;
  }
  return uVar1;
}

