
undefined4 FUN_0000a09c(undefined1 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 auStack_20 [8];
  undefined1 local_18 [4];
  
  uVar2 = DAT_0000a13c;
  uVar1 = DAT_0000a138;
  uVar3 = 0;
  do {
    if (uVar3 == 10) {
      return 0xffffffff;
    }
    *(undefined1 *)(uVar1 + 0x10) = 1;
    *(undefined1 **)(uVar1 + 0xc) = local_18;
    *(undefined2 *)(uVar1 + 8) = 0;
    *(undefined4 *)(uVar1 + 4) = 0;
    local_18[0] = param_1;
    FUN_0000131c(uVar2,auStack_20);
    software_interrupt(0x41);
    FUN_00001360(uVar2,auStack_20);
    FUN_000013bc(DAT_0000a130);
    if ((uVar1 & 0xff) == 0) {
      *(undefined1 *)(uVar1 + 0x10) = 0;
      *(undefined4 *)(uVar1 + 0xc) = 0;
      *(short *)(uVar1 + 8) = (short)param_3;
      *(undefined4 *)(uVar1 + 4) = param_2;
      FUN_0000131c(uVar2,auStack_20);
      software_interrupt(0x40);
      FUN_00001360(uVar2,auStack_20);
      if ((uVar1 & 0xff) == 0) {
        if (9 < uVar3) {
          return 0xffffffff;
        }
        return param_3;
      }
      FUN_000013bc(DAT_0000a134);
    }
    uVar3 = uVar3 + 1;
  } while( true );
}

