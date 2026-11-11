
void FUN_00005ed0(uint param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  code *pcVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  int local_20;
  
  FUN_00002f62();
  FUN_0000c88c(param_1,9);
  local_20 = 1;
  FUN_00002ce4(param_1);
  iVar6 = DAT_0000629c;
  iVar13 = param_1 * 0xf0;
  piVar12 = (int *)(DAT_0000629c + iVar13);
  *(undefined1 *)((int)piVar12 + 0xa9) = 0;
  iVar7 = DAT_000062a0;
  iVar11 = param_1 * 0x1cc;
  iVar9 = DAT_000062a0 + iVar11;
  *(undefined1 *)(iVar9 + 0x45) = 0x23;
  puVar3 = (undefined1 *)((int)piVar12 + 0xa9);
  iVar4 = FUN_0000631c(param_1,0);
  if (iVar4 != 0) {
    iVar6 = 0;
    uVar14 = (uint)*(byte *)(*piVar12 + 2);
    if ((uVar14 == 2) || (uVar14 == 8)) {
      (*(code *)**(undefined4 **)(iVar9 + 0x60))(param_1,0x41);
LAB_00006096:
      iVar7 = 0;
      iVar6 = 1;
LAB_00006098:
      if ((uVar14 & 0xfe) != 4) {
        local_20 = iVar6;
      }
    }
    else {
      pcVar10 = (code *)(uint)*(byte *)(iVar9 + 0x15);
      if (uVar14 == 7) {
        cVar1 = *(char *)(iVar7 + iVar11);
        *puVar3 = 1;
        if (*(char *)(iVar9 + 0x175) == '\0') {
          if ((pcVar10 != (code *)0x0) || (cVar1 != '\x02')) {
            iVar7 = 1;
            iVar6 = iVar7;
            if (pcVar10 != (code *)0x1) goto LAB_00006098;
            FUN_000031a0(param_1,0x10);
            goto LAB_00006096;
          }
          FUN_00002b28(param_1);
          uVar2 = *(undefined1 *)(iVar9 + 0x29);
        }
        else {
          FUN_00002b28(param_1);
          uVar2 = *(undefined1 *)(iVar9 + 0x29);
        }
        FUN_00006338(param_1,1,uVar2,iVar9 + 0x9c);
        goto LAB_00006096;
      }
      if (1 < uVar14 - 9) {
        iVar7 = iVar6;
        if (uVar14 != 0xb) goto LAB_00006032;
        iVar7 = 1;
        *puVar3 = 1;
        iVar6 = 0;
        goto LAB_00006098;
      }
      *puVar3 = 1;
      iVar7 = 1;
LAB_00006032:
      if ((uVar14 < 0xd) && (iVar11 = 1, (1 << uVar14 & DAT_00006298) != 0)) {
        FUN_00005a38(param_1);
        iVar6 = 1;
      }
      if ((uVar14 == 0x15) || (uVar14 == 0x10)) {
        (*(code *)**(undefined4 **)(iVar9 + 0x60))(param_1,0x41,*piVar12);
        iVar6 = 1;
      }
      local_20 = iVar6;
      if ((uVar14 & 0xfe) == 4) {
        local_20 = 1;
      }
      if (uVar14 - 0x11 < 8) {
        iVar6 = *(int *)(&DAT_000060ec + (uVar14 - 0x11) * 4);
        switch(uVar14) {
        case 0x13:
          pcVar10 = *(code **)piVar12[0x18];
          iVar7 = 0xb;
          iVar6 = iVar11;
          break;
        case 0x14:
        case 0x15:
          param_1 = 0;
        default:
          FUN_0000c93c(iVar11,param_1,0xe);
          piVar12[0x12] = param_1;
          *(undefined1 *)((int)piVar12 + 0x22) = 1;
          (**(code **)piVar12[0x18])(iVar11,0x15,param_1);
          return;
        case 0x17:
          break;
        }
        (*pcVar10)(iVar6,iVar7,iVar9);
        uVar8 = DAT_000066d8;
        if (*(char *)((int)piVar12 + 0x15) == '\x01') {
          FUN_000031a0(iVar11,0xe);
          FUN_00003038(iVar11,2,uVar8);
          return;
        }
        iVar6 = piVar12[0x18];
        (**(code **)(iVar6 + 0x2c))(iVar11,DAT_000066d8);
        (**(code **)(iVar6 + 0x30))
                  (iVar11,*(undefined2 *)(DAT_000066e0 + (uint)*(byte *)((int)piVar12 + 0x16) * 2));
        (**(code **)(iVar6 + 0x34))(iVar11);
        FUN_000031a0(iVar11,10);
        return;
      }
    }
    if ((iVar7 == 0) && (local_20 != 0)) goto switchD_00005f9e_caseD_4;
    goto switchD_00005f9e_caseD_7;
  }
  iVar7 = FUN_00005b48(param_1,0);
  if (iVar7 == 0) {
    iVar7 = FUN_00005b24(param_1,0);
    if (iVar7 == 0) {
      if (**(char **)(iVar6 + iVar13) == '\x01') {
        FUN_00005b6c(param_1);
      }
    }
    else {
      FUN_00005c68(param_1);
    }
    goto switchD_00005f9e_caseD_4;
  }
  pcVar5 = *(char **)(iVar6 + iVar13);
  if (0xe < (byte)pcVar5[2] - 1) goto switchD_00005f9e_caseD_7;
  cVar1 = *(char *)(iVar9 + 0x15);
  switch(pcVar5[2]) {
  case '\x01':
    if (*(char *)(iVar9 + 0x175) != '\0') {
LAB_00005fca:
      FUN_00003088(param_1);
      goto switchD_00005f9e_caseD_4;
    }
    if (cVar1 != '\0') {
      FUN_00005a38(param_1);
      goto switchD_00005f9e_caseD_4;
    }
    if (param_1 < 2) {
      *(undefined1 *)(iVar9 + 0x175) = 0;
    }
    uVar8 = 0xc;
    break;
  case '\x02':
    if ((cVar1 != '\x01') || (6 < (byte)pcVar5[1])) goto switchD_00005f9e_caseD_7;
LAB_00006166:
    uVar8 = 0x12;
    break;
  case '\x03':
    if ((*(char *)(iVar9 + 0x20) != '\x01') || (*(char *)(iVar9 + 0x1e) != cVar1))
    goto switchD_00005f9e_caseD_4;
    if (cVar1 == '\0') {
      iVar6 = 0x110;
    }
    else {
      iVar6 = 0x10c;
    }
    if (*(uint *)(iVar9 + iVar6) >> 0x1c != 1) goto switchD_00005f9e_caseD_4;
    if (*(uint *)(pcVar5 + 8) >> 0x1c == 5) {
      uVar8 = 9;
    }
    else {
      if (*(uint *)(pcVar5 + 8) >> 0x1c != 8) goto switchD_00005f9e_caseD_4;
      uVar8 = 8;
    }
    break;
  case '\x04':
  case '\x05':
  case '\x06':
    goto switchD_00005f9e_caseD_4;
  default:
    goto switchD_00005f9e_caseD_7;
  case '\t':
    if (1 < *(byte *)(iVar9 + 0x3e)) {
      if (cVar1 == '\x01') goto LAB_00006166;
      if (*(char *)(iVar9 + 0x175) != '\0') goto LAB_00005fca;
    }
    goto switchD_00005f9e_caseD_7;
  case '\n':
    if (*(byte *)(iVar9 + 0x3e) < 2) goto switchD_00005f9e_caseD_7;
    if (pcVar5[1] != '\x01') goto switchD_00005f9e_caseD_4;
    if (cVar1 == '\x01') {
      uVar8 = 0x28;
    }
    else if (pcVar5[0xb] == '\x05') {
      FUN_0000b8b8(param_1);
      if (param_1 < 2) {
        *(undefined1 *)(iVar9 + 0x175) = 0;
      }
      uVar8 = 0xb;
    }
    else {
      uVar8 = 0x2c;
    }
    break;
  case '\v':
    if (((cVar1 == '\0') && (1 < *(byte *)(iVar9 + 0x3e))) && (pcVar5[1] == '\x01')) {
      pcVar10 = (code *)**(undefined4 **)(iVar9 + 0x60);
      uVar8 = 0x3b;
LAB_000061fc:
      (*pcVar10)(param_1,uVar8,pcVar5);
      goto switchD_00005f9e_caseD_4;
    }
    goto switchD_00005f9e_caseD_7;
  case '\f':
    if (1 < *(byte *)(iVar9 + 0x3e)) {
      pcVar10 = (code *)**(undefined4 **)(iVar9 + 0x60);
      uVar8 = 0x3c;
      goto LAB_000061fc;
    }
switchD_00005f9e_caseD_7:
    FUN_00006364(param_1);
    goto switchD_00005f9e_caseD_4;
  case '\x0f':
    if (*pcVar5 == '\0') {
      *(undefined2 *)(piVar12 + 0x2c) = 0;
      *(short *)((int)piVar12 + 0xaa) = (short)DAT_00006294;
      *puVar3 = 0;
      FUN_00002ce4(param_1,0x800);
      (**(code **)(*(int *)(iVar9 + 0x60) + 0x50))(param_1,pcVar5,DAT_000062a4);
      FUN_00003038(param_1,9,0x14);
      FUN_00002ce4(param_1,0x100);
      *(char *)(iVar9 + 0x45) = '$';
      return;
    }
    goto switchD_00005f9e_caseD_4;
  }
  FUN_000031a0(param_1,uVar8);
switchD_00005f9e_caseD_4:
  if ((*(char *)(iVar9 + 0x45) == '#') && (iVar6 = FUN_0000c8d4(param_1,9), iVar6 == 0)) {
    FUN_00002908(param_1,4);
  }
  return;
}

