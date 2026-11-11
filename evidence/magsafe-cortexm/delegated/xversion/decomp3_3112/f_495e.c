
void switchD_00004468::caseD_4(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = iRam00004a40;
  switch(param_2) {
  case 2:
    iVar4 = *(int *)(iRam00004a40 + 0x60);
    *(undefined1 *)(iRam00004a40 + 0x15) = 1;
    FUN_00007c4c(0,*(undefined1 *)(iVar1 + 0x1a),param_3,param_4,param_4);
    FUN_00007be4(0,*(undefined1 *)(iVar1 + 0x1b));
    iVar2 = iVar1 + (uint)*(byte *)(iVar1 + 0x1a);
    *(undefined1 *)(iVar2 + 0x38) = 1;
    *(undefined1 *)(iVar2 + 0x3a) = 1;
    *(undefined1 *)(iVar1 + 0x2d) = 8;
    *(undefined1 *)(iVar1 + 0x1f) = 1;
    FUN_00006d00(0);
    FUN_00000b60(0x12c0);
    *(undefined1 *)(iVar1 + 0x19) = 0;
    (**(code **)(iVar4 + 4))(0,DAT_00004a3c);
    (**(code **)(iVar4 + 0xc))(0,DAT_00004a44);
    if (*(char *)(iVar1 + 0x175) == '\0') {
      uVar3 = 0x113;
    }
    else {
      uVar3 = 700;
    }
    FUN_00003038(0,9,uVar3);
    return;
  case 3:
    FUN_000063e8(0);
    *(undefined1 *)(iRam00004a48 + 0xa6) = 1;
    FUN_000031a0(0,0xe);
    return;
  case 4:
  case 5:
  case 6:
  case 8:
    FUN_000030c8(0);
    if (param_2 != 7) {
      return;
    }
code_r0x0000498a:
    FUN_0000c88c(0,9);
    FUN_00002ce4(0,0x100);
    FUN_00006de4(0,0,6);
    return;
  case 7:
    goto code_r0x0000498a;
  default:
    return;
  }
}

