
int FUN_0000c9a4(char *param_1)

{
  uint *puVar1;
  uint *puVar2;
  int *piVar3;
  int iVar4;
  undefined1 uVar5;
  uint uVar6;
  char *pcVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint local_38;
  uint local_28;
  ushort local_20 [2];
  char local_1c [8];
  
  iVar4 = DAT_0000cb30;
  if (*(char *)(DAT_0000cb30 + 0x1a) != '\x01') {
    return 0xf;
  }
  *(undefined1 *)(DAT_0000cb30 + 0x1a) = 2;
  local_1c[0] = *param_1 << 1;
  uVar11 = (uint)(byte)param_1[0x10];
  pcVar7 = *(char **)(param_1 + 0xc);
  if (pcVar7 != (char *)0x0) {
    if (uVar11 == 0) {
      uVar11 = 0;
    }
    else {
      for (bVar8 = 1; bVar8 <= uVar11; bVar8 = bVar8 + 1) {
        local_1c[bVar8] = *pcVar7;
        pcVar7 = pcVar7 + 1;
        *(char **)(param_1 + 0xc) = pcVar7;
      }
    }
  }
  local_38 = 0;
  *DAT_0000cb1c = 0xffffffff;
  FUN_0000cb34(local_1c,uVar11 + 1 & 0xff,local_20);
  *DAT_0000cb20 = 1;
  piVar3 = DAT_0000cb2c;
  puVar2 = DAT_0000cb28;
  local_28 = DAT_0000cb24;
  uVar11 = DAT_0000cb24;
  while (((puVar1 = DAT_0000cb1c, uVar9 = DAT_0000cb24, (*puVar2 & 0x1f) != 0 ||
          (-1 < *piVar3 << 0x19)) || ((int)(*puVar2 << 0x10) < 0))) {
    iVar10 = 0xc;
    if ((uVar11 < 2) || ((*DAT_0000cb1c & 2) != 0)) goto LAB_0000ca44;
    FUN_00000b60(0x30);
    uVar11 = uVar11 - 1;
  }
  iVar10 = 0;
LAB_0000ca44:
  do {
    if (((int)(*puVar1 << 0x1e) < 0) || ((int)(*puVar1 << 0x1d) < 0)) goto LAB_0000ca60;
    if (uVar9 < 2) goto LAB_0000ca5e;
    FUN_00000b60(0x30);
    uVar9 = uVar9 - 1;
  } while( true );
LAB_0000cae6:
  if (-1 < *DAT_0000cb20 << 0x1b) goto LAB_0000cb00;
  if ((int)local_28 < 2) goto LAB_0000cb0a;
  FUN_00000b60(0x30);
  local_28 = local_28 - 1;
  goto LAB_0000cae6;
LAB_0000cb0a:
  iVar12 = 0xc;
  goto LAB_0000cb0c;
LAB_0000ca5e:
  iVar10 = 0xc;
LAB_0000ca60:
  uVar11 = (uint)*(ushort *)(param_1 + 8);
  if (uVar11 == 0) {
    *DAT_0000cb20 = 0x10;
    while (*DAT_0000cb20 << 0x1b < 0) {
      if (local_28 < 2) goto LAB_0000cb0a;
      FUN_00000b60(0x30);
      local_28 = local_28 - 1;
    }
  }
  else {
    uVar9 = uVar11;
    iVar12 = iVar10;
    if (iVar10 != 0) goto LAB_0000cb0c;
    for (; local_38 = local_38 & 0xffff, local_38 < uVar11; local_38 = local_38 + uVar6) {
      uVar5 = (undefined1)uVar9;
      if (0xf < (uVar9 & 0xffff)) {
        uVar5 = 0x10;
      }
      FUN_0000cb34(*(int *)(param_1 + 4) + local_38,uVar5,local_20);
      uVar6 = (uint)local_20[0];
      uVar9 = uVar9 - uVar6;
      if ((uVar9 & 0xffff) == 0) {
        *DAT_0000cb20 = 0x10;
        goto LAB_0000cae6;
      }
      iVar12 = 0xc;
      if ((local_28 < 2) || ((*DAT_0000cb1c & 2) != 0)) goto LAB_0000cb0c;
      FUN_00000b60(0x30);
      local_28 = local_28 - 1;
      uVar11 = (uint)*(ushort *)(param_1 + 8);
    }
  }
LAB_0000cb00:
  iVar12 = iVar10;
  if (iVar10 == 0) {
    iVar12 = 0;
    goto LAB_0000cb10;
  }
LAB_0000cb0c:
  FUN_0000cb64();
LAB_0000cb10:
  *(undefined1 *)(iVar4 + 0x1a) = 1;
  return iVar12;
}

