
void FUN_00005df6(int param_1)

{
  uint uVar1;
  int unaff_r6;
  
  uVar1 = *(uint *)(param_1 + 4);
  if ((((int)uVar1 < 0) && (DAT_00005eb4 <= (DAT_00005eb0 & uVar1))) && ((uVar1 & 0x4000000) != 0))
  {
    FUN_00007172();
  }
  else {
    *(undefined1 *)(unaff_r6 + 0x43) = 2;
    FUN_00003038();
    (*(code *)**(undefined4 **)(unaff_r6 + 0x60))();
  }
  return;
}

