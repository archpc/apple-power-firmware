
void FUN_00008d54(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00008d8c + param_1 * 0x1cc;
  if (*(char *)(iVar2 + 0x15) == '\0') {
    iVar1 = *(int *)(DAT_00008d90 + param_1 * 4);
    *(uint *)(iVar1 + 0xff00) = *(uint *)(iVar1 + 0xff00) & 0xfffffff3;
    if (*(char *)(iVar2 + 0x16) == '\x03') {
      *(uint *)(iVar1 + 0xff00) = *(uint *)(iVar1 + 0xff00) | 8;
      return;
    }
  }
  return;
}

