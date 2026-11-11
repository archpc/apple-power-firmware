
void FUN_00005e56(int param_1,uint param_2)

{
  int unaff_r7;
  
  if (param_2 >> 0x1c == 0) {
    FUN_00000170(DAT_00005fe0);
    *(undefined1 *)(unaff_r7 + 0x43) = 2;
    FUN_000030f0();
    (*(code *)**(undefined4 **)(unaff_r7 + 0x60))();
  }
  else {
    FUN_00000170(param_1 + 0x22);
    FUN_00000170();
    FUN_00003258();
  }
  return;
}

