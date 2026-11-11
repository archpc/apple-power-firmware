
void FUN_00005172(void)

{
  uint uVar1;
  int *unaff_r4;
  
  FUN_000031a0();
  FUN_00002f6c();
  if ((int)((uint)*(byte *)(*unaff_r4 + 5) << 0x18) < 0) {
    FUN_00002ce4();
    FUN_00005c68();
    uVar1 = *(uint *)(*unaff_r4 + 4);
    if ((-1 < (int)uVar1) ||
       ((uVar1 >> 0x10 & 0x1ff) <= ((uVar1 & 0x7fffffff) >> 0x1b) * 0x1a + 0x1a)) {
      FUN_00002908();
    }
  }
  return;
}

