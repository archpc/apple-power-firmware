
bool FUN_00009570(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = DAT_00009590;
  bVar2 = *(int *)(DAT_00009590 + 0x10) == 0;
  if (bVar2) {
    *(undefined1 *)(DAT_00009594 + 0x2c) = 0;
    FUN_00000f28(iVar1 + 0x18);
  }
  return !bVar2;
}

