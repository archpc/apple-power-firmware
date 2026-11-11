// rea decompile_all
// name: FUN_0000a758
// address: 0xa758
// body: available
// range: 0xa758-0xa7d1 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0000a758(void)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  
  if (*(char *)(DAT_0000a7d4 + 0xc) == '\0') {
    cVar2 = -1;
    if (*(char *)(DAT_0000a7d4 + 0xb) == '\0') {
      if (((*(char *)(DAT_0000a7d8 + 0x21) != '\0') && (*(char *)(DAT_0000a7d8 + 0x45) == '#')) &&
         (cVar2 = -1, *(char *)(DAT_0000a7d8 + 0x1ed) == '\0')) {
        piVar3 = (int *)(DAT_0000a7d8 + 0x4c);
        for (uVar4 = 0; uVar4 != 2; uVar4 = uVar4 + 1) {
          if ((*(char *)((int)piVar3 + -0x1b) != '\0') &&
             (((*piVar3 != 0 || (piVar3[-1] != 0)) ||
              (iVar1 = FUN_0000c900(uVar4 & 0xff,0x11,0x13), iVar1 != 0)))) goto LAB_0000a78e;
          piVar3 = piVar3 + 0x73;
        }
        cVar2 = '\x01';
      }
    }
  }
  else {
    cVar2 = '\x01';
  }
LAB_0000a78e:
  return (int)cVar2;
}

