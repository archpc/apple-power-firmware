
bool FUN_00006c1c(int param_1)

{
  if ((*(uint *)(DAT_00006c50 + param_1 * 0x1cc + 0x48) & DAT_00006c4c) != 0) {
    FUN_00006c58(param_1,0x10);
    return true;
  }
  return *(int *)(DAT_00006c54 + param_1 * 0x88 + 0x80) != 0;
}

