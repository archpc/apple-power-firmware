// rea decompile_all
// name: FUN_00007db4
// address: 0x7db4
// body: available
// range: 0x7db4-0x7eb3 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00007db4(int param_1,undefined2 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined2 *puVar5;
  uint uVar6;
  undefined4 local_30;
  undefined2 local_1c [2];
  undefined2 local_18 [2];
  
  local_18[0] = param_2;
  uVar6 = param_3 - 0x11U & 0xff;
  iVar4 = DAT_00007eb4 + param_1 * 0xb + uVar6;
  *(undefined1 *)(iVar4 + 8) = 0;
  cVar1 = *(char *)((int)local_18 + uVar6);
  iVar2 = FUN_00008d2c(param_1);
  if (iVar2 != 0) {
    return;
  }
  local_30 = 0;
  iVar2 = DAT_00007eb8 + param_1 * 0x1cc;
  puVar5 = (undefined2 *)(iVar2 + 0x38);
  puVar3 = (undefined2 *)(iVar2 + 0x3a);
  if (*(char *)((int)puVar5 + uVar6) == cVar1) {
    *(char *)((int)puVar3 + uVar6) = cVar1;
    FUN_0000ca08(param_1,param_3);
    *(undefined1 *)(iVar4 + 8) = 1;
    return;
  }
  if (*(char *)((int)puVar3 + uVar6) == cVar1) {
    iVar2 = FUN_0000ca50(param_1,param_3);
    if (iVar2 != 0) {
      return;
    }
    *(undefined1 *)((int)puVar5 + uVar6) = *(undefined1 *)((int)puVar3 + uVar6);
    return;
  }
  if ((*(char *)(iVar2 + 0x1c) != '\x01') || (3 < *(byte *)(iVar2 + 0x1f))) goto LAB_00007e96;
  if ((*(char *)(iVar2 + 0x1c) != '\x01') || (*(char *)(iVar2 + 0x15) != '\x01')) {
    if ((*(char *)(iVar2 + 0x20) != '\x01') || (*(byte *)(iVar2 + 0x3e) < 2)) {
      local_30 = 0xb;
      goto LAB_00007e96;
    }
    if (cVar1 == '\x02') {
      FUN_00000b80(0x960);
      local_1c[0] = FUN_000088d4(param_1);
      if ((*(char *)((int)local_1c + (uint)*(byte *)(iVar2 + 0x1a)) == '\x02') &&
         (iVar2 = FUN_00008d2c(param_1), iVar2 == 0)) {
        *puVar3 = param_2;
        *puVar5 = param_2;
        return;
      }
      local_30 = 0xb;
      goto LAB_00007e96;
    }
  }
  local_30 = 2;
LAB_00007e96:
  FUN_0000c9fc(param_1,param_3,local_30);
  *(char *)((int)puVar3 + uVar6) = cVar1;
  return;
}

