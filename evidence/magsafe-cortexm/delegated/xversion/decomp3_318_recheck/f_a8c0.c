
void FUN_0000a8c0(void)

{
  short sVar1;
  char cVar2;
  int in_r3;
  
  cVar2 = '\a';
  *(undefined1 *)(in_r3 + 0x14) = 7;
  sVar1 = *DAT_0000a914;
  *DAT_0000a914 = sVar1 + -1;
  if (*(char *)(DAT_0000a918 + 0x2b) != '\x01') {
    cVar2 = *(char *)(DAT_0000a918 + 10);
  }
  if (sVar1 == 0) {
    if (cVar2 != '\x05') {
      FUN_0000a450(DAT_0000a910);
      return;
    }
  }
  else if ((cVar2 != '\x05') || (*(char *)(DAT_0000a91c + 0x1f) != '\x01')) {
    FUN_00001178(DAT_0000a90c,0,DAT_0000a920,0);
    return;
  }
  FUN_0000bcf4();
  return;
}

