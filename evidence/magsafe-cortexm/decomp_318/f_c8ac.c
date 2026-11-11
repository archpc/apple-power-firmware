
undefined8 FUN_0000c8ac(uint param_1,uint param_2,uint param_3)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = 0;
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  iVar4 = 0;
  do {
    if (iVar4 == 0x20) {
LAB_0000c8da:
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
      return CONCAT44(uVar3,uVar2);
    }
    if (((param_1 == *(ushort *)(DAT_0000c8e4 + iVar4) >> 8) &&
        (uVar5 = (uint)(byte)*(ushort *)(DAT_0000c8e4 + iVar4), param_2 <= uVar5)) &&
       (uVar5 <= param_3)) {
      uVar2 = 1;
      goto LAB_0000c8da;
    }
    iVar4 = iVar4 + 2;
  } while( true );
}

