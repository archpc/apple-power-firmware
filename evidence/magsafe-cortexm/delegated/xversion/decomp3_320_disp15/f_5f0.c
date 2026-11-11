
uint FUN_000005f0(uint param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                 char *param_6,uint param_7,int param_8,undefined4 param_9,undefined4 param_10,
                 undefined1 param_11)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 *unaff_r4;
  uint uVar5;
  byte unaff_r6;
  
  if (param_2 < param_1) {
    do {
      *unaff_r4 = 0x30;
      unaff_r4 = unaff_r4 + -1;
      unaff_r6 = unaff_r6 + 1;
    } while (unaff_r6 < param_1);
  }
  else if (unaff_r6 == 0) {
    *unaff_r4 = 0x30;
    unaff_r4 = unaff_r4 + -1;
    unaff_r6 = 1;
  }
  param_9 = (uint)unaff_r6;
  uVar5 = param_9;
  if (param_6 == (char *)0x0) {
    param_6 = (char *)0x0;
  }
  else {
    cVar1 = *param_6;
    if ((param_3 & 0x100) == 0) {
      if (cVar1 != '\0') {
        iVar3 = 0;
        do {
          iVar2 = iVar3 + 1;
          iVar3 = iVar3 + 1;
        } while (param_6[iVar2] != '\0');
        uVar5 = param_9 + iVar3;
      }
    }
    else {
      while (cVar1 != '\0') {
        (**(code **)(param_8 + 8))(param_8,param_6,1);
        cVar1 = param_6[1];
        uVar5 = uVar5 + 1;
        param_6 = param_6 + 1;
      }
    }
  }
  uVar4 = param_7 >> 0xf & 0xff;
  if (((int)uVar5 < (int)uVar4) && ((param_7 & 0x40) == 0)) {
    if ((param_7 & 0x100) == 0) {
      param_11 = 0x20;
    }
    else {
      param_11 = 0x30;
    }
    iVar3 = uVar4 - uVar5;
    uVar5 = uVar4;
    if (0 < iVar3) {
      do {
        (**(code **)(param_8 + 8))(param_8,&param_11,1);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  if ((param_6 != (char *)0x0) && ((param_7 & 0x100) == 0)) {
    cVar1 = *param_6;
    while (cVar1 != '\0') {
      (**(code **)(param_8 + 8))(param_8,param_6,1);
      cVar1 = param_6[1];
      param_6 = param_6 + 1;
    }
  }
  (**(code **)(param_8 + 8))(param_8,unaff_r4 + 1,param_9);
  if (((int)uVar5 < (int)uVar4) && ((param_7 & 0x40) != 0)) {
    param_11 = 0x20;
    iVar3 = uVar4 - uVar5;
    uVar5 = uVar4;
    if (0 < iVar3) {
      do {
        (**(code **)(param_8 + 8))(param_8,&param_11,1);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  return uVar5;
}

