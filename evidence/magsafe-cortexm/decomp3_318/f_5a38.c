
void FUN_00005a38(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_00005a78 + param_1 * 0xf0;
  *(undefined1 *)(iVar1 + 0xed) = 0;
  *(undefined1 *)(iVar1 + 0xa9) = 0;
  iVar1 = DAT_00005a7c + param_1 * 0x1cc;
  *(undefined1 *)(iVar1 + 0x43) = 0;
  if (*(char *)(iVar1 + 0x2e) != '\x06') {
    FUN_00002f62(param_1,0);
  }
  FUN_000031a0(param_1,0x16);
  return;
}

