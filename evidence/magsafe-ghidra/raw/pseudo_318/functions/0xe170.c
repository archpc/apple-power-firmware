// rea decompile_all
// name: FUN_0000e170
// address: 0xe170
// body: available
// range: 0xe170-0xe1b7 inclusive
// range: 0xe880-0xe8f9 inclusive
// range: 0xe91c-0xe91d inclusive
// range: 0xe942-0xe963 inclusive
// range: 0xe966-0xe99d inclusive
// range: 0xe9b2-0xe9db inclusive
// range: 0xe9f2-0xea39 inclusive
// range: 0xeab6-0xeab9 inclusive
// range: 0xecd2-0xece9 inclusive
// range: 0xee72-0xee97 inclusive
// range: 0xeeaa-0xeeaf inclusive
// range: 0xeefc-0xeeff inclusive
// range: 0xef0a-0xef1f inclusive
// non_contiguous: true
// provider: Ghidra 12.1.4 (ghidra)
// analysis_profile: 6570f971e35b8d40eb0ed89a5712f1e2cb5de25054ce899597c6de62ab2858ac
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0xe8f8 to 0xe1b8 FUN_0000e1b8 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; macOS sessions require a matching executable Ghidra native decompiler; REA checks for it but does not build native components or change Gatekeeper quarantine state.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Type propagation algorithm not settling */

uint FUN_0000e170(code *param_1,code *param_2,code *param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  code *pcVar5;
  uint extraout_r2;
  uint uVar6;
  code *pcVar7;
  code *pcVar8;
  code *pcVar9;
  code *pcVar10;
  code *pcVar11;
  code *pcVar12;
  uint uVar13;
  undefined4 in_cr2;
  uint uStack_54;
  undefined4 uStack_50;
  int iStack_40;
  code *pcStack_38;
  code *local_34;
  undefined2 local_30;
  undefined1 local_2e;
  undefined1 local_2d;
  code *local_2c;
  code *local_28;
  undefined2 *local_24;
  
  pcVar10 = *(code **)(param_2 + 8);
  pcVar12 = (code *)0xf;
  puVar4 = (undefined4 *)((uint)pcVar10 & 0xf);
  local_34 = (code *)(((uint)pcVar10 & 0x7ff) >> 6);
  uVar13 = *(uint *)(param_2 + 0xc);
  uVar6 = (uVar13 & 0x7ffffff) >> 0x18;
  if ((puVar4 == (undefined4 *)0x1) && (uVar6 == 0)) {
    local_24 = &local_30;
    local_2d = SUB41(param_1,0);
    local_30 = (undefined2)uVar13;
    if ((code *)0x17 < local_34) {
      local_34 = IRQ;
    }
    local_2e = SUB41(local_34,0);
    local_2c = param_3 + 4;
    local_28 = DAT_0000e2a0;
    software_interrupt(3);
    uVar6 = FUN_0000e13c(pcVar10,param_3,local_2c,&local_28);
    return uVar6;
  }
  if (uVar6 != 1) {
    *(uint *)param_3 = ((uint)pcVar10 & 0xfffff80f) + 0x20;
    return 1;
  }
  pcStack_38 = local_34;
  if ((code *)0x17 < local_34) {
    pcStack_38 = IRQ;
  }
  pcVar7 = (code *)((uVar13 & 0xffff) >> 10);
  if ((code *)0x28 < pcVar7) {
LAB_0000e852:
    param_1 = FUN_000007f0;
switchD_0000e1fa_caseD_27:
    *(uint *)param_3 = ((uint)pcVar10 & ~(uint)param_1) + 0x20;
    return 1;
  }
  iStack_40 = 0x3f0;
  uVar13 = uVar13 & 0x3ff;
  pcVar8 = param_2 + 0x10;
  pcVar5 = param_3 + 4;
  pcVar11 = (code *)((int)pcVar7 * 4);
  pcVar9 = *(code **)(pcVar11 + 0xe1fc);
  switch(pcVar7) {
  case entry:
    do {
      iVar3 = FUN_00007e4c(pcVar12,uVar13,3);
      uVar2 = FUN_00007e4c(pcVar12,uVar13,2);
      iVar3 = FUN_00000880(iVar3 << 0x10,uVar2);
      param_1 = (code *)(iStack_40 * iVar3 >> 0x10);
switchD_0000e1fa_caseD_1:
      local_34 = pcVar8 + (int)local_34 + (int)param_1 + 10;
      pcVar11 = pcVar11 + 1;
      while (pcVar11 == (code *)0x2) {
        param_2 = pcStack_38 + 1;
LAB_0000e888:
        if (param_2 == (code *)0x2) {
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            enableIRQinterrupts((uStack_54 & 1) == 1);
          }
          param_1 = (code *)((int)local_34 >> 2);
          pcVar9 = param_3;
          pcVar11 = pcVar10;
          goto switchD_0000e1fa_caseD_d;
        }
        pcStack_38 = param_2;
        pcVar11 = entry;
      }
      pcVar12 = (code *)((uint)pcVar11 & 0xff);
      uVar13 = (uint)pcStack_38 & 0xff;
    } while( true );
  case (code *)0x1:
    goto switchD_0000e1fa_caseD_1;
  case (code *)0x2:
    uVar6 = (uint)pcVar10 & 0xfffff80f;
    if (param_1 != entry) {
      uVar6 = uVar6 | (int)pcStack_38 << 6 | 0x10;
      goto LAB_0000e95e;
    }
    goto LAB_0000e994;
  default:
    if (pcVar7 == DAT_0000ef40) {
      *(short *)((int)puVar4 + ((uint)param_2 & 3) * 2 + 0x5e) = (short)param_1;
      FUN_00008efc();
    }
    *(undefined4 *)(DAT_0000ef58 + 0x4c) = 0;
    param_3 = pcVar11;
    goto LAB_0000ef0c;
  case (code *)0x8:
    *(uint *)(param_1 + 0x14) = (uint)pcVar7 & (uint)puVar4;
    *(char *)(DAT_0000eb90 + 0x22) = (char)*(undefined4 *)(param_2 + 0x14);
    pcStack_38 = local_34;
    break;
  case (code *)0xb:
    coprocessor_store(0xe,in_cr2,param_2);
    if (pcVar7 == entry) goto LAB_0000e852;
    break;
  case (code *)0xc:
    pcVar7 = (code *)((uint)((int)pcVar11 * (int)param_2) >> 7);
    pcVar12 = pcVar7;
    if (pcVar9 == entry) {
      pcVar12 = entry;
    }
    *DAT_0000ef34 = pcVar12;
    if (pcVar9 != entry) {
      pcVar7 = param_1;
    }
    *DAT_0000ef38 = pcVar7;
    *(code **)(DAT_0000ef58 + 0x4c) = param_1;
    *(undefined1 *)(DAT_0000ef4c + 1) = 3;
LAB_0000ef0c:
    *(uint *)param_3 = ((uint)pcVar10 & 0xfffff80f) + (int)local_34 * 0x40 + 0x10;
    return 1;
  case (code *)0xd:
switchD_0000e1fa_caseD_d:
    uVar2 = FUN_0000077a(pcVar5,0x18,DAT_0000eba0,uStack_50,param_1);
    uVar6 = FUN_0000e1b8(pcVar11,pcVar9,pcVar5,uVar2);
    return uVar6;
  case (code *)0xe:
    goto switchD_0000e1fa_caseD_e;
  case (code *)0xf:
  case IRQ:
    *(uint *)(param_1 + 0x14) = uVar13 << 0x10;
    *(uint *)param_3 = ((uint)pcVar10 & 0xfffff80f) + (int)local_34 * 0x40 + 0x10;
    return uVar13;
  case NotUsed:
    iStack_40 = DAT_0000eb9c + 0xf1;
    local_34 = param_2;
    goto LAB_0000e888;
  case (code *)0x15:
switchD_0000e1fa_caseD_15:
    goto LAB_0000e9cc;
  case (code *)0x16:
    local_28 = param_2 + (int)((code *)((int)puVar4 + (int)pcVar7) +
                              (uint)(byte)param_1[0x5d] * 0x10000);
    pcVar9 = (code *)0x4;
    FUN_00000170(pcVar5,&local_28,4);
    param_1 = pcVar10;
    pcVar12 = pcVar5;
  case (code *)0x26:
    pcVar5 = pcVar12;
    pcVar10 = param_1;
LAB_0000e98e:
    FUN_0000e1b8(pcVar10,pcVar11,pcVar5,pcVar9);
    uVar6 = extraout_r2;
LAB_0000e994:
    *(uint *)param_3 = uVar6 | 0x30;
    return 1;
  case (code *)0x1c:
    puVar4 = (undefined4 *)0x3f0;
    param_2 = (code *)0x30000;
  case (code *)0x20:
    iVar3 = (*(code *)*puVar4)(pcVar5,param_1 + (int)param_2,pcVar9);
    if (iVar3 != 0) {
      *(uint *)pcVar11 = ((uint)pcVar10 & 0xfffff80f) + 0x10;
      return 1;
    }
    goto LAB_0000e98e;
  case (code *)0x21:
  case (code *)0x22:
  case (code *)0x23:
  case (code *)0x24:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case (code *)0x25:
switchD_0000e1fa_caseD_25:
    *(char *)(DAT_0000eb90 + 0x20) = (char)param_1;
    *(uint *)pcVar7 = ((uint)pcVar9 & 0xfffff80f) + (int)pcStack_38 * 0x40 + 0x10;
    return 1;
  case (code *)0x27:
    goto switchD_0000e1fa_caseD_27;
  case (code *)0x28:
    if (pcVar7 != entry) {
      if (uVar13 != 0) {
        FUN_00000170(&local_28,pcVar8,4);
        pcVar7 = param_3;
        pcVar9 = pcVar10;
        if (((uint)local_28 & 0xff) == 0) {
          param_1 = entry;
        }
        else {
          if (((uint)local_28 & 0xff) != 1) {
            *(uint *)param_3 = ((uint)pcVar10 & 0xfffff80f) + 0x20;
            return 1;
          }
          param_1 = (code *)0x1;
        }
        goto switchD_0000e1fa_caseD_25;
      }
      FUN_00000170(&local_28,pcVar8,4);
      *(short *)(DAT_0000eb90 + 0x36) = (short)local_28;
      goto switchD_0000e1fa_caseD_15;
    }
    param_2 = (code *)(uint)(byte)((char)DAT_0000ebac[0x5c] + 1);
    param_1 = DAT_0000ebac;
  case (code *)0xa:
    if (param_2 < (code *)0x2) {
      param_1[0x67] = *pcVar8;
      FUN_00008efc();
    }
LAB_0000e9cc:
    param_1 = FUN_000007f0;
    goto switchD_0000e1fa_caseD_e;
  }
  uVar6 = ((uint)pcVar10 & 0xfffff80f) + (int)pcStack_38 * 0x40 + 0x10;
LAB_0000e95e:
  *(uint *)param_3 = uVar6;
  return 1;
switchD_0000e1fa_caseD_e:
  uVar6 = ((uint)pcVar10 & ~(uint)param_1) + 0x110;
  goto LAB_0000e95e;
}

