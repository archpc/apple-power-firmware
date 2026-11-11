
int FUN_0000ccb8(undefined1 param_1)

{
  uint uVar1;
  undefined4 unaff_r4;
  undefined1 *unaff_r5;
  char in_stack_00000008;
  
  *unaff_r5 = param_1;
  FUN_0000131c(DAT_0000ccf0);
  uVar1 = DAT_0000ccf4;
  *(undefined1 *)(DAT_0000ccf4 + 0x10) = 1;
  *(undefined4 *)(uVar1 + 0xc) = unaff_r4;
  *(undefined2 *)(uVar1 + 8) = 1;
  *(undefined1 **)(uVar1 + 4) = unaff_r5;
  software_interrupt(0x40);
  if ((uVar1 & 0xff) == 0) {
    FUN_00001360(DAT_0000ccf0);
    return (int)in_stack_00000008;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000967c(3);
}

