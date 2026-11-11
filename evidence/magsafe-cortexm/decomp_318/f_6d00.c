
void FUN_00006d00(uint param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = DAT_00006ddc;
  if (1 < param_1) {
    return;
  }
  bVar1 = *(byte *)(DAT_00006ddc + param_1 * 0x1cc + 0x3e);
  iVar6 = *(int *)(DAT_00006de0 + param_1 * 4);
  if (bVar1 < 2) {
    *(uint *)(iVar6 + 0x144) = *(uint *)(iVar6 + 0x144) & DAT_00006dcc;
    *(uint *)(iVar6 + 4) = *(uint *)(iVar6 + 4) & 0xfffffffc;
  }
  else {
    *(uint *)(iVar6 + 0x144) = *(uint *)(iVar6 + 0x144) | DAT_00006dd0;
  }
  uVar3 = *(uint *)(iVar6 + 0xe4) & DAT_00006dc8;
  iVar2 = iVar2 + param_1 * 0x1cc;
  if (*(char *)(iVar2 + 0x10) != '\x02') {
    uVar4 = (int)&PTR_caseD_11_00006100 + uVar3;
    if (*(char *)(iVar2 + 0x10) != '\x01') goto LAB_00006da8;
    if (*(char *)(iVar2 + 0x20) != '\0') {
      if (bVar1 < 2) {
        if (*(char *)(iVar2 + 0x14) != '\x01') goto LAB_00006da8;
      }
      else if (*(char *)(iVar2 + 0x28) == '\0') goto LAB_00006da8;
      if (*(char *)(iVar2 + 0x24) == '\0') {
        iVar5 = 99;
      }
      else {
        iVar5 = 0x67;
      }
      uVar4 = iVar5 << 8 | uVar3;
      goto LAB_00006da8;
    }
    if ((*(char *)(iVar2 + 0x15) != '\x01') || ((1 < bVar1 && (*(char *)(iVar2 + 0x28) == '\0'))))
    goto LAB_00006da8;
  }
  uVar4 = uVar3 | 0x6300;
LAB_00006da8:
  *(uint *)(iVar6 + 0xe4) = uVar4;
  *(uint *)(iVar6 + 0xf4) =
       (uint)*(byte *)(iVar2 + 0x14) << 5 |
       (DAT_00006dd4 & *(uint *)(iVar6 + 0xf4)) + (uint)*(byte *)(iVar2 + 0x15) * 0x100 | 0x41;
  *(undefined4 *)(iVar6 + 0xf0) = DAT_00006dd8;
  return;
}

