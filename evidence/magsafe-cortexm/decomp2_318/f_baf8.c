
void FUN_0000baf8(void)

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
  
  puVar2 = DAT_0000bba0;
  *DAT_0000bba0 = 0xff;
  local_2c = DAT_0000bb94;
  switch(*(undefined1 *)(DAT_0000bba4 + 0x18)) {
  case 1:
    break;
  case 2:
    local_2c = DAT_0000bb94 + 1;
    break;
  case 3:
    local_2c = DAT_0000bb9c;
    break;
  case 4:
    local_2c = (*(byte *)(DAT_0000bba8 + 0x34) & 7) * 0x100 + DAT_0000bb9c + 1;
    break;
  case 5:
    FUN_0000a450(DAT_0000bb98);
    *(undefined1 *)(DAT_0000bbac + (uint)*(byte *)(DAT_0000bba8 + 0x2c) * 0x30 + 0x2a) = 9;
  default:
    goto switchD_0000bb16_default;
  }
  local_30 = 0x1e;
  local_38 = 1;
  local_3c[0] = 0;
  local_34 = 0;
  iVar4 = FUN_0000295c(1,0xc,local_3c,PTR_LAB_0000c038_1_0000bbb0);
  if (iVar4 != 0) {
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_000012a8(puVar2);
    uVar3 = FUN_00001178(1000,0,PTR_LAB_0000bf78_1_0000bbb4,0);
    *puVar2 = uVar3;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
  }
switchD_0000bb16_default:
  return;
}

