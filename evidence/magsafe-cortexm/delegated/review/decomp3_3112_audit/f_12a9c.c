
void FUN_00012a9c(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_00012abc;
  uVar2 = *DAT_00012abc;
  *DAT_00012ac0 = *DAT_00012ac0 & 0x7fffffff;
  *(ushort *)(DAT_00012ac4 + 0x3a) = (ushort)uVar2 & 0x20;
  *puVar1 = 0;
  return;
}

