
undefined4 FUN_0000eb88(void)

{
  uint uVar1;
  undefined4 uVar2;
  int extraout_r3;
  uint extraout_r3_00;
  int *unaff_r5;
  uint in_stack_00000014;
  
  uVar1 = FUN_0000e354(in_stack_00000014);
  FUN_0000ecb0();
  if (extraout_r3 != 1) {
    *unaff_r5 = (in_stack_00000014 & 0xfffff80f) + 0x20;
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

