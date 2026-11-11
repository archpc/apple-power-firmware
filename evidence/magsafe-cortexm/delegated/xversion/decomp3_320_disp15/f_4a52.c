
void FUN_00004a52(void)

{
  int iVar1;
  code *in_r3;
  int unaff_r5;
  
  iVar1 = (*in_r3)();
  if (iVar1 != 0) {
    iVar1 = FUN_0000ca50();
    if (iVar1 != 0) {
      FUN_000028b8();
    }
    return;
  }
  (**(code **)(unaff_r5 + 0x28))();
  FUN_00003258();
  return;
}

