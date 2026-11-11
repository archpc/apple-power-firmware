
void FUN_00011ea6(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  ushort *puVar11;
  uint uVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  uint uVar16;
  undefined1 *puStack00000020;
  undefined1 *puStack00000034;
  undefined1 *puStack00000038;
  undefined1 in_stack_00000048;
  int in_stack_0000005c;
  int in_stack_0000006c;
  int in_stack_00000070;
  int in_stack_00000074;
  undefined4 *puStack0000007c;
  undefined1 in_stack_00000080;
  ushort *in_stack_00000084;
  undefined4 *puStack00000088;
  int in_stack_0000008c;
  undefined1 in_stack_000000c0;
  undefined1 in_stack_000000c4;
  
  iVar15 = 0;
  if ((uint)((int)in_stack_00000084 << 5) <= DAT_0001223c) {
    in_stack_00000080 = 0;
  }
  *(undefined1 *)(in_stack_00000074 + in_stack_0000006c) = in_stack_00000080;
  *(short *)(in_stack_00000074 + 0x32) = (short)((int)in_stack_00000084 << 5);
  puStack00000020 = &stack0x000000c5;
  puStack00000034 = &stack0x000000c5;
  puStack00000038 = &stack0x000000c5;
LAB_00011ed0:
  if (iVar15 == 0x12) {
    FUN_00012b24();
  }
  if ((&stack0x00000090)[iVar15] != '\0') {
    uVar12 = (uint)*(byte *)(in_stack_00000074 + in_stack_0000006c);
    iVar13 = DAT_00012240 + 1;
    uVar3 = uVar12 * iVar13 + DAT_00012240;
    uVar1 = *(ushort *)(in_stack_00000074 + 0x32);
    uVar16 = (uint)uVar1;
    if ((uVar3 & 0xffff) < uVar16) {
      uVar9 = uVar12 + 1;
      *(char *)(in_stack_00000074 + in_stack_0000006c) = (char)uVar9;
      if (1 < (uVar9 & 0xff)) {
        uVar9 = 0;
        *(undefined1 *)(in_stack_00000074 + in_stack_0000006c) = 0;
        *(undefined2 *)(in_stack_00000074 + 0x32) = 0;
        uVar16 = 0;
      }
      if (uVar16 <= (iVar13 * (uVar9 & 0xff) + DAT_00012240 & 0xffff)) {
        *(ushort *)(in_stack_00000074 + 0x32) = (ushort)uVar16 + 0x20;
        in_stack_000000c4 = 0x1f;
        iVar4 = FUN_00009fac((uVar3 - 0x1f & 0xffff) + in_stack_0000008c,&stack0x000000c4,1);
        if (iVar4 == 0) {
          in_stack_000000c4 = 0x7f;
          iVar4 = uVar16 + in_stack_0000008c;
          iVar5 = FUN_00009fac(iVar4,&stack0x000000c4,1);
          if (iVar5 == 0) {
            iVar5 = DAT_0001223c + 0x20;
            puVar11 = (ushort *)(in_stack_00000070 + 0x20);
            puStack00000088 = DAT_00012248;
            for (iVar10 = 0; iVar10 != 0x12; iVar10 = iVar10 + 1) {
              if ((uVar12 * iVar5 + DAT_0001223c & DAT_00012244) == (uint)*puVar11) {
                in_stack_00000084 = (ushort *)(in_stack_00000070 + 0x20);
                iVar6 = 0;
                puStack0000007c = DAT_00012248;
                goto LAB_0001205a;
              }
              puVar11 = puVar11 + 1;
              puStack00000088 = puStack00000088 + 1;
            }
          }
        }
      }
    }
    else {
      *(ushort *)(in_stack_00000074 + 0x32) = uVar1 + 0x20;
      iVar4 = in_stack_00000070 + iVar15 * 2;
      in_stack_000000c4 = 0x1f;
      iVar13 = FUN_00009fac((uint)*(ushort *)(iVar4 + 0x20) + in_stack_0000008c,&stack0x000000c4,1);
      if ((iVar13 == 0) && (uVar16 != DAT_0001224c)) {
        puVar11 = (ushort *)(iVar4 + 0x20);
        uVar14 = DAT_00012248[iVar15];
        uVar2 = *puVar11;
        in_stack_000000c0 = 0x7f;
        iVar13 = uVar16 + in_stack_0000008c;
        iVar4 = FUN_00009fac(iVar13,&stack0x000000c0,1);
        if (iVar4 == 0) {
          FUN_000001a0(&stack0x000000c4,0xff);
          puStack00000038[3] = (char)((uint)uVar14 >> 0x18);
          puStack00000038[2] = (char)((uint)uVar14 >> 0x10);
          puStack00000038[1] = (char)((uint)uVar14 >> 8);
          *puStack00000038 = (char)uVar14;
          in_stack_000000c4 = (undefined1)iVar15;
          iVar4 = FUN_00009fac(iVar13 + 1,&stack0x000000c4,5);
          if ((iVar4 == 0) &&
             (in_stack_000000c0 = in_stack_00000048,
             iVar13 = FUN_00009fac(iVar13,&stack0x000000c0,1), iVar13 == 0)) {
            in_stack_000000c4 = 7;
            iVar13 = FUN_00009fac((uint)uVar2 + in_stack_0000008c,&stack0x000000c4,1);
            if (iVar13 == 0) {
              *puVar11 = uVar1;
              *(undefined1 *)(in_stack_0000005c + iVar15 + 0x10) = 0;
            }
          }
        }
      }
    }
    goto LAB_00011faa;
  }
  goto LAB_00011fb0;
LAB_0001205a:
  if (iVar6 == 0x12) goto LAB_00012180;
  if ((iVar10 != iVar6) && (uVar3 = (uint)*in_stack_00000084, uVar3 != DAT_0001224c)) {
    uVar9 = (uint)*(byte *)(in_stack_00000074 + in_stack_0000006c) * iVar5;
    if ((uVar3 < (uVar9 & 0xe000)) || ((DAT_0001223c + uVar9 + 0x1f & 0xffff) < uVar3)) {
      uVar1 = *(ushort *)(in_stack_00000074 + 0x32);
      uVar9 = (uint)uVar1;
      if ((iVar13 * (uint)*(byte *)(in_stack_00000074 + in_stack_0000006c) + DAT_00012240 & 0xffff)
          < uVar9) goto LAB_00011faa;
      *(ushort *)(in_stack_00000074 + 0x32) = uVar1 + 0x20;
      in_stack_000000c4 = 0x1f;
      iVar7 = FUN_00009fac(uVar3 + in_stack_0000008c,&stack0x000000c4,1);
      if ((iVar7 != 0) || (uVar9 == DAT_0001224c)) goto LAB_00011faa;
      uVar14 = *puStack0000007c;
      uVar2 = *in_stack_00000084;
      iVar7 = uVar9 + in_stack_0000008c;
      in_stack_000000c0 = 0x7f;
      iVar8 = FUN_00009fac(iVar7,&stack0x000000c0,1);
      if (iVar8 != 0) goto LAB_00011faa;
      FUN_000001a0(&stack0x000000c4,0xff);
      puStack00000034[3] = (char)((uint)uVar14 >> 0x18);
      puStack00000034[2] = (char)((uint)uVar14 >> 0x10);
      puStack00000034[1] = (char)((uint)uVar14 >> 8);
      *puStack00000034 = (char)uVar14;
      in_stack_000000c4 = (undefined1)iVar6;
      iVar8 = FUN_00009fac(iVar7 + 1,&stack0x000000c4,5);
      if (((iVar8 != 0) ||
          (in_stack_000000c0 = in_stack_00000048, iVar7 = FUN_00009fac(iVar7,&stack0x000000c0,1),
          iVar7 != 0)) ||
         (in_stack_000000c4 = 7,
         iVar7 = FUN_00009fac((uint)uVar2 + in_stack_0000008c,&stack0x000000c4,1), iVar7 != 0))
      goto LAB_00011faa;
      *in_stack_00000084 = uVar1;
      *(undefined1 *)(in_stack_0000005c + iVar6 + 0x10) = 0;
    }
  }
  in_stack_00000084 = in_stack_00000084 + 1;
  puStack0000007c = puStack0000007c + 1;
  iVar6 = iVar6 + 1;
  goto LAB_0001205a;
LAB_00012180:
  in_stack_000000c4 = 0x1f;
  iVar13 = FUN_00009fac((uint)*puVar11 + in_stack_0000008c,&stack0x000000c4,1);
  if (iVar13 == 0) {
    uVar14 = *puStack00000088;
    uVar1 = *puVar11;
    in_stack_000000c0 = 0x7f;
    iVar13 = FUN_00009fac(iVar4,&stack0x000000c0,1);
    if (iVar13 == 0) {
      FUN_000001a0(&stack0x000000c4,0xff);
      puStack00000020[3] = (char)((uint)uVar14 >> 0x18);
      puStack00000020[2] = (char)((uint)uVar14 >> 0x10);
      puStack00000020[1] = (char)((uint)uVar14 >> 8);
      *puStack00000020 = (char)uVar14;
      in_stack_000000c4 = (undefined1)iVar10;
      iVar13 = FUN_00009fac(iVar4 + 1,&stack0x000000c4,5);
      if (((iVar13 == 0) &&
          (in_stack_000000c0 = in_stack_00000048, iVar13 = FUN_00009fac(iVar4,&stack0x000000c0,1),
          iVar13 == 0)) &&
         (in_stack_000000c4 = 7,
         iVar13 = FUN_00009fac((uint)uVar1 + in_stack_0000008c,&stack0x000000c4,1), iVar13 == 0)) {
        *puVar11 = (ushort)uVar16;
        *(undefined1 *)(in_stack_0000005c + iVar10 + 0x10) = 0;
        if (uVar12 < 3) {
          FUN_0000a020(uVar12 * iVar5 + in_stack_0000008c,iVar5);
        }
      }
    }
  }
LAB_00011faa:
  (&stack0x00000090)[iVar15] = 0;
LAB_00011fb0:
  iVar15 = iVar15 + 1;
  goto LAB_00011ed0;
}

