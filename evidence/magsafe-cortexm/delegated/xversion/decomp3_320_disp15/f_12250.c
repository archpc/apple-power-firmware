
void FUN_00012250(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint uVar13;
  int iVar14;
  ushort *puVar15;
  int unaff_r4;
  int iVar16;
  undefined4 uVar17;
  uint uVar18;
  undefined1 unaff_r7;
  uint uVar19;
  undefined4 *in_stack_00000044;
  undefined1 in_stack_00000048;
  int in_stack_0000005c;
  int in_stack_00000060;
  undefined4 *puStack00000064;
  ushort *puStack00000068;
  int in_stack_0000006c;
  int in_stack_00000070;
  int in_stack_00000074;
  uint in_stack_00000078;
  undefined4 *in_stack_0000007c;
  int in_stack_00000080;
  ushort *in_stack_00000084;
  undefined4 *in_stack_00000088;
  int in_stack_0000008c;
  byte in_stack_000000b8;
  char in_stack_000000bc;
  undefined1 in_stack_000000c0;
  char cStack000000c4;
  byte bStack000000c5;
  byte bStack000000c6;
  byte bStack000000c7;
  byte bStack000000c8;
  byte bStack000000c9;
  
  uVar3 = (int)in_stack_00000084 * 0x20 + unaff_r4;
  *(short *)(in_stack_00000074 + 0x32) = (short)uVar3;
  if (uVar3 <= DAT_00012618) {
    uVar3 = DAT_00012618;
  }
  uVar5 = (uint)(uVar3 + DAT_0001261c != 0);
  iVar4 = FUN_0000089c((uVar3 + DAT_0001261c) - uVar5,in_stack_00000060 << 0xd);
  uVar5 = iVar4 + uVar5;
  iVar4 = uVar5 + 1;
  do {
    if (1 < uVar5) goto LAB_00012286;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(char *)(in_stack_00000074 + in_stack_0000006c) = (char)uVar5;
LAB_00012286:
  iVar4 = 0;
LAB_0001229c:
  if (iVar4 != 0x12) {
    if ((&stack0x00000090)[iVar4] != '\0') {
      uVar5 = (uint)*(byte *)(in_stack_00000074 + in_stack_0000006c);
      iVar16 = DAT_00012680 + 1;
      uVar3 = uVar5 * iVar16 + DAT_00012680;
      uVar1 = *(ushort *)(in_stack_00000074 + 0x32);
      uVar19 = (uint)uVar1;
      if ((uVar3 & 0xffff) < uVar19) {
        uVar11 = uVar5 + 1;
        *(char *)(in_stack_00000074 + in_stack_0000006c) = (char)uVar11;
        if (1 < (uVar11 & 0xff)) {
          uVar11 = 0;
          *(undefined1 *)(in_stack_00000074 + in_stack_0000006c) = 0;
          *(undefined2 *)(in_stack_00000074 + 0x32) = 0;
          uVar19 = 0;
        }
        if (uVar19 <= (iVar16 * (uVar11 & 0xff) + DAT_00012680 & 0xffff)) {
          *(ushort *)(in_stack_00000074 + 0x32) = (ushort)uVar19 + 0x20;
          cStack000000c4 = '\x1f';
          iVar6 = FUN_00009fac((uVar3 - 0x1f & 0xffff) + in_stack_0000008c,&stack0x000000c4,1);
          if (iVar6 == 0) {
            cStack000000c4 = '\x7f';
            iVar6 = uVar19 + in_stack_0000008c;
            iVar7 = FUN_00009fac(iVar6,&stack0x000000c4,1);
            if (iVar7 == 0) {
              iVar14 = DAT_0001267c + 0x20;
              puVar15 = (ushort *)(in_stack_00000070 + 0x20);
              puVar12 = in_stack_00000044;
              for (iVar7 = 0; iVar7 != 0x12; iVar7 = iVar7 + 1) {
                if ((uVar5 * iVar14 + DAT_0001267c & DAT_00012684) == (uint)*puVar15) {
                  puStack00000068 = (ushort *)(in_stack_00000070 + 0x20);
                  iVar8 = 0;
                  puStack00000064 = DAT_0001268c;
                  goto LAB_0001242e;
                }
                puVar15 = puVar15 + 1;
                puVar12 = puVar12 + 1;
              }
            }
          }
        }
      }
      else {
        *(ushort *)(in_stack_00000074 + 0x32) = uVar1 + 0x20;
        iVar6 = in_stack_00000070 + iVar4 * 2;
        cStack000000c4 = '\x1f';
        iVar16 = FUN_00009fac((uint)*(ushort *)(iVar6 + 0x20) + in_stack_0000008c,&stack0x000000c4,1
                             );
        if ((iVar16 == 0) && (uVar19 != DAT_00012688)) {
          puVar15 = (ushort *)(iVar6 + 0x20);
          uVar17 = in_stack_00000044[iVar4];
          uVar2 = *puVar15;
          in_stack_000000c0 = 0x7f;
          iVar16 = uVar19 + in_stack_0000008c;
          iVar6 = FUN_00009fac(iVar16,&stack0x000000c0,1);
          if (iVar6 == 0) {
            FUN_000001a0(&stack0x000000c4,0xff);
            bStack000000c8 = (byte)((uint)uVar17 >> 0x18);
            bStack000000c7 = (byte)((uint)uVar17 >> 0x10);
            bStack000000c6 = (byte)((uint)uVar17 >> 8);
            bStack000000c5 = (byte)uVar17;
            cStack000000c4 = (char)iVar4;
            iVar6 = FUN_00009fac(iVar16 + 1,&stack0x000000c4,5);
            if ((iVar6 == 0) &&
               (in_stack_000000c0 = in_stack_00000048,
               iVar16 = FUN_00009fac(iVar16,&stack0x000000c0,1), iVar16 == 0)) {
              cStack000000c4 = '\a';
              iVar16 = FUN_00009fac((uint)uVar2 + in_stack_0000008c,&stack0x000000c4,1);
              if (iVar16 == 0) {
                *puVar15 = uVar1;
                *(undefined1 *)(in_stack_0000005c + iVar4 + 0x10) = 0;
              }
            }
          }
        }
      }
      goto LAB_0001237a;
    }
    goto LAB_00012384;
  }
  *(undefined1 *)(in_stack_00000074 + in_stack_0000006c) = unaff_r7;
  FUN_000001a0(&stack0x00000090,0,0x12);
  for (iVar4 = 0; iVar4 != in_stack_00000080; iVar4 = iVar4 + 1) {
    uVar3 = iVar4 * 0x20 + (int)in_stack_00000088;
    if ((uVar3 & in_stack_00000078) == in_stack_00000078) {
      FUN_00012b24();
      return;
    }
    iVar6 = (uVar3 & 0xffff) + in_stack_0000008c;
    iVar16 = (*(code *)*in_stack_0000007c)(&stack0x000000bc,iVar6,1);
    if (iVar16 != 0) {
      FUN_00012b24();
      return;
    }
    if ((in_stack_000000bc == '\x1f') || (in_stack_000000bc == '?')) {
      iVar16 = (*(code *)*in_stack_0000007c)(&stack0x000000b8,iVar6 + 1,1);
      uVar5 = (uint)in_stack_000000b8;
      if (iVar16 == 0) {
        if (((uVar5 < 0x12) && ((&stack0x000000a4)[uVar5] == '\0')) &&
           (((uVar3 & 0xffff) <= DAT_00012a64 &&
            (iVar16 = (*(code *)*in_stack_0000007c)(&stack0x000000c4,iVar6,0x20), iVar16 == 0)))) {
          uVar5 = 0;
          if (cStack000000c4 == '\a') {
LAB_00012718:
            iVar16 = 0;
            uVar19 = 0;
          }
          else if (cStack000000c4 == '\x1f') {
LAB_000126fa:
            uVar5 = (uint)bStack000000c5;
            iVar16 = 6;
            uVar11 = 0;
LAB_00012702:
            if (iVar16 == 0x20) {
              uVar19 = 0xd0;
            }
            else {
              uVar13 = uVar11 + 8;
              if (*(byte *)((int)&stack0x000000c4 + iVar16) == 0) goto code_r0x00012712;
              for (uVar18 = 7;
                  (uVar19 = uVar13, -1 < (int)uVar18 &&
                  (uVar19 = uVar11,
                  (*(byte *)((int)&stack0x000000c4 + iVar16) >> (uVar18 & 0xff) & 1) == 0));
                  uVar18 = uVar18 - 1) {
                uVar11 = uVar11 + 1;
              }
            }
            if ((0x11 < uVar5) || (0xd0 < uVar19)) goto LAB_000126d8;
            iVar16 = ((uint)bStack000000c9 * 0x100 + (uint)bStack000000c8) * 0x10000 +
                     (uint)bStack000000c7 * 0x100 + (uint)bStack000000c6 + uVar19;
          }
          else {
            if (cStack000000c4 == -1) goto LAB_00012718;
            iVar16 = 0;
            uVar19 = 0;
            if (cStack000000c4 != '\x7f') {
              if (cStack000000c4 != '?') goto LAB_000126d8;
              goto LAB_000126fa;
            }
          }
          if ((((cStack000000c4 == '\a') || (cStack000000c4 == '\x1f')) || (cStack000000c4 == '?'))
             || ((cStack000000c4 == -1 || (cStack000000c4 == '\x7f')))) {
            *(int *)(DAT_00012a68 + uVar5 * 4) = iVar16;
            in_stack_000000b8 = (byte)uVar5;
            *(char *)(in_stack_0000005c + uVar5 + 0x10) = (char)uVar19;
            *(short *)(in_stack_00000070 + uVar5 * 2 + 0x20) = (short)uVar3;
            if (in_stack_000000bc == '?') {
              (&stack0x00000090)[uVar5] = 0;
            }
            else {
              (&stack0x00000090)[uVar5] = 1;
            }
          }
        }
      }
      else if ((&stack0x000000a4)[uVar5] == '\0') {
        FUN_00012b24();
        return;
      }
    }
    else if (in_stack_000000bc == -1) break;
LAB_000126d8:
  }
  iVar4 = 0;
LAB_000127b4:
  if (iVar4 == 0x12) {
    FUN_00012b24();
    return;
  }
  if ((&stack0x00000090)[iVar4] != '\0') {
    uVar5 = (uint)*(byte *)(in_stack_00000074 + in_stack_0000006c);
    iVar16 = DAT_00012b88 + 1;
    uVar3 = uVar5 * iVar16 + DAT_00012b88;
    uVar1 = *(ushort *)(in_stack_00000074 + 0x32);
    uVar19 = (uint)uVar1;
    if ((uVar3 & 0xffff) < uVar19) {
      uVar11 = uVar5 + 1;
      *(char *)(in_stack_00000074 + in_stack_0000006c) = (char)uVar11;
      if (1 < (uVar11 & 0xff)) {
        uVar11 = 0;
        *(undefined1 *)(in_stack_00000074 + in_stack_0000006c) = 0;
        *(undefined2 *)(in_stack_00000074 + 0x32) = 0;
        uVar19 = 0;
      }
      if (uVar19 <= (iVar16 * (uVar11 & 0xff) + DAT_00012b88 & 0xffff)) {
        *(ushort *)(in_stack_00000074 + 0x32) = (ushort)uVar19 + 0x20;
        cStack000000c4 = '\x1f';
        iVar6 = FUN_00009fac((uVar3 - 0x1f & 0xffff) + in_stack_0000008c,&stack0x000000c4,1);
        if (iVar6 == 0) {
          cStack000000c4 = '\x7f';
          iVar6 = uVar19 + in_stack_0000008c;
          iVar7 = FUN_00009fac(iVar6,&stack0x000000c4,1);
          if (iVar7 == 0) {
            iVar7 = DAT_00012b84 + 0x20;
            puVar15 = (ushort *)(in_stack_00000070 + 0x20);
            in_stack_00000088 = DAT_00012b90;
            for (iVar14 = 0; iVar14 != 0x12; iVar14 = iVar14 + 1) {
              if ((uVar5 * iVar7 + DAT_00012b84 & DAT_00012b78) == (uint)*puVar15) {
                in_stack_00000084 = (ushort *)(in_stack_00000070 + 0x20);
                iVar8 = 0;
                in_stack_0000007c = DAT_00012b90;
                goto LAB_0001293c;
              }
              puVar15 = puVar15 + 1;
              in_stack_00000088 = in_stack_00000088 + 1;
            }
          }
        }
      }
    }
    else {
      *(ushort *)(in_stack_00000074 + 0x32) = uVar1 + 0x20;
      iVar6 = in_stack_00000070 + iVar4 * 2;
      cStack000000c4 = '\x1f';
      iVar16 = FUN_00009fac((uint)*(ushort *)(iVar6 + 0x20) + in_stack_0000008c,&stack0x000000c4,1);
      if ((iVar16 == 0) && (uVar19 != DAT_00012b7c)) {
        puVar15 = (ushort *)(iVar6 + 0x20);
        uVar17 = DAT_00012b90[iVar4];
        uVar2 = *puVar15;
        in_stack_000000c0 = 0x7f;
        iVar16 = uVar19 + in_stack_0000008c;
        iVar6 = FUN_00009fac(iVar16,&stack0x000000c0,1);
        if (iVar6 == 0) {
          FUN_000001a0(&stack0x000000c4,0xff);
          bStack000000c8 = (byte)((uint)uVar17 >> 0x18);
          bStack000000c7 = (byte)((uint)uVar17 >> 0x10);
          bStack000000c6 = (byte)((uint)uVar17 >> 8);
          cStack000000c4 = (char)iVar4;
          iVar6 = FUN_00009fac(iVar16 + 1,&stack0x000000c4,5);
          if ((iVar6 == 0) &&
             (in_stack_000000c0 = in_stack_00000048,
             iVar16 = FUN_00009fac(iVar16,&stack0x000000c0,1), iVar16 == 0)) {
            cStack000000c4 = '\a';
            iVar16 = FUN_00009fac((uint)uVar2 + in_stack_0000008c,&stack0x000000c4,1);
            if (iVar16 == 0) {
              *puVar15 = uVar1;
              *(undefined1 *)(in_stack_0000005c + iVar4 + 0x10) = 0;
            }
          }
        }
      }
    }
    goto LAB_0001288c;
  }
  goto LAB_00012892;
LAB_0001242e:
  if (iVar8 == 0x12) goto LAB_0001255e;
  if ((iVar7 != iVar8) && (uVar3 = (uint)*puStack00000068, uVar3 != DAT_00012688)) {
    uVar11 = (uint)*(byte *)(in_stack_00000074 + in_stack_0000006c) * iVar14;
    if ((uVar3 < (uVar11 & 0xe000)) || ((DAT_0001267c + uVar11 + 0x1f & 0xffff) < uVar3)) {
      uVar1 = *(ushort *)(in_stack_00000074 + 0x32);
      uVar11 = (uint)uVar1;
      if ((iVar16 * (uint)*(byte *)(in_stack_00000074 + in_stack_0000006c) + DAT_00012680 & 0xffff)
          < uVar11) goto LAB_0001237a;
      *(ushort *)(in_stack_00000074 + 0x32) = uVar1 + 0x20;
      cStack000000c4 = '\x1f';
      iVar9 = FUN_00009fac(uVar3 + in_stack_0000008c,&stack0x000000c4,1);
      if ((iVar9 != 0) || (uVar11 == DAT_00012688)) goto LAB_0001237a;
      uVar17 = *puStack00000064;
      uVar2 = *puStack00000068;
      iVar9 = uVar11 + in_stack_0000008c;
      in_stack_000000c0 = 0x7f;
      iVar10 = FUN_00009fac(iVar9,&stack0x000000c0,1);
      if (iVar10 != 0) goto LAB_0001237a;
      FUN_000001a0(&stack0x000000c4,0xff);
      bStack000000c8 = (byte)((uint)uVar17 >> 0x18);
      bStack000000c7 = (byte)((uint)uVar17 >> 0x10);
      bStack000000c6 = (byte)((uint)uVar17 >> 8);
      bStack000000c5 = (byte)uVar17;
      cStack000000c4 = (char)iVar8;
      iVar10 = FUN_00009fac(iVar9 + 1,&stack0x000000c4,5);
      if (((iVar10 != 0) ||
          (in_stack_000000c0 = in_stack_00000048, iVar9 = FUN_00009fac(iVar9,&stack0x000000c0,1),
          iVar9 != 0)) ||
         (cStack000000c4 = '\a',
         iVar9 = FUN_00009fac((uint)uVar2 + in_stack_0000008c,&stack0x000000c4,1), iVar9 != 0))
      goto LAB_0001237a;
      *puStack00000068 = uVar1;
      *(undefined1 *)(in_stack_0000005c + iVar8 + 0x10) = 0;
    }
  }
  puStack00000068 = puStack00000068 + 1;
  puStack00000064 = puStack00000064 + 1;
  iVar8 = iVar8 + 1;
  goto LAB_0001242e;
LAB_0001255e:
  cStack000000c4 = '\x1f';
  iVar16 = FUN_00009fac((uint)*puVar15 + in_stack_0000008c,&stack0x000000c4,1);
  if (iVar16 == 0) {
    uVar17 = *puVar12;
    uVar1 = *puVar15;
    in_stack_000000c0 = 0x7f;
    iVar16 = FUN_00009fac(iVar6,&stack0x000000c0,1);
    if (iVar16 == 0) {
      FUN_000001a0(&stack0x000000c4,0xff);
      bStack000000c8 = (byte)((uint)uVar17 >> 0x18);
      bStack000000c7 = (byte)((uint)uVar17 >> 0x10);
      bStack000000c6 = (byte)((uint)uVar17 >> 8);
      bStack000000c5 = (byte)uVar17;
      cStack000000c4 = (char)iVar7;
      iVar16 = FUN_00009fac(iVar6 + 1,&stack0x000000c4,5);
      if (((iVar16 == 0) &&
          (in_stack_000000c0 = in_stack_00000048, iVar16 = FUN_00009fac(iVar6,&stack0x000000c0,1),
          iVar16 == 0)) &&
         (cStack000000c4 = '\a',
         iVar16 = FUN_00009fac((uint)uVar1 + in_stack_0000008c,&stack0x000000c4,1), iVar16 == 0)) {
        *puVar15 = (ushort)uVar19;
        *(undefined1 *)(in_stack_0000005c + iVar7 + 0x10) = 0;
        if (uVar5 < 3) {
          FUN_0000a020(uVar5 * iVar14 + in_stack_0000008c,iVar14);
        }
      }
    }
  }
LAB_0001237a:
  (&stack0x00000090)[iVar4] = 0;
LAB_00012384:
  iVar4 = iVar4 + 1;
  goto LAB_0001229c;
code_r0x00012712:
  iVar16 = iVar16 + 1;
  uVar11 = uVar13;
  goto LAB_00012702;
LAB_0001293c:
  if (iVar8 == 0x12) goto LAB_00012a6c;
  if ((iVar14 != iVar8) && (uVar3 = (uint)*in_stack_00000084, uVar3 != DAT_00012b7c)) {
    uVar11 = (uint)*(byte *)(in_stack_00000074 + in_stack_0000006c) * iVar7;
    if ((uVar3 < (uVar11 & 0xe000)) || ((DAT_00012b84 + uVar11 + 0x1f & 0xffff) < uVar3)) {
      uVar1 = *(ushort *)(in_stack_00000074 + 0x32);
      uVar11 = (uint)uVar1;
      if ((iVar16 * (uint)*(byte *)(in_stack_00000074 + in_stack_0000006c) + DAT_00012b88 & 0xffff)
          < uVar11) goto LAB_0001288c;
      *(ushort *)(in_stack_00000074 + 0x32) = uVar1 + 0x20;
      cStack000000c4 = '\x1f';
      iVar9 = FUN_00009fac(uVar3 + in_stack_0000008c,&stack0x000000c4,1);
      if ((iVar9 != 0) || (uVar11 == DAT_00012b7c)) goto LAB_0001288c;
      uVar17 = *in_stack_0000007c;
      uVar2 = *in_stack_00000084;
      iVar9 = uVar11 + in_stack_0000008c;
      in_stack_000000c0 = 0x7f;
      iVar10 = FUN_00009fac(iVar9,&stack0x000000c0,1);
      if (iVar10 != 0) goto LAB_0001288c;
      FUN_000001a0(&stack0x000000c4,0xff);
      bStack000000c8 = (byte)((uint)uVar17 >> 0x18);
      bStack000000c7 = (byte)((uint)uVar17 >> 0x10);
      bStack000000c6 = (byte)((uint)uVar17 >> 8);
      cStack000000c4 = (char)iVar8;
      iVar10 = FUN_00009fac(iVar9 + 1,&stack0x000000c4,5);
      if (((iVar10 != 0) ||
          (in_stack_000000c0 = in_stack_00000048, iVar9 = FUN_00009fac(iVar9,&stack0x000000c0,1),
          iVar9 != 0)) ||
         (cStack000000c4 = '\a',
         iVar9 = FUN_00009fac((uint)uVar2 + in_stack_0000008c,&stack0x000000c4,1), iVar9 != 0))
      goto LAB_0001288c;
      *in_stack_00000084 = uVar1;
      *(undefined1 *)(in_stack_0000005c + iVar8 + 0x10) = 0;
    }
  }
  in_stack_00000084 = in_stack_00000084 + 1;
  in_stack_0000007c = in_stack_0000007c + 1;
  iVar8 = iVar8 + 1;
  goto LAB_0001293c;
LAB_00012a6c:
  cStack000000c4 = '\x1f';
  iVar16 = FUN_00009fac((uint)*puVar15 + in_stack_0000008c,&stack0x000000c4,1);
  if (iVar16 == 0) {
    uVar17 = *in_stack_00000088;
    uVar1 = *puVar15;
    in_stack_000000c0 = 0x7f;
    iVar16 = FUN_00009fac(iVar6,&stack0x000000c0,1);
    if (iVar16 == 0) {
      FUN_000001a0(&stack0x000000c4,0xff);
      bStack000000c8 = (byte)((uint)uVar17 >> 0x18);
      bStack000000c7 = (byte)((uint)uVar17 >> 0x10);
      bStack000000c6 = (byte)((uint)uVar17 >> 8);
      cStack000000c4 = (char)iVar14;
      iVar16 = FUN_00009fac(iVar6 + 1,&stack0x000000c4,5);
      if (((iVar16 == 0) &&
          (in_stack_000000c0 = in_stack_00000048, iVar16 = FUN_00009fac(iVar6,&stack0x000000c0,1),
          iVar16 == 0)) &&
         (cStack000000c4 = '\a',
         iVar16 = FUN_00009fac((uint)uVar1 + in_stack_0000008c,&stack0x000000c4,1), iVar16 == 0)) {
        *puVar15 = (ushort)uVar19;
        *(undefined1 *)(in_stack_0000005c + iVar14 + 0x10) = 0;
        if (uVar5 < 3) {
          FUN_0000a020(uVar5 * iVar7 + in_stack_0000008c,iVar7);
        }
      }
    }
  }
LAB_0001288c:
  (&stack0x00000090)[iVar4] = 0;
LAB_00012892:
  iVar4 = iVar4 + 1;
  goto LAB_000127b4;
}

