
undefined4 FUN_00010c18(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = DAT_00010c48;
  uVar3 = *(uint *)(DAT_00010c48 + 0x14);
  uVar2 = 0;
  if (((uVar3 >> 0x10 != 0) && (uVar3 >> 0x10 < 3)) && (uVar3 + param_1 <= DAT_00010c44)) {
    FUN_00009fac(uVar3,param_2,param_1);
    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + param_1;
    uVar2 = 1;
  }
  return uVar2;
}

