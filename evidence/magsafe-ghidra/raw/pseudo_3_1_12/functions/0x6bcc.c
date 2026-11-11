// rea decompile_all
// name: FUN_00006bcc
// address: 0x6bcc
// body: available
// range: 0x6bcc-0x6cd1 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00006bcc(int param_1,byte *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = DAT_00006cd8 + param_1 * 0x88;
  *(undefined4 *)(iVar10 + 0x80) = 0;
  bVar1 = *param_2;
  if ((bVar1 < 3) && (*(char *)(iVar10 + 0x7c) != '\x01')) {
    iVar9 = iVar10 + (uint)bVar1 * 3;
    bVar2 = *(byte *)(iVar9 + 5);
    cVar3 = *(char *)(iVar9 + 6);
    pcVar4 = (char *)(iVar9 + 6);
    iVar5 = FUN_00002fd4(param_2,0,0,0x2000,DAT_00006cd4);
    if (iVar5 != 0) {
      *pcVar4 = '\0';
    }
    iVar6 = FUN_00002fd4(param_2,1,0,0x2000,DAT_00006cd4);
    if (iVar6 == 0) {
      uVar7 = (*(uint *)(param_2 + 4) & 0xfff) >> 9;
      *(byte *)(iVar10 + 0x70) = (byte)uVar7;
      if (((*pcVar4 == '\0') || (bVar2 != uVar7)) &&
         ((bVar2 != uVar7 || ((cVar3 != '\x01' && ((cVar3 != '\0' || (iVar5 == 0)))))))) {
        *(byte *)(iVar9 + 5) = (byte)uVar7;
        *pcVar4 = '\x01';
        iVar5 = FUN_00002fd4(param_2,0,0,0x20,DAT_00006cd4);
        if ((iVar5 == 0) || (*(char *)(iVar10 + 0x73) != '\x01')) {
          *(byte *)(iVar10 + 0x71) = bVar1;
          iVar5 = FUN_00002fd4(param_2,0,0,0x2000,DAT_00006cd4);
          if (iVar5 == 0) {
            uVar8 = 0x40;
          }
          else {
            uVar8 = 2;
          }
          *(undefined4 *)(iVar10 + 0x80) = uVar8;
          if (param_3 == 0) {
            *(byte *)(iVar9 + 5) = bVar2;
            *pcVar4 = cVar3;
          }
        }
      }
    }
    else {
      *(undefined4 *)(iVar10 + 0x80) = 2;
    }
  }
  return;
}

