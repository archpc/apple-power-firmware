
void FUN_00001f30(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_00001f60 + param_1 * 0x1cc;
  if (*(char *)(iVar1 + 0x32) != '\0') {
    FUN_00007d68(param_1);
    FUN_00003008(param_1);
    *(undefined1 *)(iVar1 + 0x33) = 1;
    *(undefined1 *)(iVar1 + 0x31) = 0;
  }
  return;
}

