
undefined4 FUN_00009aee(void)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  longlong lVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  char cVar12;
  undefined4 unaff_r4;
  uint uVar13;
  undefined4 unaff_r6;
  undefined8 uVar14;
  longlong lVar15;
  int in_stack_00000004;
  int iStack00000008;
  char *in_stack_0000000c;
  int in_stack_00000010;
  
  uVar14 = CONCAT44(unaff_r4,unaff_r6);
  do {
    iStack00000008 = (int)((ulonglong)uVar14 >> 0x20);
    uVar9 = (uint)uVar14;
    uVar6 = FUN_00008778(1);
    cVar12 = '\0';
    if ((uVar6 & 0xff) != 1) {
      cVar12 = '\0';
      if ((uVar6 & 0xff00) != 0x100) {
        iVar7 = FUN_00008be8(1);
        cVar12 = '\0';
        if (iVar7 == 0) {
          uVar6 = 0;
          bVar3 = (bool)isCurrentModePrivileged();
          if (bVar3) {
            uVar6 = isIRQinterruptsEnabled();
          }
          disableIRQinterrupts();
          FUN_00009944();
          bVar3 = (bool)isCurrentModePrivileged();
          if (bVar3) {
            enableIRQinterrupts((uVar6 & 1) == 1);
          }
          if (2 < *(byte *)(in_stack_00000010 + 0x41)) {
                    /* WARNING: Subroutine does not return */
            FUN_0000967c(5);
          }
          cVar12 = *(byte *)(in_stack_00000010 + 0x41) + 1;
        }
      }
    }
    uVar6 = 0;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      uVar6 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_00009944();
    *(char *)(in_stack_00000010 + 0x41) = cVar12;
    FUN_00009ddc();
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      enableIRQinterrupts((uVar6 & 1) == 1);
    }
    uVar14 = FUN_00009dc0();
    iVar7 = iStack00000008;
    uVar6 = DAT_00009c98;
    lVar4 = CONCAT44(iStack00000008,uVar9);
    iVar8 = (int)uVar14 + -1;
    if ((int)(uint)((int)uVar14 == 0) <= (int)((ulonglong)uVar14 >> 0x20)) {
      uVar13 = 0;
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        uVar13 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00009944(iVar8);
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        enableIRQinterrupts((uVar13 & 1) == 1);
      }
      uVar13 = uVar9 - *(uint *)(in_stack_00000010 + 0x38);
      iVar8 = 0;
      if ((int)(uint)(uVar13 < DAT_00009cac) <=
          (int)((iVar7 - *(int *)(in_stack_00000010 + 0x3c)) -
               (uint)(uVar9 < *(uint *)(in_stack_00000010 + 0x38)))) {
        lVar15 = FUN_00009dc0(0,uVar13 - DAT_00009cac);
        iVar10 = (int)((ulonglong)lVar15 >> 0x20);
        lVar4 = lVar15 - lVar4;
        iVar8 = (int)lVar4;
        if (lVar4 < 0 !=
            (SBORROW4(iVar10,iVar7) != SBORROW4(iVar10 - iVar7,(uint)((uint)lVar15 < uVar9)))) {
                    /* WARNING: Subroutine does not return */
          FUN_0000967c(6);
        }
      }
    }
    do {
      uVar9 = FUN_0000b924(iVar8);
      iVar8 = FUN_0000b994();
      iVar10 = FUN_00009928();
      iVar7 = DAT_00009cb8;
      if ((uVar6 + 200 < uVar9) && (iVar10 == 1)) {
                    /* WARNING: Subroutine does not return */
        FUN_0000967c(0);
      }
      if ((((*(char *)(DAT_00009cb8 + 0x1ec) != '\0') && (*(char *)(DAT_00009cb8 + 0x20) != '\0'))
          && (iVar10 = FUN_00009928(), iVar10 - 1U < 2)) &&
         (uVar11 = (int)(uVar9 - iVar8) >> 0x1f, uVar13 = FUN_00000880(uVar9 * 0x1e,100),
         uVar13 < ((uVar9 - iVar8) + uVar11 ^ uVar11))) {
                    /* WARNING: Subroutine does not return */
        FUN_0000967c(1);
      }
      uVar13 = (uint)*(byte *)(iVar7 + 0x45);
      if (uVar13 == 0x23) {
        uVar13 = 0;
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          uVar13 = isIRQinterruptsEnabled();
        }
        disableIRQinterrupts();
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          enableIRQinterrupts((uVar13 & 1) == 1);
        }
        if (*(char *)(iVar7 + 0x20) != '\0') {
          uVar1 = *(ushort *)(iVar7 + 0x52);
          uVar2 = *(ushort *)(iVar7 + 0x54);
          iVar7 = FUN_00000880((uint)uVar1 * 0x1e,100);
          uVar6 = DAT_00009c98;
          if (iVar7 + (uint)uVar1 < uVar9) {
LAB_00009c4a:
                    /* WARNING: Subroutine does not return */
            FUN_0000967c(2);
          }
          iVar7 = FUN_00000880((uint)uVar2 * 0x1e,100);
          uVar13 = (uint)uVar2 - iVar7;
          if (uVar9 < uVar13) goto LAB_00009c4a;
        }
      }
      FUN_00009cd8(uVar13);
      FUN_000099c8(100);
      *(undefined4 *)(in_stack_00000010 + 8) = 3;
      software_interrupt(1);
      if (*in_stack_0000000c == '\0') {
        return 0;
      }
      iVar7 = FUN_00009cbc();
      iVar8 = FUN_00009928();
      if (iVar7 != iVar8) {
        if (*(int *)(in_stack_00000010 + 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_0000967c(0x10);
        }
        FUN_00009cd8();
        iVar7 = FUN_00009cbc();
        if (iVar7 == 2) {
          FUN_000099c8(100);
          iVar7 = FUN_00009928();
          if (iVar7 == 0) {
            FUN_00009d38();
          }
          uVar9 = (*DAT_00009c9c & 7) + 0x1d00;
LAB_00009acc:
          *DAT_00009c9c = uVar9;
          FUN_00001400(1,1);
        }
        else {
          if (iVar7 == 1) {
            iVar7 = FUN_00009928();
            if (iVar7 == 2) {
                    /* WARNING: Subroutine does not return */
              FUN_0000967c(8);
            }
            uVar9 = FUN_0000b924();
            uVar13 = FUN_0000b994();
            if (uVar6 < uVar13) {
                    /* WARNING: Subroutine does not return */
              FUN_0000967c(9);
            }
            if (uVar6 + 200 < uVar9) {
                    /* WARNING: Subroutine does not return */
              FUN_0000967c(10);
            }
            FUN_000099c8(100);
            FUN_00009d38();
            uVar9 = (*DAT_00009c9c & 7) + 0x3800;
            goto LAB_00009acc;
          }
          if (iVar7 == 0) {
            FUN_00001400(2,in_stack_00000004);
            FUN_00009d14(0);
            *DAT_00009ca8 = 0;
            puVar5 = DAT_00009ca4;
            *DAT_00009ca4 = *DAT_00009ca4 | in_stack_00000004 << 0x10;
            *puVar5 = *puVar5 & ~(in_stack_00000004 << 0x10);
            puVar5[0xf] = 0;
            FUN_00000b60(0x1e0);
            *DAT_00009ca0 = *DAT_00009ca0 & ~(in_stack_00000004 << 0x1f);
          }
        }
        FUN_00009cbc();
        FUN_00009d14();
      }
      uVar14 = FUN_00000e50();
      iVar8 = FUN_00009928();
    } while (iVar8 != 2);
  } while( true );
}

