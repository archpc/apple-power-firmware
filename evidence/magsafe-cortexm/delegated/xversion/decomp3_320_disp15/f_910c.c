
void FUN_0000910c(int param_1)

{
  if (param_1 != 0xaa) {
    if (param_1 != 0xff) goto LAB_00009120;
    param_1 = 0x55;
  }
  FUN_000090e0(0xaa);
LAB_00009120:
  FUN_000090e0(param_1);
  return;
}

