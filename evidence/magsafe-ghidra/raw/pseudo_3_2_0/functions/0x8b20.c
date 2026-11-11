// rea decompile_all
// name: FUN_00008b20
// address: 0x8b20
// body: available
// range: 0x8b20-0x8bed inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00008b20(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 *puVar5;
  int iVar6;
  char *pcVar7;
  
  iVar6 = *(int *)(DAT_00008bf8 + param_1 * 4);
  *(uint *)(iVar6 + 0x128) = *(uint *)(iVar6 + 0x128) & 0xffffdfff;
  *(undefined4 *)(iVar6 + 0x118) = DAT_00008bf0;
  puVar5 = (undefined4 *)(DAT_00008bfc + param_1 * 0x5c);
  if (*(char *)((int)puVar5 + 0x53) < '\0') {
    *(uint *)(iVar6 + 0x120) = *(uint *)(iVar6 + 0x120) | 0x4000;
  }
  else {
    puVar4 = (uint *)(iVar6 + 0x128);
    pcVar7 = (char *)((int)puVar5 + 0x53);
    if ((*(uint *)(iVar6 + 0xa4) & 0x100001) == 0) {
      *(undefined1 *)((int)puVar5 + 0x51) = 0;
      iVar2 = FUN_0000843c();
      if (iVar2 != 0) {
        *puVar4 = *puVar4 | 0x100000;
      }
      *puVar4 = DAT_00008bf4 | *puVar4;
      *(uint *)(iVar6 + 4) =
           (*(uint *)(iVar6 + 4) & 0xfffffffd) + (uint)(*(char *)((int)puVar5 + 0x52) == '\x01') * 2
      ;
      uVar3 = *(uint *)(iVar6 + 0xf4);
      cVar1 = *pcVar7;
      *(undefined1 *)(puVar5 + 0x15) = 0;
      *pcVar7 = *pcVar7 + -1;
      *(uint *)(iVar6 + 0xf4) = (uVar3 & 0xfff5ffff) + (uint)(cVar1 != '\0') * 0x80000 + 0x20000;
    }
    else {
      *pcVar7 = *pcVar7 + -1;
      *puVar4 = *puVar4 | 0x2000;
      (*(code *)*puVar5)(param_1,0);
    }
  }
  return;
}

