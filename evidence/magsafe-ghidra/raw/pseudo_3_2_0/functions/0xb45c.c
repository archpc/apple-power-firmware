// rea decompile_all
// name: FUN_0000b45c
// address: 0xb45c
// body: available
// range: 0xb45c-0xb717 inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000b45c(undefined4 param_1,char *param_2,code *param_3)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint local_34;
  undefined1 auStack_30 [24];
  undefined1 local_18;
  undefined1 local_17;
  
  uVar9 = *(uint *)(param_2 + 8);
  FUN_0000a908(1);
  iVar3 = DAT_0000b72c;
  if (uVar9 >> 0x10 == 0xff00) {
LAB_0000b4aa:
    if ((uVar9 & 0xff) >> 6 != 0) {
      return;
    }
    FUN_0000b7c8(param_1,*(undefined4 *)(param_2 + 8),param_3);
    return;
  }
  if (uVar9 >> 0x10 != DAT_0000b718) {
    return;
  }
  if ((int)(uVar9 << 0x10) < 0) goto LAB_0000b4aa;
  if (*param_2 != '\x01') {
    return;
  }
  uVar8 = *(uint *)(param_2 + 8);
  uVar9 = uVar8 & 0xf;
  if (uVar9 == 0) {
    *(undefined1 *)(DAT_0000b72c + 0x27) = 1;
    local_34 = DAT_0000b71c | uVar8 & 0x800f;
    local_18 = 1;
    goto LAB_0000b556;
  }
  if (uVar9 == 0xf) {
    FUN_00010c4c(0,param_2);
    local_17 = 1;
    goto LAB_0000b55c;
  }
  cVar1 = *(char *)(DAT_0000b72c + 0x27);
  if (cVar1 == '\x02') {
    if (uVar9 - 1 < 2) {
      if ((uVar8 & 0x7fff) >> 0xb == 0) {
        if (*(uint *)(DAT_0000b72c + 0x78) >> 10 == 2) {
          if (uVar9 == 1) {
            if (0xfd < *(byte *)(DAT_0000b734 + 0x5c) - 1) {
              if (*(char *)(DAT_0000b72c + 0x2a) == '\x01') {
                uVar9 = *(uint *)(DAT_0000b730 + 0x14);
                if (uVar9 >> 0x12 == 0) {
                  uVar10 = (uVar8 & 0x7ff) >> 6;
                  if (DAT_0000b720 + 1U < uVar9 + uVar10) {
                    uVar10 = (DAT_0000b720 + 1U) - uVar9;
                  }
                  (*(code *)0x43862007)(auStack_30,uVar9,uVar10);
                  goto LAB_0000b704;
                }
              }
              else if ((*(char *)(DAT_0000b72c + 0x2a) == '\0') &&
                      (uVar9 = *(uint *)(DAT_0000b730 + 0x14), uVar9 >> 0x11 == 0)) {
                uVar10 = (uVar8 & 0x7ff) >> 6;
                if (DAT_0000b724 + 1U < uVar9 + uVar10) {
                  uVar10 = (DAT_0000b724 + 1U) - uVar9;
                }
                FUN_00000170(auStack_30,uVar9,uVar10);
LAB_0000b704:
                uVar4 = FUN_0000e354(uVar8,&local_34,auStack_30,uVar10);
                goto LAB_0000b6dc;
              }
            }
            goto LAB_0000b6ce;
          }
          if (uVar9 != 2) goto LAB_0000b6ce;
          uVar9 = (uVar8 & 0x7ff) >> 6;
          iVar6 = FUN_00010c18(uVar9,param_2 + 0xc);
          if (iVar6 == 0) goto LAB_0000b6ce;
          uVar2 = *(short *)(iVar3 + 0x36) + (short)uVar9;
          *(ushort *)(iVar3 + 0x36) = uVar2;
          local_34 = (uVar8 & 0xfffff80f) + uVar9 * 0x40 + 0x10;
          uVar4 = 1;
          local_18 = 1;
          if (uVar2 < *(ushort *)(iVar3 + 0x74)) goto LAB_0000b556;
        }
        else {
LAB_0000b6ce:
          local_34 = (uVar8 & 0xfffff80f) + 0x20;
          uVar4 = 1;
        }
LAB_0000b6dc:
        *(undefined1 *)(iVar3 + 0x27) = 1;
        local_18 = uVar4;
      }
      else {
LAB_0000b516:
        local_34 = (uVar8 & 0xfffff80f) + 0x20;
        local_18 = 1;
      }
    }
    else {
      *(undefined1 *)(DAT_0000b72c + 0x27) = 1;
      local_34 = (uVar8 & 0xfffff80f) + 0x20;
      local_18 = 1;
    }
  }
  else if (cVar1 == '\x01') {
    if (uVar9 - 1 < 2) {
LAB_0000b548:
      local_18 = FUN_0000e388(param_1,param_2,&local_34);
    }
    else if (uVar9 == 3) {
      uVar9 = *(uint *)(param_2 + 0xc);
      if (((uVar9 & 0x7000000) == 0x1000000) && (local_18 = 1, (uVar9 & 0xf0000) == 0x10000)) {
        uVar5 = *(uint *)(param_2 + 0x10);
        *(uint *)(DAT_0000b72c + 0x78) = uVar5;
        *(uint *)(iVar3 + 0x74) = uVar9;
        *(undefined2 *)(iVar3 + 0x36) = 0;
        iVar6 = DAT_0000b730;
        local_34 = 0x20;
        uVar10 = DAT_0000b728;
        if (uVar5 >> 10 == 2) {
          if (*(char *)(DAT_0000b730 + 4) == '\x03') {
            if ((uVar9 & 0x800000) != 0) {
              *(undefined1 *)(iVar3 + 0x27) = 2;
              local_34 = uVar8 & 0xffffffdf | 0x10;
              local_18 = 1;
              goto LAB_0000b556;
            }
          }
          else if (((*(char *)(DAT_0000b730 + 4) == '\x01') && ((uVar9 & 0x800000) == 0)) &&
                  (0xfd < *(byte *)(DAT_0000b734 + 0x5c) - 1)) {
            uVar7 = *(undefined4 *)(param_2 + 0x14);
            *(char *)(iVar3 + 0x2a) = '\x01' - (*(int *)(param_2 + 0x18) == 0);
            *(undefined4 *)(iVar6 + 0x14) = uVar7;
            local_34 = 0x10;
            uVar10 = 0xffffffcf;
          }
        }
        local_34 = uVar8 & uVar10 | local_34;
      }
      else {
        local_18 = 1;
        local_34 = (uVar8 & 0xfffff80f) + 0x20;
      }
    }
    else if (uVar9 == 5) {
      *(undefined1 *)(DAT_0000b72c + 0x27) = 1;
      local_34 = DAT_0000b71c + 5;
      local_18 = 1;
    }
    else {
      local_34 = (uVar8 & 0xfffff80f) + 0x20;
      local_18 = 1;
    }
  }
  else if (cVar1 == '\0') {
    if (uVar9 - 1 < 2) goto LAB_0000b548;
    if (uVar9 != 5) goto LAB_0000b516;
    *(undefined1 *)(DAT_0000b72c + 0x27) = 1;
    local_34 = DAT_0000b71c + 5;
    local_18 = 1;
  }
  else {
    local_18 = 0;
  }
LAB_0000b556:
  local_17 = 0;
LAB_0000b55c:
  (*param_3)(param_1);
  return;
}

