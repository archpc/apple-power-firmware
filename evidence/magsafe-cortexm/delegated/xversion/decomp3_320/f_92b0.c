
void FUN_000092b0(void)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = DAT_0000938c;
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  *(uint *)(DAT_0000938c + 0x4c) = *(uint *)(DAT_0000938c + 0x4c) | 0x10;
  puVar3 = DAT_00009380;
  uVar2 = DAT_0000937c;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar6 & 1) == 1);
  }
  if (*(char *)(iVar5 + 0x2e) == '\0') {
    *DAT_00009380 = 0x4000000;
    *puVar3 = *puVar3;
    puVar3[2] = 0;
    *puVar3 = *puVar3;
    puVar3[9] = 0xc;
    puVar3[0xe] = 1;
    puVar3[10] = 0x31;
    puVar3[5] = uVar2;
    puVar3[3] = 0x8000;
    *(undefined1 *)(iVar5 + 0x2e) = 1;
  }
  FUN_00000b70();
  puVar4 = DAT_00009384;
  *DAT_00009384 = *DAT_00009384 | 8;
  FUN_00000b78();
  FUN_00000b70();
  puVar4[2] = 0x8000000;
  FUN_00000b78();
  puVar3[3] = 0;
  puVar3[5] = 0x4000;
  puVar3 = DAT_00009388;
  if (*(char *)(iVar5 + 0x2f) == '\0') {
    *DAT_00009388 = 0x4000000;
    *puVar3 = *puVar3;
    puVar3[2] = 0;
    *puVar3 = *puVar3;
    puVar3[9] = 0xc;
    puVar3[0xe] = 1;
    puVar3[10] = 0x31;
    puVar3[5] = DAT_0000937c;
    puVar3[3] = 0x8000;
    *(undefined1 *)(iVar5 + 0x2f) = 1;
  }
  FUN_00000b70();
  puVar4 = DAT_00009384;
  *DAT_00009384 = *DAT_00009384 | 1;
  FUN_00000b78();
  FUN_00000b70();
  puVar4[2] = 0x1000000;
  FUN_00000b78();
  puVar3[3] = 0;
  puVar3[5] = 0x4000;
  return;
}

