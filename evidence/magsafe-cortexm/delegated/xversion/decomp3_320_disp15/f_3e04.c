
void FUN_00003e04(uint param_1,byte *param_2,uint param_3,uint *param_4,undefined4 param_5,
                 int param_6,int param_7,int param_8,int param_9,byte *param_10,undefined4 param_11,
                 int param_12)

{
  uint *puVar1;
  int unaff_r5;
  int unaff_r6;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  do {
    uVar2 = param_1 >> 0x1e;
    puVar1 = param_4;
    uVar4 = param_1;
    if (uVar2 == 2) {
      uVar2 = DAT_00003f08;
      if (param_9 + 0x74U < (param_8 + 3U & param_1)) {
LAB_00003e3c:
        uVar4 = param_9 + (param_1 & uVar2) + 0x74;
      }
LAB_00003e6a:
      *(uint *)(unaff_r5 * 4 + unaff_r6 + 0xb8) = uVar4;
      unaff_r5 = unaff_r5 + 1;
      param_2 = param_10;
    }
    else if (uVar2 != 1) {
      if (uVar2 == 0) {
        uVar3 = param_8 + 3U & param_1;
        uVar2 = DAT_00003f10;
        if (param_9 + 0x74U < uVar3) goto LAB_00003e3c;
        uVar3 = uVar3 * 0x6e;
        if (DAT_00003f0c <= uVar3 && uVar3 - DAT_00003f0c != 0) {
          uVar4 = param_1 & ~(param_6 << 0x14);
        }
        if ((param_1 & 0x3fffff) >> 0x14 != 0) goto LAB_00003e6a;
      }
      uVar4 = param_1;
      goto LAB_00003e6a;
    }
    do {
      param_4 = puVar1 + 1;
      param_3 = param_3 + 1;
      if (param_3 == 6) {
        *(char *)(unaff_r6 + param_7 + 0x7a) = (char)unaff_r5;
        *(undefined1 *)(param_12 + 0xe6) = 0x11;
        param_5 = unaff_r6 + 0x9c;
        FUN_00007272();
        return;
      }
      puVar1[-0x31] = 0;
      puVar1 = param_4;
    } while ((*param_2 >> (param_3 & 0xff) & 1) == 0);
    param_1 = *param_4;
  } while( true );
}

