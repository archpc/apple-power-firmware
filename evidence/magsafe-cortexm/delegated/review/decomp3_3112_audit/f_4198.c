
void switchD_00003ba4::caseD_7(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  iVar2 = iRam00004284;
  iVar1 = DAT_00004280;
  if (6 < param_2 - 2U) {
    return;
  }
  puVar5 = *(undefined4 **)(DAT_00004280 + 0x60);
  switch(param_2) {
  case 2:
    (*(code *)puVar5[1])(0,*(undefined2 *)(iRam00004284 + 0xc6));
    (*(code *)puVar5[3])(0,uRam00004288);
    if (*(char *)(iVar1 + 0x175) == '\0') {
      uVar4 = 600;
    }
    else {
      uVar4 = 0x44c;
    }
    uVar3 = 9;
    break;
  case 3:
    puVar5 = (undefined4 *)(DAT_00004280 + 0x104);
    *(undefined4 *)(DAT_00004280 + 0x10c) = *puVar5;
    *(undefined4 *)(iVar1 + 0x108) = *puVar5;
    func_0x000064c4(0);
    if (*(char *)(iVar1 + 0x35) != '\0') {
      return;
    }
    FUN_000078bc(0,1);
    return;
  default:
    FUN_00003088(0);
    return;
  case 7:
    FUN_0000c88c(0,9);
    FUN_00002ce4(0,0x100);
    FUN_00006de4(0,0,6);
    uVar4 = 900;
    uVar3 = 0xd;
    break;
  case 8:
    *(undefined4 *)(iRam00004284 + 0xd8) = *(undefined4 *)(DAT_00004280 + 0x104);
    *(undefined1 *)(iVar2 + 0xdc) = 0x18;
    (*(code *)*puVar5)(0,0x16);
    FUN_000030c8(0);
    return;
  }
  FUN_00003038(0,uVar3,uVar4);
  return;
}

