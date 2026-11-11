// rea decompile_all
// name: FUN_00001f84
// address: 0x1f84
// body: available
// range: 0x1f84-0x2101 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00001f84(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  byte *pbVar7;
  uint uVar8;
  char *pcVar9;
  undefined1 *puVar10;
  int local_20;
  char *local_18;
  
  iVar3 = DAT_0000210c;
  iVar2 = DAT_00002108;
  pbVar7 = (byte *)(DAT_00002108 + 0x2d);
  local_20 = DAT_0000210c + 8;
  local_18 = (char *)(DAT_00002110 + 0x73);
  for (uVar8 = 0; uVar8 != 2; uVar8 = uVar8 + 1) {
    if (pbVar7[4] != 0) {
      bVar1 = *pbVar7;
      if (*(int *)(pbVar7 + 0x1f) == 0) {
        uVar4 = uVar8 & 0xff;
        iVar5 = FUN_0000ca50(uVar4,0x15);
        if ((((iVar5 == 0) && (1 < bVar1 - 1)) &&
            ((3 < bVar1 - 6 ||
             ((iVar5 = FUN_0000ca88(uVar4,0x10,0x12), iVar5 == 0 &&
              (*(char *)(local_20 + (uint)pbVar7[-0x13]) != '\0')))))) &&
           ((bVar1 = pbVar7[0x18], bVar1 == 0 ||
            ((((((*(int *)(pbVar7 + 0x1b) == 0 && (iVar5 = FUN_0000ca50(uVar4,9), iVar5 == 0)) &&
                (*(int *)(local_18 + 0xd) == 0)) &&
               ((local_18[0x11] == '\0' && (*local_18 != '\x01')))) &&
              (iVar5 = FUN_00008d2c(uVar4), iVar5 == 0)) &&
             ((pbVar7[-0xb] == 1 ||
              ((uVar4 = (uint)(byte)(bVar1 - 0xb), uVar4 < 0x19 &&
               ((DAT_00002104 >> uVar4 & 1) == 0)))))))))) goto LAB_00002058;
      }
      if (uVar8 < 2) {
        return 0;
      }
      break;
    }
LAB_00002058:
    pbVar7 = pbVar7 + 0x1cc;
    local_18 = local_18 + 0x88;
    local_20 = local_20 + 0xb;
  }
  iVar5 = 3;
  pcVar9 = (char *)(iVar2 + 0x31);
  while (iVar5 = iVar5 + -1, iVar5 != 0) {
    if (((1 < (byte)pcVar9[-4] - 3) || (*pcVar9 == '\0')) ||
       (pcVar6 = pcVar9 + -0x29, pcVar9 = pcVar9 + 0x1cc, *pcVar6 != '\x01')) goto LAB_000020a6;
  }
  if (*(char *)(iVar3 + 6) == '\0') {
    for (uVar8 = 0; uVar8 != 2; uVar8 = uVar8 + 1) {
      FUN_0000ca08(uVar8 & 0xff,0x10);
    }
    puVar10 = (undefined1 *)(iVar3 + 6);
    for (uVar8 = 0; uVar8 != 2; uVar8 = uVar8 + 1) {
      *puVar10 = 1;
      FUN_00007958(uVar8 & 0xff,0x10,0x1e);
      FUN_00002dd0(uVar8 & 0xff,0x20);
      puVar10 = puVar10 + 0xb;
    }
  }
LAB_000020a6:
  pcVar9 = (char *)(iVar2 + 0x31);
  for (uVar8 = 0; uVar8 != 2; uVar8 = uVar8 + 1) {
    if (*pcVar9 != '\0') {
      FUN_0000869c(uVar8 & 0xff);
    }
    pcVar9 = pcVar9 + 0x1cc;
  }
  return 1;
}

