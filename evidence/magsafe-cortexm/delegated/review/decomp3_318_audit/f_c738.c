
void FUN_0000c738(int param_1,int param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  
  puVar8 = DAT_0000c7d8;
  uVar2 = DAT_0000c7cc;
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  if ((param_2 != 0xff) && (param_3 != 0)) {
    uVar5 = param_1 * 0x100 + param_2;
    iVar3 = DAT_0000c7d0;
    puVar4 = DAT_0000c7d4;
    for (iVar7 = 0; iVar7 != 0x20; iVar7 = iVar7 + 2) {
      if (*(ushort *)((int)DAT_0000c7d8 + iVar7) == uVar5) {
        FUN_000012a8(iVar3);
        *(short *)((int)puVar8 + iVar7) = (short)uVar2;
        *puVar4 = 0;
        break;
      }
      puVar4 = puVar4 + 1;
      iVar3 = iVar3 + 1;
    }
    iVar3 = 0;
    puVar4 = DAT_0000c7d4;
    while( true ) {
      if (iVar3 == 0x10) {
                    /* WARNING: Subroutine does not return */
        FUN_00000f10(DAT_0000c7dc);
      }
      if (*puVar8 == uVar2) break;
      puVar8 = puVar8 + 1;
      puVar4 = puVar4 + 1;
      iVar3 = iVar3 + 1;
    }
    *puVar4 = param_4;
    *puVar8 = (ushort)uVar5;
    iVar7 = FUN_00001178(param_3 * 1000,0,DAT_0000c7e0,iVar3);
    *(char *)(DAT_0000c7d0 + iVar3) = (char)iVar7;
    if (iVar7 == -1) {
                    /* WARNING: Subroutine does not return */
      FUN_00000f10(DAT_0000c7e4);
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar6 & 1) == 1);
  }
  return;
}

