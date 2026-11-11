// rea decompile_all
// name: FUN_000005f0
// address: 0x5f0
// body: available
// range: 0x5f0-0x6df inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_000005f0(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                 uint param_6,int param_7)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int unaff_r4;
  uint unaff_r5;
  uint uVar5;
  int iVar6;
  char *unaff_r7;
  undefined1 in_stack_00000018;
  
  param_5 = param_1 << 8;
  uVar5 = unaff_r5;
  if (unaff_r7 == (char *)0x0) {
    unaff_r7 = (char *)0x0;
  }
  else {
    cVar1 = *unaff_r7;
    if ((param_3 & param_5) == 0) {
      if (cVar1 != '\0') {
        iVar6 = 0;
        do {
          iVar2 = iVar6 + 1;
          iVar6 = iVar6 + 1;
        } while (unaff_r7[iVar2] != '\0');
        uVar5 = unaff_r5 + iVar6;
      }
    }
    else {
      while (cVar1 != '\0') {
        (**(code **)(param_7 + 8))(param_7,unaff_r7,1);
        cVar1 = unaff_r7[1];
        unaff_r7 = unaff_r7 + 1;
        uVar5 = uVar5 + 1;
      }
    }
  }
  uVar3 = param_5;
  uVar4 = param_6 >> 0xf & 0xff;
  if (((param_6 & 0x40) == 0) && ((int)uVar5 < (int)uVar4)) {
    if ((param_6 & param_5) == 0) {
      in_stack_00000018 = 0x20;
    }
    else {
      in_stack_00000018 = 0x30;
    }
    iVar6 = uVar4 - uVar5;
    uVar5 = uVar4;
    if (0 < iVar6) {
      do {
        (**(code **)(param_7 + 8))(param_7,&stack0x00000018,1);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  if (((param_6 & uVar3) == 0) && (unaff_r7 != (char *)0x0)) {
    cVar1 = *unaff_r7;
    while (cVar1 != '\0') {
      (**(code **)(param_7 + 8))(param_7,unaff_r7,1);
      cVar1 = unaff_r7[1];
      unaff_r7 = unaff_r7 + 1;
    }
  }
  (**(code **)(param_7 + 8))(param_7,unaff_r4 + 1,unaff_r5);
  if (((param_6 & 0x40) != 0) && ((int)uVar5 < (int)uVar4)) {
    in_stack_00000018 = 0x20;
    iVar6 = uVar4 - uVar5;
    uVar5 = uVar4;
    if (0 < iVar6) {
      do {
        (**(code **)(param_7 + 8))(param_7,&stack0x00000018,1);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  return uVar5;
}

