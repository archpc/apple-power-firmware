
undefined4 FUN_0000ec36(int param_1,int param_2)

{
  int iVar1;
  int *in_stack_00000010;
  uint in_stack_00000014;
  undefined4 in_stack_00000020;
  int in_stack_00000024;
  uint in_stack_00000030;
  
  if (param_2 == param_1) {
    iVar1 = FUN_0000da90(DAT_0000edac,0);
    if (iVar1 == 0) {
      iVar1 = 0x30;
    }
    else {
      iVar1 = 0x110;
    }
    *in_stack_00000010 = (in_stack_00000014 & 0xfffff80f) + iVar1;
  }
  else {
    FUN_00000170(&stack0x00000030,in_stack_00000020,4);
    if ((in_stack_00000030 & 0xff) < 2) {
      *(char *)(DAT_0000ed70 + 0x28) = (char)in_stack_00000030;
      iVar1 = (in_stack_00000014 & 0xfffff80f) + in_stack_00000024 * 0x40 + 0x10;
    }
    else {
      iVar1 = (in_stack_00000014 & 0xfffff80f) + 0x20;
    }
    *in_stack_00000010 = iVar1;
  }
  return 1;
}

