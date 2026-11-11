// rea decompile_all
// name: FUN_00009634
// address: 0x9634
// body: available
// range: 0x9634-0x9641 inclusive
// range: 0x9662-0x9667 inclusive
// range: 0x9a08-0x9c79 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0x9c46 to 0x967c FUN_0000967c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x9c4c to 0x967c FUN_0000967c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x9c52 to 0x967c FUN_0000967c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x9c58 to 0x967c FUN_0000967c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x9c5e to 0x967c FUN_0000967c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x9c64 to 0x967c FUN_0000967c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x9c6a to 0x967c FUN_0000967c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x9c70 to 0x967c FUN_0000967c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x9c76 to 0x967c FUN_0000967c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or 
// limitations_truncated: true; decompile-index.json keeps the complete list
// pseudocode: provider-specific; not original source


/* WARNING: Instruction at (ram,0x00009adc) overlaps instruction at (ram,0x00009ada)
    */
/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00009634(uint param_1)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  uint *puVar4;
  undefined *puVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  char cVar13;
  undefined4 unaff_r4;
  undefined4 unaff_r6;
  uint unaff_r7;
  int unaff_lr;
  bool bVar14;
  undefined8 in_d2;
  undefined8 unaff_d15;
  undefined8 uVar15;
  longlong lVar16;
  int in_stack_00000000;
  char *in_stack_00000004;
  int in_stack_00000008;
  
  lVar16 = CONCAT44(unaff_r4,unaff_r6);
  if (param_1 < 6) {
    bVar14 = (param_1 & 0x3fffffff) == 0;
    puVar5 = (&switchD_00009640::switchdataD_00009644)[param_1];
    lVar3 = CONCAT44(in_stack_00000000,unaff_r6);
    switch(param_1) {
    case 0:
      goto switchD_00009640_caseD_0;
    case 1:
      VectorSub(unaff_d15,in_d2,2);
      goto code_r0x00009aec;
    default:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 4:
      goto switchD_00009640_caseD_4;
    case 5:
      goto switchD_00009640_caseD_5;
    }
  }
  uVar6 = FUN_000095e8();
  return uVar6;
switchD_00009640_caseD_0:
  puVar5 = (undefined *)FUN_00009928();
  bVar14 = puVar5 == (undefined *)0x2;
code_r0x00009aec:
  if (bVar14) {
switchD_00009640_caseD_5:
    unaff_r7 = 1;
    puVar5 = (undefined *)0x1;
    lVar3 = lVar16;
switchD_00009640_caseD_4:
    in_stack_00000000 = (int)((ulonglong)lVar3 >> 0x20);
    uVar7 = FUN_00008778(puVar5);
    cVar13 = '\0';
    if ((uVar7 & 0xff) != 1) {
      cVar13 = '\0';
      if ((uVar7 & 0xff00) != unaff_r7 * 0x100) {
        iVar8 = FUN_00008be8(1);
        cVar13 = '\0';
        if (iVar8 == 0) {
          uVar7 = 0;
          bVar14 = (bool)isCurrentModePrivileged();
          if (bVar14) {
            uVar7 = isIRQinterruptsEnabled();
          }
          disableIRQinterrupts();
          FUN_00009944();
          bVar14 = (bool)isCurrentModePrivileged();
          if (bVar14) {
            enableIRQinterrupts((uVar7 & 1) == 1);
          }
          if (2 < *(byte *)(in_stack_00000008 + 0x41)) {
                    /* WARNING: Subroutine does not return */
            FUN_0000967c(5);
          }
          cVar13 = *(byte *)(in_stack_00000008 + 0x41) + 1;
        }
      }
    }
    uVar7 = 0;
    bVar14 = (bool)isCurrentModePrivileged();
    if (bVar14) {
      uVar7 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_00009944();
    *(char *)(in_stack_00000008 + 0x41) = cVar13;
    FUN_00009ddc();
    bVar14 = (bool)isCurrentModePrivileged();
    if (bVar14) {
      enableIRQinterrupts((uVar7 & 1) == 1);
    }
    uVar15 = FUN_00009dc0();
    unaff_r7 = DAT_00009c98;
    puVar5 = (undefined *)((int)uVar15 + -1);
    if ((int)(uint)((int)uVar15 == 0) <= (int)((ulonglong)uVar15 >> 0x20)) {
      uVar7 = 0;
      bVar14 = (bool)isCurrentModePrivileged();
      if (bVar14) {
        uVar7 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00009944(puVar5);
      bVar14 = (bool)isCurrentModePrivileged();
      if (bVar14) {
        enableIRQinterrupts((uVar7 & 1) == 1);
      }
      lVar16 = lVar3 - *(longlong *)(in_stack_00000008 + 0x38);
      uVar7 = (uint)lVar16;
      puVar5 = (undefined *)0x0;
      if ((int)(uint)(uVar7 < DAT_00009cac) <= (int)((ulonglong)lVar16 >> 0x20)) {
        lVar16 = FUN_00009dc0(0,uVar7 - DAT_00009cac);
        iVar8 = (int)((ulonglong)lVar16 >> 0x20);
        puVar5 = (undefined *)(lVar16 - lVar3);
        if (lVar16 - lVar3 < 0 !=
            (SBORROW4(iVar8,in_stack_00000000) !=
            SBORROW4(iVar8 - in_stack_00000000,(uint)((uint)lVar16 < (uint)lVar3)))) {
                    /* WARNING: Subroutine does not return */
          FUN_0000967c(6);
        }
      }
    }
  }
  uVar7 = FUN_0000b924(puVar5);
  iVar9 = FUN_0000b994();
  iVar10 = FUN_00009928();
  iVar8 = DAT_00009cb8;
  if ((unaff_r7 + 200 < uVar7) && (iVar10 == 1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0000967c(0);
  }
  if ((((*(char *)(DAT_00009cb8 + 0x1ec) != '\0') && (*(char *)(DAT_00009cb8 + 0x20) != '\0')) &&
      (iVar10 = FUN_00009928(), iVar10 - 1U < 2)) &&
     (uVar12 = (int)(uVar7 - iVar9) >> 0x1f, uVar11 = FUN_00000880(uVar7 * 0x1e,100),
     uVar11 < ((uVar7 - iVar9) + uVar12 ^ uVar12))) {
                    /* WARNING: Subroutine does not return */
    FUN_0000967c(1);
  }
  uVar11 = (uint)*(byte *)(iVar8 + 0x45);
  if (uVar11 == 0x23) {
    uVar11 = 0;
    bVar14 = (bool)isCurrentModePrivileged();
    if (bVar14) {
      uVar11 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    bVar14 = (bool)isCurrentModePrivileged();
    if (bVar14) {
      enableIRQinterrupts((uVar11 & 1) == 1);
    }
    if (*(char *)(iVar8 + 0x20) != '\0') {
      uVar1 = *(ushort *)(iVar8 + 0x52);
      uVar2 = *(ushort *)(iVar8 + 0x54);
      iVar8 = FUN_00000880((uint)uVar1 * 0x1e,100);
      unaff_r7 = DAT_00009c98;
      if (iVar8 + (uint)uVar1 < uVar7) {
LAB_00009c4a:
                    /* WARNING: Subroutine does not return */
        FUN_0000967c(2);
      }
      iVar8 = FUN_00000880((uint)uVar2 * 0x1e,100);
      uVar11 = (uint)uVar2 - iVar8;
      if (uVar7 < uVar11) goto LAB_00009c4a;
    }
  }
  FUN_00009cd8(uVar11);
  FUN_000099c8(100);
  *(undefined4 *)(in_stack_00000008 + 8) = 3;
  software_interrupt(1);
  if (*in_stack_00000004 == '\0') {
    return 0;
  }
  iVar8 = FUN_00009cbc();
  iVar9 = FUN_00009928();
  if (iVar8 != iVar9) {
    if (*(int *)(in_stack_00000008 + 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0000967c(0x10);
    }
    FUN_00009cd8();
    iVar8 = FUN_00009cbc();
    if (iVar8 == 2) {
      FUN_000099c8(100);
      iVar8 = FUN_00009928();
      if (iVar8 == 0) {
        FUN_00009d38();
      }
      uVar7 = (*DAT_00009c9c & 7) + 0x1d00;
LAB_00009acc:
      *DAT_00009c9c = uVar7;
      FUN_00001400(1,1);
    }
    else {
      if (iVar8 == 1) {
        iVar8 = FUN_00009928();
        if (iVar8 == 2) {
                    /* WARNING: Subroutine does not return */
          FUN_0000967c(8);
        }
        uVar7 = FUN_0000b924();
        uVar11 = FUN_0000b994();
        if (unaff_r7 < uVar11) {
                    /* WARNING: Subroutine does not return */
          FUN_0000967c(9);
        }
        if (unaff_r7 + 200 < uVar7) {
                    /* WARNING: Subroutine does not return */
          FUN_0000967c(10);
        }
        FUN_000099c8(100);
        FUN_00009d38();
        uVar7 = (*DAT_00009c9c & 7) + 0x3800;
        goto LAB_00009acc;
      }
      if (iVar8 == 0) {
        FUN_00001400(2,unaff_lr);
        FUN_00009d14(0);
        *DAT_00009ca8 = 0;
        puVar4 = DAT_00009ca4;
        *DAT_00009ca4 = *DAT_00009ca4 | unaff_lr << 0x10;
        *puVar4 = *puVar4 & ~(unaff_lr << 0x10);
        puVar4[0xf] = 0;
        FUN_00000b60(0x1e0);
        *DAT_00009ca0 = *DAT_00009ca0 & ~(unaff_lr << 0x1f);
      }
    }
    FUN_00009cbc();
    FUN_00009d14();
  }
  lVar16 = FUN_00000e50();
  goto switchD_00009640_caseD_0;
}

