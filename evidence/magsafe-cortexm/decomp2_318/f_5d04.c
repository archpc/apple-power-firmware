
void FUN_00005d04(int param_1,uint param_2,uint param_3,int param_4)

{
  int unaff_r5;
  char *unaff_r6;
  
  if ((param_3 & param_2) != param_1 * 0x20000) {
    return;
  }
  switch(*(undefined2 *)(unaff_r5 + 8)) {
  case 1:
    if (((*unaff_r6 != '\0') && ((int)((uint)(byte)unaff_r6[0x9e] << 0x18) < 0)) &&
       ((int)((uint)(byte)unaff_r6[0x106] << 0x19) < 0)) {
      *(char *)(param_4 + 0xee) = (char)param_1;
LAB_00005ea8:
      FUN_000031a0();
      return;
    }
    break;
  case 2:
    if (*unaff_r6 != '\x01') goto LAB_00005ea8;
    break;
  case 3:
    if (unaff_r6[0x15] == '\x01') {
      if (unaff_r6[0x175] == '\0') {
        return;
      }
      FUN_00006388();
      return;
    }
    break;
  case 4:
    if (unaff_r6[0x15] == '\0') {
      return;
    }
  }
  FUN_000062f4();
  return;
}

