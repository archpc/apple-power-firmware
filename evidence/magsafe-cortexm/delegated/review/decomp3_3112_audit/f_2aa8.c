
undefined4 FUN_00002aa8(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  if (1 < param_1) {
    return 2;
  }
  uVar1 = param_2 >> 0x1c & 7;
  if (((int)param_2 < 0) || (uVar1 != 0)) {
    if ((int)param_2 < 0) {
      iVar2 = 0x177;
    }
    else {
      iVar2 = 0x29;
    }
    if (uVar1 <= *(byte *)(DAT_00002b24 + param_1 * 0x1cc + iVar2)) {
      if ((int)param_2 < 0) {
        uVar1 = param_2 >> 0x1c | 8;
      }
      if ((param_2 & 0xfffffff) >> 0x1a != 0) {
        param_2 = param_2 >> 10;
      }
      if ((param_2 & DAT_00002b20) <=
          (*(uint *)(uVar1 * 4 + DAT_00002b24 + param_1 * 0x1cc + 0x98) & DAT_00002b20)) {
        return 0;
      }
      return 0xc;
    }
  }
  return 0xc;
}

