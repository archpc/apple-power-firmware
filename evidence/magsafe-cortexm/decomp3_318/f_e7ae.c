
undefined4 switchD_0000e1fa::caseD_28(void)

{
  undefined4 uVar1;
  int unaff_r7;
  char in_ZR;
  uint in_stack_00000010;
  int *in_stack_00000014;
  undefined1 *in_stack_0000001c;
  int in_stack_00000020;
  uint in_stack_00000030;
  
  if (in_ZR == '\0') {
    if (unaff_r7 != 0) {
      FUN_00000170(&stack0x00000030,in_stack_0000001c,4);
      if ((in_stack_00000030 & 0xff) == 0) {
        *(undefined1 *)(DAT_0000eb90 + 0x20) = 0;
        *in_stack_00000014 = (in_stack_00000010 & 0xfffff80f) + in_stack_00000020 * 0x40 + 0x10;
        return 1;
      }
      if ((in_stack_00000030 & 0xff) != 1) {
        *in_stack_00000014 = (in_stack_00000010 & 0xfffff80f) + 0x20;
        return 1;
      }
      uVar1 = caseD_25(1);
      return uVar1;
    }
    FUN_00000170(&stack0x00000030,in_stack_0000001c,4);
    *(short *)(DAT_0000eb90 + 0x36) = (short)in_stack_00000030;
  }
  else if ((byte)(*(char *)(DAT_0000ebac + 0x5c) + 1U) < 2) {
    *(undefined1 *)(DAT_0000ebac + 0x67) = *in_stack_0000001c;
    FUN_00008efc();
  }
  *in_stack_00000014 = (in_stack_00000010 & 0xfffff80f) + 0x110;
  return 1;
}

