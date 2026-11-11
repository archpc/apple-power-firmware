
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00004a34(void)

{
  int iVar1;
  int unaff_r5;
  
  iVar1 = (**(code **)(unaff_r5 + 0x20))();
  if (iVar1 == 0) {
    (**(code **)(unaff_r5 + 0x28))();
    FUN_00003258();
    return;
  }
  iVar1 = FUN_0000ca50();
  if (iVar1 != 0) {
    FUN_000028b8();
  }
  return;
}

