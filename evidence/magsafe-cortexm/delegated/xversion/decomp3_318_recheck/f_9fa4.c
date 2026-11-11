
undefined4 FUN_00009fa4(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    uVar2 = 0x100 - (param_1 & 0xff);
    if (param_3 <= uVar2) {
      uVar2 = param_3;
    }
    iVar1 = FUN_00009edc(param_1,param_2,uVar2);
    if (iVar1 < 0) break;
    param_1 = uVar2 + param_1;
    param_3 = param_3 - uVar2;
    param_2 = param_2 + uVar2;
  }
  return 0xffffffff;
}

