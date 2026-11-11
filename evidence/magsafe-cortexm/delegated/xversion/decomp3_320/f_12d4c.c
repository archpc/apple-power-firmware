
void FUN_00012d4c(void)

{
  uint *puVar1;
  
  *DAT_00012d7c = *DAT_00012d7c | 0x80000000;
  puVar1 = DAT_00012d80;
  *DAT_00012d80 = *DAT_00012d80 & 0xfffffffd | 0xd;
  *puVar1 = *puVar1 & 0xffffffef | 0xe0;
  *DAT_00012d84 = (uint)*(ushort *)(DAT_00012d88 + 0x3a);
  return;
}

