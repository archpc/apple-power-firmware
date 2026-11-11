// rea decompile_all
// name: FUN_00007f90
// address: 0x7f90
// body: available
// range: 0x7f90-0x806b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_00007f90(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_24;
  undefined4 local_18;
  
  local_18 = 0;
  iVar1 = *(int *)(DAT_0000806c + param_1 * 4);
  if (param_2 == 0) {
    local_2c = 0x3000000;
    puVar4 = (uint *)(iVar1 + 0x17c);
    puVar6 = (uint *)(iVar1 + 0x180);
    local_30 = 0x18;
    local_24 = 0x100;
  }
  else {
    local_2c = 0x18000000;
    puVar4 = (uint *)(iVar1 + 0x184);
    puVar6 = (uint *)(iVar1 + 0x188);
    local_30 = 0x1b;
    local_24 = 0x200;
  }
  uVar2 = FUN_00000b70();
  uVar3 = *puVar6;
  *puVar6 = (param_3 & 3) * 0x20000 + 0x200;
  *puVar4 = *puVar4 | 1;
  for (; ((*puVar4 & 1) != 0 && (local_18 < 200)); local_18 = local_18 + 1) {
  }
  FUN_00000b80(0x60);
  uVar5 = *puVar4;
  *puVar6 = uVar3;
  FUN_00000b80(0x1e0);
  *(uint *)(iVar1 + 0x11c) = local_24;
  if (((*(uint *)(iVar1 + 300) & local_24) != 0) && (-1 < (int)uVar3)) {
    uVar3 = (*(uint *)(iVar1 + 0x114) & local_2c) >> local_30;
    if ((uVar3 == 1 && (*puVar6 & 0x8000) == 0) || (uVar3 == 2 && (*puVar6 & 0x8000) != 0)) {
      *(uint *)(iVar1 + 0x124) = *(uint *)(iVar1 + 0x124) | local_24;
    }
  }
  FUN_00000b78(uVar2);
  return uVar5 >> 0x10 & 0xff;
}

