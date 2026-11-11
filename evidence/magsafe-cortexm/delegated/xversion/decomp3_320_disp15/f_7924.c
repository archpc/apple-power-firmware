
void FUN_00007924(int param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = DAT_00007954 + param_1 * 0x1cc;
  *(undefined1 *)(iVar1 + 0x2d) = param_2;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  FUN_0000ca08(param_1,0x10);
  FUN_00002dd0(param_1,0x20);
  FUN_00002a18(param_1,2);
  return;
}

