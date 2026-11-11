
undefined4 FUN_0000d048(int param_1)

{
  code *pcVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  uint uVar8;
  undefined1 *puVar9;
  uint uVar10;
  int iVar11;
  undefined1 *puVar12;
  uint uVar13;
  undefined1 auStack_114 [64];
  uint auStack_d4 [8];
  uint auStack_b4 [8];
  undefined1 auStack_94 [64];
  undefined1 auStack_54 [64];
  
  if (*(char *)(DAT_0000d24c + 0x66) == '\x01') {
LAB_0000d058:
    uVar3 = 0;
  }
  else {
    puVar9 = DAT_0000d250;
    if (param_1 != 0) {
      puVar9 = DAT_0000d250 + 0x40;
    }
    iVar4 = FUN_00001c44(puVar9);
    pcVar1 = DAT_0000d254;
    puVar7 = DAT_0000d250;
    if (iVar4 == 0) {
      puVar12 = DAT_0000d250;
      if (param_1 != 0) {
        puVar12 = DAT_0000d250 + 0x40;
      }
      (*DAT_0000d254)(auStack_54,puVar12,puVar12);
      (*pcVar1)(auStack_94,auStack_54,puVar12);
      puVar2 = PTR_FUN_00001fd0_1_0000d258;
      (*(code *)PTR_FUN_00001fd0_1_0000d258)(auStack_54,auStack_94,puVar12);
      (*(code *)puVar2)(auStack_94,auStack_54,puVar12);
      (*(code *)puVar2)(auStack_54,auStack_94,puVar12);
      FUN_00001b08(auStack_94,auStack_54,PTR_DAT_0000d25c);
      if (param_1 == 0) {
        puVar7 = puVar7 + 0x20;
      }
      else {
        puVar7 = puVar7 + 0x60;
      }
      (*pcVar1)(auStack_54,puVar7,puVar7);
      iVar4 = FUN_0000176c(auStack_54,auStack_94);
      if (iVar4 == 0) {
        FUN_000001a2(auStack_114,0,0x40);
        puVar2 = PTR_DAT_0000d260;
        iVar4 = FUN_00001822(PTR_DAT_0000d260);
        if ((iVar4 == 0) && (iVar4 = FUN_00001c44(puVar9), iVar4 == 0)) {
          uVar13 = 0x101;
          do {
            FUN_00000170(auStack_54,auStack_114,0x40);
            FUN_00001c60(auStack_114,auStack_54);
            if ((*(uint *)(puVar2 + (uVar13 - 2 >> 5) * 4) >> (uVar13 - 2 & 0x1f) & 1) != 0) {
              FUN_00000170(auStack_54,auStack_114,0x40);
              FUN_00001bc4(auStack_114,auStack_54,puVar9);
            }
            uVar13 = uVar13 - 1;
          } while (1 < uVar13);
        }
        iVar4 = FUN_00001c44(auStack_114);
        if (((iVar4 != 0) && (iVar5 = FUN_00001822(DAT_0000d264), iVar4 = DAT_0000d264, iVar5 == 0))
           && (iVar5 = FUN_0000176c(PTR_DAT_0000d260,DAT_0000d264), -1 < iVar5)) {
          iVar11 = iVar4 + 0x20;
          iVar5 = FUN_0000176c(PTR_DAT_0000d260,iVar11);
          if (((-1 < iVar5) &&
              (iVar5 = FUN_0000197c(auStack_b4,iVar4 + 0x60,iVar11,PTR_DAT_0000d260), iVar5 != 0))
             && (iVar4 = FUN_0000197c(auStack_d4,iVar4,iVar11,PTR_DAT_0000d260), iVar4 != 0)) {
            FUN_000001a2(auStack_114,0,0x40);
            FUN_00001bc4(auStack_94,DAT_0000d268,puVar9);
            uVar13 = 0x101;
            do {
              FUN_00000170(auStack_54,auStack_114,0x40);
              FUN_00001c60(auStack_114,auStack_54);
              uVar8 = uVar13 - 2 & 0x1f;
              uVar6 = uVar13 - 2 >> 5;
              uVar10 = auStack_b4[uVar6];
              uVar6 = auStack_d4[uVar6];
              if (((uVar6 | uVar10) >> uVar8 & 1) != 0) {
                FUN_00000170(auStack_54,auStack_114,0x40);
                if (((uVar6 & uVar10) >> uVar8 & 1) == 0) {
                  puVar7 = DAT_0000d268;
                  if ((uVar10 >> uVar8 & 1) == 0) {
                    puVar7 = puVar9;
                  }
                }
                else {
                  puVar7 = auStack_94;
                }
                FUN_00001bc4(auStack_114,auStack_54,puVar7);
              }
              uVar13 = uVar13 - 1;
            } while (1 < uVar13);
            iVar4 = FUN_0000176c(auStack_114,PTR_DAT_0000d260);
            if (0 < iVar4) {
              FUN_000017a0(auStack_114,PTR_DAT_0000d260);
            }
            iVar4 = FUN_0000176c(auStack_114,DAT_0000d264);
            if (iVar4 == 0) goto LAB_0000d058;
          }
        }
      }
    }
    uVar3 = 4;
  }
  return uVar3;
}

