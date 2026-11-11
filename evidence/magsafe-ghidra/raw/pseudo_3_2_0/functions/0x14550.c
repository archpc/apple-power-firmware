// rea decompile_all
// name: FUN_00014550
// address: 0x14550
// body: available
// range: 0x14550-0x14677 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00014550(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int aiStack_17c [18];
  uint local_134 [72];
  
  iVar1 = DAT_00014678;
  for (iVar2 = 0; iVar2 != 0x40; iVar2 = iVar2 + 4) {
    uVar6 = *(uint *)(DAT_00014678 + iVar2 + 4);
    *(uint *)((int)local_134 + iVar2 + 0x20) =
         uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18;
  }
  for (iVar2 = 0; iVar2 != 0xc0; iVar2 = iVar2 + 4) {
    uVar7 = *(uint *)((int)local_134 + iVar2 + 0x24);
    uVar6 = *(uint *)((int)local_134 + iVar2 + 0x58);
    *(uint *)((int)local_134 + iVar2 + 0x60) =
         ((uVar6 >> 0x11 | uVar6 << 0xf) ^ (uVar6 >> 0x13 | uVar6 << 0xd) ^ uVar6 >> 10) +
         *(int *)((int)local_134 + iVar2 + 0x44) + *(int *)((int)local_134 + iVar2 + 0x20) +
         ((uVar7 >> 7 | uVar7 << 0x19) ^ (uVar7 >> 0x12 | uVar7 << 0xe) ^ uVar7 >> 3);
  }
  for (iVar2 = 0x48; iVar2 != 0x68; iVar2 = iVar2 + 4) {
    *(undefined4 *)((int)aiStack_17c + iVar2) = *(undefined4 *)(DAT_00014678 + iVar2);
  }
  for (iVar2 = 0; iVar2 != 0x40; iVar2 = iVar2 + 1) {
    iVar3 = (local_134[5] & local_134[4]) + local_134[7];
    uVar6 = local_134[iVar2 + 8];
    iVar4 = *(int *)(DAT_0001467c + iVar2 * 4);
    for (iVar5 = 0; iVar5 != -0x1c; iVar5 = iVar5 + -4) {
      *(undefined4 *)((int)local_134 + iVar5 + 0x1c) =
           *(undefined4 *)((int)local_134 + iVar5 + 0x18);
    }
    iVar3 = iVar3 + ((local_134[4] >> 0x19 | local_134[4] << 7) ^
                    (local_134[4] >> 6 | local_134[4] << 0x1a) ^
                    (local_134[4] >> 0xb | local_134[4] << 0x15)) + (local_134[6] & ~local_134[4]) +
            iVar4 + uVar6;
    local_134[4] = local_134[4] + iVar3;
    local_134[0] = ((local_134[0] >> 2 | local_134[0] << 0x1e) ^
                    (local_134[0] >> 0xd | local_134[0] << 0x13) ^
                   (local_134[0] >> 0x16 | local_134[0] << 10)) + iVar3 +
                   ((local_134[2] ^ local_134[1]) & local_134[0] ^ local_134[2] & local_134[1]);
  }
  for (iVar2 = 0x48; iVar2 != 0x68; iVar2 = iVar2 + 4) {
    *(int *)(iVar1 + iVar2) = *(int *)((int)aiStack_17c + iVar2) + *(int *)(iVar1 + iVar2);
  }
  return;
}

