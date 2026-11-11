
void FUN_00012ac8(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_00012b10;
  DAT_00012b10[-8] = DAT_00012b14;
  *puVar1 = DAT_00012b18;
  uVar3 = DAT_00012b20;
  puVar2 = DAT_00012b1c;
  *DAT_00012b1c = DAT_00012b20;
  puVar2[1] = 7;
  puVar2 = DAT_00012b24;
  *DAT_00012b24 = uVar3;
  puVar2[1] = 1;
  puVar2 = DAT_00012b28;
  *DAT_00012b28 = 0;
  puVar2[0x10] = 0;
  puVar2 = DAT_00012b2c;
  DAT_00012b2c[0x10] = 0;
  *puVar2 = 0;
  puVar2 = DAT_00012b30;
  DAT_00012b30[0x10] = 0;
  *puVar2 = 1;
  *(short *)(DAT_00012b34 + 0x3a) = (short)*puVar2;
  *puVar1 = *puVar1 & 0xf3ffffff;
  return;
}

