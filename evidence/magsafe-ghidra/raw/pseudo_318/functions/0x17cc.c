// rea decompile_all
// name: FUN_000017cc
// address: 0x17cc
// body: available
// range: 0x17cc-0x1821 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined8 FUN_000017cc(ushort *param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  ushort *puVar7;
  ushort *local_18;
  
  local_18 = param_1;
  for (iVar3 = 0; iVar3 != param_3; iVar3 = iVar3 + 1) {
    uVar1 = *(ushort *)(param_2 + iVar3 * 2);
    puVar2 = local_18;
    for (iVar6 = 0; iVar6 != 0x10; iVar6 = iVar6 + 1) {
      uVar5 = 0;
      puVar7 = puVar2;
      for (uVar4 = (uint)uVar1 * (uint)*(ushort *)(param_4 + iVar6 * 2); uVar4 != 0 || uVar5 != 0;
          uVar4 = uVar4 >> 0x10) {
        uVar5 = (uVar4 & 0xffff) + uVar5 + (uint)*puVar7;
        *puVar7 = (ushort)uVar5;
        uVar5 = uVar5 >> 0x10;
        puVar7 = puVar7 + 1;
      }
      puVar2 = puVar2 + 1;
    }
    local_18 = local_18 + 1;
  }
  return CONCAT44(param_3,param_2);
}

