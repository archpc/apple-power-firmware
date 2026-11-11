
undefined4 FUN_000107d6(void)

{
  bool bVar1;
  int unaff_r4;
  uint uVar2;
  undefined1 in_stack_0000006c;
  
  *(undefined1 *)(unaff_r4 + 5) = 0;
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  FUN_00008f54(9);
  FUN_00009058();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar2 & 1) == 1);
  }
  *(undefined1 *)(unaff_r4 + 5) = in_stack_0000006c;
  return 0;
}

