
void FUN_00007af4(int param_1,int param_2,undefined1 param_3)

{
  int iVar1;
  
  iVar1 = DAT_00007b28 + param_1 * 0x1cc;
  *(undefined1 *)(iVar1 + 0x35) = param_3;
  FUN_00008d94(param_1,param_2);
  FUN_00008e58(param_1,param_2);
  iVar1 = iVar1 + param_2;
  *(undefined1 *)(iVar1 + 0x3a) = 2;
  *(undefined1 *)(iVar1 + 0x38) = 2;
  return;
}

