
void FUN_00003358(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 8) {
    iVar1 = DAT_000033d0 + param_1 * 0xf0;
    if (*(char *)(iVar1 + 0xe1) == '\0') {
      FUN_000030c8(param_1);
      return;
    }
    *(undefined1 *)(iVar1 + 0xe1) = 0;
    (**(code **)(*(int *)(DAT_000033d4 + param_1 * 0x1cc + 0x60) + 0x10))(param_1,DAT_000033d8);
    uVar2 = DAT_000033cc;
  }
  else {
    if (param_2 == 7) {
      FUN_000031a0(param_1,3);
      return;
    }
    if (param_2 != 2) {
      return;
    }
    FUN_00006700(param_1);
    *(undefined1 *)(DAT_000033d0 + param_1 * 0xf0 + 0xe1) = 1;
    uVar2 = 0x1b;
  }
  FUN_00003038(param_1,9,uVar2);
  return;
}

