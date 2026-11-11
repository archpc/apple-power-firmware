
void FUN_0000dac4(int param_1)

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
    FUN_00000b70();
    *DAT_0000db38 = *DAT_0000db38 & 0xfffffffb;
    WaitForInterrupt();
    FUN_00000b78();
  }
  else if ((param_1 == 2) && (iVar3 = FUN_0000a8c0(), iVar2 = DAT_0000db3c, -1 < iVar3)) {
    iVar3 = *DAT_0000db34;
    *(byte *)(DAT_0000db3c + 0x31) = (byte)((uint)iVar3 >> 0x1f);
    if (iVar3 < 0) {
      FUN_00012d8c();
    }
    FUN_00012c4c();
    if (*(char *)(iVar2 + 0x31) != '\0') {
      FUN_00012d4c();
    }
    if ((*(char *)(iVar2 + 0x13) == '\x01') && (iVar3 = FUN_00001f84(), iVar3 == 0)) {
      FUN_00002114();
      FUN_0000bba4();
      *(undefined1 *)(iVar2 + 0x13) = 0;
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  return;
}

