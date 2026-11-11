// rea decompile_all
// name: FUN_00002204
// address: 0x2204
// body: available
// range: 0x2204-0x25ed inclusive
// range: 0x25f8-0x26c5 inclusive
// range: 0x27f8-0x282f inclusive
// range: 0x2836-0x2839 inclusive
// range: 0x2892-0x28ef inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Control flow encountered bad instruction data */

void FUN_00002204(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  short sVar4;
  ushort uVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  byte *pbVar13;
  int *piVar14;
  undefined1 *puVar15;
  uint uVar16;
  undefined1 *puVar17;
  uint extraout_r2;
  code *pcVar18;
  uint *extraout_r3;
  uint *puVar19;
  undefined4 *puVar20;
  uint uVar21;
  uint uVar22;
  char cVar23;
  bool bVar24;
  undefined8 in_d19;
  undefined8 in_d28;
  undefined1 *local_6c;
  undefined1 *local_68;
  byte *local_64;
  uint local_60;
  byte *local_5c;
  uint local_58;
  ushort local_40 [8];
  int local_30;
  
  iVar11 = DAT_000025f4;
  uVar21 = DAT_000025f0 + param_1 * 0x1cc;
  if (*(char *)(uVar21 + 0x31) == '\0') {
    if (*(char *)(uVar21 + 0x33) != '\x01') {
      return;
    }
    *(undefined1 *)(uVar21 + 0x33) = 0;
    FUN_00007c18(param_1);
    FUN_00002f50(param_1);
    return;
  }
  bVar2 = *(byte *)(uVar21 + 0x2d);
  uVar16 = (uint)*(byte *)(uVar21 + 0x19);
  pbVar13 = (byte *)(uVar21 + 0x2d);
  piVar14 = (int *)(uVar21 + 0x60);
  if (*(char *)(uVar21 + 0x25) == '\0') {
    bVar1 = *(byte *)(uVar21 + 0x1a);
    local_5c = *(byte **)(uVar21 + 0x60);
    local_64 = (byte *)FUN_00008778(param_1);
    *(short *)(uVar21 + 0x36) = (short)local_64;
    uVar22 = (uint)local_64 & 0xffff;
    bVar24 = 1 < bVar2 - 3;
    if (bVar24) {
      FUN_00007c64(param_1,uVar22,0x11);
      FUN_00007c64(param_1,uVar22,0x12);
    }
    local_60 = (uint)!bVar24;
    iVar8 = FUN_00007d6c(param_1,uVar22);
    uVar3 = *(ushort *)(uVar21 + 0x38);
    puVar15 = (undefined1 *)(uint)uVar3;
    local_40[0] = uVar3;
    cVar7 = *(char *)((int)local_40 + (uint)bVar1);
    puVar17 = (undefined1 *)(uVar21 + 0x1c);
    local_58 = uVar16;
    if (*(char *)(uVar21 + 0x1c) == '\0') {
      if (uVar16 == 0) {
        if (local_60 == 0) {
          local_6c = puVar15;
          if (*(char *)(uVar21 + 0x15) == '\0') {
            if (((uint)local_64 & 0xffff) == 0) {
              iVar9 = iVar11 + param_1 * 0xb;
              if (*(char *)(iVar9 + 1) == '\0') {
                *(undefined1 *)(iVar9 + 1) = 1;
                FUN_0000c880(param_1,0x13,0xc);
              }
              else {
                iVar9 = FUN_0000c8d4(param_1,0x13);
                if (iVar9 == 0) {
                  *(undefined2 *)(uVar21 + 0x3c) = 0;
                }
              }
            }
            else {
              *(short *)(uVar21 + 0x3c) = (short)local_64;
              FUN_0000c88c(param_1,0x13);
              *(undefined1 *)(iVar11 + param_1 * 0xb + 1) = 0;
            }
            sVar4 = *(short *)(uVar21 + 0x3c);
            iVar9 = FUN_00007854(param_1);
            if ((iVar8 != 0) && (iVar9 != 0)) {
              uVar5 = uVar3 >> 8;
              if ((2 < (((uint)local_64 & 0xff) - 1 & 0xffff)) || (uVar5 != 0)) {
                if ((((0x3ff < uVar22) || (uVar22 >> 8 == 0)) || ((uVar3 & 0xff) != 0)) &&
                   (((3 < uVar5 || (2 < ((uint)puVar15 & 0xff) - 1)) || (uVar5 == 0))))
                goto LAB_000025ac;
              }
              *(char *)(uVar21 + 0x39) = (char)(uVar22 >> 8);
              *(char *)(uVar21 + 0x38) = (char)local_64;
              *puVar17 = 1;
              uVar10 = 8;
              local_68 = puVar17;
              goto LAB_00002524;
            }
LAB_000025ac:
            local_68 = puVar17;
            if (sVar4 == 0) {
              FUN_00007a24(param_1);
              goto LAB_000025ba;
            }
          }
          else {
            iVar9 = FUN_00007d6c(param_1);
            if (iVar9 == 1) {
              FUN_0000c88c(param_1,0x15);
              local_68 = puVar17;
              if (puVar15 == (undefined1 *)(uint)*(ushort *)(uVar21 + 0x3a)) {
                iVar8 = (**(code **)(local_5c + 0x20))(param_1,800,0);
                if (iVar8 == 0) {
                  *(undefined1 *)(iVar11 + param_1 * 0xb + 7) = 0;
                  (**(code **)(local_5c + 0x28))(param_1);
                  FUN_0000c88c(param_1,0x14);
                  *puVar17 = 1;
                  if (*(char *)(uVar21 + 0x44) == '\0') {
                    uVar10 = 8;
                    goto LAB_00002524;
                  }
                  *pbVar13 = 8;
                }
                else {
                  iVar8 = iVar11 + param_1 * 0xb;
                  if (*(char *)(iVar8 + 3) == '\0') {
                    if (*(char *)(iVar8 + 7) == '\0') {
                      *(undefined1 *)(iVar8 + 7) = 1;
                      (**(code **)(local_5c + 0x24))(param_1);
                      FUN_0000c880(param_1,0x14,0x32);
                    }
                    else {
                      iVar9 = FUN_0000c8d4(param_1,0x14);
                      if (iVar9 == 0) {
                        *(undefined1 *)(iVar8 + 7) = 0;
                        (**(code **)(local_5c + 0x28))(param_1);
                        (**(code **)*piVar14)(param_1,0,0);
                        *(undefined1 *)(iVar8 + 3) = 1;
                      }
                    }
                  }
                }
              }
            }
            else {
              local_68 = puVar17;
              if ((iVar8 == 0) &&
                 ((iVar8 = FUN_0000c8d4(param_1,0x15), uVar22 == 0x202 || (iVar8 == 0)))) {
LAB_000025ba:
                FUN_00007dd4(param_1);
                pcVar18 = *(code **)*piVar14;
                uVar10 = 0x22;
                goto LAB_000023e4;
              }
            }
          }
        }
        else if (iVar8 != 0) {
          if (bVar2 == 3) {
            FUN_00007c4c(param_1,0);
            FUN_00007c4c(param_1,1);
            FUN_0000c880(param_1,0x15,10);
          }
          FUN_000077cc(param_1,2);
          *(undefined1 *)(uVar21 + 0x19) = 0;
          FUN_00007a24(param_1);
        }
      }
    }
    else if (*(char *)(uVar21 + 0x15) == '\0') {
      if (*(char *)(uVar21 + 0x42) == '\0') {
        if (uVar16 == 0) {
          cVar6 = FUN_00002c80(param_1);
          if (cVar7 == '\0') {
            *(undefined1 *)(iVar11 + param_1 * 0xb + (uint)*(byte *)(uVar21 + 0x1a) + 8) = 0;
            (**(code **)*piVar14)(param_1,0x37);
            cVar6 = -5;
          }
          cVar23 = '\x05';
          local_58 = (uint)cVar6;
          do {
            if (cVar23 == '\0') {
              *puVar17 = 0;
              goto LAB_00002520;
            }
            pcVar18 = *(code **)(local_5c + 0x20);
            uVar10 = FUN_00002c9c(param_1);
            iVar8 = (*pcVar18)(param_1,uVar10,local_58);
            cVar23 = cVar23 + -1;
          } while (iVar8 == 0);
        }
      }
      else if (cVar7 == '\0') {
        *puVar17 = 0;
        *(undefined1 *)(uVar21 + 0x42) = 0;
LAB_00002520:
        uVar10 = 4;
        local_68 = puVar17;
        goto LAB_00002524;
      }
      local_68 = puVar17;
      if (*(char *)(uVar21 + 0x16) != cVar7) {
        *(char *)(uVar21 + 0x16) = cVar7;
        FUN_00008c14(param_1);
        pcVar18 = *(code **)*piVar14;
        uVar10 = 9;
LAB_000023e4:
        (*pcVar18)(param_1,uVar10,0);
        local_68 = puVar17;
      }
    }
    else if ((uVar16 == 0) &&
            ((cVar7 == '\x02' ||
             ((*(char *)(uVar21 + 0x1f) == '\x04' &&
              ((cVar7 != '\0' || (*(char *)((int)local_40 + (uint)(bVar1 == 0)) != '\0')))))))) {
      FUN_0000c88c(param_1,0xf);
      *puVar17 = 0;
      uVar10 = 4;
LAB_00002524:
      FUN_00002a48(param_1,uVar10);
    }
  }
  uVar16 = FUN_00008dbc(uVar21 + 0x4c);
  if (uVar16 < 8) {
    if (uVar16 == 0) {
      FUN_000077cc(param_1,1);
    }
    else if (uVar16 == 7) {
      uVar10 = FUN_00000b50();
      uVar16 = (uint)*(byte *)(uVar21 + 0x34);
      if (uVar16 < 3) {
        bVar2 = *(byte *)(DAT_000028f0 + uVar16);
        *(byte *)(uVar21 + 2) = bVar2;
        if ((*pbVar13 != 3) && (*(char *)(uVar21 + 0x20) == '\0')) {
          if ((*(char *)(uVar21 + 0x1d) != '\0') && (*(char *)(uVar21 + 0x15) == '\x01')) {
            if (bVar2 < *(byte *)(uVar21 + 0x35)) {
              FUN_0000c78c(param_1,0x16,0,DAT_000028f4);
            }
            else {
              (**(code **)(*piVar14 + 8))(param_1,300);
            }
          }
          FUN_000078bc(param_1,*(undefined1 *)(uVar21 + 2));
        }
        FUN_00007af8(param_1,1);
        uVar16 = (uint)*(byte *)(uVar21 + 0x34);
      }
      if (uVar16 - 3 < 2) {
        if (uVar16 == 3) {
          *(undefined1 *)(iVar11 + param_1 * 0xb + 4) = 1;
        }
        FUN_00002a48(param_1,1);
      }
      FUN_00000b58(uVar10);
    }
    else {
      (**(code **)(DAT_000028f8 + (uint)*pbVar13 * 4))(param_1);
    }
  }
  if (*(char *)(uVar21 + 0x45) == '\0') {
    return;
  }
  if (*(int *)(uVar21 + 0x48) == 0) goto LAB_00002808;
  piVar14 = (int *)(uVar21 + 0x48);
  uVar16 = 0x175;
  if (*(char *)(uVar21 + 0x175) != '\0') {
    cVar7 = *(char *)(uVar21 + 0x15);
    if (cVar7 == '\x01') {
      if (-1 < *piVar14 << 0x1c) goto LAB_00002698;
      FUN_00003038(param_1,0xd,900);
      cVar7 = *(char *)(uVar21 + 0x15);
    }
    if ((cVar7 == '\0') && ((*piVar14 << 0x1c < 0 || (*piVar14 << 0x19 < 0)))) {
      FUN_00003048(param_1);
    }
  }
LAB_00002698:
  if ((*piVar14 << 0x16 < 0) && (*(char *)(uVar21 + 0x2e) == '\x05')) {
    FUN_00003088(param_1);
  }
  pbVar13 = (byte *)FUN_00008dbc(piVar14);
  puVar19 = extraout_r3;
  switch(pbVar13) {
  case (byte *)0x0:
    return;
  case (byte *)0x1:
  case (byte *)0x6:
    do {
      uVar22 = uVar16 >> 0x1e;
      if ((uVar22 < 3) || (1 < *local_5c)) {
        if (uVar22 == 2) {
          if ((uVar16 & 0x26df) <= extraout_r2) goto LAB_00002bf2;
          uVar22 = uVar16 & DAT_00002c68 | extraout_r2;
LAB_00002bd0:
          local_68 = local_6c;
        }
        else {
          if (uVar22 == 1) {
            uVar22 = (uVar16 >> 10 & 0x26df) * 0x26c8;
            if (uVar22 < (uVar16 & 0x26df)) {
              uVar22 = uVar22 & 0x26d8 | uVar16 & DAT_00002c68;
              goto LAB_00002bd0;
            }
          }
          else if (uVar22 == 0) {
            if (extraout_r2 < (uVar16 & 0x26df)) {
              uVar22 = (uVar16 & DAT_00002c70) + extraout_r2;
              goto LAB_00002bd0;
            }
            uVar12 = (uVar16 & 0x26df) * 0x6e;
            uVar22 = uVar16;
            if (DAT_00002c6c <= uVar12 && uVar12 - DAT_00002c6c != 0) {
              uVar22 = uVar16 & 0xffcfffff;
            }
            if ((uVar16 & 0x3fffff) >> 0x14 != 0) goto LAB_00002bf4;
          }
LAB_00002bf2:
          uVar22 = uVar16;
        }
LAB_00002bf4:
        *(uint *)(local_60 + local_58 * 4 + 0x9c) = uVar22;
        local_58 = local_58 + 1;
        pbVar13 = local_64;
      }
      do {
        puVar19 = puVar19 + 1;
        uVar21 = uVar21 + 1;
        if (uVar21 == 7) {
          if (local_58 < 7) {
            puVar20 = (undefined4 *)(local_60 + local_58 * 4 + 0x9c);
            for (iVar11 = local_58 - 7; iVar11 != 0; iVar11 = iVar11 + 1) {
              *puVar20 = 0;
              puVar20 = puVar20 + 1;
            }
          }
          *(byte *)(local_60 + 0x15b) = (byte)local_68 & 1;
          *(char *)(local_60 + 0x29) = (char)local_58;
          uVar21 = DAT_00002c74;
          if (1 < *local_5c) {
            uVar21 = switchD_000026c4::caseD_2;
          }
          *(uint *)(local_60 + 0x9c) =
               (uint)(*local_64 >> 7) * 0x8000000 + (*(uint *)(local_60 + 0x9c) & 0xf6bfffff) &
               uVar21;
          return;
        }
      } while ((*pbVar13 >> (uVar21 & 0xff) & 1) == 0);
      uVar16 = *puVar19;
    } while( true );
  case (byte *)0x2:
  case (byte *)0x3:
  case (byte *)0x4:
  case (byte *)0x5:
  case (byte *)0x7:
  case (byte *)0x8:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case (byte *)0x9:
    VectorRoundShiftRightAccumulate(in_d28,in_d19,1);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  default:
    (**(code **)(DAT_00002904 + (uint)*(byte *)(uVar21 + 0x45) * 4))(param_1,pbVar13);
  }
LAB_00002808:
  if (((1 < *(byte *)(uVar21 + 0x3e)) && (local_30 = *(int *)(uVar21 + 0x58), local_30 != 0)) &&
     (iVar11 = FUN_0000295c(param_1,0x11,local_40,0), iVar11 == 0)) {
    *(undefined4 *)(uVar21 + 0x58) = 0;
  }
  return;
}

