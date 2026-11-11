// rea decompile_all
// name: FUN_00007304
// address: 0x7304
// body: available
// range: 0x7304-0x73ed inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00007304(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_000073f4 + param_1 * 0x1cc;
  if (param_2 - 4U < 2) {
    FUN_00007bc4(param_1,0,DAT_000073f4,param_4,param_4);
    iVar3 = DAT_000073f8 + param_1 * 0xb;
    if (*(char *)(iVar3 + 4) == '\x01') {
      *(undefined1 *)(iVar3 + 4) = 0;
      if (*(char *)(iVar4 + 0x44) == '\0') {
        iVar3 = *(int *)(DAT_00007400 + param_1 * 4);
        *(undefined4 *)(iVar3 + 0x11c) = 0x80;
        *(uint *)(iVar3 + 300) = *(uint *)(iVar3 + 300) & 0xffffff7f;
      }
      FUN_00007c50(param_1,1);
      (*(code *)**(undefined4 **)(iVar4 + 0x60))(param_1,0x1a,0);
      *(undefined1 *)(iVar4 + 0x31) = 0;
      return;
    }
    *(undefined1 *)(iVar4 + 0x2d) = 1;
    uVar1 = 0xf;
    uVar2 = 0x32;
LAB_000073e6:
    FUN_00007958(param_1,uVar1,uVar2);
    return;
  }
  if (param_2 == 6) {
    FUN_00007c50(param_1,1);
    FUN_00007c80(param_1);
  }
  else if (param_2 == 1) {
    iVar3 = *(int *)(iVar4 + 0x60);
    FUN_0000ca08(param_1,0xf);
    if (*(char *)(DAT_000073f8 + param_1 * 0xb + 4) == '\0') {
      *(undefined1 *)(iVar4 + 0x1d) = 0;
      (*(code *)**(undefined4 **)(iVar4 + 0x60))(param_1,1);
    }
    *(undefined1 *)(iVar4 + 0x19) = 1;
    if (*(char *)(iVar4 + 0x15) == '\0') {
      FUN_00007bc4(param_1,0);
      *(undefined1 *)(iVar4 + 0x2d) = 1;
    }
    else {
      FUN_00007bc4(param_1,1);
    }
    (**(code **)(iVar3 + 0x10))(param_1,DAT_000073fc);
    uVar1 = 0x10;
    uVar2 = DAT_000073f0;
    goto LAB_000073e6;
  }
  return;
}

