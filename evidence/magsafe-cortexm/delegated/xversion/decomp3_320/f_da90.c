
undefined8 FUN_0000da90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  iVar1 = DAT_0000dac0;
  iVar2 = DAT_0000dac0 + 100;
  uStack_1c = param_3;
  uStack_18 = param_4;
  FUN_00001334(iVar2,&uStack_1c);
  iVar3 = *(int *)(iVar1 + 0x50);
  if (iVar3 == 0) {
    *(undefined4 *)(iVar1 + 0x50) = param_1;
    *(undefined4 *)(iVar1 + 0x54) = param_2;
  }
  FUN_00001378(iVar2,&uStack_1c);
  return CONCAT44(param_2,(uint)(iVar3 == 0));
}

