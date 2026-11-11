// rea decompile_all
// name: FUN_0000cb2c
// address: 0xcb2c
// body: available
// range: 0xcb2c-0xccc3 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0000cb2c(char *param_1)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int local_38;
  uint local_28;
  uint local_24;
  ushort local_20 [2];
  char local_1c;
  char local_1b [7];
  
  iVar5 = DAT_0000ccd8;
  if (*(char *)(DAT_0000ccd8 + 0x22) != '\x01') {
    return 0xf;
  }
  *(undefined1 *)(DAT_0000ccd8 + 0x22) = 2;
  local_1c = *param_1 << 1;
  pcVar9 = *(char **)(param_1 + 0xc);
  if ((pcVar9 != (char *)0x0) && (uVar7 = (uint)(byte)param_1[0x10], uVar7 != 0)) {
    pcVar8 = &local_1c;
    for (; pcVar8 = pcVar8 + 1, uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar8 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      *(char **)(param_1 + 0xc) = pcVar9;
    }
  }
  piVar2 = DAT_0000ccc4;
  local_28 = 0;
  *DAT_0000ccc4 = -1;
  FUN_0000ccdc(&local_1c,param_1[0x10] + '\x01',local_20);
  bVar1 = true;
  *DAT_0000ccc8 = 1;
  puVar4 = DAT_0000ccd0;
  local_24 = DAT_0000cccc;
  uVar7 = DAT_0000cccc;
  while( true ) {
    uVar11 = DAT_0000cccc;
    uVar10 = DAT_0000cccc;
    if ((((*puVar4 & 0x1f) == 0) && (*DAT_0000ccd4 << 0x19 < 0)) && (-1 < (int)(*puVar4 << 0x10))) {
      local_38 = 0;
      goto LAB_0000cbd6;
    }
    if (*piVar2 << 0x1e < 0 || uVar7 < 2) break;
    FUN_00000b80(0x30);
    uVar7 = uVar7 - 1;
  }
  local_38 = 0xc;
  bVar1 = false;
LAB_0000cbd6:
  do {
    piVar3 = DAT_0000ccc8;
    if ((*piVar2 << 0x1e < 0) || (*piVar2 << 0x1d < 0)) break;
    if (uVar10 < 2) {
      local_28 = 0xc;
      uVar10 = local_28;
      if (*(short *)(param_1 + 8) == 0) goto LAB_0000cc5a;
      goto LAB_0000ccae;
    }
    FUN_00000b80(0x30);
    uVar10 = uVar10 - 1;
  } while( true );
  uVar7 = (uint)*(ushort *)(param_1 + 8);
  if (uVar7 == 0) {
    local_28 = local_38;
LAB_0000cc5a:
    *DAT_0000ccc8 = 0x10;
    while (*piVar3 << 0x1b < 0) {
      if (uVar11 < 2) goto LAB_0000cca0;
      FUN_00000b80(0x30);
      uVar11 = uVar11 - 1;
    }
  }
  else {
    uVar11 = uVar7;
    uVar10 = local_38;
    if (!bVar1) goto LAB_0000ccae;
    while (uVar12 = local_28 & 0xffff, local_28 = local_38, uVar12 < uVar7) {
      uVar7 = uVar11 & 0xffff;
      if (0xf < uVar7) {
        uVar7 = 0x10;
      }
      FUN_0000ccdc(*(int *)(param_1 + 4) + uVar12,uVar7,local_20);
      piVar3 = DAT_0000ccc8;
      uVar6 = (uint)local_20[0];
      uVar11 = uVar11 - uVar6;
      if ((uVar11 & 0xffff) == 0) {
        *DAT_0000ccc8 = 0x10;
        goto LAB_0000cc8c;
      }
      local_28 = 0xc;
      uVar10 = local_28;
      if ((*piVar2 << 0x1e < 0) || (local_24 < 2)) goto LAB_0000ccae;
      FUN_00000b80(0x30);
      local_24 = local_24 - 1;
      uVar7 = (uint)*(ushort *)(param_1 + 8);
      local_28 = uVar12 + uVar6;
    }
  }
LAB_0000cca8:
  uVar10 = local_28;
  if (local_28 == 0) {
    local_28 = 0;
    goto LAB_0000ccb4;
  }
  goto LAB_0000ccae;
LAB_0000cc8c:
  if (-1 < *piVar3 << 0x1b) goto LAB_0000cca8;
  if ((int)local_24 < 2) goto LAB_0000cca0;
  FUN_00000b80(0x30);
  local_24 = local_24 - 1;
  goto LAB_0000cc8c;
LAB_0000cca0:
  uVar10 = 0xc;
LAB_0000ccae:
  local_28 = uVar10;
  FUN_0000cd0c();
LAB_0000ccb4:
  *(undefined1 *)(iVar5 + 0x22) = 1;
  return local_28;
}

