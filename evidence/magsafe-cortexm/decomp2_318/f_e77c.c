
undefined4 switchD_0000e1fa::caseD_16(int param_1,int param_2,int param_3,int param_4)

{
  uint extraout_r2;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  uint *in_stack_00000014;
  int iStack00000030;
  
  iStack00000030 = (uint)*(byte *)(param_1 + 0x5d) * 0x10000 + param_2 + param_3 + param_4;
  FUN_00000170(in_stack_0000000c,&stack0x00000030,4);
  FUN_0000e1b8(in_stack_00000010);
  *in_stack_00000014 = extraout_r2 | 0x30;
  return 1;
}

