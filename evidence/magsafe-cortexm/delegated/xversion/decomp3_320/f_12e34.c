
void FUN_00012e34(int param_1)

{
  FUN_00000b70();
  *DAT_00012e50 = param_1 << 6 | *DAT_00012e50 & 0xffffff3f;
  FUN_00000b78();
  return;
}

