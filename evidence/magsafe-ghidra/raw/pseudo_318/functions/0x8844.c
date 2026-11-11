// rea decompile_all
// name: FUN_00008844
// address: 0x8844
// body: available
// range: 0x8844-0x8939 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined8 FUN_00008844(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  uint *puVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  uVar6 = 0x110;
  if (param_2 != 1) {
    uVar6 = 0;
  }
  iVar5 = *(int *)(DAT_0000893c + param_1 * 4);
  puVar2 = (uint *)(iVar5 + 0x18c);
  iVar9 = DAT_00008940 + param_1 * 0x1cc;
  uVar7 = (uint)*(byte *)(iVar9 + 0x15);
  bVar10 = (*(uint *)(iVar5 + 0x18c) & 0x110) != uVar6;
  if (bVar10) {
    *puVar2 = *puVar2 & 0xfffffeef;
    *puVar2 = *puVar2 | uVar6;
  }
  if (uVar7 == 1) {
    pbVar3 = (byte *)(DAT_00008944 + (uint)*(byte *)(iVar9 + 0x35) * 4);
    pbVar1 = pbVar3 + 1;
  }
  else {
    if (param_3 == 0) {
      iVar8 = 1;
    }
    else {
      iVar8 = 2;
    }
    pbVar1 = (byte *)(DAT_00008944 + 0xc + iVar8);
    pbVar3 = (byte *)(DAT_00008944 + 0xc + param_3);
  }
  uVar6 = (uint)*pbVar1 << 9 | (uint)*pbVar3 << 5;
  if ((*puVar2 & 0xee0) == uVar6) {
    uVar6 = uVar7;
    if (!bVar10) goto LAB_000088ea;
  }
  else {
    *puVar2 = *puVar2 & 0xfffff11f;
    *puVar2 = *puVar2 | uVar6;
  }
  FUN_00000b60(0x960);
  uVar6 = (uint)*(byte *)(iVar9 + 0x15);
LAB_000088ea:
  iVar9 = 2;
  if (uVar7 != 1) {
    iVar9 = param_3;
  }
  iVar8 = 2;
  if (param_3 == 0) {
    iVar8 = 1;
  }
  if (uVar6 == 1) {
    iVar8 = 1;
  }
  iVar4 = 3;
  uVar7 = *(uint *)(iVar5 + 0xa4) & 0x60000;
  if (uVar7 != 0x40000) {
    iVar8 = iVar9;
  }
  iVar5 = iVar8;
  if (uVar6 == 1) {
    iVar5 = 0;
  }
  if (uVar7 != 0) {
    iVar5 = iVar8;
  }
  if (param_3 == 0) {
    iVar4 = 2;
  }
  if ((uVar7 ^ 0x60000) + uVar6 == 0) {
    iVar5 = iVar4;
  }
  return CONCAT44(param_2,iVar5);
}

