
void FUN_0000b64c(uint param_1,uint param_2,code *param_3)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint local_34 [4];
  uint local_24;
  undefined1 local_18;
  undefined1 local_17;
  
  uVar4 = param_2 & 0x1f;
  if (4 < uVar4 - 1) {
    return;
  }
  uVar2 = (param_2 & 0x7ff) >> 8;
  iVar3 = *(int *)(DAT_0000b704 + uVar4 * 4);
  FUN_00000170(local_34,*(undefined4 *)(DAT_0000b700 + uVar4 * 4),iVar3 << 2);
  pbVar1 = DAT_0000b70c;
  if (uVar4 == 5) {
    if (*DAT_0000b70c == param_1) {
      *(undefined1 *)(DAT_0000b710 + 0x1f) = 0;
      *pbVar1 = 0xff;
LAB_0000b6dc:
      if (uVar2 == 1) goto LAB_0000b6ee;
    }
  }
  else {
    if (uVar4 != 4) {
      if (uVar4 == 1) {
        local_24 = (local_24 & 0xfffffff) + (uint)*(byte *)(DAT_0000b708 + 0x5d) * 0x10000000;
      }
      goto LAB_0000b6ee;
    }
    if ((*DAT_0000b70c == 0xff) || (*DAT_0000b70c == param_1)) {
      *(undefined1 *)(DAT_0000b710 + 0x1f) = 0;
      *pbVar1 = (byte)param_1;
      goto LAB_0000b6dc;
    }
  }
  local_34[0] = uVar2 * 0x100 + (local_34[0] & 0xfffff83f) + 0x80;
LAB_0000b6ee:
  local_17 = 0;
  local_18 = (undefined1)iVar3;
  (*param_3)(param_1);
  return;
}

