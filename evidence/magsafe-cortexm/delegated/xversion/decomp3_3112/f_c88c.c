
void FUN_0000c88c(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = 0;
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  iVar2 = DAT_0000c8cc;
  puVar3 = DAT_0000c8c8;
  do {
    if (iVar4 == 0x20) {
LAB_0000c8be:
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar5 & 1) == 1);
      }
      return;
    }
    if (param_1 * 0x100 + param_2 == (uint)*(ushort *)(DAT_0000c8d0 + iVar4)) {
      *(short *)(DAT_0000c8d0 + iVar4) = (short)DAT_0000c8c4;
      *puVar3 = 0;
      FUN_000012a8(iVar2);
      goto LAB_0000c8be;
    }
    iVar4 = iVar4 + 2;
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 1;
  } while( true );
}

