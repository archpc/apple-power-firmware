// rea decompile_all
// name: FUN_0000b09c
// address: 0xb09c
// body: available
// range: 0xb09c-0xb185 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000b09c(int param_1,int param_2,code *param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint local_24;
  undefined1 local_20;
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  
  FUN_00002938();
  iVar2 = DAT_0000b198;
  bVar1 = true;
  if (*(char *)(*(int *)(DAT_0000b198 + 0x58) + 0x21) != '\0') {
    FUN_00002db0(1);
  }
  *(undefined1 *)(iVar2 + 0x69) = 1;
  iVar4 = DAT_0000b1a0;
  iVar3 = DAT_0000b19c;
  if (*(char *)(DAT_0000b19c + 0x3e) != '\x01') {
    *(undefined1 *)(DAT_0000b1a0 + 4) = 1;
  }
  if (*(char *)(iVar2 + 0x54) == '\0') {
    local_24 = (uint)*(byte *)(*(int *)(iVar2 + 0x58) + 0x20);
    if (local_24 == 0) {
      FUN_0000a4c0((uint *)(param_2 + 8),&local_24,auStack_18,auStack_1c);
      uVar5 = DAT_0000b188 & *(uint *)(param_2 + 8);
      local_24 = DAT_0000b190;
      if (uVar5 < 10) {
        local_24 = uVar5 * 0x400 + DAT_0000b18c;
      }
    }
    else {
      bVar1 = false;
    }
  }
  else {
    *(undefined1 *)(iVar2 + 0x54) = 0;
    *(undefined1 *)(iVar3 + param_1 * 0x1cc + 0x1bc) = 0;
    local_24 = *(uint *)(iVar2 + 0x50);
  }
  if (bVar1) {
    local_20 = 3;
    (*param_3)(param_1);
  }
  else {
    if ((*(uint *)(param_2 + 4) & DAT_0000b194 + 0xe) == DAT_0000b194) {
      FUN_0000a500(0);
      FUN_00006828();
    }
    else {
      if (*(char *)(iVar4 + 0x13) == '\x01') {
        FUN_00006828();
        *(undefined1 *)(iVar4 + 0x13) = 0;
      }
      FUN_0000a500(1);
    }
    *(undefined1 *)(iVar2 + 0x55) = 1;
    *(code **)(iVar4 + 0x5c) = param_3;
  }
  return;
}

