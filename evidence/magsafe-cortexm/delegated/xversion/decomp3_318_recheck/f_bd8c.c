
void FUN_0000bd8c(undefined4 param_1,uint param_2,int param_3)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined1 auStack_30 [28];
  byte local_14;
  undefined1 local_13;
  
  puVar2 = DAT_0000bde8;
  if (param_2 < 2) {
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_000012a8(DAT_0000bde8);
    uVar3 = FUN_00001178(500,0,DAT_0000bdec,0);
    *puVar2 = uVar3;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar4 & 1) == 1);
    }
  }
  else if (param_2 == 4) {
    local_13 = 0;
    local_14 = *(byte *)(param_3 + 1);
    FUN_00000170(auStack_30,param_3 + 8,(uint)local_14 << 2);
    (**(code **)(DAT_0000bde4 + 0x68))(1,auStack_30);
  }
  return;
}

