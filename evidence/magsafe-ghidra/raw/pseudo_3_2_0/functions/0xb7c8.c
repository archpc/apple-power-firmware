// rea decompile_all
// name: FUN_0000b7c8
// address: 0xb7c8
// body: available
// range: 0xb7c8-0xb875 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000b7c8(uint param_1,uint param_2,code *param_3)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint local_34 [4];
  uint local_24;
  undefined1 local_18;
  undefined1 local_17;
  
  uVar4 = param_2 & 0x1f;
  if (uVar4 == 0) {
    return;
  }
  if (5 < uVar4) {
    return;
  }
  uVar2 = (param_2 & 0x7ff) >> 8;
  iVar3 = *(int *)(DAT_0000b87c + uVar4 * 4);
  FUN_00000170(local_34,*(undefined4 *)(DAT_0000b878 + uVar4 * 4),iVar3 << 2);
  pbVar1 = DAT_0000b884;
  if (uVar4 == 5) {
    if (*DAT_0000b884 == param_1) {
      *(undefined1 *)(DAT_0000b888 + 0x27) = 0;
      *pbVar1 = 0xff;
LAB_0000b850:
      if (uVar2 == 1) goto LAB_0000b866;
    }
  }
  else {
    if (uVar4 != 4) {
      if (uVar4 == 1) {
        local_24 = (local_24 & 0xfffffff) + (uint)*(byte *)(DAT_0000b880 + 0x5d) * 0x10000000;
      }
      goto LAB_0000b866;
    }
    if ((*DAT_0000b884 == 0xff) || (*DAT_0000b884 == param_1)) {
      *(undefined1 *)(DAT_0000b888 + 0x27) = 0;
      *pbVar1 = (byte)param_1;
      goto LAB_0000b850;
    }
  }
  local_34[0] = (local_34[0] & 0xfffff83f) + uVar2 * 0x100 + 0x80;
LAB_0000b866:
  local_17 = 0;
  local_18 = (undefined1)iVar3;
  (*param_3)(param_1);
  return;
}

