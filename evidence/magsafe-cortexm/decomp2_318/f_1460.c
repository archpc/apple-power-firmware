
uint FUN_00001460(byte *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 0xffffffff;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    uVar1 = *(uint *)(DAT_00001494 + ((uVar1 ^ *param_1) & 0xf) * 4) ^ uVar1 >> 4;
    uVar1 = uVar1 >> 4 ^ *(uint *)(DAT_00001494 + ((uint)(*param_1 >> 4) ^ uVar1 & 0xf) * 4);
    param_1 = param_1 + 1;
  }
  return ~uVar1;
}

