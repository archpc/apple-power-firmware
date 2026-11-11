
undefined4 FUN_0000b9a0(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  uint uVar12;
  byte local_18 [4];
  
  iVar5 = DAT_0000ba7c;
  iVar4 = DAT_0000ba78;
  iVar3 = DAT_0000ba74;
  puVar6 = *(uint **)(*(int *)(DAT_0000ba74 + 0x4c) + 0x1c);
  while (*(char *)(iVar3 + 0x17) == '\0') {
    pcVar11 = (char *)(iVar4 + 0x2a);
    iVar10 = iVar5;
    for (uVar9 = 0; uVar9 != 2; uVar9 = uVar9 + 1) {
      FUN_00002204(uVar9 & 0xff);
      cVar1 = *pcVar11;
      *pcVar11 = '\0';
      if (cVar1 != '\0') {
        FUN_0000baa4(iVar10,cVar1,0);
      }
      iVar10 = iVar10 + 0x14;
      pcVar11 = pcVar11 + 0x30;
    }
    while( true ) {
      if (*(byte *)((int)puVar6 + 0xf9) == 0) break;
      uVar9 = 0;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        uVar9 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_00001150(puVar6 + 0x3e,local_18,DAT_0000ba80,puVar6);
      uVar7 = puVar6[local_18[0] + 0x2a];
      uVar12 = puVar6[local_18[0] + 0x1a];
      *(byte *)(puVar6[0x3f] + (uint)*(byte *)((int)puVar6 + 0xf9)) = local_18[0];
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        enableIRQinterrupts((uVar9 & 1) == 1);
      }
      puVar8 = puVar6 + 9;
      for (uVar9 = 0; uVar9 < *puVar6; uVar9 = uVar9 + 1) {
        (*(code *)puVar8[-8])(puVar6,uVar12,*puVar8,uVar7);
        puVar8 = puVar8 + 1;
      }
    }
    iVar10 = FUN_0000a7dc();
    if (iVar10 == 1) {
      software_interrupt(1);
    }
    else {
      FUN_000013bc(500);
    }
  }
  return 0;
}

