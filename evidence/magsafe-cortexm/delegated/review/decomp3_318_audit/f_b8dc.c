
void FUN_0000b8dc(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  uVar1 = 0;
  bVar6 = (bool)isCurrentModePrivileged();
  if (bVar6) {
    uVar1 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  uVar2 = param_2 & 0xff;
  FUN_00008e4c(uVar2,7,param_3,param_4,param_2,uVar2,uVar1);
  FUN_00000b60(0x1e0);
  bVar6 = true;
  iVar5 = 0;
  iVar4 = 0;
  while (bVar6) {
    bVar6 = false;
    iVar3 = FUN_00007e4c(param_1,0,2);
    iVar4 = iVar4 + iVar3;
    iVar3 = FUN_00007e4c(param_1,0,1);
    iVar5 = iVar5 + iVar3;
  }
  FUN_00008e4c(uVar2,0);
  bVar6 = (bool)isCurrentModePrivileged();
  if (bVar6) {
    enableIRQinterrupts((uVar1 & 1) == 1);
  }
  FUN_00000880(iVar5 * DAT_0000b93c,iVar4);
  return;
}

