
void FUN_0000aa10(undefined **param_1,int param_2,undefined **param_3)

{
  byte bVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  undefined **ppuVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined1 uVar10;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_1c [2];
  
  iVar2 = DAT_0000af80;
  iVar8 = DAT_0000add4;
  iVar4 = DAT_0000add0;
  if (param_2 - 9U < 0xe) {
    ppuVar5 = &PTR_FUN_0000aa2c;
    puVar3 = (&PTR_FUN_0000aa2c)[param_2 - 9U];
    switch(param_2) {
    case 9:
FUN_0000af24:
      uVar7 = 0x1c;
      goto LAB_0000af3a;
    case 10:
    case 0x12:
      goto FUN_0000aee4;
    default:
      FUN_0000a554(0);
      FUN_00006828();
      *(undefined1 *)((int)param_1 + 0x55) = local_28;
      *(undefined4 *)(iVar4 + 0x5c) = local_24;
      return;
    case 0xc:
FUN_0000af5c:
      puVar9 = local_1c;
      uVar10 = 1;
LAB_0000ad50:
      FUN_00006854(param_1,ppuVar5,puVar9,uVar10);
      return;
    case 0x13:
      return;
    case 0x16:
      if (puVar3 != (undefined *)0x0) {
        param_1[0x18] = (undefined *)&PTR_FUN_0000aa2c;
        return;
      }
      (*(code *)&PTR_FUN_0000aa2c)(1);
      param_1[0x18] = (undefined *)0x0;
      return;
    }
  }
  if (param_2 != 0x41) {
    if (param_2 == 3) {
      FUN_00009df8();
      FUN_00001fa0();
      FUN_00007be4(1,0);
      FUN_00007be4(1,1);
      if (*(char *)(DAT_0000af80 + 0x14) == '\0') {
        return;
      }
      *(undefined1 *)(DAT_0000af80 + 0x14) = 0;
      FUN_0000955c();
      FUN_00001178(DAT_0000af7c,0,DAT_0000af84,0);
      return;
    }
    if (param_2 == 0x28) {
      if (param_1 != (undefined **)0x1) {
        return;
      }
      if (*(char *)(DAT_0000af80 + 0x14) == '\0') {
        FUN_0000d984(0);
      }
      *(undefined1 *)(iVar2 + 0x14) = 1;
      FUN_00009e74();
      *(undefined1 *)(DAT_0000af88 + 0x34) = 2;
      iVar4 = DAT_0000af68 + 6;
    }
    else {
      if (param_2 == 0x3d) {
        if (param_1 != (undefined **)0x0) {
          return;
        }
        FUN_000031a0(1,0x29);
        return;
      }
      if (param_2 != 2) {
        return;
      }
      if (param_1 != (undefined **)0x0) {
        return;
      }
      FUN_00001178(DAT_0000ade8,0,DAT_0000adec,0);
      iVar4 = DAT_0000ade4;
    }
    FUN_0000a4a4(iVar4);
    return;
  }
  if (*(char *)param_3 != '\0') {
    return;
  }
  FUN_000001a2(DAT_0000add0 + 0x28,0,0x2c);
  *(undefined1 *)(iVar4 + 0x34) = 0x1e;
  ppuVar5 = (undefined **)(uint)(param_1 != (undefined **)0x1);
  if (*(char *)(iVar8 + (int)param_1 * 0x1cc + 0x20) == '\0') goto switchD_0000ad8e_caseD_15;
  uVar6 = (uint)*(byte *)((int)param_3 + 2);
  if ((int)((uint)*(byte *)((int)param_3 + 5) << 0x18) < 0) {
    if ((uVar6 < 7) && ((1 << uVar6 & 0x58U) != 0)) {
      if (*(char *)(iVar8 + (int)ppuVar5 * 0x1cc + 0x20) != '\0') {
        FUN_00000170(iVar4 + 0x38,param_3 + 2,(uint)*(byte *)((int)param_3 + 1) << 2);
        *(char *)(iVar4 + 0x28) = *(char *)param_3;
        bVar1 = *(byte *)(param_3 + 1);
        *(undefined1 *)(iVar4 + 0x34) = 0x1e;
        *(int *)(iVar4 + 0x30) = iVar4 + 0x38;
        *(char *)(iVar4 + 0x2c) = *(char *)((int)param_3 + 1);
        *(byte *)(iVar4 + 0x29) = bVar1 & 0x1f;
        uVar7 = 0xd;
        goto LAB_0000af3a;
      }
    }
    else {
      FUN_00002938();
    }
    goto switchD_0000ad8e_caseD_15;
  }
  switch(uVar6) {
  case 8:
    if (*(char *)(iVar8 + (int)ppuVar5 * 0x1cc + 0x20) != '\0') {
      uVar7 = 3;
      goto LAB_0000af3a;
    }
    iVar8 = iVar8 + (int)param_1 * 0x1cc;
    uVar10 = *(undefined1 *)(iVar8 + 0xb);
    puVar9 = (undefined4 *)(iVar8 + 0xd0);
    ppuVar5 = (undefined **)0x4;
    goto LAB_0000ad50;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x13:
  case 0x14:
    goto switchD_0000ad8e_caseD_9;
  case 0x11:
    param_3 = &Reserved2;
    puVar3 = (undefined *)((int)ppuVar5 * 0x1cc);
FUN_0000aee4:
    if (*(char *)((int)param_3 + (int)(puVar3 + iVar8)) != '\0') {
      uVar7 = 0xe;
LAB_0000af3a:
      FUN_0000b790(param_1,ppuVar5,uVar7);
      return;
    }
    break;
  case 0x12:
    if (*(char *)(iVar8 + (int)ppuVar5 * 0x1cc + 0x20) != '\0') {
      uVar7 = 0xf;
      goto LAB_0000af3a;
    }
    break;
  case 0x15:
    break;
  case 0x16:
    if (*(char *)(iVar8 + (int)ppuVar5 * 0x1cc + 0x20) == '\0') {
      FUN_00006834(param_1,0xf,DAT_0000af8c,0x19);
      return;
    }
    uVar7 = 0x16;
    goto LAB_0000af3a;
  case 0x17:
    if (*(char *)(iVar8 + (int)ppuVar5 * 0x1cc + 0x20) != '\0') goto FUN_0000af24;
    break;
  case 0x18:
    if (*(char *)(iVar8 + (int)ppuVar5 * 0x1cc + 0x20) != '\0') {
      uVar7 = 0x1d;
      goto LAB_0000af3a;
    }
    local_1c[0] = DAT_0000af78;
    ppuVar5 = (undefined **)0xc;
    goto FUN_0000af5c;
  default:
    if (uVar6 == 2) {
      if (*(char *)(iVar8 + (int)ppuVar5 * 0x1cc + 0x20) != '\0') {
        uVar7 = 2;
        goto LAB_0000af3a;
      }
      break;
    }
    goto switchD_0000ad8e_caseD_9;
  }
switchD_0000ad8e_caseD_15:
  ppuVar5 = param_1;
LAB_0000ae1e:
  FUN_00006364(ppuVar5);
  return;
switchD_0000ad8e_caseD_9:
  FUN_00002938();
  goto LAB_0000ae1e;
}

