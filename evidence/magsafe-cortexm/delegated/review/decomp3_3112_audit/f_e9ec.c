
undefined4 switchD_0000e27a::caseD_20(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  uint extraout_r2;
  int *unaff_r5;
  undefined4 in_stack_0000000c;
  uint in_stack_00000010;
  uint *in_stack_00000014;
  
  iVar1 = (*(code *)*param_3)(in_stack_0000000c,param_1 + param_2);
  if (iVar1 == 0) {
    FUN_0000e238(in_stack_00000010);
    *in_stack_00000014 = extraout_r2 | 0x30;
  }
  else {
    *unaff_r5 = (in_stack_00000010 & 0xfffff80f) + 0x10;
  }
  return 1;
}

