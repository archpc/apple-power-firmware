
undefined4 FUN_0000ca88(uint param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  ushort *puVar4;
  uint uVar5;
  
  uVar2 = 0;
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  puVar4 = DAT_0000cac4;
  for (; uVar2 != 0x10; uVar2 = uVar2 + 1) {
    if (((param_1 == *puVar4 >> 8) && (uVar5 = (uint)(byte)*puVar4, param_2 <= uVar5)) &&
       (uVar5 <= param_3)) goto LAB_0000cab2;
    puVar4 = puVar4 + 1;
  }
  uVar2 = 0x10;
LAB_0000cab2:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  if (0xf < uVar2) {
    return 0;
  }
  return 1;
}

