
void FUN_0000c314(void)

{
  char cVar1;
  int iVar2;
  int *in_r3;
  
  iVar2 = DAT_0000c354;
  cVar1 = *(char *)(DAT_0000c354 + 10);
  *(undefined1 *)((int)in_r3 + 10) = 2;
  if ((*in_r3 == 1) && (*(char *)(in_r3[1] + 0x14) == '\x01')) {
    if ((*(char *)(iVar2 + 0x2b) != '\x01') && (cVar1 == '\x05')) {
      FUN_0000c4ac(1);
      return;
    }
    FUN_0000c3f8(1,*(char *)(iVar2 + 0x2b),100,0);
    in_r3[0xb] = 5;
  }
  return;
}

