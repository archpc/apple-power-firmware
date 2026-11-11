
void FUN_00000f3c(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  FUN_00012e20(uRam00000f50);
  FUN_00012e20(param_1);
  iVar2 = FUN_00000c40();
  if (iVar2 != 0) {
    if (*(char *)(iVar2 + 9) != '\0') {
      uVar4 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar4 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00000fb0(iVar2);
      iVar3 = *(int *)(DAT_00000fa8 + 0x48);
      if ((((iVar3 != 0) && (iVar3 != iVar2)) && (*(char *)(iVar3 + 8) != '\0')) &&
         (*(char *)(DAT_00000fa8 + 1) == '\0')) {
        *(undefined1 *)(DAT_00000fa8 + 1) = 1;
        FUN_00000fb0();
        *DAT_00000fa4 = 0x10000000;
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
  FUN_00000f3c(DAT_00000fac,0);
}

