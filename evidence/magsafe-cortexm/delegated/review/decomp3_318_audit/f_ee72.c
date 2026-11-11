
undefined4 switchD_0000e1fa::caseD_c(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int unaff_r4;
  int unaff_r5;
  uint in_stack_00000010;
  int *in_stack_00000014;
  int in_stack_00000024;
  
  uVar1 = (uint)(unaff_r5 * param_2) >> 7;
  uVar2 = uVar1;
  if (unaff_r4 == 0) {
    uVar2 = 0;
  }
  *DAT_0000ef34 = uVar2;
  if (unaff_r4 != 0) {
    uVar1 = param_1;
  }
  *DAT_0000ef38 = uVar1;
  *(uint *)(DAT_0000ef58 + 0x4c) = param_1;
  *(undefined1 *)(DAT_0000ef4c + 1) = 3;
  *in_stack_00000014 = (in_stack_00000010 & 0xfffff80f) + in_stack_00000024 * 0x40 + 0x10;
  return 1;
}

