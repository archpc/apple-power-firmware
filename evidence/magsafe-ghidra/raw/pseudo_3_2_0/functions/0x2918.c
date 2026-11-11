// rea decompile_all
// name: FUN_00002918
// address: 0x2918
// body: available
// range: 0x2918-0x2a0d inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00002918(uint param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined2 local_18 [2];
  
  iVar1 = DAT_00002a14;
  if (1 < param_1) {
    return 7;
  }
  if ((param_1 == 1) && (*(char *)(DAT_00002a10 + 3) != '\0')) {
    return 0xf;
  }
  if ((param_5 == 0) && (*(char *)(DAT_00002a14 + param_1 * 0x1cc + 0x43) != '\0')) {
    return 0xf;
  }
  FUN_0000a908();
  iVar1 = iVar1 + param_1 * 0x1cc;
  if (*(char *)(iVar1 + 0x31) == '\0') {
    return 0xb;
  }
  if (*(char *)(iVar1 + 0x1d) != '\0') {
    if (*(char *)(iVar1 + 0x2f) == '\0') {
      if ((param_2 != 5) && (*(int *)(iVar1 + 0x48) != 0)) {
        return 0xf;
      }
    }
    else if (param_2 != 5) {
      return 0xf;
    }
    if ((*(char *)(iVar1 + 0x45) != '#') &&
       (((param_2 != 0 || (*(char *)(iVar1 + 0x45) != '\x0f')) && (param_2 != 5)))) {
      return 0xb;
    }
    if (((param_2 != 5) && (1 < *(byte *)(iVar1 + 0x3e))) &&
       ((*(char *)(iVar1 + 0x1c9) != '\x01' && ((*(char *)(iVar1 + 0x15) == '\0' && (param_5 == 0)))
        ))) {
      if (*(char *)(iVar1 + 0x16) != '\x03') {
        return 0xe;
      }
      local_18[0] = FUN_000088d4(param_1);
      if (*(char *)((int)local_18 + (uint)*(byte *)(iVar1 + 0x1a)) != '\x03') {
        return 0xe;
      }
    }
    *(char *)(iVar1 + 0x2e) = (char)param_2;
    *(undefined1 *)(iVar1 + 0x2f) = 1;
    *(undefined4 *)(iVar1 + 100) = param_4;
    if (param_3 != 0) {
      FUN_00000170(*(undefined4 *)(iVar1 + 0x6c),param_3,0x2c);
    }
    FUN_000028b8(param_1,0x200);
    return 0;
  }
  return 0xb;
}

