
undefined4 FUN_000107ba(void)

{
  bool bVar1;
  int unaff_r4;
  uint uVar2;
  undefined1 in_stack_00000070;
  
  *(undefined1 *)(unaff_r4 + 5) = 0;
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  FUN_00009094(9);
  FUN_0000918c();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar2 & 1) == 1);
  }
  *(undefined1 *)(unaff_r4 + 5) = in_stack_00000070;
  return 0;
}

