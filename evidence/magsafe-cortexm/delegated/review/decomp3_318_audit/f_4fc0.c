
void FUN_00004fc0(int param_1,int param_2)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  undefined4 uVar7;
  char cVar8;
  char cVar9;
  int *piVar10;
  int *piVar11;
  char local_18 [4];
  
  piVar11 = (int *)(DAT_00005308 + param_1 * 0xf0);
  cVar8 = (char)piVar11[0x2b];
  cVar1 = *(char *)((int)piVar11 + 0xab);
  cVar6 = *(char *)((int)piVar11 + 0xaa);
  uVar2 = *(undefined2 *)((int)piVar11 + 0xae);
  piVar10 = (int *)piVar11[0x2d];
  cVar9 = *(char *)((int)piVar11 + 0xad);
  iVar3 = DAT_0000530c + param_1 * 0x1cc;
  local_18[0] = cVar6;
  if ((param_2 == 2) && (*(char *)(iVar3 + 0x10) != '\x02')) {
    if ((cVar1 == '\x03') || ((byte)(cVar6 - 1U) < 2)) {
      if (*(byte *)(iVar3 + 0x3e) < 2) {
        if (*(char *)(iVar3 + 0x14) != '\x01') {
LAB_00005122:
          uVar7 = 1;
          goto LAB_00005124;
        }
      }
      else if ((*(char *)(iVar3 + 0x28) == '\0') ||
              (iVar3 = (**(code **)(*(int *)(iVar3 + 0x60) + 0x1c))(param_1), iVar3 == 0))
      goto LAB_00005122;
    }
LAB_0000501c:
    if (cVar1 == '\x02') {
      FUN_00007172(param_1,cVar6,cVar8,uVar2,piVar10);
      return;
    }
    if (cVar1 != '\x01') {
      if (cVar1 != '\0') {
        return;
      }
      FUN_00006de4(param_1,cVar6,cVar8);
      return;
    }
LAB_000050fc:
    FUN_00007160(param_1,cVar6,cVar8,cVar9,piVar10);
    return;
  }
  switch(param_2) {
  case 2:
    goto LAB_0000501c;
  case 3:
    if (cVar1 == '\x03') {
      (*(code *)**(undefined4 **)(iVar3 + 0x60))(param_1,0x14,0);
    }
    if ((((byte)(cVar6 - 1U) < 2) && (cVar1 == '\0')) && (cVar8 == '\r')) {
      (*(code *)**(undefined4 **)(iVar3 + 0x60))(param_1,0x13,local_18);
    }
    FUN_00002f62(param_1,3);
    if ((short)piVar11[0x2c] != 0) {
      FUN_00003038(param_1,9);
      return;
    }
    *(undefined1 *)(iVar3 + 0x2f) = 0;
    *(undefined4 *)(iVar3 + 100) = 0;
    break;
  case 4:
    if ((*(char *)((int)piVar11 + 0xa9) == '\x01') || (*(char *)((int)piVar11 + 0xed) != '\0')) {
LAB_000052ba:
      FUN_00005a38(param_1);
      return;
    }
    uVar7 = 0;
LAB_00005124:
    FUN_00002f62(param_1,uVar7);
    break;
  case 5:
    if (cVar6 == '\0') goto LAB_000052ba;
    goto LAB_00005122;
  case 6:
    uVar7 = *(undefined4 *)(DAT_00005308 + param_1 * 0xf0);
    iVar4 = FUN_00002fd4(uVar7,cVar6,(char)piVar11[0x2e],piVar11[0x2f],(short)piVar11[0x30]);
    if ((iVar4 == 0) && (iVar4 = FUN_00002fd4(uVar7,cVar6,0,DAT_00005304,0), iVar4 == 0)) {
      FUN_00002f62(param_1,0);
      if (*(char *)((int)piVar11 + 0xa9) != '\x02') {
        FUN_00005ed0(param_1);
        return;
      }
      goto LAB_000052ba;
    }
    if (*(char *)(iVar3 + 0x15) == '\0') {
      uVar7 = 0xc;
      if ((*(char *)(iVar3 + 0x2e) != '\x01') && (*(char *)(iVar3 + 0x2e) != '\x04'))
      goto LAB_0000516e;
    }
    else {
LAB_0000516e:
      uVar7 = 0x23;
    }
    FUN_000031a0(param_1,uVar7);
    FUN_00002f6c(param_1,4,*piVar11);
    if (-1 < (int)((uint)*(byte *)(*piVar11 + 5) << 0x18)) {
      return;
    }
    FUN_00002ce4(param_1,4);
    FUN_00005c68(param_1);
    uVar5 = *(uint *)(*piVar11 + 4);
    if (((int)uVar5 < 0) && (((uVar5 & 0x7fffffff) >> 0x1b) * 0x1a + 0x1a < (uVar5 >> 0x10 & 0x1ff))
       ) {
      return;
    }
    uVar7 = 4;
    goto LAB_00005236;
  default:
    goto switchD_0000504a_caseD_7;
  case 8:
    FUN_00002f62(param_1,2);
    if (cVar8 == '\x0f') {
      uVar7 = 0x11;
    }
    else {
      uVar7 = 0x10;
    }
    if (cVar1 != '\x01') {
      uVar7 = 0x10;
    }
    (*(code *)**(undefined4 **)(iVar3 + 0x60))(param_1,uVar7,0);
    if ((((byte)(cVar6 - 1U) < 2) && (cVar1 == '\0')) && (cVar8 == '\r')) {
      FUN_000062a8(param_1,3,0,0,0,0,0,0,0,0,0);
      return;
    }
    break;
  case 0xb:
    FUN_0000c838(param_1,9);
    FUN_00002ce4(param_1,0x100);
    cVar8 = *(char *)((int)piVar11 + 0xa1);
    if (cVar8 == '\0') {
      cVar9 = (char)piVar11[0x28];
      if (cVar9 != '\0') {
        piVar10 = piVar11 + 0x21;
        if ((cVar6 == '\x01') && (*(char *)(iVar3 + 0x10) == '\x02')) {
          cVar6 = *(char *)((int)piVar11 + 0xaa);
        }
        else {
          cVar6 = '\0';
        }
        cVar8 = '\x0f';
        goto LAB_000050fc;
      }
    }
    else {
      if (cVar8 == '\x03') {
        FUN_000062f4(param_1,0x10);
        return;
      }
      if ((cVar8 != '\x01') && ((1 < *(byte *)(iVar3 + 0x3e) || (*DAT_00005310 == '\x01')))) {
        *(undefined1 *)(iVar3 + 0x43) = 2;
        FUN_00003038(param_1,9,0x1b);
        *(undefined1 *)(iVar3 + 0x45) = 0x23;
        return;
      }
    }
    break;
  case 0xe:
    FUN_0000c838(param_1,9);
    FUN_00002ce4(param_1,0x100);
    *(undefined1 *)(iVar3 + 0x45) = 0x23;
    uVar7 = 0x4000;
LAB_00005236:
    FUN_00002908(param_1,uVar7);
    goto switchD_0000504a_caseD_7;
  }
  FUN_000031a0(param_1,0x23);
switchD_0000504a_caseD_7:
  return;
}

