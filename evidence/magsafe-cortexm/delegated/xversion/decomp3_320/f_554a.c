
void FUN_0000554a(undefined4 param_1,int param_2)

{
  uint unaff_r4;
  uint *unaff_r5;
  undefined1 unaff_r6;
  int unaff_r7;
  int in_stack_00000004;
  int iStack00000008;
  
  iStack00000008 = param_2;
  FUN_0000b9dc();
  if (*(int *)(iStack00000008 + 0x108) < 0) {
    FUN_00003140();
  }
  else {
    if (unaff_r4 < 2) {
      *(undefined1 *)(iStack00000008 + in_stack_00000004 + 0x78) = unaff_r6;
      *(undefined1 *)(iStack00000008 + unaff_r7) = unaff_r6;
    }
    FUN_0000ca08();
  }
  if (*unaff_r5 < DAT_000055e4 + 1U) {
    return;
  }
  FUN_00007260();
  return;
}

