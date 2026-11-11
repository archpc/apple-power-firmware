
void FUN_00008fa8(undefined1 param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = DAT_00008fcc;
  bVar1 = *(byte *)(DAT_00008fcc + 6);
  *(undefined1 *)(DAT_00008fd0 + (uint)bVar1 + 0x28) = param_1;
  cVar2 = bVar1 + 1;
  *(char *)(iVar3 + 6) = cVar2;
  if (cVar2 == '\b') {
    FUN_00008ff4();
    *(undefined1 *)(iVar3 + 6) = 0;
  }
  return;
}

