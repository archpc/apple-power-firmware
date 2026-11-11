// rea decompile_all
// name: FUN_00008548
// address: 0x8548
// body: available
// range: 0x8548-0x8763 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_00008548(int param_1)

{
  short sVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  byte *pbVar11;
  
  iVar10 = DAT_00008768 + param_1 * 0x1cc;
  if (*(char *)(iVar10 + 0x31) == '\0') {
    return 0;
  }
  iVar8 = *(int *)(DAT_0000876c + param_1 * 4);
  puVar7 = (uint *)(iVar8 + 0x124);
  puVar9 = (uint *)(iVar8 + 0xa4);
  if (*(char *)(iVar10 + 0x1c) == '\x01') {
    *(undefined4 *)(iVar8 + 0x11c) = 0x10;
    *(uint *)(iVar8 + 300) = *(uint *)(iVar8 + 300) | 0x10;
    if (*(char *)(iVar10 + 0x15) == '\x01') {
      if (*(char *)(iVar10 + 0x1f) == '\x04') {
        uVar5 = 1;
        goto LAB_00008678;
      }
      *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) & 0xfffffcff;
      *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) | 0x200;
      uVar4 = 0x20;
      *(undefined4 *)(iVar8 + 0x11c) = 0x20;
      *(uint *)(iVar8 + 300) = *(uint *)(iVar8 + 300) | 0x20;
      if (-1 < (int)(*puVar9 << 0xe)) {
        return 0x20;
      }
      uVar6 = *puVar7;
      goto LAB_0000875c;
    }
    *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) & 0xfffff0ff;
    *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) | 0xf00;
    *(undefined4 *)(iVar8 + 0x11c) = 0x60;
    *(uint *)(iVar8 + 300) = *(uint *)(iVar8 + 300) | 0x60;
    sVar1 = *(short *)(iVar10 + 0x3a);
    sVar3 = FUN_00008778(param_1);
    if (sVar1 == sVar3) {
      FUN_00002c9c(param_1);
      FUN_00002c80(param_1);
      return (uint)*(ushort *)(DAT_00008770 + param_1 * 0x5c + 0x46);
    }
  }
  else {
    if (*(char *)(iVar10 + 0x15) != '\x01') {
      uVar5 = 0;
LAB_00008678:
      uVar4 = FUN_000084a4(param_1,uVar5);
      return uVar4;
    }
    *(uint *)(iVar8 + 0x18c) = *(uint *)(iVar8 + 0x18c) & 0xfffffeff;
    *(uint *)(iVar8 + 0x18c) = *(uint *)(iVar8 + 0x18c) | 0x10;
    uVar6 = DAT_00008764 + 0x20;
    *(uint *)(iVar8 + 0x18c) = *(uint *)(iVar8 + 0x18c) & uVar6;
    iVar2 = DAT_00008774;
    uVar4 = (uint)*(byte *)(DAT_00008774 + (uint)*(byte *)(iVar10 + 0x35) * 4);
    *(uint *)(iVar8 + 0x18c) = uVar4 << 9 | *(uint *)(iVar8 + 0x18c) | uVar4 << 5;
    FUN_00000b60();
    pbVar11 = (byte *)(iVar10 + 0x35);
    if ((*puVar9 & 0x60000) == 0x40000) {
      *(uint *)(iVar8 + 0x18c) = *(uint *)(iVar8 + 0x18c) & 0xffffff1f;
      *(uint *)(iVar8 + 0x18c) =
           *(uint *)(iVar8 + 0x18c) | (uint)*(byte *)(iVar2 + (uint)*pbVar11 * 4 + 1) << 5;
      *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) & DAT_00008764;
      *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) | 0x600;
      FUN_00000b60(0x1e0);
      *(undefined4 *)(iVar8 + 0x11c) = 0x70;
      *(uint *)(iVar8 + 300) = *(uint *)(iVar8 + 300) | 0x60;
      if (-1 < (int)(*puVar9 << 0xe)) {
LAB_0000874a:
        if ((*puVar9 & 0x40000) != 0) {
          return *puVar9;
        }
LAB_00008752:
        uVar4 = *puVar7;
        uVar6 = 0x40;
        goto LAB_0000875c;
      }
    }
    else if ((*puVar9 & 0x60000) == 0x20000) {
      *(uint *)(iVar8 + 0x18c) = *(uint *)(iVar8 + 0x18c) & 0xfffff1ff;
      *(uint *)(iVar8 + 0x18c) =
           *(uint *)(iVar8 + 0x18c) | (uint)*(byte *)(iVar2 + (uint)*pbVar11 * 4 + 1) << 9;
      *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) & DAT_00008764;
      *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) | 0x900;
      FUN_00000b60(0x1e0);
      *(undefined4 *)(iVar8 + 0x11c) = 0x70;
      *(uint *)(iVar8 + 300) = *(uint *)(iVar8 + 300) | 0x60;
      if ((*puVar9 & 0x20000) != 0) {
        if ((*puVar9 & 0x40000) == 0) {
          return *puVar9;
        }
        goto LAB_00008752;
      }
    }
    else {
      *(uint *)(iVar8 + 0x18c) = *(uint *)(iVar8 + 0x18c) & uVar6;
      uVar4 = (uint)*(byte *)(iVar2 + (uint)*pbVar11 * 4 + 1);
      *(uint *)(iVar8 + 0x18c) = uVar4 << 9 | *(uint *)(iVar8 + 0x18c) | uVar4 << 5;
      *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) & DAT_00008764;
      *(uint *)(iVar8 + 0x114) = *(uint *)(iVar8 + 0x114) | 0x500;
      FUN_00000b60(0x1e0);
      *(undefined4 *)(iVar8 + 0x11c) = 0x70;
      *(uint *)(iVar8 + 300) = *(uint *)(iVar8 + 300) | 0x60;
      if ((*puVar9 & 0x20000) != 0) goto LAB_0000874a;
    }
  }
  uVar4 = *puVar7;
  uVar6 = 0x20;
LAB_0000875c:
  *puVar7 = uVar6 | uVar4;
  return uVar4;
}

