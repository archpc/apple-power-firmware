
uint FUN_00001244(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar2 = DAT_000012a0;
  if (*(char *)(DAT_0000129c + 0x111) != '\0') {
    iVar4 = (uint)**(byte **)(DAT_0000129c + 0x114) * 0x10;
    uVar5 = *(undefined4 *)(DAT_0000129c + iVar4);
    uVar3 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar3 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    *(undefined4 *)(DAT_000012a0 + 0x14) = *(undefined4 *)(DAT_0000129c + iVar4 + 4);
    *(undefined4 *)(iVar2 + 0x10) = uVar5;
    if (*DAT_000012a4 == '\0') {
      *DAT_00001298 = 0x100;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar3 & 1) == 1);
    }
    return uVar3;
  }
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  *(undefined4 *)(DAT_000012a0 + 0x14) = 0;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  return uVar3;
}

