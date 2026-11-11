
void switchD_0000267a::caseD_9(undefined4 param_1,byte *param_2,byte *param_3,int param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  uint *unaff_r5;
  uint unaff_r6;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int in_stack_00000010;
  int in_stack_00000014;
  
  param_4 = param_4 * 8;
  uVar3 = unaff_r6;
  uVar6 = unaff_r6;
  do {
    if (unaff_r6 == 7) {
      if (uVar3 < 7) {
        puVar2 = (undefined4 *)(in_stack_00000014 + uVar3 * 4 + 0x9c);
        for (uVar1 = uVar3; uVar1 < 7; uVar1 = uVar1 + 1) {
          *puVar2 = 0;
          puVar2 = puVar2 + 1;
        }
      }
      *(byte *)(in_stack_00000014 + 0x15b) = (byte)uVar6 & 1;
      *(char *)(in_stack_00000014 + 0x29) = (char)uVar3;
      uVar3 = DAT_00002d48;
      if (1 < *param_3) {
        uVar3 = DAT_00002d4c;
      }
      *(uint *)(in_stack_00000014 + 0x9c) =
           (uint)(*param_2 >> 7) * 0x8000000 + (*(uint *)(in_stack_00000014 + 0x9c) & 0xf7ffffff) &
           uVar3;
      return;
    }
    if (((*param_2 >> (unaff_r6 & 0xff) & 1) != 0) &&
       ((uVar1 = *unaff_r5, 1 < *param_3 || (uVar1 >> 0x1e < 3)))) {
      uVar4 = uVar1 >> 0x1e;
      uVar5 = uVar1;
      if (uVar4 == 2) {
        if (in_stack_00000010 + 0x28U < (param_4 + 0x17U & uVar1)) {
          uVar5 = uVar1 & DAT_00002d3c | in_stack_00000010 + 0x28U;
LAB_00002c7a:
          uVar6 = 1;
        }
      }
      else if (uVar4 == 1) {
        uVar4 = param_4 * (uVar1 >> 10 & param_4 + 0x17U);
        if (uVar4 < (param_4 + 0x17U & uVar1)) {
          uVar6 = 1;
          uVar5 = uVar4 & param_4 + 0x10U | uVar1 & DAT_00002d3c;
        }
      }
      else if (uVar4 == 0) {
        uVar4 = param_4 + 0x17U & uVar1;
        if (in_stack_00000010 + 0x28U < uVar4) {
          uVar5 = in_stack_00000010 + (uVar1 & DAT_00002d44) + 0x28;
          goto LAB_00002c7a;
        }
        uVar4 = uVar4 * 0x6e;
        if (DAT_00002d40 <= uVar4 && uVar4 - DAT_00002d40 != 0) {
          uVar5 = uVar1 & 0xffcfffff;
        }
        if ((uVar1 & 0x3fffff) >> 0x14 == 0) {
          uVar5 = uVar1;
        }
      }
      *(uint *)(in_stack_00000014 + uVar3 * 4 + 0x9c) = uVar5;
      uVar3 = uVar3 + 1;
    }
    unaff_r5 = unaff_r5 + 1;
    unaff_r6 = unaff_r6 + 1;
  } while( true );
}

