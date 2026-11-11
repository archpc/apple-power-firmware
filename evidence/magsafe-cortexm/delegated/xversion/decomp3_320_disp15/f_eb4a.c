
void FUN_0000eb4a(void)

{
  int *unaff_r4;
  char in_ZR;
  undefined8 in_d0;
  undefined8 in_d2;
  uint in_stack_00000014;
  
  VectorMultiplyAccumulate(in_d2,in_d0,4,1);
  if (in_ZR != '\0') {
    FUN_0000eca0();
    return;
  }
  *unaff_r4 = (in_stack_00000014 & 0xfffff80f) + 0x310;
  FUN_0000ecb0();
  return;
}

