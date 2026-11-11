// rea decompile_all
// name: FUN_00001904
// address: 0x1904
// body: available
// range: 0x1904-0x197d inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_00001904(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  byte abStack_94 [28];
  uint uStack_78;
  byte local_74 [28];
  uint uStack_58;
  byte local_54 [32];
  byte local_34 [32];
  
  pcVar1 = DAT_00001a38;
  (*DAT_00001a38)(local_34,param_3,0x20);
  (*pcVar1)(local_54,param_4,0x20);
  (*pcVar1)(local_74,param_2,0x20);
  FUN_000001a0(abStack_94,0,0x20);
  uVar2 = FUN_000017b0(param_3);
  if (uVar2 == 0) {
    while (iVar3 = FUN_000016fc(local_34,local_54), iVar3 != 0) {
      if ((local_34[0] & 1) == 0) {
        FUN_00001a3c(local_34);
LAB_00001966:
        if ((local_74[0] & 1) == 0) {
          FUN_00001a3c(local_74);
        }
        else {
          iVar3 = FUN_00001a5e(local_74,param_4);
          FUN_00001a3c(local_74);
          if (iVar3 != 0) {
            uStack_58 = uStack_58 | 0x80000000;
          }
        }
      }
      else {
        if ((local_54[0] & 1) == 0) {
          FUN_00001a3c(local_54);
        }
        else {
          if (0 < iVar3) {
            FUN_00001730(local_34,local_54);
            FUN_00001a3c(local_34);
            iVar3 = FUN_00001730(local_74,abStack_94);
            if (iVar3 != 0) {
              FUN_00001a5e(local_74,param_4);
            }
            goto LAB_00001966;
          }
          FUN_00001730(local_54,local_34);
          FUN_00001a3c(local_54);
          iVar3 = FUN_00001730(abStack_94,local_74);
          if (iVar3 != 0) {
            FUN_00001a5e(abStack_94,param_4);
          }
        }
        if ((abStack_94[0] & 1) == 0) {
          FUN_00001a3c(abStack_94);
        }
        else {
          iVar3 = FUN_00001a5e(abStack_94,param_4);
          FUN_00001a3c(abStack_94);
          if (iVar3 != 0) {
            uStack_78 = uStack_78 | 0x80000000;
          }
        }
      }
    }
    FUN_00000170(param_1,local_74,0x20);
  }
  return uVar2 ^ 1;
}

