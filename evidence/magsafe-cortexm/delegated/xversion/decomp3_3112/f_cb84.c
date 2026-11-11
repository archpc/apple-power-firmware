
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0000cb84(char *param_1)

{
  bool bVar1;
  uint *puVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  undefined1 *puVar11;
  byte bVar12;
  uint uVar13;
  uint uVar14;
  uint local_30;
  ushort local_20 [2];
  char local_1c [8];
  
  iVar5 = DAT_0000cd28;
  uVar14 = DAT_0000cd10;
  puVar2 = _FUN_0000cd0c;
  if (*(char *)(DAT_0000cd28 + 0x1a) == '\x01') {
    *_FUN_0000cd0c = *_FUN_0000cd0c & DAT_0000cd10;
    *puVar2 = *puVar2 | uVar14 + 1;
    puVar2 = DAT_0000cd18;
    uVar14 = DAT_0000cd14;
    pcVar6 = *(char **)(param_1 + 0xc);
    if ((pcVar6 == (char *)0x0) || (uVar9 = (uint)(byte)param_1[0x10], uVar9 == 0)) {
LAB_0000cc28:
      *(undefined1 *)(iVar5 + 0x1a) = 3;
      FUN_00000b60(0x1e0);
      local_1c[0] = *param_1 * '\x02' + '\x01';
      *puVar2 = 0xffffffff;
      _FUN_0000cd0c[0x1a] = 1;
      local_30 = 1;
      FUN_0000cb34(local_1c,1,local_20);
      puVar2 = DAT_0000cd24;
      uVar9 = (uint)local_20[0];
      uVar10 = (uint)*(ushort *)(param_1 + 8);
      uVar13 = uVar10 - 1;
      bVar1 = false;
      uVar14 = DAT_0000cd14;
      for (uVar7 = 0; uVar7 = uVar7 & 0xffff, uVar7 < uVar10; uVar7 = uVar7 + uVar9) {
        bVar12 = (byte)uVar13;
        if (0xf < (uVar13 & 0xffff)) {
          bVar12 = 0x10;
        }
        uVar10 = *puVar2 & 0x1f;
        uVar9 = (uint)bVar12;
        if (uVar10 <= bVar12) {
          uVar9 = uVar10;
        }
        puVar11 = (undefined1 *)(*(int *)(param_1 + 4) + uVar7);
        for (uVar10 = uVar9; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar11 = (char)puVar2[0xe];
          puVar11 = puVar11 + 1;
        }
        uVar13 = uVar13 - uVar9;
        if ((uVar13 & 0xffff) == 0 && !bVar1) {
          _FUN_0000cd0c[0x1a] = 0x18;
          bVar1 = true;
          uVar13 = local_30;
        }
        if (uVar14 < 2) {
          local_20[0] = (ushort)uVar9;
          goto LAB_0000ccf6;
        }
        FUN_00000b60(0x30);
        uVar14 = uVar14 - 1;
        uVar10 = (uint)*(ushort *)(param_1 + 8);
      }
      local_20[0] = (ushort)uVar9;
      while ((int)(_FUN_0000cd0c[0x1a] << 0x1b) < 0) {
        if ((int)uVar14 < 2) goto LAB_0000ccf6;
        FUN_00000b60(0x30);
        uVar14 = uVar14 - 1;
      }
      uVar8 = 0;
    }
    else {
      local_1c[0] = *param_1 << 1;
      for (bVar12 = 1; bVar12 <= uVar9; bVar12 = bVar12 + 1) {
        local_1c[bVar12] = *pcVar6;
        pcVar6 = pcVar6 + 1;
        *(char **)(param_1 + 0xc) = pcVar6;
      }
      *puVar2 = 0xffffffff;
      FUN_0000cb34(local_1c,uVar9 + 1 & 0xff,local_20);
      _FUN_0000cd0c[0x1a] = 1;
      piVar4 = DAT_0000cd20;
      puVar3 = DAT_0000cd1c;
      while( true ) {
        if ((((*puVar3 & 0x1f) == 0) && (*piVar4 << 0x19 < 0)) && (-1 < (int)(*puVar3 << 0x10)))
        goto LAB_0000cc28;
        if (uVar14 < 2) break;
        if ((*puVar2 & 2) != 0) break;
        FUN_00000b60(0x30);
        uVar14 = uVar14 - 1;
      }
LAB_0000ccf6:
      FUN_0000cb64();
      uVar8 = 0xc;
    }
    *(undefined1 *)(iVar5 + 0x1a) = 1;
  }
  else {
    uVar8 = 0xf;
  }
  return uVar8;
}

