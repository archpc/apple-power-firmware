
undefined4 FUN_00009eec(uint param_1,byte *param_2,int param_3)

{
  bool bVar1;
  uint *puVar2;
  uint uVar3;
  byte *pbVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  if (param_1 >> 0x12 == 0) {
    FUN_00009f50();
    FUN_00009f98();
    puVar2 = DAT_00009f4c;
    uVar3 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar3 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    *DAT_00009f4c = 2;
    *puVar2 = param_1 >> 0x10;
    *puVar2 = param_1 >> 8 & 0xff;
    *puVar2 = param_1 & 0xff;
    pbVar4 = param_2 + param_3;
    for (; param_2 < pbVar4; param_2 = param_2 + 1) {
      *puVar2 = (uint)*param_2;
      do {
      } while (0xe < (puVar2[-0xe] & 0x1f));
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar3 & 1) == 1);
    }
    FUN_00009ec4(uVar3);
    FUN_00009f50();
  }
  else {
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

