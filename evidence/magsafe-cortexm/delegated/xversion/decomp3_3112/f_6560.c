
void FUN_00006560(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_000065b0 + param_1 * 0x1cc;
  if (*(char *)(iVar1 + 0x15) == '\x01') {
    FUN_000078bc(param_1,*(undefined1 *)(iVar1 + 2));
    FUN_00008ab0(param_1,1);
    FUN_0000658c();
    return;
  }
  *(undefined1 *)(iVar1 + 0x45) = 0xb;
  FUN_0000c93c(param_1,0,0xe);
  *(undefined4 *)(iVar1 + 0x48) = 0;
  *(undefined1 *)(iVar1 + 0x22) = 1;
  (*(code *)**(undefined4 **)(iVar1 + 0x60))(param_1,0x15,0);
  return;
}

