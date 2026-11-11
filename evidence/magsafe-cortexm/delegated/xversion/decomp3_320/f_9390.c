
uint FUN_00009390(void)

{
  bool bVar1;
  uint uVar2;
  
  FUN_00012d14();
  FUN_00012d30();
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  *(uint *)(DAT_000093b0 + 0x4c) = *(uint *)(DAT_000093b0 + 0x4c) & 0xffffffef;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar2 & 1) == 1);
  }
  return uVar2;
}

