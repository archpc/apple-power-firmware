
void FUN_000063e4(int param_1)

{
  undefined4 uVar1;
  
  if (*(byte *)(DAT_00006404 + param_1 * 0x1cc + 0x3e) < 2) {
    uVar1 = 4;
  }
  else {
    uVar1 = 0x10;
  }
  FUN_00006374(param_1,uVar1);
  return;
}

