
void FUN_0000315c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = DAT_0000319c + param_1 * 0x1cc;
  *(undefined1 *)(iVar2 + 0x22) = 0;
  (*(code *)**(undefined4 **)(iVar2 + 0x60))(param_1,10,0);
  FUN_00002f62(param_1,0);
  if (*(char *)(iVar2 + 0x15) == '\x01') {
    uVar1 = 2;
  }
  else {
    uVar1 = 5;
  }
  FUN_000031a0(param_1,uVar1);
  *(undefined4 *)(iVar2 + 0x48) = 4;
  return;
}

