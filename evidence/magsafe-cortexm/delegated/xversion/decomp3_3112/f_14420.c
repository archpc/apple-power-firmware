
void FUN_00014420(uint *param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  
  uVar4 = 0;
  FUN_00013df6(param_1,0,0x68);
  FUN_00013dc4(param_1 + 0x12,DAT_000144e8,0x20);
  uVar1 = DAT_000144ec;
  if (((param_2 < 0x100001) && (param_3 < 0x100001)) && (param_3 + param_2 < 0x100001)) {
    for (; uVar4 < param_3; uVar4 = uVar3 + uVar4) {
      uVar3 = param_3 - uVar4;
      if (0x7f < uVar3) {
        uVar3 = 0x80;
      }
      (*pcRam000003f0)(uVar1,param_2,uVar3);
      FUN_000143e4(param_1,uVar1,uVar3);
      param_2 = uVar3 + param_2;
    }
  }
  local_18[0] = 0x80;
  local_1c[0] = 0;
  uVar4 = *param_1;
  FUN_000143e4(param_1,local_18,1);
  while ((*param_1 != 0 && ((*param_1 & 0x1ff) != 0x1c0))) {
    FUN_000143e4(param_1,local_1c,1);
  }
  param_1[0xf] = 0;
  param_1[0x10] =
       uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18;
  FUN_000142ac(param_1,param_1 + 1);
  for (iVar2 = 0x48; iVar2 != 0x68; iVar2 = iVar2 + 4) {
    uVar4 = *(uint *)((int)param_1 + iVar2);
    *(uint *)((int)param_1 + iVar2) =
         uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18;
  }
  return;
}

