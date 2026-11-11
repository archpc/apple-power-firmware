
void FUN_000036ec(uint param_1,int param_2,int param_3)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int unaff_r5;
  uint uVar5;
  int unaff_r6;
  int unaff_r7;
  uint uVar6;
  uint uVar7;
  undefined4 in_cr14;
  
  if (6 < param_2 - 2U) {
    return;
  }
  puVar1 = (&switchD_00003700::switchdataD_00003704)[param_2 - 2U];
  switch(param_2) {
  case 2:
    puVar1[unaff_r5] = 1;
    FUN_000030f0(param_1,9);
    return;
  case 3:
    puVar1 = (undefined *)(uint)*(byte *)(unaff_r5 + 0xe2);
  case 6:
    if (puVar1 != (undefined *)0x0) {
      *(undefined1 *)(unaff_r5 + 0xe2) = 0;
      FUN_00003258(param_1,0x10);
    }
    FUN_00003258(param_1,0x10);
    return;
  default:
    coprocessor_load(0,in_cr14,0x3704);
    (*(code *)**(undefined4 **)(unaff_r6 + 0x60))(param_1,0x10,0);
    FUN_00003140(param_1);
    break;
  case 8:
    param_3 = param_3 * 4;
    if (*(char *)(unaff_r6 + 0x1f) == '\x06') {
      (**(code **)(*(int *)(unaff_r6 + 0x60) + 0x10))(param_1,DAT_00003f1c);
    }
    else {
      FUN_00002bec(param_1,0xdc10);
      if ((*(char *)(unaff_r6 + 0x175) == '\0') && (*(char *)(param_3 + 0xee) == '\0')) {
        FUN_00007260(param_1,0,1,*(undefined1 *)(unaff_r6 + 0x29),unaff_r6 + 0x9c);
      }
      else {
        uVar5 = 0;
        *(undefined1 *)(param_3 + 0xee) = 0;
        if (*(char *)(unaff_r6 + 0x176) == '\0') {
          puVar4 = (uint *)(unaff_r7 + param_1 * 0x1cc + 0x180);
          for (uVar3 = 0; uVar3 != 6; uVar3 = uVar3 + 1) {
            puVar4[-0x32] = 0;
            if ((*(byte *)(unaff_r6 + 0x17e) >> (uVar3 & 0xff) & 1) != 0) {
              uVar2 = *puVar4;
              uVar6 = uVar2 >> 0x1e;
              uVar7 = uVar2;
              if (uVar6 == 2) {
                uVar6 = DAT_00003f08;
                if (500 < (uVar2 & 0x3ff)) {
LAB_00003e3c:
                  uVar7 = (uVar2 & uVar6) + 500;
                }
              }
              else {
                if (uVar6 == 1) goto LAB_00003e76;
                if (uVar6 == 0) {
                  uVar6 = DAT_00003f10;
                  if (500 < (uVar2 & 0x3ff)) goto LAB_00003e3c;
                  uVar6 = (uVar2 & 0x3ff) * 0x6e;
                  if (DAT_00003f0c <= uVar6 && uVar6 - DAT_00003f0c != 0) {
                    uVar7 = uVar2 & 0xffcfffff;
                  }
                  if ((uVar2 & 0x3fffff) >> 0x14 != 0) goto LAB_00003e6a;
                }
                uVar7 = uVar2;
              }
LAB_00003e6a:
              *(uint *)(uVar5 * 4 + unaff_r6 + 0xb8) = uVar7;
              uVar5 = uVar5 + 1;
            }
LAB_00003e76:
            puVar4 = puVar4 + 1;
          }
          *(char *)(unaff_r6 + 0x179) = (char)uVar5;
          uVar5 = (uVar5 & 0xff) * 4 + 0x1c;
        }
        else {
          uVar5 = (uint)*(byte *)(unaff_r6 + 0x29) << 2;
          if (param_1 < 2) {
            *(undefined1 *)(unaff_r6 + 0x176) = 0;
          }
        }
        *(undefined1 *)(param_3 + 0xe6) = 0x11;
        FUN_00007272(param_1,0,0x11,(uVar5 & 0x1fc) + 0x8000,unaff_r6 + 0x9c);
      }
    }
  }
  return;
}

