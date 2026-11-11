
undefined4 FUN_0001074a(void)

{
  bool bVar1;
  int iVar2;
  int unaff_r4;
  int unaff_r5;
  int iVar3;
  uint uVar4;
  undefined4 unaff_r7;
  undefined8 uVar5;
  int in_stack_00000068;
  undefined4 in_stack_0000006c;
  undefined1 in_stack_00000070;
  int in_stack_00000074;
  undefined1 uStack00000078;
  undefined1 uStack00000079;
  undefined1 uStack0000007a;
  undefined1 uStack0000007b;
  undefined1 in_stack_0000007c;
  undefined1 in_stack_00000080;
  
  *(short *)(in_stack_00000074 + 0x42) = (short)unaff_r5;
  *(short *)(unaff_r4 + 0x32) = (short)unaff_r5 + 0x20;
  if (unaff_r5 != DAT_000107e0) {
    in_stack_00000080 = 0x7f;
    iVar3 = unaff_r5 + in_stack_00000068 * 0x4000;
    iVar2 = FUN_00009fac(iVar3);
    if (iVar2 == 0) {
      FUN_000001a0(&stack0x00000078,0xff);
      in_stack_0000007c = (undefined1)((uint)unaff_r7 >> 0x18);
      uStack0000007b = (undefined1)((uint)unaff_r7 >> 0x10);
      uStack0000007a = (undefined1)((uint)unaff_r7 >> 8);
      uStack00000079 = (undefined1)unaff_r7;
      uStack00000078 = 0x11;
      iVar2 = FUN_00009fac(iVar3 + 1,&stack0x00000078,5);
      if (iVar2 == 0) {
        in_stack_00000080 = 0x3f;
        uVar5 = FUN_00009fac(iVar3,&stack0x00000080,1);
        if ((int)uVar5 == 0) {
          FUN_0000fe26(0,(int)((ulonglong)uVar5 >> 0x20),in_stack_0000006c);
        }
      }
    }
  }
  *(undefined1 *)(unaff_r4 + 5) = 0;
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  FUN_00009094(9);
  FUN_0000918c();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  *(undefined1 *)(unaff_r4 + 5) = in_stack_00000070;
  return 0;
}

