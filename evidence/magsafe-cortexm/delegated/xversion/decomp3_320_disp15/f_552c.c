
void switchD_00004ee2::caseD_6(void)

{
  int iVar1;
  uint unaff_r4;
  uint *unaff_r5;
  undefined1 unaff_r6;
  undefined4 in_cr5;
  undefined4 in_cr9;
  undefined4 in_cr14;
  
  coprocessor_function2(0,9,1,in_cr14,in_cr5,in_cr9);
  iVar1 = DAT_000055ec + unaff_r4 * 0x1cc;
  if (*(char *)(iVar1 + 0x175) == '\0') {
    FUN_00005b5c();
  }
  else {
    FUN_0000b9dc();
    if (*(int *)(iVar1 + 0x108) < 0) {
      FUN_00003140();
    }
    else {
      if (unaff_r4 < 2) {
        *(undefined1 *)(iVar1 + 0x177) = unaff_r6;
        *(undefined1 *)(iVar1 + 0x175) = unaff_r6;
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

