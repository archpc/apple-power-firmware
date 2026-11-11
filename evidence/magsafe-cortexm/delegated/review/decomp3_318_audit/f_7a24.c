
void FUN_00007a24(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = DAT_00007a64 + param_1 * 0x1cc;
  uVar2 = (undefined2)DAT_00007a5c;
  *(undefined2 *)(iVar1 + 0x3c) = uVar2;
  if (*(char *)(iVar1 + 0x15) != '\0') {
    uVar2 = (undefined2)DAT_00007a60;
  }
  *(undefined2 *)(iVar1 + 0x3a) = uVar2;
  *(undefined2 *)(iVar1 + 0x38) = uVar2;
  FUN_0000c8e8(param_1,0x11,0x14);
  *(undefined1 *)(DAT_00007a68 + param_1 * 0xb + 1) = 0;
  return;
}

