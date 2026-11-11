
int FUN_0000a704(void)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  
  if (*(char *)(DAT_0000a780 + 0xc) == '\0') {
    cVar2 = -1;
    if (*(char *)(DAT_0000a780 + 0xb) == '\0') {
      if (((*(char *)(DAT_0000a784 + 0x21) != '\0') && (*(char *)(DAT_0000a784 + 0x45) == '#')) &&
         (cVar2 = -1, *(char *)(DAT_0000a784 + 0x1ed) == '\0')) {
        piVar3 = (int *)(DAT_0000a784 + 0x4c);
        for (uVar4 = 0; uVar4 != 2; uVar4 = uVar4 + 1) {
          if ((*(char *)((int)piVar3 + -0x1b) != '\0') &&
             (((*piVar3 != 0 || (piVar3[-1] != 0)) ||
              (iVar1 = FUN_0000c8ac(uVar4 & 0xff,0x11,0x13), iVar1 != 0)))) goto LAB_0000a73a;
          piVar3 = piVar3 + 0x73;
        }
        cVar2 = '\x01';
      }
    }
  }
  else {
    cVar2 = '\x01';
  }
LAB_0000a73a:
  return (int)cVar2;
}

