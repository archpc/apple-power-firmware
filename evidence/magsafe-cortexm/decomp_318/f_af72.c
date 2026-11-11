
void FUN_0000af72(int param_1,code *param_2)

{
  int unaff_r4;
  
  if (param_1 != 0) {
    *(code **)(unaff_r4 + 0x60) = param_2;
    return;
  }
  (*param_2)(1);
  *(undefined4 *)(unaff_r4 + 0x60) = 0;
  return;
}

