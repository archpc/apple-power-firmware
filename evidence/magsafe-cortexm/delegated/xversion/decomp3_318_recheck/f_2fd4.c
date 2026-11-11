
undefined4 FUN_00002fd4(byte *param_1,uint param_2,int param_3,uint param_4,uint param_5)

{
  if ((param_2 != 7) && (*param_1 != param_2)) {
    return 0;
  }
  if (param_3 == 2) {
    if (-1 < (int)((uint)param_1[5] << 0x18)) {
      return 0;
    }
  }
  else {
    if (param_3 == 1) {
      if (param_1[1] == 0) {
        return 0;
      }
    }
    else {
      if (param_3 != 0) goto LAB_0000300c;
      if (param_1[1] != 0) {
        return 0;
      }
    }
    if ((int)((uint)param_1[5] << 0x18) < 0) {
      return 0;
    }
  }
LAB_0000300c:
  if (((param_4 == 0) || ((param_4 >> (*(uint *)(param_1 + 4) & 0x1f) & 1) != 0)) &&
     ((param_5 == DAT_00003034 || (param_1[1] == param_5)))) {
    return 1;
  }
  return 0;
}

