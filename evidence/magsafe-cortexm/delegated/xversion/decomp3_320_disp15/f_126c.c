
uint FUN_0000126c(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar2 = DAT_000012c8;
  if (*(char *)(DAT_000012c4 + 0x111) != '\0') {
    iVar4 = (uint)**(byte **)(DAT_000012c4 + 0x114) * 0x10;
    uVar5 = *(undefined4 *)(DAT_000012c4 + iVar4);
    uVar3 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar3 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    *(undefined4 *)(DAT_000012c8 + 0xc) = *(undefined4 *)(DAT_000012c4 + iVar4 + 4);
    *(undefined4 *)(iVar2 + 8) = uVar5;
    if (*DAT_000012cc == '\0') {
      *DAT_000012c0 = 0x100;
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
  *(undefined4 *)(DAT_000012c8 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 8) = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  return uVar3;
}

