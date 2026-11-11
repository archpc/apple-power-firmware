
int FUN_000011a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined8 uVar9;
  longlong lVar10;
  
  iVar4 = DAT_00001238;
  iVar2 = DAT_00001234;
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  iVar3 = DAT_00001234 + 0x110;
  uVar6 = (uint)*(byte *)(DAT_00001234 + 0x111);
  if (uVar6 == *(byte *)(DAT_00001234 + 0x110)) {
    uVar7 = 0xff;
  }
  else {
    uVar7 = (uint)*(byte *)(*(int *)(DAT_00001234 + 0x114) + uVar6);
  }
  if (*(byte *)(DAT_00001238 + 2) < uVar6) {
    *(byte *)(DAT_00001238 + 2) = *(byte *)(DAT_00001234 + 0x111);
  }
  if (uVar7 != 0xff) {
    iVar4 = *(int *)(iVar4 + 0x40);
    iVar8 = iVar2 + uVar7 * 0x10;
    *(undefined4 *)(iVar8 + 8) = param_3;
    uVar9 = FUN_00000866(iVar4,iVar4 >> 0x1f,param_1,param_2);
    iVar4 = (int)((ulonglong)uVar9 >> 0x20);
    lVar10 = FUN_00000e38();
    lVar10 = lVar10 + CONCAT44(iVar4 >> 0xd,((uint)uVar9 >> 0xd) + iVar4 * 0x80000);
    *(int *)(iVar2 + uVar7 * 0x10) = (int)lVar10;
    *(undefined4 *)(iVar8 + 0xc) = param_4;
    *(int *)(iVar8 + 4) = (int)((ulonglong)lVar10 >> 0x20);
    FUN_00001132(iVar3,uVar7,DAT_0000123c,0);
    FUN_0000126c();
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
    return (int)(char)uVar7;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00000f3c(DAT_00001240);
}

