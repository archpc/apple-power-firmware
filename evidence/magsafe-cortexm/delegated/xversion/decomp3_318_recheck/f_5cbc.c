
void FUN_00005cbc(int param_1)

{
  uint uVar1;
  uint uVar2;
  int unaff_r6;
  int iVar3;
  int in_stack_00000008;
  
  if (param_1 == 0) {
    uVar1 = *(uint *)(in_stack_00000008 + 4);
    if ((((int)uVar1 < 0) && (DAT_00005eb4 <= (DAT_00005eb0 & uVar1))) && ((uVar1 & 0x4000000) != 0)
       ) {
      FUN_00007172();
      return;
    }
  }
  else if (((param_1 == 1) && (uVar1 = *(uint *)(in_stack_00000008 + 4), (int)uVar1 < 0)) &&
          (uVar2 = (uVar1 & 0x1ffffff) >> 0x10, 0x1a < uVar2)) {
    iVar3 = in_stack_00000008 + 8;
    if ((uVar1 & 0x7fffffff) >> 0x1b != 0) {
      FUN_00000170(in_stack_00000008 + 0x22,iVar3,uVar2 - 0x1a);
      FUN_00000170(iVar3,DAT_00005ecc,0x1a);
      FUN_000031a0();
      return;
    }
    FUN_00000170(DAT_00005ecc,iVar3,0x1a);
  }
  *(undefined1 *)(unaff_r6 + 0x43) = 2;
  FUN_00003038();
  (*(code *)**(undefined4 **)(unaff_r6 + 0x60))();
  return;
}

