
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void switchD_00003ba4::caseD_3(int param_1,int param_2)

{
  int *unaff_r5;
  int unaff_r6;
  
  if (param_1 != param_2) {
    FUN_00003088();
  }
  *(undefined4 *)(unaff_r6 + 0x104) = *(undefined4 *)(*unaff_r5 + 8);
  (**(code **)(*(int *)(unaff_r6 + 0x60) + 0x40))();
  return;
}

