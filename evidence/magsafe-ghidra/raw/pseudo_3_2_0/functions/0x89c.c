// rea decompile_all
// name: FUN_0000089c
// address: 0x89c
// body: available
// range: 0x89c-0x951 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_0000089c(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar1 = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar3 = param_1 >> 1 | param_1;
    uVar3 = uVar3 >> 2 | uVar3;
    uVar3 = uVar3 >> 4 | uVar3;
    uVar3 = uVar3 >> 8 | uVar3;
    uVar3 = ~(uVar3 >> 0x10 | uVar3);
    uVar3 = uVar3 - (uVar3 >> 1 & DAT_00000954);
    uVar3 = (uVar3 & DAT_00000958) + (uVar3 >> 2 & DAT_00000958);
    uVar5 = DAT_00000960 * (uVar3 + (uVar3 >> 4) & DAT_0000095c) >> 0x18;
    uVar3 = param_2 >> 1 | param_2;
    uVar3 = uVar3 >> 2 | uVar3;
    uVar3 = uVar3 >> 4 | uVar3;
    uVar3 = uVar3 >> 8 | uVar3;
    uVar3 = ~(uVar3 >> 0x10 | uVar3);
    uVar3 = uVar3 - (uVar3 >> 1 & DAT_00000954);
    uVar3 = (uVar3 & DAT_00000958) + (uVar3 >> 2 & DAT_00000958);
    uVar4 = DAT_00000960 * (uVar3 + (uVar3 >> 4) & DAT_0000095c) >> 0x18;
    uVar3 = uVar4 - uVar5;
    if ((uVar3 < 0x20) && (uVar1 = param_1, uVar3 != 0x1f)) {
      iVar2 = ~uVar4 + uVar5;
      uVar1 = param_1 >> (uVar3 + 1 & 0xff);
      param_1 = param_1 << (0x1f - uVar3 & 0xff);
      uVar3 = 0;
      do {
        uVar1 = uVar1 * 2 - ((int)param_1 >> 0x1f);
        uVar4 = ~uVar1;
        if ((int)(uVar4 + param_2) < 0) {
          uVar1 = uVar1 - param_2;
        }
        param_1 = uVar3 | param_1 << 1;
        uVar3 = -((int)(uVar4 + param_2) >> 0x1f);
        bVar6 = iVar2 != -1;
        iVar2 = iVar2 + 1;
      } while (bVar6);
      uVar1 = uVar3 + param_1 * 2;
    }
  }
  return uVar1;
}

