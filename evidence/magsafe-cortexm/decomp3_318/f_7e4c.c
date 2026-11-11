
uint FUN_00007e4c(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_18 = 0;
  iVar1 = *(int *)(DAT_00007f1c + param_1 * 4);
  if (param_2 == 0) {
    local_30 = 0x3000000;
    puVar3 = (uint *)(iVar1 + 0x17c);
    puVar5 = (uint *)(iVar1 + 0x180);
    local_34 = 0x18;
    local_1c = 0x100;
  }
  else {
    local_30 = 0x18000000;
    puVar3 = (uint *)(iVar1 + 0x184);
    puVar5 = (uint *)(iVar1 + 0x188);
    local_34 = 0x1b;
    local_1c = 0x200;
  }
  uVar2 = FUN_00000b50();
  uVar6 = *puVar5;
  *puVar5 = (param_3 & 3) * 0x20000 + 0x200;
  *puVar3 = *puVar3 | 1;
  for (; ((*puVar3 & 1) != 0 && (local_18 < 200)); local_18 = local_18 + 1) {
  }
  FUN_00000b60(0x60);
  uVar4 = *puVar3;
  *puVar5 = uVar6;
  FUN_00000b60(0x1e0);
  *(uint *)(iVar1 + 0x11c) = local_1c;
  if ((-1 < (int)uVar6) && ((*(uint *)(iVar1 + 300) & local_1c) != 0)) {
    uVar6 = (*(uint *)(iVar1 + 0x114) & local_30) >> local_34;
    if (((uVar6 == 1) && ((*puVar5 & 0x8000) == 0)) || ((uVar6 == 2 && ((*puVar5 & 0x8000) != 0))))
    {
      *(uint *)(iVar1 + 0x124) = *(uint *)(iVar1 + 0x124) | local_1c;
    }
  }
  FUN_00000b58(uVar2);
  return uVar4 >> 0x10 & 0xff;
}

