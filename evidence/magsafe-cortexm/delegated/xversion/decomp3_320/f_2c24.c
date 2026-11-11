
void switchD_0000267a::caseD_2
               (int param_1,byte *param_2,byte *param_3,undefined4 param_4,byte param_5,byte param_6
               ,byte *param_7,int param_8,int param_9,int param_10)

{
  uint uVar1;
  undefined4 *puVar2;
  uint unaff_r4;
  uint *unaff_r5;
  uint unaff_r6;
  uint uVar3;
  uint uVar4;
  char in_ZR;
  
  while (in_ZR == '\0') {
    if (((*param_2 >> (unaff_r4 & 0xff) & 1) != 0) &&
       ((uVar1 = *unaff_r5, 1 < *param_3 || (uVar1 >> 0x1e < 3)))) {
      uVar3 = uVar1 >> 0x1e;
      uVar4 = uVar1;
      if (uVar3 == 2) {
        if (param_9 + 0x28U < (param_1 + 0x17U & uVar1)) {
          uVar4 = uVar1 & DAT_00002d3c | param_9 + 0x28U;
          param_6 = param_5;
        }
      }
      else if (uVar3 == 1) {
        uVar3 = param_1 * (uVar1 >> 10 & param_1 + 0x17U);
        if (uVar3 < (param_1 + 0x17U & uVar1)) {
          uVar4 = uVar3 & param_1 + 0x10U | uVar1 & DAT_00002d3c;
          param_6 = param_5;
        }
      }
      else if (uVar3 == 0) {
        uVar3 = param_1 + 0x17U & uVar1;
        if (param_9 + 0x28U < uVar3) {
          uVar4 = param_9 + (uVar1 & DAT_00002d44) + 0x28;
          param_6 = param_5;
        }
        else {
          uVar3 = uVar3 * 0x6e;
          if (DAT_00002d40 <= uVar3 && uVar3 - DAT_00002d40 != 0) {
            uVar4 = uVar1 & 0xffcfffff;
          }
          if ((uVar1 & 0x3fffff) >> 0x14 == 0) {
            uVar4 = uVar1;
          }
        }
      }
      *(uint *)(param_10 + unaff_r6 * 4 + 0x9c) = uVar4;
      unaff_r6 = unaff_r6 + 1;
      param_1 = param_8;
      param_2 = param_7;
    }
    unaff_r5 = unaff_r5 + 1;
    unaff_r4 = unaff_r4 + 1;
    in_ZR = unaff_r4 == 7;
  }
  if (unaff_r6 < 7) {
    puVar2 = (undefined4 *)(param_10 + unaff_r6 * 4 + 0x9c);
    for (uVar1 = unaff_r6; uVar1 < 7; uVar1 = uVar1 + 1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
  }
  *(byte *)(param_10 + 0x15b) = param_6 & 1;
  *(char *)(param_10 + 0x29) = (char)unaff_r6;
  uVar1 = DAT_00002d48;
  if (1 < *param_3) {
    uVar1 = DAT_00002d4c;
  }
  *(uint *)(param_10 + 0x9c) =
       (uint)(*param_2 >> 7) * 0x8000000 + (*(uint *)(param_10 + 0x9c) & 0xf7ffffff) & uVar1;
  return;
}

