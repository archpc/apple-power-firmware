
void FUN_0000b73c(int param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar6 = DAT_0000b7bc;
  *(char *)(DAT_0000b7bc + 0x16) = (char)param_2;
  *(char *)(iVar6 + 0x15) = (char)param_3;
  puVar3 = DAT_0000b7c4;
  iVar2 = DAT_0000b7c0;
  uVar7 = param_2;
  uVar5 = param_3;
  if ((param_1 == 1) && (*(char *)(DAT_0000b7c0 + 0x34) != '\0')) {
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_000012a8(DAT_0000b7c4);
    uVar4 = FUN_00001178(DAT_0000b7b8,0,DAT_0000b7c8,0,uVar7,uVar5);
    *puVar3 = uVar4;
    *(undefined1 *)(iVar6 + 3) = 1;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
  }
  iVar6 = FUN_0000295c(param_2,param_3,iVar2 + 0x28,DAT_0000b7cc,uVar7,uVar5);
  if (iVar6 != 0) {
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_000012a8(puVar3 + 2);
    uVar4 = FUN_00001178(1000,0,DAT_0000b7d0,0);
    puVar3[2] = uVar4;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
  }
  return;
}

