// rea decompile_all
// name: FUN_0000bac0
// address: 0xbac0
// body: available
// range: 0xbac0-0xbb93 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0000bac0(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  uint uVar12;
  byte local_18 [4];
  
  iVar5 = DAT_0000bb9c;
  iVar4 = DAT_0000bb98;
  iVar3 = DAT_0000bb94;
  puVar6 = *(uint **)(*(int *)(DAT_0000bb94 + 0x48) + 0x1c);
  while (*(char *)(iVar3 + 0x1f) == '\0') {
    pcVar11 = (char *)(iVar4 + 0x2a);
    iVar10 = iVar5;
    for (uVar9 = 0; uVar9 != 2; uVar9 = uVar9 + 1) {
      FUN_000021a0(uVar9 & 0xff);
      cVar1 = *pcVar11;
      *pcVar11 = '\0';
      if (cVar1 != '\0') {
        FUN_0000bbc4(iVar10,cVar1,0);
      }
      iVar10 = iVar10 + 0x14;
      pcVar11 = pcVar11 + 0x30;
    }
    while( true ) {
      if (*(byte *)((int)puVar6 + 0xf9) == 0) break;
      uVar9 = 0;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        uVar9 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00001178(puVar6 + 0x3e,local_18,DAT_0000bba0,puVar6);
      uVar7 = puVar6[local_18[0] + 0x2a];
      uVar12 = puVar6[local_18[0] + 0x1a];
      *(byte *)(puVar6[0x3f] + (uint)*(byte *)((int)puVar6 + 0xf9)) = local_18[0];
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        enableIRQinterrupts((uVar9 & 1) == 1);
      }
      puVar8 = puVar6 + 9;
      for (uVar9 = 0; uVar9 < *puVar6; uVar9 = uVar9 + 1) {
        (*(code *)puVar8[-8])(puVar6,uVar12,*puVar8,uVar7);
        puVar8 = puVar8 + 1;
      }
    }
    iVar10 = FUN_0000a8c0();
    if (iVar10 == 1) {
      software_interrupt(1);
    }
    else {
      FUN_000013ac(500);
    }
  }
  return 0;
}

