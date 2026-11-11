
undefined8 FUN_00000e08(void)

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
  iVar5 = *(int *)(DAT_00000e48 + 0x40);
  uVar6 = *DAT_00000e40;
  *(uint *)(DAT_00000e48 + 0x40) = uVar6 & 0xffff;
  iVar3 = DAT_00000e4c;
  uVar6 = (uVar6 & 0xffff) - iVar5;
  if ((int)uVar6 < 0) {
    uVar6 = uVar6 + DAT_00000e44;
  }
  piVar1 = (int *)(DAT_00000e4c + 0x1c);
  uVar7 = *(uint *)(DAT_00000e4c + 0x18);
  *(uint *)(DAT_00000e4c + 0x18) = uVar7 + uVar6;
  *(uint *)(iVar3 + 0x1c) = *piVar1 + ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar7,uVar6);
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  return *(undefined8 *)(iVar3 + 0x18);
}

