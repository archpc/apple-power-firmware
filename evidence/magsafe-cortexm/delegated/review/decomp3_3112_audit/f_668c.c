
void FUN_0000668c(void)

{
  code *in_r3;
  int unaff_r6;
  int iVar1;
  
  (*in_r3)();
  if (*(char *)(unaff_r6 + 0x15) == '\x01') {
    FUN_000031a0();
    FUN_00003038();
    return;
  }
  iVar1 = *(int *)(unaff_r6 + 0x60);
  (**(code **)(iVar1 + 0x2c))();
  (**(code **)(iVar1 + 0x30))();
  (**(code **)(iVar1 + 0x34))();
  FUN_000031a0();
  return;
}

