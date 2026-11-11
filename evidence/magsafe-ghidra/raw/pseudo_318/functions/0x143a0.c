// rea decompile_all
// name: FUN_000143a0
// address: 0x143a0
// body: available
// range: 0x143a0-0x14465 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000143a0(uint *param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  
  uVar4 = 0;
  FUN_00013d76(param_1,0,0x68);
  FUN_00013d44(param_1 + 0x12,DAT_00014468,0x20);
  uVar1 = DAT_0001446c;
  if (((param_2 < 0x100001) && (param_3 < 0x100001)) && (param_3 + param_2 < 0x100001)) {
    for (; uVar4 < param_3; uVar4 = uVar3 + uVar4) {
      uVar3 = param_3 - uVar4;
      if (0x7f < uVar3) {
        uVar3 = 0x80;
      }
      (*(code *)&SUB_ce10e000)(uVar1,param_2,uVar3);
      FUN_00014364(param_1,uVar1,uVar3);
      param_2 = uVar3 + param_2;
    }
  }
  local_18[0] = 0x80;
  local_1c[0] = 0;
  uVar4 = *param_1;
  FUN_00014364(param_1,local_18,1);
  while ((*param_1 != 0 && ((*param_1 & 0x1ff) != 0x1c0))) {
    FUN_00014364(param_1,local_1c,1);
  }
  param_1[0xf] = 0;
  param_1[0x10] =
       uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18;
  FUN_0001422c(param_1,param_1 + 1);
  for (iVar2 = 0x48; iVar2 != 0x68; iVar2 = iVar2 + 4) {
    uVar4 = *(uint *)((int)param_1 + iVar2);
    *(uint *)((int)param_1 + iVar2) =
         uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18;
  }
  return;
}

