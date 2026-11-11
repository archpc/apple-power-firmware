
/* WARNING: Removing unreachable block (ram,0x000040ca) */
/* WARNING: Removing unreachable block (ram,0x000041a6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00003b90(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int *unaff_r5;
  int unaff_r6;
  
  if (0xb < param_2 - 2U) {
    return;
  }
  switch(param_2) {
  case 2:
    if (-1 < param_3) goto LAB_00004080;
    break;
  case 3:
    if ((undefined **)(&switchD_00003ba4::switchdataD_00003ba8)[param_2 - 2U] ==
        &switchD_00003ba4::switchdataD_00003ba8) goto LAB_00004080;
    break;
  case 4:
    return;
  case 5:
    FUN_00002f62(param_1,0,param_3,param_3 << 1);
    FUN_00005a38(param_1);
    return;
  case 6:
    FUN_00006de4(param_1,&switchD_00003ba4::switchdataD_00003ba8,2);
    return;
  case 7:
  case 8:
    return;
  default:
    FUN_00007160(param_1,&switchD_00003ba4::switchdataD_00003ba8,param_3,1);
    return;
  case 0xd:
    FUN_00003088(param_1,&switchD_00003ba4::switchdataD_00003ba8,param_3,
                 (int)(&switchD_00003ba4::switchdataD_00003ba8)[param_2 - 2U] << 0xc);
    return;
  }
  FUN_00003088(param_1);
LAB_00004080:
  iVar1 = *unaff_r5;
  *(undefined4 *)(unaff_r6 + 0x104) = *(undefined4 *)(iVar1 + 8);
  (**(code **)(*(int *)(unaff_r6 + 0x60) + 0x40))
            (param_1,iVar1 + 8,*(undefined1 *)(iVar1 + 1),switchD_00003ba4::caseD_4);
  return;
}

