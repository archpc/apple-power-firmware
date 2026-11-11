// rea decompile_all
// name: FUN_0000b3a0
// address: 0xb3a0
// body: available
// range: 0xb3a0-0xb5ef inclusive
// non_contiguous: false
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0000b3a0(undefined4 param_1,char *param_2,code *param_3)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint local_34;
  undefined1 auStack_30 [24];
  undefined1 local_18;
  undefined1 local_17;
  
  uVar8 = *(uint *)(param_2 + 8);
  FUN_0000a824(1);
  iVar3 = DAT_0000b600;
  if (uVar8 >> 0x10 == 0xff00) {
LAB_0000b3ca:
    if ((uVar8 & 0xff) >> 6 != 0) {
      return;
    }
    FUN_0000b6a0(param_1,*(undefined4 *)(param_2 + 8),param_3);
    return;
  }
  if (uVar8 >> 0x10 != DAT_0000b5f0) {
    return;
  }
  if ((int)(uVar8 << 0x10) < 0) goto LAB_0000b3ca;
  if (*param_2 != '\x01') {
    return;
  }
  uVar9 = *(uint *)(param_2 + 8);
  uVar8 = uVar9 & 0xf;
  if (uVar8 == 0) {
    *(undefined1 *)(DAT_0000b600 + 0x1f) = 1;
    local_34 = DAT_0000b5f4 | uVar9 & 0x800f;
LAB_0000b410:
    local_18 = 1;
    goto LAB_0000b572;
  }
  if (uVar8 == 0xf) {
    FUN_00010b28(param_1,param_2);
    local_17 = 1;
    goto LAB_0000b578;
  }
  cVar1 = *(char *)(DAT_0000b600 + 0x1f);
  if (cVar1 == '\x02') {
    if (uVar8 - 1 < 2) {
      if ((uVar9 & 0x7fff) >> 0xb == 0) {
        if (*(uint *)(DAT_0000b600 + 0x78) >> 10 == 2) {
          if (uVar8 == 1) {
            if ((byte)(*(char *)(DAT_0000b60c + 0x5c) + 1U) < 2) {
              if (*(char *)(DAT_0000b600 + 0x22) == '\x01') {
                uVar8 = *(uint *)(DAT_0000b608 + 0x14);
                if (uVar8 >> 0x12 == 0) {
                  uVar6 = (uVar9 & 0x7ff) >> 6;
                  if (DAT_0000b5f8 + 1U < uVar8 + uVar6) {
                    uVar6 = (DAT_0000b5f8 + 1U) - uVar8;
                  }
                  (*(code *)&SUB_ce10e000)(auStack_30,uVar8,uVar6);
                  goto LAB_0000b5de;
                }
              }
              else if ((*(char *)(DAT_0000b600 + 0x22) == '\0') &&
                      (uVar8 = *(uint *)(DAT_0000b608 + 0x14), uVar8 >> 0x11 == 0)) {
                uVar6 = (uVar9 & 0x7ff) >> 6;
                if (DAT_0000b5fc + 1U < uVar8 + uVar6) {
                  uVar6 = (DAT_0000b5fc + 1U) - uVar8;
                }
                FUN_00000170(auStack_30,uVar8,uVar6);
LAB_0000b5de:
                uVar4 = FUN_0000e1bc(uVar9,&local_34,auStack_30,uVar6);
                goto LAB_0000b59a;
              }
            }
            goto LAB_0000b58e;
          }
          if (uVar8 != 2) goto LAB_0000b58e;
          uVar8 = (uVar9 & 0x7ff) >> 6;
          iVar5 = FUN_00010af4(uVar8,param_2 + 0xc);
          if (iVar5 == 0) goto LAB_0000b58e;
          uVar2 = *(short *)(iVar3 + 0x38) + (short)uVar8;
          *(ushort *)(iVar3 + 0x38) = uVar2;
          local_34 = (uVar9 & 0xfffff80f) + uVar8 * 0x40 + 0x10;
          local_18 = 1;
          uVar4 = 1;
          if (uVar2 < *(ushort *)(DAT_0000b604 + 4)) goto LAB_0000b572;
        }
        else {
LAB_0000b58e:
          local_34 = (uVar9 & 0xfffff80f) + 0x20;
          uVar4 = 1;
        }
LAB_0000b59a:
        local_18 = uVar4;
        *(undefined1 *)(iVar3 + 0x1f) = 1;
        goto LAB_0000b572;
      }
    }
    else {
      *(undefined1 *)(DAT_0000b600 + 0x1f) = 1;
    }
LAB_0000b568:
    local_18 = 1;
    local_34 = (uVar9 & 0xfffff80f) + 0x20;
  }
  else {
    if (cVar1 == '\x01') {
      if (1 < uVar8 - 1) {
        if (uVar8 == 5) goto LAB_0000b504;
        if (((uVar8 != 3) || (uVar8 = *(uint *)(param_2 + 0xc), (uVar8 & 0x7000000) != 0x1000000))
           || ((uVar8 & 0xf0000) != 0x10000)) goto LAB_0000b568;
        *(uint *)(DAT_0000b604 + 4) = uVar8;
        uVar6 = *(uint *)(param_2 + 0x10);
        *(undefined2 *)(iVar3 + 0x38) = 0;
        *(uint *)(iVar3 + 0x78) = uVar6;
        iVar5 = DAT_0000b608;
        if (uVar6 >> 10 != 2) goto LAB_0000b568;
        local_18 = 1;
        if (((uVar8 & 0x800000) == 0) || (*(char *)(DAT_0000b608 + 4) != '\x03')) {
          if (((uVar8 & 0x800000) != 0) ||
             ((*(char *)(DAT_0000b608 + 4) != '\x01' ||
              (1 < (byte)(*(char *)(DAT_0000b60c + 0x5c) + 1U))))) goto LAB_0000b568;
          uVar7 = *(undefined4 *)(param_2 + 0x14);
          *(char *)(iVar3 + 0x22) = '\x01' - (*(int *)(param_2 + 0x18) == 0);
          *(undefined4 *)(iVar5 + 0x14) = uVar7;
          local_34 = uVar9 & 0xffffffdf | 0x10;
        }
        else {
          *(undefined1 *)(iVar3 + 0x1f) = 2;
          local_34 = uVar9 & 0xffffffdf | 0x10;
        }
        goto LAB_0000b572;
      }
    }
    else {
      if (cVar1 != '\0') {
        local_18 = 0;
        goto LAB_0000b572;
      }
      if (uVar8 == 5) {
LAB_0000b504:
        *(undefined1 *)(DAT_0000b600 + 0x1f) = 1;
        local_34 = DAT_0000b5f4 + 5;
        goto LAB_0000b410;
      }
      if (1 < uVar8 - 1) goto LAB_0000b568;
    }
    local_18 = FUN_0000e1f0(param_1,param_2,&local_34);
  }
LAB_0000b572:
  local_17 = 0;
LAB_0000b578:
  (*param_3)(param_1);
  return;
}

