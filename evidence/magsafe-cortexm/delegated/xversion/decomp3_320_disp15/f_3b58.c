
void FUN_00003b58(int param_1,int param_2)

{
  char cVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = DAT_00003bd0 + param_1 * 0xf0;
  cVar1 = *(char *)(iVar3 + 0xa6);
  if (param_2 != 8) {
    if (param_2 != 2) {
      return;
    }
    FUN_0000669c(param_1);
    if (cVar1 == '\0') {
      sVar2 = *(short *)(DAT_00003bd4 + param_1 * 0x1cc + 0x5c);
      if (sVar2 == 0) goto LAB_00003bc4;
      *(undefined1 *)(iVar3 + 0xe2) = 1;
    }
    else {
      sVar2 = 0x37;
    }
    FUN_000030f0(param_1,9,sVar2);
    return;
  }
  if (cVar1 == '\0') {
    if (*(char *)(iVar3 + 0xe2) != '\0') {
      *(undefined1 *)(iVar3 + 0xe2) = 0;
      FUN_00003258(param_1,0x10);
    }
  }
  else {
    *(undefined1 *)(iVar3 + 0xa6) = 0;
  }
LAB_00003bc4:
  FUN_00003258(param_1,0x10);
  return;
}

