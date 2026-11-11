
void FUN_00005d9a(void)

{
  uint uVar1;
  uint uVar2;
  int unaff_r6;
  int in_stack_00000008;
  
  uVar1 = *(uint *)(in_stack_00000008 + 4);
  if ((int)uVar1 < 0) {
    uVar2 = (uVar1 & 0x1ffffff) >> 0x10;
    if (0x1a < uVar2) {
      uVar1 = (uVar1 & 0x7fffffff) >> 0x1b;
      if (uVar1 != 1) {
        if (uVar1 == 0) {
          FUN_00000170(DAT_00005ecc,in_stack_00000008 + 8,0x1a);
          FUN_00007172();
        }
        goto LAB_00005dfc;
      }
      FUN_000007f0(in_stack_00000008 + 0x22,in_stack_00000008 + 8,uVar2 - 0x1a);
      FUN_00000170(in_stack_00000008 + 8,DAT_00005ecc,0x1a);
    }
    FUN_000031a0();
  }
  else {
LAB_00005dfc:
    *(undefined1 *)(unaff_r6 + 0x43) = 2;
    FUN_00003038();
    (*(code *)**(undefined4 **)(unaff_r6 + 0x60))();
  }
  return;
}

