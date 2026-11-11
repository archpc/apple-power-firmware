
void FUN_000096f8(int param_1)

{
  byte bVar1;
  
  if (*(char *)(DAT_0000971c + 0x66) != '\0') {
    bVar1 = 0;
    if (param_1 != 0) {
      bVar1 = *(byte *)(DAT_00009720 + 0xf) | 0x80;
    }
    *(byte *)(DAT_00009720 + 0xf) = bVar1;
    FUN_00000f54(DAT_00009724 + 0x18);
  }
  return;
}

