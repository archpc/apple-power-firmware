
void switchD_00004218::caseD_4(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 in_cr11;
  
  coprocessor_storelong(0xd,in_cr11,param_4 + -0x40);
  iVar1 = (**(code **)(param_3 + 0x1c))();
  if (iVar1 != 0) {
    FUN_00006ec8();
    return;
  }
  FUN_0000301a();
  FUN_00003258();
  return;
}

