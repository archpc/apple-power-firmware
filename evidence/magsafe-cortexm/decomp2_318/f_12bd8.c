
void FUN_00012bd8(int param_1)

{
  FUN_00000b50();
  *DAT_00012bf4 = param_1 << 6 | *DAT_00012bf4 & 0xffffff3f;
  FUN_00000b58();
  return;
}

