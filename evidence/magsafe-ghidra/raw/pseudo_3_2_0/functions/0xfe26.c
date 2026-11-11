// rea decompile_all
// name: FUN_0000fe26
// address: 0xfe26
// body: available
// range: 0xfe26-0xfe6b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000fe26(undefined4 param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint extraout_r3;
  int unaff_r5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  int in_stack_00000060;
  int in_stack_00000064;
  int in_stack_00000068;
  int in_stack_00000074;
  undefined1 in_stack_00000078;
  
  bVar1 = *(byte *)(param_3 + in_stack_00000060);
  uVar5 = (uint)bVar1 + unaff_r5;
  *(char *)(param_3 + in_stack_00000060) = (char)uVar5;
  *(int *)(in_stack_00000064 + 0x44) = *(int *)(in_stack_00000064 + 0x44) + unaff_r5;
  uVar8 = (ulonglong)CONCAT14(bVar1,(uint)*(ushort *)(in_stack_00000074 + 0x42));
  if (*(ushort *)(in_stack_00000074 + 0x42) == DAT_0000fffc) {
    uVar8 = FUN_000107ba();
    uVar5 = extraout_r3;
  }
  iVar3 = (int)(uVar8 >> 0x20);
  uVar2 = (uint)uVar8;
  uVar4 = uVar5 & 0xff;
  iVar6 = uVar4 - 8;
  if (uVar4 < 8) {
    iVar6 = 0;
  }
  uVar7 = 0xff;
  for (uVar5 = uVar5 - (iVar6 + 7U & 0x1f8); (uVar5 & 0xff) != 0; uVar5 = uVar5 - 1) {
    uVar7 = uVar7 >> 1;
  }
  uVar5 = (iVar6 + 7U & 0xff) >> 3;
  if (uVar4 - iVar3 != 1) {
    iVar3 = iVar3 + -8;
    if (uVar8 < 0x800000000) {
      iVar3 = 0;
    }
    uVar4 = (iVar3 + 7U & 0xff) >> 3;
    if (uVar5 != uVar4) {
      iVar3 = 0;
      while (iVar3 < (int)(uVar5 - uVar4)) {
        in_stack_00000078 = 0;
        iVar6 = FUN_00009fac(in_stack_00000068 * 0x4000 + (uVar4 + iVar3 & 0xff) +
                             (uint)*(ushort *)(in_stack_00000074 + 0x42) + 6,&stack0x00000078,1);
        iVar3 = iVar3 + 1;
        if (iVar6 != 0) {
          FUN_000107ba();
          return;
        }
      }
      uVar2 = (uint)*(ushort *)(in_stack_00000074 + 0x42);
    }
  }
  in_stack_00000078 = (char)uVar7;
  FUN_00009fac(in_stack_00000068 * 0x4000 + uVar5 + uVar2 + 6,&stack0x00000078,1);
  FUN_000107ba();
  return;
}

