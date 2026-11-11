
void FUN_00008fd4(int param_1)

{
  if (param_1 == 0xaa) {
    param_1 = 0xaa;
  }
  else {
    if (param_1 != 0xff) goto LAB_00008fec;
    param_1 = 0x55;
  }
  FUN_00008fa8(0xaa);
LAB_00008fec:
  FUN_00008fa8(param_1);
  return;
}

