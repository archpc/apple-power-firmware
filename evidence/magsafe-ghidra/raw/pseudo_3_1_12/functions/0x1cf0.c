// rea decompile_all
// name: FUN_00001cf0
// address: 0x1cf0
// body: available
// range: 0x1cf0-0x1def inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00001cf0(int param_1)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  undefined4 uVar9;
  int iVar10;
  char *pcVar11;
  
  pcVar11 = (char *)(DAT_00001f2c + param_1 * 0x1cc);
  *(undefined4 *)(pcVar11 + 0x60) = DAT_00001f30;
  *(char **)(pcVar11 + 0x6c) = pcVar11 + 0x70;
  iVar6 = DAT_00001f34;
  iVar7 = param_1 * 0xf0;
  iVar10 = DAT_00001f34 + iVar7;
  FUN_00000170(pcVar11,iVar10 + 0x40);
  if (*(short *)(iVar10 + 0x2e) == 0) {
    FUN_000001a2(pcVar11 + 0x128,0,0x19);
  }
  else {
    FUN_00000170(pcVar11 + 0x128,iVar6 + (uint)*(ushort *)(iVar10 + 0x2c),0x19);
  }
  if (*(short *)(iVar10 + 0x32) == 0) {
    FUN_000001a2(pcVar11 + 0x15c,0,0x18);
  }
  else {
    FUN_00000170(pcVar11 + 0x15c,iVar6 + (uint)*(ushort *)(iVar10 + 0x30),0x18);
  }
  pcVar11[0x175] = '\0';
  FUN_00000170(pcVar11 + 0x17c,DAT_00001f38 + param_1 * 0x40);
  if (*pcVar11 != '\x02') {
    pcVar11[1] = *pcVar11;
  }
  puVar4 = DAT_00001f04;
  puVar3 = DAT_00001f00;
  puVar2 = DAT_00001efc;
  puVar8 = *(uint **)(DAT_00001f3c + param_1 * 4);
  if (param_1 == 0) {
    *DAT_00001f04 = 0x4000;
    *puVar3 = 0x4000;
    uVar9 = 0x40;
    *puVar4 = 0x40;
    puVar2[8] = DAT_00001f40;
    *puVar2 = DAT_00001f44;
  }
  else {
    *DAT_00001f04 = 0x8000;
    *puVar3 = 0x8000;
    uVar9 = 0x80;
    *puVar4 = 0x80;
    puVar2[9] = DAT_00001f48;
    puVar2[1] = DAT_00001f4c;
  }
  *puVar3 = uVar9;
  uVar5 = DAT_00001f08;
  *puVar8 = *puVar8 | DAT_00001f08 + 1;
  puVar8[99] = puVar8[99] & uVar5;
  puVar8[0x65] = puVar8[0x65] & 0xfffffff7;
  puVar8[0x65] = puVar8[0x65] | 1;
  FUN_00000b60(0x12c0);
  puVar8[0x3fc6] = puVar8[0x3fc6] & 0xfffffffb | 3;
  puVar8[0x3fc3] = puVar8[0x3fc3] & 0xfffffffa | 2;
  puVar8[0x3fc0] = puVar8[0x3fc0] & 0xfffffff3;
  iVar6 = DAT_00001f50;
  iVar10 = DAT_00001f50 + param_1 * 0x5c;
  uVar1 = (undefined2)DAT_00001f0c;
  *(undefined2 *)(iVar10 + 0x44) = uVar1;
  *(undefined2 *)(iVar10 + 0x46) = uVar1;
  FUN_0000843c(param_1,0);
  FUN_0000843c(param_1,1);
  puVar8[99] = DAT_00001f10 & puVar8[99];
  puVar8[99] = puVar8[99] | 0xe0000;
  puVar8[0x45] = puVar8[0x45] & 0xfff3ffff;
  puVar8[0x45] = puVar8[0x45] & 0xfb7fffff;
  puVar8[0x67] = puVar8[0x67] & 0xffffffeb;
  iVar10 = DAT_00001f54;
  *(undefined1 *)(DAT_00001f54 + param_1 * 0x88 + 0x85) = 1;
  *(int *)(DAT_00001f58 + iVar7) = DAT_00001f58 + iVar7 + 4;
  *(undefined4 *)(iVar10 + param_1 * 0x88) = DAT_00001f5c;
  *(undefined4 *)(iVar6 + param_1 * 0x5c) = DAT_00001f60;
  puVar8[0x2a] = 0x3f;
  puVar8[0x2b] = 0xfffffffd;
  puVar8[0x2c] = 0xffffffff;
  puVar8[0x31] = 0xfffffffd;
  puVar8[0x32] = 0xffffffff;
  puVar8[0x2e] = 0xfffffffd;
  puVar8[0x2f] = 0xffffffff;
  puVar8[1] = DAT_00001f14;
  puVar8[0x2d] = 0xffffffff;
  puVar8[0x33] = 0xffffffff;
  puVar8[0x30] = 0xffffffff;
  puVar8[0x36] = DAT_00001f18;
  puVar8[0x39] = 0xf;
  puVar8[0x40] = 300;
  puVar8[0x41] = DAT_00001f1c;
  puVar8[0x4a] = DAT_00001f20 & puVar8[0x4a];
  puVar8[0x51] = puVar8[0x51] & 0xffff;
  puVar8[0x51] = DAT_00001f24 | puVar8[0x51];
  puVar8[0x3c] = DAT_00001f28;
  pcVar11[0x32] = '\x01';
  *DAT_00001f64 = 1;
  return;
}

