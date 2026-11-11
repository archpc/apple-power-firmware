
void FUN_00006498(int param_1)

{
  undefined4 uVar1;
  
  FUN_00002f62(param_1,4);
  if (*(char *)(DAT_000064c0 + param_1 * 0x1cc + 0x15) == '\0') {
    uVar1 = 0xb;
  }
  else {
    uVar1 = 0x10;
  }
  FUN_000031a0(param_1,uVar1);
  return;
}

