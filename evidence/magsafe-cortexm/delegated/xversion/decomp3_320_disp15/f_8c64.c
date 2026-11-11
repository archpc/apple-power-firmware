
void FUN_00008c64(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00008c88 + param_1 * 4);
  *(uint *)(iVar1 + 0x138) = *(uint *)(iVar1 + 0x138) | 0x101;
  FUN_00000b80(0xf0);
  *(uint *)(iVar1 + 0x138) = *(uint *)(iVar1 + 0x138) & 0xfffffefe;
  return;
}

