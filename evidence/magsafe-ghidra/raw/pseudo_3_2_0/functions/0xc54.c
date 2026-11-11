// rea decompile_all
// name: FUN_00000c54
// address: 0xc54
// body: available
// range: 0xc54-0xc6b inclusive
// range: 0xc70-0xe37 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint FUN_00000c54(uint *param_1)

{
  int *piVar1;
  uint *puVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  code *pcVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  undefined4 in_cr14;
  longlong lVar13;
  longlong lVar14;
  undefined8 uVar15;
  byte local_34 [4];
  undefined1 auStack_30 [8];
  code *local_28;
  uint *puStack_1c;
  
  iVar11 = _DAT_20001890;
  uVar4 = (uint)*(byte *)(param_1[6] - 2);
  switch(uVar4) {
  case 0:
    FUN_00000c40();
    coprocessor_store(0,in_cr14,param_1);
    uVar4 = 0;
    bVar12 = (bool)isCurrentModePrivileged();
    if (bVar12) {
      uVar4 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    DAT_20001848 = 1;
    _DAT_40030044 = _DAT_40030044 | 1;
    puStack_1c = param_1;
    lVar13 = FUN_00000e38();
    iVar11 = (int)((ulonglong)lVar13 >> 0x20);
    uVar5 = (uint)lVar13;
    if (((int)(uint)(_DAT_200018d0 == 0) <= _DAT_200018d4) &&
       (bVar12 = uVar5 < _DAT_200018d0, lVar13 = lVar13 - CONCAT44(_DAT_200018d4,_DAT_200018d0),
       uVar5 = (uint)lVar13,
       lVar13 < 0 ==
       (SBORROW4(iVar11,_DAT_200018d4) != SBORROW4(iVar11 - _DAT_200018d4,(uint)bVar12)))) {
      _DAT_200018d4 = 0;
      _DAT_200018d0 = 0;
      while (uVar6 = 0, DAT_20000299 != 0) {
        local_34[0] = *_DAT_2000029c;
        iVar10 = *(int *)((uint)local_34[0] * 0x10 + 0x2000018c);
        puVar2 = (uint *)((uint)local_34[0] * 0x10 + 0x20000188);
        uVar5 = *puVar2;
        lVar13 = *(longlong *)puVar2;
        lVar14 = FUN_00000e38();
        iVar11 = (int)((ulonglong)lVar14 >> 0x20);
        lVar13 = lVar14 - lVar13;
        uVar6 = (undefined4)lVar13;
        if (lVar13 < 0 !=
            (SBORROW4(iVar11,iVar10) != SBORROW4(iVar11 - iVar10,(uint)((uint)lVar14 < uVar5))))
        break;
        FUN_00001178(&DAT_20000298,local_34,0x16c5,0,uVar4);
        bVar3 = local_34[0];
        iVar11 = (uint)local_34[0] * 0x10;
        FUN_00000170(auStack_30,iVar11 + 0x20000188,0x10);
        *(undefined4 *)(iVar11 + 0x20000188) = 0;
        *(undefined4 *)(iVar11 + 0x20000190) = 0;
        *(undefined4 *)(iVar11 + 0x2000018c) = 0;
        _DAT_2000029c[DAT_20000299] = bVar3;
        (*local_28)(auStack_30);
      }
      uVar5 = FUN_0000126c(uVar6);
    }
    lVar13 = FUN_00000e38(uVar5);
    iVar11 = (int)((ulonglong)lVar13 >> 0x20);
    uVar5 = (uint)lVar13;
    if (_DAT_200018d0 == 0 && _DAT_200018d4 == 0) {
      uVar7 = 0x8000;
    }
    else {
      uVar7 = _DAT_200018d0 - uVar5;
      uVar9 = uVar7;
      if (-1 < (int)((_DAT_200018d4 - iVar11) - (uint)(_DAT_200018d0 < uVar5))) {
        uVar9 = 0x8000;
      }
      if (0x7fff < uVar7) {
        uVar7 = 0x8000;
      }
      if (_DAT_200018d4 - iVar11 != (uint)(_DAT_200018d0 < uVar5)) {
        uVar7 = uVar9;
      }
    }
    if ((int)uVar7 < 4) {
      uVar7 = 3;
    }
    _DAT_40030040 = _DAT_4003003c + uVar7 & 0xffff;
    if ((int)((_DAT_200018cc - iVar11) - (uint)(_DAT_200018c8 < uVar5)) < 0 !=
        (SBORROW4(_DAT_200018cc,iVar11) !=
        SBORROW4(_DAT_200018cc - iVar11,(uint)(_DAT_200018c8 < uVar5)))) {
      FUN_00000f54(0x20000100,_DAT_200018c8 - uVar5);
      _DAT_200000d0 = _DAT_200000d0 + -1;
      if (_DAT_200000d0 == 0) {
        FUN_00012e20(&DAT_000133c9);
        uVar15 = FUN_00000bcc();
        if (uVar5 != 0) {
          uVar6 = 0;
          bVar12 = (bool)isCurrentModePrivileged();
          if (bVar12) {
            uVar6 = isIRQinterruptsEnabled();
          }
          uVar15 = CONCAT44(DAT_00000e78,uVar6);
          disableIRQinterrupts();
        }
        iVar11 = (int)((ulonglong)uVar15 >> 0x20);
        iVar10 = *(int *)(iVar11 + 0x44);
        uVar4 = *DAT_00000e70;
        *(uint *)(iVar11 + 0x44) = uVar4 & 0xffff;
        iVar11 = DAT_00000e7c;
        uVar4 = (uVar4 & 0xffff) - iVar10;
        if ((int)uVar4 < 0) {
          uVar4 = uVar4 + DAT_00000e74;
        }
        piVar1 = (int *)(DAT_00000e7c + 0x14);
        uVar5 = *(uint *)(DAT_00000e7c + 0x10);
        *(uint *)(DAT_00000e7c + 0x10) = uVar5 + uVar4;
        *(uint *)(iVar11 + 0x14) = *piVar1 + (uint)CARRY4(uVar5,uVar4);
        bVar12 = (bool)isCurrentModePrivileged();
        if (bVar12) {
          enableIRQinterrupts(((uint)uVar15 & 1) == 1);
        }
        return *(uint *)(iVar11 + 0x10);
      }
      _DAT_200018c8 = lVar13 + 0xb18e;
    }
    DAT_20001848 = 0;
    bVar12 = (bool)isCurrentModePrivileged();
    if (bVar12) {
      enableIRQinterrupts((uVar4 & 1) == 1);
    }
                    /* WARNING: Could not recover jumptable at 0x00000e0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar4 = (*(code *)0xcbd)();
    return uVar4;
  case 1:
    _DAT_e000ed04 = 0x10000000;
    InstructionSynchronizationBarrier(0xf);
    return 0x10000000;
  case 2:
    *(uint *)(_DAT_20001890 + 0xc) = *param_1;
    *(undefined1 *)(iVar11 + 9) = 0;
    _DAT_e000ed04 = 0x10000000;
    InstructionSynchronizationBarrier(0xf);
    return 0x10000000;
  case 3:
    uVar4 = ((undefined4 *)*param_1)[1];
    pcVar8 = *(code **)*param_1;
    break;
  default:
    if (uVar4 < 0x40) {
      return uVar4;
    }
    pcVar8 = *(code **)(uVar4 * 4 + 0x14124);
    uVar4 = *param_1;
  }
  uVar4 = (*pcVar8)(uVar4);
  *param_1 = uVar4;
  return uVar4;
}

