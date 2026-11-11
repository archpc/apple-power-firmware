
undefined4 FUN_0000e9be(void)

{
  int iVar1;
  int unaff_r6;
  int *in_stack_00000010;
  uint in_stack_00000014;
  undefined1 *in_stack_00000020;
  int in_stack_00000024;
  uint in_stack_00000030;
  
  if (unaff_r6 == 4) {
    if (0xfd < *(byte *)(DAT_0000edb0 + 0x5c) - 1) {
      *(undefined1 *)(DAT_0000edb0 + 0x67) = *in_stack_00000020;
      FUN_0000903c();
    }
  }
  else {
    if (unaff_r6 != 0) {
      FUN_00000170(&stack0x00000030,in_stack_00000020,4);
      if ((in_stack_00000030 & 0xff) < 2) {
        *(char *)(DAT_0000ed70 + 0x28) = (char)in_stack_00000030;
        iVar1 = (in_stack_00000014 & 0xfffff80f) + in_stack_00000024 * 0x40 + 0x10;
      }
      else {
        iVar1 = (in_stack_00000014 & 0xfffff80f) + 0x20;
      }
      *in_stack_00000010 = iVar1;
      return 1;
    }
    FUN_00000170(&stack0x00000030,in_stack_00000020,4);
    *(short *)(DAT_0000ed70 + 0x34) = (short)in_stack_00000030;
  }
  *in_stack_00000010 = (in_stack_00000014 & 0xfffff80f) + 0x110;
  return 1;
}

