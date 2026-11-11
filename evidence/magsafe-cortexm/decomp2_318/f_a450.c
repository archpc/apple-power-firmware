
void FUN_0000a450(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar2 = DAT_0000a4b8;
  uVar7 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar7 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  iVar3 = DAT_0000a4b8 + 0x110;
  if (((uint)*(byte *)(DAT_0000a4b8 + 0x111) != (uint)*(byte *)(DAT_0000a4b8 + 0x110)) &&
     (uVar5 = (uint)*(byte *)(*(int *)(DAT_0000a4b8 + 0x114) + (uint)*(byte *)(DAT_0000a4b8 + 0x111)
                             ), uVar5 != 0xff)) {
    iVar6 = DAT_0000a4b8 + 0x18 + uVar5 * 4;
    *(undefined4 *)(iVar6 + 0xa8) = 0;
    *(undefined4 *)(iVar6 + 0x68) = param_1;
    FUN_0000110a(iVar3,uVar5,DAT_0000a4bc);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar7 & 1) == 1);
  }
  puVar4 = (undefined4 *)(iVar2 + 0x70);
  for (uVar7 = 0; uVar7 < *(uint *)(iVar2 + 0x5c); uVar7 = uVar7 + 1) {
    (*(code *)puVar4[-4])(iVar2 + 0x18,param_1,*puVar4,0);
    puVar4 = puVar4 + 1;
  }
  return;
}

