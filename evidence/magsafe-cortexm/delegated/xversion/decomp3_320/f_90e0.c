
void FUN_000090e0(undefined1 param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = DAT_00009104;
  bVar1 = *(byte *)(DAT_00009104 + 6);
  *(undefined1 *)(DAT_00009108 + (uint)bVar1 + 0x20) = param_1;
  cVar2 = bVar1 + 1;
  *(char *)(iVar3 + 6) = cVar2;
  if (cVar2 == '\b') {
    FUN_00009128();
    *(undefined1 *)(iVar3 + 6) = 0;
  }
  return;
}

