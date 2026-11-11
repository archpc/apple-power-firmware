
void FUN_00001378(int *param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  if ((int *)*param_1 == param_2) {
    iVar2 = *param_2;
    *param_1 = iVar2;
    if (iVar2 == 0) {
      param_1[1] = 0;
    }
    else {
      FUN_00000f54(*(undefined4 *)(iVar2 + 4));
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar3 & 1) == 1);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00000f3c(DAT_000013a8);
}

