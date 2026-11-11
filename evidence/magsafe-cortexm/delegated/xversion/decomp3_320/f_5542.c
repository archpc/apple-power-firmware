
void FUN_00005542(int param_1,int param_2,int param_3)

{
  uint unaff_r4;
  uint *unaff_r5;
  undefined1 unaff_r6;
  int unaff_r7;
  
  if (param_1 == 0) {
    FUN_00005b5c();
  }
  else {
    FUN_0000b9dc();
    if (*(int *)(param_2 + 0x108) < 0) {
      FUN_00003140();
    }
    else {
      if (unaff_r4 < 2) {
        *(undefined1 *)(param_2 + param_3 + 0x78) = unaff_r6;
        *(undefined1 *)(param_2 + unaff_r7) = unaff_r6;
      }
      FUN_0000ca08();
    }
  }
  if (*unaff_r5 < DAT_000055e4 + 1U) {
    return;
  }
  FUN_00007260();
  return;
}

