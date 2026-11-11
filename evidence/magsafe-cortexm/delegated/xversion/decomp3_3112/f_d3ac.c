
undefined4 FUN_0000d3ac(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar1 = param_1[1];
  if (((uVar1 < 0x20001) && (uVar2 = param_1[2], uVar2 < 0x20001)) && (uVar2 + uVar1 < 0x20001)) {
    uVar3 = *param_1;
    FUN_00001554(uVar3);
    FUN_000016ac(uVar3,uVar1,uVar2);
    FUN_000016e4(uVar3);
    *(undefined1 *)(DAT_0000d3e8 + 0x1b) = 0;
  }
  return 0;
}

