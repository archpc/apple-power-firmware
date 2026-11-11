
undefined4 FUN_00008d2c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00008d50 + param_1 * 4);
  if (((*(uint *)(iVar1 + 0xa4) & DAT_00008d4c) == 0) && (-1 < *(int *)(iVar1 + 0x118) << 0x16)) {
    return 0;
  }
  return 1;
}

