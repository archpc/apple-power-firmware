
void FUN_00006648(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_00006698 + param_1 * 0x1cc;
  if (*(char *)(iVar1 + 0x15) == '\x01') {
    FUN_00007a14(param_1,*(undefined1 *)(iVar1 + 2));
    FUN_00008c00(param_1,1);
  }
  else {
    *(undefined1 *)(iVar1 + 0x45) = 0xb;
  }
  FUN_0000cac8(param_1,0,0xe);
  *(undefined4 *)(iVar1 + 0x48) = 0;
  *(undefined1 *)(iVar1 + 0x22) = 1;
  (*(code *)**(undefined4 **)(iVar1 + 0x60))(param_1,0x15,0);
  return;
}

