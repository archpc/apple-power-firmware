
void FUN_000038b8(uint param_1,int param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  int unaff_r5;
  int unaff_r6;
  uint unaff_r7;
  uint uVar4;
  uint uVar5;
  int iStack_34;
  int iStack_30;
  uint uStack_2c;
  int iStack_28;
  byte *pbStack_24;
  int iStack_20;
  int iStack_1c;
  
  if (8 < param_2 - 2U) {
    return;
  }
  pbVar2 = &DAT_000038d0;
  uVar1 = *(uint *)(&DAT_000038d0 + (param_2 - 2U) * 4);
  iStack_20 = unaff_r5;
  switch(param_2) {
  case 2:
    iStack_20 = 0;
    (&DAT_000038d0)[uVar1] = 0;
    iStack_28 = 0x180;
    if (*(char *)(unaff_r6 + 0x176) != '\0') {
      uVar1 = (uint)*(byte *)(unaff_r6 + 0x29) << 2;
      if (param_1 < 2) {
        *(undefined1 *)(unaff_r6 + 0x176) = 0;
      }
      goto LAB_00003e8a;
    }
    iStack_34 = 3;
    param_4 = (uint *)(unaff_r7 + param_1 * 0x1cc + 0x180);
    pbVar2 = (byte *)(unaff_r6 + 0x17e);
    uStack_2c = iStack_30 << 2;
    param_3 = 0;
FUN_00003dec:
    pbStack_24 = pbVar2;
    for (; param_3 != 6; param_3 = param_3 + 1) {
      param_4[-0x32] = 0;
      uVar1 = (uint)*pbVar2;
FUN_00003dfc:
      if ((uVar1 >> (param_3 & 0xff) & 1) != 0) {
        uVar1 = *param_4;
FUN_00003e04:
        unaff_r7 = uVar1 >> 0x1e;
        if (unaff_r7 == 2) {
          uVar3 = DAT_00003f08;
          uVar5 = uVar1;
          if (iStack_28 + 0x74U < (uStack_2c + 3 & uVar1)) {
LAB_00003e3c:
            uVar5 = iStack_28 + (uVar1 & uVar3) + 0x74;
          }
        }
        else {
          if (unaff_r7 == 1) goto LAB_00003e76;
FUN_00003e0e:
          if (unaff_r7 == 0) {
            uVar4 = uStack_2c + 3 & uVar1;
            uVar3 = DAT_00003f10;
            if (iStack_28 + 0x74U < uVar4) goto LAB_00003e3c;
            uVar4 = uVar4 * 0x6e;
            uVar5 = uVar1;
            if (DAT_00003f0c <= uVar4 && uVar4 - DAT_00003f0c != 0) {
              uVar5 = uVar1 & ~(iStack_34 << 0x14);
            }
            if ((uVar1 & 0x3fffff) >> 0x14 != 0) goto LAB_00003e6a;
          }
          uVar5 = uVar1;
        }
LAB_00003e6a:
        *(uint *)(iStack_20 * 4 + unaff_r6 + 0xb8) = uVar5;
        iStack_20 = iStack_20 + 1;
        pbVar2 = pbStack_24;
      }
LAB_00003e76:
      param_4 = param_4 + 1;
    }
    *(char *)(unaff_r6 + iStack_30 + 0x7a) = (char)iStack_20;
    uVar1 = (iStack_20 << 2 & uStack_2c) + 0x1c;
LAB_00003e8a:
    *(undefined1 *)(iStack_1c + 0xe6) = 0x11;
    FUN_00007272(param_1,0,0x11,(iStack_28 + 0x7cU & uVar1) + 0x8000,unaff_r6 + 0x9c);
    return;
  case 3:
    goto FUN_00003e04;
  case 4:
    goto FUN_00003dec;
  case 5:
  case 6:
    goto FUN_00003dfc;
  default:
    FUN_00007260(param_1,0,1);
    return;
  case 10:
    goto FUN_00003e0e;
  }
}

