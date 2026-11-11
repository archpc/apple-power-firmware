// rea decompile_all
// name: FUN_0000e388
// address: 0xe388
// body: available
// range: 0xe388-0xe417 inclusive
// range: 0xe4ec-0xe4f9 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0000e388(undefined1 param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint extraout_r3;
  uint extraout_r3_00;
  uint uVar4;
  undefined2 local_30;
  undefined1 local_2e;
  undefined1 local_2d;
  int *local_2c;
  undefined4 local_28;
  undefined2 *local_24;
  
  uVar2 = *(uint *)(param_2 + 8);
  uVar4 = *(uint *)(param_2 + 0xc);
  uVar3 = (uVar4 & 0x7ffffff) >> 0x18;
  if ((uVar3 == 0) && ((uVar2 & 0xf) == 1)) {
    local_24 = &local_30;
    local_30 = (undefined2)uVar4;
    uVar3 = (uVar2 & 0x7ff) >> 6;
    local_2e = (undefined1)uVar3;
    if (0x17 < uVar3) {
      local_2e = 0x18;
    }
    local_2c = param_3 + 1;
    local_28 = DAT_0000e4bc;
    software_interrupt(3);
    local_2d = param_1;
    uVar4 = FUN_0000e354(uVar2,param_3,local_2c,&local_28);
    FUN_0000ecb0();
    uVar3 = extraout_r3;
  }
  if (uVar3 != 1) {
    *param_3 = (uVar2 & 0xfffff80f) + 0x20;
    return 1;
  }
  uVar3 = (uVar4 & 0xffff) >> 10;
  if (0x28 < uVar3) {
    FUN_0000eca0();
    uVar3 = extraout_r3_00;
  }
                    /* WARNING: Could not recover jumptable at 0x0000e416. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(&PTR_DAT_0000e418)[uVar3])();
  return uVar1;
}

