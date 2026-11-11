
void FUN_000058fc(undefined4 param_1,int param_2,uint param_3,int *param_4)

{
  int *piVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int *unaff_r5;
  undefined **unaff_r6;
  char *unaff_r7;
  int *piStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  uVar6 = DAT_00005fcc;
  if (6 < param_2 - 2U) {
    return;
  }
  ppuVar3 = &PTR_FUN_00005910;
  piVar1 = (int *)(&PTR_FUN_00005910)[param_2 - 2U];
  switch(param_2) {
  case 2:
FUN_00005dd4:
    switch((short)unaff_r5[2]) {
    case 1:
      if (((*unaff_r7 == '\0') || (-1 < (int)((uint)(byte)unaff_r7[0x9e] << 0x18))) ||
         (-1 < (int)((uint)(byte)unaff_r7[0x106] << 0x19))) break;
      ppuVar3 = (undefined **)0xee;
      goto FUN_00005e0c;
    case 2:
      if (*unaff_r7 == '\x01') break;
      uVar4 = 0x2e;
      goto LAB_00005fbc;
    case 3:
      if (unaff_r7[0x15] == '\x01') {
        if (unaff_r7[0x175] == '\0') {
          return;
        }
        FUN_00006408(param_1,0x10,2,DAT_00005fdc);
        return;
      }
      break;
    case 4:
      if (unaff_r7[0x15] == '\0') {
        return;
      }
    }
    FUN_00006374(param_1,0x10);
    return;
  case 4:
  case 5:
    if (unaff_r6 == (undefined **)((int)&Reset + 2)) {
      (*(code *)**(undefined4 **)(unaff_r7 + 0x60))(param_1,0x41,*unaff_r5);
      unaff_r7[0x43] = '\x02';
      FUN_000030f0(param_1,9,0x1b);
      return;
    }
    if (unaff_r6 == (undefined **)((int)&MemManage + 2)) {
      if (unaff_r7[0x15] == '\0') {
        uVar6 = piStack_30[1];
        if ((((int)uVar6 < 0) && (DAT_00005fc8 <= (DAT_00005fc4 & uVar6))) &&
           ((int)(uVar6 << 5) < 0)) {
          FUN_00007272(param_1,0,0x12,(DAT_00005fcc & uVar6 >> 0x10) + 0x8800,unaff_r7 + 0xec);
          return;
        }
      }
      else if (((unaff_r7[0x15] == '\x01') && (uVar6 = piStack_30[1], (int)uVar6 < 0)) &&
              (param_3 = (uVar6 & 0x1ffffff) >> 0x10, 0x1a < param_3)) {
        unaff_r6 = (undefined **)(piStack_30 + 2);
        ppuVar3 = (undefined **)(uVar6 << 1);
        piVar1 = piStack_30;
        goto FUN_00005e56;
      }
      goto LAB_00005f82;
    }
    if (unaff_r6 != (undefined **)((int)&MemManage + 1)) {
      if (unaff_r6 != &MemManage) {
        if ((int)unaff_r6 - 3U < 2) {
          (*(code *)**(undefined4 **)(unaff_r7 + 0x60))(param_1,0x41,*unaff_r5);
        }
        if ((unaff_r6 < &MemManage) && ((1 << ((uint)unaff_r6 & 0xff) & DAT_00005fd0) != 0)) {
          return;
        }
        unaff_r7[0x43] = '\x02';
        FUN_000030f0(param_1,9,0x1b);
        if ((int)unaff_r6 - 3U < 2) {
          return;
        }
        goto LAB_00005f92;
      }
      piVar1 = (int *)0x1;
      *(undefined1 *)((int)unaff_r5 + 0xa9) = 1;
      param_4 = unaff_r5;
      unaff_r5 = piStack_30;
      if ((DAT_00005fc4 & piStack_30[1]) != 0x20000) {
        return;
      }
      goto FUN_00005dd4;
    }
    if (unaff_r7[0x15] != '\0') {
      FUN_00006374(param_1,0x10);
LAB_00005f82:
      unaff_r7[0x43] = '\x02';
      FUN_000030f0(param_1,9,0x1b);
LAB_00005f92:
      (*(code *)**(undefined4 **)(unaff_r7 + 0x60))(param_1,0x1e,*unaff_r5);
      return;
    }
    uVar2 = piStack_30[1];
    if (-1 < (int)uVar2) goto LAB_00005f82;
    uVar5 = (uVar2 & 0x1ffffff) >> 0x10;
    if (0x1a < uVar5) {
      uVar2 = (uVar2 & 0x7fffffff) >> 0x1b;
      if (uVar2 != 1) {
        if (uVar2 == 0) {
          FUN_00000170(DAT_00005fe0,piStack_30 + 2,0x1a);
          uStack_28 = 0;
          uStack_2c = 0;
          uVar2 = *(uint *)(*unaff_r5 + 4) >> 0x10;
          FUN_00007272(param_1,0,0x11,(uVar6 & uVar2) + (uVar2 + 0x800 & 0x7800) + 0x8400,&uStack_2c
                      );
        }
        goto LAB_00005f82;
      }
      unaff_r6 = (undefined **)(piStack_30 + 2);
      FUN_0000080c((undefined *)((int)piStack_30 + 0x22),unaff_r6,uVar5 - 0x1a);
      goto LAB_00005fb0;
    }
    break;
  case 6:
FUN_00005e0c:
    *(char *)((int)param_4 + (int)ppuVar3) = (char)piVar1;
    uVar4 = 0x10;
    goto LAB_00005fbc;
  case 8:
FUN_00005e56:
    if ((uint)ppuVar3 >> 0x1c == 0) {
      FUN_00000170(DAT_00005fe0,unaff_r6,0x1a);
      goto LAB_00005f82;
    }
  default:
    FUN_00000170((undefined *)((int)piVar1 + 0x22),unaff_r6,param_3 - 0x1a);
LAB_00005fb0:
    FUN_00000170(unaff_r6,DAT_00005fe0,0x1a);
  }
  uVar4 = 0xc;
LAB_00005fbc:
  FUN_00003258(param_1,uVar4);
  return;
}

