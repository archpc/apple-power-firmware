
void FUN_00006df4(uint param_1,int param_2,uint param_3,uint param_4,uint param_5,uint param_6,
                 undefined4 *param_7)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  byte bVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  char *pcVar15;
  undefined4 *puVar16;
  uint local_50;
  uint local_48;
  uint local_38;
  uint local_30;
  uint local_2c;
  
  if ((param_1 < 2) && (iVar14 = DAT_00007154 + param_1 * 0x88, *(char *)(iVar14 + 0x73) != '\x01'))
  {
    puVar8 = (undefined1 *)(iVar14 + 0x73);
    iVar14 = DAT_00007154 + param_1 * 0x88;
    if (((*(char *)(iVar14 + 0x85) == '\0') || (param_4 == 0)) ||
       (((param_7 != (undefined4 *)0x0 && ((param_5 & 0x1ff) < 0x105)) &&
        (((param_5 & 0x8400) != 0x8000 ||
         ((uVar10 = (param_5 & 0x7fff) >> 0xb, uVar10 == 0 || (uVar10 * 0x1a < (param_5 & 0x1ff)))))
        )))) {
      pcVar15 = (char *)(iVar14 + 0x85);
      local_2c = param_6 & 7;
      *(char *)(iVar14 + 0x7b) = (char)local_2c;
      *(char *)(iVar14 + 0x7a) = (char)param_3;
      *(char *)(iVar14 + 0x74) = (char)param_2;
      *(char *)(iVar14 + 0x78) = (char)param_4;
      uVar3 = (ushort)param_5;
      *(ushort *)(iVar14 + 0x76) = uVar3;
      param_5 = DAT_00007150 & param_5;
      iVar12 = DAT_00007158 + param_1 * 0x1cc;
      bVar2 = *(byte *)(iVar12 + 0x3f);
      uVar10 = (uint)*(byte *)(iVar12 + 0x3e);
      uVar4 = 3;
      if ((1 < uVar10) && (*pcVar15 != '\0')) {
        if (param_4 == 0) {
          uVar4 = 2;
        }
        else {
          uVar4 = 0;
        }
        if ((short)uVar3 < 0) {
          uVar4 = 2;
        }
        if (param_5 < 0x1b) {
          uVar4 = 2;
        }
        if ((param_2 != 0) && (*(char *)(iVar12 + 0x10) != '\x02')) {
          if (*(char *)(iVar12 + 0x28) == '\0') {
            *puVar8 = 1;
            FUN_00006b70(param_1,0x20);
            return;
          }
          if (bVar2 < 2) {
            uVar4 = 3;
          }
        }
      }
      if (*(char *)(iVar14 + 0x72) == '\x01') {
        uVar4 = 0;
        *(undefined1 *)(iVar14 + 0x72) = 0;
      }
      if (*pcVar15 == '\0') {
        if (param_2 == 0) {
          uVar13 = (uint)*(byte *)(iVar12 + 0x14) << 5 | (uint)*(byte *)(iVar12 + 0x15) << 8;
        }
        else {
          uVar13 = 0x100;
        }
        bVar2 = *(byte *)(iVar14 + param_2 * 3 + 4);
        puVar16 = (undefined4 *)(iVar14 + 0x10);
        for (uVar5 = local_2c; uVar5 != 0; uVar5 = uVar5 - 1) {
          uVar6 = *param_7;
          param_7 = param_7 + 1;
          *puVar16 = uVar6;
          puVar16 = puVar16 + 1;
        }
        uVar13 = (uint)bVar2 << 9 | param_3 | uVar13 | local_2c << 0xc | 0x40;
        *(uint *)(iVar14 + 0x30) = uVar13;
        FUN_00008948(param_1,param_2,uVar4,local_2c,uVar13,0,iVar14 + 0x10);
      }
      else {
        local_30 = (uint)(short)uVar3;
        local_48 = 0;
        local_38 = (uint)((int)local_30 < 0);
        if (param_4 != 0) {
          local_38 = 1;
          if (param_5 < 0x1b) {
            uVar3 = uVar3 | 0x8000;
          }
          local_30 = (uint)(short)uVar3;
          if ((int)local_30 < 0) {
            if ((int)(local_30 << 0x15) < 0) {
              local_30 = local_30 & 0xfe00;
              local_48 = 0;
            }
            else {
              uVar13 = (local_30 & 0x7fff) >> 0xb;
              if (param_5 < uVar13 * 0x1a + 0x1a) {
                local_48 = uVar13 * -0x1a + param_5;
              }
              else {
                local_48 = 0x1a;
              }
            }
            local_2c = FUN_00008d62((local_48 & 0xffff) + 2);
          }
          else {
            local_2c = 0;
            local_38 = 0;
            local_48 = param_5;
          }
        }
        if (param_2 == 0) {
          local_50 = (uint)*(byte *)(iVar12 + 0x14) << 5 |
                     uVar10 << 6 | (uint)*(byte *)(iVar12 + 0x15) << 8;
        }
        else {
          local_50 = (uint)bVar2 << 6 | 0x100;
        }
        bVar2 = *(byte *)(iVar14 + param_2 * 3 + 4);
        puVar16 = (undefined4 *)(iVar14 + 0x10);
        bVar1 = *(byte *)(iVar14 + 0x7a);
        uVar13 = 0;
        FUN_000001a2(puVar16,0,0x20);
        if ((local_38 & param_4) == 1) {
          *(short *)puVar16 = (short)local_30;
          uVar13 = 2;
          bVar7 = (byte)local_48;
        }
        else {
          bVar7 = (byte)(local_2c << 2);
        }
        uVar11 = (local_2c & 0xff) << 0xc | (uint)(param_4 != 0) * 0x8000 | local_50 | (uint)bVar1 |
                 (uint)bVar2 << 9;
        puVar9 = param_7;
        for (uVar5 = (uint)bVar7; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined1 *)((int)puVar16 + (uVar13 & 0xff)) = *(undefined1 *)puVar9;
          puVar9 = (undefined4 *)((int)puVar9 + 1);
          uVar13 = uVar13 + 1;
        }
        uVar6 = 0;
        if ((param_4 != 0) && (local_38 == 0)) {
          uVar11 = uVar11 | local_30 << 0x10;
          local_2c = FUN_00008d62(local_48 & 0xffff);
          uVar6 = 1;
          puVar16 = param_7;
        }
        *(uint *)(iVar14 + 0x30) = uVar11;
        FUN_00008948(param_1,param_2,uVar4,local_2c & 0xff,uVar11,uVar6,puVar16);
      }
      uVar4 = FUN_00000b50();
      *puVar8 = 1;
      iVar12 = FUN_00006b34(param_1);
      if (iVar12 == 0) {
        if ((((*(byte *)(iVar14 + 0x71) - 1 < 2) || (*(char *)(iVar14 + 0x79) == '\x06')) &&
            ((param_2 - 1U & 0xff) < 2)) && ((uVar10 < 2 || (*pcVar15 == '\0')))) {
          FUN_0000c78c(param_1,4,2,DAT_0000715c);
        }
        else {
          FUN_000089b8(param_1);
        }
      }
    }
    else {
      uVar4 = FUN_00000b50();
      *puVar8 = 1;
      FUN_00006b70(param_1,0x10);
    }
    FUN_00000b58(uVar4);
  }
  return;
}

