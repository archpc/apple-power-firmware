
void FUN_00001680(uint *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint local_1c;
  undefined1 local_18;
  undefined3 uStack_17;
  
  _local_18 = CONCAT31((int3)((uint)param_4 >> 8),0x80);
  local_1c = param_3 & 0xffffff00;
  uVar3 = *param_1;
  puVar2 = (uint *)&local_18;
  do {
    FUN_00001648(param_1,puVar2,1);
    if ((*param_1 & 0x1ff) == 0x1c0) break;
    puVar2 = &local_1c;
  } while (*param_1 != 0);
  param_1[0xf] = 0;
  param_1[0x10] =
       uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
  FUN_00001520(param_1,param_1 + 1);
  for (iVar1 = 0x48; iVar1 != 0x68; iVar1 = iVar1 + 4) {
    uVar3 = *(uint *)((int)param_1 + iVar1);
    *(uint *)((int)param_1 + iVar1) =
         uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
  }
  return;
}

