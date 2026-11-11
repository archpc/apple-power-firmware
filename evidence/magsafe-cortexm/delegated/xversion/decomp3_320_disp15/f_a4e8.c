
void FUN_0000a4e8(int param_1)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 *puVar12;
  uint local_48 [7];
  undefined4 local_2c [6];
  
  iVar11 = DAT_0000a7f4;
  iVar7 = *(int *)(*(int *)(DAT_0000a7f0 + 0x118) + 0x11c);
  if (iVar7 == 0) {
    if (*(char *)(DAT_0000a7f4 + 0x16) == '\x01') {
      local_48[0] = DAT_0000a7e8 + 0x28;
    }
    else if (*(char *)(DAT_0000a7f4 + 0x16) == '\x02') {
      local_48[0] = DAT_0000a7e8 + 0x8c;
    }
    else {
      local_48[0] = DAT_0000a7e8;
      if (*(char *)(DAT_0000a7f4 + 0x16) == '\x03') {
        local_48[0] = DAT_0000a7ec;
      }
    }
    FUN_00002a30(1,local_48);
    *(undefined1 *)(iVar11 + 0x1d6) = 1;
  }
  else {
    if ((DAT_0000a7bc + 0xe & *(uint *)(iVar7 + 4)) == DAT_0000a7bc) {
      uVar4 = (*(uint *)(iVar7 + 4) & 0x1ffffff) >> 0x12;
    }
    else {
      uVar4 = (uint)*(byte *)(iVar7 + 1);
    }
    puVar8 = (uint *)(iVar7 + 8);
    for (iVar11 = 0; uVar4 << 2 != iVar11; iVar11 = iVar11 + 4) {
      uVar5 = *(uint *)((int)puVar8 + iVar11);
      iVar7 = FUN_0000a958(uVar5);
      if (iVar7 != 0) {
        iVar11 = FUN_0000089c(DAT_0000a7d0,iVar7);
        FUN_0000089c(iVar11 + 9,10);
                    /* WARNING: Could not recover jumptable at 0x0000a572. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)((uint)(byte)(&DAT_0000a574)[uVar5 >> 0x1e] * 2 + 0xa576))();
        return;
      }
      *(undefined4 *)((int)local_48 + iVar11) = 0;
    }
    local_48[0] = local_48[0] & 0xc9ffffff;
    if (uVar4 < 8) {
      FUN_00002a30(uVar4,local_48);
      *(byte *)(DAT_0000a7f4 + 0x1d6) = ~(byte)(-1 << uVar4) | (byte)(*puVar8 >> 0x14) & 0x80;
    }
    else {
      FUN_00002a30(7,local_48);
      iVar11 = DAT_0000a7f4;
      *(byte *)(DAT_0000a7f4 + 0x1d6) = (byte)(*puVar8 >> 0x14) | 0x7f;
      uVar4 = uVar4 - 7;
      uVar5 = uVar4 & 0xff;
      if ((uVar5 != 0) && ((uVar4 & 0xff) < 7)) {
        puVar12 = local_2c;
        puVar6 = (undefined4 *)(iVar11 + 0x34c);
        for (uVar9 = uVar5; uVar9 != 0; uVar9 = uVar9 - 1) {
          uVar10 = *puVar12;
          puVar12 = puVar12 + 1;
          *puVar6 = uVar10;
          puVar6 = puVar6 + 1;
        }
        *(char *)(iVar11 + DAT_0000a7e0) = (char)uVar4;
      }
      *(byte *)(iVar11 + DAT_0000a7e4) = ~(byte)(-1 << uVar5);
    }
  }
  if ((param_1 != 0) &&
     (iVar11 = FUN_0000290c(1,0,0,DAT_0000a7f8), puVar2 = DAT_0000a7fc, iVar11 != 0)) {
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    FUN_000012d0(DAT_0000a7fc);
    uVar3 = FUN_000011a0(1000,0,DAT_0000a800,0);
    *puVar2 = uVar3;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar4 & 1) == 1);
    }
  }
  return;
}

