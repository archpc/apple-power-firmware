
void FUN_000063e8(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_00003104();
  iVar2 = DAT_00006424 + param_1 * 0xf0;
  *(undefined1 *)(iVar2 + 0xd4) = 3;
  if (*(char *)(iVar2 + 0xe3) == '\x13') {
    uVar1 = 0x1c;
  }
  else {
    uVar1 = 0xd;
  }
  (*(code *)**(undefined4 **)(DAT_00006428 + param_1 * 0x1cc + 0x60))(param_1,uVar1,iVar2 + 0xd4);
  return;
}

