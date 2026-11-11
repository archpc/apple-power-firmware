
void FUN_0000131c(undefined4 *param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  *param_2 = 0;
  iVar2 = DAT_0000135c;
  param_2[1] = *(undefined4 *)(DAT_0000135c + 0x4c);
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    *(undefined4 *)param_1[1] = param_2;
  }
  puVar4 = (undefined4 *)*param_1;
  if ((undefined4 *)*param_1 == (undefined4 *)0x0) {
    *param_1 = param_2;
    puVar4 = param_2;
  }
  param_1[1] = param_2;
  while( true ) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar3 & 1) == 1);
    }
    if (puVar4[1] == *(int *)(iVar2 + 0x4c)) break;
    software_interrupt(1);
    uVar3 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar3 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    puVar4 = (undefined4 *)*param_1;
  }
  return;
}

