
void FUN_00012a48(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_00012a90;
  DAT_00012a90[-8] = DAT_00012a94;
  *puVar1 = DAT_00012a98;
  uVar3 = DAT_00012aa0;
  puVar2 = DAT_00012a9c;
  *DAT_00012a9c = DAT_00012aa0;
  puVar2[1] = 7;
  puVar2 = DAT_00012aa4;
  *DAT_00012aa4 = uVar3;
  puVar2[1] = 1;
  puVar2 = DAT_00012aa8;
  *DAT_00012aa8 = 0;
  puVar2[0x10] = 0;
  puVar2 = DAT_00012aac;
  DAT_00012aac[0x10] = 0;
  *puVar2 = 0;
  puVar2 = DAT_00012ab0;
  DAT_00012ab0[0x10] = 0;
  *puVar2 = 1;
  *(short *)(DAT_00012ab4 + 0x3a) = (short)*puVar2;
  *puVar1 = *puVar1 & 0xf3ffffff;
  return;
}

