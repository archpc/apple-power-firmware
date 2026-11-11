// rea decompile_all
// name: FUN_00001c74
// address: 0x1c74
// body: available
// range: 0x1c74-0x1d77 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00001c74(int param_1)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  undefined4 *puVar8;
  int iVar9;
  char *pcVar10;
  undefined4 uVar11;
  
  pcVar10 = (char *)(DAT_00001ebc + param_1 * 0x1cc);
  *(undefined4 *)(pcVar10 + 0x60) = DAT_00001ec0;
  *(char **)(pcVar10 + 0x6c) = pcVar10 + 0x70;
  iVar5 = DAT_00001ec4;
  iVar6 = param_1 * 0xf0;
  iVar9 = DAT_00001ec4 + iVar6;
  FUN_00000170(pcVar10,iVar9 + 0x40);
  if (*(short *)(iVar9 + 0x2e) == 0) {
    FUN_000001a0(pcVar10 + 0x128,0,0x19);
  }
  else {
    FUN_00000170(pcVar10 + 0x128,iVar5 + (uint)*(ushort *)(iVar9 + 0x2c),0x19);
  }
  if (*(short *)(iVar9 + 0x32) == 0) {
    FUN_000001a0(pcVar10 + 0x15c,0,0x18);
  }
  else {
    FUN_00000170(pcVar10 + 0x15c,iVar5 + (uint)*(ushort *)(iVar9 + 0x30),0x18);
  }
  pcVar10[0x177] = '\0';
  pcVar10[0x175] = '\0';
  uVar11 = 0x40;
  FUN_00000170(pcVar10 + 0x17c,DAT_00001ec8 + param_1 * 0x40,0x40);
  if (*pcVar10 != '\x02') {
    pcVar10[1] = *pcVar10;
  }
  puVar3 = DAT_00001e94;
  puVar2 = DAT_00001e8c;
  puVar7 = *(uint **)(DAT_00001ecc + param_1 * 4);
  if (param_1 == 0) {
    *DAT_00001e94 = 0x4000;
    puVar8 = DAT_00001e90;
    *DAT_00001e90 = 0x4000;
    puVar2[8] = DAT_00001ed0;
    *puVar2 = DAT_00001ed4;
  }
  else {
    *DAT_00001e94 = 0x8000;
    puVar8 = DAT_00001e90;
    *DAT_00001e90 = 0x8000;
    puVar2[9] = DAT_00001ed8;
    puVar2[1] = DAT_00001edc;
    uVar11 = 0x80;
  }
  *puVar3 = uVar11;
  *puVar8 = uVar11;
  uVar4 = DAT_00001e98;
  *puVar7 = *puVar7 | DAT_00001e98 + 1;
  puVar7[99] = puVar7[99] & uVar4;
  puVar7[0x65] = puVar7[0x65] & 0xfffffff7;
  puVar7[0x65] = puVar7[0x65] | 1;
  FUN_00000b80(&DAT_000012c0);
  puVar7[0x3fc6] = puVar7[0x3fc6] & 0xfffffffb | 3;
  puVar7[0x3fc3] = puVar7[0x3fc3] & 0xfffffffa | 2;
  puVar7[0x3fc0] = puVar7[0x3fc0] & 0xfffffff3;
  iVar5 = DAT_00001ee0;
  iVar9 = DAT_00001ee0 + param_1 * 0x5c;
  uVar1 = (undefined2)DAT_00001e9c;
  *(undefined2 *)(iVar9 + 0x44) = uVar1;
  *(undefined2 *)(iVar9 + 0x46) = uVar1;
  FUN_00008590(param_1,0);
  FUN_00008590(param_1,1);
  puVar7[99] = DAT_00001ea0 & puVar7[99];
  puVar7[99] = puVar7[99] | 0xe0000;
  puVar7[0x45] = puVar7[0x45] & 0xfff3ffff;
  puVar7[0x45] = puVar7[0x45] & 0xfb7fffff;
  puVar7[0x67] = puVar7[0x67] & 0xffffffeb;
  iVar9 = DAT_00001ee4;
  *(undefined1 *)(DAT_00001ee4 + param_1 * 0x88 + 0x85) = 1;
  *(int *)(DAT_00001ee8 + iVar6) = DAT_00001ee8 + iVar6 + 4;
  *(undefined4 *)(iVar9 + param_1 * 0x88) = DAT_00001eec;
  *(undefined4 *)(iVar5 + param_1 * 0x5c) = DAT_00001ef0;
  puVar7[0x2a] = 0x3f;
  puVar7[0x2b] = 0xfffffffd;
  puVar7[0x2c] = 0xffffffff;
  puVar7[0x31] = 0xfffffffd;
  puVar7[0x32] = 0xffffffff;
  puVar7[0x2e] = 0xfffffffd;
  puVar7[0x2f] = 0xffffffff;
  puVar7[1] = DAT_00001ea4;
  puVar7[0x2d] = 0xffffffff;
  puVar7[0x33] = 0xffffffff;
  puVar7[0x30] = 0xffffffff;
  puVar7[0x36] = DAT_00001ea8;
  puVar7[0x39] = 0xf;
  puVar7[0x40] = 300;
  puVar7[0x41] = DAT_00001eac;
  puVar7[0x4a] = DAT_00001eb0 & puVar7[0x4a];
  puVar7[0x51] = puVar7[0x51] & 0xffff;
  puVar7[0x51] = DAT_00001eb4 | puVar7[0x51];
  puVar7[0x3c] = DAT_00001eb8;
  pcVar10[0x32] = '\x01';
  *DAT_00001ef4 = 1;
  return;
}

