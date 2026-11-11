// rea decompile_all
// name: FUN_0000c950
// address: 0xc950
// body: available
// range: 0xc950-0xca99 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_0000c950(char *param_1)

{
  bool bVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  undefined1 uVar5;
  char *pcVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint local_28;
  ushort local_20 [2];
  char local_1c [8];
  
  iVar4 = DAT_0000cab0;
  if (*(char *)(DAT_0000cab0 + 0x1a) != '\x01') {
    return 0xf;
  }
  *(undefined1 *)(DAT_0000cab0 + 0x1a) = 2;
  local_1c[0] = *param_1 << 1;
  uVar12 = (uint)(byte)param_1[0x10];
  pcVar6 = *(char **)(param_1 + 0xc);
  if (pcVar6 != (char *)0x0) {
    if (uVar12 == 0) {
      uVar12 = 0;
    }
    else {
      for (bVar7 = 1; bVar7 <= uVar12; bVar7 = bVar7 + 1) {
        local_1c[bVar7] = *pcVar6;
        pcVar6 = pcVar6 + 1;
        *(char **)(param_1 + 0xc) = pcVar6;
      }
    }
  }
  local_28 = 0;
  *DAT_0000ca9c = 0xffffffff;
  FUN_0000cab4(local_1c,uVar12 + 1 & 0xff,local_20);
  bVar1 = true;
  *DAT_0000caa0 = 1;
  puVar3 = DAT_0000caa8;
  uVar12 = DAT_0000caa4;
  uVar9 = DAT_0000caa4;
  while( true ) {
    piVar2 = DAT_0000caa0;
    if ((((*puVar3 & 0x1f) == 0) && (*DAT_0000caac << 0x19 < 0)) && (-1 < (int)(*puVar3 << 0x10))) {
      uVar9 = (uint)*(ushort *)(param_1 + 8);
      uVar10 = 0;
      if (uVar9 == 0) goto LAB_0000c9ee;
      local_28 = 0;
      uVar11 = uVar9;
      goto LAB_0000ca1c;
    }
    if ((uVar9 < 2) || ((*DAT_0000ca9c & 2) != 0)) break;
    FUN_00000b60(0x30);
    uVar9 = uVar9 - 1;
  }
  uVar10 = 0xc;
  if (*(short *)(param_1 + 8) == 0) {
    bVar1 = false;
LAB_0000c9ee:
    *DAT_0000caa0 = 0x10;
    while (*piVar2 << 0x1b < 0) {
      if (uVar12 < 2) goto LAB_0000ca86;
      FUN_00000b60(0x30);
      uVar12 = uVar12 - 1;
    }
    if (bVar1) goto LAB_0000ca8e;
  }
LAB_0000ca88:
  FUN_0000cae4();
  local_28 = uVar10;
LAB_0000ca8e:
  *(undefined1 *)(iVar4 + 0x1a) = 1;
  return local_28;
LAB_0000ca1c:
  uVar8 = uVar10 & 0xffff;
  if (uVar9 <= uVar8) goto LAB_0000ca8e;
  uVar5 = (undefined1)uVar11;
  if (0xf < (uVar11 & 0xffff)) {
    uVar5 = 0x10;
  }
  FUN_0000cab4(*(int *)(param_1 + 4) + uVar8,uVar5,local_20);
  piVar2 = DAT_0000caa0;
  uVar11 = uVar11 - local_20[0];
  if ((uVar11 & 0xffff) == 0) {
    *DAT_0000caa0 = 0x10;
    goto LAB_0000ca72;
  }
  uVar10 = 0xc;
  if ((uVar12 < 2) || ((*DAT_0000ca9c & 2) != 0)) goto LAB_0000ca88;
  uVar10 = uVar8 + local_20[0];
  FUN_00000b60(0x30);
  uVar12 = uVar12 - 1;
  uVar9 = (uint)*(ushort *)(param_1 + 8);
  goto LAB_0000ca1c;
LAB_0000ca72:
  if (-1 < *piVar2 << 0x1b) goto LAB_0000ca8e;
  if ((int)uVar12 < 2) goto LAB_0000ca86;
  FUN_00000b60(0x30);
  uVar12 = uVar12 - 1;
  goto LAB_0000ca72;
LAB_0000ca86:
  uVar10 = 0xc;
  goto LAB_0000ca88;
}

