
void FUN_00003da8(int param_1,undefined4 param_2,undefined1 param_3)

{
  int unaff_r5;
  int unaff_r6;
  bool in_ZR;
  bool in_CY;
  int iStack00000000;
  
  if (!in_CY || in_ZR) {
    *(undefined1 *)(unaff_r5 + param_1) = param_3;
  }
  *(undefined1 *)(unaff_r6 + 0xe6) = 0x11;
  iStack00000000 = unaff_r5 + 0x9c;
  FUN_00007172();
  return;
}

