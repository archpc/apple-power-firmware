// rea decompile_all
// name: FUN_00000c34
// address: 0xc34
// body: available
// range: 0xc34-0xc4b inclusive
// range: 0xc50-0xe07 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint FUN_00000c34(uint *param_1)

{
  int *piVar1;
  uint *puVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  code *pcVar9;
  int extraout_r1;
  int extraout_r2;
  int iVar10;
  bool bVar11;
  undefined4 in_cr14;
  longlong lVar12;
  longlong lVar13;
  undefined8 uVar14;
  byte local_34 [4];
  undefined1 auStack_30 [8];
  code *local_28;
  int iStack_1c;
  
  iVar7 = _DAT_200018a0;
  uVar4 = (uint)*(byte *)(param_1[6] - 2);
  switch(uVar4) {
  case 0:
    FUN_00000c20();
    coprocessor_store(0,in_cr14,param_1);
    iStack_1c = extraout_r2 + extraout_r1;
    uVar4 = 0;
    bVar11 = (bool)isCurrentModePrivileged();
    if (bVar11) {
      uVar4 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    DAT_20001854 = 1;
    _DAT_40030044 = _DAT_40030044 | 1;
    lVar12 = FUN_00000e08();
    iVar7 = (int)((ulonglong)lVar12 >> 0x20);
    uVar5 = (uint)lVar12;
    if (((int)(uint)(_DAT_200018e0 == 0) <= _DAT_200018e4) &&
       (bVar11 = uVar5 < _DAT_200018e0, lVar12 = lVar12 - CONCAT44(_DAT_200018e4,_DAT_200018e0),
       uVar5 = (uint)lVar12,
       lVar12 < 0 == (SBORROW4(iVar7,_DAT_200018e4) != SBORROW4(iVar7 - _DAT_200018e4,(uint)bVar11))
       )) {
      _DAT_200018e4 = 0;
      _DAT_200018e0 = 0;
      while (uVar6 = 0, DAT_200002a1 != 0) {
        local_34[0] = *_DAT_200002a4;
        iVar10 = *(int *)((uint)local_34[0] * 0x10 + 0x20000194);
        puVar2 = (uint *)((uint)local_34[0] * 0x10 + 0x20000190);
        uVar5 = *puVar2;
        lVar12 = *(longlong *)puVar2;
        lVar13 = FUN_00000e08();
        iVar7 = (int)((ulonglong)lVar13 >> 0x20);
        lVar12 = lVar13 - lVar12;
        uVar6 = (undefined4)lVar12;
        if (lVar12 < 0 !=
            (SBORROW4(iVar7,iVar10) != SBORROW4(iVar7 - iVar10,(uint)((uint)lVar13 < uVar5))))
        break;
        FUN_00001150(&DAT_200002a0,local_34,0x169d,0);
        bVar3 = local_34[0];
        iVar7 = (uint)local_34[0] * 0x10;
        FUN_00000170(auStack_30,iVar7 + 0x20000190,0x10);
        *(undefined4 *)(iVar7 + 0x20000190) = 0;
        *(undefined4 *)(iVar7 + 0x20000198) = 0;
        *(undefined4 *)(iVar7 + 0x20000194) = 0;
        _DAT_200002a4[DAT_200002a1] = bVar3;
        (*local_28)(auStack_30);
      }
      uVar5 = FUN_00001244(uVar6);
    }
    lVar12 = FUN_00000e08(uVar5);
    iVar7 = (int)((ulonglong)lVar12 >> 0x20);
    uVar5 = (uint)lVar12;
    if (_DAT_200018e0 == 0 && _DAT_200018e4 == 0) {
      uVar8 = 0x8000;
    }
    else {
      uVar8 = _DAT_200018e0 - uVar5;
      if ((int)(uint)(_DAT_200018e0 - uVar5 < 0x8000) <=
          (int)((_DAT_200018e4 - iVar7) - (uint)(_DAT_200018e0 < uVar5))) {
        uVar8 = 0x8000;
      }
      if ((int)uVar8 < 4) {
        uVar8 = 3;
      }
    }
    _DAT_40030040 = _DAT_4003003c + uVar8 & 0xffff;
    if ((int)((_DAT_200018dc - iVar7) - (uint)(_DAT_200018d8 < uVar5)) < 0 !=
        (SBORROW4(_DAT_200018dc,iVar7) !=
        SBORROW4(_DAT_200018dc - iVar7,(uint)(_DAT_200018d8 < uVar5)))) {
      FUN_00000f28(0x20000120,_DAT_200018d8 - uVar5);
      _DAT_200000d0 = _DAT_200000d0 + -1;
      if (_DAT_200000d0 == 0) {
        FUN_00012bc4(&DAT_0001316d);
        uVar14 = FUN_00000bac();
        if (uVar5 != 0) {
          uVar6 = 0;
          bVar11 = (bool)isCurrentModePrivileged();
          if (bVar11) {
            uVar6 = isIRQinterruptsEnabled();
          }
          uVar14 = CONCAT44(DAT_00000e48,uVar6);
          disableIRQinterrupts();
        }
        iVar7 = (int)((ulonglong)uVar14 >> 0x20);
        iVar10 = *(int *)(iVar7 + 0x40);
        uVar4 = *DAT_00000e40;
        *(uint *)(iVar7 + 0x40) = uVar4 & 0xffff;
        iVar7 = DAT_00000e4c;
        uVar4 = (uVar4 & 0xffff) - iVar10;
        if ((int)uVar4 < 0) {
          uVar4 = uVar4 + DAT_00000e44;
        }
        piVar1 = (int *)(DAT_00000e4c + 0x1c);
        uVar5 = *(uint *)(DAT_00000e4c + 0x18);
        *(uint *)(DAT_00000e4c + 0x18) = uVar5 + uVar4;
        *(uint *)(iVar7 + 0x1c) = *piVar1 + ((int)uVar4 >> 0x1f) + (uint)CARRY4(uVar5,uVar4);
        bVar11 = (bool)isCurrentModePrivileged();
        if (bVar11) {
          enableIRQinterrupts(((uint)uVar14 & 1) == 1);
        }
        return *(uint *)(iVar7 + 0x18);
      }
      _DAT_200018d8 = lVar12 + 0xb18e;
    }
    DAT_20001854 = 0;
    bVar11 = (bool)isCurrentModePrivileged();
    if (bVar11) {
      enableIRQinterrupts((uVar4 & 1) == 1);
    }
                    /* WARNING: Could not recover jumptable at 0x00000ddc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar4 = (*(code *)0xc9d)(uVar4);
    return uVar4;
  case 1:
    _DAT_e000ed04 = 0x10000000;
    InstructionSynchronizationBarrier(0xf);
    return 0x10000000;
  case 2:
    *(uint *)(_DAT_200018a0 + 0xc) = *param_1;
    *(undefined1 *)(iVar7 + 9) = 0;
    _DAT_e000ed04 = 0x10000000;
    InstructionSynchronizationBarrier(0xf);
    return 0x10000000;
  case 3:
    uVar4 = ((undefined4 *)*param_1)[1];
    pcVar9 = *(code **)*param_1;
    break;
  default:
    if (uVar4 < 0x40) {
      return uVar4;
    }
    pcVar9 = *(code **)(uVar4 * 4 + 0x13ed4);
    uVar4 = *param_1;
  }
  uVar4 = (*pcVar9)(uVar4);
  *param_1 = uVar4;
  return uVar4;
}

