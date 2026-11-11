
void FUN_00000f10(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  FUN_00012bc4(uRam00000f24);
  FUN_00012bc4(param_1);
  iVar2 = FUN_00000c20();
  if (iVar2 != 0) {
    if (*(char *)(iVar2 + 9) != '\0') {
      uVar4 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar4 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00000f84(iVar2);
      iVar3 = *(int *)(DAT_00000f7c + 0x4c);
      if ((((iVar3 != 0) && (iVar3 != iVar2)) && (*(char *)(iVar3 + 8) != '\0')) &&
         (*(char *)(DAT_00000f7c + 1) == '\0')) {
        *(undefined1 *)(DAT_00000f7c + 1) = 1;
        FUN_00000f84();
        *DAT_00000f78 = 0x10000000;
        InstructionSynchronizationBarrier(0xf);
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar4 & 1) == 1);
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00000f10(DAT_00000f80,0);
}

