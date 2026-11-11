
void FUN_0000d4a8(undefined4 param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = DAT_0000d4f8;
  if (((param_3 < 0x40001) && (param_2 < 0x40001)) && (param_3 + param_2 < 0x40001)) {
    for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar3 + uVar2) {
      uVar3 = param_3 - uVar2;
      if (0x7f < uVar3) {
        uVar3 = 0x80;
      }
      (*pcRam000003f0)(uVar1,param_2,uVar3);
      FUN_00001648(param_1,uVar1,uVar3);
      param_2 = uVar3 + param_2;
    }
  }
  return;
}

