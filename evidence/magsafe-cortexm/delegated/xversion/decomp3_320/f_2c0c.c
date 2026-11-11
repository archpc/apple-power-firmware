
void switchD_0000267a::caseD_0(undefined4 param_1,int param_2,int param_3)

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
  
  uVar3 = unaff_r6;
  uVar6 = unaff_r6;
  do {
    if (unaff_r6 == 7) {
      if (uVar3 < 7) {
        puVar2 = (undefined4 *)(param_2 + uVar3 * 4 + 0x9c);
        for (uVar1 = uVar3; uVar1 < 7; uVar1 = uVar1 + 1) {
          *puVar2 = 0;
          puVar2 = puVar2 + 1;
        }
      }
      *(byte *)(param_2 + 0x15b) = (byte)uVar6 & 1;
      *(char *)(param_2 + 0x29) = (char)uVar3;
      uVar3 = DAT_00002d48;
      if (1 < *(byte *)(param_3 + 0x3e)) {
        uVar3 = DAT_00002d4c;
      }
      *(uint *)(param_2 + 0x9c) =
           (uint)(*(byte *)(param_2 + 10) >> 7) * 0x8000000 +
           (*(uint *)(param_2 + 0x9c) & 0xf7ffffff) & uVar3;
      return;
    }
    if (((*(byte *)(param_2 + 10) >> (unaff_r6 & 0xff) & 1) != 0) &&
       ((uVar1 = *unaff_r5, 1 < *(byte *)(param_3 + 0x3e) || (uVar1 >> 0x1e < 3)))) {
      uVar4 = uVar1 >> 0x1e;
      uVar5 = uVar1;
      if (uVar4 == 2) {
        if (in_stack_00000010 + 0x28U < (uVar1 & 0x3ff)) {
          uVar5 = uVar1 & DAT_00002d3c | in_stack_00000010 + 0x28U;
LAB_00002c7a:
          uVar6 = 1;
        }
      }
      else if (uVar4 == 1) {
        uVar4 = (uVar1 >> 10 & 0x3ff) * 1000;
        if (uVar4 < (uVar1 & 0x3ff)) {
          uVar6 = 1;
          uVar5 = uVar4 & 0x3f8 | uVar1 & DAT_00002d3c;
        }
      }
      else if (uVar4 == 0) {
        if (in_stack_00000010 + 0x28U < (uVar1 & 0x3ff)) {
          uVar5 = in_stack_00000010 + (uVar1 & DAT_00002d44) + 0x28;
          goto LAB_00002c7a;
        }
        uVar4 = (uVar1 & 0x3ff) * 0x6e;
        if (DAT_00002d40 <= uVar4 && uVar4 - DAT_00002d40 != 0) {
          uVar5 = uVar1 & 0xffcfffff;
        }
        if ((uVar1 & 0x3fffff) >> 0x14 == 0) {
          uVar5 = uVar1;
        }
      }
      *(uint *)(param_2 + uVar3 * 4 + 0x9c) = uVar5;
      uVar3 = uVar3 + 1;
    }
    unaff_r5 = unaff_r5 + 1;
    unaff_r6 = unaff_r6 + 1;
  } while( true );
}

