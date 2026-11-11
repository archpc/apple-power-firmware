
void FUN_0000b7c8(uint param_1,uint param_2,code *param_3)

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
  if (uVar4 == 0) {
    return;
  }
  if (5 < uVar4) {
    return;
  }
  uVar2 = (param_2 & 0x7ff) >> 8;
  iVar3 = *(int *)(DAT_0000b87c + uVar4 * 4);
  FUN_00000170(local_34,*(undefined4 *)(DAT_0000b878 + uVar4 * 4),iVar3 << 2);
  pbVar1 = DAT_0000b884;
  if (uVar4 == 5) {
    if (*DAT_0000b884 == param_1) {
      *(undefined1 *)(DAT_0000b888 + 0x27) = 0;
      *pbVar1 = 0xff;
LAB_0000b850:
      if (uVar2 == 1) goto LAB_0000b866;
    }
  }
  else {
    if (uVar4 != 4) {
      if (uVar4 == 1) {
        local_24 = (local_24 & 0xfffffff) + (uint)*(byte *)(DAT_0000b880 + 0x5d) * 0x10000000;
      }
      goto LAB_0000b866;
    }
    if ((*DAT_0000b884 == 0xff) || (*DAT_0000b884 == param_1)) {
      *(undefined1 *)(DAT_0000b888 + 0x27) = 0;
      *pbVar1 = (byte)param_1;
      goto LAB_0000b850;
    }
  }
  local_34[0] = (local_34[0] & 0xfffff83f) + uVar2 * 0x100 + 0x80;
LAB_0000b866:
  local_17 = 0;
  local_18 = (undefined1)iVar3;
  (*param_3)(param_1);
  return;
}

