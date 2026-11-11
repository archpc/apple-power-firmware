
void FUN_00012af0(void)

{
  uint *puVar1;
  
  *DAT_00012b20 = *DAT_00012b20 | 0x80000000;
  puVar1 = DAT_00012b24;
  *DAT_00012b24 = *DAT_00012b24 & 0xfffffffd | 0xd;
  *puVar1 = *puVar1 & 0xffffffef | 0xe0;
  *DAT_00012b28 = (uint)*(ushort *)(DAT_00012b2c + 0x3c);
  return;
}

