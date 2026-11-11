// rea decompile_all
// name: FUN_0000a4e8
// address: 0xa4e8
// body: available
// range: 0xa4e8-0xa573 inclusive
// range: 0xa6cc-0xa7b9 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000a4e8(int param_1)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 *puVar12;
  uint local_48 [7];
  undefined4 local_2c [6];
  
  iVar11 = DAT_0000a7f4;
  iVar7 = *(int *)(*(int *)(DAT_0000a7f0 + 0x118) + 0x11c);
  if (iVar7 == 0) {
    if (*(char *)(DAT_0000a7f4 + 0x16) == '\x01') {
      local_48[0] = DAT_0000a7e8 + 0x28;
    }
    else if (*(char *)(DAT_0000a7f4 + 0x16) == '\x02') {
      local_48[0] = DAT_0000a7e8 + 0x8c;
    }
    else {
      local_48[0] = DAT_0000a7e8;
      if (*(char *)(DAT_0000a7f4 + 0x16) == '\x03') {
        local_48[0] = DAT_0000a7ec;
      }
    }
    FUN_00002a30(1,local_48);
    *(undefined1 *)(iVar11 + 0x1d6) = 1;
  }
  else {
    if ((DAT_0000a7bc + 0xe & *(uint *)(iVar7 + 4)) == DAT_0000a7bc) {
      uVar4 = (*(uint *)(iVar7 + 4) & 0x1ffffff) >> 0x12;
    }
    else {
      uVar4 = (uint)*(byte *)(iVar7 + 1);
    }
    puVar8 = (uint *)(iVar7 + 8);
    for (iVar11 = 0; uVar4 << 2 != iVar11; iVar11 = iVar11 + 4) {
      uVar5 = *(uint *)((int)puVar8 + iVar11);
      iVar7 = FUN_0000a958(uVar5);
      if (iVar7 != 0) {
        iVar11 = FUN_0000089c(DAT_0000a7d0,iVar7);
        FUN_0000089c(iVar11 + 9,10);
                    /* WARNING: Could not recover jumptable at 0x0000a572. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)((uint)(byte)(&DAT_0000a574)[uVar5 >> 0x1e] * 2 + 0xa576))();
        return;
      }
      *(undefined4 *)((int)local_48 + iVar11) = 0;
    }
    local_48[0] = local_48[0] & 0xc9ffffff;
    if (uVar4 < 8) {
      FUN_00002a30(uVar4,local_48);
      *(byte *)(DAT_0000a7f4 + 0x1d6) = ~(byte)(-1 << uVar4) | (byte)(*puVar8 >> 0x14) & 0x80;
    }
    else {
      FUN_00002a30(7,local_48);
      iVar11 = DAT_0000a7f4;
      *(byte *)(DAT_0000a7f4 + 0x1d6) = (byte)(*puVar8 >> 0x14) | 0x7f;
      uVar4 = uVar4 - 7;
      uVar5 = uVar4 & 0xff;
      if ((uVar5 != 0) && ((uVar4 & 0xff) < 7)) {
        puVar12 = local_2c;
        puVar6 = (undefined4 *)(iVar11 + 0x34c);
        for (uVar9 = uVar5; uVar9 != 0; uVar9 = uVar9 - 1) {
          uVar10 = *puVar12;
          puVar12 = puVar12 + 1;
          *puVar6 = uVar10;
          puVar6 = puVar6 + 1;
        }
        *(char *)(iVar11 + DAT_0000a7e0) = (char)uVar4;
      }
      *(byte *)(iVar11 + DAT_0000a7e4) = ~(byte)(-1 << uVar5);
    }
  }
  if ((param_1 != 0) &&
     (iVar11 = FUN_0000290c(1,0,0,DAT_0000a7f8), puVar2 = DAT_0000a7fc, iVar11 != 0)) {
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_000012d0(DAT_0000a7fc);
    uVar3 = FUN_000011a0(1000,0,DAT_0000a800,0);
    *puVar2 = uVar3;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar4 & 1) == 1);
    }
  }
  return;
}

