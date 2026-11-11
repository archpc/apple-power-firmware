
undefined4 FUN_0000eb00(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int extraout_r3;
  uint extraout_r3_00;
  uint unaff_r4;
  int *unaff_r5;
  int iVar4;
  undefined4 in_stack_0000000c;
  int *in_stack_00000010;
  uint in_stack_00000014;
  undefined4 *in_stack_0000001c;
  
  iVar3 = unaff_r4 - param_4;
  iVar4 = 0;
  if (unaff_r4 < param_4) {
    iVar3 = 0;
  }
  uVar2 = iVar3 + param_1;
  if (uVar2 < param_2) {
    if (uVar2 + 0x18 < param_2) {
      iVar4 = 0x18;
    }
    else {
      iVar4 = param_2 - uVar2;
    }
    iVar3 = (*(code *)*in_stack_0000001c)(in_stack_0000000c,uVar2 + 0x30000,iVar4);
    if (iVar3 != 0) {
      *in_stack_00000010 = (in_stack_00000014 & 0xfffff80f) + 0x10;
      return 1;
    }
  }
  uVar2 = FUN_0000e354(in_stack_00000014,in_stack_00000010,in_stack_0000000c,iVar4);
  FUN_0000ecb0();
  if (extraout_r3 != 1) {
    *unaff_r5 = (in_stack_00000014 & 0xfffff80f) + 0x20;
    return 1;
  }
  uVar2 = (uVar2 & 0xffff) >> 10;
  if (0x28 < uVar2) {
    FUN_0000eca0();
    uVar2 = extraout_r3_00;
  }
                    /* WARNING: Could not recover jumptable at 0x0000e416. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(&PTR_FUN_0000e418)[uVar2])();
  return uVar1;
}

