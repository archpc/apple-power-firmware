// rea decompile_all
// name: FUN_00001520
// address: 0x1520
// body: available
// range: 0x1520-0x1641 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00001520(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int aiStack_17c [18];
  uint local_134 [72];
  
  for (iVar1 = 0; iVar1 != 0x40; iVar1 = iVar1 + 4) {
    uVar5 = *(uint *)(param_2 + iVar1);
    *(uint *)((int)local_134 + iVar1 + 0x20) =
         uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18;
  }
  for (iVar1 = 0; iVar1 != 0xc0; iVar1 = iVar1 + 4) {
    uVar6 = *(uint *)((int)local_134 + iVar1 + 0x24);
    uVar5 = *(uint *)((int)local_134 + iVar1 + 0x58);
    *(uint *)((int)local_134 + iVar1 + 0x60) =
         ((uVar5 >> 0x11 | uVar5 << 0xf) ^ (uVar5 >> 0x13 | uVar5 << 0xd) ^ uVar5 >> 10) +
         *(int *)((int)local_134 + iVar1 + 0x44) + *(int *)((int)local_134 + iVar1 + 0x20) +
         ((uVar6 >> 7 | uVar6 << 0x19) ^ (uVar6 >> 0x12 | uVar6 << 0xe) ^ uVar6 >> 3);
  }
  for (iVar1 = 0x48; iVar1 != 0x68; iVar1 = iVar1 + 4) {
    *(undefined4 *)((int)aiStack_17c + iVar1) = *(undefined4 *)(param_1 + iVar1);
  }
  for (iVar1 = 0; iVar1 != 0x40; iVar1 = iVar1 + 1) {
    iVar2 = (local_134[5] & local_134[4]) + local_134[7];
    uVar5 = local_134[iVar1 + 8];
    iVar3 = *(int *)(DAT_00001644 + iVar1 * 4);
    for (iVar4 = 0; iVar4 != -0x1c; iVar4 = iVar4 + -4) {
      *(undefined4 *)((int)local_134 + iVar4 + 0x1c) =
           *(undefined4 *)((int)local_134 + iVar4 + 0x18);
    }
    iVar2 = iVar2 + ((local_134[4] >> 0x19 | local_134[4] << 7) ^
                    (local_134[4] >> 6 | local_134[4] << 0x1a) ^
                    (local_134[4] >> 0xb | local_134[4] << 0x15)) + (local_134[6] & ~local_134[4]) +
            iVar3 + uVar5;
    local_134[4] = local_134[4] + iVar2;
    local_134[0] = ((local_134[0] >> 2 | local_134[0] << 0x1e) ^
                    (local_134[0] >> 0xd | local_134[0] << 0x13) ^
                   (local_134[0] >> 0x16 | local_134[0] << 10)) + iVar2 +
                   ((local_134[2] ^ local_134[1]) & local_134[0] ^ local_134[2] & local_134[1]);
  }
  for (iVar1 = 0x48; iVar1 != 0x68; iVar1 = iVar1 + 4) {
    *(int *)(param_1 + iVar1) = *(int *)((int)aiStack_17c + iVar1) + *(int *)(param_1 + iVar1);
  }
  return;
}

