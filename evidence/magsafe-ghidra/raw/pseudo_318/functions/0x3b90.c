// rea decompile_all
// name: FUN_00003b90
// address: 0x3b90
// body: available
// range: 0x3b90-0x3ba5 inclusive
// range: 0x3efa-0x3efd inclusive
// range: 0x4058-0x405d inclusive
// range: 0x4076-0x4099 inclusive
// range: 0x40ba-0x40db inclusive
// range: 0x40e2-0x40f3 inclusive
// range: 0x412c-0x4135 inclusive
// range: 0x418c-0x418d inclusive
// range: 0x4198-0x41bb inclusive
// range: 0x41be-0x41cb inclusive
// range: 0x4218-0x4219 inclusive
// range: 0x437a-0x4383 inclusive
// range: 0x4442-0x4445 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Removing unreachable block (ram,0x000040ca) */
/* WARNING: Removing unreachable block (ram,0x000041a6) */

void FUN_00003b90(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int *unaff_r5;
  int unaff_r6;
  
  if (0xb < param_2 - 2U) {
    return;
  }
  switch(param_2) {
  case 2:
    if (-1 < param_3) goto LAB_00004080;
    break;
  case 3:
    if ((undefined **)(&switchD_00003ba4::switchdataD_00003ba8)[param_2 - 2U] ==
        &switchD_00003ba4::switchdataD_00003ba8) goto LAB_00004080;
    break;
  case 4:
    return;
  case 5:
    FUN_00002f62(param_1,0,param_3,param_3 << 1);
    FUN_00005a38(param_1);
    return;
  case 6:
    FUN_00006de4(param_1,&switchD_00003ba4::switchdataD_00003ba8,2);
    return;
  case 7:
  case 8:
    return;
  default:
    FUN_00007160(param_1,&switchD_00003ba4::switchdataD_00003ba8,param_3,1);
    return;
  case 0xd:
    FUN_00003088(param_1,&switchD_00003ba4::switchdataD_00003ba8,param_3,
                 (int)(&switchD_00003ba4::switchdataD_00003ba8)[param_2 - 2U] << 0xc);
    return;
  }
  FUN_00003088(param_1);
LAB_00004080:
  iVar1 = *unaff_r5;
  *(undefined4 *)(unaff_r6 + 0x104) = *(undefined4 *)(iVar1 + 8);
  (**(code **)(*(int *)(unaff_r6 + 0x60) + 0x40))
            (param_1,iVar1 + 8,*(undefined1 *)(iVar1 + 1),&LAB_000068ac_1);
  return;
}

