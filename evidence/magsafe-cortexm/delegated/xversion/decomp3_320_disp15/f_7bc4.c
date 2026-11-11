
void FUN_00007bc4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_00007c48 + param_1 * 0x1cc;
  iVar3 = *(int *)(iVar1 + 0x60);
  iVar4 = param_2;
  FUN_00003008(param_1);
  FUN_00007d34(param_1,0);
  FUN_00007d34(param_1,1);
  iVar2 = *(int *)(DAT_00007c4c + param_1 * 4);
  *(uint *)(iVar2 + 400) = *(uint *)(iVar2 + 400) & 0xfffffbff;
  (**(code **)(iVar3 + 0x18))(param_1,0,*(code **)(iVar3 + 0x18),0x400,iVar4);
  (**(code **)(iVar3 + 0x18))(param_1,1);
  if (param_2 == 0) {
    (**(code **)(iVar3 + 0x10))(param_1,0);
    (**(code **)(iVar3 + 0x38))(param_1,0);
    FUN_0000cac8(param_1,0xf,0x18);
    *(undefined1 *)(iVar1 + 0x2d) = 0;
    *(undefined1 *)(iVar1 + 0x42) = 0;
    *(undefined4 *)(iVar1 + 0x4c) = 0;
    *(undefined1 *)(iVar1 + 0x1d) = 0;
    *(undefined1 *)(iVar1 + 0x1c) = 0;
    *(undefined1 *)(iVar1 + 0x19) = 1;
  }
  return;
}

