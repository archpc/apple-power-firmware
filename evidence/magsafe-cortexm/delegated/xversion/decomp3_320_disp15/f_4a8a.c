
void FUN_00004a8a(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = DAT_00004b6c;
  switch(param_2) {
  case 2:
    *(undefined1 *)(DAT_00004b6c + 0x15) = 1;
    iVar4 = *(int *)(iVar1 + 0x60);
    FUN_00007d9c(0,*(undefined1 *)(iVar1 + 0x1a),param_3,param_4,param_4,0);
    FUN_00007d34(0,*(undefined1 *)(iVar1 + 0x1b));
    *(undefined1 *)(iVar1 + 0x2d) = 8;
    iVar2 = iVar1 + (uint)*(byte *)(iVar1 + 0x1a);
    *(undefined1 *)(iVar2 + 0x38) = 1;
    *(undefined1 *)(iVar2 + 0x3a) = 1;
    *(undefined1 *)(iVar1 + 0x1f) = 1;
    FUN_00006de4(0);
    FUN_00000b80(&DAT_000012c0);
    *(undefined1 *)(iVar1 + 0x19) = 0;
    (**(code **)(iVar4 + 4))(0,DAT_00004b68);
    (**(code **)(iVar4 + 0xc))(0,DAT_00004b70);
    if (*(char *)(iVar1 + 0x175) == '\0') {
      uVar3 = 0x113;
    }
    else {
      uVar3 = 700;
    }
    FUN_000030f0(0,9,uVar3);
    return;
  case 3:
    FUN_00006468(0);
    *(undefined1 *)(DAT_00004b74 + 0xa6) = 1;
    FUN_00003258(0,0xe);
    return;
  case 4:
  case 5:
  case 6:
  case 8:
    FUN_00003180(0);
    if (param_2 != 7) {
      return;
    }
switchD_00004aa2_caseD_7:
    FUN_0000ca08(0,9);
    FUN_00002db8(0,0x100);
    FUN_00006ec8(0,0,6);
    return;
  case 7:
    goto switchD_00004aa2_caseD_7;
  default:
    return;
  }
}

