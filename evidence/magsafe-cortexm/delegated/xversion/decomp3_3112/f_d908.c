
void FUN_0000d908(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  if (param_1 == 1) {
    FUN_00000b50();
    *DAT_0000d97c = *DAT_0000d97c & 0xfffffffb;
    WaitForInterrupt();
    FUN_00000b58();
  }
  else if ((param_1 == 2) && (iVar3 = FUN_0000a7dc(), iVar2 = DAT_0000d980, -1 < iVar3)) {
    iVar3 = *DAT_0000d978;
    *(byte *)(DAT_0000d980 + 0x33) = (byte)((uint)iVar3 >> 0x1f);
    if (iVar3 < 0) {
      FUN_00012bb0();
    }
    FUN_00012a70();
    if (*(char *)(iVar2 + 0x33) != '\0') {
      FUN_00012b70();
    }
    if ((*(char *)(iVar2 + 0xc) == '\x01') && (iVar3 = FUN_00001ff0(), iVar3 == 0)) {
      FUN_00002178();
      FUN_0000ba84();
      *(undefined1 *)(iVar2 + 0xc) = 0;
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  return;
}

