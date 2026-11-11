
undefined4 FUN_0000ea64(void)

{
  undefined4 uVar1;
  char in_ZR;
  int *in_stack_00000010;
  uint in_stack_00000014;
  int in_stack_00000018;
  
  if (in_ZR == '\0') {
    uVar1 = FUN_0000eca0();
    return uVar1;
  }
  *in_stack_00000010 = (in_stack_00000014 & 0xfffff80f) + in_stack_00000018 * 0x40 + 0x10;
  return 1;
}

