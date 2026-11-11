
void FUN_00002b70(undefined4 param_1,int param_2,uint param_3,uint *param_4,undefined4 param_5,
                 byte param_6,byte param_7,byte *param_8,int param_9,byte *param_10,uint param_11)

{
  undefined4 *puVar1;
  uint unaff_r4;
  int iVar2;
  byte *unaff_r5;
  uint unaff_r6;
  uint uVar3;
  uint uVar4;
  
  do {
    uVar3 = unaff_r6 >> 0x1e;
    if ((uVar3 < 3) || (1 < *param_10)) {
      if (uVar3 == 2) {
        if (param_3 < (param_2 + 0x17U & unaff_r6)) {
          uVar3 = unaff_r6 & DAT_00002c68 | param_3;
          param_7 = param_6;
          goto LAB_00002bf4;
        }
LAB_00002bf2:
        uVar3 = unaff_r6;
      }
      else {
        if (uVar3 == 1) {
          uVar3 = param_2 * (unaff_r6 >> 10 & param_2 + 0x17U);
          if (uVar3 < (param_2 + 0x17U & unaff_r6)) {
            uVar3 = uVar3 & param_2 + 0x10U | unaff_r6 & DAT_00002c68;
            param_7 = param_6;
            goto LAB_00002bf4;
          }
          goto LAB_00002bf2;
        }
        if (uVar3 != 0) goto LAB_00002bf2;
        uVar4 = param_2 + 0x17U & unaff_r6;
        if (param_3 < uVar4) {
          uVar3 = (unaff_r6 & DAT_00002c70) + param_3;
          param_7 = param_6;
        }
        else {
          uVar4 = uVar4 * 0x6e;
          uVar3 = unaff_r6;
          if (DAT_00002c6c <= uVar4 && uVar4 - DAT_00002c6c != 0) {
            uVar3 = unaff_r6 & 0xffcfffff;
          }
          if ((unaff_r6 & 0x3fffff) >> 0x14 == 0) goto LAB_00002bf2;
        }
      }
LAB_00002bf4:
      *(uint *)(param_9 + param_11 * 4 + 0x9c) = uVar3;
      param_11 = param_11 + 1;
      unaff_r5 = param_8;
    }
    do {
      param_4 = param_4 + 1;
      unaff_r4 = unaff_r4 + 1;
      if (unaff_r4 == 7) {
        if (param_11 < 7) {
          puVar1 = (undefined4 *)(param_9 + param_11 * 4 + 0x9c);
          for (iVar2 = param_11 - 7; iVar2 != 0; iVar2 = iVar2 + 1) {
            *puVar1 = 0;
            puVar1 = puVar1 + 1;
          }
        }
        *(byte *)(param_9 + 0x15b) = param_7 & 1;
        *(char *)(param_9 + 0x29) = (char)param_11;
        uVar3 = DAT_00002c74;
        if (1 < *param_10) {
          uVar3 = DAT_00002c78;
        }
        *(uint *)(param_9 + 0x9c) =
             (uint)(*param_8 >> 7) * 0x8000000 + (*(uint *)(param_9 + 0x9c) & 0xf6bfffff) & uVar3;
        return;
      }
    } while ((*unaff_r5 >> (unaff_r4 & 0xff) & 1) == 0);
    unaff_r6 = *param_4;
  } while( true );
}

