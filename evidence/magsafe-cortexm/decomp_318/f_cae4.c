
void FUN_0000cae4(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_0000cafc;
  DAT_0000cafc[0x1a] = 0;
  uVar2 = DAT_0000cb00;
  *puVar1 = *puVar1 & DAT_0000cb00;
  *puVar1 = *puVar1 | uVar2 + 1;
  return;
}

