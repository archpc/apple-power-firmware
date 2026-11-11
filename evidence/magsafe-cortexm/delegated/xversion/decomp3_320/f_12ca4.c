
void FUN_00012ca4(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_00012cec;
  DAT_00012cec[-8] = DAT_00012cf0;
  *puVar1 = DAT_00012cf4;
  uVar3 = DAT_00012cfc;
  puVar2 = DAT_00012cf8;
  *DAT_00012cf8 = DAT_00012cfc;
  puVar2[1] = 7;
  puVar2 = DAT_00012d00;
  *DAT_00012d00 = uVar3;
  puVar2[1] = 1;
  puVar2 = DAT_00012d04;
  *DAT_00012d04 = 0;
  puVar2[0x10] = 0;
  puVar2 = DAT_00012d08;
  DAT_00012d08[0x10] = 0;
  *puVar2 = 0;
  puVar2 = DAT_00012d0c;
  DAT_00012d0c[0x10] = 0;
  *puVar2 = 1;
  *(short *)(DAT_00012d10 + 0x38) = (short)*puVar2;
  *puVar1 = *puVar1 & 0xf3ffffff;
  return;
}

