
void FUN_00008c54(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  char *pcVar4;
  
  iVar2 = *(int *)(DAT_00008ce8 + param_1 * 4);
  puVar3 = (uint *)(iVar2 + 0xff00);
  if ((*DAT_00008ce0 == -0x1b) && (DAT_00008ce0[1] == -0x53)) {
    if (param_1 == 0) {
      pcVar4 = DAT_00008ce0 + 2;
    }
    else {
      pcVar4 = DAT_00008ce0 + 5;
    }
  }
  else {
    pcVar4 = DAT_00008ce4;
    if (param_1 != 0) {
      pcVar4 = DAT_00008ce4 + 0xc;
    }
  }
  *puVar3 = *puVar3 & 0xfffffff3;
  *(uint *)(&DAT_0000ff04 + iVar2) = *(uint *)(&DAT_0000ff04 + iVar2) & 0xffffffc0;
  *(uint *)(&DAT_0000ff08 + iVar2) = *(uint *)(&DAT_0000ff08 + iVar2) & 0xffffffc0;
  *(uint *)(&DAT_0000ff04 + iVar2) = *(uint *)(&DAT_0000ff04 + iVar2) | (uint)(byte)pcVar4[param_3];
  *(uint *)(&DAT_0000ff08 + iVar2) = *(uint *)(&DAT_0000ff08 + iVar2) | (uint)(byte)pcVar4[param_3];
  if (param_3 == 2) {
    *puVar3 = *puVar3 | 8;
    param_3 = 3;
  }
  if (param_2 == 0) {
    uVar1 = 0x41000000;
  }
  else {
    uVar1 = 0x42000000;
  }
  *(uint *)(iVar2 + 0x18c) = *(uint *)(iVar2 + 0x18c) & 0xb3ffffff | param_3 << 0x1a | uVar1;
  return;
}

