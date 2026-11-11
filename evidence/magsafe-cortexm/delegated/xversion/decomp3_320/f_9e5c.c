
void FUN_00009e5c(void)

{
  bool bVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_00000e80();
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  FUN_0000991c();
  *(undefined8 *)(DAT_00009e80 + 0x58) = uVar3;
  FUN_00009dec();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar2 & 1) == 1);
  }
  return;
}

