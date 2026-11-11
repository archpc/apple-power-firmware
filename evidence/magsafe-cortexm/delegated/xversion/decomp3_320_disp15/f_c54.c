
uint FUN_00000c54(uint *param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  uint *puVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  code *pcVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  bool bVar16;
  undefined4 in_cr14;
  longlong lVar17;
  longlong lVar18;
  undefined8 uVar19;
  byte local_34 [4];
  undefined1 auStack_30 [8];
  code *local_28;
  uint *puStack_1c;
  
  uVar5 = (uint)*(byte *)(param_1[6] - 2);
  switch(uVar5) {
  case 0:
    FUN_00000c40();
    puVar2 = puRam00000e20;
    coprocessor_store(0,in_cr14,param_1);
    uVar5 = 0;
    bVar16 = (bool)isCurrentModePrivileged();
    if (bVar16) {
      uVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    *puRam00000e20 = 1;
    piRam00000e18[2] = piRam00000e18[2] | 1;
    puStack_1c = param_1;
    lVar17 = FUN_00000e38();
    puVar3 = puRam00000e24;
    iVar11 = (int)((ulonglong)lVar17 >> 0x20);
    uVar6 = (uint)lVar17;
    if (((int)(uint)(puRam00000e24[2] == 0) <= (int)puRam00000e24[3]) &&
       (bVar16 = uVar6 < puRam00000e24[2], lVar17 = lVar17 - *(longlong *)(puRam00000e24 + 2),
       uVar6 = (uint)lVar17,
       lVar17 < 0 ==
       (SBORROW4(iVar11,puRam00000e24[3]) != SBORROW4(iVar11 - puRam00000e24[3],(uint)bVar16)))) {
      puRam00000e24[3] = 0;
      puVar3[2] = 0;
      uVar9 = uRam00000e2c;
      iVar11 = iRam00000e28;
      while (uVar7 = 0, *(char *)(iVar11 + 0x111) != '\0') {
        local_34[0] = **(byte **)(iVar11 + 0x114);
        iVar14 = *(int *)(iVar11 + (uint)local_34[0] * 0x10 + 4);
        uVar6 = *(uint *)(iVar11 + (uint)local_34[0] * 0x10);
        lVar18 = FUN_00000e38();
        iVar15 = (int)((ulonglong)lVar18 >> 0x20);
        lVar17 = lVar18 - CONCAT44(iVar14,uVar6);
        uVar7 = (undefined4)lVar17;
        if (lVar17 < 0 !=
            (SBORROW4(iVar15,iVar14) != SBORROW4(iVar15 - iVar14,(uint)((uint)lVar18 < uVar6))))
        break;
        FUN_00001178(iVar11 + 0x110,local_34,uVar9,0,uVar5);
        bVar4 = local_34[0];
        uVar6 = (uint)local_34[0];
        iVar15 = iVar11 + uVar6 * 0x10;
        FUN_00000170(auStack_30,iVar15,0x10);
        *(undefined4 *)(iVar11 + uVar6 * 0x10) = 0;
        *(undefined4 *)(iVar15 + 8) = 0;
        *(undefined4 *)(iVar15 + 4) = 0;
        *(byte *)(*(int *)(iVar11 + 0x114) + (uint)*(byte *)(iVar11 + 0x111)) = bVar4;
        (*local_28)(auStack_30);
      }
      uVar6 = FUN_0000126c(uVar7);
    }
    lVar17 = FUN_00000e38(uVar6);
    iVar11 = (int)((ulonglong)lVar17 >> 0x20);
    uVar6 = (uint)lVar17;
    if (puVar3[2] == 0 && puVar3[3] == 0) {
      uVar8 = 0x8000;
    }
    else {
      uVar8 = puVar3[2] - uVar6;
      uVar12 = (uint)(puVar3[2] < uVar6);
      uVar13 = uVar8;
      if (-1 < (int)((puVar3[3] - iVar11) - uVar12)) {
        uVar13 = 0x8000;
      }
      if (0x7fff < uVar8) {
        uVar8 = 0x8000;
      }
      if (puVar3[3] - iVar11 != uVar12) {
        uVar8 = uVar13;
      }
    }
    if ((int)uVar8 < 4) {
      uVar8 = 3;
    }
    piRam00000e18[1] = *piRam00000e18 + uVar8 & 0xffff;
    iVar15 = iRam00000e30;
    uVar8 = puVar3[1];
    uVar12 = *puVar3;
    if ((int)((uVar8 - iVar11) - (uint)(uVar12 < uVar6)) < 0 !=
        (SBORROW4(uVar8,iVar11) != SBORROW4(uVar8 - iVar11,(uint)(uVar12 < uVar6)))) {
      FUN_00000f54(iRam00000e30 + 0x38,uVar12 - uVar6);
      iVar11 = *(int *)(iVar15 + 8) + -1;
      *(int *)(iVar15 + 8) = iVar11;
      if (iVar11 == 0) {
        FUN_00012e20(uRam00000e34);
        uVar19 = FUN_00000bcc();
        if (uVar6 != 0) {
          uVar9 = 0;
          bVar16 = (bool)isCurrentModePrivileged();
          if (bVar16) {
            uVar9 = isIRQinterruptsEnabled();
          }
          uVar19 = CONCAT44(DAT_00000e78,uVar9);
          disableIRQinterrupts();
        }
        iVar11 = (int)((ulonglong)uVar19 >> 0x20);
        iVar15 = *(int *)(iVar11 + 0x44);
        uVar5 = *DAT_00000e70;
        *(uint *)(iVar11 + 0x44) = uVar5 & 0xffff;
        iVar11 = DAT_00000e7c;
        uVar5 = (uVar5 & 0xffff) - iVar15;
        if ((int)uVar5 < 0) {
          uVar5 = uVar5 + DAT_00000e74;
        }
        piVar1 = (int *)(DAT_00000e7c + 0x14);
        uVar6 = *(uint *)(DAT_00000e7c + 0x10);
        *(uint *)(DAT_00000e7c + 0x10) = uVar6 + uVar5;
        *(uint *)(iVar11 + 0x14) = *piVar1 + (uint)CARRY4(uVar6,uVar5);
        bVar16 = (bool)isCurrentModePrivileged();
        if (bVar16) {
          enableIRQinterrupts(((uint)uVar19 & 1) == 1);
        }
        return *(uint *)(iVar11 + 0x10);
      }
      *(ulonglong *)puVar3 = lVar17 + (ulonglong)uRam00000e1c;
    }
    *puVar2 = 0;
    bVar16 = (bool)isCurrentModePrivileged();
    if (bVar16) {
      enableIRQinterrupts((uVar5 & 1) == 1);
    }
                    /* WARNING: Could not recover jumptable at 0x00000e0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar5 = (*(code *)0xcbd)();
    return uVar5;
  case 1:
    *puRam00000cbc = 0x10000000;
    InstructionSynchronizationBarrier(0xf);
    return 0x10000000;
  case 2:
    iVar11 = *(int *)(iRam00000cc0 + 0x48);
    *(uint *)(iVar11 + 0xc) = *param_1;
    *(undefined1 *)(iVar11 + 9) = 0;
    *puRam00000cbc = 0x10000000;
    InstructionSynchronizationBarrier(0xf);
    return 0x10000000;
  case 3:
    uVar5 = ((undefined4 *)*param_1)[1];
    pcVar10 = *(code **)*param_1;
    break;
  default:
    if (uVar5 < 0x40) {
      return uVar5;
    }
    pcVar10 = *(code **)(uVar5 * 4 + iRam00000cc4 + -0x100);
    uVar5 = *param_1;
  }
  uVar5 = (*pcVar10)(uVar5);
  *param_1 = uVar5;
  return uVar5;
}

