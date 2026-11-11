
undefined4 FUN_000099ec(void)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  uint *puVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  char cVar14;
  longlong lVar15;
  undefined8 uVar16;
  longlong lVar17;
  
  pcVar5 = DAT_00009cb0;
  *DAT_00009cb0 = '\x01';
  iVar6 = DAT_00009cb4;
  uVar9 = DAT_00009c94;
  uVar12 = DAT_00009c98;
  if (*(int *)(DAT_00009cb4 + 0x10) != 0) {
    while (uVar12 = FUN_0000b994(), uVar12 < uVar9) {
      *(undefined4 *)(iVar6 + 8) = 3;
      software_interrupt(1);
    }
                    /* WARNING: Subroutine does not return */
    FUN_0000967c(0xd);
  }
  do {
    iVar7 = FUN_00009cbc();
    iVar8 = FUN_00009928();
    if (iVar7 != iVar8) {
      if (*(int *)(iVar6 + 0x10) != 0) {
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
          uVar11 = FUN_0000b994();
          if (uVar12 < uVar11) {
                    /* WARNING: Subroutine does not return */
            FUN_0000967c(9);
          }
          if (uVar12 + 200 < uVar9) {
                    /* WARNING: Subroutine does not return */
            FUN_0000967c(10);
          }
          FUN_000099c8(100);
          FUN_00009d38();
          uVar9 = (*DAT_00009c9c & 7) + 0x3800;
          goto LAB_00009acc;
        }
        if (iVar7 == 0) {
          FUN_00001400(2,1);
          FUN_00009d14(0);
          *DAT_00009ca8 = 0;
          puVar4 = DAT_00009ca4;
          *DAT_00009ca4 = *DAT_00009ca4 | 0x10000;
          *puVar4 = *puVar4 & 0xfffeffff;
          puVar4[0xf] = 0;
          FUN_00000b60(0x1e0);
          *DAT_00009ca0 = *DAT_00009ca0 & 0x7fffffff;
        }
      }
      FUN_00009cbc();
      FUN_00009d14();
    }
    lVar15 = FUN_00000e50();
    iVar8 = (int)((ulonglong)lVar15 >> 0x20);
    iVar7 = FUN_00009928();
    if (iVar7 == 2) {
      uVar9 = FUN_00008778(1);
      cVar14 = '\0';
      if (((uVar9 & 0xff) != 1) && (cVar14 = '\0', (uVar9 & 0xff00) != 0x100)) {
        iVar7 = FUN_00008be8(1);
        cVar14 = '\0';
        if (iVar7 == 0) {
          uVar9 = 0;
          bVar3 = (bool)isCurrentModePrivileged();
          if (bVar3) {
            uVar9 = isIRQinterruptsEnabled();
          }
          disableIRQinterrupts();
          FUN_00009944();
          bVar3 = (bool)isCurrentModePrivileged();
          if (bVar3) {
            enableIRQinterrupts((uVar9 & 1) == 1);
          }
          if (2 < *(byte *)(iVar6 + 0x41)) {
                    /* WARNING: Subroutine does not return */
            FUN_0000967c(5);
          }
          cVar14 = *(byte *)(iVar6 + 0x41) + 1;
        }
      }
      uVar9 = 0;
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        uVar9 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00009944();
      *(char *)(iVar6 + 0x41) = cVar14;
      FUN_00009ddc();
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        enableIRQinterrupts((uVar9 & 1) == 1);
      }
      uVar16 = FUN_00009dc0();
      uVar12 = DAT_00009c98;
      iVar7 = (int)uVar16 + -1;
      if ((int)(uint)((int)uVar16 == 0) <= (int)((ulonglong)uVar16 >> 0x20)) {
        uVar9 = 0;
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          uVar9 = isIRQinterruptsEnabled();
        }
        disableIRQinterrupts();
        FUN_00009944(iVar7);
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          enableIRQinterrupts((uVar9 & 1) == 1);
        }
        lVar17 = lVar15 - *(longlong *)(iVar6 + 0x38);
        uVar9 = (uint)lVar17;
        iVar7 = 0;
        if ((int)(uint)(uVar9 < DAT_00009cac) <= (int)((ulonglong)lVar17 >> 0x20)) {
          lVar17 = FUN_00009dc0(0,uVar9 - DAT_00009cac);
          iVar10 = (int)((ulonglong)lVar17 >> 0x20);
          iVar7 = (int)(lVar17 - lVar15);
          if (lVar17 - lVar15 < 0 !=
              (SBORROW4(iVar10,iVar8) !=
              SBORROW4(iVar10 - iVar8,(uint)((uint)lVar17 < (uint)lVar15)))) {
                    /* WARNING: Subroutine does not return */
            FUN_0000967c(6);
          }
        }
      }
    }
    uVar9 = FUN_0000b924(iVar7);
    iVar8 = FUN_0000b994();
    iVar10 = FUN_00009928();
    iVar7 = DAT_00009cb8;
    if ((uVar12 + 200 < uVar9) && (iVar10 == 1)) {
                    /* WARNING: Subroutine does not return */
      FUN_0000967c(0);
    }
    if ((((*(char *)(DAT_00009cb8 + 0x1ec) != '\0') && (*(char *)(DAT_00009cb8 + 0x20) != '\0')) &&
        (iVar10 = FUN_00009928(), iVar10 - 1U < 2)) &&
       (uVar13 = (int)(uVar9 - iVar8) >> 0x1f, uVar11 = FUN_00000880(uVar9 * 0x1e,100),
       uVar11 < ((uVar9 - iVar8) + uVar13 ^ uVar13))) {
                    /* WARNING: Subroutine does not return */
      FUN_0000967c(1);
    }
    uVar11 = (uint)*(byte *)(iVar7 + 0x45);
    if (uVar11 == 0x23) {
      uVar11 = 0;
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        uVar11 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        enableIRQinterrupts((uVar11 & 1) == 1);
      }
      if (*(char *)(iVar7 + 0x20) != '\0') {
        uVar1 = *(ushort *)(iVar7 + 0x52);
        uVar2 = *(ushort *)(iVar7 + 0x54);
        iVar7 = FUN_00000880((uint)uVar1 * 0x1e,100);
        uVar12 = DAT_00009c98;
        if (iVar7 + (uint)uVar1 < uVar9) {
LAB_00009c4a:
                    /* WARNING: Subroutine does not return */
          FUN_0000967c(2);
        }
        iVar7 = FUN_00000880((uint)uVar2 * 0x1e,100);
        uVar11 = (uint)uVar2 - iVar7;
        if (uVar9 < uVar11) goto LAB_00009c4a;
      }
    }
    FUN_00009cd8(uVar11);
    FUN_000099c8(100);
    *(undefined4 *)(iVar6 + 8) = 3;
    software_interrupt(1);
    if (*pcVar5 == '\0') {
      return 0;
    }
  } while( true );
}

