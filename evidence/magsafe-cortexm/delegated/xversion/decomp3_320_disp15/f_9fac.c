
undefined4 FUN_00009fac(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  do {
    if (param_3 == 0) {
      return 0;
    }
    uVar1 = 0x100 - (param_1 & 0xff);
    uVar3 = param_3;
    if (uVar1 <= param_3) {
      uVar3 = uVar1;
    }
    iVar2 = FUN_00009eec(param_1,param_2,uVar3);
    param_1 = uVar3 + param_1;
    param_3 = param_3 - uVar3;
    param_2 = param_2 + uVar3;
  } while (-1 < iVar2);
  return 0xffffffff;
}

