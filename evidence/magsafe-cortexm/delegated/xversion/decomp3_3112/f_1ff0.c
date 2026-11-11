
undefined4 FUN_00001ff0(void)

{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  undefined1 *puVar10;
  int local_18;
  
  iVar4 = DAT_00002170;
  iVar3 = DAT_0000216c;
  pbVar9 = (byte *)(DAT_0000216c + 0x2d);
  local_18 = DAT_00002170 + 8;
  pcVar6 = (char *)(DAT_00002174 + 0x73);
  for (uVar7 = 0; uVar7 != 2; uVar7 = uVar7 + 1) {
    if (pbVar9[4] != 0) {
      if (*(int *)(pbVar9 + 0x1f) != 0) {
        return 0;
      }
      bVar2 = *pbVar9;
      uVar8 = uVar7 & 0xff;
      iVar5 = FUN_0000c8d4(uVar8,0x15);
      if (bVar2 - 1 < 2) {
        return 0;
      }
      if (iVar5 != 0) {
        return 0;
      }
      if (bVar2 - 6 < 4) {
        iVar5 = FUN_0000c900(uVar8,0x10,0x12);
        if (iVar5 != 0) {
          return 0;
        }
        if (*(char *)(local_18 + (uint)pbVar9[-0x13]) == '\0') {
          return 0;
        }
      }
      bVar2 = pbVar9[0x18];
      if (bVar2 != 0) {
        if (*(int *)(pbVar9 + 0x1b) != 0) {
          return 0;
        }
        iVar5 = FUN_0000c8d4(uVar8,9);
        if (iVar5 != 0) {
          return 0;
        }
        if (*(int *)(pcVar6 + 0xd) != 0) {
          return 0;
        }
        if (pcVar6[0x11] != '\0') {
          return 0;
        }
        if (*pcVar6 == '\x01') {
          return 0;
        }
        iVar5 = FUN_00008be8(uVar8);
        if (iVar5 != 0) {
          return 0;
        }
        if (pbVar9[-0xb] != 1) {
          uVar8 = bVar2 - 0xb;
          if (0x18 < uVar8) {
            return 0;
          }
          if ((1 << (uVar8 & 0xff) & DAT_00002168) == 0) {
            return 0;
          }
        }
      }
    }
    pbVar9 = pbVar9 + 0x1cc;
    pcVar6 = pcVar6 + 0x88;
    local_18 = local_18 + 0xb;
  }
  iVar5 = 3;
  pcVar6 = (char *)(iVar3 + 0x31);
  while (iVar5 = iVar5 + -1, iVar5 != 0) {
    if (((1 < (byte)pcVar6[-4] - 3) || (*pcVar6 == '\0')) ||
       (pcVar1 = pcVar6 + -0x29, pcVar6 = pcVar6 + 0x1cc, *pcVar1 != '\x01')) goto LAB_00002108;
  }
  if (*(char *)(iVar4 + 6) == '\0') {
    for (uVar7 = 0; uVar7 != 2; uVar7 = uVar7 + 1) {
      FUN_0000c88c(uVar7 & 0xff,0x10);
    }
    puVar10 = (undefined1 *)(iVar4 + 6);
    for (uVar7 = 0; uVar7 != 2; uVar7 = uVar7 + 1) {
      *puVar10 = 1;
      FUN_00007800(uVar7 & 0xff,0x10,0x1e);
      FUN_00002cfc(uVar7 & 0xff,0x20);
      puVar10 = puVar10 + 0xb;
    }
  }
LAB_00002108:
  pcVar6 = (char *)(iVar3 + 0x31);
  for (uVar7 = 0; uVar7 != 2; uVar7 = uVar7 + 1) {
    if (*pcVar6 != '\0') {
      FUN_00008548(uVar7 & 0xff);
    }
    pcVar6 = pcVar6 + 0x1cc;
  }
  return 1;
}

