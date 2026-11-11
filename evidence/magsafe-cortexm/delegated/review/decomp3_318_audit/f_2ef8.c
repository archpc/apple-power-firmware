
void FUN_00002ef8(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  
  *(undefined1 *)(DAT_00002f44 + param_1 * 0xf0 + 0xe4) = 0;
  uVar1 = 2;
  if (*(char *)(DAT_00002f48 + 4) == '\0') {
    uVar1 = 1;
  }
  uVar2 = 2;
  if (param_1 != 0) {
    uVar2 = uVar1;
  }
  iVar3 = DAT_00002f4c + param_1 * 0x1cc;
  *(undefined1 *)(iVar3 + 0x40) = uVar2;
  *(undefined1 *)(iVar3 + 0x3e) = uVar2;
  *(undefined1 *)(iVar3 + 0x27) = 1;
  uVar1 = 2;
  if (param_1 != 1) {
    uVar1 = uVar2;
  }
  *(undefined1 *)(iVar3 + 0x3f) = uVar1;
  return;
}

