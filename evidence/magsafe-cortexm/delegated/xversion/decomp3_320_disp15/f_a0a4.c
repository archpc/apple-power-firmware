
undefined4 FUN_0000a0a4(undefined1 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_20 [8];
  undefined1 local_18 [4];
  
  uVar1 = DAT_0000a148;
  uVar2 = 0;
  iVar3 = DAT_0000a14c + 0x30;
  do {
    if (uVar2 == 10) {
      return 0xffffffff;
    }
    *(undefined1 *)(uVar1 + 0x10) = 1;
    *(undefined1 **)(uVar1 + 0xc) = local_18;
    *(undefined2 *)(uVar1 + 8) = 0;
    *(undefined4 *)(uVar1 + 4) = 0;
    local_18[0] = param_1;
    FUN_00001334(iVar3,auStack_20);
    software_interrupt(0x41);
    FUN_00001378(iVar3,auStack_20);
    FUN_000013ac(DAT_0000a140);
    if ((uVar1 & 0xff) == 0) {
      *(undefined1 *)(uVar1 + 0x10) = 0;
      *(undefined4 *)(uVar1 + 0xc) = 0;
      *(short *)(uVar1 + 8) = (short)param_3;
      *(undefined4 *)(uVar1 + 4) = param_2;
      FUN_00001334(iVar3,auStack_20);
      software_interrupt(0x40);
      FUN_00001378(iVar3,auStack_20);
      if ((uVar1 & 0xff) == 0) {
        if (9 < uVar2) {
          return 0xffffffff;
        }
        return param_3;
      }
      FUN_000013ac(DAT_0000a144);
    }
    uVar2 = uVar2 + 1;
  } while( true );
}

