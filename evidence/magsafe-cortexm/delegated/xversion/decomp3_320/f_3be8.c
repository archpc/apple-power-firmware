
void FUN_00003be8(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int *piVar7;
  code *pcVar8;
  uint *puVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int local_18;
  
  iVar1 = DAT_00003f18;
  if (0xb < param_2 - 2U) {
    return;
  }
  piVar7 = (int *)(DAT_00003f14 + param_1 * 0xf0);
  iVar10 = DAT_00003f18 + param_1 * 0x1cc;
  switch(param_2) {
  case 2:
    if (*(char *)(iVar10 + 0x1f) == '\x06') {
      (**(code **)(*(int *)(iVar10 + 0x60) + 0x10))(param_1,DAT_00003f1c);
      return;
    }
    FUN_00002bec(param_1);
    if ((*(char *)(iVar10 + 0x175) == '\0') && (*(char *)((int)piVar7 + 0xee) == '\0')) {
      FUN_00007260(param_1,0,1,*(undefined1 *)(iVar10 + 0x29),iVar10 + 0x9c);
      return;
    }
    uVar2 = 0;
    *(undefined1 *)((int)piVar7 + 0xee) = 0;
    if (*(char *)(iVar10 + 0x176) == '\0') {
      puVar9 = (uint *)(iVar1 + param_1 * 0x1cc + 0x180);
      for (uVar6 = 0; uVar6 != 6; uVar6 = uVar6 + 1) {
        puVar9[-0x32] = 0;
        if ((*(byte *)(iVar10 + 0x17e) >> (uVar6 & 0xff) & 1) != 0) {
          uVar4 = *puVar9;
          uVar11 = uVar4 >> 0x1e;
          uVar12 = uVar4;
          if (uVar11 == 2) {
            uVar11 = DAT_00003f08;
            if (500 < (uVar4 & 0x3ff)) {
LAB_00003e3c:
              uVar12 = (uVar4 & uVar11) + 500;
            }
          }
          else {
            if (uVar11 == 1) goto LAB_00003e76;
            if (uVar11 == 0) {
              uVar11 = DAT_00003f10;
              if (500 < (uVar4 & 0x3ff)) goto LAB_00003e3c;
              uVar11 = (uVar4 & 0x3ff) * 0x6e;
              if (DAT_00003f0c <= uVar11 && uVar11 - DAT_00003f0c != 0) {
                uVar12 = uVar4 & 0xffcfffff;
              }
              if ((uVar4 & 0x3fffff) >> 0x14 != 0) goto LAB_00003e6a;
            }
            uVar12 = uVar4;
          }
LAB_00003e6a:
          *(uint *)(uVar2 * 4 + iVar10 + 0xb8) = uVar12;
          uVar2 = uVar2 + 1;
        }
LAB_00003e76:
        puVar9 = puVar9 + 1;
      }
      *(char *)(iVar10 + 0x179) = (char)uVar2;
      uVar2 = (uVar2 & 0xff) * 4 + 0x1c;
    }
    else {
      uVar2 = (uint)*(byte *)(iVar10 + 0x29) << 2;
      if (param_1 < 2) {
        *(undefined1 *)(iVar10 + 0x176) = 0;
      }
    }
    *(undefined1 *)((int)piVar7 + 0xe6) = 0x11;
    iVar10 = iVar10 + 0x9c;
    iVar1 = (uVar2 & 0x1fc) + 0x8000;
LAB_00003ea2:
    FUN_00007272(param_1,0,0x11,iVar1,iVar10);
    break;
  case 3:
    FUN_0000ca08(param_1,2);
    FUN_00002db8(param_1,0x2000);
    *(undefined2 *)(piVar7 + 0x29) = 0;
    *(undefined1 *)(iVar10 + 0x21) = 1;
    FUN_000030f0(param_1,9,0x1b);
    pcVar8 = (code *)**(undefined4 **)(iVar10 + 0x60);
    uVar5 = 0x28;
    goto LAB_00003cc2;
  case 4:
    if (*(char *)(iVar10 + 0x20) != '\x01') goto switchD_00003c12_caseD_5;
    if (*(char *)((int)piVar7 + 0xa9) != '\x01') {
      uVar5 = 0x23;
      goto LAB_00003dae;
    }
LAB_00003ee6:
    FUN_00005b5c(param_1);
    break;
  case 5:
switchD_00003c12_caseD_5:
    if (*(char *)(iVar10 + 0x21) != '\0') goto LAB_00003ee6;
    *(char *)((int)piVar7 + 0xa5) = *(char *)((int)piVar7 + 0xa5) + '\x01';
    FUN_00006dc0(param_1,0);
    FUN_00003258(param_1,0x11);
    if (*(char *)((int)piVar7 + 0xa5) != '\x06') {
      return;
    }
    pcVar8 = (code *)**(undefined4 **)(iVar10 + 0x60);
    uVar5 = 0x27;
LAB_00003cc2:
    (*pcVar8)(param_1,uVar5,0);
    break;
  case 6:
    iVar1 = *piVar7;
    if (*(char *)(iVar10 + 0x175) == '\0') {
      iVar1 = FUN_0000308c(iVar1,0,1,4,DAT_00003f04);
      if (iVar1 == 0) {
LAB_00003ee0:
        FUN_00005bf0(param_1);
        goto LAB_00003ee6;
      }
    }
    else {
      local_18 = (uint)*(ushort *)(iVar1 + 8) * 0x10000 + (uint)*(ushort *)(iVar1 + 4);
      FUN_00000170(iVar1 + 4,&local_18,4);
      uVar5 = DAT_00003f04;
      iVar1 = *piVar7;
      if ((*(char *)(iVar1 + 2) == '\x11') && (uVar2 = *(uint *)(iVar1 + 4), (int)uVar2 < 0)) {
        if (((-1 < (int)(uVar2 << 5)) || ((uVar2 & 0x7fffffff) >> 0x1b != 1)) ||
           (uVar2 = (uint)*(byte *)(iVar10 + 0x179) * 4 + 0x1c & 0x1fc, uVar2 < 0x1b))
        goto LAB_00003ee0;
        *(undefined1 *)((int)piVar7 + 0xe6) = 0x11;
        iVar10 = iVar10 + 0xb6;
        iVar1 = uVar2 + 0x8800;
        goto LAB_00003ea2;
      }
      iVar3 = FUN_0000308c(iVar1,0,1,0x200,DAT_00003f04);
      if (iVar3 == 0) {
        iVar1 = FUN_0000308c(iVar1,0,1,4,uVar5);
        if (iVar1 == 0) goto LAB_00003ee0;
        if (*(char *)(iVar10 + 0x175) != '\0') goto LAB_00003d34;
      }
      else if (*(char *)(iVar10 + 0x175) == '\0') {
LAB_00003d34:
        FUN_00003140(param_1);
        return;
      }
    }
    uVar5 = 0x12;
LAB_00003dae:
    FUN_00003258(param_1,uVar5);
    return;
  case 7:
    FUN_00006648(param_1);
    break;
  case 8:
    (*(code *)**(undefined4 **)(iVar10 + 0x60))(param_1,0x10,0);
    goto LAB_00003d34;
  case 0xd:
    if (*(char *)(iVar10 + 0x21) == '\0') {
      FUN_000028b8(param_1,0x2000);
    }
  }
  return;
}

