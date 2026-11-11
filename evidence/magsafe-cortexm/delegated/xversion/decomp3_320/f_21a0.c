
/* WARNING: Removing unreachable block (ram,0x00002b3a) */
/* WARNING: Removing unreachable block (ram,0x00002ae6) */

uint FUN_000021a0(int param_1)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  short sVar4;
  undefined1 uVar5;
  ushort uVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  uint *puVar13;
  undefined *puVar14;
  byte *pbVar15;
  int *piVar16;
  uint uVar17;
  undefined **ppuVar18;
  byte *extraout_r2;
  code *pcVar19;
  int extraout_r3;
  int iVar20;
  undefined *puVar21;
  uint uVar22;
  undefined **ppuVar23;
  char cVar24;
  uint uVar25;
  undefined *puVar26;
  bool bVar27;
  uint uStack_78;
  uint local_74;
  undefined **local_70;
  undefined *local_6c;
  uint local_68;
  undefined **local_64;
  ushort local_40 [8];
  int local_30;
  
  iVar20 = DAT_000025a8;
  uVar22 = DAT_000025a4 + param_1 * 0x1cc;
  if (*(char *)(uVar22 + 0x31) == '\0') {
    if (*(byte *)(uVar22 + 0x33) != 1) {
      return (uint)*(byte *)(uVar22 + 0x33);
    }
    *(undefined1 *)(uVar22 + 0x33) = 0;
    FUN_00007d68(param_1);
    uVar22 = FUN_00003008(param_1);
    return uVar22;
  }
  ppuVar23 = (undefined **)(uint)*(byte *)(uVar22 + 0x2d);
  cVar7 = *(char *)(uVar22 + 0x19);
  pbVar15 = (byte *)(uVar22 + 0x2d);
  piVar16 = (int *)(uVar22 + 0x60);
  if (*(char *)(uVar22 + 0x25) == '\0') {
    bVar2 = *(byte *)(uVar22 + 0x1a);
    iVar8 = *(int *)(uVar22 + 0x60);
    uVar11 = FUN_000088d4(param_1);
    local_6c = (undefined *)(uVar11 >> 8);
    uVar5 = (undefined1)(uVar11 >> 8);
    *(undefined1 *)(uVar22 + 0x37) = uVar5;
    *(char *)(uVar22 + 0x36) = (char)uVar11;
    bVar27 = true;
    local_68 = 1;
    if ((ppuVar23 != (undefined **)0x3) && (bVar27 = true, ppuVar23 != (undefined **)0x4)) {
      FUN_00007db4(param_1,uVar11 & 0xffff,0x11);
      FUN_00007db4(param_1,uVar11 & 0xffff,0x12);
      bVar27 = false;
    }
    iVar9 = FUN_00007ebc(param_1,uVar11 & 0xffff);
    uVar3 = *(ushort *)(uVar22 + 0x38);
    uVar17 = (uint)uVar3;
    local_40[0] = uVar3;
    cVar1 = *(char *)((int)local_40 + (uint)bVar2);
    ppuVar18 = (undefined **)(uVar22 + 0x1c);
    local_64 = ppuVar23;
    if (*(char *)(uVar22 + 0x1c) == '\0') {
      if (cVar7 == '\0') {
        if (bVar27) {
          if (iVar9 != 0) {
            if (ppuVar23 == (undefined **)0x3) {
              FUN_00007d9c(param_1,0);
              FUN_00007d9c(param_1,1);
              FUN_0000c9fc(param_1,0x15,10);
            }
            FUN_00007924(param_1,2);
            *(undefined1 *)(uVar22 + 0x19) = 0;
            FUN_00007b7c(param_1);
          }
        }
        else {
          local_74 = uVar17;
          if (*(char *)(uVar22 + 0x15) == '\0') {
            if ((uVar11 & 0xffff) == 0) {
              iVar8 = iVar20 + param_1 * 0xb;
              if (*(char *)(iVar8 + 1) == '\0') {
                *(undefined1 *)(iVar8 + 1) = 1;
                FUN_0000c9fc(param_1,0x13,0xc);
              }
              else {
                iVar8 = FUN_0000ca50(param_1,0x13);
                if (iVar8 == 0) {
                  *(undefined2 *)(uVar22 + 0x3c) = 0;
                }
              }
            }
            else {
              *(short *)(uVar22 + 0x3c) = (short)uVar11;
              FUN_0000ca08(param_1,0x13);
              *(undefined1 *)(iVar20 + param_1 * 0xb + 1) = 0;
            }
            sVar4 = *(short *)(uVar22 + 0x3c);
            iVar8 = FUN_000079ac(param_1);
            uVar25 = (uint)(iVar9 == 0);
            if (iVar8 == 0) {
              uVar25 = local_68;
            }
            if (uVar25 == 0) {
              uVar6 = uVar3 >> 8;
              if ((2 < (uVar11 & 0xff) - 1) || (uVar6 != 0)) {
                if (((2 < (uVar11 - 0x100 & 0xffff) >> 8) || ((uVar3 & 0xff) != 0)) &&
                   (((2 < (uVar17 & 0xff) - 1 || (uVar6 == 0)) || (3 < uVar6)))) goto LAB_00002466;
              }
              *(undefined1 *)(uVar22 + 0x39) = uVar5;
              *(char *)(uVar22 + 0x38) = (char)uVar11;
              *(byte *)ppuVar18 = 1;
              uVar12 = 8;
              local_70 = ppuVar18;
              goto LAB_000024ac;
            }
LAB_00002466:
            local_70 = ppuVar18;
            if (sVar4 == 0) {
              FUN_00007b7c(param_1);
              goto LAB_00002492;
            }
          }
          else {
            iVar10 = FUN_00007ebc(param_1);
            if (iVar10 == 1) {
              FUN_0000ca08(param_1,0x15);
              local_70 = ppuVar18;
              if (uVar17 == *(ushort *)(uVar22 + 0x3a)) {
                iVar9 = (**(code **)(iVar8 + 0x20))(param_1,800,0);
                if (iVar9 == 0) {
                  *(undefined1 *)(iVar20 + param_1 * 0xb + 7) = 0;
                  (**(code **)(iVar8 + 0x28))(param_1);
                  FUN_0000ca08(param_1,0x14);
                  *(byte *)ppuVar18 = 1;
                  if (*(char *)(uVar22 + 0x44) == '\0') {
                    uVar12 = 8;
                    goto LAB_000024ac;
                  }
                  *pbVar15 = 8;
                }
                else {
                  iVar9 = iVar20 + param_1 * 0xb;
                  if (*(char *)(iVar9 + 3) == '\0') {
                    if (*(char *)(iVar9 + 7) == '\0') {
                      *(undefined1 *)(iVar9 + 7) = 1;
                      (**(code **)(iVar8 + 0x24))(param_1);
                      FUN_0000c9fc(param_1,0x14,0x32);
                    }
                    else {
                      iVar10 = FUN_0000ca50(param_1,0x14);
                      if (iVar10 == 0) {
                        *(undefined1 *)(iVar9 + 7) = 0;
                        (**(code **)(iVar8 + 0x28))(param_1);
                        (**(code **)*piVar16)(param_1,0,0);
                        *(undefined1 *)(iVar9 + 3) = 1;
                      }
                    }
                  }
                }
              }
            }
            else {
              local_70 = ppuVar18;
              if ((iVar9 == 0) &&
                 ((iVar8 = FUN_0000ca50(param_1,0x15), iVar8 == 0 || ((uVar11 & 0xffff) == 0x202))))
              {
LAB_00002492:
                FUN_00007f24(param_1);
                pcVar19 = *(code **)*piVar16;
                uVar12 = 0x22;
                goto LAB_00002398;
              }
            }
          }
        }
      }
    }
    else if (*(char *)(uVar22 + 0x15) == '\0') {
      if (*(char *)(uVar22 + 0x42) == '\0') {
        if (cVar7 == '\0') {
          cVar7 = FUN_00002d54(param_1);
          if (cVar1 == '\0') {
            *(undefined1 *)(iVar20 + param_1 * 0xb + (uint)*(byte *)(uVar22 + 0x1a) + 8) = 0;
            (**(code **)*piVar16)(param_1,0x37);
            cVar7 = -5;
          }
          cVar24 = '\x05';
          do {
            if (cVar24 == '\0') {
              *(byte *)ppuVar18 = 0;
              goto LAB_000024a8;
            }
            pcVar19 = *(code **)(iVar8 + 0x20);
            uVar12 = FUN_00002d70(param_1);
            iVar9 = (*pcVar19)(param_1,uVar12,(int)cVar7);
            cVar24 = cVar24 + -1;
          } while (iVar9 == 0);
        }
      }
      else if (cVar1 == '\0') {
        *(byte *)ppuVar18 = 0;
        *(undefined1 *)(uVar22 + 0x42) = 0;
LAB_000024a8:
        uVar12 = 4;
        local_70 = ppuVar18;
        goto LAB_000024ac;
      }
      local_70 = ppuVar18;
      if (*(char *)(uVar22 + 0x16) != cVar1) {
        *(char *)(uVar22 + 0x16) = cVar1;
        FUN_00008d54(param_1);
        pcVar19 = *(code **)*piVar16;
        uVar12 = 9;
LAB_00002398:
        (*pcVar19)(param_1,uVar12,0);
        local_70 = ppuVar18;
      }
    }
    else if ((cVar7 == '\0') &&
            ((cVar1 == '\x02' ||
             ((*(char *)(uVar22 + 0x1f) == '\x04' &&
              ((cVar1 != '\0' || (*(char *)((int)local_40 + (uint)(bVar2 == 0)) != '\0')))))))) {
      FUN_0000ca08(param_1,0xf);
      *(byte *)ppuVar18 = 0;
      uVar12 = 4;
LAB_000024ac:
      FUN_00002a18(param_1,uVar12);
    }
  }
  uVar11 = FUN_00008efc(uVar22 + 0x4c);
  if (uVar11 < 8) {
    if (uVar11 == 0) {
      FUN_00007924(param_1,1);
    }
    else if (uVar11 == 7) {
      uVar12 = FUN_00000b70();
      uVar11 = (uint)*(byte *)(uVar22 + 0x34);
      if (uVar11 < 3) {
        bVar2 = *(byte *)(DAT_000028a0 + uVar11);
        *(byte *)(uVar22 + 2) = bVar2;
        if ((*pbVar15 != 3) && (*(char *)(uVar22 + 0x20) == '\0')) {
          if ((*(char *)(uVar22 + 0x1d) != '\0') && (*(char *)(uVar22 + 0x15) == '\x01')) {
            if (bVar2 < *(byte *)(uVar22 + 0x35)) {
              FUN_0000c908(param_1,0x16,0,DAT_000028a4);
            }
            else {
              (**(code **)(*piVar16 + 8))(param_1,300);
            }
          }
          FUN_00007a14(param_1,*(undefined1 *)(uVar22 + 2));
        }
        FUN_00007c50(param_1,1);
        uVar11 = (uint)*(byte *)(uVar22 + 0x34);
      }
      if (uVar11 - 3 < 2) {
        if (uVar11 == 3) {
          *(undefined1 *)(iVar20 + param_1 * 0xb + 4) = 1;
        }
        FUN_00002a18(param_1,1);
      }
      FUN_00000b78(uVar12);
    }
    else {
      (**(code **)(DAT_000028a8 + (uint)*pbVar15 * 4))(param_1);
    }
  }
  if (*(char *)(uVar22 + 0x45) == '\0') {
    return 0;
  }
  if (*(int *)(uVar22 + 0x48) == 0) goto LAB_000027b4;
  piVar16 = (int *)(uVar22 + 0x48);
  uVar11 = 0x175;
  if (*(char *)(uVar22 + 0x175) != '\0') {
    cVar7 = *(char *)(uVar22 + 0x15);
    if (cVar7 == '\x01') {
      if (-1 < *piVar16 << 0x1c) goto LAB_0000264c;
      FUN_000030f0(param_1,0xd,900);
      cVar7 = *(char *)(uVar22 + 0x15);
    }
    if ((cVar7 == '\0') && ((*piVar16 << 0x1c < 0 || (*piVar16 << 0x19 < 0)))) {
      FUN_00003100(param_1);
    }
  }
LAB_0000264c:
  if ((*piVar16 << 0x16 < 0) && (*(char *)(uVar22 + 0x2e) == '\x05')) {
    FUN_00003140(param_1);
  }
  puVar13 = (uint *)FUN_00008efc(piVar16);
  if (puVar13 < (uint *)((int)&NMI + 2U)) {
    bVar27 = ((uint)puVar13 & 0x3fffffff) == 0;
    ppuVar23 = &switchD_0000267a::switchdataD_0000267c;
    puVar14 = (&switchD_0000267a::switchdataD_0000267c)[(int)puVar13];
    pbVar15 = extraout_r2;
    iVar20 = extraout_r3;
    uVar17 = uVar11;
    switch(puVar13) {
    case (uint *)0x0:
      pbVar15 = extraout_r2 + 0x3e;
      local_64 = &switchD_0000267a::switchdataD_0000267c;
      ppuVar23 = (undefined **)((int)&PTR_caseD_2_00002684 + 2);
      iVar20 = 0x7d;
switchD_0000267a_caseD_9:
      puVar14 = (undefined *)(iVar20 << 3);
      uStack_78 = 1;
      local_74 = 0x175;
      local_70 = ppuVar23;
      local_6c = puVar14;
      break;
    case (uint *)0x1:
    case (uint *)0x6:
      return uVar22;
    default:
      goto switchD_0000267a_caseD_2;
    case (uint *)0x9:
      goto switchD_0000267a_caseD_9;
    }
    do {
      bVar27 = uVar11 == 7;
      uVar22 = uVar11;
switchD_0000267a_caseD_2:
      if (bVar27) {
        if (uVar17 < 7) {
          ppuVar18 = local_64 + uVar17 + 0x27;
          for (uVar22 = uVar17; uVar22 < 7; uVar22 = uVar22 + 1) {
            *ppuVar18 = (undefined *)0x0;
            ppuVar18 = ppuVar18 + 1;
          }
        }
        *(byte *)((int)local_64 + 0x15b) = (byte)local_74 & 1;
        *(char *)((int)local_64 + 0x29) = (char)uVar17;
        uVar22 = DAT_00002d48;
        if (1 < *pbVar15) {
          uVar22 = DAT_00002d4c;
        }
        local_64[0x27] =
             (undefined *)
             ((uint)(*(byte *)ppuVar23 >> 7) * 0x8000000 + ((uint)local_64[0x27] & 0xf7ffffff) &
             uVar22);
        return 0x9c;
      }
      if (((*(byte *)ppuVar23 >> (uVar22 & 0xff) & 1) != 0) &&
         ((puVar21 = (undefined *)*puVar13, 1 < *pbVar15 || ((uint)puVar21 >> 0x1e < 3)))) {
        uVar11 = (uint)puVar21 >> 0x1e;
        puVar26 = puVar21;
        if (uVar11 == 2) {
          if (local_68 + 0x28 < ((uint)(puVar14 + 0x17) & (uint)puVar21)) {
            puVar26 = (undefined *)((uint)puVar21 & DAT_00002d3c | local_68 + 0x28);
LAB_00002c7a:
            local_74 = uStack_78;
          }
        }
        else if (uVar11 == 1) {
          uVar11 = (int)puVar14 * ((uint)puVar21 >> 10 & (uint)(puVar14 + 0x17));
          if (uVar11 < ((uint)(puVar14 + 0x17) & (uint)puVar21)) {
            local_74 = uStack_78;
            puVar26 = (undefined *)(uVar11 & (uint)(puVar14 + 0x10) | (uint)puVar21 & DAT_00002d3c);
          }
        }
        else if (uVar11 == 0) {
          if (local_68 + 0x28 < ((uint)(puVar14 + 0x17) & (uint)puVar21)) {
            puVar26 = (undefined *)(local_68 + ((uint)puVar21 & DAT_00002d44) + 0x28);
            goto LAB_00002c7a;
          }
          uVar11 = ((uint)(puVar14 + 0x17) & (uint)puVar21) * 0x6e;
          if (DAT_00002d40 <= uVar11 && uVar11 - DAT_00002d40 != 0) {
            puVar26 = (undefined *)((uint)puVar21 & 0xffcfffff);
          }
          if (((uint)puVar21 & 0x3fffff) >> 0x14 == 0) {
            puVar26 = puVar21;
          }
        }
        local_64[uVar17 + 0x27] = puVar26;
        uVar17 = uVar17 + 1;
        puVar14 = local_6c;
        ppuVar23 = local_70;
      }
      puVar13 = puVar13 + 1;
      uVar11 = uVar22 + 1;
    } while( true );
  }
  (**(code **)(DAT_000028b4 + (uint)*(byte *)(uVar22 + 0x45) * 4))(param_1,puVar13);
LAB_000027b4:
  uVar11 = (uint)*(byte *)(uVar22 + 0x3e);
  if (1 < uVar11) {
    local_30 = *(int *)(uVar22 + 0x58);
    uVar11 = 0;
    if ((local_30 != 0) && (uVar11 = FUN_0000290c(param_1,0x11,local_40,0), uVar11 == 0)) {
      *(undefined4 *)(uVar22 + 0x58) = 0;
    }
  }
  return uVar11;
}

