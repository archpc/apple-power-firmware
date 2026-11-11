
void FUN_00009604(int param_1)

{
  byte bVar1;
  
  if (*(char *)(DAT_00009628 + 0x66) != '\0') {
    bVar1 = 0;
    if (param_1 != 0) {
      bVar1 = *(byte *)(DAT_0000962c + 7) | 0x80;
    }
    *(byte *)(DAT_0000962c + 7) = bVar1;
    FUN_00000f28(DAT_00009630 + 0x18);
  }
  return;
}

