
undefined4 FUN_00009edc(uint param_1,byte *param_2,uint param_3)

{
  bool bVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  
  uVar3 = 0xffffffff;
  if ((param_1 >> 0x12 == 0) && (param_3 < 0x101)) {
    FUN_00009f48(0xffffffff);
    FUN_00009f90();
    puVar2 = DAT_00009f44;
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    *DAT_00009f44 = 2;
    *puVar2 = param_1 >> 0x10;
    *puVar2 = param_1 >> 8 & 0xff;
    *puVar2 = param_1 & 0xff;
    pbVar5 = param_2 + param_3;
    for (; param_2 < pbVar5; param_2 = param_2 + 1) {
      *puVar2 = (uint)*param_2;
      do {
      } while (0xe < (puVar2[-0xe] & 0x1f));
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar4 & 1) == 1);
    }
    FUN_00009eb4(uVar4);
    FUN_00009f48();
    uVar3 = 0;
  }
  return uVar3;
}

