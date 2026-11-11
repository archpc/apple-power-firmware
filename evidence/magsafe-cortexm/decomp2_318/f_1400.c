
void FUN_00001400(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = DAT_00001440;
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  if (param_1 == 2) {
    *(uint *)(DAT_00001440 + 0x50) = *(uint *)(DAT_00001440 + 0x50) & ~param_2;
    param_2 = *(uint *)(iVar2 + 0x54) & ~param_2;
  }
  else {
    if (param_1 != 1) {
      if (param_1 == 0) {
        *(uint *)(DAT_00001440 + 0x50) = *(uint *)(DAT_00001440 + 0x50) | param_2;
      }
      goto LAB_00001438;
    }
    *(uint *)(DAT_00001440 + 0x50) = *(uint *)(DAT_00001440 + 0x50) & ~param_2;
    param_2 = *(uint *)(iVar2 + 0x54) | param_2;
  }
  *(uint *)(iVar2 + 0x54) = param_2;
LAB_00001438:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  return;
}

