
uint FUN_0000197e(void)

{
  int iVar1;
  undefined4 unaff_r5;
  uint unaff_r6;
  undefined4 unaff_r7;
  undefined4 in_stack_00000004;
  uint in_stack_00000008;
  byte in_stack_0000000c;
  uint in_stack_00000028;
  byte in_stack_0000002c;
  uint in_stack_00000048;
  byte in_stack_0000004c;
  byte in_stack_0000006c;
  
code_r0x0000197e:
  FUN_00001a3c(&stack0x0000004c);
LAB_00001984:
  if ((in_stack_0000000c & 1) == 0) {
    FUN_00001a3c(&stack0x0000000c);
  }
  else {
    iVar1 = FUN_00001a5e(&stack0x0000000c,unaff_r7);
    FUN_00001a3c(&stack0x0000000c);
    unaff_r7 = unaff_r5;
    if (iVar1 != 0) {
      in_stack_00000028 = in_stack_00000028 | unaff_r6;
    }
  }
LAB_0000194c:
  iVar1 = FUN_000016fc(&stack0x0000006c,&stack0x0000004c);
  if (iVar1 == 0) {
    FUN_00000170(in_stack_00000004,&stack0x0000002c,0x20);
    return in_stack_00000008 ^ 1;
  }
  if ((in_stack_0000006c & 1) == 0) {
    FUN_00001a3c(&stack0x0000006c);
  }
  else {
    if ((in_stack_0000004c & 1) == 0) goto code_r0x0000197e;
    if (iVar1 < 1) goto LAB_000019fe;
    FUN_00001730(&stack0x0000006c,&stack0x0000004c);
    FUN_00001a3c(&stack0x0000006c);
    iVar1 = FUN_00001730(&stack0x0000002c,&stack0x0000000c);
    if (iVar1 != 0) {
      FUN_00001a5e(&stack0x0000002c,unaff_r7);
    }
  }
  if ((in_stack_0000002c & 1) == 0) {
    FUN_00001a3c(&stack0x0000002c);
  }
  else {
    iVar1 = FUN_00001a5e(&stack0x0000002c,unaff_r7);
    FUN_00001a3c(&stack0x0000002c);
    unaff_r7 = unaff_r5;
    if (iVar1 != 0) {
      in_stack_00000048 = in_stack_00000048 | unaff_r6;
    }
  }
  goto LAB_0000194c;
LAB_000019fe:
  FUN_00001730(&stack0x0000004c,&stack0x0000006c);
  FUN_00001a3c(&stack0x0000004c);
  iVar1 = FUN_00001730(&stack0x0000000c,&stack0x0000002c);
  if (iVar1 != 0) {
    FUN_00001a5e(&stack0x0000000c,unaff_r7);
  }
  goto LAB_00001984;
}

