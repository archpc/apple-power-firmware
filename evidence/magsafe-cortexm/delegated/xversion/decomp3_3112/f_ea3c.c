
undefined4 switchD_0000e27a::caseD_a(int param_1,uint param_2)

{
  uint in_stack_00000010;
  int *in_stack_00000014;
  undefined1 *in_stack_0000001c;
  
  if (param_2 < 2) {
    *(undefined1 *)(param_1 + 0x67) = *in_stack_0000001c;
    FUN_00008efc();
  }
  *in_stack_00000014 = (in_stack_00000010 & 0xfffff80f) + 0x110;
  return 1;
}

