
void FUN_0000bcf4(void)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  
  *(undefined1 *)(DAT_0000bd20 + 0x18) = 1;
  puVar2 = DAT_0000bd24;
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  FUN_000012a8(DAT_0000bd24);
  uVar3 = FUN_00001178(1000,0,DAT_0000bd28,0);
  *puVar2 = uVar3;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  return;
}

