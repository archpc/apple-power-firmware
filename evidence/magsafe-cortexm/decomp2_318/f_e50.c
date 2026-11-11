
undefined8 FUN_00000e50(void)

{
  int iVar1;
  undefined8 uVar2;
  
  FUN_00000e08();
  uVar2 = FUN_0000084a();
  iVar1 = (int)((ulonglong)uVar2 >> 0x20);
  return CONCAT44(iVar1 >> 0xd,((uint)uVar2 >> 0xd) + iVar1 * 0x80000);
}

