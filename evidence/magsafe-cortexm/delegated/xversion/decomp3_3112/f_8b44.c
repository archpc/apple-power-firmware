
void FUN_00008b44(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(DAT_00008b78 + param_1 * 0x5c + 0x54) = 0;
  iVar1 = *(int *)(DAT_00008b7c + param_1 * 4);
  *(uint *)(iVar1 + 0x128) = DAT_00008b70 & *(uint *)(iVar1 + 0x128);
  *(undefined4 *)(iVar1 + 0x118) = DAT_00008b74;
  return;
}

