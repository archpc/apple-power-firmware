
void FUN_000016e4(uint *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint local_1c;
  undefined1 local_18;
  undefined3 uStack_17;
  
  _local_18 = CONCAT31((int3)((uint)param_4 >> 8),0x80);
  local_1c = param_3 & 0xffffff00;
  uVar2 = *param_1;
  FUN_000016ac(param_1,&local_18,1,param_4,param_2);
  while ((*param_1 != 0 && ((*param_1 & 0x1ff) != 0x1c0))) {
    FUN_000016ac(param_1,&local_1c,1);
  }
  param_1[0xf] = 0;
  param_1[0x10] =
       uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18;
  FUN_00001574(param_1,param_1 + 1);
  for (iVar1 = 0x48; iVar1 != 0x68; iVar1 = iVar1 + 4) {
    uVar2 = *(uint *)((int)param_1 + iVar1);
    *(uint *)((int)param_1 + iVar1) =
         uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18;
  }
  return;
}

