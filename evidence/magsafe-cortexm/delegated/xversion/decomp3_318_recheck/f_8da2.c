
void FUN_00008da2(uint *param_1,uint param_2)

{
  FUN_00000b50();
  if (param_1 != (uint *)0x0) {
    *param_1 = *param_1 & ~param_2;
  }
  FUN_00000b58();
  return;
}

