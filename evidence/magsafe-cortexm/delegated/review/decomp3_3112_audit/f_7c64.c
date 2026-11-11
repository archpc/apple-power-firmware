
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00007c64(int param_1,undefined2 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined2 *puVar5;
  uint uVar6;
  undefined4 uStack_30;
  undefined2 auStack_1c [2];
  undefined2 local_18 [2];
  
  local_18[0] = param_2;
  uVar6 = param_3 - 0x11U & 0xff;
  iVar4 = _LAB_00007d64 + param_1 * 0xb + uVar6;
  *(undefined1 *)(iVar4 + 8) = 0;
  cVar1 = *(char *)((int)local_18 + uVar6);
  iVar2 = FUN_00008be8(param_1);
  if (iVar2 != 0) {
    return;
  }
  uStack_30 = 0;
  iVar2 = iRam00007d68 + param_1 * 0x1cc;
  puVar5 = (undefined2 *)(iVar2 + 0x38);
  puVar3 = (undefined2 *)(iVar2 + 0x3a);
  if (*(char *)((int)puVar5 + uVar6) == cVar1) {
    *(char *)((int)puVar3 + uVar6) = cVar1;
    FUN_0000c88c(param_1,param_3);
    *(undefined1 *)(iVar4 + 8) = 1;
    return;
  }
  if (*(char *)((int)puVar3 + uVar6) == cVar1) {
    iVar2 = FUN_0000c8d4(param_1,param_3);
    if (iVar2 != 0) {
      return;
    }
    *(undefined1 *)((int)puVar5 + uVar6) = *(undefined1 *)((int)puVar3 + uVar6);
    return;
  }
  if ((*(char *)(iVar2 + 0x1c) != '\x01') || (3 < *(byte *)(iVar2 + 0x1f))) goto code_r0x00007d46;
  if ((*(char *)(iVar2 + 0x1c) != '\x01') || (*(char *)(iVar2 + 0x15) != '\x01')) {
    if ((*(char *)(iVar2 + 0x20) != '\x01') || (*(byte *)(iVar2 + 0x3e) < 2)) {
      uStack_30 = 0xb;
      goto code_r0x00007d46;
    }
    if (cVar1 == '\x02') {
      FUN_00000b60(0x960);
      auStack_1c[0] = FUN_00008778(param_1);
      if ((*(char *)((int)auStack_1c + (uint)*(byte *)(iVar2 + 0x1a)) == '\x02') &&
         (iVar2 = FUN_00008be8(param_1), iVar2 == 0)) {
        *puVar3 = param_2;
        *puVar5 = param_2;
        return;
      }
      uStack_30 = 0xb;
      goto code_r0x00007d46;
    }
  }
  uStack_30 = 2;
code_r0x00007d46:
  FUN_0000c880(param_1,param_3,uStack_30);
  *(char *)((int)puVar3 + uVar6) = cVar1;
  return;
}

