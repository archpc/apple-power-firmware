
undefined4 FUN_00009af4(undefined4 param_1)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  char cVar11;
  uint uVar12;
  undefined4 unaff_r6;
  int unaff_r7;
  longlong lVar13;
  undefined8 uVar14;
  longlong lVar15;
  int in_stack_00000004;
  int in_stack_00000008;
  char *in_stack_0000000c;
  int in_stack_00000010;
  
  lVar13 = CONCAT44(in_stack_00000008,unaff_r6);
  do {
    in_stack_00000008 = (int)((ulonglong)lVar13 >> 0x20);
    uVar5 = FUN_00008778(param_1);
    cVar11 = '\0';
    if ((uVar5 & 0xff) != 1) {
      cVar11 = '\0';
      if ((uVar5 & 0xff00) != unaff_r7 * 0x100) {
        iVar6 = FUN_00008be8(1);
        cVar11 = '\0';
        if (iVar6 == 0) {
          uVar5 = 0;
          bVar3 = (bool)isCurrentModePrivileged();
          if (bVar3) {
            uVar5 = isIRQinterruptsEnabled();
          }
          disableIRQinterrupts();
          FUN_00009944();
          bVar3 = (bool)isCurrentModePrivileged();
          if (bVar3) {
            enableIRQinterrupts((uVar5 & 1) == 1);
          }
          if (2 < *(byte *)(in_stack_00000010 + 0x41)) {
                    /* WARNING: Subroutine does not return */
            FUN_0000967c(5);
          }
          cVar11 = *(byte *)(in_stack_00000010 + 0x41) + 1;
        }
      }
    }
    uVar5 = 0;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      uVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_00009944();
    *(char *)(in_stack_00000010 + 0x41) = cVar11;
    FUN_00009ddc();
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
    uVar14 = FUN_00009dc0();
    uVar5 = DAT_00009c98;
    iVar6 = (int)uVar14 + -1;
    if ((int)(uint)((int)uVar14 == 0) <= (int)((ulonglong)uVar14 >> 0x20)) {
      uVar12 = 0;
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        uVar12 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00009944(iVar6);
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        enableIRQinterrupts((uVar12 & 1) == 1);
      }
      lVar15 = lVar13 - *(longlong *)(in_stack_00000010 + 0x38);
      uVar12 = (uint)lVar15;
      iVar6 = 0;
      if ((int)(uint)(uVar12 < DAT_00009cac) <= (int)((ulonglong)lVar15 >> 0x20)) {
        lVar15 = FUN_00009dc0(0,uVar12 - DAT_00009cac);
        iVar7 = (int)((ulonglong)lVar15 >> 0x20);
        iVar6 = (int)(lVar15 - lVar13);
        if (lVar15 - lVar13 < 0 !=
            (SBORROW4(iVar7,in_stack_00000008) !=
            SBORROW4(iVar7 - in_stack_00000008,(uint)((uint)lVar15 < (uint)lVar13)))) {
                    /* WARNING: Subroutine does not return */
          FUN_0000967c(6);
        }
      }
    }
    do {
      uVar12 = FUN_0000b924(iVar6);
      iVar7 = FUN_0000b994();
      iVar8 = FUN_00009928();
      iVar6 = DAT_00009cb8;
      if ((uVar5 + 200 < uVar12) && (iVar8 == 1)) {
                    /* WARNING: Subroutine does not return */
        FUN_0000967c(0);
      }
      if ((((*(char *)(DAT_00009cb8 + 0x1ec) != '\0') && (*(char *)(DAT_00009cb8 + 0x20) != '\0'))
          && (iVar8 = FUN_00009928(), iVar8 - 1U < 2)) &&
         (uVar10 = (int)(uVar12 - iVar7) >> 0x1f, uVar9 = FUN_00000880(uVar12 * 0x1e,100),
         uVar9 < ((uVar12 - iVar7) + uVar10 ^ uVar10))) {
                    /* WARNING: Subroutine does not return */
        FUN_0000967c(1);
      }
      uVar9 = (uint)*(byte *)(iVar6 + 0x45);
      if (uVar9 == 0x23) {
        uVar9 = 0;
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          uVar9 = isIRQinterruptsEnabled();
        }
        disableIRQinterrupts();
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          enableIRQinterrupts((uVar9 & 1) == 1);
        }
        if (*(char *)(iVar6 + 0x20) != '\0') {
          uVar1 = *(ushort *)(iVar6 + 0x52);
          uVar2 = *(ushort *)(iVar6 + 0x54);
          iVar6 = FUN_00000880((uint)uVar1 * 0x1e,100);
          uVar5 = DAT_00009c98;
          if (iVar6 + (uint)uVar1 < uVar12) {
LAB_00009c4a:
                    /* WARNING: Subroutine does not return */
            FUN_0000967c(2);
          }
          iVar6 = FUN_00000880((uint)uVar2 * 0x1e,100);
          uVar9 = (uint)uVar2 - iVar6;
          if (uVar12 < uVar9) goto LAB_00009c4a;
        }
      }
      FUN_00009cd8(uVar9);
      FUN_000099c8(100);
      *(undefined4 *)(in_stack_00000010 + 8) = 3;
      software_interrupt(1);
      if (*in_stack_0000000c == '\0') {
        return 0;
      }
      iVar6 = FUN_00009cbc();
      iVar7 = FUN_00009928();
      if (iVar6 != iVar7) {
        if (*(int *)(in_stack_00000010 + 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_0000967c(0x10);
        }
        FUN_00009cd8();
        iVar6 = FUN_00009cbc();
        if (iVar6 == 2) {
          FUN_000099c8(100);
          iVar6 = FUN_00009928();
          if (iVar6 == 0) {
            FUN_00009d38();
          }
          uVar12 = (*DAT_00009c9c & 7) + 0x1d00;
LAB_00009acc:
          *DAT_00009c9c = uVar12;
          FUN_00001400(1,1);
        }
        else {
          if (iVar6 == 1) {
            iVar6 = FUN_00009928();
            if (iVar6 == 2) {
                    /* WARNING: Subroutine does not return */
              FUN_0000967c(8);
            }
            uVar12 = FUN_0000b924();
            uVar9 = FUN_0000b994();
            if (uVar5 < uVar9) {
                    /* WARNING: Subroutine does not return */
              FUN_0000967c(9);
            }
            if (uVar5 + 200 < uVar12) {
                    /* WARNING: Subroutine does not return */
              FUN_0000967c(10);
            }
            FUN_000099c8(100);
            FUN_00009d38();
            uVar12 = (*DAT_00009c9c & 7) + 0x3800;
            goto LAB_00009acc;
          }
          if (iVar6 == 0) {
            FUN_00001400(2,in_stack_00000004);
            FUN_00009d14(0);
            *DAT_00009ca8 = 0;
            puVar4 = DAT_00009ca4;
            *DAT_00009ca4 = *DAT_00009ca4 | in_stack_00000004 << 0x10;
            *puVar4 = *puVar4 & ~(in_stack_00000004 << 0x10);
            puVar4[0xf] = 0;
            FUN_00000b60(0x1e0);
            *DAT_00009ca0 = *DAT_00009ca0 & ~(in_stack_00000004 << 0x1f);
          }
        }
        FUN_00009cbc();
        FUN_00009d14();
      }
      lVar13 = FUN_00000e50();
      iVar6 = FUN_00009928();
    } while (iVar6 != 2);
    unaff_r7 = 1;
    param_1 = 1;
  } while( true );
}

