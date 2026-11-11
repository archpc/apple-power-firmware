
void FUN_00000f84(int param_1)

{
  if (*(char *)(param_1 + 2) != '\0') {
    return;
  }
  *(undefined1 *)(param_1 + 2) = 1;
  FUN_0000110a(DAT_00000fa4 + 0x28,*(undefined1 *)(param_1 + 1),DAT_00000fa8);
  return;
}

