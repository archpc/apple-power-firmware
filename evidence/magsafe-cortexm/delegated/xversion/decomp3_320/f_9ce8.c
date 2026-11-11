
void FUN_00009ce8(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar1 = DAT_00009d20;
  if (*(char *)(DAT_00009d20 + 0x23) == '\0') {
    iVar3 = FUN_0000ceb8();
    if (iVar3 < 0x51) {
      if (*(byte *)(iVar1 + 0x10) < 0x15) {
        cVar2 = *(byte *)(iVar1 + 0x10) + 1;
      }
      else {
        cVar2 = '\x15';
      }
      *(char *)(iVar1 + 0x10) = cVar2;
      return;
    }
  }
  else {
    *(undefined1 *)(DAT_00009d20 + 0x23) = 0;
  }
  if (*(byte *)(iVar1 + 0x10) < 0x14) {
    FUN_00000bcc();
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000975c(7);
}

