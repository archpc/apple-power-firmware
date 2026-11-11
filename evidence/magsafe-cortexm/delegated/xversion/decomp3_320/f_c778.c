
void FUN_0000c778(int param_1,int param_2,code *param_3,int param_4)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_2 + param_4 * 4 + 8);
  iVar1 = DAT_0000c800 + param_1 * 0x30;
  if (*(char *)(*(int *)(iVar1 + 4) + 0x14) == '\x01') {
    uVar3 = (uVar3 & 0x3f) >> 4;
    if (uVar3 != 0) {
      if (uVar3 != 1) {
        return;
      }
      if (*(char *)(iVar1 + 10) == '\x02') {
        if (*(char *)(DAT_0000c800 + 0x2b) == '\x01') {
          return;
        }
        if (*(char *)(DAT_0000c800 + 10) != '\x05') {
          return;
        }
        uVar2 = 10;
      }
      else {
        uVar2 = 0xd;
      }
      *(undefined1 *)(iVar1 + 0x2a) = uVar2;
      return;
    }
    uVar2 = 0xc;
  }
  else if (*(char *)(iVar1 + 10) == '\x04') {
    if ((uVar3 & 0x3f) >> 4 != 0) {
      return;
    }
    uVar2 = 0xd;
  }
  else {
    if (*(char *)(iVar1 + 10) != '\x02') {
      return;
    }
    if ((uVar3 & 0x3f) >> 4 != 0) {
      return;
    }
    uVar2 = 10;
  }
  *(undefined1 *)(iVar1 + 0x2a) = uVar2;
  (*param_3)();
  return;
}

