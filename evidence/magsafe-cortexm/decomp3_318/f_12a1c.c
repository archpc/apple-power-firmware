
void FUN_00012a1c(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_00012a3c;
  uVar2 = *DAT_00012a3c;
  *DAT_00012a40 = *DAT_00012a40 & 0x7fffffff;
  *(ushort *)(DAT_00012a44 + 0x3a) = (ushort)uVar2 & 0x20;
  *puVar1 = 0;
  return;
}

