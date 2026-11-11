
void FUN_00007d68(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00007d98 + param_1 * 4);
  *(undefined4 *)(iVar1 + 0x11c) = 0x80;
  *(uint *)(iVar1 + 300) = *(uint *)(iVar1 + 300) & 0xffffff7f;
  FUN_00007bc4(param_1,0);
  FUN_00007c50(param_1,0);
  return;
}

