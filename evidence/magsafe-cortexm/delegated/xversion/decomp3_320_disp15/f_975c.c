
undefined1 FUN_0000975c(undefined4 param_1)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 local_4 [4];
  
  FUN_00012c78();
  FUN_00000974(param_1);
  local_4[0] = (undefined1)param_1;
  switch(param_1) {
  case 0:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00009094(0xb);
      FUN_0000918c();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    uVar2 = 2;
    goto LAB_000098f2;
  case 1:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00009094(0xc);
      FUN_0000918c();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    uVar2 = 5;
    goto LAB_000098f2;
  case 2:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar2 = 0xd;
LAB_000098de:
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00009094(uVar2);
      FUN_0000918c();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 3:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar2 = 0xe;
      goto LAB_000098de;
    }
    break;
  case 4:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar2 = 0xf;
      goto LAB_000098de;
    }
    break;
  case 5:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar2 = 0x10;
      goto LAB_000098de;
    }
    break;
  case 6:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar2 = 0x11;
      goto LAB_000098de;
    }
    break;
  case 7:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00009094(10);
      FUN_0000918c();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    uVar2 = 3;
    goto LAB_000098f2;
  case 8:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar2 = 0x12;
      goto LAB_000098de;
    }
    break;
  case 9:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar2 = 0x13;
      goto LAB_000098de;
    }
    break;
  case 10:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00009094(0x14);
      FUN_0000918c();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    uVar2 = 4;
    goto LAB_000098f2;
  case 0xb:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar2 = 0x15;
      goto LAB_000098de;
    }
    break;
  case 0xc:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar2 = 0x16;
      goto LAB_000098de;
    }
    break;
  case 0xd:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar2 = 0x17;
      goto LAB_000098de;
    }
    break;
  case 0xe:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar2 = 0x18;
      goto LAB_000098de;
    }
    break;
  case 0xf:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar2 = 0x19;
      goto LAB_000098de;
    }
    break;
  case 0x10:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar2 = 0x1a;
      goto LAB_000098de;
    }
    break;
  case 0x11:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar2 = 0x1b;
      goto LAB_000098de;
    }
    break;
  default:
    if (*(char *)(iRam000098fc + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00009094(0x1c);
      FUN_000091a0(local_4,1);
      FUN_0000918c();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
  }
  uVar2 = 7;
LAB_000098f2:
  FUN_0000db40(uVar2);
  FUN_00000bcc();
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  FUN_0000991c(0);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  return *(undefined1 *)(DAT_00009918 + 0x62);
}

