
bool FUN_00007ebc(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_00007f20 + param_1 * 0x1cc;
  if (*(char *)(iVar1 + 0x15) == '\0') {
    uVar2 = param_2 & 0xff;
    if (*(char *)(iVar1 + 0x2d) != '\x04') {
      if (3 < uVar2) {
        return false;
      }
      uVar3 = param_2 >> 8 & 0xff;
      if (3 < uVar3) {
        return false;
      }
      return uVar2 != 0 || uVar3 != 0;
    }
    if ((2 < uVar2 - 1) && (2 < (param_2 >> 8 & 0xff) - 1)) {
      return false;
    }
  }
  else if ((((param_2 & 0xff) != 1) && ((param_2 & 0xff00) != 0x100)) && ((param_2 & 0xffff) != 0))
  {
    return false;
  }
  return true;
}

