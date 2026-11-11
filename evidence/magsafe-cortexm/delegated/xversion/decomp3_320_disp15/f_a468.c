
void FUN_0000a468(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  
  iVar2 = DAT_0000a4e0;
  uVar9 = 0;
  uVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar8 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  iVar3 = DAT_0000a4e0 + 0x110;
  if (((uint)*(byte *)(DAT_0000a4e0 + 0x111) != (uint)*(byte *)(DAT_0000a4e0 + 0x110)) &&
     (uVar5 = (uint)*(byte *)(*(int *)(DAT_0000a4e0 + 0x114) + (uint)*(byte *)(DAT_0000a4e0 + 0x111)
                             ), uVar5 != 0xff)) {
    iVar7 = DAT_0000a4e0 + 0x18;
    iVar6 = iVar7 + uVar5 * 4;
    *(undefined4 *)(iVar6 + 0xa8) = 0;
    *(undefined4 *)(iVar6 + 0x68) = 0;
    FUN_00001132(iVar3,uVar5,DAT_0000a4e4,iVar7,0,param_4 - param_2);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar8 & 1) == 1);
  }
  puVar4 = (undefined4 *)(iVar2 + 0x70);
  for (uVar8 = 0; uVar8 < *(uint *)(iVar2 + 0x5c); uVar8 = uVar8 + 1) {
    (*(code *)puVar4[-4])(iVar2 + 0x18,uVar9,*puVar4,0);
    puVar4 = puVar4 + 1;
  }
  return;
}

