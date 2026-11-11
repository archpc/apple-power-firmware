
void FUN_00003140(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_0000317c + param_1 * 0x1cc;
  *(undefined1 *)(iVar1 + 0x20) = 0;
  FUN_0000cac8(param_1,0,0xe);
  if (*(char *)(iVar1 + 0x2e) != '\x05') {
    FUN_0000301a(param_1,0);
  }
  FUN_00003258(param_1,1);
  *(undefined4 *)(iVar1 + 0x48) = 4;
  return;
}

