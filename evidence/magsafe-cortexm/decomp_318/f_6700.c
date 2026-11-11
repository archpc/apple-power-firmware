
void FUN_00006700(int param_1)

{
  int iVar1;
  bool bVar2;
  
  FUN_00006730();
  iVar1 = DAT_0000672c + param_1 * 0x1cc;
  (**(code **)(*(int *)(iVar1 + 0x60) + 0x18))(param_1,*(undefined1 *)(iVar1 + 0x1b));
  bVar2 = *(char *)(iVar1 + 0x15) == '\x01';
  *(bool *)(iVar1 + 0x28) = bVar2;
  *(bool *)(iVar1 + 0x14) = bVar2;
  return;
}

