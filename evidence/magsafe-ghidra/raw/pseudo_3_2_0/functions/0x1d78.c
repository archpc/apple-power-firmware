// rea decompile_all
// name: FUN_00001d78
// address: 0x1d78
// body: available
// range: 0x1d78-0x1e8b inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00001d78(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *unaff_r5;
  uint *unaff_r6;
  uint *in_stack_00000010;
  int iStack00000014;
  int in_stack_00000018;
  uint in_stack_0000001c;
  int in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  
  unaff_r6[0x1b] = unaff_r6[0x1b] & 0xfffffff7;
  unaff_r6[0x1b] = unaff_r6[0x1b] | 1;
  iStack00000014 = 0x4b;
  FUN_00000b80(&DAT_000012c0);
  in_stack_00000010[6] = in_stack_00000010[6] & 0xfffffffb | 3;
  in_stack_00000010[3] = in_stack_00000010[3] & 0xfffffffa | 2;
  *in_stack_00000010 = *in_stack_00000010 & 0xfffffff3;
  iVar2 = DAT_00001ee0;
  iVar3 = DAT_00001ee0 + in_stack_00000028 * 0x5c;
  uVar1 = (undefined2)DAT_00001e9c;
  *(undefined2 *)(iVar3 + 0x44) = uVar1;
  *(undefined2 *)(iVar3 + 0x46) = uVar1;
  FUN_00008590(in_stack_00000028,0);
  FUN_00008590(in_stack_00000028,1);
  unaff_r6[0x19] = DAT_00001ea0 & unaff_r6[0x19];
  unaff_r6[0x19] = unaff_r6[0x19] | 0xe0000;
  unaff_r5[0x1b] = unaff_r5[0x1b] & 0xfff3ffff;
  unaff_r5[0x1b] = unaff_r5[0x1b] & 0xfb7fffff;
  unaff_r6[0x1d] = unaff_r6[0x1d] & ~in_stack_0000001c;
  iVar3 = DAT_00001ee4;
  *(undefined1 *)(DAT_00001ee4 + in_stack_00000028 * 0x88 + 0x85) = 1;
  *(int *)(DAT_00001ee8 + in_stack_00000020) = DAT_00001ee8 + in_stack_00000020 + 4;
  *(undefined4 *)(iVar3 + in_stack_00000028 * 0x88) = DAT_00001eec;
  *(undefined4 *)(iVar2 + in_stack_00000028 * 0x5c) = DAT_00001ef0;
  *unaff_r5 = 0x3f;
  unaff_r5[1] = 0xfffffffd;
  unaff_r5[2] = 0xffffffff;
  unaff_r5[7] = 0xfffffffd;
  unaff_r5[8] = 0xffffffff;
  unaff_r5[4] = 0xfffffffd;
  unaff_r5[5] = 0xffffffff;
  *(undefined4 *)(in_stack_00000018 + 4) = DAT_00001ea4;
  unaff_r5[3] = 0xffffffff;
  unaff_r5[9] = 0xffffffff;
  unaff_r5[6] = 0xffffffff;
  unaff_r5[0xc] = DAT_00001ea8;
  unaff_r5[0xf] = 0xf;
  unaff_r5[0x16] = iStack00000014 << 2;
  unaff_r5[0x17] = DAT_00001eac;
  *unaff_r6 = DAT_00001eb0 & *unaff_r6;
  unaff_r6[7] = unaff_r6[7] & 0xffff;
  unaff_r6[7] = DAT_00001eb4 | unaff_r6[7];
  unaff_r5[0x12] = DAT_00001eb8;
  *(undefined1 *)(in_stack_00000024 + 0x32) = 1;
  *DAT_00001ef4 = 1;
  return;
}

