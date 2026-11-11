
undefined4 FUN_0000ea80(uint param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_r3;
  uint extraout_r3_00;
  undefined4 unaff_r4;
  uint uVar4;
  uint uStack00000004;
  undefined4 in_stack_00000008;
  int *in_stack_0000000c;
  undefined4 in_stack_00000010;
  uint in_stack_00000014;
  uint uStack00000018;
  int in_stack_0000001c;
  uint uStack00000024;
  
  uStack00000018 = DAT_0000ed7c + 0xf1;
  uStack00000004 = param_1;
  uStack00000024 = param_2;
  for (; param_2 != 2; param_2 = param_2 + 1) {
    for (uVar4 = 0; uVar4 != 2; uVar4 = uVar4 + 1) {
      iVar2 = FUN_00007f90(uVar4 & 0xff,param_2 & 0xff,3);
      uVar3 = FUN_00007f90(uVar4 & 0xff,param_2 & 0xff,2);
      iVar2 = FUN_0000089c(iVar2 << 0x10,uVar3);
      uStack00000024 =
           in_stack_0000001c + uStack00000024 + ((int)(uStack00000018 * iVar2) >> 0x10) + 10;
    }
    unaff_r4 = in_stack_00000010;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uStack00000004 & 1) == 1);
  }
  uVar3 = FUN_000007a2(in_stack_0000000c,0x18,DAT_0000ed80,in_stack_00000008);
  uVar4 = FUN_0000e354(in_stack_00000014,unaff_r4,in_stack_0000000c,uVar3);
  FUN_0000ecb0();
  if (extraout_r3 != 1) {
    *in_stack_0000000c = (in_stack_00000014 & 0xfffff80f) + 0x20;
    return 1;
  }
  uStack00000018 = (in_stack_00000014 & 0x7ff) >> 6;
  uStack00000024 = uStack00000018;
  if (0x17 < uStack00000018) {
    uStack00000024 = 0x18;
  }
  uVar4 = (uVar4 & 0xffff) >> 10;
  if (0x28 < uVar4) {
    FUN_0000eca0();
    uVar4 = extraout_r3_00;
  }
                    /* WARNING: Could not recover jumptable at 0x0000e416. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*(code *)(&PTR_FUN_0000e418)[uVar4])();
  return uVar3;
}

