
undefined4 FUN_00009ae6(void)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  char cVar11;
  undefined4 unaff_r4;
  undefined4 unaff_r6;
  uint unaff_r7;
  longlong lVar12;
  undefined8 uVar13;
  longlong lVar14;
  int in_stack_00000004;
  char *in_stack_0000000c;
  int in_stack_00000010;
  
  lVar12 = CONCAT44(unaff_r4,unaff_r6);
  do {
    iVar7 = (int)((ulonglong)lVar12 >> 0x20);
    iVar5 = FUN_00009928();
    if (iVar5 == 2) {
      uVar6 = FUN_00008778(1);
      cVar11 = '\0';
      if ((uVar6 & 0xff) != 1) {
        cVar11 = '\0';
        if ((uVar6 & 0xff00) != 0x100) {
          iVar5 = FUN_00008be8(1);
          cVar11 = '\0';
          if (iVar5 == 0) {
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
            cVar11 = *(byte *)(in_stack_00000010 + 0x41) + 1;
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
      *(char *)(in_stack_00000010 + 0x41) = cVar11;
      FUN_00009ddc();
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        enableIRQinterrupts((uVar6 & 1) == 1);
      }
      uVar13 = FUN_00009dc0();
      unaff_r7 = DAT_00009c98;
      iVar5 = (int)uVar13 + -1;
      if ((int)(uint)((int)uVar13 == 0) <= (int)((ulonglong)uVar13 >> 0x20)) {
        uVar6 = 0;
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          uVar6 = isIRQinterruptsEnabled();
        }
        disableIRQinterrupts();
        FUN_00009944(iVar5);
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          enableIRQinterrupts((uVar6 & 1) == 1);
        }
        lVar14 = lVar12 - *(longlong *)(in_stack_00000010 + 0x38);
        uVar6 = (uint)lVar14;
        iVar5 = 0;
        if ((int)(uint)(uVar6 < DAT_00009cac) <= (int)((ulonglong)lVar14 >> 0x20)) {
          lVar14 = FUN_00009dc0(0,uVar6 - DAT_00009cac);
          iVar8 = (int)((ulonglong)lVar14 >> 0x20);
          iVar5 = (int)(lVar14 - lVar12);
          if (lVar14 - lVar12 < 0 !=
              (SBORROW4(iVar8,iVar7) != SBORROW4(iVar8 - iVar7,(uint)((uint)lVar14 < (uint)lVar12)))
             ) {
                    /* WARNING: Subroutine does not return */
            FUN_0000967c(6);
          }
        }
      }
    }
    uVar6 = FUN_0000b924(iVar5);
    iVar7 = FUN_0000b994();
    iVar8 = FUN_00009928();
    iVar5 = DAT_00009cb8;
    if ((unaff_r7 + 200 < uVar6) && (iVar8 == 1)) {
                    /* WARNING: Subroutine does not return */
      FUN_0000967c(0);
    }
    if ((((*(char *)(DAT_00009cb8 + 0x1ec) != '\0') && (*(char *)(DAT_00009cb8 + 0x20) != '\0')) &&
        (iVar8 = FUN_00009928(), iVar8 - 1U < 2)) &&
       (uVar10 = (int)(uVar6 - iVar7) >> 0x1f, uVar9 = FUN_00000880(uVar6 * 0x1e,100),
       uVar9 < ((uVar6 - iVar7) + uVar10 ^ uVar10))) {
                    /* WARNING: Subroutine does not return */
      FUN_0000967c(1);
    }
    uVar9 = (uint)*(byte *)(iVar5 + 0x45);
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
      if (*(char *)(iVar5 + 0x20) != '\0') {
        uVar1 = *(ushort *)(iVar5 + 0x52);
        uVar2 = *(ushort *)(iVar5 + 0x54);
        iVar5 = FUN_00000880((uint)uVar1 * 0x1e,100);
        unaff_r7 = DAT_00009c98;
        if (iVar5 + (uint)uVar1 < uVar6) {
LAB_00009c4a:
                    /* WARNING: Subroutine does not return */
          FUN_0000967c(2);
        }
        iVar5 = FUN_00000880((uint)uVar2 * 0x1e,100);
        uVar9 = (uint)uVar2 - iVar5;
        if (uVar6 < uVar9) goto LAB_00009c4a;
      }
    }
    FUN_00009cd8(uVar9);
    FUN_000099c8(100);
    *(undefined4 *)(in_stack_00000010 + 8) = 3;
    software_interrupt(1);
    if (*in_stack_0000000c == '\0') {
      return 0;
    }
    iVar5 = FUN_00009cbc();
    iVar7 = FUN_00009928();
    if (iVar5 != iVar7) {
      if (*(int *)(in_stack_00000010 + 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0000967c(0x10);
      }
      FUN_00009cd8();
      iVar5 = FUN_00009cbc();
      if (iVar5 == 2) {
        FUN_000099c8(100);
        iVar5 = FUN_00009928();
        if (iVar5 == 0) {
          FUN_00009d38();
        }
        uVar6 = (*DAT_00009c9c & 7) + 0x1d00;
LAB_00009acc:
        *DAT_00009c9c = uVar6;
        FUN_00001400(1,1);
      }
      else {
        if (iVar5 == 1) {
          iVar5 = FUN_00009928();
          if (iVar5 == 2) {
                    /* WARNING: Subroutine does not return */
            FUN_0000967c(8);
          }
          uVar6 = FUN_0000b924();
          uVar9 = FUN_0000b994();
          if (unaff_r7 < uVar9) {
                    /* WARNING: Subroutine does not return */
            FUN_0000967c(9);
          }
          if (unaff_r7 + 200 < uVar6) {
                    /* WARNING: Subroutine does not return */
            FUN_0000967c(10);
          }
          FUN_000099c8(100);
          FUN_00009d38();
          uVar6 = (*DAT_00009c9c & 7) + 0x3800;
          goto LAB_00009acc;
        }
        if (iVar5 == 0) {
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
    lVar12 = FUN_00000e50();
  } while( true );
}

