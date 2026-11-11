
/* WARNING: Control flow encountered bad instruction data */

uint FUN_0000e170(code *param_1,undefined **param_2,undefined **param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined **ppuVar5;
  uint extraout_r2;
  uint uVar6;
  undefined **ppuVar7;
  undefined **ppuVar8;
  undefined **ppuVar9;
  undefined **ppuVar10;
  undefined **ppuVar11;
  undefined **ppuVar12;
  undefined *puVar13;
  undefined4 in_cr2;
  uint uStack_54;
  undefined4 uStack_50;
  int iStack_40;
  undefined **ppuStack_38;
  undefined **local_34;
  undefined2 local_30;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined **local_2c;
  code *local_28;
  undefined2 *local_24;
  
  ppuVar10 = (undefined **)param_2[2];
  ppuVar12 = (undefined **)((int)&HardFault + 3);
  puVar4 = (undefined4 *)((uint)ppuVar10 & 0xf);
  local_34 = (undefined **)(((uint)ppuVar10 & 0x7ff) >> 6);
  puVar13 = param_2[3];
  uVar6 = ((uint)puVar13 & 0x7ffffff) >> 0x18;
  if ((puVar4 == (undefined4 *)0x1) && (uVar6 == 0)) {
    local_24 = &local_30;
    local_2d = SUB41(param_1,0);
    local_30 = SUB42(puVar13,0);
    if ((undefined **)0x17 < local_34) {
      local_34 = &UsageFault;
    }
    local_2e = SUB41(local_34,0);
    local_2c = param_3 + 1;
    local_28 = DAT_0000e2a0;
    software_interrupt(3);
    uVar6 = FUN_0000e13c(ppuVar10,param_3,local_2c,&local_28);
    return uVar6;
  }
  if (uVar6 != 1) {
    *param_3 = (undefined *)(((uint)ppuVar10 & 0xfffff80f) + 0x20);
    return 1;
  }
  ppuStack_38 = local_34;
  if ((undefined **)0x17 < local_34) {
    ppuStack_38 = &UsageFault;
  }
  ppuVar7 = (undefined **)(((uint)puVar13 & 0xffff) >> 10);
  if (&Reserved4 < ppuVar7) {
LAB_0000e852:
    param_1 = FUN_000007f0;
switchD_0000e1fa_caseD_27:
    *param_3 = (undefined *)(((uint)ppuVar10 & ~(uint)param_1) + 0x20);
    return 1;
  }
  iStack_40 = 0x3f0;
  uVar6 = (uint)puVar13 & 0x3ff;
  ppuVar8 = param_2 + 4;
  ppuVar5 = param_3 + 1;
  ppuVar11 = (undefined **)((int)ppuVar7 * 4);
  ppuVar9 = (undefined **)ppuVar11[0x387f];
  switch(ppuVar7) {
  case (undefined **)0x0:
    do {
      iVar3 = FUN_00007e4c(ppuVar12,uVar6,3);
      uVar2 = FUN_00007e4c(ppuVar12,uVar6,2);
      iVar3 = FUN_00000880(iVar3 << 0x10,uVar2);
      param_1 = (code *)(iStack_40 * iVar3 >> 0x10);
switchD_0000e1fa_caseD_1:
      local_34 = (undefined **)((undefined1 *)((int)ppuVar8 + (int)local_34) + (int)param_1 + 10);
      ppuVar11 = (undefined **)((int)ppuVar11 + 1);
      while (ppuVar11 == (undefined **)0x2) {
        param_2 = (undefined **)((int)ppuStack_38 + 1);
LAB_0000e888:
        if (param_2 == (undefined **)0x2) {
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            enableIRQinterrupts((uStack_54 & 1) == 1);
          }
          param_1 = (code *)((int)local_34 >> 2);
          ppuVar9 = param_3;
          ppuVar11 = ppuVar10;
          goto switchD_0000e1fa_caseD_d;
        }
        ppuStack_38 = param_2;
        ppuVar11 = (undefined **)0x0;
      }
      ppuVar12 = (undefined **)((uint)ppuVar11 & 0xff);
      uVar6 = (uint)ppuStack_38 & 0xff;
    } while( true );
  case (undefined **)0x1:
    goto switchD_0000e1fa_caseD_1;
  case (undefined **)0x2:
    uVar6 = (uint)ppuVar10 & 0xfffff80f;
    if ((undefined **)param_1 != (undefined **)0x0) {
      puVar13 = (undefined *)(uVar6 | (int)ppuStack_38 << 6 | 0x10);
      goto LAB_0000e95e;
    }
    goto LAB_0000e994;
  default:
    if (ppuVar7 == DAT_0000ef40) {
      *(short *)((int)puVar4 + ((uint)param_2 & 3) * 2 + 0x5e) = (short)param_1;
      FUN_00008efc();
    }
    *(undefined4 *)(DAT_0000ef58 + 0x4c) = 0;
    param_3 = ppuVar11;
    goto LAB_0000ef0c;
  case (undefined **)0x8:
    *(undefined **)((int)param_1 + 0x14) = (undefined *)((uint)ppuVar7 & (uint)puVar4);
    *(char *)(DAT_0000eb90 + 0x22) = (char)param_2[5];
    ppuStack_38 = local_34;
    break;
  case (undefined **)0xb:
    coprocessor_store(0xe,in_cr2,param_2);
    if (ppuVar7 == (undefined **)0x0) goto LAB_0000e852;
    break;
  case (undefined **)0xc:
    ppuVar7 = (undefined **)((uint)((int)ppuVar11 * (int)param_2) >> 7);
    ppuVar12 = ppuVar7;
    if (ppuVar9 == (undefined **)0x0) {
      ppuVar12 = (undefined **)0x0;
    }
    *DAT_0000ef34 = ppuVar12;
    if (ppuVar9 != (undefined **)0x0) {
      ppuVar7 = (undefined **)param_1;
    }
    *DAT_0000ef38 = ppuVar7;
    *(code **)(DAT_0000ef58 + 0x4c) = param_1;
    *(undefined1 *)(DAT_0000ef4c + 1) = 3;
LAB_0000ef0c:
    *param_3 = (undefined *)(((uint)ppuVar10 & 0xfffff80f) + (int)local_34 * 0x40 + 0x10);
    return 1;
  case (undefined **)0xd:
switchD_0000e1fa_caseD_d:
    uVar2 = FUN_0000077a(ppuVar5,0x18,DAT_0000eba0,uStack_50,param_1);
    uVar6 = FUN_0000e1b8(ppuVar11,ppuVar9,ppuVar5,uVar2);
    return uVar6;
  case (undefined **)0xe:
    goto switchD_0000e1fa_caseD_e;
  case (undefined **)0xf:
  case (undefined **)0x1b:
    *(undefined **)((int)param_1 + 0x14) = (undefined *)(uVar6 << 0x10);
    *param_3 = (undefined *)(((uint)ppuVar10 & 0xfffff80f) + (int)local_34 * 0x40 + 0x10);
    return uVar6;
  case (undefined **)0x14:
    iStack_40 = DAT_0000eb9c + 0xf1;
    local_34 = param_2;
    goto LAB_0000e888;
  case (undefined **)0x15:
switchD_0000e1fa_caseD_15:
    goto FUN_0000e9cc;
  case (undefined **)0x16:
    local_28 = (code *)((int)param_2 +
                       (uint)*(byte *)((int)param_1 + 0x5d) * 0x10000 + (int)puVar4 + (int)ppuVar7);
    ppuVar9 = &Reset;
    FUN_00000170(ppuVar5,&local_28,4);
    param_1 = (code *)ppuVar10;
    ppuVar12 = ppuVar5;
  case (undefined **)0x26:
    ppuVar5 = ppuVar12;
    ppuVar10 = (undefined **)param_1;
LAB_0000e98e:
    FUN_0000e1b8(ppuVar10,ppuVar11,ppuVar5,ppuVar9);
    uVar6 = extraout_r2;
LAB_0000e994:
    *param_3 = (undefined *)(uVar6 | 0x30);
    return 1;
  case (undefined **)0x1c:
    puVar4 = (undefined4 *)0x3f0;
    param_2 = (undefined **)0x30000;
  case (undefined **)0x20:
    iVar3 = (*(code *)*puVar4)(ppuVar5,(undefined1 *)((int)param_1 + (int)param_2),ppuVar9);
    if (iVar3 != 0) {
      *ppuVar11 = (undefined *)(((uint)ppuVar10 & 0xfffff80f) + 0x10);
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
    *ppuVar7 = (undefined *)(((uint)ppuVar9 & 0xfffff80f) + (int)ppuStack_38 * 0x40 + 0x10);
    return 1;
  case (undefined **)0x27:
    goto switchD_0000e1fa_caseD_27;
  case (undefined **)0x28:
    if (ppuVar7 != (undefined **)0x0) {
      if (uVar6 != 0) {
        FUN_00000170(&local_28,ppuVar8,4);
        if (((uint)local_28 & 0xff) != 0) {
          if (((uint)local_28 & 0xff) != 1) {
            *param_3 = (undefined *)(((uint)ppuVar10 & 0xfffff80f) + 0x20);
            return 1;
          }
          uVar6 = switchD_0000e1fa::caseD_25(1);
          return uVar6;
        }
        param_1 = (code *)0x0;
        ppuVar7 = param_3;
        ppuVar9 = ppuVar10;
        goto code_r0x0000ea16;
      }
      FUN_00000170(&local_28,ppuVar8,4);
      *(short *)(DAT_0000eb90 + 0x36) = (short)local_28;
      goto switchD_0000e1fa_caseD_15;
    }
    param_2 = (undefined **)(uint)(byte)(*(char *)(DAT_0000ebac + 0x17) + 1);
    param_1 = (code *)DAT_0000ebac;
  case (undefined **)0xa:
    if (param_2 < (undefined **)0x2) {
      *(undefined1 *)((int)param_1 + 0x67) = *(undefined1 *)ppuVar8;
      FUN_00008efc();
    }
FUN_0000e9cc:
    param_1 = FUN_000007f0;
    goto switchD_0000e1fa_caseD_e;
  }
  puVar13 = (undefined *)(((uint)ppuVar10 & 0xfffff80f) + (int)ppuStack_38 * 0x40 + 0x10);
LAB_0000e95e:
  *param_3 = puVar13;
  return 1;
switchD_0000e1fa_caseD_e:
  puVar13 = (undefined *)(((uint)ppuVar10 & ~(uint)param_1) + 0x110);
  goto LAB_0000e95e;
}

