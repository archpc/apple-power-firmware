
void FUN_00012b30(void)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  puVar2 = DAT_00012b8c;
  puVar1 = DAT_00012b88;
  *DAT_00012b8c = (*DAT_00012b8c & 0xfe) - ((int)(DAT_00012b88[8] << 0x1c) >> 0x1f);
  puVar3 = DAT_00012b90;
  *DAT_00012b90 = *DAT_00012b90 & 0xfffffff0;
  *puVar2 = (puVar1[8] >> 7 & 2) + (*puVar2 & 0xfd) ^ 2;
  *puVar3 = *puVar3 & 0xffffff0f;
  puVar4 = DAT_00012b94;
  uVar5 = *DAT_00012b94;
  *puVar1 = *puVar1 & 0x7fffffff;
  *(ushort *)(DAT_00012b98 + 0x3c) = (ushort)uVar5 & 0x20;
  *puVar4 = 0;
  return;
}

