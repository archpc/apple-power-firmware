
void FUN_00000f28(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 != 0) {
    if (*(char *)(param_1 + 9) != '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00000f84(param_1);
      iVar2 = *(int *)(DAT_00000f7c + 0x4c);
      if ((((iVar2 != 0) && (iVar2 != param_1)) && (*(char *)(iVar2 + 8) != '\0')) &&
         (*(char *)(DAT_00000f7c + 1) == '\0')) {
        *(undefined1 *)(DAT_00000f7c + 1) = 1;
        FUN_00000f84();
        *DAT_00000f78 = 0x10000000;
        InstructionSynchronizationBarrier(0xf);
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00000f10(DAT_00000f80);
}

