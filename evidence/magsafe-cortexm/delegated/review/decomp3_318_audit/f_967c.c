
undefined1 FUN_0000967c(undefined4 param_1)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 local_4 [4];
  
  FUN_00012a1c();
  FUN_0000094c(param_1);
  local_4[0] = (undefined1)param_1;
  switch(param_1) {
  case 0:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0xb);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    uVar2 = 2;
    goto LAB_0000991a;
  case 1:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0xc);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    uVar2 = 5;
    goto LAB_0000991a;
  case 2:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0xd);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 3:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0xe);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 4:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0xf);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 5:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x10);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 6:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x11);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 7:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(10);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    uVar2 = 3;
    goto LAB_0000991a;
  case 8:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x12);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 9:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x13);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 10:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x14);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    uVar2 = 4;
    goto LAB_0000991a;
  case 0xb:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x15);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 0xc:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x16);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 0xd:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x17);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 0xe:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x18);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 0xf:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x19);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 0x10:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x1a);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  case 0x11:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x1b);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
    break;
  default:
    if (*(char *)(iRam00009924 + 5) == '\0') {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00008f54(0x1c);
      FUN_0000906c(local_4,1);
      FUN_00009058();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar3 & 1) == 1);
      }
    }
  }
  uVar2 = 7;
LAB_0000991a:
  FUN_0000d904(uVar2);
  FUN_00000bac();
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  FUN_00009944(0);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  return *(undefined1 *)(DAT_00009940 + 0x42);
}

