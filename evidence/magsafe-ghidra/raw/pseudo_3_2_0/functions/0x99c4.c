// rea decompile_all
// name: FUN_000099c4
// address: 0x99c4
// body: available
// range: 0x99c4-0x9ca1 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0x9c54 to 0x975c FUN_0000975c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x9c5a to 0x975c FUN_0000975c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x9c60 to 0x975c FUN_0000975c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x9c66 to 0x975c FUN_0000975c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x9c6c to 0x975c FUN_0000975c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x9c72 to 0x975c FUN_0000975c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x9c78 to 0x975c FUN_0000975c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x9c7e to 0x975c FUN_0000975c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x9c84 to 0x975c FUN_0000975c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; Ghidra Listing reports a terminal call at 0x9c9e to 0x975c FUN_0000975c (external=false, thunk=false, hasNoReturn=true); fallthrough is excluded by Ghidra's flow model. This records Ghidra's FunctionManager flag, not an independent verification that the callee cannot return.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default 
// limitations_truncated: true; decompile-index.json keeps the complete list
// pseudocode: provider-specific; not original source


undefined4 FUN_000099c4(void)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  char cVar12;
  longlong lVar13;
  undefined8 uVar14;
  longlong lVar15;
  
  iVar3 = DAT_00009cc0;
  *(undefined1 *)(DAT_00009cc0 + 0x11) = 1;
  iVar4 = DAT_00009cc4;
  uVar7 = DAT_00009ca4;
  if (*(int *)(DAT_00009cc4 + 0x10) != 0) {
    while (uVar9 = FUN_0000bab4(), uVar9 < uVar7) {
      *(undefined4 *)(iVar4 + 8) = 3;
      software_interrupt(1);
    }
                    /* WARNING: Subroutine does not return */
    FUN_0000975c(0xd);
  }
  do {
    iVar5 = FUN_00009ccc();
    iVar6 = FUN_00009900();
    if (iVar5 != iVar6) {
      if (*(int *)(iVar4 + 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0000975c(0x10);
      }
      FUN_00009ce8();
      uVar7 = FUN_00009ccc();
      if (uVar7 == 2) {
        FUN_000099a0(100);
        iVar5 = FUN_00009900();
        if (iVar5 == 0) {
          FUN_00009d48();
        }
        *DAT_00009cac = (*DAT_00009cac & 7) + 0x1d00;
        uVar7 = 0;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          uVar7 = isIRQinterruptsEnabled();
        }
        disableIRQinterrupts();
        *(uint *)(iVar3 + 0x4c) = *(uint *)(iVar3 + 0x4c) | 1;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          enableIRQinterrupts((uVar7 & 1) == 1);
        }
      }
      else if (uVar7 == 1) {
        iVar5 = FUN_00009900();
        if (iVar5 == 2) {
                    /* WARNING: Subroutine does not return */
          FUN_0000975c(8);
        }
        uVar7 = FUN_0000ba44();
        uVar9 = FUN_0000bab4();
        if (DAT_00009ca8 < uVar9) {
                    /* WARNING: Subroutine does not return */
          FUN_0000975c(9);
        }
        if (DAT_00009ca8 + 200 < uVar7) {
                    /* WARNING: Subroutine does not return */
          FUN_0000975c(10);
        }
        FUN_000099a0(100);
        FUN_00009d48();
        *DAT_00009cac = (*DAT_00009cac & 7) + 0x3800;
        uVar7 = 0;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          uVar7 = isIRQinterruptsEnabled();
        }
        disableIRQinterrupts();
        *(uint *)(iVar3 + 0x4c) = *(uint *)(iVar3 + 0x4c) | 1;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          enableIRQinterrupts((uVar7 & 1) == 1);
        }
      }
      else if (uVar7 == 0) {
        uVar7 = 0;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          uVar7 = isIRQinterruptsEnabled();
        }
        disableIRQinterrupts();
        *(uint *)(iVar3 + 0x4c) = *(uint *)(iVar3 + 0x4c) & 0xfffffffe;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          enableIRQinterrupts((uVar7 & 1) == 1);
        }
        FUN_00009d24(0);
        *DAT_00009cb8 = 0;
        puVar2 = DAT_00009cb4;
        *DAT_00009cb4 = *DAT_00009cb4 | 0x10000;
        *puVar2 = *puVar2 & 0xfffeffff;
        puVar2[0xf] = 0;
        FUN_00000b80(0x1e0);
        uVar7 = 0x80000000;
        *DAT_00009cb0 = *DAT_00009cb0 & 0x7fffffff;
      }
      FUN_00009ccc(uVar7);
      FUN_00009d24();
    }
    lVar13 = FUN_00000e80();
    iVar6 = (int)((ulonglong)lVar13 >> 0x20);
    iVar5 = FUN_00009900();
    if (iVar5 == 2) {
      uVar7 = FUN_000088d4(1);
      cVar12 = '\0';
      if (((uVar7 & 0xff) != 1) && (cVar12 = '\0', (uVar7 & 0xff00) != 0x100)) {
        iVar5 = FUN_00008d2c(1);
        cVar12 = '\0';
        if (iVar5 == 0) {
          uVar7 = 0;
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            uVar7 = isIRQinterruptsEnabled();
          }
          disableIRQinterrupts();
          FUN_0000991c();
          cVar12 = *(char *)(iVar4 + 0x61);
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            enableIRQinterrupts((uVar7 & 1) == 1);
          }
          if (('\x02' < cVar12) || (cVar12 < '\0')) {
                    /* WARNING: Subroutine does not return */
            FUN_0000975c(5);
          }
          cVar12 = cVar12 + '\x01';
        }
      }
      uVar7 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar7 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_0000991c();
      *(char *)(iVar4 + 0x61) = cVar12;
      FUN_00009dec();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar7 & 1) == 1);
      }
      uVar14 = FUN_00009dd0();
      iVar5 = (int)uVar14 + -1;
      if ((int)(uint)((int)uVar14 == 0) <= (int)((ulonglong)uVar14 >> 0x20)) {
        uVar7 = 0;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          uVar7 = isIRQinterruptsEnabled();
        }
        disableIRQinterrupts();
        FUN_0000991c(iVar5);
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          enableIRQinterrupts((uVar7 & 1) == 1);
        }
        lVar15 = lVar13 - *(longlong *)(iVar4 + 0x58);
        uVar7 = (uint)lVar15;
        iVar5 = 0;
        if ((int)(uint)(uVar7 < DAT_00009cbc) <= (int)((ulonglong)lVar15 >> 0x20)) {
          lVar15 = FUN_00009dd0(0,uVar7 - DAT_00009cbc);
          iVar8 = (int)((ulonglong)lVar15 >> 0x20);
          iVar5 = (int)(lVar15 - lVar13);
          if (lVar15 - lVar13 < 0 !=
              (SBORROW4(iVar8,iVar6) != SBORROW4(iVar8 - iVar6,(uint)((uint)lVar15 < (uint)lVar13)))
             ) {
                    /* WARNING: Subroutine does not return */
            FUN_0000975c(6);
          }
        }
      }
    }
    uVar7 = FUN_0000ba44(iVar5);
    iVar6 = FUN_0000bab4();
    uVar9 = DAT_00009ca8 + 200;
    iVar8 = FUN_00009900();
    iVar5 = DAT_00009cc8;
    if ((uVar9 < uVar7) && (iVar8 == 1)) {
                    /* WARNING: Subroutine does not return */
      FUN_0000975c(0);
    }
    if ((((*(char *)(DAT_00009cc8 + 0x1ec) != '\0') && (*(char *)(DAT_00009cc8 + 0x20) != '\0')) &&
        (iVar8 = FUN_00009900(), iVar8 - 1U < 2)) &&
       (uVar10 = (int)(uVar7 - iVar6) >> 0x1f, uVar9 = FUN_0000089c(uVar7 * 0x1e,100),
       uVar9 < (uVar7 - iVar6 ^ uVar10) - uVar10)) {
                    /* WARNING: Subroutine does not return */
      FUN_0000975c(1);
    }
    uVar9 = (uint)*(byte *)(iVar5 + 0x45);
    if (uVar9 == 0x23) {
      uVar9 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar9 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((uVar9 & 1) == 1);
      }
      if (((*(char *)(iVar5 + 0x20) != '\0') &&
          (uVar10 = (uint)*(ushort *)(iVar5 + 0x52), uVar10 != 0)) &&
         (uVar11 = (uint)*(ushort *)(iVar5 + 0x54), uVar11 != 0)) {
        iVar5 = FUN_0000089c(uVar10 * 0x1e,100);
        if (iVar5 + uVar10 < uVar7) {
LAB_00009c64:
                    /* WARNING: Subroutine does not return */
          FUN_0000975c(2);
        }
        iVar5 = FUN_0000089c(uVar11 * 0x1e,100);
        uVar9 = uVar11 - iVar5;
        if (uVar7 < uVar9) goto LAB_00009c64;
      }
    }
    FUN_00009ce8(uVar9);
    FUN_000099a0(100);
    *(undefined4 *)(iVar4 + 8) = 3;
    software_interrupt(1);
    if (*(char *)(iVar3 + 0x11) == '\0') {
      return 0;
    }
  } while( true );
}

