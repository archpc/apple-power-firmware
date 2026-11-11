
/* WARNING: Instruction at (ram,0x00009aea) overlaps instruction at (ram,0x00009ae8)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00009ae8(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  char cVar11;
  undefined4 unaff_r4;
  undefined4 unaff_r6;
  uint unaff_r7;
  char in_ZR;
  undefined4 extraout_s4;
  undefined4 extraout_s5;
  undefined8 in_d2;
  undefined8 unaff_d15;
  longlong lVar12;
  undefined8 uVar13;
  longlong lVar14;
  int in_stack_00000004;
  char *in_stack_0000000c;
  int in_stack_00000010;
  
  lVar12 = CONCAT44(unaff_r4,unaff_r6);
  do {
    iVar9 = (int)((ulonglong)lVar12 >> 0x20);
    VectorSub(unaff_d15,in_d2,2);
    if (in_ZR != '\0') {
      uVar5 = FUN_00008778(1);
      cVar11 = '\0';
      if ((uVar5 & 0xff) != 1) {
        cVar11 = '\0';
        if ((uVar5 & 0xff00) != 0x100) {
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
      uVar13 = FUN_00009dc0();
      unaff_r7 = DAT_00009c98;
      param_1 = (int)uVar13 + -1;
      if ((int)(uint)((int)uVar13 == 0) <= (int)((ulonglong)uVar13 >> 0x20)) {
        uVar5 = 0;
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          uVar5 = isIRQinterruptsEnabled();
        }
        disableIRQinterrupts();
        FUN_00009944(param_1);
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          enableIRQinterrupts((uVar5 & 1) == 1);
        }
        lVar14 = lVar12 - *(longlong *)(in_stack_00000010 + 0x38);
        uVar5 = (uint)lVar14;
        param_1 = 0;
        if ((int)(uint)(uVar5 < DAT_00009cac) <= (int)((ulonglong)lVar14 >> 0x20)) {
          lVar14 = FUN_00009dc0(0,uVar5 - DAT_00009cac);
          iVar6 = (int)((ulonglong)lVar14 >> 0x20);
          param_1 = (int)(lVar14 - lVar12);
          if (lVar14 - lVar12 < 0 !=
              (SBORROW4(iVar6,iVar9) != SBORROW4(iVar6 - iVar9,(uint)((uint)lVar14 < (uint)lVar12)))
             ) {
                    /* WARNING: Subroutine does not return */
            FUN_0000967c(6);
          }
        }
      }
    }
    uVar5 = FUN_0000b8d0(param_1);
    iVar6 = FUN_0000b940();
    iVar7 = FUN_00009928();
    iVar9 = DAT_00009cb8;
    if ((unaff_r7 + 200 < uVar5) && (iVar7 == 1)) {
                    /* WARNING: Subroutine does not return */
      FUN_0000967c(0);
    }
    if ((((*(char *)(DAT_00009cb8 + 0x1ec) != '\0') && (*(char *)(DAT_00009cb8 + 0x20) != '\0')) &&
        (iVar7 = FUN_00009928(), iVar7 - 1U < 2)) &&
       (uVar10 = (int)(uVar5 - iVar6) >> 0x1f, uVar8 = FUN_00000880(uVar5 * 0x1e,100),
       uVar8 < ((uVar5 - iVar6) + uVar10 ^ uVar10))) {
                    /* WARNING: Subroutine does not return */
      FUN_0000967c(1);
    }
    uVar8 = (uint)*(byte *)(iVar9 + 0x45);
    if (uVar8 == 0x23) {
      uVar8 = 0;
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        uVar8 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        enableIRQinterrupts((uVar8 & 1) == 1);
      }
      if (*(char *)(iVar9 + 0x20) != '\0') {
        uVar1 = *(ushort *)(iVar9 + 0x52);
        uVar2 = *(ushort *)(iVar9 + 0x54);
        iVar9 = FUN_00000880((uint)uVar1 * 0x1e,100);
        unaff_r7 = DAT_00009c98;
        if (iVar9 + (uint)uVar1 < uVar5) {
LAB_00009c4a:
                    /* WARNING: Subroutine does not return */
          FUN_0000967c(2);
        }
        iVar9 = FUN_00000880((uint)uVar2 * 0x1e,100);
        uVar8 = (uint)uVar2 - iVar9;
        if (uVar5 < uVar8) goto LAB_00009c4a;
      }
    }
    FUN_00009cd8(uVar8);
    FUN_000099c8(100);
    *(undefined4 *)(in_stack_00000010 + 8) = 3;
    software_interrupt(1);
    if (*in_stack_0000000c == '\0') {
      return 0;
    }
    iVar9 = FUN_00009cbc();
    iVar6 = FUN_00009928();
    if (iVar9 != iVar6) {
      if (*(int *)(in_stack_00000010 + 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0000967c(0x10);
      }
      FUN_00009cd8();
      iVar9 = FUN_00009cbc();
      if (iVar9 == 2) {
        FUN_000099c8(100);
        iVar9 = FUN_00009928();
        if (iVar9 == 0) {
          FUN_00009d38();
        }
        uVar5 = (*_DAT_00009c9c & 7) + 0x1d00;
LAB_00009acc:
        *_DAT_00009c9c = uVar5;
        FUN_00001400(1,1);
      }
      else {
        if (iVar9 == 1) {
          iVar9 = FUN_00009928();
          if (iVar9 == 2) {
                    /* WARNING: Subroutine does not return */
            FUN_0000967c(8);
          }
          uVar5 = FUN_0000b8d0();
          uVar8 = FUN_0000b940();
          if (unaff_r7 < uVar8) {
                    /* WARNING: Subroutine does not return */
            FUN_0000967c(9);
          }
          if (unaff_r7 + 200 < uVar5) {
                    /* WARNING: Subroutine does not return */
            FUN_0000967c(10);
          }
          FUN_000099c8(100);
          FUN_00009d38();
          uVar5 = (*_DAT_00009c9c & 7) + 0x3800;
          goto LAB_00009acc;
        }
        if (iVar9 == 0) {
          FUN_00001400(2,in_stack_00000004);
          FUN_00009d14(0);
          *_DAT_00009ca8 = 0;
          puVar4 = _DAT_00009ca4;
          *_DAT_00009ca4 = *_DAT_00009ca4 | in_stack_00000004 << 0x10;
          *puVar4 = *puVar4 & ~(in_stack_00000004 << 0x10);
          puVar4[0xf] = 0;
          FUN_00000b60(0x1e0);
          *_DAT_00009ca0 = *_DAT_00009ca0 & ~(in_stack_00000004 << 0x1f);
        }
      }
      FUN_00009cbc();
      FUN_00009d14();
    }
    lVar12 = FUN_00000e50();
    param_1 = FUN_00009928();
    in_d2 = CONCAT44(extraout_s5,extraout_s4);
    in_ZR = param_1 == 2;
  } while( true );
}

