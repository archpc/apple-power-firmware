
undefined4 FUN_0000eae4(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int extraout_r3;
  uint extraout_r3_00;
  undefined4 in_stack_00000008;
  int *in_stack_0000000c;
  uint in_stack_00000014;
  
  FUN_000007a2(in_stack_0000000c,param_2,DAT_0000ed80,in_stack_00000008);
  uVar1 = FUN_0000e354(in_stack_00000014);
  FUN_0000ecb0();
  if (extraout_r3 != 1) {
    *in_stack_0000000c = (in_stack_00000014 & 0xfffff80f) + 0x20;
    return 1;
  }
  uVar1 = (uVar1 & 0xffff) >> 10;
  if (0x28 < uVar1) {
    FUN_0000eca0();
    uVar1 = extraout_r3_00;
  }
                    /* WARNING: Could not recover jumptable at 0x0000e416. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)(&PTR_FUN_0000e418)[uVar1])();
  return uVar2;
}

