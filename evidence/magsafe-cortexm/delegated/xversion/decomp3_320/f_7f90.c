
uint FUN_00007f90(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_24;
  undefined4 local_18;
  
  local_18 = 0;
  iVar1 = *(int *)(DAT_0000806c + param_1 * 4);
  if (param_2 == 0) {
    local_2c = 0x3000000;
    puVar4 = (uint *)(iVar1 + 0x17c);
    puVar6 = (uint *)(iVar1 + 0x180);
    local_30 = 0x18;
    local_24 = 0x100;
  }
  else {
    local_2c = 0x18000000;
    puVar4 = (uint *)(iVar1 + 0x184);
    puVar6 = (uint *)(iVar1 + 0x188);
    local_30 = 0x1b;
    local_24 = 0x200;
  }
  uVar2 = FUN_00000b70();
  uVar3 = *puVar6;
  *puVar6 = (param_3 & 3) * 0x20000 + 0x200;
  *puVar4 = *puVar4 | 1;
  for (; ((*puVar4 & 1) != 0 && (local_18 < 200)); local_18 = local_18 + 1) {
  }
  FUN_00000b80(0x60);
  uVar5 = *puVar4;
  *puVar6 = uVar3;
  FUN_00000b80(0x1e0);
  *(uint *)(iVar1 + 0x11c) = local_24;
  if (((*(uint *)(iVar1 + 300) & local_24) != 0) && (-1 < (int)uVar3)) {
    uVar3 = (*(uint *)(iVar1 + 0x114) & local_2c) >> local_30;
    if ((uVar3 == 1 && (*puVar6 & 0x8000) == 0) || (uVar3 == 2 && (*puVar6 & 0x8000) != 0)) {
      *(uint *)(iVar1 + 0x124) = *(uint *)(iVar1 + 0x124) | local_24;
    }
  }
  FUN_00000b78(uVar2);
  return uVar5 >> 0x10 & 0xff;
}

