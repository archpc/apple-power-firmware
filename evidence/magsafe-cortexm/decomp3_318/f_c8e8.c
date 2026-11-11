
undefined8 FUN_0000c8e8(uint param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint local_20;
  
  uVar2 = param_1;
  local_20 = param_2;
  if (param_2 < param_3) {
    iVar4 = 0;
    uVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar2 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    puVar5 = DAT_0000c944;
    iVar6 = DAT_0000c948;
    for (; iVar4 != 0x20; iVar4 = iVar4 + 2) {
      if (((param_1 == *(ushort *)(DAT_0000c94c + iVar4) >> 8) &&
          (uVar3 = (uint)(byte)*(ushort *)(DAT_0000c94c + iVar4), param_2 <= uVar3)) &&
         (uVar3 <= param_3)) {
        *(short *)(DAT_0000c94c + iVar4) = (short)DAT_0000c940;
        *puVar5 = 0;
        FUN_000012a8(iVar6);
      }
      iVar6 = iVar6 + 1;
      puVar5 = puVar5 + 1;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    local_20 = uVar2;
    if (bVar1) {
      enableIRQinterrupts((uVar2 & 1) == 1);
    }
  }
  return CONCAT44(local_20,uVar2);
}

