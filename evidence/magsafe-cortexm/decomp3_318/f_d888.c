
void FUN_0000d888(int param_1)

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
    *DAT_0000d8fc = *DAT_0000d8fc & 0xfffffffb;
    WaitForInterrupt();
    FUN_00000b58();
  }
  else if ((param_1 == 2) && (iVar3 = FUN_0000a788(), iVar2 = DAT_0000d900, -1 < iVar3)) {
    iVar3 = *DAT_0000d8f8;
    *(byte *)(DAT_0000d900 + 0x33) = (byte)((uint)iVar3 >> 0x1f);
    if (iVar3 < 0) {
      FUN_00012b30();
    }
    FUN_000129f0();
    if (*(char *)(iVar2 + 0x33) != '\0') {
      FUN_00012af0();
    }
    if ((*(char *)(iVar2 + 0xc) == '\x01') && (iVar3 = FUN_00001ff0(), iVar3 == 0)) {
      FUN_00002178();
      FUN_0000ba30();
      *(undefined1 *)(iVar2 + 0xc) = 0;
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  return;
}

