
int FUN_0000084c(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_0000089c((param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f),
                       (param_2 ^ (int)param_2 >> 0x1f) - ((int)param_2 >> 0x1f));
  uVar2 = (int)(param_2 ^ param_1) >> 0x1f;
  return (uVar1 ^ uVar2) - uVar2;
}

