
int FUN_0000a8c0(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  
  iVar2 = DAT_0000a904;
  if (*(char *)(DAT_0000a904 + 0x13) == '\0') {
    iVar3 = FUN_0000a840();
    cVar4 = -1;
    if ((iVar3 == 1) && (iVar3 = FUN_00001f84(), iVar3 != 0)) {
      uVar5 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar5 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      cVar4 = '\x01';
      iVar3 = FUN_0000a840();
      if (iVar3 == 1) {
        *(undefined1 *)(iVar2 + 0x13) = 1;
      }
      else {
        FUN_0000a908(1);
        cVar4 = -1;
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar5 & 1) == 1);
      }
    }
  }
  else {
    cVar4 = '\x01';
  }
  return (int)cVar4;
}

