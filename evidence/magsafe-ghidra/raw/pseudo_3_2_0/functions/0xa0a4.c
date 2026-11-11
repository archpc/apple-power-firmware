// rea decompile_all
// name: FUN_0000a0a4
// address: 0xa0a4
// body: available
// range: 0xa0a4-0xa13f inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0000a0a4(undefined1 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_20 [8];
  undefined1 local_18 [4];
  
  uVar1 = DAT_0000a148;
  uVar2 = 0;
  iVar3 = DAT_0000a14c + 0x30;
  do {
    if (uVar2 == 10) {
      return 0xffffffff;
    }
    *(undefined1 *)(uVar1 + 0x10) = 1;
    *(undefined1 **)(uVar1 + 0xc) = local_18;
    *(undefined2 *)(uVar1 + 8) = 0;
    *(undefined4 *)(uVar1 + 4) = 0;
    local_18[0] = param_1;
    FUN_00001334(iVar3,auStack_20);
    software_interrupt(0x41);
    FUN_00001378(iVar3,auStack_20);
    FUN_000013ac(DAT_0000a140);
    if ((uVar1 & 0xff) == 0) {
      *(undefined1 *)(uVar1 + 0x10) = 0;
      *(undefined4 *)(uVar1 + 0xc) = 0;
      *(short *)(uVar1 + 8) = (short)param_3;
      *(undefined4 *)(uVar1 + 4) = param_2;
      FUN_00001334(iVar3,auStack_20);
      software_interrupt(0x40);
      FUN_00001378(iVar3,auStack_20);
      if ((uVar1 & 0xff) == 0) {
        if (9 < uVar2) {
          return 0xffffffff;
        }
        return param_3;
      }
      FUN_000013ac(DAT_0000a144);
    }
    uVar2 = uVar2 + 1;
  } while( true );
}

