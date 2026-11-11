
void FUN_00008c8c(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(DAT_00008cc0 + param_1 * 0x5c + 0x54) = 0;
  iVar1 = *(int *)(DAT_00008cc4 + param_1 * 4);
  *(uint *)(iVar1 + 0x128) = DAT_00008cb8 & *(uint *)(iVar1 + 0x128);
  *(undefined4 *)(iVar1 + 0x118) = DAT_00008cbc;
  return;
}

