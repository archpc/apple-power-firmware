// rea decompile_all
// name: FUN_0000197c
// address: 0x197c
// body: available
// range: 0x197c-0x19d1 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0000197c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 local_98;
  byte abStack_94 [28];
  uint uStack_78;
  byte abStack_74 [28];
  uint uStack_58;
  byte abStack_54 [32];
  byte abStack_34 [32];
  
  pcVar1 = DAT_00001ab4;
  (*DAT_00001ab4)(abStack_34,param_3,0x20);
  (*pcVar1)(abStack_54,param_4,0x20);
  (*pcVar1)(abStack_74,param_2,0x20);
  local_98 = 0;
  FUN_000001a2(abStack_94,0,0x20);
  iVar2 = FUN_00001822(param_3);
  if (iVar2 == 0) {
    local_98 = 1;
    while (iVar2 = FUN_0000176c(abStack_34,abStack_54), iVar2 != 0) {
      if ((abStack_34[0] & 1) == 0) {
        FUN_00001ab8(abStack_34);
LAB_000019de:
        if ((abStack_74[0] & 1) == 0) {
          FUN_00001ab8(abStack_74);
        }
        else {
          iVar2 = FUN_00001ada(abStack_74,param_4);
          FUN_00001ab8(abStack_74);
          if (iVar2 != 0) {
            uStack_58 = uStack_58 | 0x80000000;
          }
        }
      }
      else {
        if ((abStack_54[0] & 1) == 0) {
          FUN_00001ab8(abStack_54);
        }
        else {
          iVar2 = FUN_0000176c(abStack_34,abStack_54);
          if (0 < iVar2) {
            FUN_000017a0(abStack_34,abStack_54);
            FUN_00001ab8(abStack_34);
            iVar2 = FUN_000017a0(abStack_74,abStack_94);
            if (iVar2 != 0) {
              FUN_00001ada(abStack_74,param_4);
            }
            goto LAB_000019de;
          }
          FUN_000017a0(abStack_54,abStack_34);
          FUN_00001ab8(abStack_54);
          iVar2 = FUN_000017a0(abStack_94,abStack_74);
          if (iVar2 != 0) {
            FUN_00001ada(abStack_94,param_4);
          }
        }
        if ((abStack_94[0] & 1) == 0) {
          FUN_00001ab8(abStack_94);
        }
        else {
          iVar2 = FUN_00001ada(abStack_94,param_4);
          FUN_00001ab8(abStack_94);
          if (iVar2 != 0) {
            uStack_78 = uStack_78 | 0x80000000;
          }
        }
      }
    }
    FUN_00000170(param_1,abStack_74,0x20);
  }
  return local_98;
}

