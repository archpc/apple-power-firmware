
/* WARNING: Removing unreachable block (ram,0x0000496e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000444e(undefined4 param_1,int param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  undefined **ppuVar2;
  int unaff_r5;
  
  if (6 < param_2 - 2U) {
    return;
  }
  ppuVar2 = &switchD_00004468::switchdataD_0000446c;
  switch(param_2) {
  case 2:
    if ((&switchD_00004468::switchdataD_0000446c)[param_2 - 2U][switchD_00004468::caseD_4 + 0xe3] ==
        '\x13') {
      param_3 = 10;
      ppuVar2 = DAT_00004954;
    }
    else {
      param_3 = 0;
      ppuVar2 = DAT_00004958;
    }
    param_4 = *(code **)(unaff_r5 + 0x20);
  case 3:
    iVar1 = (*param_4)(0,ppuVar2,param_3);
    if (iVar1 != 0) {
      iVar1 = FUN_0000c880(0,9);
      if (iVar1 != 0) {
        FUN_00002908(0,0x80);
      }
      return;
    }
    (**(code **)(unaff_r5 + 0x28))(0);
    FUN_000031a0(0,0x20);
    return;
  case 4:
  case 5:
  case 6:
    break;
  case 8:
    FUN_000030c8(0,&switchD_00004468::switchdataD_0000446c,param_3,
                 (&switchD_00004468::switchdataD_0000446c)[param_2 - 2U]);
    if (unaff_r5 != 7) {
      return;
    }
    FUN_0000c838(0,9);
    FUN_00002ce4(0,0x100);
    ppuVar2 = (undefined **)0x0;
  case 7:
    FUN_00006de4(0,ppuVar2,6);
  }
  return;
}

