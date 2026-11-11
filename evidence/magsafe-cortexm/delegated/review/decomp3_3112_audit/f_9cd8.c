
void FUN_00009cd8(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar1 = DAT_00009d10;
  if (*(char *)(DAT_00009d10 + 8) == '\0') {
    iVar3 = FUN_0000cd2c();
    if (iVar3 < 0x51) {
      if (*(byte *)(iVar1 + 9) < 0x15) {
        cVar2 = *(byte *)(iVar1 + 9) + 1;
      }
      else {
        cVar2 = '\x15';
      }
      *(char *)(iVar1 + 9) = cVar2;
      return;
    }
  }
  else {
    *(undefined1 *)(DAT_00009d10 + 8) = 0;
  }
  if (*(byte *)(iVar1 + 9) < 0x14) {
    FUN_00000bac();
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000967c(7);
}

