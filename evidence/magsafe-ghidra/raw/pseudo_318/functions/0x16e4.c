// rea decompile_all
// name: FUN_000016e4
// address: 0x16e4
// body: available
// range: 0x16e4-0x173d inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000016e4(uint *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint local_1c;
  undefined1 local_18;
  undefined3 uStack_17;
  
  _local_18 = CONCAT31((int3)((uint)param_4 >> 8),0x80);
  local_1c = param_3 & 0xffffff00;
  uVar2 = *param_1;
  FUN_000016ac(param_1,&local_18,1,param_4,param_2);
  while ((*param_1 != 0 && ((*param_1 & 0x1ff) != 0x1c0))) {
    FUN_000016ac(param_1,&local_1c,1);
  }
  param_1[0xf] = 0;
  param_1[0x10] =
       uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18;
  FUN_00001574(param_1,param_1 + 1);
  for (iVar1 = 0x48; iVar1 != 0x68; iVar1 = iVar1 + 4) {
    uVar2 = *(uint *)((int)param_1 + iVar1);
    *(uint *)((int)param_1 + iVar1) =
         uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18;
  }
  return;
}

