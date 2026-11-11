
undefined4 FUN_0000d1d8(int param_1)

{
  code *pcVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined1 *puVar8;
  uint uVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  undefined1 auStack_114 [64];
  uint auStack_d4 [8];
  uint auStack_b4 [8];
  undefined1 auStack_94 [64];
  undefined1 auStack_54 [64];
  
  if (*(char *)(DAT_0000d3d4 + 0x66) == '\x01') {
LAB_0000d1e8:
    uVar4 = 0;
  }
  else {
    puVar11 = DAT_0000d3d8;
    if (param_1 != 0) {
      puVar11 = DAT_0000d3d8 + 0x40;
    }
    iVar5 = FUN_00001bc8(puVar11);
    pcVar1 = DAT_0000d3dc;
    if (iVar5 == 0) {
      (*DAT_0000d3dc)(auStack_54,puVar11,puVar11);
      (*pcVar1)(auStack_94,auStack_54,puVar11);
      puVar2 = PTR_FUN_00001f54_1_0000d3e0;
      (*(code *)PTR_FUN_00001f54_1_0000d3e0)(auStack_54,auStack_94,puVar11);
      (*(code *)puVar2)(auStack_94,auStack_54,puVar11);
      (*(code *)puVar2)(auStack_54,auStack_94,puVar11);
      FUN_00001a8c(auStack_94,auStack_54,PTR_DAT_0000d3e4);
      if (param_1 == 0) {
        iVar5 = 0x20;
      }
      else {
        iVar5 = 0x60;
      }
      (*pcVar1)(auStack_54,DAT_0000d3d8 + iVar5,DAT_0000d3d8 + iVar5);
      iVar5 = FUN_000016fc(auStack_54,auStack_94);
      if (iVar5 == 0) {
        FUN_000001a0(auStack_114,0,0x40);
        puVar2 = PTR_DAT_0000d3e8;
        iVar5 = FUN_000017b0(PTR_DAT_0000d3e8);
        if ((iVar5 == 0) && (iVar5 = FUN_00001bc8(puVar11), iVar5 == 0)) {
          uVar12 = 0x101;
          do {
            FUN_00000170(auStack_54,auStack_114,0x40);
            FUN_00001be4(auStack_114,auStack_54);
            if ((*(uint *)(puVar2 + (uVar12 - 2 >> 5) * 4) >> (uVar12 - 2 & 0x1f) & 1) != 0) {
              FUN_00000170(auStack_54,auStack_114,0x40);
              FUN_00001b48(auStack_114,auStack_54,puVar11);
            }
            uVar12 = uVar12 - 1;
          } while (1 < uVar12);
        }
        iVar5 = FUN_00001bc8(auStack_114);
        if (((iVar5 != 0) && (iVar6 = FUN_000017b0(DAT_0000d3ec), iVar5 = DAT_0000d3ec, iVar6 == 0))
           && (iVar6 = FUN_000016fc(PTR_DAT_0000d3e8,DAT_0000d3ec), -1 < iVar6)) {
          iVar14 = iVar5 + 0x20;
          iVar6 = FUN_000016fc(PTR_DAT_0000d3e8,iVar14);
          if (((-1 < iVar6) &&
              (iVar6 = FUN_00001904(auStack_b4,iVar5 + 0x60,iVar14,PTR_DAT_0000d3e8), iVar6 != 0))
             && (iVar5 = FUN_00001904(auStack_d4,iVar5,iVar14,PTR_DAT_0000d3e8), iVar5 != 0)) {
            FUN_000001a0(auStack_114,0,0x40);
            puVar3 = DAT_0000d3f0;
            FUN_00001b48(auStack_94,DAT_0000d3f0,puVar11);
            uVar12 = 0x101;
            do {
              FUN_00000170(auStack_54,auStack_114,0x40);
              FUN_00001be4(auStack_114,auStack_54);
              uVar9 = 1 << (uVar12 - 2 & 0x1f);
              uVar7 = uVar12 - 2 >> 5;
              uVar15 = auStack_d4[uVar7];
              uVar13 = auStack_b4[uVar7] & uVar9;
              if ((uVar9 & (auStack_b4[uVar7] | uVar15)) != 0) {
                FUN_00000170(auStack_54,auStack_114,0x40);
                puVar10 = puVar11;
                if (uVar13 != 0) {
                  puVar10 = puVar3;
                }
                puVar8 = puVar10;
                if ((uVar15 & uVar9) != 0) {
                  puVar8 = auStack_94;
                }
                if (uVar13 != 0) {
                  puVar10 = puVar8;
                }
                FUN_00001b48(auStack_114,auStack_54,puVar10);
              }
              uVar12 = uVar12 - 1;
            } while (1 < uVar12);
            iVar5 = FUN_000016fc(auStack_114,PTR_DAT_0000d3e8);
            if (0 < iVar5) {
              FUN_00001730(auStack_114,PTR_DAT_0000d3e8);
            }
            iVar5 = FUN_000016fc(auStack_114,DAT_0000d3ec);
            if (iVar5 == 0) goto LAB_0000d1e8;
          }
        }
      }
    }
    uVar4 = 4;
  }
  return uVar4;
}

