
void FUN_00004b78(uint param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  uint *unaff_r5;
  int unaff_r7;
  
  uVar1 = DAT_00004f28;
  if (param_2 - 2U < 8) {
    switch(param_2) {
    case 2:
      FUN_00003258();
      break;
    default:
      FUN_00005b5c(DAT_00004f28,(&switchD_00004b92::switchdataD_00004b94)[param_2 - 2U],DAT_00004f24
                  );
      if (DAT_000055e4 + 1U <= *unaff_r5) {
        FUN_00007260(uVar1,0,10,1);
        return;
      }
      return;
    case 6:
      unaff_r5[0x19] = param_1;
      break;
    case 8:
      *(undefined1 *)(param_4 + unaff_r7 * DAT_00004f20 + 0xa9) = 2;
    case 9:
      FUN_00006328();
    }
  }
  return;
}

