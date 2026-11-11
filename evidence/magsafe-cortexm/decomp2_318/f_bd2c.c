
void FUN_0000bd2c(void)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  undefined1 local_3c [4];
  undefined1 local_38;
  undefined1 local_30;
  undefined4 local_2c;
  
  puVar2 = DAT_0000bd7c;
  local_30 = 0x1e;
  local_3c[0] = 0;
  local_38 = 1;
  *DAT_0000bd7c = 0xff;
  local_2c = *(undefined4 *)(DAT_0000bd80 + 100);
  iVar4 = FUN_0000295c(0,0xc,local_3c,PTR_LAB_0000c20c_1_0000bd84);
  if (iVar4 != 0) {
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_000012a8(puVar2);
    uVar3 = FUN_00001178(500,0,PTR_LAB_0000c1ac_1_0000bd88,0);
    *puVar2 = uVar3;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
  }
  return;
}

