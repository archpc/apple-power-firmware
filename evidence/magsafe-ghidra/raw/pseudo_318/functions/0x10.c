// rea decompile_all
// name: DataAbort
// address: 0x10
// body: available
// range: 0x10-0x13 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void DataAbort(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  uint *puVar2;
  byte *pbVar3;
  int iVar4;
  int *piVar5;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 in_r12;
  bool in_NG;
  undefined1 auStack_28 [4];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  if (in_NG) {
    *param_2 = 0x1c;
    param_2[-1] = auStack_28;
    param_2[-2] = in_r12;
    param_2[-3] = unaff_r10;
    param_2[-4] = unaff_r9;
    param_2[-5] = unaff_r6;
    param_2[-6] = unaff_r5;
    param_2[-7] = unaff_r4;
    param_2[-8] = param_2;
  }
  *puRam00000124 = 0xdd000000;
  *puRam00000128 = uRam0000012c;
  puVar1 = puRam00000130;
  *puRam00000130 = 0x21;
  puVar1[2] = uRam00000134;
  puVar1 = puRam00000138;
  *puRam00000138 = 0x40;
  puVar1[2] = 0x380000;
  puVar1[6] = 0x40;
  puVar1 = puRam0000013c;
  *puRam0000013c = 7;
  puVar1[2] = 0x1b6;
  puVar1[6] = 7;
  *puRam00000140 = 0x12;
  uStack_24 = FUN_00000b50();
  puVar2 = puRam00000144;
  *puRam00000144 = *puRam00000144 & 0xfffffff8;
  pbVar3 = pbRam00000148;
  puVar2[1] = (uint)pbRam00000148[0x19];
  puVar2[2] = puVar2[2] & 0xfffffff8;
  puVar2[4] = (puVar2[4] & 0xffffff80) + (*pbVar3 & 0x7f);
  FUN_00000b60(0x32);
  uStack_18 = 5;
  uStack_1c = 2;
  *puVar2 = *puVar2 & 0xfffffffd | 5;
  FUN_00000b60(0x32);
  uStack_20 = 1;
  *puVar2 = *puVar2 & 0xfffffffe | 6;
  FUN_00000b58(uStack_24);
  *puRam0000014c = 0x4f00;
  piVar5 = piRam00000154;
  iVar4 = iRam00000150;
  *piRam00000154 = iRam00000150 + 0x40;
  puVar1 = puRam00000158;
  *puRam00000158 = 0x300;
  *piVar5 = iVar4;
  puVar1[1] = 0;
  *piVar5 = iVar4 + 1;
  puRam0000014c[1] = 0x4f00;
  *piVar5 = iVar4 + 0x41;
  puVar1[2] = 0x900;
  *piVar5 = iVar4 + 2;
  puVar1[3] = 0x200;
  *piVar5 = iVar4 + 3;
  puVar1[4] = 0x2f00;
  *piVar5 = iVar4 + 4;
  puVar1[5] = 0x2f00;
  *piVar5 = iVar4 + 5;
  *puRam0000015c = 0;
  puVar1 = puRam00000160;
  puRam00000160[7] = 3;
  puVar1[4] = 3;
  puVar1[3] = uStack_18;
  puVar1[2] = uStack_20;
  *puVar1 = uStack_1c;
  return;
}

