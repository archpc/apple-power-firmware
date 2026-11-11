
void FUN_000068b4(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    uVar1 = 0x1000;
  }
  else if (param_2 == 2) {
    uVar1 = 0x2000;
  }
  else {
    uVar1 = 0;
    if (param_2 == 0xd) {
      if (*(char *)(DAT_0000690c + param_1 * 0x1cc + 0x175) != '\0') {
        FUN_00003140(param_1);
      }
    }
    else if (param_2 == 0xc) {
      FUN_00005b5c(param_1);
    }
    else if (param_2 == 9) {
      uVar1 = 0x100;
    }
  }
  FUN_000028b8(param_1,uVar1);
  return;
}

