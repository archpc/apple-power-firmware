
void FUN_00009f50(void)

{
  bool bVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = DAT_00009f94;
  puVar2 = DAT_00009f90;
  while( true ) {
    *puVar3 = *puVar3 | 0x10000;
    *puVar3 = *puVar3 & 0xfffeffff;
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    *puVar2 = 5;
    *puVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar4 & 1) == 1);
    }
    FUN_00009ec4(uVar4);
    if ((puVar3[0xf] & 1) == 0) break;
    FUN_00000b80(0x1e0);
  }
  return;
}

