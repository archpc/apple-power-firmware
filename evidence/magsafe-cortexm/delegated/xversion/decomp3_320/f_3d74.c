
void FUN_00003d74(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint unaff_r4;
  int iVar4;
  int unaff_r6;
  int unaff_r7;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iStack00000000;
  int in_stack_00000008;
  undefined4 uStack00000010;
  int in_stack_0000001c;
  
  iVar4 = 0;
  *(undefined1 *)(param_2 + param_1) = 0;
  uStack00000010 = 0x180;
  if (*(char *)(unaff_r6 + 0x176) == '\0') {
    puVar3 = (uint *)(unaff_r7 + unaff_r4 * 0x1cc + 0x180);
    for (uVar2 = 0; uVar2 != 6; uVar2 = uVar2 + 1) {
      puVar3[-0x32] = 0;
      if ((*(byte *)(unaff_r6 + 0x17e) >> (uVar2 & 0xff) & 1) != 0) {
        uVar1 = *puVar3;
        uVar5 = uVar1 >> 0x1e;
        uVar7 = uVar1;
        if (uVar5 == 2) {
          uVar5 = DAT_00003f08;
          if (500 < (in_stack_00000008 * 4 + 3U & uVar1)) {
LAB_00003e3c:
            uVar7 = (uVar1 & uVar5) + 500;
          }
        }
        else {
          if (uVar5 == 1) goto LAB_00003e76;
          if (uVar5 == 0) {
            uVar6 = in_stack_00000008 * 4 + 3U & uVar1;
            uVar5 = DAT_00003f10;
            if (500 < uVar6) goto LAB_00003e3c;
            uVar6 = uVar6 * 0x6e;
            if (DAT_00003f0c <= uVar6 && uVar6 - DAT_00003f0c != 0) {
              uVar7 = uVar1 & 0xffcfffff;
            }
            if ((uVar1 & 0x3fffff) >> 0x14 != 0) goto LAB_00003e6a;
          }
          uVar7 = uVar1;
        }
LAB_00003e6a:
        *(uint *)(iVar4 * 4 + unaff_r6 + 0xb8) = uVar7;
        iVar4 = iVar4 + 1;
      }
LAB_00003e76:
      puVar3 = puVar3 + 1;
    }
    *(char *)(unaff_r6 + in_stack_00000008 + 0x7a) = (char)iVar4;
  }
  else if (unaff_r4 < 2) {
    *(undefined1 *)(unaff_r6 + 0x176) = 0;
  }
  *(undefined1 *)(in_stack_0000001c + 0xe6) = 0x11;
  iStack00000000 = unaff_r6 + 0x9c;
  FUN_00007272();
  return;
}

