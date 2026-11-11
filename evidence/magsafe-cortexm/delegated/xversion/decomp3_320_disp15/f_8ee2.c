
void FUN_00008ee2(uint *param_1,uint param_2)

{
  FUN_00000b70();
  if (param_1 != (uint *)0x0) {
    *param_1 = *param_1 & ~param_2;
  }
  FUN_00000b78();
  return;
}

