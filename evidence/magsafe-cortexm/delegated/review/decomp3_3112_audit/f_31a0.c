
void FUN_000031a0(int param_1,int param_2)

{
  if (param_2 == 0x23) {
    *(undefined1 *)(DAT_000031e0 + param_1 * 0xf0 + 0xa9) = 0;
  }
  *(char *)(DAT_000031e4 + param_1 * 0x1cc + 0x45) = (char)param_2;
  FUN_0000c88c(param_1,9);
  FUN_00002ce4(param_1,0x100);
  FUN_00002908(param_1,4);
  return;
}

