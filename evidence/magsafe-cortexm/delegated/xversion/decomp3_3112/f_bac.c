
void FUN_00000bac(void)

{
  uint *puVar1;
  
  FUN_00000b50();
  FUN_00012a9c();
  puVar1 = DAT_00000c0c;
  *DAT_00000c0c = *DAT_00000c0c & 0xffbfffff;
  *puVar1 = *puVar1 | 0x100000;
  *puVar1 = *puVar1 & 0xff7fffff;
  *puVar1 = *puVar1 | 0x200000;
  puVar1 = DAT_00000c10;
  *DAT_00000c10 = *DAT_00000c10 & 0xfeffffff;
  *puVar1 = *puVar1 & 0xfdffffff;
  *puVar1 = (DAT_00000c14 & *puVar1) + 0x500000;
  *puVar1 = (DAT_00000c18 & *puVar1) + 0xa00000;
  FUN_00000b60(DAT_00000c1c);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

