
void FUN_000016ac(int *param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  for (; param_3 != 0; param_3 = param_3 + -1) {
    uVar1 = *param_2;
    iVar2 = param_1[0x11];
    param_1[0x11] = iVar2 + 1;
    *(undefined1 *)((int)(param_1 + 1) + iVar2) = uVar1;
    *param_1 = *param_1 + 8;
    if (param_1[0x11] == 0x40) {
      FUN_00001574(param_1,param_1 + 1);
      param_1[0x11] = 0;
    }
    param_2 = param_2 + 1;
  }
  return;
}

