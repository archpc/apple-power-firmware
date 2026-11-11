
void FUN_00012b9c(uint param_1)

{
  uint uVar1;
  
  do {
    if (*DAT_00012bc0 << 0x14 < 0) {
      uVar1 = 0x10;
    }
    else {
      uVar1 = 8;
    }
  } while (uVar1 == (*DAT_00012bbc & 0x1f));
  DAT_00012bbc[0xe] = param_1;
  return;
}

