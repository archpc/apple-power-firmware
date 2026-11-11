
undefined4 switchD_0000e1fa::caseD_2(int param_1)

{
  uint in_stack_00000010;
  uint *in_stack_00000014;
  int in_stack_00000020;
  
  if (param_1 == 0) {
    *in_stack_00000014 = in_stack_00000010 & 0xfffff80f | 0x30;
  }
  else {
    *in_stack_00000014 = in_stack_00000010 & 0xfffff80f | in_stack_00000020 << 6 | 0x10;
  }
  return 1;
}

