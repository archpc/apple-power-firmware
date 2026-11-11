
void FUN_00007db4(int param_1,undefined2 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined2 *puVar5;
  uint uVar6;
  undefined4 local_30;
  undefined2 local_1c [2];
  undefined2 local_18 [2];
  
  local_18[0] = param_2;
  uVar6 = param_3 - 0x11U & 0xff;
  iVar4 = DAT_00007eb4 + param_1 * 0xb + uVar6;
  *(undefined1 *)(iVar4 + 8) = 0;
  cVar1 = *(char *)((int)local_18 + uVar6);
  iVar2 = FUN_00008d2c(param_1);
  if (iVar2 != 0) {
    return;
  }
  local_30 = 0;
  iVar2 = DAT_00007eb8 + param_1 * 0x1cc;
  puVar5 = (undefined2 *)(iVar2 + 0x38);
  puVar3 = (undefined2 *)(iVar2 + 0x3a);
  if (*(char *)((int)puVar5 + uVar6) == cVar1) {
    *(char *)((int)puVar3 + uVar6) = cVar1;
    FUN_0000ca08(param_1,param_3);
    *(undefined1 *)(iVar4 + 8) = 1;
    return;
  }
  if (*(char *)((int)puVar3 + uVar6) == cVar1) {
    iVar2 = FUN_0000ca50(param_1,param_3);
    if (iVar2 != 0) {
      return;
    }
    *(undefined1 *)((int)puVar5 + uVar6) = *(undefined1 *)((int)puVar3 + uVar6);
    return;
  }
  if ((*(char *)(iVar2 + 0x1c) != '\x01') || (3 < *(byte *)(iVar2 + 0x1f))) goto LAB_00007e96;
  if ((*(char *)(iVar2 + 0x1c) != '\x01') || (*(char *)(iVar2 + 0x15) != '\x01')) {
    if ((*(char *)(iVar2 + 0x20) != '\x01') || (*(byte *)(iVar2 + 0x3e) < 2)) {
      local_30 = 0xb;
      goto LAB_00007e96;
    }
    if (cVar1 == '\x02') {
      FUN_00000b80(0x960);
      local_1c[0] = FUN_000088d4(param_1);
      if ((*(char *)((int)local_1c + (uint)*(byte *)(iVar2 + 0x1a)) == '\x02') &&
         (iVar2 = FUN_00008d2c(param_1), iVar2 == 0)) {
        *puVar3 = param_2;
        *puVar5 = param_2;
        return;
      }
      local_30 = 0xb;
      goto LAB_00007e96;
    }
  }
  local_30 = 2;
LAB_00007e96:
  FUN_0000c9fc(param_1,param_3,local_30);
  *(char *)((int)puVar3 + uVar6) = cVar1;
  return;
}

