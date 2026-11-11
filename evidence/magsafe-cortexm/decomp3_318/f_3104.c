
void FUN_00003104(int param_1)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  
  iVar2 = DAT_00003154 + param_1 * 0x1cc;
  if (*(char *)(iVar2 + 0x20) == '\x01') {
    if (param_1 != 1) {
      bVar1 = *(byte *)(iVar2 + 0x3e);
      goto LAB_0000314c;
    }
    bVar3 = 2;
    *(undefined1 *)(iVar2 + 0x3f) = 2;
  }
  else {
    if ((*(byte *)(DAT_00003158 + 4) & 1) == 0 && param_1 != 0) {
      bVar3 = 1;
    }
    else {
      bVar3 = 2;
    }
    *(byte *)(iVar2 + 0x3f) = bVar3;
    if (param_1 != 1) {
      return;
    }
  }
  bVar1 = *(byte *)(iVar2 + 0x40);
  if (bVar3 <= bVar1) {
    return;
  }
LAB_0000314c:
  *(byte *)(iVar2 + 0x3f) = bVar1;
  return;
}

