
void switchD_00003ba4::caseD_8(undefined4 param_1,int param_2)

{
  int iVar1;
  int unaff_r4;
  int iVar2;
  undefined4 *puVar3;
  
  if (6 < param_2 - 2U) {
    return;
  }
  iVar2 = DAT_00004280 + unaff_r4 * 0x1cc;
  puVar3 = *(undefined4 **)(iVar2 + 0x60);
  switch(param_2) {
  case 2:
    (*(code *)puVar3[1])();
    (*(code *)puVar3[3])();
    break;
  case 3:
    *(undefined4 *)(iVar2 + 0x10c) = *(undefined4 *)(iVar2 + 0x104);
    *(undefined4 *)(iVar2 + 0x108) = *(undefined4 *)(iVar2 + 0x104);
    func_0x000064c4();
    if (*(char *)(iVar2 + 0x35) != '\0') {
      return;
    }
    FUN_000078bc();
    return;
  default:
    FUN_00003088();
    return;
  case 7:
    FUN_0000c838();
    FUN_00002ce4();
    FUN_00006de4();
    break;
  case 8:
    iVar1 = iRam00004284 + unaff_r4 * 0xf0;
    *(undefined4 *)(iVar1 + 0xd8) = *(undefined4 *)(iVar2 + 0x104);
    *(undefined1 *)(iVar1 + 0xdc) = 0x18;
    (*(code *)*puVar3)();
    FUN_000030c8();
    return;
  }
  FUN_00003038();
  return;
}

