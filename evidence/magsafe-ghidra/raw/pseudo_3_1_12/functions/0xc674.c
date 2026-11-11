// rea decompile_all
// name: FUN_0000c674
// address: 0xc674
// body: available
// range: 0xc674-0xc721 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000c674(int param_1,int param_2,code *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_34;
  undefined1 auStack_30 [24];
  char local_18;
  undefined1 local_17;
  
  if (param_4 == 0) {
    iVar2 = 4;
  }
  else {
    iVar2 = 8;
  }
  uVar7 = *(uint *)(param_2 + 8 + iVar2);
  uVar5 = *(uint *)(param_2 + 8 + param_4 * 4);
  FUN_000001a2(&local_34,0);
  uVar1 = uVar5 & 0x7ff;
  uVar6 = uVar1 >> 6;
  uVar4 = DAT_0000c724;
  if (param_4 == 0) {
    uVar4 = DAT_0000c724 + 0xf;
  }
  iVar2 = DAT_0000c728;
  if (((param_1 == 1) || (iVar2 = DAT_0000c72c, param_1 == 0)) &&
     (uVar3 = uVar7 & 0xffff, (uVar6 < 0x15 && (uVar7 & 0x7000000) == 0) && uVar3 + uVar6 < 9)) {
    uVar4 = uVar4 + uVar6 * 0x40;
    FUN_00000170(auStack_30,iVar2 + uVar3,uVar6);
  }
  else {
    uVar4 = uVar4 & DAT_0000c724 + 1 | 0x20;
  }
  local_17 = 0;
  local_18 = (char)(uVar1 >> 8);
  if ((uVar5 & 0xff) >> 6 != 0) {
    local_18 = local_18 + '\x01';
  }
  local_18 = local_18 + '\x01';
  local_34 = uVar4;
  (*param_3)(param_1);
  return;
}

