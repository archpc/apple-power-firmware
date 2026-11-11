
void FUN_0000cd0c(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_0000cd24;
  DAT_0000cd24[0x1a] = 0;
  uVar2 = DAT_0000cd28;
  *puVar1 = *puVar1 & DAT_0000cd28;
  *puVar1 = *puVar1 | uVar2 + 1;
  return;
}

