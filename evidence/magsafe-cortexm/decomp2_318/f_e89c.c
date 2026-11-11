
void switchD_0000e1fa::caseD_0(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint unaff_r5;
  uint unaff_r6;
  uint unaff_r7;
  uint in_stack_00000004;
  undefined4 in_stack_00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  undefined4 in_stack_00000014;
  uint in_stack_00000020;
  
  do {
    iVar2 = FUN_00007e4c(unaff_r6,unaff_r7,3);
    uVar3 = FUN_00007e4c(unaff_r6,unaff_r7,2);
    FUN_00000880(iVar2 << 0x10,uVar3);
    unaff_r5 = unaff_r5 + 1;
    while (unaff_r5 == 2) {
      in_stack_00000020 = in_stack_00000020 + 1;
      if (in_stack_00000020 == 2) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          enableIRQinterrupts((in_stack_00000004 & 1) == 1);
        }
        uVar3 = FUN_0000077a(in_stack_0000000c,0x18,DAT_0000eba0,in_stack_00000008);
        FUN_0000e1b8(in_stack_00000010,in_stack_00000014,in_stack_0000000c,uVar3);
        return;
      }
      unaff_r5 = 0;
    }
    unaff_r6 = unaff_r5 & 0xff;
    unaff_r7 = in_stack_00000020 & 0xff;
  } while( true );
}

