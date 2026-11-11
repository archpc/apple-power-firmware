
undefined4 switchD_0000e1fa::caseD_b(undefined4 param_1,undefined4 param_2)

{
  char in_ZR;
  undefined4 in_cr2;
  uint in_stack_00000010;
  int *in_stack_00000014;
  int in_stack_00000020;
  
  coprocessor_store(0xe,in_cr2,param_2);
  if (in_ZR == '\0') {
    *in_stack_00000014 = (in_stack_00000010 & 0xfffff80f) + in_stack_00000020 * 0x40 + 0x10;
  }
  else {
    *in_stack_00000014 = (in_stack_00000010 & 0xfffff80f) + 0x20;
  }
  return 1;
}

