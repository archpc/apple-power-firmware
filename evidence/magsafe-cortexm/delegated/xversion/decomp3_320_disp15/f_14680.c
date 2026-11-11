
void FUN_00014680(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = DAT_000146b4;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    uVar1 = *param_1;
    iVar3 = piVar2[0x11];
    piVar2[0x11] = iVar3 + 1;
    *(undefined1 *)((int)piVar2 + iVar3 + 4) = uVar1;
    *piVar2 = *piVar2 + 8;
    if (piVar2[0x11] == 0x40) {
      FUN_00014550();
      piVar2[0x11] = 0;
    }
    param_1 = param_1 + 1;
  }
  return;
}

