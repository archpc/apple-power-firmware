
void FUN_00004a92(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  switch(param_2) {
  case 2:
    iVar3 = DAT_00004b6c + param_1 * 0x1cc;
    *(undefined1 *)(iVar3 + 0x15) = 1;
    iVar4 = *(int *)(iVar3 + 0x60);
    FUN_00007d9c(param_1,*(undefined1 *)(iVar3 + 0x1a));
    FUN_00007d34(param_1,*(undefined1 *)(iVar3 + 0x1b));
    *(undefined1 *)(iVar3 + 0x2d) = 8;
    iVar1 = iVar3 + (uint)*(byte *)(iVar3 + 0x1a);
    *(undefined1 *)(iVar1 + 0x38) = 1;
    *(undefined1 *)(iVar1 + 0x3a) = 1;
    *(undefined1 *)(iVar3 + 0x1f) = 1;
    FUN_00006de4(param_1);
    FUN_00000b80(&DAT_000012c0);
    *(undefined1 *)(iVar3 + 0x19) = 0;
    (**(code **)(iVar4 + 4))(param_1,DAT_00004b68);
    (**(code **)(iVar4 + 0xc))(param_1,DAT_00004b70);
    if (*(char *)(iVar3 + 0x175) == '\0') {
      uVar2 = 0x113;
    }
    else {
      uVar2 = 700;
    }
    FUN_000030f0(param_1,9,uVar2);
    return;
  case 3:
    FUN_00006468(param_1);
    *(undefined1 *)(DAT_00004b74 + param_1 * 0xf0 + 0xa6) = 1;
    FUN_00003258(param_1,0xe);
    return;
  case 4:
  case 5:
  case 6:
  case 8:
    FUN_00003180(param_1);
    if (param_2 != 7) {
      return;
    }
switchD_00004aa2_caseD_7:
    FUN_0000ca08(param_1,9);
    FUN_00002db8(param_1,0x100);
    FUN_00006ec8(param_1,0,6);
    return;
  case 7:
    goto switchD_00004aa2_caseD_7;
  default:
    return;
  }
}

