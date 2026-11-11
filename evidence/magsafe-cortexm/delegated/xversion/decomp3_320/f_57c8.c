
void FUN_000057c8(int param_1)

{
  uint unaff_r4;
  char in_ZR;
  
  if (in_ZR != '\0') {
    if (unaff_r4 < 2) {
      *(undefined1 *)(DAT_000058f8 + unaff_r4 * 0x1cc + 0x175) = 1;
    }
    FUN_0000ca08();
    (*(code *)**(undefined4 **)(DAT_000058f8 + unaff_r4 * 0x1cc + 0x60))();
    FUN_00003258();
    return;
  }
  if (param_1 != 5) {
    return;
  }
  if (unaff_r4 < 2) {
    *(undefined1 *)(DAT_000058f8 + unaff_r4 * 0x1cc + 0x175) = 0;
  }
  FUN_00005b5c();
  return;
}

