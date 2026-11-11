
void FUN_00007b7c(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = DAT_00007bbc + param_1 * 0x1cc;
  uVar2 = (undefined2)DAT_00007bb4;
  *(undefined2 *)(iVar1 + 0x3c) = uVar2;
  if (*(char *)(iVar1 + 0x15) != '\0') {
    uVar2 = (undefined2)DAT_00007bb8;
  }
  *(undefined2 *)(iVar1 + 0x3a) = uVar2;
  *(undefined2 *)(iVar1 + 0x38) = uVar2;
  FUN_0000cac8(param_1,0x11,0x14);
  *(undefined1 *)(DAT_00007bc0 + param_1 * 0xb + 1) = 0;
  return;
}

