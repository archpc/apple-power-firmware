
bool FUN_00006b34(int param_1)

{
  if ((*(uint *)(DAT_00006b68 + param_1 * 0x1cc + 0x48) & DAT_00006b64) != 0) {
    FUN_00006b70(param_1,0x10);
    return true;
  }
  return *(int *)(DAT_00006b6c + param_1 * 0x88 + 0x80) != 0;
}

