
void FUN_00012d8c(void)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  puVar2 = DAT_00012de8;
  puVar1 = DAT_00012de4;
  *DAT_00012de8 = (*DAT_00012de8 & 0xfe) - ((int)(DAT_00012de4[8] << 0x1c) >> 0x1f);
  puVar3 = DAT_00012dec;
  *DAT_00012dec = *DAT_00012dec & 0xfffffff0;
  *puVar2 = (puVar1[8] >> 7 & 2) + (*puVar2 & 0xfd) ^ 2;
  *puVar3 = *puVar3 & 0xffffff0f;
  puVar4 = DAT_00012df0;
  uVar5 = *DAT_00012df0;
  *puVar1 = *puVar1 & 0x7fffffff;
  *(ushort *)(DAT_00012df4 + 0x3a) = (ushort)uVar5 & 0x20;
  *puVar4 = 0;
  return;
}

