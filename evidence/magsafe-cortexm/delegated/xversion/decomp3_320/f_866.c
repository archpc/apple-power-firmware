
undefined8 FUN_00000866(uint param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (param_1 & 0xffff) * (param_3 & 0xffff);
  uVar3 = (uVar2 >> 0x10) + (param_3 & 0xffff) * (param_1 >> 0x10);
  uVar1 = (uVar3 & 0xffff) + (param_3 >> 0x10) * (param_1 & 0xffff);
  return CONCAT44(param_1 * param_4 + param_3 * param_2 + (param_3 >> 0x10) * (param_1 >> 0x10) +
                  (uVar3 >> 0x10) + (uVar1 >> 0x10),uVar1 * 0x10000 + (uVar2 & 0xffff));
}

