
void FUN_0000c730(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_0000c778 + param_1 * 0x30;
  *(undefined1 *)(iVar2 + 10) = 1;
  iVar1 = FUN_0000c8d4(param_1,0x99);
  if (iVar1 != 0) {
    FUN_0000c88c(param_1,0x99);
  }
  iVar1 = DAT_0000c77c;
  *(undefined4 *)(DAT_0000c77c + param_1 * 0x14) = DAT_0000c780;
  *(undefined1 *)(iVar2 + 0x2b) = 0;
  *(undefined1 *)(DAT_0000c784 + 0x19) = 0;
  iVar1 = iVar1 + param_1 * 0x14;
  *(undefined4 *)(iVar1 + 0x10) = 1;
  *(int *)(iVar1 + 0xc) = iVar2;
  *(undefined4 *)(iVar1 + 8) = DAT_0000c788;
  *(undefined4 *)(iVar1 + 4) = 0;
  *(undefined2 *)(iVar2 + 0x28) = 0;
  return;
}

