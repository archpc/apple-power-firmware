
undefined4 FUN_0000e9e6(int param_1)

{
  int iVar1;
  uint extraout_r2;
  int *unaff_r5;
  undefined4 in_stack_0000000c;
  uint in_stack_00000010;
  uint *in_stack_00000014;
  undefined4 *in_stack_00000018;
  
  iVar1 = (*(code *)*in_stack_00000018)(in_stack_0000000c,param_1 + 0x30000);
  if (iVar1 == 0) {
    FUN_0000e238(in_stack_00000010);
    *in_stack_00000014 = extraout_r2 | 0x30;
  }
  else {
    *unaff_r5 = (in_stack_00000010 & 0xfffff80f) + 0x10;
  }
  return 1;
}

