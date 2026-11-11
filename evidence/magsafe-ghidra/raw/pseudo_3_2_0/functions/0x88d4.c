// rea decompile_all
// name: FUN_000088d4
// address: 0x88d4
// body: available
// range: 0x88d4-0x8991 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_000088d4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_18;
  
  iVar4 = DAT_00008994 + param_1 * 0x1cc;
  local_18 = CONCAT22((short)((uint)param_4 >> 0x10),*(undefined2 *)(iVar4 + 0x3a));
  uVar3 = (uint)*(byte *)(iVar4 + 0x1a);
  if ((*(char *)(iVar4 + 0x1d) != '\0') &&
     ((*(uint *)(*(int *)(DAT_00008998 + param_1 * 4) + 0xa4) & 7) >> 1 != 0)) {
    return local_18;
  }
  if (*(char *)(iVar4 + 0x15) == '\x01') {
    uVar1 = FUN_0000899c(param_1,-uVar3 + 1 & 0xff,0);
    *(undefined1 *)((int)&local_18 + -uVar3 + 1) = uVar1;
    uVar1 = FUN_0000899c(param_1,uVar3,0);
    goto LAB_0000895c;
  }
  if (*(char *)(iVar4 + 0x1d) == '\0') {
    for (uVar3 = 0; uVar3 != 2; uVar3 = uVar3 + 1) {
      iVar4 = FUN_0000899c(param_1,uVar3 & 0xff,0);
      *(char *)((int)&local_18 + uVar3) = (char)iVar4;
      if (iVar4 != 0) {
        uVar1 = FUN_0000899c(param_1,uVar3 & 0xff,1);
        *(undefined1 *)((int)&local_18 + uVar3) = uVar1;
      }
    }
    return local_18;
  }
  if (*(byte *)((int)&local_18 + uVar3) < 2) {
LAB_0000894a:
    uVar1 = FUN_0000899c(param_1,uVar3,0);
    *(undefined1 *)((int)&local_18 + uVar3) = uVar1;
  }
  else {
    uVar2 = FUN_0000899c(param_1,uVar3,1);
    *(char *)((int)&local_18 + uVar3) = (char)uVar2;
    if (uVar2 < 2) goto LAB_0000894a;
  }
  uVar3 = (uint)*(byte *)(iVar4 + 0x1b);
  uVar1 = 0;
LAB_0000895c:
  *(undefined1 *)((int)&local_18 + uVar3) = uVar1;
  return local_18;
}

