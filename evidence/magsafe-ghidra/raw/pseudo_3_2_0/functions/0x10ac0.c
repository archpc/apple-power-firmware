// rea decompile_all
// name: FUN_00010ac0
// address: 0x10ac0
// body: available
// range: 0x10ac0-0x10c07 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0x10ad6 to 0x107d6 FUN_000107d6 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; Ghidra Listing reports a terminal call at 0x10aee to 0x107d6 FUN_000107d6 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; Ghidra Listing reports a terminal call at 0x10b1e to 0x107d6 FUN_000107d6 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; Ghidra Listing reports a terminal call at 0x10b36 to 0x107d6 FUN_000107d6 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; Ghidra Listing reports a terminal call at 0x10b58 to 0x107d6 FUN_000107d6 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; Ghidra Listing reports a terminal call at 0x10b76 to 0x107d6 FUN_000107d6 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; Ghidra Listing reports a terminal call at 0x10ba6 to 0x107d6 FUN_000107d6 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; Ghidra Listing reports a terminal call at 0x10bbc to 0x107d6 FUN_000107d6 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; Ghidra Listing reports a terminal call at 0x10bda to 0x107d6 FUN_000107d6 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; Ghidra Listing reports a terminal call at 0x10bec to 0x107d6 FUN_000107d6 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; Ghidra Listing reports a terminal call at 0x10c02 to 0x107d6 FUN_000107d6 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thum
// limitations_truncated: true; decompile-index.json keeps the complete list
// pseudocode: provider-specific; not original source


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010ac0(void)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  ushort *extraout_r3;
  int unaff_r4;
  undefined4 unaff_r7;
  undefined8 uVar4;
  int in_stack_00000010;
  undefined1 in_stack_00000014;
  int in_stack_00000024;
  ushort in_stack_0000002c;
  undefined4 in_stack_00000034;
  undefined1 in_stack_0000003c;
  ushort *in_stack_00000040;
  undefined1 in_stack_0000004c;
  int in_stack_00000050;
  uint in_stack_00000054;
  int in_stack_00000060;
  int in_stack_00000068;
  int in_stack_0000006c;
  int in_stack_00000074;
  undefined1 in_stack_00000078;
  undefined1 uStack00000079;
  undefined1 uStack0000007a;
  undefined1 uStack0000007b;
  undefined1 in_stack_0000007c;
  undefined1 in_stack_00000080;
  
  *(short *)(in_stack_00000074 + 0x40) = (short)in_stack_00000068;
  *(short *)(unaff_r4 + 0x32) = (short)in_stack_00000068 + 0x20;
  if (in_stack_00000068 == DAT_00010c08) {
    FUN_000107d6();
    return;
  }
  in_stack_00000080 = 0x7f;
  iVar3 = FUN_00009fac(in_stack_00000068 + 0x4000);
  if (iVar3 != 0) {
    FUN_000107d6();
    return;
  }
  FUN_000001a0(&stack0x00000078,0xff);
  in_stack_0000007c = (undefined1)((uint)unaff_r7 >> 0x18);
  uStack0000007b = (undefined1)((uint)unaff_r7 >> 0x10);
  uStack0000007a = (undefined1)((uint)unaff_r7 >> 8);
  uStack00000079 = (undefined1)unaff_r7;
  in_stack_00000078 = 0x10;
  iVar3 = FUN_00009fac(&LAB_00004000_1 + in_stack_00000068,&stack0x00000078,5);
  if (iVar3 != 0) {
    FUN_000107d6();
    return;
  }
  in_stack_00000080 = 0x3f;
  uVar4 = FUN_00009fac(in_stack_00000068 + 0x4000,&stack0x00000080,1);
  if ((int)uVar4 != 0) {
    FUN_000107d6();
    return;
  }
  FUN_0000ff42(0,(int)((ulonglong)uVar4 >> 0x20),in_stack_0000006c);
  in_stack_00000078 = in_stack_0000004c;
  iVar3 = FUN_00009fac((uint)*extraout_r3 + in_stack_00000050,&stack0x00000078,1);
  uVar2 = entry;
  if (iVar3 != 0) {
    FUN_000107d6();
    return;
  }
  uVar1 = *in_stack_00000040;
  in_stack_00000080 = in_stack_0000003c;
  iVar3 = FUN_00009fac(in_stack_00000024,&stack0x00000080,1);
  if (iVar3 != 0) {
    FUN_000107d6();
    return;
  }
  FUN_000001a0(&stack0x00000078,0xff);
  in_stack_0000007c = (undefined1)((uint)uVar2 >> 0x18);
  uStack0000007b = (undefined1)((uint)uVar2 >> 0x10);
  uStack0000007a = (undefined1)((uint)uVar2 >> 8);
  uStack00000079 = (undefined1)uVar2;
  in_stack_00000078 = (undefined1)in_stack_00000060;
  iVar3 = FUN_00009fac(in_stack_00000024 + 1,&stack0x00000078,5);
  if (iVar3 != 0) {
    FUN_000107d6();
    return;
  }
  in_stack_00000080 = 0x3f;
  iVar3 = FUN_00009fac(in_stack_00000024,&stack0x00000080,1);
  if (iVar3 != 0) {
    FUN_000107d6();
    return;
  }
  in_stack_00000078 = in_stack_00000014;
  iVar3 = FUN_00009fac((uint)uVar1 + in_stack_00000050,&stack0x00000078,1);
  if (iVar3 != 0) {
    FUN_000107d6();
    return;
  }
  *in_stack_00000040 = in_stack_0000002c;
  *(undefined1 *)(in_stack_0000006c + in_stack_00000060 + 0x10) = 0;
  if (2 < in_stack_00000054) {
    FUN_000107d6();
    return;
  }
  uVar4 = FUN_0000a020(in_stack_00000010 + in_stack_00000050,in_stack_00000034);
  if ((int)uVar4 != 0) {
    FUN_000107d6();
    return;
  }
  FUN_0000ff42(0,(int)((ulonglong)uVar4 >> 0x20),in_stack_0000006c);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

