
void FUN_000077cc(int param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = DAT_000077fc + param_1 * 0x1cc;
  *(undefined1 *)(iVar1 + 0x2d) = param_2;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  FUN_0000c88c(param_1,0x10);
  FUN_00002cfc(param_1,0x20);
  FUN_00002a48(param_1,2);
  return;
}

