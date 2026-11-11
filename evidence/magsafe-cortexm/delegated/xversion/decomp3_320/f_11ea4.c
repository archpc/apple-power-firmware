
void FUN_00011ea4(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  ushort *puVar12;
  int unaff_r4;
  uint uVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  uint uVar17;
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
  undefined4 *puStack00000088;
  int in_stack_0000008c;
  undefined1 in_stack_000000c0;
  undefined1 in_stack_000000c4;
  
  iVar16 = 0;
  if ((uint)(unaff_r4 << 5) <= DAT_0001223c) {
    in_stack_00000080 = 0;
  }
  *(undefined1 *)(in_stack_00000074 + in_stack_0000006c) = in_stack_00000080;
  *(short *)(in_stack_00000074 + 0x32) = (short)(unaff_r4 << 5);
  puStack00000020 = &stack0x000000c5;
  puStack00000034 = &stack0x000000c5;
  puStack00000038 = &stack0x000000c5;
LAB_00011ed0:
  if (iVar16 == 0x12) {
    FUN_00012b24();
  }
  if ((&stack0x00000090)[iVar16] != '\0') {
    uVar13 = (uint)*(byte *)(in_stack_00000074 + in_stack_0000006c);
    iVar14 = DAT_00012240 + 1;
    uVar3 = uVar13 * iVar14 + DAT_00012240;
    uVar1 = *(ushort *)(in_stack_00000074 + 0x32);
    uVar17 = (uint)uVar1;
    if ((uVar3 & 0xffff) < uVar17) {
      uVar10 = uVar13 + 1;
      *(char *)(in_stack_00000074 + in_stack_0000006c) = (char)uVar10;
      if (1 < (uVar10 & 0xff)) {
        uVar10 = 0;
        *(undefined1 *)(in_stack_00000074 + in_stack_0000006c) = 0;
        *(undefined2 *)(in_stack_00000074 + 0x32) = 0;
        uVar17 = 0;
      }
      if (uVar17 <= (iVar14 * (uVar10 & 0xff) + DAT_00012240 & 0xffff)) {
        *(ushort *)(in_stack_00000074 + 0x32) = (ushort)uVar17 + 0x20;
        in_stack_000000c4 = 0x1f;
        iVar4 = FUN_00009fac((uVar3 - 0x1f & 0xffff) + in_stack_0000008c,&stack0x000000c4,1);
        if (iVar4 == 0) {
          in_stack_000000c4 = 0x7f;
          iVar4 = uVar17 + in_stack_0000008c;
          iVar5 = FUN_00009fac(iVar4,&stack0x000000c4,1);
          if (iVar5 == 0) {
            iVar5 = DAT_0001223c + 0x20;
            puVar12 = (ushort *)(in_stack_00000070 + 0x20);
            puStack00000088 = DAT_00012248;
            for (iVar11 = 0; iVar11 != 0x12; iVar11 = iVar11 + 1) {
              if ((uVar13 * iVar5 + DAT_0001223c & DAT_00012244) == (uint)*puVar12) {
                puVar6 = (ushort *)(in_stack_00000070 + 0x20);
                iVar7 = 0;
                puStack0000007c = DAT_00012248;
                goto LAB_0001205a;
              }
              puVar12 = puVar12 + 1;
              puStack00000088 = puStack00000088 + 1;
            }
          }
        }
      }
    }
    else {
      *(ushort *)(in_stack_00000074 + 0x32) = uVar1 + 0x20;
      iVar4 = in_stack_00000070 + iVar16 * 2;
      in_stack_000000c4 = 0x1f;
      iVar14 = FUN_00009fac((uint)*(ushort *)(iVar4 + 0x20) + in_stack_0000008c,&stack0x000000c4,1);
      if ((iVar14 == 0) && (uVar17 != DAT_0001224c)) {
        puVar12 = (ushort *)(iVar4 + 0x20);
        uVar15 = DAT_00012248[iVar16];
        uVar2 = *puVar12;
        in_stack_000000c0 = 0x7f;
        iVar14 = uVar17 + in_stack_0000008c;
        iVar4 = FUN_00009fac(iVar14,&stack0x000000c0,1);
        if (iVar4 == 0) {
          FUN_000001a0(&stack0x000000c4,0xff);
          puStack00000038[3] = (char)((uint)uVar15 >> 0x18);
          puStack00000038[2] = (char)((uint)uVar15 >> 0x10);
          puStack00000038[1] = (char)((uint)uVar15 >> 8);
          *puStack00000038 = (char)uVar15;
          in_stack_000000c4 = (undefined1)iVar16;
          iVar4 = FUN_00009fac(iVar14 + 1,&stack0x000000c4,5);
          if ((iVar4 == 0) &&
             (in_stack_000000c0 = in_stack_00000048,
             iVar14 = FUN_00009fac(iVar14,&stack0x000000c0,1), iVar14 == 0)) {
            in_stack_000000c4 = 7;
            iVar14 = FUN_00009fac((uint)uVar2 + in_stack_0000008c,&stack0x000000c4,1);
            if (iVar14 == 0) {
              *puVar12 = uVar1;
              *(undefined1 *)(in_stack_0000005c + iVar16 + 0x10) = 0;
            }
          }
        }
      }
    }
    goto LAB_00011faa;
  }
  goto LAB_00011fb0;
LAB_0001205a:
  if (iVar7 == 0x12) goto LAB_00012180;
  if ((iVar11 != iVar7) && (uVar3 = (uint)*puVar6, uVar3 != DAT_0001224c)) {
    uVar10 = (uint)*(byte *)(in_stack_00000074 + in_stack_0000006c) * iVar5;
    if ((uVar3 < (uVar10 & 0xe000)) || ((DAT_0001223c + uVar10 + 0x1f & 0xffff) < uVar3)) {
      uVar1 = *(ushort *)(in_stack_00000074 + 0x32);
      uVar10 = (uint)uVar1;
      if ((iVar14 * (uint)*(byte *)(in_stack_00000074 + in_stack_0000006c) + DAT_00012240 & 0xffff)
          < uVar10) goto LAB_00011faa;
      *(ushort *)(in_stack_00000074 + 0x32) = uVar1 + 0x20;
      in_stack_000000c4 = 0x1f;
      iVar8 = FUN_00009fac(uVar3 + in_stack_0000008c,&stack0x000000c4,1);
      if ((iVar8 != 0) || (uVar10 == DAT_0001224c)) goto LAB_00011faa;
      uVar15 = *puStack0000007c;
      uVar2 = *puVar6;
      iVar8 = uVar10 + in_stack_0000008c;
      in_stack_000000c0 = 0x7f;
      iVar9 = FUN_00009fac(iVar8,&stack0x000000c0,1);
      if (iVar9 != 0) goto LAB_00011faa;
      FUN_000001a0(&stack0x000000c4,0xff);
      puStack00000034[3] = (char)((uint)uVar15 >> 0x18);
      puStack00000034[2] = (char)((uint)uVar15 >> 0x10);
      puStack00000034[1] = (char)((uint)uVar15 >> 8);
      *puStack00000034 = (char)uVar15;
      in_stack_000000c4 = (undefined1)iVar7;
      iVar9 = FUN_00009fac(iVar8 + 1,&stack0x000000c4,5);
      if (((iVar9 != 0) ||
          (in_stack_000000c0 = in_stack_00000048, iVar8 = FUN_00009fac(iVar8,&stack0x000000c0,1),
          iVar8 != 0)) ||
         (in_stack_000000c4 = 7,
         iVar8 = FUN_00009fac((uint)uVar2 + in_stack_0000008c,&stack0x000000c4,1), iVar8 != 0))
      goto LAB_00011faa;
      *puVar6 = uVar1;
      *(undefined1 *)(in_stack_0000005c + iVar7 + 0x10) = 0;
    }
  }
  puVar6 = puVar6 + 1;
  puStack0000007c = puStack0000007c + 1;
  iVar7 = iVar7 + 1;
  goto LAB_0001205a;
LAB_00012180:
  in_stack_000000c4 = 0x1f;
  iVar14 = FUN_00009fac((uint)*puVar12 + in_stack_0000008c,&stack0x000000c4,1);
  if (iVar14 == 0) {
    uVar15 = *puStack00000088;
    uVar1 = *puVar12;
    in_stack_000000c0 = 0x7f;
    iVar14 = FUN_00009fac(iVar4,&stack0x000000c0,1);
    if (iVar14 == 0) {
      FUN_000001a0(&stack0x000000c4,0xff);
      puStack00000020[3] = (char)((uint)uVar15 >> 0x18);
      puStack00000020[2] = (char)((uint)uVar15 >> 0x10);
      puStack00000020[1] = (char)((uint)uVar15 >> 8);
      *puStack00000020 = (char)uVar15;
      in_stack_000000c4 = (undefined1)iVar11;
      iVar14 = FUN_00009fac(iVar4 + 1,&stack0x000000c4,5);
      if (((iVar14 == 0) &&
          (in_stack_000000c0 = in_stack_00000048, iVar14 = FUN_00009fac(iVar4,&stack0x000000c0,1),
          iVar14 == 0)) &&
         (in_stack_000000c4 = 7,
         iVar14 = FUN_00009fac((uint)uVar1 + in_stack_0000008c,&stack0x000000c4,1), iVar14 == 0)) {
        *puVar12 = (ushort)uVar17;
        *(undefined1 *)(in_stack_0000005c + iVar11 + 0x10) = 0;
        if (uVar13 < 3) {
          FUN_0000a020(uVar13 * iVar5 + in_stack_0000008c,iVar5);
        }
      }
    }
  }
LAB_00011faa:
  (&stack0x00000090)[iVar16] = 0;
LAB_00011fb0:
  iVar16 = iVar16 + 1;
  goto LAB_00011ed0;
}

