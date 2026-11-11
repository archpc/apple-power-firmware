
void FUN_00004708(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_2 != 8) {
    if (param_2 != 6) {
      if (param_2 != 2) {
        return;
      }
      FUN_000030f0(param_1,9,100);
      return;
    }
    iVar1 = FUN_0000639c(param_1,0x40);
    if (iVar1 != 0) {
      piVar2 = (int *)(DAT_00004768 + param_1 * 0xf0);
      iVar1 = DAT_0000476c + param_1 * 0x1cc;
      (**(code **)(*(int *)(iVar1 + 0x60) + 0x18))(param_1,*(undefined1 *)(iVar1 + 0x1b));
      *(undefined1 *)(iVar1 + 0x28) = 0;
      *(undefined1 *)(*piVar2 + 2) = 3;
      FUN_000064d0(param_1);
      return;
    }
  }
  FUN_00003140(param_1);
  return;
}

