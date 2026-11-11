// rea decompile_all
// name: FUN_000005f0
// address: 0x5f0
// body: available
// range: 0x5f0-0x705 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_000005f0(uint param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                 char *param_6,uint param_7,int param_8,undefined4 param_9,undefined4 param_10,
                 undefined1 param_11)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 *unaff_r4;
  uint uVar5;
  byte unaff_r6;
  
  if (param_2 < param_1) {
    do {
      *unaff_r4 = 0x30;
      unaff_r4 = unaff_r4 + -1;
      unaff_r6 = unaff_r6 + 1;
    } while (unaff_r6 < param_1);
  }
  else if (unaff_r6 == 0) {
    *unaff_r4 = 0x30;
    unaff_r4 = unaff_r4 + -1;
    unaff_r6 = 1;
  }
  param_9 = (uint)unaff_r6;
  uVar5 = param_9;
  if (param_6 == (char *)0x0) {
    param_6 = (char *)0x0;
  }
  else {
    cVar1 = *param_6;
    if ((param_3 & 0x100) == 0) {
      if (cVar1 != '\0') {
        iVar3 = 0;
        do {
          iVar2 = iVar3 + 1;
          iVar3 = iVar3 + 1;
        } while (param_6[iVar2] != '\0');
        uVar5 = param_9 + iVar3;
      }
    }
    else {
      while (cVar1 != '\0') {
        (**(code **)(param_8 + 8))(param_8,param_6,1);
        cVar1 = param_6[1];
        uVar5 = uVar5 + 1;
        param_6 = param_6 + 1;
      }
    }
  }
  uVar4 = param_7 >> 0xf & 0xff;
  if (((int)uVar5 < (int)uVar4) && ((param_7 & 0x40) == 0)) {
    if ((param_7 & 0x100) == 0) {
      param_11 = 0x20;
    }
    else {
      param_11 = 0x30;
    }
    iVar3 = uVar4 - uVar5;
    uVar5 = uVar4;
    if (0 < iVar3) {
      do {
        (**(code **)(param_8 + 8))(param_8,&param_11,1);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  if ((param_6 != (char *)0x0) && ((param_7 & 0x100) == 0)) {
    cVar1 = *param_6;
    while (cVar1 != '\0') {
      (**(code **)(param_8 + 8))(param_8,param_6,1);
      cVar1 = param_6[1];
      param_6 = param_6 + 1;
    }
  }
  (**(code **)(param_8 + 8))(param_8,unaff_r4 + 1,param_9);
  if (((int)uVar5 < (int)uVar4) && ((param_7 & 0x40) != 0)) {
    param_11 = 0x20;
    iVar3 = uVar4 - uVar5;
    uVar5 = uVar4;
    if (0 < iVar3) {
      do {
        (**(code **)(param_8 + 8))(param_8,&param_11,1);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  return uVar5;
}

