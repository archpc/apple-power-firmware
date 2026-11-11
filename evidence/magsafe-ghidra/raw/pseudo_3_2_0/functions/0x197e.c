// rea decompile_all
// name: FUN_0000197e
// address: 0x197e
// body: available
// range: 0x197e-0x1a37 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_0000197e(void)

{
  int iVar1;
  undefined4 unaff_r5;
  uint unaff_r6;
  undefined4 unaff_r7;
  undefined4 in_stack_00000004;
  uint in_stack_00000008;
  byte in_stack_0000000c;
  uint in_stack_00000028;
  byte in_stack_0000002c;
  uint in_stack_00000048;
  byte in_stack_0000004c;
  byte in_stack_0000006c;
  
code_r0x0000197e:
  FUN_00001a3c(&stack0x0000004c);
LAB_00001984:
  if ((in_stack_0000000c & 1) == 0) {
    FUN_00001a3c(&stack0x0000000c);
  }
  else {
    iVar1 = FUN_00001a5e(&stack0x0000000c,unaff_r7);
    FUN_00001a3c(&stack0x0000000c);
    unaff_r7 = unaff_r5;
    if (iVar1 != 0) {
      in_stack_00000028 = in_stack_00000028 | unaff_r6;
    }
  }
LAB_0000194c:
  iVar1 = FUN_000016fc(&stack0x0000006c,&stack0x0000004c);
  if (iVar1 == 0) {
    FUN_00000170(in_stack_00000004,&stack0x0000002c,0x20);
    return in_stack_00000008 ^ 1;
  }
  if ((in_stack_0000006c & 1) == 0) {
    FUN_00001a3c(&stack0x0000006c);
  }
  else {
    if ((in_stack_0000004c & 1) == 0) goto code_r0x0000197e;
    if (iVar1 < 1) goto LAB_000019fe;
    FUN_00001730(&stack0x0000006c,&stack0x0000004c);
    FUN_00001a3c(&stack0x0000006c);
    iVar1 = FUN_00001730(&stack0x0000002c,&stack0x0000000c);
    if (iVar1 != 0) {
      FUN_00001a5e(&stack0x0000002c,unaff_r7);
    }
  }
  if ((in_stack_0000002c & 1) == 0) {
    FUN_00001a3c(&stack0x0000002c);
  }
  else {
    iVar1 = FUN_00001a5e(&stack0x0000002c,unaff_r7);
    FUN_00001a3c(&stack0x0000002c);
    unaff_r7 = unaff_r5;
    if (iVar1 != 0) {
      in_stack_00000048 = in_stack_00000048 | unaff_r6;
    }
  }
  goto LAB_0000194c;
LAB_000019fe:
  FUN_00001730(&stack0x0000004c,&stack0x0000006c);
  FUN_00001a3c(&stack0x0000004c);
  iVar1 = FUN_00001730(&stack0x0000000c,&stack0x0000002c);
  if (iVar1 != 0) {
    FUN_00001a5e(&stack0x0000000c,unaff_r7);
  }
  goto LAB_00001984;
}

