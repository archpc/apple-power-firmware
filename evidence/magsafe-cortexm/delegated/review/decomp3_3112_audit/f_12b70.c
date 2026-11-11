
void FUN_00012b70(void)

{
  uint *puVar1;
  
  *DAT_00012ba0 = *DAT_00012ba0 | 0x80000000;
  puVar1 = DAT_00012ba4;
  *DAT_00012ba4 = *DAT_00012ba4 & 0xfffffffd | 0xd;
  *puVar1 = *puVar1 & 0xffffffef | 0xe0;
  *DAT_00012ba8 = (uint)*(ushort *)(DAT_00012bac + 0x3c);
  return;
}

