
undefined8 FUN_00000e80(void)

{
  int iVar1;
  undefined8 uVar2;
  
  FUN_00000e38();
  uVar2 = FUN_00000866();
  iVar1 = (int)((ulonglong)uVar2 >> 0x20);
  return CONCAT44(iVar1 >> 0xd,((uint)uVar2 >> 0xd) + iVar1 * 0x80000);
}

