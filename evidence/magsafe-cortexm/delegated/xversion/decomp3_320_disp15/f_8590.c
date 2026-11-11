
undefined2 FUN_00008590(int param_1,int param_2)

{
  uint uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == 0) {
    iVar4 = 0x180;
  }
  else {
    iVar4 = 0x188;
  }
  *(undefined4 *)(*(int *)(DAT_000085f0 + param_1 * 4) + iVar4) = DAT_000085ec;
  uVar1 = (uint)(param_2 != 0);
  iVar3 = FUN_00007f90(param_1,uVar1,2);
  iVar4 = DAT_000085f4;
  if (iVar3 != 0) {
    uVar2 = FUN_0000089c(0x4b000,iVar3);
    *(undefined2 *)(iVar4 + param_1 * 0x5c + uVar1 * 2 + 0x44) = uVar2;
  }
  return *(undefined2 *)(iVar4 + param_1 * 0x5c + uVar1 * 2 + 0x44);
}

