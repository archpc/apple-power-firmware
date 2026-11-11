
void FUN_00012c78(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_00012c98;
  uVar2 = *DAT_00012c98;
  *DAT_00012c9c = *DAT_00012c9c & 0x7fffffff;
  *(ushort *)(DAT_00012ca0 + 0x38) = (ushort)uVar2 & 0x20;
  *puVar1 = 0;
  return;
}

