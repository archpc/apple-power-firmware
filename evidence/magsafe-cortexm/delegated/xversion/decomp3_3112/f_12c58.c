
void FUN_00012c58(int param_1)

{
  FUN_00000b50();
  *DAT_00012c74 = param_1 << 6 | *DAT_00012c74 & 0xffffff3f;
  FUN_00000b58();
  return;
}

