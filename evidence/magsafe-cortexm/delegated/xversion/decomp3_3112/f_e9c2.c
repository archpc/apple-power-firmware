
undefined4 switchD_0000e27a::caseD_8(int param_1,int param_2,uint param_3,uint param_4)

{
  uint in_stack_00000010;
  int *in_stack_00000014;
  int in_stack_00000024;
  
  *(uint *)(param_1 + 0x14) = param_4 & param_3;
  *(char *)(DAT_0000ec10 + 0x22) = (char)*(undefined4 *)(param_2 + 0x14);
  *in_stack_00000014 = (in_stack_00000010 & 0xfffff80f) + in_stack_00000024 * 0x40 + 0x10;
  return 1;
}

