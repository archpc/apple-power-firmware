
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void switchD_00004468::caseD_2(void)

{
  int iVar1;
  int unaff_r5;
  
  iVar1 = (**(code **)(unaff_r5 + 0x20))();
  if (iVar1 == 0) {
    (**(code **)(unaff_r5 + 0x28))();
    FUN_000031a0();
    return;
  }
  iVar1 = FUN_0000c880();
  if (iVar1 != 0) {
    FUN_00002908();
  }
  return;
}

