
undefined8 FUN_000012a8(char *param_1)

{
  undefined1 uVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar4 = DAT_00001314;
  uVar5 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar5 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  iVar6 = *(int *)(DAT_00001314 + 0x114);
  uVar7 = 0;
  do {
    if (*(byte *)(DAT_00001314 + 0x111) == uVar7) {
LAB_00001306:
      *param_1 = -1;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        enableIRQinterrupts((uVar5 & 1) == 1);
      }
      return CONCAT44(0x114,uVar5);
    }
    if (*(char *)(iVar6 + uVar7) == *param_1) {
      bVar3 = *(byte *)(DAT_00001314 + 0x111) - 1;
      *(byte *)(DAT_00001314 + 0x111) = bVar3;
      uVar1 = *(undefined1 *)(iVar6 + uVar7);
      *(undefined1 *)(iVar6 + uVar7) = *(undefined1 *)(iVar6 + (uint)bVar3);
      *(undefined1 *)(*(int *)(iVar4 + 0x114) + (uint)*(byte *)(iVar4 + 0x111)) = uVar1;
      FUN_000010a4(iVar4 + 0x110,uVar7,DAT_00001318,0);
      *(char *)(*(int *)(iVar4 + 0x114) + (uint)*(byte *)(iVar4 + 0x111)) = *param_1;
      FUN_00001244();
      goto LAB_00001306;
    }
    uVar7 = uVar7 + 1;
  } while( true );
}

