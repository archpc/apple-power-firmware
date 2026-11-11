
void switchD_00004468::caseD_6(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  switch(param_2) {
  case 2:
    iVar3 = iRam00004a40 + param_1 * 0x1cc;
    iVar4 = *(int *)(iVar3 + 0x60);
    *(undefined1 *)(iVar3 + 0x15) = 1;
    FUN_00007c4c(param_1,*(undefined1 *)(iVar3 + 0x1a));
    FUN_00007be4(param_1,*(undefined1 *)(iVar3 + 0x1b));
    iVar1 = iVar3 + (uint)*(byte *)(iVar3 + 0x1a);
    *(undefined1 *)(iVar1 + 0x38) = 1;
    *(undefined1 *)(iVar1 + 0x3a) = 1;
    *(undefined1 *)(iVar3 + 0x2d) = 8;
    *(undefined1 *)(iVar3 + 0x1f) = 1;
    FUN_00006d00(param_1);
    FUN_00000b60(0x12c0);
    *(undefined1 *)(iVar3 + 0x19) = 0;
    (**(code **)(iVar4 + 4))(param_1,DAT_00004a3c);
    (**(code **)(iVar4 + 0xc))(param_1,DAT_00004a44);
    if (*(char *)(iVar3 + 0x175) == '\0') {
      uVar2 = 0x113;
    }
    else {
      uVar2 = 700;
    }
    FUN_00003038(param_1,9,uVar2);
    return;
  case 3:
    FUN_000063e8(param_1);
    *(undefined1 *)(iRam00004a48 + param_1 * 0xf0 + 0xa6) = 1;
    FUN_000031a0(param_1,0xe);
    return;
  case 4:
  case 5:
  case 6:
  case 8:
    FUN_000030c8(param_1);
    if (param_2 != 7) {
      return;
    }
code_r0x0000498a:
    FUN_0000c88c(param_1,9);
    FUN_00002ce4(param_1,0x100);
    FUN_00006de4(param_1,0,6);
    return;
  case 7:
    goto code_r0x0000498a;
  default:
    return;
  }
}

