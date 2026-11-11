
uint FUN_000005f0(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                 uint param_6,int param_7)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int unaff_r4;
  uint unaff_r5;
  uint uVar5;
  int iVar6;
  char *unaff_r7;
  undefined1 in_stack_00000018;
  
  param_5 = param_1 << 8;
  uVar5 = unaff_r5;
  if (unaff_r7 == (char *)0x0) {
    unaff_r7 = (char *)0x0;
  }
  else {
    cVar1 = *unaff_r7;
    if ((param_3 & param_5) == 0) {
      if (cVar1 != '\0') {
        iVar6 = 0;
        do {
          iVar2 = iVar6 + 1;
          iVar6 = iVar6 + 1;
        } while (unaff_r7[iVar2] != '\0');
        uVar5 = unaff_r5 + iVar6;
      }
    }
    else {
      while (cVar1 != '\0') {
        (**(code **)(param_7 + 8))(param_7,unaff_r7,1);
        cVar1 = unaff_r7[1];
        unaff_r7 = unaff_r7 + 1;
        uVar5 = uVar5 + 1;
      }
    }
  }
  uVar3 = param_5;
  uVar4 = param_6 >> 0xf & 0xff;
  if (((param_6 & 0x40) == 0) && ((int)uVar5 < (int)uVar4)) {
    if ((param_6 & param_5) == 0) {
      in_stack_00000018 = 0x20;
    }
    else {
      in_stack_00000018 = 0x30;
    }
    iVar6 = uVar4 - uVar5;
    uVar5 = uVar4;
    if (0 < iVar6) {
      do {
        (**(code **)(param_7 + 8))(param_7,&stack0x00000018,1);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  if (((param_6 & uVar3) == 0) && (unaff_r7 != (char *)0x0)) {
    cVar1 = *unaff_r7;
    while (cVar1 != '\0') {
      (**(code **)(param_7 + 8))(param_7,unaff_r7,1);
      cVar1 = unaff_r7[1];
      unaff_r7 = unaff_r7 + 1;
    }
  }
  (**(code **)(param_7 + 8))(param_7,unaff_r4 + 1,unaff_r5);
  if (((param_6 & 0x40) != 0) && ((int)uVar5 < (int)uVar4)) {
    in_stack_00000018 = 0x20;
    iVar6 = uVar4 - uVar5;
    uVar5 = uVar4;
    if (0 < iVar6) {
      do {
        (**(code **)(param_7 + 8))(param_7,&stack0x00000018,1);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  return uVar5;
}

