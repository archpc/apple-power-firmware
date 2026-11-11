
undefined4 FUN_000019d2(byte *param_1)

{
  int iVar1;
  uint unaff_r6;
  undefined4 in_stack_00000004;
  undefined4 in_stack_00000008;
  byte in_stack_0000000c;
  uint in_stack_00000028;
  byte in_stack_0000002c;
  uint in_stack_00000048;
  byte in_stack_0000004c;
  
  do {
    if ((*param_1 & 1) == 0) {
      FUN_00001ab8(&stack0x0000006c);
LAB_000019de:
      if ((in_stack_0000002c & 1) == 0) {
        FUN_00001ab8(&stack0x0000002c);
      }
      else {
        iVar1 = FUN_00001ada(&stack0x0000002c);
        FUN_00001ab8(&stack0x0000002c);
        if (iVar1 != 0) {
          in_stack_00000048 = in_stack_00000048 | unaff_r6;
        }
      }
    }
    else {
      if ((in_stack_0000004c & 1) == 0) {
        FUN_00001ab8(&stack0x0000004c);
      }
      else {
        iVar1 = FUN_0000176c(&stack0x0000006c,&stack0x0000004c);
        if (0 < iVar1) {
          FUN_000017a0(&stack0x0000006c,&stack0x0000004c);
          FUN_00001ab8(&stack0x0000006c);
          iVar1 = FUN_000017a0(&stack0x0000002c,&stack0x0000000c);
          if (iVar1 != 0) {
            FUN_00001ada(&stack0x0000002c);
          }
          goto LAB_000019de;
        }
        FUN_000017a0(&stack0x0000004c,&stack0x0000006c);
        FUN_00001ab8(&stack0x0000004c);
        iVar1 = FUN_000017a0(&stack0x0000000c,&stack0x0000002c);
        if (iVar1 != 0) {
          FUN_00001ada(&stack0x0000000c);
        }
      }
      if ((in_stack_0000000c & 1) == 0) {
        FUN_00001ab8(&stack0x0000000c);
      }
      else {
        iVar1 = FUN_00001ada(&stack0x0000000c);
        FUN_00001ab8(&stack0x0000000c);
        if (iVar1 != 0) {
          in_stack_00000028 = in_stack_00000028 | unaff_r6;
        }
      }
    }
    iVar1 = FUN_0000176c(&stack0x0000006c,&stack0x0000004c);
    if (iVar1 == 0) {
      FUN_00000170(in_stack_00000004,&stack0x0000002c,0x20);
      return in_stack_00000008;
    }
    param_1 = &stack0x0000006c;
  } while( true );
}

