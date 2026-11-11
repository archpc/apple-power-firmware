
void FUN_00003398(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 8) {
    iVar1 = DAT_00003410 + param_1 * 0xf0;
    if (*(char *)(iVar1 + 0xe1) == '\0') {
      FUN_00003180(param_1);
      return;
    }
    *(undefined1 *)(iVar1 + 0xe1) = 0;
    (**(code **)(*(int *)(DAT_00003414 + param_1 * 0x1cc + 0x60) + 0x10))(param_1,DAT_00003418);
    uVar2 = DAT_0000340c;
  }
  else {
    if (param_2 == 7) {
      FUN_00003258(param_1,3);
      return;
    }
    if (param_2 != 2) {
      return;
    }
    FUN_000067e8(param_1);
    *(undefined1 *)(DAT_00003410 + param_1 * 0xf0 + 0xe1) = 1;
    uVar2 = 0x1b;
  }
  FUN_000030f0(param_1,9,uVar2);
  return;
}

