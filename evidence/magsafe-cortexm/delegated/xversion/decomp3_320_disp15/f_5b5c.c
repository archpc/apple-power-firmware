
void FUN_00005b5c(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_00005b9c + param_1 * 0xf0;
  *(undefined1 *)(iVar1 + 0xed) = 0;
  *(undefined1 *)(iVar1 + 0xa9) = 0;
  iVar1 = DAT_00005ba0 + param_1 * 0x1cc;
  *(undefined1 *)(iVar1 + 0x43) = 0;
  if (*(char *)(iVar1 + 0x2e) != '\x06') {
    FUN_0000301a(param_1,0);
  }
  FUN_00003258(param_1,0x16);
  return;
}

