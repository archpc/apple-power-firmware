
uint FUN_00000c34(uint *param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  code *pcVar10;
  int iVar11;
  int extraout_r1;
  uint extraout_r2;
  int iVar12;
  int iVar13;
  bool bVar14;
  undefined4 in_cr14;
  longlong lVar15;
  longlong lVar16;
  undefined8 uVar17;
  byte local_34 [4];
  undefined1 auStack_30 [8];
  code *local_28;
  uint uStack_1c;
  
  uVar4 = (uint)*(byte *)(param_1[6] - 2);
  switch(uVar4) {
  case 0:
    FUN_00000c20();
    puVar2 = puRam00000df0;
    coprocessor_store(0,in_cr14,param_1);
    uStack_1c = extraout_r2 + extraout_r1 ^ extraout_r2;
    uVar4 = 0;
    bVar14 = (bool)isCurrentModePrivileged();
    if (bVar14) {
      uVar4 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    *puRam00000df0 = 1;
    piRam00000de8[2] = piRam00000de8[2] | 1;
    lVar15 = FUN_00000e08();
    iVar11 = iRam00000df4;
    iVar8 = (int)((ulonglong)lVar15 >> 0x20);
    uVar5 = (uint)lVar15;
    if (((int)(uint)(*(int *)(iRam00000df4 + 0x10) == 0) <= *(int *)(iRam00000df4 + 0x14)) &&
       (bVar14 = uVar5 < *(uint *)(iRam00000df4 + 0x10),
       lVar15 = lVar15 - *(longlong *)(iRam00000df4 + 0x10), uVar5 = (uint)lVar15,
       lVar15 < 0 ==
       (SBORROW4(iVar8,*(int *)(iRam00000df4 + 0x14)) !=
       SBORROW4(iVar8 - *(int *)(iRam00000df4 + 0x14),(uint)bVar14)))) {
      *(undefined4 *)(iRam00000df4 + 0x14) = 0;
      *(undefined4 *)(iVar11 + 0x10) = 0;
      uVar9 = uRam00000dfc;
      iVar8 = iRam00000df8;
      while (uVar6 = 0, *(char *)(iVar8 + 0x111) != '\0') {
        local_34[0] = **(byte **)(iVar8 + 0x114);
        iVar12 = *(int *)(iVar8 + (uint)local_34[0] * 0x10 + 4);
        uVar5 = *(uint *)(iVar8 + (uint)local_34[0] * 0x10);
        lVar16 = FUN_00000e08();
        iVar13 = (int)((ulonglong)lVar16 >> 0x20);
        lVar15 = lVar16 - CONCAT44(iVar12,uVar5);
        uVar6 = (undefined4)lVar15;
        if (lVar15 < 0 !=
            (SBORROW4(iVar13,iVar12) != SBORROW4(iVar13 - iVar12,(uint)((uint)lVar16 < uVar5))))
        break;
        FUN_00001150(iVar8 + 0x110,local_34,uVar9,0);
        bVar3 = local_34[0];
        uVar5 = (uint)local_34[0];
        iVar13 = iVar8 + uVar5 * 0x10;
        FUN_00000170(auStack_30,iVar13,0x10);
        *(undefined4 *)(iVar8 + uVar5 * 0x10) = 0;
        *(undefined4 *)(iVar13 + 8) = 0;
        *(undefined4 *)(iVar13 + 4) = 0;
        *(byte *)(*(int *)(iVar8 + 0x114) + (uint)*(byte *)(iVar8 + 0x111)) = bVar3;
        (*local_28)(auStack_30);
      }
      uVar5 = FUN_00001244(uVar6);
    }
    lVar15 = FUN_00000e08(uVar5);
    iVar8 = (int)((ulonglong)lVar15 >> 0x20);
    uVar5 = (uint)lVar15;
    if (*(int *)(iVar11 + 0x10) == 0 && *(int *)(iVar11 + 0x14) == 0) {
      uVar7 = 0x8000;
    }
    else {
      uVar7 = *(uint *)(iVar11 + 0x10) - uVar5;
      if ((int)(uint)(uVar7 < 0x8000) <=
          (int)((*(int *)(iVar11 + 0x14) - iVar8) - (uint)(*(uint *)(iVar11 + 0x10) < uVar5))) {
        uVar7 = 0x8000;
      }
      if ((int)uVar7 < 4) {
        uVar7 = 3;
      }
    }
    piRam00000de8[1] = *piRam00000de8 + uVar7 & 0xffff;
    iVar13 = iRam00000e00;
    iVar12 = *(int *)(iVar11 + 0xc);
    uVar7 = *(uint *)(iVar11 + 8);
    if ((int)((iVar12 - iVar8) - (uint)(uVar7 < uVar5)) < 0 !=
        (SBORROW4(iVar12,iVar8) != SBORROW4(iVar12 - iVar8,(uint)(uVar7 < uVar5)))) {
      FUN_00000f28(iRam00000e00 + 0x58,uVar7 - uVar5);
      iVar8 = *(int *)(iVar13 + 8) + -1;
      *(int *)(iVar13 + 8) = iVar8;
      if (iVar8 == 0) {
        FUN_00012c44(uRam00000e04);
        uVar17 = FUN_00000bac();
        if (uVar5 != 0) {
          uVar9 = 0;
          bVar14 = (bool)isCurrentModePrivileged();
          if (bVar14) {
            uVar9 = isIRQinterruptsEnabled();
          }
          uVar17 = CONCAT44(DAT_00000e48,uVar9);
          disableIRQinterrupts();
        }
        iVar11 = (int)((ulonglong)uVar17 >> 0x20);
        iVar8 = *(int *)(iVar11 + 0x40);
        uVar4 = *DAT_00000e40;
        *(uint *)(iVar11 + 0x40) = uVar4 & 0xffff;
        iVar11 = DAT_00000e4c;
        uVar4 = (uVar4 & 0xffff) - iVar8;
        if ((int)uVar4 < 0) {
          uVar4 = uVar4 + DAT_00000e44;
        }
        piVar1 = (int *)(DAT_00000e4c + 0x1c);
        uVar5 = *(uint *)(DAT_00000e4c + 0x18);
        *(uint *)(DAT_00000e4c + 0x18) = uVar5 + uVar4;
        *(uint *)(iVar11 + 0x1c) = *piVar1 + ((int)uVar4 >> 0x1f) + (uint)CARRY4(uVar5,uVar4);
        bVar14 = (bool)isCurrentModePrivileged();
        if (bVar14) {
          enableIRQinterrupts(((uint)uVar17 & 1) == 1);
        }
        return *(uint *)(iVar11 + 0x18);
      }
      *(ulonglong *)(iVar11 + 8) = lVar15 + (ulonglong)uRam00000dec;
    }
    *puVar2 = 0;
    bVar14 = (bool)isCurrentModePrivileged();
    if (bVar14) {
      enableIRQinterrupts((uVar4 & 1) == 1);
    }
                    /* WARNING: Could not recover jumptable at 0x00000ddc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar4 = (*(code *)0xc9d)(uVar4);
    return uVar4;
  case 1:
    *puRam00000c9c = 0x10000000;
    InstructionSynchronizationBarrier(0xf);
    return 0x10000000;
  case 2:
    iVar11 = *(int *)(iRam00000ca0 + 0x4c);
    *(uint *)(iVar11 + 0xc) = *param_1;
    *(undefined1 *)(iVar11 + 9) = 0;
    *puRam00000c9c = 0x10000000;
    InstructionSynchronizationBarrier(0xf);
    return 0x10000000;
  case 3:
    uVar4 = ((undefined4 *)*param_1)[1];
    pcVar10 = *(code **)*param_1;
    break;
  default:
    if (uVar4 < 0x40) {
      return uVar4;
    }
    pcVar10 = *(code **)(uVar4 * 4 + iRam00000ca4 + -0x100);
    uVar4 = *param_1;
  }
  uVar4 = (*pcVar10)(uVar4);
  *param_1 = uVar4;
  return uVar4;
}

