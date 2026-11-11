
void FUN_00001f68(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_00001f9c + param_1 * 0x1cc;
  if ((*(char *)(iVar1 + 0x32) != '\0') && (*(char *)(iVar1 + 0x13) == '\0')) {
    *(undefined1 *)(iVar1 + 0x31) = 1;
    *(undefined1 *)(iVar1 + 0x33) = 0;
    *(undefined1 *)(iVar1 + 0x10) = 2;
    FUN_00007b28();
    return;
  }
  return;
}

