
undefined8 FUN_0000c880(int param_1,int param_2)

{
  ushort *puVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = 0;
  uVar4 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  iVar5 = 0;
  do {
    if (iVar5 == 0x20) goto LAB_0000c8a0;
    puVar1 = (ushort *)(DAT_0000c8a8 + iVar5);
    iVar5 = iVar5 + 2;
  } while (param_1 * 0x100 + param_2 != (uint)*puVar1);
  uVar3 = 1;
LAB_0000c8a0:
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  return CONCAT44(uVar4,uVar3);
}

