
/* WARNING: Removing unreachable block (ram,0x0000f0ba) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort * FUN_0000f120(ushort *param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  code *pcVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  ushort *puVar16;
  byte bVar17;
  ushort *unaff_r4;
  int *unaff_r5;
  char in_NG;
  bool bVar18;
  int in_stack_00000018;
  undefined1 local_80 [68];
  ushort *local_3c;
  ushort *local_38;
  int local_34;
  undefined4 local_30;
  ushort *local_2c;
  undefined4 local_28;
  undefined2 local_18;
  undefined2 local_16;
  
  while( true ) {
    if (in_NG != '\0') {
      param_1[0x26] = 0;
      param_1[0x27] = 0;
      *unaff_r5 = ((uint)unaff_r4 & 0xfffff80f) + in_stack_00000018 * 0x40 + 0x10;
      return (ushort *)0x1;
    }
    if (-1 < (int)param_1) break;
    param_1 = (ushort *)0x0;
    in_NG = '\0';
  }
  if ((int)param_1 < 0) {
    bVar18 = param_1 == (ushort *)0x0;
    if ((int)param_1 < 0) {
      if (-1 < (int)param_1) goto LAB_0000f176;
      if (-1 < (int)param_1) {
        local_3c = param_1;
        local_38 = (ushort *)param_3;
        FUN_000001a0(&local_30,0,0x1c);
        pcVar2 = DAT_0000f2bc;
        local_16 = SUB42(param_1,0);
        local_34 = 0;
        local_18 = 0;
        local_28 = DAT_0000f2b4;
        local_30 = local_38;
        local_38 = param_1;
        local_2c = param_1;
        iVar4 = (*DAT_0000f2bc)(&local_30,DAT_0000f2b8);
        iVar5 = (*pcVar2)(&local_30,DAT_0000f2c0);
        iVar6 = (*pcVar2)(&local_30,DAT_0000f2c4,DAT_0000f2b0);
        iVar4 = iVar4 - (int)local_3c;
        iVar7 = (*pcVar2)(&local_30,DAT_0000f2cc,*(undefined1 *)(DAT_0000f2c8 + 0x5d));
        puVar3 = DAT_0000f2d0;
        iVar15 = *DAT_0000f2d0 - DAT_0000f2d0[1];
        if (*DAT_0000f2d0 < DAT_0000f2d0[1]) {
          iVar15 = local_34;
        }
        iVar8 = (*pcVar2)(&local_30,DAT_0000f2d4,iVar15);
        iVar15 = puVar3[2] - puVar3[3];
        if (puVar3[2] < puVar3[3]) {
          iVar15 = local_34;
        }
        iVar9 = (*pcVar2)(&local_30,DAT_0000f2d8,iVar15);
        iVar15 = puVar3[4] - puVar3[5];
        if (puVar3[4] < puVar3[5]) {
          iVar15 = local_34;
        }
        iVar10 = (*pcVar2)(&local_30,DAT_0000f2dc,iVar15);
        iVar15 = puVar3[6] - puVar3[7];
        if (puVar3[6] < puVar3[7]) {
          iVar15 = local_34;
        }
        iVar11 = (*pcVar2)(&local_30,DAT_0000f2e0,iVar15);
        iVar15 = puVar3[8] - puVar3[9];
        if (puVar3[8] < puVar3[9]) {
          iVar15 = local_34;
        }
        iVar12 = (*pcVar2)(&local_30,DAT_0000f2e4,iVar15);
        iVar15 = puVar3[10] - puVar3[0xb];
        if (puVar3[10] < puVar3[0xb]) {
          iVar15 = local_34;
        }
        iVar13 = (*pcVar2)(&local_30,DAT_0000f2e8,iVar15);
        iVar15 = puVar3[0xc] - puVar3[0xd];
        if (puVar3[0xc] < puVar3[0xd]) {
          iVar15 = local_34;
        }
        iVar14 = (*pcVar2)(&local_30,DAT_0000f2ec,iVar15);
        iVar15 = puVar3[0xe] - puVar3[0xf];
        if (puVar3[0xe] < puVar3[0xf]) {
          iVar15 = local_34;
        }
        iVar15 = (*pcVar2)(&local_30,DAT_0000f2f0,iVar15);
        puVar16 = (ushort *)
                  (iVar4 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 + iVar12 + iVar13
                   + iVar14 + iVar15);
        if ((int)local_38 <= (int)puVar16) {
          puVar16 = local_38;
        }
        return puVar16;
      }
      register0x00000054 = (BADSPACEBASE *)local_80;
      unaff_r4 = param_1;
      goto LAB_0000f13e;
    }
  }
  else {
LAB_0000f13e:
    if (unaff_r4 == (ushort *)0x0) {
      return (ushort *)0x0;
    }
    if (0x5c < *unaff_r4) {
      return (ushort *)0x0;
    }
    unaff_r5 = (int *)0x5d;
    FUN_00000170((undefined1 *)((int)register0x00000054 + 0x10),DAT_0000f1a4,0x5d);
    bVar18 = *(char *)((int)unaff_r4 + 3) == '\x01';
  }
  if (bVar18) {
    FUN_00000170((undefined4 *)((int)register0x00000054 + 0x28),DAT_0000f1a8 + 0x34,0x11);
  }
  *(undefined4 *)((int)register0x00000054 + 8) = 0;
  *(undefined4 *)((int)register0x00000054 + 4) = 2;
  *(undefined4 *)register0x00000054 = 3;
LAB_0000f176:
  FUN_000007a2((undefined1 *)((int)register0x00000054 + 0x39),0xc,DAT_0000f1ac,_DAT_0000f1b0);
  bVar17 = (byte)unaff_r4[1];
  uVar1 = *unaff_r4;
  if (0x5d < (uint)uVar1 + (uint)bVar17) {
    bVar17 = (char)unaff_r5 - (char)uVar1;
  }
  *(byte *)(unaff_r4 + 1) = bVar17;
  FUN_00000170(*(undefined4 *)(unaff_r4 + 2),(undefined1 *)((int)register0x00000054 + uVar1 + 0x10),
               bVar17);
  return (ushort *)(uint)(byte)unaff_r4[1];
}

