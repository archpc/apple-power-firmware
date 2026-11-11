
undefined8 FUN_0000899c(int param_1,int param_2,int param_3)

{
  char cVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  
  uVar8 = 0x110;
  if (param_2 != 1) {
    uVar8 = 0;
  }
  iVar10 = DAT_00008aa4 + param_1 * 0x1cc;
  cVar1 = *(char *)(iVar10 + 0x15);
  iVar3 = param_3;
  if (cVar1 == '\x01') {
    iVar3 = 2;
  }
  iVar11 = *(int *)(DAT_00008aa8 + param_1 * 4);
  puVar2 = (uint *)(iVar11 + 0x18c);
  uVar4 = *(uint *)(iVar11 + 0x18c) & 0x110;
  if (uVar4 != uVar8) {
    *puVar2 = *puVar2 & 0xfffffeef;
    *puVar2 = *puVar2 | uVar8;
  }
  if (cVar1 == '\x01') {
    pbVar9 = (byte *)(DAT_00008aac + (uint)*(byte *)(iVar10 + 0x35) * 4);
    pbVar5 = pbVar9 + 1;
  }
  else {
    if (param_3 == 0) {
      iVar6 = 1;
    }
    else {
      iVar6 = 2;
    }
    pbVar5 = (byte *)(DAT_00008aac + 0xc + iVar6);
    pbVar9 = (byte *)(DAT_00008aac + 0xc + param_3);
  }
  uVar7 = (uint)*pbVar5 << 9 | (uint)*pbVar9 << 5;
  if ((*puVar2 & 0xee0) == uVar7) {
    if (uVar4 == uVar8) goto LAB_00008a40;
  }
  else {
    *puVar2 = *puVar2 & 0xfffff11f;
    *puVar2 = *puVar2 | uVar7;
  }
  FUN_00000b80(0x960);
LAB_00008a40:
  uVar8 = *(uint *)(iVar11 + 0xa4) & 0x20000;
  uVar4 = *(uint *)(iVar11 + 0xa4) & 0x40000;
  if ((uVar4 != 0) && (uVar8 == 0)) {
    if (param_3 == 0) {
      iVar3 = 1;
    }
    else {
      iVar3 = 2;
    }
    if (*(char *)(iVar10 + 0x15) == '\x01') {
      iVar3 = 1;
    }
    uVar8 = 0;
  }
  if (param_3 == 0) {
    iVar11 = 2;
  }
  else {
    iVar11 = 3;
  }
  cVar1 = *(char *)(iVar10 + 0x15);
  if (cVar1 == '\x01' && (uVar4 == 0 && uVar8 == 0)) {
    iVar3 = 0;
  }
  iVar10 = iVar3;
  if (uVar8 != 0) {
    iVar10 = iVar11;
  }
  iVar11 = iVar3;
  if (uVar4 != 0) {
    iVar11 = iVar10;
  }
  if (cVar1 == '\0') {
    iVar3 = iVar11;
  }
  return CONCAT44(param_2,iVar3);
}

