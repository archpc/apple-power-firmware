// rea decompile_all
// name: FUN_0000c49c
// address: 0xc49c
// body: available
// range: 0xc49c-0xc5ab inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000c49c(int param_1,int param_2,code *param_3,int param_4)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  
  cVar1 = *(char *)(DAT_0000c5b0 + 0x19);
  if (cVar1 != '\x02') {
    if (param_4 == 0) {
      uVar5 = *(uint *)(param_2 + 8) & 0xf;
      if (uVar5 != 0) {
        if (uVar5 == 5) {
          uVar6 = 0;
          goto LAB_0000c4e4;
        }
        if (cVar1 != '\x01') {
          bVar2 = *(byte *)(param_2 + 1);
          iVar4 = DAT_0000c5b4 + param_1 * 0x30;
          for (iVar3 = 0; (uint)bVar2 * 4 - iVar3 != 0; iVar3 = iVar3 + 4) {
            *(undefined4 *)(iVar4 + 0xc + iVar3) = *(undefined4 *)(param_2 + iVar3 + 8);
          }
          if (uVar5 != 1) {
            if (uVar5 != 2) {
              return;
            }
            if (*(char *)(iVar4 + 10) != '\x02') {
              *(undefined1 *)(iVar4 + 0x29) = 1;
              *(byte *)(iVar4 + 0x28) = bVar2;
              FUN_0000c254(param_1,iVar4,5,0);
            }
            (*param_3)(param_1);
            return;
          }
          uVar6 = 0;
          goto LAB_0000c57c;
        }
        goto LAB_0000c558;
      }
      if (*(char *)(DAT_0000c5b4 + (uint)(param_1 != 1) * 0x30 + 10) == '\x01') {
        uVar6 = 0;
        goto LAB_0000c540;
      }
    }
    else {
      uVar5 = *(uint *)(param_2 + 0xc) & 0xf;
      if (uVar5 != 0) {
        if (uVar5 != 2) {
          if (uVar5 != 5) {
            return;
          }
          uVar6 = 1;
LAB_0000c4e4:
          FUN_0000c5b8(param_1,param_2,param_3,uVar6);
          return;
        }
        if (cVar1 != '\x01') {
          uVar6 = 1;
LAB_0000c57c:
          FUN_0000c674(param_1,param_2,param_3,uVar6);
          return;
        }
        goto LAB_0000c558;
      }
      if (*(char *)(DAT_0000c5b4 + (uint)(param_1 != 1) * 0x30 + 10) == '\x01') {
        uVar6 = 1;
LAB_0000c540:
        FUN_0000c644(param_1,param_3,uVar6);
        return;
      }
    }
    *(undefined1 *)(DAT_0000c5b0 + 0x19) = 2;
  }
LAB_0000c558:
  FUN_0000c454(param_1,param_1 != 1,param_2,param_3);
  return;
}

