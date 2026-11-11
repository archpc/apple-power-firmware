
void FUN_00012df8(uint param_1)

{
  uint uVar1;
  
  do {
    if (*DAT_00012e1c << 0x14 < 0) {
      uVar1 = 0x10;
    }
    else {
      uVar1 = 8;
    }
  } while (uVar1 == (*DAT_00012e18 & 0x1f));
  DAT_00012e18[0xe] = param_1;
  return;
}

