// rea decompile_all
// name: FUN_000091a8
// address: 0x91a8
// body: available
// range: 0x91a8-0x9267 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000091a8(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint *puVar3;
  int iVar4;
  
  FUN_00001400(1,0x10);
  iVar4 = DAT_00009278;
  puVar2 = DAT_0000926c;
  uVar1 = DAT_00009268;
  if (*(char *)(DAT_00009278 + 0x26) == '\0') {
    *DAT_0000926c = 0x4000000;
    *puVar2 = *puVar2;
    puVar2[2] = 0;
    *puVar2 = *puVar2;
    puVar2[9] = 0xc;
    puVar2[0xe] = 1;
    puVar2[10] = 0x31;
    puVar2[5] = uVar1;
    puVar2[3] = 0x8000;
    *(undefined1 *)(iVar4 + 0x26) = 1;
  }
  FUN_00000b50();
  puVar3 = DAT_00009270;
  *DAT_00009270 = *DAT_00009270 | 8;
  FUN_00000b58();
  FUN_00000b50();
  puVar3[2] = 0x8000000;
  FUN_00000b58();
  puVar2[3] = 0;
  puVar2[5] = 0x4000;
  puVar2 = DAT_00009274;
  if (*(char *)(iVar4 + 0x27) == '\0') {
    *DAT_00009274 = 0x4000000;
    *puVar2 = *puVar2;
    puVar2[2] = 0;
    *puVar2 = *puVar2;
    puVar2[9] = 0xc;
    puVar2[0xe] = 1;
    puVar2[10] = 0x31;
    puVar2[5] = DAT_00009268;
    puVar2[3] = 0x8000;
    *(undefined1 *)(iVar4 + 0x27) = 1;
  }
  FUN_00000b50();
  puVar3 = DAT_00009270;
  *DAT_00009270 = *DAT_00009270 | 1;
  FUN_00000b58();
  FUN_00000b50();
  puVar3[2] = 0x1000000;
  FUN_00000b58();
  puVar2[3] = 0;
  puVar2[5] = 0x4000;
  return;
}

