
void FUN_00013dc8(void)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
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
  undefined4 local_1c;
  undefined4 local_18;
  
  *DAT_00014134 = 0x2000;
  *DAT_00014138 = DAT_0001413c;
  *DAT_00014140 = 2;
  FUN_000141e0(0x17);
  FUN_000141e0(0x21,1);
  puVar2 = DAT_00014144;
  *DAT_00014144 = 0xc;
  *puVar2 = DAT_00014148 | *puVar2;
  puVar2[0x10] = 0;
  puVar2[0x12] = 0xa0000;
  *DAT_0001414c = 0x80000007;
  puVar2[0x11] = 1;
  puVar3 = DAT_00014150;
  *DAT_00014150 = 0x80000007;
  puVar3[1] = 4;
  puVar2[0x14] = 4;
  puVar3 = DAT_00014154;
  *DAT_00014154 = 0;
  puVar3[0x10] = 0;
  puVar3 = DAT_00014158;
  DAT_00014158[0x10] = 0;
  *puVar3 = 0;
  puVar3 = DAT_0001415c;
  DAT_0001415c[0x10] = 0;
  *puVar3 = 0;
  *puVar2 = *puVar2 | 0x80000000;
  *DAT_00014160 = DAT_00014164;
  *DAT_00014168 = 0xffffffff;
  FUN_00013da4(DAT_0001416c);
  (*pcRam000003f0)(local_12c,0x1000,0x100);
  iVar6 = (*pcRam000003ec)(local_12c,0xfc);
  if (iVar6 != local_30) {
LAB_000140b2:
    puVar3 = DAT_0001418c;
    *DAT_0001418c = 6;
    FUN_000141b8();
    *puVar3 = 0x20;
    *puVar3 = 0;
    *puVar3 = 0x10;
    *puVar3 = 0;
    FUN_000141b8();
    puVar2 = DAT_00014194;
    uVar10 = DAT_00014190;
    while( true ) {
      *puVar2 = *puVar2 | uVar10 + 5;
      *puVar2 = *puVar2 & 0xfffeffff;
      *puVar3 = 5;
      *puVar3 = 0;
      FUN_000141b8();
      if ((puVar2[0xf] & 1) == 0) break;
      FUN_00013da4(0x1e0);
    }
    *DAT_00014198 = 0x80000000;
    FUN_00013da4(0x12c0);
    *DAT_0001419c = *DAT_0001419c | 0x300000;
    FUN_00013da4(DAT_000141a0);
    *DAT_000141a4 = DAT_000141a8 | *DAT_000141a4 & uVar10;
    return;
  }
  iVar6 = 0x20000;
  if (local_118 != 0) {
    iVar6 = local_11c;
  }
  iVar16 = iVar6 + 0x100;
  iVar7 = 0;
LAB_00013ea0:
  if (iVar7 != 4) {
    (*pcRam000003f0)(local_1ac,iVar16,0x80);
    iVar13 = local_130;
    iVar8 = (*pcRam000003ec)(local_1ac,0x7c);
    iVar17 = DAT_000141ac;
    if (iVar8 == iVar13) {
      FUN_000143a0(DAT_000141ac,iVar16,local_1ac[0] + 0x80);
      for (iVar13 = 0; iVar13 != 4; iVar13 = iVar13 + 1) {
        (*pcRam000003f0)(local_12c,iVar6 + 8 + iVar13 * 0x24);
        iVar8 = 0;
        do {
          if (iVar8 + 4 == 0x24) {
            if (local_1a0 >> 0x18 != 0) goto LAB_000140a4;
            uVar10 = local_1ac[0] + local_1a0;
            uVar15 = local_1a0 - 0x80;
            iVar17 = iVar16;
            goto LAB_00013f1c;
          }
          iVar1 = iVar8 + -4;
          iVar9 = iVar17 + iVar8;
          iVar8 = iVar8 + 4;
        } while (*(int *)(iVar9 + 0x48) == *(int *)(auStack_124 + iVar1));
      }
    }
  }
  goto LAB_000140b2;
LAB_00013f1c:
  uVar5 = DAT_000141b0;
  if (uVar10 <= uVar15) goto LAB_000140a4;
  (*pcRam000003f0)(DAT_000141b0,iVar17,0x100);
  iVar13 = FUN_00013d86(uVar5,uVar15,0x100);
  if (iVar13 != 0) {
    uVar14 = 0;
    local_20 = 0;
    local_24 = 0;
    if (uVar15 < 0x20000) {
      FUN_00013d44(auStack_124,DAT_000141b0,0x100);
      puVar2 = DAT_00014170;
      local_12c[0] = DAT_00014178;
      local_12c[1] = 0xff;
      *DAT_00014170 = (uint)local_12c;
      puVar12 = puVar2 + -1;
      *puVar12 = 0x80000004;
      uVar11 = *puVar2;
      if (DAT_00014174 < *puVar2) {
LAB_00013f8a:
        uVar14 = uVar11 & 0xff;
      }
      else if ((uVar11 & DAT_00014174 + 1) != 0xa0000000) {
        uVar11 = *DAT_00014170;
        goto LAB_00013f8a;
      }
      local_20 = uVar14;
      if (uVar14 == 0) {
        FUN_00013db8();
        local_18 = DAT_000141b4;
        puVar2 = DAT_00014170;
        local_1c = DAT_0001417c;
        *DAT_00014170 = (uint)&local_1c;
        *puVar12 = 0x80000016;
        puVar4 = DAT_00014170;
        local_24 = *puVar2;
        if (DAT_00014174 < *puVar2) {
LAB_00013fd4:
          local_24 = local_24 & 0xff;
        }
        else {
          if ((local_24 & DAT_00014174 + 1) != 0xa0000000) {
            local_24 = *DAT_00014170;
            goto LAB_00013fd4;
          }
          local_24 = 0;
        }
        if (local_24 == 0) {
          *DAT_00014170 = DAT_00014180;
          *puVar12 = 0x80000015;
          local_20 = *puVar4;
          if (*puVar4 <= DAT_00014174) {
            if ((local_20 & DAT_00014174 + 1) == 0xa0000000) {
              local_20 = 0;
              goto LAB_0001400e;
            }
            local_20 = *DAT_00014170;
          }
          local_20 = local_20 & 0xff;
        }
LAB_0001400e:
        puVar2 = DAT_00014170;
        if (local_20 == 0) {
          local_12c[0] = DAT_00014184 | (uVar15 >> 8) << 0x10;
          *DAT_00014170 = (uint)local_12c;
          *puVar12 = 0x80000005;
          local_20 = *puVar2;
          if (*puVar2 <= DAT_00014174) {
            if ((local_20 & DAT_00014174 + 1) == 0xa0000000) {
              local_20 = 0;
              goto LAB_00014052;
            }
            local_20 = *DAT_00014170;
          }
          local_20 = local_20 & 0xff;
        }
LAB_00014052:
        puVar2 = DAT_00014170;
        if (local_24 == 0) {
          local_1c = DAT_00014188;
          *DAT_00014170 = (uint)&local_1c;
          *puVar12 = 0x80000017;
          local_24 = *puVar2;
          if (DAT_00014174 < *puVar2) {
LAB_0001408a:
            local_24 = local_24 & 0xff;
          }
          else {
            if ((local_24 & DAT_00014174 + 1) != 0xa0000000) {
              local_24 = *DAT_00014170;
              goto LAB_0001408a;
            }
            local_24 = 0;
          }
          if (local_24 != 0) {
            local_20 = local_24;
          }
        }
        FUN_00013dc0();
      }
    }
    else {
      local_20 = 4;
    }
  }
  iVar17 = iVar17 + 0x100;
  uVar15 = uVar15 + 0x100;
  goto LAB_00013f1c;
LAB_000140a4:
  iVar16 = iVar16 + local_1ac[0] + 0x80;
  iVar7 = iVar7 + 1;
  goto LAB_00013ea0;
}

