// rea decompile_all
// name: FUN_000032a4
// address: 0x32a4
// body: available
// range: 0x32a4-0x3389 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000032a4(int param_1,int param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  
  iVar3 = DAT_00003394;
  iVar8 = DAT_0000338c + param_1 * 0x1cc;
  cVar2 = *(char *)(iVar8 + 0x44);
  cVar1 = *(char *)(iVar8 + 0x15);
  if (param_2 - 3U < 3) {
    (*(code *)**(undefined4 **)(iVar8 + 0x60))
              (param_1,0x12,0,(code *)**(undefined4 **)(iVar8 + 0x60),param_2);
    if ((cVar2 != '\0') &&
       ((*(char *)(iVar8 + 0x21) == '\0' || ((param_2 != 3 && (cVar1 == '\0')))))) {
      FUN_00003180(param_1);
      return;
    }
    FUN_0000301a(param_1,3);
    *(undefined1 *)(iVar8 + 0x2f) = 0;
    *(undefined4 *)(iVar8 + 100) = 0;
    if (cVar1 == '\x01') {
      uVar5 = 2;
    }
    else {
      uVar5 = 5;
    }
  }
  else {
    if (param_2 != 2) {
      return;
    }
    iVar6 = DAT_00003390 + param_1 * 0xf0;
    bVar4 = *(byte *)(iVar6 + 0xa4);
    pbVar7 = (byte *)(iVar6 + 0xa4);
    if (*(char *)(DAT_00003394 + param_1) == '\0') {
      bVar4 = bVar4 + 1;
      *pbVar7 = bVar4;
    }
    if (3 < bVar4) {
      *pbVar7 = 3;
      if ((*(char *)(iVar8 + 0x21) == '\0') || (cVar1 != '\x01')) {
        FUN_00006648();
      }
      else {
        FUN_00003180();
      }
      FUN_0000301a(param_1,1);
      return;
    }
    if (*(char *)(iVar3 + param_1) == '\0') {
      FUN_00006818();
      if (cVar1 == '\0') {
        *(undefined1 *)(iVar8 + 0x19) = 1;
      }
    }
    else {
      *(undefined1 *)(iVar3 + param_1) = 0;
    }
    iVar8 = FUN_00007288(param_1);
    if (iVar8 == 0) {
      return;
    }
    uVar5 = 1;
    *(undefined1 *)(iVar3 + param_1) = 1;
  }
  FUN_00003258(param_1,uVar5);
  return;
}

