
void FUN_0000576a(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int unaff_r4;
  int unaff_r6;
  uint unaff_r7;
  int iStack00000008;
  
  *(undefined1 *)(param_1 + param_2) = 0;
  iStack00000008 = param_4;
  FUN_0000ca08();
  (*(code *)**(undefined4 **)(iStack00000008 + unaff_r4 * 0x1cc + 0x60))();
  if ((unaff_r7 & 0xff0000) == unaff_r6 * 0x40000) {
    FUN_00003258();
    return;
  }
  FUN_00005b5c();
  return;
}

