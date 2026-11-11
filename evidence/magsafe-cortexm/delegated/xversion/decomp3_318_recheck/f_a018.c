
undefined4 FUN_0000a018(uint param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  if ((param_1 & 0xfff) == 0) {
    for (; 0 < param_2; param_2 = param_2 + iVar4) {
      if (((param_1 & 0xffff) == 0) && (DAT_0000a08c < param_2)) {
        iVar3 = DAT_0000a08c + 1;
        uVar1 = 0xd8;
        iVar4 = DAT_0000a090;
      }
      else {
        bVar5 = (param_1 & DAT_0000a088) == 0;
        uVar2 = DAT_0000a084;
        iVar4 = DAT_0000a098;
        if (bVar5 && (int)DAT_0000a088 < param_2) {
          uVar2 = DAT_0000a088;
          iVar4 = DAT_0000a094;
        }
        iVar3 = uVar2 + 1;
        if (bVar5 && (int)DAT_0000a088 < param_2) {
          uVar1 = 0x52;
        }
        else {
          uVar1 = 0x20;
        }
      }
      FUN_00009fe0(uVar1,param_1);
      param_1 = param_1 + iVar3;
    }
    return 0;
  }
  return 1;
}

