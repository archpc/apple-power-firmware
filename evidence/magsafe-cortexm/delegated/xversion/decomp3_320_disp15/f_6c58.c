
void FUN_00006c58(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = (undefined4 *)(DAT_00006cac + param_1 * 0x88);
  bVar1 = *(byte *)(puVar2 + 0x1d);
  uVar3 = (uint)bVar1;
  if (*(char *)((int)puVar2 + 0x73) == '\x01') {
    *(undefined1 *)((int)puVar2 + 0x73) = 0;
    FUN_0000cac8(param_1,4,5,param_4,param_4);
    if (uVar3 < 4) {
      *(byte *)((int)puVar2 + uVar3 * 3 + 4) = *(char *)((int)puVar2 + uVar3 * 3 + 4) + 1U & 7;
    }
    *(byte *)((int)puVar2 + 0x79) = bVar1;
    FUN_00008c8c(param_1);
    (*(code *)*puVar2)(param_1,param_2);
  }
  return;
}

