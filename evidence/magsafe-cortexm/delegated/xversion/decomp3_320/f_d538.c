
undefined4 FUN_0000d538(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar1 = param_1[1];
  if (((uVar1 < 0x20001) && (uVar2 = param_1[2], uVar2 < 0x20001)) && (uVar2 + uVar1 < 0x20001)) {
    uVar3 = *param_1;
    FUN_00001500(uVar3);
    FUN_00001648(uVar3,uVar1,uVar2);
    FUN_00001680(uVar3);
    *(undefined1 *)(DAT_0000d574 + 0x2b) = 0;
  }
  return 0;
}

