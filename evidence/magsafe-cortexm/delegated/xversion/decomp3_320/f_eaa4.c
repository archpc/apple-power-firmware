
undefined4 FUN_0000eaa4(int param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int extraout_r3;
  uint extraout_r3_00;
  uint unaff_r5;
  uint unaff_r6;
  uint unaff_r7;
  uint in_stack_00000004;
  undefined4 in_stack_00000008;
  int *in_stack_0000000c;
  undefined4 in_stack_00000010;
  uint in_stack_00000014;
  uint in_stack_00000020;
  
  do {
    uVar3 = FUN_00007f90(unaff_r7,unaff_r6,2);
    FUN_0000089c(param_1 << 0x10,uVar3);
    unaff_r5 = unaff_r5 + 1;
    while (unaff_r5 == 2) {
      in_stack_00000020 = in_stack_00000020 + 1;
      if (in_stack_00000020 == 2) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          enableIRQinterrupts((in_stack_00000004 & 1) == 1);
        }
        uVar3 = FUN_000007a2(in_stack_0000000c,0x18,DAT_0000ed80,in_stack_00000008);
        uVar2 = FUN_0000e354(in_stack_00000014,in_stack_00000010,in_stack_0000000c,uVar3);
        FUN_0000ecb0();
        if (extraout_r3 != 1) {
          *in_stack_0000000c = (in_stack_00000014 & 0xfffff80f) + 0x20;
          return 1;
        }
        uVar2 = (uVar2 & 0xffff) >> 10;
        if (0x28 < uVar2) {
          FUN_0000eca0();
          uVar2 = extraout_r3_00;
        }
                    /* WARNING: Could not recover jumptable at 0x0000e416. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar3 = (*(code *)(&PTR_FUN_0000e418)[uVar2])();
        return uVar3;
      }
      unaff_r5 = 0;
    }
    unaff_r7 = unaff_r5 & 0xff;
    unaff_r6 = in_stack_00000020 & 0xff;
    param_1 = FUN_00007f90(unaff_r7,unaff_r6,3);
  } while( true );
}

