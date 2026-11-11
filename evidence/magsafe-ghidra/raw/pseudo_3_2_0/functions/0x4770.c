// rea decompile_all
// name: FUN_00004770
// address: 0x4770
// body: available
// range: 0x4770-0x4825 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00004770(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = DAT_00004828 + param_1 * 0xf0;
  cVar1 = *(char *)(iVar3 + 0xe3);
  if ((param_2 == 2) && (cVar1 == '\v')) {
    (**(code **)(*(int *)(DAT_0000482c + param_1 * 0x1cc + 0x60) + 0x4c))(param_1,DAT_00004830);
    return;
  }
  if (2 < param_2 - 4U) {
    if (param_2 == 10) {
      cVar1 = *(char *)(iVar3 + 0x80);
      *(char *)(iVar3 + 0xc2) = cVar1;
      if (cVar1 == '\x01') goto LAB_000047e6;
      FUN_00006ec8(param_1,0,cVar1);
    }
    else if (param_2 == 3) {
      if (*(char *)(iVar3 + 0xc2) == '\x03') {
        if (cVar1 != '\v') {
          return;
        }
        if (*(char *)(DAT_0000482c + param_1 * 0x1cc + 0x28) == '\x01') {
          uVar2 = 0x19;
        }
        else {
          uVar2 = 0x18;
        }
      }
      else {
        if (cVar1 == '\v') {
          uVar2 = 0xf;
        }
        else {
          uVar2 = 0xe;
        }
        (*(code *)**(undefined4 **)(DAT_0000482c + param_1 * 0x1cc + 0x60))
                  (param_1,uVar2,iVar3 + 0xc2);
        uVar2 = 0x23;
      }
      FUN_00003258(param_1,uVar2);
      return;
    }
    return;
  }
  if (cVar1 != '\x13') {
    FUN_00005b5c(param_1);
    return;
  }
LAB_000047e6:
  FUN_00003140(param_1);
  return;
}

