// rea decompile_all
// name: FUN_00005d88
// address: 0x5d88
// body: available
// range: 0x5d88-0x5de7 inclusive
// range: 0x5dec-0x5fc3 inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00005d88(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  char *pcVar8;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar1 = DAT_00005fd4;
  iVar2 = *(int *)(DAT_00005fd4 + param_1 * 0xf0);
  uVar7 = (uint)*(byte *)(iVar2 + 2);
  FUN_00005ba4(param_1);
  uVar5 = DAT_00005fcc;
  piVar6 = (int *)(iVar1 + param_1 * 0xf0);
  pcVar8 = (char *)(DAT_00005fd8 + param_1 * 0x1cc);
  if (uVar7 == 6) {
    (*(code *)**(undefined4 **)(pcVar8 + 0x60))(param_1,0x41,*piVar6);
    pcVar8[0x43] = '\x02';
    FUN_000030f0(param_1,9,0x1b);
    return;
  }
  if (uVar7 == 0x12) {
    if (pcVar8[0x15] == '\0') {
      uVar5 = *(uint *)(iVar2 + 4);
      if ((((int)uVar5 < 0) && (DAT_00005fc8 <= (DAT_00005fc4 & uVar5))) && ((int)(uVar5 << 5) < 0))
      {
        FUN_00007272(param_1,0,0x12,(DAT_00005fcc & uVar5 >> 0x10) + 0x8800,pcVar8 + 0xec);
        return;
      }
    }
    else if (((pcVar8[0x15] == '\x01') && (uVar5 = *(uint *)(iVar2 + 4), (int)uVar5 < 0)) &&
            (uVar7 = (uVar5 & 0x1ffffff) >> 0x10, 0x1a < uVar7)) {
      if ((uVar5 & 0x7fffffff) >> 0x1b != 0) {
        FUN_00000170(iVar2 + 0x22,iVar2 + 8,uVar7 - 0x1a);
LAB_00005fb0:
        FUN_00000170(iVar2 + 8,DAT_00005fe0,0x1a);
LAB_00005fba:
        uVar3 = 0xc;
LAB_00005fbc:
        FUN_00003258(param_1,uVar3);
        return;
      }
      FUN_00000170(DAT_00005fe0,iVar2 + 8,0x1a);
    }
  }
  else {
    if (uVar7 != 0x11) {
      if (uVar7 == 0x10) {
        *(undefined1 *)((int)piVar6 + 0xa9) = 1;
        if ((DAT_00005fc4 & *(uint *)(iVar2 + 4)) != 0x20000) {
          return;
        }
        switch(*(undefined2 *)(iVar2 + 8)) {
        case 1:
          if (((*pcVar8 == '\0') || (-1 < (int)((uint)(byte)pcVar8[0x9e] << 0x18))) ||
             (-1 < (int)((uint)(byte)pcVar8[0x106] << 0x19))) break;
          *(undefined1 *)((int)piVar6 + 0xee) = 1;
          uVar3 = 0x10;
          goto LAB_00005fbc;
        case 2:
          if (*pcVar8 != '\x01') {
            uVar3 = 0x2e;
            goto LAB_00005fbc;
          }
          break;
        case 3:
          if (pcVar8[0x15] == '\x01') {
            if (pcVar8[0x175] == '\0') {
              return;
            }
            FUN_00006408(param_1,0x10,2,DAT_00005fdc);
            return;
          }
          break;
        case 4:
          if (pcVar8[0x15] == '\0') {
            return;
          }
        }
        FUN_00006374(param_1,0x10);
        return;
      }
      if (uVar7 - 3 < 2) {
        (*(code *)**(undefined4 **)(pcVar8 + 0x60))(param_1,0x41,*piVar6);
      }
      if ((uVar7 < 0x10) && ((1 << uVar7 & DAT_00005fd0) != 0)) {
        return;
      }
      pcVar8[0x43] = '\x02';
      FUN_000030f0(param_1,9,0x1b);
      if (uVar7 - 3 < 2) {
        return;
      }
      goto LAB_00005f92;
    }
    if (pcVar8[0x15] == '\0') {
      uVar7 = *(uint *)(iVar2 + 4);
      if ((int)uVar7 < 0) {
        uVar4 = (uVar7 & 0x1ffffff) >> 0x10;
        if (uVar4 < 0x1b) goto LAB_00005fba;
        uVar7 = (uVar7 & 0x7fffffff) >> 0x1b;
        if (uVar7 == 1) {
          FUN_0000080c(iVar2 + 0x22,iVar2 + 8,uVar4 - 0x1a);
          goto LAB_00005fb0;
        }
        if (uVar7 == 0) {
          FUN_00000170(DAT_00005fe0,iVar2 + 8,0x1a);
          local_18 = 0;
          local_1c = 0;
          uVar7 = *(uint *)(*piVar6 + 4) >> 0x10;
          FUN_00007272(param_1,0,0x11,(uVar5 & uVar7) + (uVar7 + 0x800 & 0x7800) + 0x8400,&local_1c)
          ;
        }
      }
    }
    else {
      FUN_00006374(param_1,0x10);
    }
  }
  pcVar8[0x43] = '\x02';
  FUN_000030f0(param_1,9,0x1b);
LAB_00005f92:
  (*(code *)**(undefined4 **)(pcVar8 + 0x60))(param_1,0x1e,*piVar6);
  return;
}

