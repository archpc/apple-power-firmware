// rea decompile_all
// name: FUN_00007e4c
// address: 0x7e4c
// body: available
// range: 0x7e4c-0x7f19 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_00007e4c(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_18 = 0;
  iVar1 = *(int *)(DAT_00007f1c + param_1 * 4);
  if (param_2 == 0) {
    local_30 = 0x3000000;
    puVar3 = (uint *)(iVar1 + 0x17c);
    puVar5 = (uint *)(iVar1 + 0x180);
    local_34 = 0x18;
    local_1c = 0x100;
  }
  else {
    local_30 = 0x18000000;
    puVar3 = (uint *)(iVar1 + 0x184);
    puVar5 = (uint *)(iVar1 + 0x188);
    local_34 = 0x1b;
    local_1c = 0x200;
  }
  uVar2 = FUN_00000b50();
  uVar6 = *puVar5;
  *puVar5 = (param_3 & 3) * 0x20000 + 0x200;
  *puVar3 = *puVar3 | 1;
  for (; ((*puVar3 & 1) != 0 && (local_18 < 200)); local_18 = local_18 + 1) {
  }
  FUN_00000b60(0x60);
  uVar4 = *puVar3;
  *puVar5 = uVar6;
  FUN_00000b60(0x1e0);
  *(uint *)(iVar1 + 0x11c) = local_1c;
  if ((-1 < (int)uVar6) && ((*(uint *)(iVar1 + 300) & local_1c) != 0)) {
    uVar6 = (*(uint *)(iVar1 + 0x114) & local_30) >> local_34;
    if (((uVar6 == 1) && ((*puVar5 & 0x8000) == 0)) || ((uVar6 == 2 && ((*puVar5 & 0x8000) != 0))))
    {
      *(uint *)(iVar1 + 0x124) = *(uint *)(iVar1 + 0x124) | local_1c;
    }
  }
  FUN_00000b58(uVar2);
  return uVar4 >> 0x10 & 0xff;
}

