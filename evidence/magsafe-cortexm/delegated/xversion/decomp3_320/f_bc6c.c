
void FUN_0000bc6c(void)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  undefined1 local_3c [4];
  undefined1 local_38;
  undefined4 local_34;
  undefined1 local_30;
  int local_2c;
  
  puVar2 = DAT_0000bd14;
  *DAT_0000bd14 = 0xff;
  local_2c = DAT_0000bd08;
  switch(*(undefined1 *)(DAT_0000bd18 + 0x20)) {
  case 1:
    break;
  case 2:
    local_2c = DAT_0000bd08 + 1;
    break;
  case 3:
    local_2c = DAT_0000bd10;
    break;
  case 4:
    local_2c = (*(byte *)(DAT_0000bd1c + 0x34) & 7) * 0x100 + DAT_0000bd10 + 1;
    break;
  case 5:
    FUN_0000a478(DAT_0000bd0c);
    *(undefined1 *)(DAT_0000bd20 + (uint)*(byte *)(DAT_0000bd1c + 0x2c) * 0x30 + 0x2a) = 9;
  default:
    goto switchD_0000bc8a_default;
  }
  local_30 = 0x1e;
  local_38 = 1;
  local_3c[0] = 0;
  local_34 = 0;
  iVar4 = FUN_0000290c(1,0xc,local_3c,DAT_0000bd24);
  if (iVar4 != 0) {
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_000012d0(puVar2);
    uVar3 = FUN_000011a0(1000,0,DAT_0000bd28,0);
    *puVar2 = uVar3;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
  }
switchD_0000bc8a_default:
  return;
}

