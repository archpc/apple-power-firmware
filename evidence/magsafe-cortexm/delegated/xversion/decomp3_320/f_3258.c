
void FUN_00003258(int param_1,int param_2)

{
  if (param_2 == 0x23) {
    *(undefined1 *)(DAT_00003298 + param_1 * 0xf0 + 0xa9) = 0;
  }
  *(char *)(DAT_0000329c + param_1 * 0x1cc + 0x45) = (char)param_2;
  FUN_0000ca08(param_1,9);
  FUN_00002db8(param_1,0x100);
  FUN_000028b8(param_1,4);
  return;
}

