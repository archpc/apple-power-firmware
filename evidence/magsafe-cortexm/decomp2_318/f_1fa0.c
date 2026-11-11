
void FUN_00001fa0(void)

{
  int iVar1;
  
  iVar1 = DAT_00001fcc;
  if (*(char *)(DAT_00001fcc + 0x1fe) != '\0') {
    FUN_00007c18(1);
    FUN_00002f50(1);
    *(undefined1 *)(iVar1 + DAT_00001fc8) = 1;
    *(undefined1 *)(iVar1 + 0x1fd) = 0;
  }
  return;
}

