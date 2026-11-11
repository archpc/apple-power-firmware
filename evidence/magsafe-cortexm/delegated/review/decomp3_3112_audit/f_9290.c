
uint FUN_00009290(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)(param_1 * 0x32) >> 0x10;
  if (uVar1 < 0x31) {
    iVar2 = uVar1 + 1;
  }
  else {
    iVar2 = 0x31;
  }
  uVar1 = (uint)*(ushort *)(param_2 + uVar1 * 2);
  return uVar1 + ((*(ushort *)(param_2 + iVar2 * 2) - uVar1) * param_1 >> 0x10) & 0xffff;
}

