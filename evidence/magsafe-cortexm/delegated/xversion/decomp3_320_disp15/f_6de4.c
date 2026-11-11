
void FUN_00006de4(uint param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = DAT_00006ec0;
  if (1 < param_1) {
    return;
  }
  bVar1 = *(byte *)(DAT_00006ec0 + param_1 * 0x1cc + 0x3e);
  iVar6 = *(int *)(DAT_00006ec4 + param_1 * 4);
  if (bVar1 < 2) {
    *(uint *)(iVar6 + 0x144) = *(uint *)(iVar6 + 0x144) & DAT_00006eb0;
    *(uint *)(iVar6 + 4) = *(uint *)(iVar6 + 4) & 0xfffffffc;
  }
  else {
    *(uint *)(iVar6 + 0x144) = *(uint *)(iVar6 + 0x144) | DAT_00006eb4;
  }
  uVar3 = *(uint *)(iVar6 + 0xe4) & DAT_00006eac;
  iVar2 = iVar2 + param_1 * 0x1cc;
  if (*(char *)(iVar2 + 0x10) != '\x02') {
    uVar4 = uVar3 + 0x6100;
    if (*(char *)(iVar2 + 0x10) != '\x01') goto LAB_00006e8c;
    if (*(char *)(iVar2 + 0x20) != '\0') {
      if (bVar1 < 2) {
        if (*(char *)(iVar2 + 0x14) != '\x01') goto LAB_00006e8c;
      }
      else if (*(char *)(iVar2 + 0x28) == '\0') goto LAB_00006e8c;
      if (*(char *)(iVar2 + 0x24) == '\0') {
        iVar5 = 99;
      }
      else {
        iVar5 = 0x67;
      }
      uVar4 = iVar5 << 8 | uVar3;
      goto LAB_00006e8c;
    }
    if ((*(char *)(iVar2 + 0x15) != '\x01') || ((1 < bVar1 && (*(char *)(iVar2 + 0x28) == '\0'))))
    goto LAB_00006e8c;
  }
  uVar4 = uVar3 | 0x6300;
LAB_00006e8c:
  *(uint *)(iVar6 + 0xe4) = uVar4;
  *(uint *)(iVar6 + 0xf4) =
       (uint)*(byte *)(iVar2 + 0x14) << 5 |
       (DAT_00006eb8 & *(uint *)(iVar6 + 0xf4)) + (uint)*(byte *)(iVar2 + 0x15) * 0x100 | 0x41;
  *(undefined4 *)(iVar6 + 0xf0) = DAT_00006ebc;
  return;
}

