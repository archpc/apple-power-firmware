// rea decompile_all
// name: FUN_0001422c
// address: 0x1422c
// body: available
// range: 0x1422c-0x1435d inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0001422c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int aiStack_17c [18];
  uint local_134 [72];
  
  for (iVar5 = 0; iVar5 != 0x40; iVar5 = iVar5 + 4) {
    uVar3 = *(uint *)(param_2 + iVar5);
    *(uint *)((int)local_134 + iVar5 + 0x20) =
         uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
  }
  for (iVar5 = 0; iVar5 != 0xc0; iVar5 = iVar5 + 4) {
    uVar3 = *(uint *)((int)local_134 + iVar5 + 0x58);
    uVar4 = *(uint *)((int)local_134 + iVar5 + 0x24);
    *(uint *)((int)local_134 + iVar5 + 0x60) =
         *(int *)((int)local_134 + iVar5 + 0x20) + *(int *)((int)local_134 + iVar5 + 0x44) +
         ((uVar3 >> 0x11 | uVar3 << 0xf) ^ uVar3 >> 10 ^ (uVar3 >> 0x13 | uVar3 << 0xd)) +
         ((uVar4 >> 7 | uVar4 << 0x19) ^ uVar4 >> 3 ^ (uVar4 >> 0x12 | uVar4 << 0xe));
  }
  for (iVar5 = 0x48; iVar5 != 0x68; iVar5 = iVar5 + 4) {
    *(undefined4 *)((int)aiStack_17c + iVar5) = *(undefined4 *)(param_1 + iVar5);
  }
  for (iVar5 = 0; iVar5 != 0x40; iVar5 = iVar5 + 1) {
    iVar1 = *(int *)(DAT_00014360 + iVar5 * 4) + local_134[7];
    uVar3 = local_134[iVar5 + 8];
    for (iVar2 = 0; iVar2 != -0x1c; iVar2 = iVar2 + -4) {
      *(undefined4 *)((int)local_134 + iVar2 + 0x1c) =
           *(undefined4 *)((int)local_134 + iVar2 + 0x18);
    }
    iVar1 = iVar1 + ((local_134[4] >> 0x19 | local_134[4] << 7) ^
                    (local_134[4] >> 6 | local_134[4] << 0x1a) ^
                    (local_134[4] >> 0xb | local_134[4] << 0x15)) +
            (local_134[6] & ~local_134[4] | local_134[5] & local_134[4]) + uVar3;
    local_134[4] = local_134[4] + iVar1;
    local_134[0] = ((local_134[0] >> 2 | local_134[0] << 0x1e) ^
                    (local_134[0] >> 0xd | local_134[0] << 0x13) ^
                   (local_134[0] << 10 | local_134[0] >> 0x16)) + iVar1 +
                   ((local_134[2] ^ local_134[1]) & local_134[0] ^ local_134[2] & local_134[1]);
  }
  for (iVar5 = 0x48; iVar5 != 0x68; iVar5 = iVar5 + 4) {
    *(int *)(param_1 + iVar5) = *(int *)((int)aiStack_17c + iVar5) + *(int *)(param_1 + iVar5);
  }
  return;
}

