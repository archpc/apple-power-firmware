
void FUN_00005dd4(undefined1 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int unaff_r5;
  char *unaff_r7;
  
  switch(*(undefined2 *)(unaff_r5 + 8)) {
  case 1:
    if (((*unaff_r7 != '\0') && ((int)((uint)(byte)unaff_r7[0x9e] << 0x18) < 0)) &&
       ((int)((uint)(byte)unaff_r7[0x106] << 0x19) < 0)) {
      *(undefined1 *)(param_4 + 0xee) = param_1;
LAB_00005fbc:
      FUN_00003258();
      return;
    }
    break;
  case 2:
    if (*unaff_r7 != '\x01') goto LAB_00005fbc;
    break;
  case 3:
    if (unaff_r7[0x15] == '\x01') {
      if (unaff_r7[0x175] == '\0') {
        return;
      }
      FUN_00006408();
      return;
    }
    break;
  case 4:
    if (unaff_r7[0x15] == '\0') {
      return;
    }
  }
  FUN_00006374();
  return;
}

