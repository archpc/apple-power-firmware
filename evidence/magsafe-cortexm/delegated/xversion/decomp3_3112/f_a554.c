
void FUN_0000a554(int param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  undefined4 uVar13;
  uint uVar14;
  bool bVar15;
  uint local_54;
  int local_50;
  int local_4c;
  uint local_48 [7];
  undefined4 local_2c [6];
  
  iVar5 = DAT_0000a70c;
  iVar11 = *(int *)(*(int *)(DAT_0000a708 + 0x118) + 0x11c);
  if (iVar11 == 0) {
    if (*(char *)(DAT_0000a70c + 0x16) == '\x01') {
      uVar9 = 0x32;
    }
    else if (*(char *)(DAT_0000a70c + 0x16) == '\x02') {
      uVar9 = 0x96;
    }
    else if (*(char *)(DAT_0000a70c + 0x16) == '\x03') {
      uVar9 = 300;
    }
    else {
      uVar9 = 10;
    }
    uVar10 = FUN_0000a478(100);
    local_48[0] = 0x19000;
    if (uVar10 <= uVar9) {
      local_48[0] = (DAT_0000a6f4 & uVar9 - uVar10) + 0x19000;
    }
    FUN_00002a60(1,local_48);
    *(undefined1 *)(iVar5 + 0x1d6) = 1;
  }
  else {
    if ((DAT_0000a6f0 + 0xe & *(uint *)(iVar11 + 4)) == DAT_0000a6f0) {
      uVar9 = (*(uint *)(iVar11 + 4) & 0x1ffffff) >> 0x12;
    }
    else {
      uVar9 = (uint)*(byte *)(iVar11 + 1);
    }
    puVar12 = (uint *)(iVar11 + 8);
    puVar7 = local_48;
    for (uVar10 = uVar9; uVar14 = DAT_0000a6f8, uVar10 != 0; uVar10 = uVar10 - 1) {
      FUN_0000a514(puVar12,&local_4c,&local_50,&local_54);
      if (((uint)(local_50 * 0x32) < uVar14 || local_50 * 0x32 - uVar14 == 0) &&
         ((uint)(local_4c * 0x32) < uVar14 || local_4c * 0x32 - uVar14 == 0)) {
        uVar14 = *puVar12;
      }
      else {
        uVar14 = 0;
        local_4c = 0;
        local_50 = 0;
      }
      uVar14 = uVar14 & DAT_0000a6fc;
      uVar4 = FUN_0000a478(local_4c);
      bVar15 = local_54 < uVar4;
      local_54 = local_54 - uVar4;
      if (bVar15) {
        local_54 = 0;
      }
      *puVar7 = uVar14 + (local_54 & DAT_0000a6f4);
      puVar7 = puVar7 + 1;
      puVar12 = puVar12 + 1;
    }
    local_48[0] = local_48[0] & 0xc9ffffff;
    if (uVar9 < 8) {
      FUN_00002a60(uVar9,local_48);
      *(byte *)(DAT_0000a70c + 0x1d6) =
           ~(byte)(-1 << uVar9) | (byte)(*(uint *)(iVar11 + 8) >> 0x14) & 0x80;
    }
    else {
      FUN_00002a60(7,local_48);
      iVar5 = DAT_0000a70c;
      *(byte *)(DAT_0000a70c + 0x1d6) = (byte)(*(uint *)(iVar11 + 8) >> 0x14) | 0x7f;
      bVar1 = (char)uVar9 - 7;
      if ((uVar9 - 8 & 0xff) < 6) {
        puVar6 = (undefined4 *)(iVar5 + 0x34c);
        puVar8 = local_2c;
        for (uVar9 = (uint)bVar1; uVar9 != 0; uVar9 = uVar9 - 1) {
          uVar13 = *puVar8;
          puVar8 = puVar8 + 1;
          *puVar6 = uVar13;
          puVar6 = puVar6 + 1;
        }
        *(byte *)(iVar5 + DAT_0000a700) = bVar1;
      }
      *(byte *)(iVar5 + DAT_0000a704) = ~(byte)(-1 << (uint)bVar1);
    }
  }
  if ((param_1 != 0) &&
     (iVar5 = FUN_0000295c(1,0,0,DAT_0000a710), puVar2 = DAT_0000a714, iVar5 != 0)) {
    uVar9 = 0;
    bVar15 = (bool)isCurrentModePrivileged();
    if (bVar15) {
      uVar9 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_000012a8(DAT_0000a714);
    uVar3 = FUN_00001178(1000,0,DAT_0000a718,0);
    *puVar2 = uVar3;
    bVar15 = (bool)isCurrentModePrivileged();
    if (bVar15) {
      enableIRQinterrupts((uVar9 & 1) == 1);
    }
  }
  return;
}

