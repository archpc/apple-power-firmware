// rea decompile_all
// name: FUN_0000c5b8
// address: 0xc5b8
// body: available
// range: 0xc5b8-0xc639 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000c5b8(int param_1,int param_2,code *param_3,int param_4)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_2 + param_4 * 4 + 8);
  iVar1 = DAT_0000c640 + param_1 * 0x30;
  if (*(char *)(*(int *)(iVar1 + 4) + 0x14) == '\x01') {
    uVar3 = (uVar3 & 0x3f) >> 4;
    if (uVar3 != 0) {
      if (uVar3 != 1) {
        return;
      }
      if (*(char *)(iVar1 + 10) == '\x02') {
        if (*(char *)(DAT_0000c640 + 0x2b) == '\x01') {
          return;
        }
        if (*(char *)(DAT_0000c640 + 10) != '\x05') {
          return;
        }
        uVar2 = 10;
      }
      else {
        uVar2 = 0xd;
      }
      *(undefined1 *)(iVar1 + 0x2a) = uVar2;
      return;
    }
    uVar2 = 0xc;
  }
  else if (*(char *)(iVar1 + 10) == '\x04') {
    if ((uVar3 & 0x3f) >> 4 != 0) {
      return;
    }
    uVar2 = 0xd;
  }
  else {
    if (*(char *)(iVar1 + 10) != '\x02') {
      return;
    }
    if ((uVar3 & 0x3f) >> 4 != 0) {
      return;
    }
    uVar2 = 10;
  }
  *(undefined1 *)(iVar1 + 0x2a) = uVar2;
  (*param_3)();
  return;
}

