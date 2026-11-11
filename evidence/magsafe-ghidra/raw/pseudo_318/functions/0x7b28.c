// rea decompile_all
// name: FUN_00007b28
// address: 0x7b28
// body: available
// range: 0x7b28-0x7bd9 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00007b28(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_18;
  
  iVar1 = *(int *)(DAT_00007bdc + param_1 * 4);
  *(undefined4 *)(iVar1 + 0x11c) = 0x80;
  *(uint *)(iVar1 + 300) = *(uint *)(iVar1 + 300) | 0x80;
  *(uint *)(iVar1 + 0x1a0) = *(uint *)(iVar1 + 0x1a0) | 1;
  *(uint *)(iVar1 + 0x18c) = *(uint *)(iVar1 + 0x18c) | 10;
  iVar1 = DAT_00007be0;
  iVar3 = DAT_00007be0 + param_1 * 0x1cc;
  *(undefined1 *)(iVar3 + 0x19) = 1;
  if (*(char *)(iVar3 + 1) == '\x01') {
    local_18 = 3;
  }
  else {
    local_18 = 4;
  }
  iVar2 = *(int *)(iVar3 + 0x60);
  if (*(char *)(iVar3 + 0x17) == '\0') {
    if (((*(char *)(iVar3 + 0x11) == '\x01') && (*(char *)(iVar1 + param_1 * 0x1cc) != '\x01')) &&
       (iVar1 = FUN_00007854(param_1), iVar1 != 0)) {
      *(undefined1 *)(iVar3 + 0x18) = 1;
      local_18 = 4;
    }
    else {
      (**(code **)(iVar2 + 0x38))(param_1,0);
    }
  }
  *(undefined1 *)(iVar3 + 0x17) = 1;
  FUN_00002f50(param_1);
  *(undefined1 *)(iVar3 + 0x2d) = local_18;
  *(undefined4 *)(iVar3 + 0x4c) = 2;
  (*(code *)**(undefined4 **)(iVar3 + 0x60))(param_1,0x1b,0);
  return;
}

