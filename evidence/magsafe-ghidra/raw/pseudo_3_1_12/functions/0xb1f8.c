// rea decompile_all
// name: FUN_0000b1f8
// address: 0xb1f8
// body: available
// range: 0xb1f8-0xb36b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000b1f8(int param_1,uint *param_2,int param_3,code *param_4)

{
  bool bVar1;
  ulonglong uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  longlong lVar11;
  uint local_1c;
  undefined1 local_18;
  
  iVar3 = DAT_0000b380;
  uVar5 = *param_2;
  if (param_3 == 3) {
    *(undefined1 *)(DAT_0000b380 + 0x10) = 1;
    FUN_00009634(param_2[2]);
  }
  lVar11 = FUN_00000e50();
  uVar2 = (ulonglong)DAT_0000b36c;
  uVar10 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar10 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  FUN_00009944();
  *(ulonglong *)(DAT_0000b384 + 0x48) = lVar11 + uVar2;
  FUN_00009ddc();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar10 & 1) == 1);
  }
  if ((int)uVar5 < 0) {
    iVar6 = 7;
  }
  else {
    iVar6 = -1;
  }
  if (param_1 == 1) {
    uVar9 = (uVar5 & 0x7fffffff) >> 0x1c;
    FUN_00002db0(1);
    iVar4 = DAT_0000b388;
    iVar6 = (uVar9 + iVar6) * 4;
    uVar10 = *(uint *)(*(int *)(*(int *)(DAT_0000b388 + 0x44) + 0x11c) + iVar6 + 8);
    if (*(char *)(*(int *)(DAT_0000b388 + 0x44) + 0x21) == '\0') {
      if (((uVar9 == 0) || (*(byte *)(*(int *)(DAT_0000b388 + 0x58) + 0x29) < uVar9)) ||
         (2 < *(uint *)(uVar9 * 4 + *(int *)(DAT_0000b388 + 0x58) + 0x98) >> 0x1e)) {
        *(undefined1 *)(DAT_0000b388 + 0x69) = 0;
        local_18 = 4;
      }
      else {
        iVar6 = FUN_00002aa8(1,uVar5);
        if (iVar6 == 0) {
          local_18 = 3;
        }
        else {
          *(undefined1 *)(iVar4 + 0x69) = 0;
          local_18 = 4;
        }
      }
      (*param_4)(1,&local_1c);
      *(undefined1 *)(iVar3 + 0x11) = 0;
    }
    else {
      *(undefined1 *)(iVar3 + 0x11) = 1;
      uVar9 = DAT_0000b370;
      uVar8 = *(uint *)(DAT_0000b38c + iVar6 + 0x268);
      iVar6 = 0;
      uVar7 = 0;
      if ((uVar8 >> 0x1e | 2) == 2) {
        uVar7 = uVar10 & DAT_0000b370;
        iVar6 = FUN_0000a478(uVar8 >> 10 & DAT_0000b370);
      }
      local_1c = DAT_0000b374 & iVar6 * 0x400 + uVar5;
      if (uVar7 < local_1c >> 10) {
        local_1c = uVar7 << 10;
      }
      uVar9 = iVar6 + uVar5 & uVar9;
      local_1c = uVar9 + (DAT_0000b378 & uVar5) + local_1c;
      if (uVar7 < uVar9) {
        local_1c = (local_1c & DAT_0000b37c) + uVar7;
      }
      if (*(char *)(iVar4 + 0x55) == '\x01') {
        local_18 = 3;
        (*param_4)(0);
        *(undefined1 *)(iVar4 + 0x55) = 0;
      }
      else {
        *(uint *)(iVar4 + 0x50) = local_1c;
        *(code **)(iVar3 + 0x5c) = param_4;
        iVar6 = FUN_00002d14();
        if (iVar6 == 0) {
          *(undefined1 *)(iVar4 + 0x54) = 1;
        }
        else {
          *(undefined1 *)(iVar3 + 0x12) = 1;
          local_18 = 0xc;
          (*param_4)(1);
        }
      }
    }
  }
  return;
}

