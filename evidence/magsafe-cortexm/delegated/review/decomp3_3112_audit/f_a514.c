
void FUN_0000a514(uint *param_1,uint *param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if (uVar1 >> 0x1e == 2) {
    *param_2 = (uVar1 & 0xfffff) >> 10;
    *param_3 = (*param_1 & 0x3fffffff) >> 0x14;
  }
  else {
    if (uVar1 >> 0x1e != 0) {
      *param_4 = 0;
      *param_3 = 0;
      *param_2 = 0;
      return;
    }
    uVar1 = (uVar1 & 0xfffff) >> 10;
    *param_3 = uVar1;
    *param_2 = uVar1;
  }
  *param_4 = DAT_0000a550 & *param_1;
  return;
}

