// rea decompile_all
// name: FUN_0001074a
// address: 0x1074a
// body: available
// range: 0x1074a-0x107b9 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0001074a(void)

{
  bool bVar1;
  int iVar2;
  int unaff_r4;
  int unaff_r5;
  int iVar3;
  uint uVar4;
  undefined4 unaff_r7;
  undefined8 uVar5;
  int in_stack_00000068;
  undefined4 in_stack_0000006c;
  undefined1 in_stack_00000070;
  int in_stack_00000074;
  undefined1 uStack00000078;
  undefined1 uStack00000079;
  undefined1 uStack0000007a;
  undefined1 uStack0000007b;
  undefined1 in_stack_0000007c;
  undefined1 in_stack_00000080;
  
  *(short *)(in_stack_00000074 + 0x42) = (short)unaff_r5;
  *(short *)(unaff_r4 + 0x32) = (short)unaff_r5 + 0x20;
  if (unaff_r5 != DAT_000107e0) {
    in_stack_00000080 = 0x7f;
    iVar3 = unaff_r5 + in_stack_00000068 * 0x4000;
    iVar2 = FUN_00009fac(iVar3);
    if (iVar2 == 0) {
      FUN_000001a0(&stack0x00000078,0xff);
      in_stack_0000007c = (undefined1)((uint)unaff_r7 >> 0x18);
      uStack0000007b = (undefined1)((uint)unaff_r7 >> 0x10);
      uStack0000007a = (undefined1)((uint)unaff_r7 >> 8);
      uStack00000079 = (undefined1)unaff_r7;
      uStack00000078 = 0x11;
      iVar2 = FUN_00009fac(iVar3 + 1,&stack0x00000078,5);
      if (iVar2 == 0) {
        in_stack_00000080 = 0x3f;
        uVar5 = FUN_00009fac(iVar3,&stack0x00000080,1);
        if ((int)uVar5 == 0) {
          FUN_0000fe26(0,(int)((ulonglong)uVar5 >> 0x20),in_stack_0000006c);
        }
      }
    }
  }
  *(undefined1 *)(unaff_r4 + 5) = 0;
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  FUN_00009094(9);
  FUN_0000918c();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  *(undefined1 *)(unaff_r4 + 5) = in_stack_00000070;
  return 0;
}

