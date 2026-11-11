
void FUN_0000cb64(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_0000cb7c;
  DAT_0000cb7c[0x1a] = 0;
  uVar2 = DAT_0000cb80;
  *puVar1 = *puVar1 & DAT_0000cb80;
  *puVar1 = *puVar1 | uVar2 + 1;
  return;
}

