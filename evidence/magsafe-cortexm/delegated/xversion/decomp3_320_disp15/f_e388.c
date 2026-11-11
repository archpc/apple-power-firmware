
undefined4 FUN_0000e388(undefined1 param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint extraout_r3;
  uint extraout_r3_00;
  uint uVar4;
  undefined2 local_30;
  undefined1 local_2e;
  undefined1 local_2d;
  int *local_2c;
  undefined4 local_28;
  undefined2 *local_24;
  
  uVar2 = *(uint *)(param_2 + 8);
  uVar4 = *(uint *)(param_2 + 0xc);
  uVar3 = (uVar4 & 0x7ffffff) >> 0x18;
  if ((uVar3 == 0) && ((uVar2 & 0xf) == 1)) {
    local_24 = &local_30;
    local_30 = (undefined2)uVar4;
    uVar3 = (uVar2 & 0x7ff) >> 6;
    local_2e = (undefined1)uVar3;
    if (0x17 < uVar3) {
      local_2e = 0x18;
    }
    local_2c = param_3 + 1;
    local_28 = DAT_0000e4bc;
    software_interrupt(3);
    local_2d = param_1;
    uVar4 = FUN_0000e354(uVar2,param_3,local_2c,&local_28);
    FUN_0000ecb0();
    uVar3 = extraout_r3;
  }
  if (uVar3 != 1) {
    *param_3 = (uVar2 & 0xfffff80f) + 0x20;
    return 1;
  }
  uVar3 = (uVar4 & 0xffff) >> 10;
  if (0x28 < uVar3) {
    FUN_0000eca0();
    uVar3 = extraout_r3_00;
  }
                    /* WARNING: Could not recover jumptable at 0x0000e416. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(&PTR_FUN_0000e418)[uVar3])();
  return uVar1;
}

