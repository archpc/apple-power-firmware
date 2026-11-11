// rea decompile_all
// name: FUN_0000cd78
// address: 0xcd78
// body: available
// range: 0xcd78-0xcdad inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000cd78(undefined1 param_1,undefined1 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_24 [8];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  
  uVar1 = DAT_0000cdb0;
  local_1c[0] = param_2;
  local_18[0] = param_1;
  FUN_0000131c(DAT_0000cdb0,auStack_24);
  iVar2 = DAT_0000cdb4;
  *(undefined1 *)(DAT_0000cdb4 + 0x10) = 1;
  *(undefined1 **)(iVar2 + 0xc) = local_18;
  *(undefined2 *)(iVar2 + 8) = 1;
  *(undefined1 **)(iVar2 + 4) = local_1c;
  software_interrupt(0x41);
  FUN_00001360(uVar1,auStack_24);
  return;
}

