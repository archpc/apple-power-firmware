
void MemManage(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  byte *pbVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  
  disableIRQinterrupts();
  *puRam0000011c = uRam00000120;
  *puRam00000124 = 0xdd000000;
  *puRam00000128 = uRam0000012c;
  puVar1 = puRam00000130;
  *puRam00000130 = 0x21;
  puVar1[2] = uRam00000134;
  puVar1 = puRam00000138;
  *puRam00000138 = 0x40;
  puVar1[2] = 0x380000;
  puVar1[6] = 0x40;
  puVar1 = puRam0000013c;
  *puRam0000013c = 7;
  puVar1[2] = 0x1b6;
  puVar1[6] = 7;
  *puRam00000140 = 0x12;
  uVar6 = FUN_00000b50();
  puVar2 = puRam00000144;
  *puRam00000144 = *puRam00000144 & 0xfffffff8;
  pbVar3 = pbRam00000148;
  puVar2[1] = (uint)pbRam00000148[0x19];
  puVar2[2] = puVar2[2] & 0xfffffff8;
  puVar2[4] = (puVar2[4] & 0xffffff80) + (*pbVar3 & 0x7f);
  FUN_00000b60(0x32);
  *puVar2 = *puVar2 & 0xfffffffd | 5;
  FUN_00000b60(0x32);
  *puVar2 = *puVar2 & 0xfffffffe | 6;
  FUN_00000b58(uVar6);
  *puRam0000014c = 0x4f00;
  piVar5 = piRam00000154;
  iVar4 = iRam00000150;
  *piRam00000154 = iRam00000150 + 0x40;
  puVar1 = puRam00000158;
  *puRam00000158 = 0x300;
  *piVar5 = iVar4;
  puVar1[1] = 0;
  *piVar5 = iVar4 + 1;
  puRam0000014c[1] = 0x4f00;
  *piVar5 = iVar4 + 0x41;
  puVar1[2] = 0x900;
  *piVar5 = iVar4 + 2;
  puVar1[3] = 0x200;
  *piVar5 = iVar4 + 3;
  puVar1[4] = 0x2f00;
  *piVar5 = iVar4 + 4;
  puVar1[5] = 0x2f00;
  *piVar5 = iVar4 + 5;
  *puRam0000015c = 0;
  puVar1 = puRam00000160;
  puRam00000160[7] = 3;
  puVar1[4] = 3;
  puVar1[3] = 5;
  puVar1[2] = 1;
  *puVar1 = 2;
  return;
}

