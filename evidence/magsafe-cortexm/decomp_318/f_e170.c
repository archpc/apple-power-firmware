
/* WARNING: Control flow encountered bad instruction data */

uint FUN_0000e170(code *param_1,code *param_2,undefined **param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  undefined **ppuVar6;
  uint extraout_r2;
  uint uVar7;
  undefined **ppuVar8;
  code *pcVar9;
  undefined **ppuVar10;
  undefined **ppuVar11;
  undefined **ppuVar12;
  undefined **ppuVar13;
  uint uVar14;
  undefined4 in_cr2;
  uint uStack_54;
  undefined4 uStack_50;
  int iStack_40;
  code *pcStack_38;
  code *local_34;
  undefined2 local_30;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined **local_2c;
  code *local_28;
  undefined2 *local_24;
  
  ppuVar11 = *(undefined ***)(param_2 + 8);
  ppuVar13 = (undefined **)((int)&HardFault + 3);
  puVar5 = (undefined4 *)((uint)ppuVar11 & 0xf);
  local_34 = (code *)(((uint)ppuVar11 & 0x7ff) >> 6);
  uVar14 = *(uint *)(param_2 + 0xc);
  uVar7 = (uVar14 & 0x7ffffff) >> 0x18;
  if ((puVar5 == (undefined4 *)0x1) && (uVar7 == 0)) {
    local_24 = &local_30;
    local_2d = SUB41(param_1,0);
    local_30 = (undefined2)uVar14;
    if ((code *)0x17 < local_34) {
      local_34 = (code *)0x18;
    }
    local_2e = SUB41(local_34,0);
    local_2c = param_3 + 1;
    local_28 = DAT_0000e2a0;
    software_interrupt(3);
    uVar7 = FUN_0000e13c(ppuVar11,param_3,local_2c,&local_28);
    return uVar7;
  }
  if (uVar7 != 1) {
    *param_3 = (undefined *)(((uint)ppuVar11 & 0xfffff80f) + 0x20);
    return 1;
  }
  pcStack_38 = local_34;
  if ((code *)0x17 < local_34) {
    pcStack_38 = (code *)0x18;
  }
  ppuVar8 = (undefined **)((uVar14 & 0xffff) >> 10);
  if ((undefined **)0x28 < ppuVar8) {
LAB_0000e852:
    param_1 = FUN_000007f0;
switchD_0000e1fa_caseD_27:
    *param_3 = (undefined *)(((uint)ppuVar11 & ~(uint)param_1) + 0x20);
    return 1;
  }
  iStack_40 = 0x3f0;
  uVar14 = uVar14 & 0x3ff;
  pcVar9 = param_2 + 0x10;
  ppuVar6 = param_3 + 1;
  ppuVar12 = (undefined **)((int)ppuVar8 * 4);
  ppuVar10 = (undefined **)ppuVar12[0x387f];
  switch(ppuVar8) {
  case (undefined **)0x0:
    do {
      iVar3 = FUN_00007e4c(ppuVar13,uVar14,3);
      uVar2 = FUN_00007e4c(ppuVar13,uVar14,2);
      iVar3 = FUN_00000880(iVar3 << 0x10,uVar2);
      param_1 = (code *)(iStack_40 * iVar3 >> 0x10);
switchD_0000e1fa_caseD_1:
      local_34 = pcVar9 + (int)local_34 + (int)param_1 + 10;
      ppuVar12 = (undefined **)((int)ppuVar12 + 1);
      while (ppuVar12 == (undefined **)0x2) {
        param_2 = pcStack_38 + 1;
LAB_0000e888:
        if (param_2 == (code *)0x2) {
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            enableIRQinterrupts((uStack_54 & 1) == 1);
          }
          param_1 = (code *)((int)local_34 >> 2);
          ppuVar10 = param_3;
          ppuVar12 = ppuVar11;
          goto switchD_0000e1fa_caseD_d;
        }
        pcStack_38 = param_2;
        ppuVar12 = (undefined **)0x0;
      }
      ppuVar13 = (undefined **)((uint)ppuVar12 & 0xff);
      uVar14 = (uint)pcStack_38 & 0xff;
    } while( true );
  case (undefined **)0x1:
    goto switchD_0000e1fa_caseD_1;
  case (undefined **)0x2:
    uVar7 = (uint)ppuVar11 & 0xfffff80f;
    if ((undefined **)param_1 != (undefined **)0x0) {
      puVar4 = (undefined *)(uVar7 | (int)pcStack_38 << 6 | 0x10);
      goto LAB_0000e95e;
    }
    goto LAB_0000e994;
  default:
    if (ppuVar8 == DAT_0000ef40) {
      *(short *)((int)puVar5 + ((uint)param_2 & 3) * 2 + 0x5e) = (short)param_1;
      FUN_00008efc();
    }
    *(undefined4 *)(DAT_0000ef58 + 0x4c) = 0;
    param_3 = ppuVar12;
    goto LAB_0000ef0c;
  case (undefined **)0x8:
    *(undefined **)((int)param_1 + 0x14) = (undefined *)((uint)ppuVar8 & (uint)puVar5);
    *(char *)(DAT_0000eb90 + 0x22) = (char)*(undefined4 *)(param_2 + 0x14);
    pcStack_38 = local_34;
    break;
  case (undefined **)0xb:
    coprocessor_store(0xe,in_cr2,param_2);
    if (ppuVar8 == (undefined **)0x0) goto LAB_0000e852;
    break;
  case (undefined **)0xc:
    ppuVar8 = (undefined **)((uint)((int)ppuVar12 * (int)param_2) >> 7);
    ppuVar13 = ppuVar8;
    if (ppuVar10 == (undefined **)0x0) {
      ppuVar13 = (undefined **)0x0;
    }
    *DAT_0000ef34 = ppuVar13;
    if (ppuVar10 != (undefined **)0x0) {
      ppuVar8 = (undefined **)param_1;
    }
    *DAT_0000ef38 = (int)ppuVar8;
    *(code **)(DAT_0000ef58 + 0x4c) = param_1;
    *(undefined1 *)(DAT_0000ef4c + 1) = 3;
LAB_0000ef0c:
    *param_3 = (undefined *)(((uint)ppuVar11 & 0xfffff80f) + (int)local_34 * 0x40 + 0x10);
    return 1;
  case (undefined **)0xd:
switchD_0000e1fa_caseD_d:
    uVar2 = FUN_0000077a(ppuVar6,0x18,DAT_0000eba0,uStack_50,param_1);
    uVar7 = FUN_0000e1b8(ppuVar12,ppuVar10,ppuVar6,uVar2);
    return uVar7;
  case (undefined **)0xe:
    goto switchD_0000e1fa_caseD_e;
  case (undefined **)0xf:
  case (undefined **)0x1b:
    *(undefined **)((int)param_1 + 0x14) = (undefined *)(uVar14 << 0x10);
    *param_3 = (undefined *)(((uint)ppuVar11 & 0xfffff80f) + (int)local_34 * 0x40 + 0x10);
    return uVar14;
  case (undefined **)0x14:
    iStack_40 = DAT_0000eb9c + 0xf1;
    local_34 = param_2;
    goto LAB_0000e888;
  case (undefined **)0x15:
switchD_0000e1fa_caseD_15:
    goto FUN_0000e9cc;
  case (undefined **)0x16:
    local_28 = param_2 + (int)((code *)((int)puVar5 + (int)ppuVar8) +
                              (uint)(byte)*(code *)((int)param_1 + 0x5d) * 0x10000);
    ppuVar10 = &Reset;
    FUN_00000170(ppuVar6,&local_28,4);
    param_1 = (code *)ppuVar11;
    ppuVar13 = ppuVar6;
  case (undefined **)0x26:
    ppuVar6 = ppuVar13;
    ppuVar11 = (undefined **)param_1;
LAB_0000e98e:
    FUN_0000e1b8(ppuVar11,ppuVar12,ppuVar6,ppuVar10);
    uVar7 = extraout_r2;
LAB_0000e994:
    *param_3 = (undefined *)(uVar7 | 0x30);
    return 1;
  case (undefined **)0x1c:
    puVar5 = (undefined4 *)0x3f0;
    param_2 = (code *)0x30000;
  case (undefined **)0x20:
    iVar3 = (*(code *)*puVar5)(ppuVar6,(code *)((int)param_1 + (int)param_2),ppuVar10);
    if (iVar3 != 0) {
      *ppuVar12 = (undefined *)(((uint)ppuVar11 & 0xfffff80f) + 0x10);
      return 1;
    }
    goto LAB_0000e98e;
  case (undefined **)0x21:
  case (undefined **)0x22:
  case (undefined **)0x23:
  case (undefined **)0x24:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case (undefined **)0x25:
code_r0x0000ea16:
    *(char *)(DAT_0000eb90 + 0x20) = (char)param_1;
    *ppuVar8 = (undefined *)(((uint)ppuVar10 & 0xfffff80f) + (int)pcStack_38 * 0x40 + 0x10);
    return 1;
  case (undefined **)0x27:
    goto switchD_0000e1fa_caseD_27;
  case (undefined **)0x28:
    if (ppuVar8 != (undefined **)0x0) {
      if (uVar14 != 0) {
        FUN_00000170(&local_28,pcVar9,4);
        if (((uint)local_28 & 0xff) != 0) {
          if (((uint)local_28 & 0xff) != 1) {
            *param_3 = (undefined *)(((uint)ppuVar11 & 0xfffff80f) + 0x20);
            return 1;
          }
          uVar7 = switchD_0000e1fa::caseD_25(1);
          return uVar7;
        }
        param_1 = (code *)0x0;
        ppuVar8 = param_3;
        ppuVar10 = ppuVar11;
        goto code_r0x0000ea16;
      }
      FUN_00000170(&local_28,pcVar9,4);
      *(short *)(DAT_0000eb90 + 0x36) = (short)local_28;
      goto switchD_0000e1fa_caseD_15;
    }
    param_2 = (code *)(uint)(byte)((char)*(code *)(DAT_0000ebac + 0x17) + 1);
    param_1 = (code *)DAT_0000ebac;
  case (undefined **)0xa:
    if (param_2 < (code *)0x2) {
      *(code *)((int)param_1 + 0x67) = *pcVar9;
      FUN_00008efc();
    }
FUN_0000e9cc:
    param_1 = FUN_000007f0;
    goto switchD_0000e1fa_caseD_e;
  }
  puVar4 = (undefined *)(((uint)ppuVar11 & 0xfffff80f) + (int)pcStack_38 * 0x40 + 0x10);
LAB_0000e95e:
  *param_3 = puVar4;
  return 1;
switchD_0000e1fa_caseD_e:
  puVar4 = (undefined *)(((uint)ppuVar11 & ~(uint)param_1) + 0x110);
  goto LAB_0000e95e;
}

