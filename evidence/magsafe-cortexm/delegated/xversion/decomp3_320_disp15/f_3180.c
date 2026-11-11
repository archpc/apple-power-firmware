
void FUN_00003180(int param_1)

{
  int iVar1;
  
  FUN_0000301a(param_1,0);
  iVar1 = DAT_000031b8 + param_1 * 0x1cc;
  *(undefined1 *)(iVar1 + 0x19) = 0;
  if (*(char *)(iVar1 + 0x12) == '\x01') {
    FUN_00003008(param_1);
    FUN_00002a18(param_1,1);
    return;
  }
  FUN_00006648(param_1);
  return;
}

