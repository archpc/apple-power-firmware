
bool FUN_00007d6c(int param_1,ushort param_2)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = DAT_00007dd0 + param_1 * 0x1cc;
  uVar1 = param_2 >> 8;
  if (*(char *)(iVar3 + 0x15) == '\0') {
    uVar4 = (uint)(byte)param_2;
    if (*(char *)(iVar3 + 0x2d) == '\x04') {
      if ((uVar4 - 1 < 3) || ((bVar2 = false, param_2 >> 10 == 0 && (uVar1 != 0)))) {
        return true;
      }
    }
    else {
      bVar2 = false;
      if ((uVar4 < 4) && (param_2 < 0x400)) {
        return uVar4 != 0 || uVar1 != 0;
      }
    }
  }
  else {
    bVar2 = param_2 == 0 || ((byte)param_2 == 1 || uVar1 == 1);
  }
  return bVar2;
}

