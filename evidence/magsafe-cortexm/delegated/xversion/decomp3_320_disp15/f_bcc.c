
void FUN_00000bcc(void)

{
  uint *puVar1;
  
  FUN_00000b70();
  FUN_00012c78();
  puVar1 = DAT_00000c2c;
  *DAT_00000c2c = *DAT_00000c2c & 0xffbfffff;
  *puVar1 = *puVar1 | 0x100000;
  *puVar1 = *puVar1 & 0xff7fffff;
  *puVar1 = *puVar1 | 0x200000;
  puVar1 = DAT_00000c30;
  *DAT_00000c30 = *DAT_00000c30 & 0xfeffffff;
  *puVar1 = *puVar1 & 0xfdffffff;
  *puVar1 = (DAT_00000c34 & *puVar1) + 0x500000;
  *puVar1 = (DAT_00000c38 & *puVar1) + 0xa00000;
  FUN_00000b80(DAT_00000c3c);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

