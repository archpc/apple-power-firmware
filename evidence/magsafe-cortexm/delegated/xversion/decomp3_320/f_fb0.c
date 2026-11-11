
void FUN_00000fb0(int param_1)

{
  if (*(char *)(param_1 + 2) != '\0') {
    return;
  }
  *(undefined1 *)(param_1 + 2) = 1;
  FUN_00001132(DAT_00000fd0 + 0x28,*(undefined1 *)(param_1 + 1),DAT_00000fd4);
  return;
}

