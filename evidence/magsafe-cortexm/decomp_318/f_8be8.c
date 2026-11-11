
uint FUN_00008be8(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00008c10 + param_1 * 4);
  if ((*(uint *)(iVar1 + 0xa4) & DAT_00008c0c) != 0) {
    return 1;
  }
  return (*(uint *)(iVar1 + 0x118) & 0x200) >> 9;
}

