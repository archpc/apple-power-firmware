
void FUN_00005ed0(uint param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  int iVar4;
  char *pcVar5;
  undefined *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined *puVar10;
  code *pcVar11;
  undefined *puVar12;
  int *piVar13;
  int iVar14;
  uint uVar15;
  int local_20;
  
  FUN_00002f62();
  FUN_0000c838(param_1,9);
  local_20 = 1;
  FUN_00002ce4(param_1);
  iVar7 = DAT_0000629c;
  iVar14 = param_1 * 0xf0;
  piVar13 = (int *)(DAT_0000629c + iVar14);
  *(undefined1 *)((int)piVar13 + 0xa9) = 0;
  iVar8 = DAT_000062a0;
  puVar12 = (undefined *)(param_1 * 0x1cc);
  puVar10 = puVar12 + DAT_000062a0;
  puVar10[0x45] = 0x23;
  puVar3 = (undefined1 *)((int)piVar13 + 0xa9);
  iVar4 = FUN_0000631c(param_1,0);
  if (iVar4 != 0) {
    iVar7 = 0;
    uVar15 = (uint)*(byte *)(*piVar13 + 2);
    if ((uVar15 == 2) || (uVar15 == 8)) {
      (*(code *)**(undefined4 **)(puVar10 + 0x60))(param_1,0x41);
LAB_00006096:
      iVar8 = 0;
      iVar7 = 1;
LAB_00006098:
      if ((uVar15 & 0xfe) != 4) {
        local_20 = iVar7;
      }
    }
    else {
      pcVar11 = (code *)(uint)(byte)puVar10[0x15];
      if (uVar15 == 7) {
        cVar1 = puVar12[iVar8];
        *puVar3 = 1;
        if (puVar10[0x175] == '\0') {
          if ((pcVar11 != (code *)0x0) || (cVar1 != '\x02')) {
            iVar8 = 1;
            iVar7 = iVar8;
            if (pcVar11 != (code *)0x1) goto LAB_00006098;
            FUN_000031a0(param_1,0x10);
            goto LAB_00006096;
          }
          FUN_00002b28(param_1);
          uVar2 = puVar10[0x29];
        }
        else {
          FUN_00002b28(param_1);
          uVar2 = puVar10[0x29];
        }
        FUN_00006338(param_1,1,uVar2,puVar10 + 0x9c);
        goto LAB_00006096;
      }
      if (1 < uVar15 - 9) {
        iVar8 = iVar7;
        if (uVar15 != 0xb) goto LAB_00006032;
        iVar8 = 1;
        *puVar3 = 1;
        iVar7 = 0;
        goto LAB_00006098;
      }
      *puVar3 = 1;
      iVar8 = 1;
LAB_00006032:
      if ((uVar15 < 0xd) && (puVar12 = (undefined *)0x1, (1 << uVar15 & DAT_00006298) != 0)) {
        FUN_00005a38(param_1);
        iVar7 = 1;
      }
      if ((uVar15 == 0x15) || (uVar15 == 0x10)) {
        (*(code *)**(undefined4 **)(puVar10 + 0x60))(param_1,0x41,*piVar13);
        iVar7 = 1;
      }
      local_20 = iVar7;
      if ((uVar15 & 0xfe) == 4) {
        local_20 = 1;
      }
      if (uVar15 - 0x11 < 8) {
        puVar6 = (&switchD_000060ea::switchdataD_000060ec)[uVar15 - 0x11];
        switch(uVar15) {
        case 0x13:
          pcVar11 = *(code **)piVar13[0x18];
          iVar8 = 0xb;
          puVar6 = puVar12;
          break;
        case 0x14:
        case 0x15:
          param_1 = 0;
        default:
          FUN_0000c8e8(puVar12,param_1,0xe);
          piVar13[0x12] = param_1;
          *(undefined1 *)((int)piVar13 + 0x22) = 1;
          (**(code **)piVar13[0x18])(puVar12,0x15,param_1);
          return;
        case 0x17:
          break;
        }
        (*pcVar11)(puVar6,iVar8,puVar10);
        uVar9 = DAT_000066d8;
        if (*(char *)((int)piVar13 + 0x15) == '\x01') {
          FUN_000031a0(puVar12,0xe);
          FUN_00003038(puVar12,2,uVar9);
          return;
        }
        iVar7 = piVar13[0x18];
        (**(code **)(iVar7 + 0x2c))(puVar12,DAT_000066d8);
        (**(code **)(iVar7 + 0x30))
                  (puVar12,*(undefined2 *)(DAT_000066e0 + (uint)*(byte *)((int)piVar13 + 0x16) * 2))
        ;
        (**(code **)(iVar7 + 0x34))(puVar12);
        FUN_000031a0(puVar12,10);
        return;
      }
    }
    if ((iVar8 == 0) && (local_20 != 0)) goto switchD_00005f9e_caseD_4;
    goto switchD_00005f9e_caseD_7;
  }
  iVar8 = FUN_00005b48(param_1,0);
  if (iVar8 == 0) {
    iVar8 = FUN_00005b24(param_1,0);
    if (iVar8 == 0) {
      if (**(char **)(iVar7 + iVar14) == '\x01') {
        FUN_00005b6c(param_1);
      }
    }
    else {
      FUN_00005c68(param_1);
    }
    goto switchD_00005f9e_caseD_4;
  }
  pcVar5 = *(char **)(iVar7 + iVar14);
  if (0xe < (byte)pcVar5[2] - 1) goto switchD_00005f9e_caseD_7;
  cVar1 = puVar10[0x15];
  switch(pcVar5[2]) {
  case '\x01':
    if (puVar10[0x175] != '\0') {
LAB_00005fca:
      FUN_00003088(param_1);
      goto switchD_00005f9e_caseD_4;
    }
    if (cVar1 != '\0') {
      FUN_00005a38(param_1);
      goto switchD_00005f9e_caseD_4;
    }
    if (param_1 < 2) {
      puVar10[0x175] = 0;
    }
    uVar9 = 0xc;
    break;
  case '\x02':
    if ((cVar1 != '\x01') || (6 < (byte)pcVar5[1])) goto switchD_00005f9e_caseD_7;
LAB_00006166:
    uVar9 = 0x12;
    break;
  case '\x03':
    if ((puVar10[0x20] != '\x01') || (puVar10[0x1e] != cVar1)) goto switchD_00005f9e_caseD_4;
    if (cVar1 == '\0') {
      iVar7 = 0x110;
    }
    else {
      iVar7 = 0x10c;
    }
    if (*(uint *)(puVar10 + iVar7) >> 0x1c != 1) goto switchD_00005f9e_caseD_4;
    if (*(uint *)(pcVar5 + 8) >> 0x1c == 5) {
      uVar9 = 9;
    }
    else {
      if (*(uint *)(pcVar5 + 8) >> 0x1c != 8) goto switchD_00005f9e_caseD_4;
      uVar9 = 8;
    }
    break;
  case '\x04':
  case '\x05':
  case '\x06':
    goto switchD_00005f9e_caseD_4;
  default:
    goto switchD_00005f9e_caseD_7;
  case '\t':
    if (1 < (byte)puVar10[0x3e]) {
      if (cVar1 == '\x01') goto LAB_00006166;
      if (puVar10[0x175] != '\0') goto LAB_00005fca;
    }
    goto switchD_00005f9e_caseD_7;
  case '\n':
    if ((byte)puVar10[0x3e] < 2) goto switchD_00005f9e_caseD_7;
    if (pcVar5[1] != '\x01') goto switchD_00005f9e_caseD_4;
    if (cVar1 == '\x01') {
      uVar9 = 0x28;
    }
    else if (pcVar5[0xb] == '\x05') {
      FUN_0000b864(param_1);
      if (param_1 < 2) {
        puVar10[0x175] = 0;
      }
      uVar9 = 0xb;
    }
    else {
      uVar9 = 0x2c;
    }
    break;
  case '\v':
    if (((cVar1 == '\0') && (1 < (byte)puVar10[0x3e])) && (pcVar5[1] == '\x01')) {
      pcVar11 = (code *)**(undefined4 **)(puVar10 + 0x60);
      uVar9 = 0x3b;
LAB_000061fc:
      (*pcVar11)(param_1,uVar9,pcVar5);
      goto switchD_00005f9e_caseD_4;
    }
    goto switchD_00005f9e_caseD_7;
  case '\f':
    if (1 < (byte)puVar10[0x3e]) {
      pcVar11 = (code *)**(undefined4 **)(puVar10 + 0x60);
      uVar9 = 0x3c;
      goto LAB_000061fc;
    }
switchD_00005f9e_caseD_7:
    FUN_00006364(param_1);
    goto switchD_00005f9e_caseD_4;
  case '\x0f':
    if (*pcVar5 == '\0') {
      *(undefined2 *)(piVar13 + 0x2c) = 0;
      *(short *)((int)piVar13 + 0xaa) = (short)DAT_00006294;
      *puVar3 = 0;
      FUN_00002ce4(param_1,0x800);
      (**(code **)(*(int *)(puVar10 + 0x60) + 0x50))(param_1,pcVar5,DAT_000062a4);
      FUN_00003038(param_1,9,0x14);
      FUN_00002ce4(param_1,0x100);
      puVar10[0x45] = '$';
      return;
    }
    goto switchD_00005f9e_caseD_4;
  }
  FUN_000031a0(param_1,uVar9);
switchD_00005f9e_caseD_4:
  if ((puVar10[0x45] == '#') && (iVar7 = FUN_0000c880(param_1,9), iVar7 == 0)) {
    FUN_00002908(param_1,4);
  }
  return;
}

