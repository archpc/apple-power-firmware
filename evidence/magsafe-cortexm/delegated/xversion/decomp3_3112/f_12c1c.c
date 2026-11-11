
void FUN_00012c1c(uint param_1)

{
  uint uVar1;
  
  do {
    if (*DAT_00012c40 << 0x14 < 0) {
      uVar1 = 0x10;
    }
    else {
      uVar1 = 8;
    }
  } while (uVar1 == (*DAT_00012c3c & 0x1f));
  DAT_00012c3c[0xe] = param_1;
  return;
}

