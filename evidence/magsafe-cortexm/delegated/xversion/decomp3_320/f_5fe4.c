
void FUN_00005fe4(uint param_1)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  char *pcVar10;
  code *pcVar11;
  undefined4 *puVar12;
  
  FUN_0000301a(param_1,0);
  FUN_0000ca08(param_1,9);
  FUN_00002db8(param_1);
  puVar12 = (undefined4 *)(DAT_0000631c + param_1 * 0xf0);
  *(undefined1 *)((int)puVar12 + 0xa9) = 0;
  iVar7 = DAT_00006320;
  iVar9 = DAT_00006320 + param_1 * 0x1cc;
  *(undefined1 *)(iVar9 + 0x45) = 0x23;
  puVar4 = (undefined1 *)((int)puVar12 + 0xa9);
  iVar5 = FUN_0000639c(param_1,0);
  if (iVar5 != 0) {
    pcVar10 = (char *)*puVar12;
    uVar6 = (uint)(byte)pcVar10[2];
    if ((uVar6 == 2) || (uVar6 == 8)) {
      pcVar11 = (code *)**(undefined4 **)(iVar9 + 0x60);
LAB_0000618e:
      uVar8 = 0x41;
LAB_00006192:
      (*pcVar11)(param_1,uVar8,pcVar10);
      goto switchD_000060ba_caseD_4;
    }
    bVar3 = false;
    cVar1 = *(char *)(iVar9 + 0x15);
    if (uVar6 == 7) {
      cVar2 = *(char *)(iVar7 + param_1 * 0x1cc);
      *puVar4 = 1;
      if ((*(char *)(iVar9 + 0x175) != '\0') || ((cVar1 == '\0' && (cVar2 == '\x02')))) {
        FUN_00002bec(param_1);
        FUN_000063b8(param_1,1,*(undefined1 *)(iVar9 + 0x29),iVar9 + 0x9c);
        goto switchD_000060ba_caseD_4;
      }
      if (cVar1 == '\x01') {
        uVar8 = 0x10;
        goto LAB_00006310;
      }
      goto switchD_000060ba_caseD_7;
    }
    if (uVar6 - 9 < 2) {
      *puVar4 = 1;
      goto switchD_0000613e_caseD_4;
    }
    switch(uVar6) {
    case 3:
    case 6:
    case 0xc:
      FUN_00005b5c(param_1);
      bVar3 = true;
    default:
switchD_0000613e_caseD_4:
      if ((uVar6 == 0x15) || (uVar6 == 0x10)) {
        (*(code *)**(undefined4 **)(iVar9 + 0x60))(param_1,0x41,*puVar12);
        bVar3 = true;
      }
      break;
    case 0xb:
      goto switchD_0000617e_caseD_13;
    }
    switch(uVar6) {
    case 0x11:
    case 0x12:
    case 0x16:
    case 0x18:
switchD_0000617e_caseD_11:
      pcVar11 = (code *)**(undefined4 **)(iVar9 + 0x60);
      pcVar10 = (char *)*puVar12;
      goto LAB_0000618e;
    case 0x13:
switchD_0000617e_caseD_13:
      *puVar4 = 1;
      break;
    default:
      if ((1 < uVar6 - 9) && (((uVar6 & 0xfe) == 4 || (bVar3)))) goto switchD_000060ba_caseD_4;
      break;
    case 0x17:
      if (cVar1 != '\0') goto switchD_0000617e_caseD_11;
    }
    goto switchD_000060ba_caseD_7;
  }
  iVar7 = FUN_00005c68(param_1,0);
  if (iVar7 == 0) {
    iVar7 = FUN_00005c44(param_1,0);
    if (iVar7 == 0) {
      if (*(char *)*puVar12 == '\x01') {
        FUN_00005c8c(param_1);
      }
    }
    else {
      FUN_00005d88(param_1);
    }
    goto switchD_000060ba_caseD_4;
  }
  pcVar10 = (char *)*puVar12;
  if (0xe < (byte)pcVar10[2] - 1) goto switchD_000060ba_caseD_7;
  cVar1 = *(char *)(iVar9 + 0x15);
  switch(pcVar10[2]) {
  case '\x01':
    if (*(char *)(iVar9 + 0x175) != '\0') {
LAB_000060e6:
      FUN_00003140(param_1);
      goto switchD_000060ba_caseD_4;
    }
    if (cVar1 != '\0') {
      FUN_00005b5c(param_1);
      goto switchD_000060ba_caseD_4;
    }
    if (param_1 < 2) {
      *(undefined1 *)(iVar9 + 0x175) = 0;
    }
    uVar8 = 0xc;
    break;
  case '\x02':
    if ((cVar1 != '\x01') || (6 < (byte)pcVar10[1])) goto switchD_000060ba_caseD_7;
LAB_000061da:
    uVar8 = 0x12;
    break;
  case '\x03':
    if ((*(char *)(iVar9 + 0x20) != '\x01') || (*(char *)(iVar9 + 0x1e) != cVar1))
    goto switchD_000060ba_caseD_4;
    if (cVar1 == '\0') {
      iVar7 = 0x110;
    }
    else {
      iVar7 = 0x10c;
    }
    if (*(uint *)(iVar9 + iVar7) >> 0x1c != 1) goto switchD_000060ba_caseD_4;
    if (*(uint *)(pcVar10 + 8) >> 0x1c == 5) {
      uVar8 = 9;
    }
    else {
      if (*(uint *)(pcVar10 + 8) >> 0x1c != 8) goto switchD_000060ba_caseD_4;
      uVar8 = 8;
    }
    break;
  case '\x04':
  case '\x05':
  case '\x06':
    goto switchD_000060ba_caseD_4;
  default:
    goto switchD_000060ba_caseD_7;
  case '\t':
    if (1 < *(byte *)(iVar9 + 0x3e)) {
      if (cVar1 == '\x01') goto LAB_000061da;
      if (*(char *)(iVar9 + 0x175) != '\0') goto LAB_000060e6;
    }
    goto switchD_000060ba_caseD_7;
  case '\n':
    if (*(byte *)(iVar9 + 0x3e) < 2) goto switchD_000060ba_caseD_7;
    if (pcVar10[1] != '\x01') goto switchD_000060ba_caseD_4;
    if (cVar1 == '\x01') {
      uVar8 = 0x28;
    }
    else if (pcVar10[0xb] == '\x05') {
      FUN_0000b9dc(param_1);
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
    if ((*(byte *)(iVar9 + 0x3e) < 2) || (cVar1 != '\0')) goto switchD_000060ba_caseD_7;
    pcVar11 = (code *)**(undefined4 **)(iVar9 + 0x60);
    uVar8 = 0x3b;
    goto LAB_00006192;
  case '\f':
    if (1 < *(byte *)(iVar9 + 0x3e)) {
      pcVar11 = (code *)**(undefined4 **)(iVar9 + 0x60);
      uVar8 = 0x3c;
      goto LAB_00006192;
    }
switchD_000060ba_caseD_7:
    FUN_000063e4(param_1);
    goto switchD_000060ba_caseD_4;
  case '\x0f':
    if (*pcVar10 == '\0') {
      *(undefined2 *)(puVar12 + 0x2c) = 0;
      *(short *)((int)puVar12 + 0xaa) = (short)DAT_00006318;
      *puVar4 = 0;
      FUN_00002db8(param_1,0x800);
      (**(code **)(*(int *)(iVar9 + 0x60) + 0x50))(param_1,pcVar10,DAT_00006324);
      FUN_000030f0(param_1,9,0x14);
      FUN_00002db8(param_1,0x100);
      *(char *)(iVar9 + 0x45) = '$';
      return;
    }
    goto switchD_000060ba_caseD_4;
  }
LAB_00006310:
  FUN_00003258(param_1,uVar8);
switchD_000060ba_caseD_4:
  if ((*(char *)(iVar9 + 0x45) == '#') && (iVar7 = FUN_0000ca50(param_1,9), iVar7 == 0)) {
    FUN_000028b8(param_1,4);
  }
  return;
}

