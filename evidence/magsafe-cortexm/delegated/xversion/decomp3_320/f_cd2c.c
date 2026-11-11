
undefined4 FUN_0000cd2c(char *param_1)

{
  bool bVar1;
  uint *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  int iVar11;
  undefined1 *puVar12;
  uint uVar13;
  uint uVar14;
  undefined1 auStack_20 [4];
  char local_1c;
  undefined1 local_1b [7];
  
  iVar4 = DAT_0000ceb4;
  uVar13 = DAT_0000ce9c;
  puVar2 = DAT_0000ce98;
  if (*(char *)(DAT_0000ceb4 + 0x22) == '\x01') {
    *DAT_0000ce98 = *DAT_0000ce98 & DAT_0000ce9c;
    *puVar2 = *puVar2 | uVar13 + 1;
    piVar3 = DAT_0000cea4;
    uVar13 = DAT_0000cea0;
    iVar5 = *(int *)(param_1 + 0xc);
    iVar11 = 0;
    if ((iVar5 == 0) || (param_1[0x10] == '\0')) {
LAB_0000cdd4:
      *(undefined1 *)(iVar4 + 0x22) = 3;
      FUN_00000b80(0x1e0);
      *piVar3 = -1;
      DAT_0000ce98[0x1a] = 1;
      local_1c = *param_1 * '\x02' + '\x01';
      FUN_0000ccdc(&local_1c,1,auStack_20);
      puVar2 = DAT_0000ceb0;
      uVar8 = (uint)*(ushort *)(param_1 + 8);
      uVar14 = uVar8 - 1;
      bVar1 = false;
      for (uVar7 = 0; uVar7 = uVar7 & 0xffff, uVar7 < uVar8; uVar7 = uVar7 + uVar9) {
        uVar9 = *puVar2 & 0x1f;
        uVar8 = uVar14 & 0xffff;
        if (0xf < uVar8) {
          uVar8 = 0x10;
        }
        if (uVar8 <= uVar9) {
          uVar9 = uVar8;
        }
        puVar12 = (undefined1 *)(*(int *)(param_1 + 4) + uVar7);
        for (uVar8 = uVar9; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar12 = (char)puVar2[0xe];
          puVar12 = puVar12 + 1;
        }
        uVar14 = uVar14 - (uVar9 & 0xff);
        bVar10 = true;
        if ((uVar14 & 0xffff) == 0) {
          bVar10 = bVar1;
        }
        if (!bVar10) {
          DAT_0000ce98[0x1a] = 0x18;
          uVar14 = 1;
          bVar1 = true;
        }
        if (uVar13 < 2) goto LAB_0000ce86;
        FUN_00000b80(0x30);
        uVar13 = uVar13 - 1;
        uVar8 = (uint)*(ushort *)(param_1 + 8);
      }
      while ((int)(DAT_0000ce98[0x1a] << 0x1b) < 0) {
        if ((int)uVar13 < 2) goto LAB_0000ce86;
        FUN_00000b80(0x30);
        uVar13 = uVar13 - 1;
      }
      uVar6 = 0;
    }
    else {
      local_1c = *param_1 << 1;
      uVar7 = (uint)(byte)(param_1[0x10] + 1);
      for (; uVar7 - 1 != iVar11; iVar11 = iVar11 + 1) {
        local_1b[iVar11] = *(undefined1 *)(iVar5 + iVar11);
        *(int *)(param_1 + 0xc) = iVar5 + iVar11 + 1;
      }
      *piVar3 = -1;
      FUN_0000ccdc(&local_1c,uVar7,auStack_20);
      DAT_0000ce98[0x1a] = 1;
      puVar2 = DAT_0000cea8;
      uVar7 = uVar13;
      while( true ) {
        if ((((*puVar2 & 0x1f) == 0) && (*DAT_0000ceac << 0x19 < 0)) &&
           (-1 < (int)(*puVar2 << 0x10))) goto LAB_0000cdd4;
        if ((*piVar3 << 0x1e < 0) || (uVar7 < 2)) break;
        FUN_00000b80(0x30);
        uVar7 = uVar7 - 1;
      }
LAB_0000ce86:
      FUN_0000cd0c();
      uVar6 = 0xc;
    }
    *(undefined1 *)(iVar4 + 0x22) = 1;
  }
  else {
    uVar6 = 0xf;
  }
  return uVar6;
}

