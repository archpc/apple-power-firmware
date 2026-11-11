
undefined4 switchD_0000e1fa::caseD_3(undefined2 param_1,uint param_2,int param_3,int param_4)

{
  int *unaff_r5;
  uint in_stack_00000010;
  int in_stack_00000024;
  
  if (param_4 == DAT_0000ef40) {
    *(undefined2 *)((param_2 & 3) * 2 + param_3 + 0x5e) = param_1;
    FUN_00008efc();
  }
  *(undefined4 *)(DAT_0000ef58 + 0x4c) = 0;
  *unaff_r5 = (in_stack_00000010 & 0xfffff80f) + in_stack_00000024 * 0x40 + 0x10;
  return 1;
}

