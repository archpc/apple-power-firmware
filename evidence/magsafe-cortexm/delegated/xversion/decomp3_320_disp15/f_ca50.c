
bool FUN_0000ca50(int param_1,int param_2)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  
  uVar3 = 0xffffffff;
  uVar4 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  puVar5 = DAT_0000ca84;
  do {
    if (uVar3 == 0xf) {
      uVar3 = 0x10;
      break;
    }
    uVar3 = uVar3 + 1;
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
  } while (param_1 * 0x100 + param_2 != (uint)uVar1);
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  return uVar3 < 0x10;
}

