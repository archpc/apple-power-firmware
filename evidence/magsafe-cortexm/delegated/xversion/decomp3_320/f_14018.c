
void FUN_00014018(void)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint local_1d8;
  uint local_1cc;
  uint local_1b0;
  int local_1ac [3];
  uint local_1a0;
  int local_130;
  uint local_12c [2];
  undefined1 auStack_124 [8];
  int local_11c;
  int local_118;
  int local_30;
  uint local_24;
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  
  *DAT_000143c8 = 0x2000;
  *DAT_000143cc = DAT_000143d0;
  *DAT_000143d4 = 2;
  FUN_00014504(0x17);
  FUN_00014504(0x21,1);
  puVar2 = DAT_00014428;
  *DAT_00014428 = 0xc;
  *puVar2 = DAT_0001442c | *puVar2;
  puVar2[0x10] = 0;
  puVar2[0x12] = 0xa0000;
  *DAT_00014430 = 0x80000007;
  puVar2[0x11] = 1;
  puVar3 = DAT_00014434;
  *DAT_00014434 = 0x80000007;
  puVar3[1] = 4;
  puVar2[0x14] = 4;
  puVar3 = DAT_00014438;
  *DAT_00014438 = 0;
  puVar3[0x10] = 0;
  puVar3 = DAT_0001443c;
  DAT_0001443c[0x10] = 0;
  *puVar3 = 0;
  puVar3 = DAT_00014440;
  DAT_00014440[0x10] = 0;
  *puVar3 = 0;
  *puVar2 = *puVar2 | 0x80000000;
  *DAT_00014444 = DAT_00014448;
  *DAT_0001444c = 0xffffffff;
  FUN_00013ff4(DAT_00014484);
  (*pcRam000003f0)(local_12c,0x1000,0x100);
  iVar6 = (*pcRam000003ec)(local_12c,0xfc);
  if (iVar6 != local_30) {
LAB_000143d8:
    puVar3 = DAT_000144b0;
    *DAT_000144b0 = 6;
    FUN_000144dc();
    *puVar3 = 0x20;
    *puVar3 = 0;
    *puVar3 = 0x10;
    *puVar3 = 0;
    FUN_000144dc();
    puVar2 = DAT_000144b4;
    while( true ) {
      *puVar2 = *puVar2 | DAT_00014488 + 5;
      *puVar2 = *puVar2 & DAT_0001448c;
      *puVar3 = 5;
      *puVar3 = 0;
      FUN_000144dc();
      if ((puVar2[0xf] & 1) == 0) break;
      FUN_00013ff4(0x1e0);
    }
    *DAT_000144b8 = 0x80000000;
    FUN_00013ff4(&DAT_000012c0);
    *DAT_000144bc = *DAT_000144bc | 0x300000;
    FUN_00013ff4(DAT_000144c0);
    *DAT_000144c4 = DAT_000144c8 | *DAT_000144c4 & DAT_00014488;
    return;
  }
  iVar6 = 0x20000;
  if (local_118 != 0) {
    iVar6 = local_11c;
  }
  local_1d8 = iVar6 + 0x100;
  iVar12 = 0;
LAB_000140f0:
  if (iVar12 != 4) {
    local_1cc = 0x80;
    (*pcRam000003f0)(local_1ac,local_1d8);
    iVar9 = local_130;
    iVar7 = (*pcRam000003ec)(local_1ac,0x7c);
    iVar15 = local_1ac[0];
    puVar2 = DAT_000144cc;
    if (iVar7 == iVar9) {
      FUN_00013fc4(DAT_000144cc,0,0x68);
      FUN_00013f94(puVar2 + 0x12,DAT_000144d0,0x20);
      uVar14 = iVar15 + 0x80;
      if (((uVar14 < 0x100001) && (local_1d8 < 0x100001)) && (uVar14 + local_1d8 < 0x100001)) {
        uVar10 = local_1d8;
        for (uVar13 = 0; uVar5 = DAT_000144d4, uVar13 < uVar14; uVar13 = uVar16 + uVar13) {
          uVar16 = uVar14 - uVar13;
          if (0x7f < uVar14 - uVar13) {
            uVar16 = local_1cc;
          }
          (*pcRam000003f0)(DAT_000144d4,uVar10,uVar16);
          FUN_00014680(uVar5,uVar16);
          uVar10 = uVar16 + uVar10;
        }
      }
      puVar8 = local_12c;
      local_12c[0] = CONCAT31(local_12c[0]._1_3_,0x80);
      iVar15 = 0;
      local_1c = local_1c & 0xffffff00;
      uVar14 = *puVar2;
      do {
        FUN_00014680(puVar8,1);
        puVar8 = &local_1c;
        if ((*puVar2 & 0x1ff) == 0x1c0) break;
      } while (*puVar2 != 0);
      puVar2[0xf] = 0;
      puVar2[0x10] = uVar14 << 0x18 | (uVar14 >> 8 & 0xff) << 0x10 | (uVar14 >> 0x10 & 0xff) << 8 |
                     uVar14 >> 0x18;
      FUN_00014550();
      for (iVar9 = 0x48; iVar9 != 0x68; iVar9 = iVar9 + 4) {
        uVar14 = *(uint *)((int)puVar2 + iVar9);
        *(uint *)((int)puVar2 + iVar9) =
             uVar14 << 0x18 | (uVar14 >> 8 & 0xff) << 0x10 | (uVar14 >> 0x10 & 0xff) << 8 |
             uVar14 >> 0x18;
      }
      for (; iVar15 != 4; iVar15 = iVar15 + 1) {
        (*pcRam000003f0)(local_12c,iVar6 + 8 + iVar15 * 0x24);
        iVar9 = 0;
        do {
          if (iVar9 + 4 == 0x24) {
            if (local_1a0 >> 0x18 != 0) goto LAB_0001437a;
            uVar10 = local_1ac[0] + local_1a0;
            local_1b0 = local_1a0 * 0x100 + DAT_00014498;
            uVar13 = local_1a0 - 0x80;
            uVar14 = local_1d8;
            goto LAB_000141e2;
          }
          iVar7 = iVar9 + 0x48;
          iVar1 = iVar9 + -4;
          iVar9 = iVar9 + 4;
        } while (*(int *)((int)puVar2 + iVar7) == *(int *)(auStack_124 + iVar1));
      }
    }
  }
  goto LAB_000143d8;
LAB_000141e2:
  uVar5 = DAT_000144d4;
  if (uVar10 <= uVar13) goto LAB_0001437a;
  (*pcRam000003f0)(DAT_000144d4,uVar14,0x100);
  iVar15 = FUN_00013fd4(uVar5,uVar13,0x100);
  if (iVar15 != 0) {
    uVar16 = 0;
    local_20 = 0;
    local_24 = 0;
    if (uVar13 < 0x20000) {
      FUN_00013f94(auStack_124,DAT_000144d4,0x100);
      puVar2 = DAT_00014490;
      local_12c[0] = DAT_0001449c;
      local_12c[1] = 0xff;
      *DAT_00014490 = (uint)local_12c;
      puVar8 = puVar2 + -1;
      *puVar8 = 0x80000004;
      uVar11 = *puVar2;
      if (DAT_00014494 < *puVar2) {
LAB_00014252:
        uVar16 = uVar11 & 0xff;
      }
      else if ((uVar11 & DAT_00014494 + 1) != 0xa0000000) {
        uVar11 = *DAT_00014490;
        goto LAB_00014252;
      }
      local_20 = uVar16;
      if (uVar16 == 0) {
        FUN_00014008();
        local_18 = DAT_000144d8;
        puVar2 = DAT_00014490;
        local_1c = DAT_000144a0;
        *DAT_00014490 = (uint)&local_1c;
        *puVar8 = 0x80000016;
        puVar4 = DAT_00014490;
        local_24 = *puVar2;
        if (DAT_00014494 < *puVar2) {
LAB_0001429c:
          local_24 = local_24 & 0xff;
        }
        else {
          if ((local_24 & DAT_00014494 + 1) != 0xa0000000) {
            local_24 = *DAT_00014490;
            goto LAB_0001429c;
          }
          local_24 = 0;
        }
        if (local_24 == 0) {
          *DAT_00014490 = DAT_000144a4;
          *puVar8 = 0x80000015;
          local_20 = *puVar4;
          if (*puVar4 <= DAT_00014494) {
            if ((local_20 & DAT_00014494 + 1) == 0xa0000000) {
              local_20 = 0;
              goto LAB_000142d6;
            }
            local_20 = *DAT_00014490;
          }
          local_20 = local_20 & 0xff;
        }
LAB_000142d6:
        puVar2 = DAT_00014490;
        if (local_20 == 0) {
          local_12c[0] = DAT_000144a8 | DAT_0001448c + 1 & local_1b0;
          *DAT_00014490 = (uint)local_12c;
          *puVar8 = 0x80000005;
          local_20 = *puVar2;
          if (*puVar2 <= DAT_00014494) {
            if ((local_20 & DAT_00014494 + 1) == 0xa0000000) {
              local_20 = 0;
              goto LAB_0001431e;
            }
            local_20 = *DAT_00014490;
          }
          local_20 = local_20 & 0xff;
        }
LAB_0001431e:
        puVar2 = DAT_00014490;
        if (local_24 == 0) {
          local_1c = DAT_000144ac;
          *DAT_00014490 = (uint)&local_1c;
          *puVar8 = 0x80000017;
          local_24 = *puVar2;
          if (DAT_00014494 < *puVar2) {
LAB_00014356:
            local_24 = local_24 & 0xff;
          }
          else {
            if ((local_24 & DAT_00014494 + 1) != 0xa0000000) {
              local_24 = *DAT_00014490;
              goto LAB_00014356;
            }
            local_24 = 0;
          }
          if (local_24 != 0) {
            local_20 = local_24;
          }
        }
        FUN_00014010();
      }
    }
    else {
      local_20 = 4;
    }
  }
  uVar14 = uVar14 + 0x100;
  uVar13 = uVar13 + 0x100;
  local_1b0 = DAT_00014488 + local_1b0 + 5;
  goto LAB_000141e2;
LAB_0001437a:
  local_1d8 = local_1d8 + local_1ac[0] + 0x80;
  iVar12 = iVar12 + 1;
  goto LAB_000140f0;
}

