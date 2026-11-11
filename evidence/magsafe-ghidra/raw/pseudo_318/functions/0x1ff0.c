// rea decompile_all
// name: FUN_00001ff0
// address: 0x1ff0
// body: available
// range: 0x1ff0-0x2167 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00001ff0(void)

{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  undefined1 *puVar10;
  int local_18;
  
  iVar4 = DAT_00002170;
  iVar3 = DAT_0000216c;
  pbVar9 = (byte *)(DAT_0000216c + 0x2d);
  local_18 = DAT_00002170 + 8;
  pcVar6 = (char *)(DAT_00002174 + 0x73);
  for (uVar7 = 0; uVar7 != 2; uVar7 = uVar7 + 1) {
    if (pbVar9[4] != 0) {
      if (*(int *)(pbVar9 + 0x1f) != 0) {
        return 0;
      }
      bVar2 = *pbVar9;
      uVar8 = uVar7 & 0xff;
      iVar5 = FUN_0000c880(uVar8,0x15);
      if (bVar2 - 1 < 2) {
        return 0;
      }
      if (iVar5 != 0) {
        return 0;
      }
      if (bVar2 - 6 < 4) {
        iVar5 = FUN_0000c8ac(uVar8,0x10,0x12);
        if (iVar5 != 0) {
          return 0;
        }
        if (*(char *)(local_18 + (uint)pbVar9[-0x13]) == '\0') {
          return 0;
        }
      }
      bVar2 = pbVar9[0x18];
      if (bVar2 != 0) {
        if (*(int *)(pbVar9 + 0x1b) != 0) {
          return 0;
        }
        iVar5 = FUN_0000c880(uVar8,9);
        if (iVar5 != 0) {
          return 0;
        }
        if (*(int *)(pcVar6 + 0xd) != 0) {
          return 0;
        }
        if (pcVar6[0x11] != '\0') {
          return 0;
        }
        if (*pcVar6 == '\x01') {
          return 0;
        }
        iVar5 = FUN_00008be8(uVar8);
        if (iVar5 != 0) {
          return 0;
        }
        if (pbVar9[-0xb] != 1) {
          uVar8 = bVar2 - 0xb;
          if (0x18 < uVar8) {
            return 0;
          }
          if ((1 << (uVar8 & 0xff) & DAT_00002168) == 0) {
            return 0;
          }
        }
      }
    }
    pbVar9 = pbVar9 + 0x1cc;
    pcVar6 = pcVar6 + 0x88;
    local_18 = local_18 + 0xb;
  }
  iVar5 = 3;
  pcVar6 = (char *)(iVar3 + 0x31);
  while (iVar5 = iVar5 + -1, iVar5 != 0) {
    if (((1 < (byte)pcVar6[-4] - 3) || (*pcVar6 == '\0')) ||
       (pcVar1 = pcVar6 + -0x29, pcVar6 = pcVar6 + 0x1cc, *pcVar1 != '\x01')) goto LAB_00002108;
  }
  if (*(char *)(iVar4 + 6) == '\0') {
    for (uVar7 = 0; uVar7 != 2; uVar7 = uVar7 + 1) {
      FUN_0000c838(uVar7 & 0xff,0x10);
    }
    puVar10 = (undefined1 *)(iVar4 + 6);
    for (uVar7 = 0; uVar7 != 2; uVar7 = uVar7 + 1) {
      *puVar10 = 1;
      FUN_00007800(uVar7 & 0xff,0x10,0x1e);
      FUN_00002cfc(uVar7 & 0xff,0x20);
      puVar10 = puVar10 + 0xb;
    }
  }
LAB_00002108:
  pcVar6 = (char *)(iVar3 + 0x31);
  for (uVar7 = 0; uVar7 != 2; uVar7 = uVar7 + 1) {
    if (*pcVar6 != '\0') {
      FUN_00008548(uVar7 & 0xff);
    }
    pcVar6 = pcVar6 + 0x1cc;
  }
  return 1;
}

