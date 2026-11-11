// rea decompile_all
// name: FUN_000036ac
// address: 0x36ac
// body: available
// range: 0x36ac-0x36c1 inclusive
// range: 0x3868-0x386b inclusive
// range: 0x3b60-0x3b75 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Control flow encountered bad instruction data */

void FUN_000036ac(uint param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined *puVar1;
  undefined **ppuVar2;
  uint uVar3;
  int unaff_r4;
  undefined1 *unaff_r5;
  int unaff_r6;
  int iVar4;
  int unaff_r7;
  uint *puVar5;
  
  if (6 < param_2 - 2U) {
    return;
  }
  ppuVar2 = &switchD_000036c0::switchdataD_000036c4;
  puVar1 = (&switchD_000036c0::switchdataD_000036c4)[param_2 - 2U];
  switch(param_2) {
  case 2:
    *unaff_r5 = 0;
    FUN_000031a0(param_1,0x10);
    ppuVar2 = (undefined **)0x10;
  case 3:
    FUN_000031a0(param_1,ppuVar2);
    return;
  default:
    if ((puVar1 != (undefined *)0x11) || (uVar3 = *(uint *)(unaff_r5 + 4), -1 < (int)uVar3)) {
      iVar4 = FUN_00002fd4();
      if (iVar4 == 0) {
        iVar4 = FUN_00002fd4();
        if (iVar4 == 0) goto LAB_00003eee;
        if (*(char *)(unaff_r4 + unaff_r7) == '\0') goto LAB_00003dc4;
      }
      else if (*(char *)(unaff_r4 + unaff_r7) != '\0') {
LAB_00003dc4:
        FUN_000031a0(param_1,0x12);
        return;
      }
      FUN_00003088(param_1);
      return;
    }
    if (((-1 < (int)(uVar3 << 5)) || ((uVar3 & 0x7fffffff) >> 0x1b != 1)) ||
       (uVar3 = (uint)*(byte *)(unaff_r4 + unaff_r6 + 0x78) * 4 + 0x1c & 0x1fc, uVar3 < 0x1b)) {
LAB_00003eee:
      FUN_00005acc(param_1);
      FUN_00005a38(param_1);
      return;
    }
    *(undefined1 *)(param_4 + 0xe6) = 0x11;
    puVar1 = (undefined *)(unaff_r4 + 0xb6);
    iVar4 = uVar3 + 0x8800;
    break;
  case 6:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 8:
    if (puVar1[0x36e3] == '\x06') {
      (**(code **)(*(int *)(puVar1 + 0x3724) + 0x10))(param_1,DAT_00003f28);
      return;
    }
    FUN_00002b28(param_1);
    if ((puVar1[0x3839] == '\0') && (*(char *)(DAT_00003f2c + param_1 * 0xf0 + 0xee) == '\0')) {
      FUN_00007160(param_1,0,1,puVar1[0x36ed],puVar1 + 0x3760);
      return;
    }
    iVar4 = DAT_00003f2c + param_1 * 0xf0;
    *(undefined1 *)(iVar4 + 0xee) = 0;
    if (puVar1[0x383a] == '\0') {
      puVar5 = (uint *)(puVar1 + 0x3844);
      for (uVar3 = 0; uVar3 != 6; uVar3 = uVar3 + 1) {
        puVar5[-0x32] = 0;
        if (((byte)puVar1[0x3842] >> (uVar3 & 0xff) & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00003e26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)((uint)(byte)(&DAT_00003e28)[*puVar5 >> 0x1e] * 2 + 0x3e2a))();
          return;
        }
        puVar5 = puVar5 + 1;
      }
      puVar1[0x383b] = 0;
      uVar3 = 0x1c;
    }
    else {
      uVar3 = (uint)(byte)puVar1[0x36ed] << 2;
      if (param_1 < 2) {
        puVar1[0x383a] = 0;
      }
    }
    *(undefined1 *)(iVar4 + 0xe6) = 0x11;
    puVar1 = puVar1 + 0x3760;
    iVar4 = (uVar3 & 0x1fc) + 0x8000;
  }
  FUN_00007172(param_1,0,0x11,iVar4,puVar1);
  return;
}

