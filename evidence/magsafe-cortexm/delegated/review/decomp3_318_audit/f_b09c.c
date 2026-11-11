
void FUN_0000b09c(int param_1,int param_2,code *param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint local_24;
  undefined1 local_20;
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  
  FUN_00002938();
  iVar2 = DAT_0000b198;
  bVar1 = true;
  if (*(char *)(*(int *)(DAT_0000b198 + 0x58) + 0x21) != '\0') {
    FUN_00002db0(1);
  }
  *(undefined1 *)(iVar2 + 0x69) = 1;
  iVar4 = DAT_0000b1a0;
  iVar3 = DAT_0000b19c;
  if (*(char *)(DAT_0000b19c + 0x3e) != '\x01') {
    *(undefined1 *)(DAT_0000b1a0 + 4) = 1;
  }
  if (*(char *)(iVar2 + 0x54) == '\0') {
    local_24 = (uint)*(byte *)(*(int *)(iVar2 + 0x58) + 0x20);
    if (local_24 == 0) {
      FUN_0000a4c0((uint *)(param_2 + 8),&local_24,auStack_18,auStack_1c);
      uVar5 = DAT_0000b188 & *(uint *)(param_2 + 8);
      local_24 = DAT_0000b190;
      if (uVar5 < 10) {
        local_24 = uVar5 * 0x400 + DAT_0000b18c;
      }
    }
    else {
      bVar1 = false;
    }
  }
  else {
    *(undefined1 *)(iVar2 + 0x54) = 0;
    *(undefined1 *)(iVar3 + param_1 * 0x1cc + 0x1bc) = 0;
    local_24 = *(uint *)(iVar2 + 0x50);
  }
  if (bVar1) {
    local_20 = 3;
    (*param_3)(param_1);
  }
  else {
    if ((*(uint *)(param_2 + 4) & DAT_0000b194 + 0xe) == DAT_0000b194) {
      FUN_0000a500(0);
      FUN_00006828();
    }
    else {
      if (*(char *)(iVar4 + 0x13) == '\x01') {
        FUN_00006828();
        *(undefined1 *)(iVar4 + 0x13) = 0;
      }
      FUN_0000a500(1);
    }
    *(undefined1 *)(iVar2 + 0x55) = 1;
    *(code **)(iVar4 + 0x5c) = param_3;
  }
  return;
}

