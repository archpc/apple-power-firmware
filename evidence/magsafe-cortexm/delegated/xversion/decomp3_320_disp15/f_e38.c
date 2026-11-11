
undefined8 FUN_00000e38(void)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar4 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  iVar5 = *(int *)(DAT_00000e78 + 0x44);
  uVar6 = *DAT_00000e70;
  *(uint *)(DAT_00000e78 + 0x44) = uVar6 & 0xffff;
  iVar3 = DAT_00000e7c;
  uVar6 = (uVar6 & 0xffff) - iVar5;
  if ((int)uVar6 < 0) {
    uVar6 = uVar6 + DAT_00000e74;
  }
  piVar1 = (int *)(DAT_00000e7c + 0x14);
  uVar7 = *(uint *)(DAT_00000e7c + 0x10);
  *(uint *)(DAT_00000e7c + 0x10) = uVar7 + uVar6;
  *(uint *)(iVar3 + 0x14) = *piVar1 + (uint)CARRY4(uVar7,uVar6);
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  return *(undefined8 *)(iVar3 + 0x10);
}

