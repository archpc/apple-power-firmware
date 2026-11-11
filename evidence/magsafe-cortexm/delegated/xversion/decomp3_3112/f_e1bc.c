
int FUN_0000e1bc(uint param_1,int *param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  *param_2 = (param_1 & 0xfffff80f) + (param_4 & 0x1f) * 0x40 + 0x10;
  if (param_3 != 0) {
    FUN_000007f0(param_2 + 1,param_3,param_4);
    uVar1 = param_4 >> 2;
    if ((param_4 & 3) != 0) {
      uVar1 = uVar1 + 1;
    }
    return uVar1 + 1;
  }
  return 1;
}

