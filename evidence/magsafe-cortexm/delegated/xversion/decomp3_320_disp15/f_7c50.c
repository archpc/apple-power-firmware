
void FUN_00007c50(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_00007c7c + param_1 * 0x1cc;
  if (*(char *)(iVar1 + 0x30) == '\x01') {
    *(undefined1 *)(iVar1 + 0x30) = 0;
    if (*(code **)(iVar1 + 0x68) != (code *)0x0) {
      (**(code **)(iVar1 + 0x68))();
      *(undefined4 *)(iVar1 + 0x68) = 0;
    }
  }
  return;
}

