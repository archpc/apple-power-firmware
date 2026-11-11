
void FUN_00001cf0(int param_1)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  undefined4 uVar11;
  char *pcVar12;
  
  pcVar12 = (char *)(DAT_00001f2c + param_1 * 0x1cc);
  *(undefined **)(pcVar12 + 0x60) = PTR_DAT_00001f30;
  *(char **)(pcVar12 + 0x6c) = pcVar12 + 0x70;
  puVar6 = PTR_DAT_00001f34;
  iVar9 = param_1 * 0xf0;
  FUN_00000170(pcVar12,PTR_DAT_00001f34 + iVar9 + 0x40);
  if (*(short *)(puVar6 + iVar9 + 0x2e) == 0) {
    FUN_000001a2(pcVar12 + 0x128,0,0x19);
  }
  else {
    FUN_00000170(pcVar12 + 0x128,puVar6 + *(ushort *)(puVar6 + iVar9 + 0x2c),0x19);
  }
  if (*(short *)(puVar6 + iVar9 + 0x32) == 0) {
    FUN_000001a2(pcVar12 + 0x15c,0,0x18);
  }
  else {
    FUN_00000170(pcVar12 + 0x15c,puVar6 + *(ushort *)(puVar6 + iVar9 + 0x30),0x18);
  }
  pcVar12[0x175] = '\0';
  FUN_00000170(pcVar12 + 0x17c,DAT_00001f38 + param_1 * 0x40);
  if (*pcVar12 != '\x02') {
    pcVar12[1] = *pcVar12;
  }
  puVar4 = DAT_00001f04;
  puVar3 = DAT_00001f00;
  puVar2 = DAT_00001efc;
  puVar10 = *(uint **)(PTR_DAT_00001f3c + param_1 * 4);
  if (param_1 == 0) {
    *DAT_00001f04 = 0x4000;
    *puVar3 = 0x4000;
    uVar11 = 0x40;
    *puVar4 = 0x40;
    puVar2[8] = PTR_LAB_000083a0_1_00001f40;
    *puVar2 = DAT_00001f44;
  }
  else {
    *DAT_00001f04 = 0x8000;
    *puVar3 = 0x8000;
    uVar11 = 0x80;
    *puVar4 = 0x80;
    puVar2[9] = DAT_00001f48;
    puVar2[1] = DAT_00001f4c;
  }
  *puVar3 = uVar11;
  uVar5 = DAT_00001f08;
  *puVar10 = *puVar10 | DAT_00001f08 + 1;
  puVar10[99] = puVar10[99] & uVar5;
  puVar10[0x65] = puVar10[0x65] & 0xfffffff7;
  puVar10[0x65] = puVar10[0x65] | 1;
  FUN_00000b60(0x12c0);
  puVar10[0x3fc6] = puVar10[0x3fc6] & 0xfffffffb | 3;
  puVar10[0x3fc3] = puVar10[0x3fc3] & 0xfffffffa | 2;
  puVar10[0x3fc0] = puVar10[0x3fc0] & 0xfffffff3;
  iVar7 = DAT_00001f50;
  iVar8 = DAT_00001f50 + param_1 * 0x5c;
  uVar1 = (undefined2)DAT_00001f0c;
  *(undefined2 *)(iVar8 + 0x44) = uVar1;
  *(undefined2 *)(iVar8 + 0x46) = uVar1;
  FUN_0000843c(param_1,0);
  FUN_0000843c(param_1,1);
  puVar10[99] = DAT_00001f10 & puVar10[99];
  puVar10[99] = puVar10[99] | 0xe0000;
  puVar10[0x45] = puVar10[0x45] & 0xfff3ffff;
  puVar10[0x45] = puVar10[0x45] & 0xfb7fffff;
  puVar10[0x67] = puVar10[0x67] & 0xffffffeb;
  iVar8 = DAT_00001f54;
  *(undefined1 *)(DAT_00001f54 + param_1 * 0x88 + 0x85) = 1;
  *(int *)(DAT_00001f58 + iVar9) = DAT_00001f58 + iVar9 + 4;
  *(undefined4 *)(iVar8 + param_1 * 0x88) = DAT_00001f5c;
  *(undefined4 *)(iVar7 + param_1 * 0x5c) = DAT_00001f60;
  puVar10[0x2a] = 0x3f;
  puVar10[0x2b] = 0xfffffffd;
  puVar10[0x2c] = 0xffffffff;
  puVar10[0x31] = 0xfffffffd;
  puVar10[0x32] = 0xffffffff;
  puVar10[0x2e] = 0xfffffffd;
  puVar10[0x2f] = 0xffffffff;
  puVar10[1] = DAT_00001f14;
  puVar10[0x2d] = 0xffffffff;
  puVar10[0x33] = 0xffffffff;
  puVar10[0x30] = 0xffffffff;
  puVar10[0x36] = DAT_00001f18;
  puVar10[0x39] = 0xf;
  puVar10[0x40] = 300;
  puVar10[0x41] = DAT_00001f1c;
  puVar10[0x4a] = DAT_00001f20 & puVar10[0x4a];
  puVar10[0x51] = puVar10[0x51] & 0xffff;
  puVar10[0x51] = DAT_00001f24 | puVar10[0x51];
  puVar10[0x3c] = DAT_00001f28;
  pcVar12[0x32] = '\x01';
  *DAT_00001f64 = 1;
  return;
}

