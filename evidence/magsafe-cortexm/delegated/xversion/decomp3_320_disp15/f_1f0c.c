
void FUN_00001f0c(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0x13) != '\0') {
    return;
  }
  *(undefined1 *)(param_2 + 0x31) = 1;
  *(undefined1 *)(param_2 + 0x33) = 0;
  *(undefined1 *)(param_2 + 0x10) = 2;
  FUN_00007c80();
  return;
}

