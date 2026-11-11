
int FUN_0000a840(void)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  
  if (*(char *)(DAT_0000a8b8 + 0x13) == '\0') {
    cVar2 = -1;
    if ((((*(char *)(DAT_0000a8b8 + 0x12) != '\0') || (*(char *)(DAT_0000a8bc + 0x21) == '\0')) ||
        (*(char *)(DAT_0000a8bc + 0x45) != '#')) ||
       (cVar2 = -1, *(char *)(DAT_0000a8bc + 0x1ed) != '\0')) goto LAB_0000a876;
    piVar3 = (int *)(DAT_0000a8bc + 0x4c);
    for (uVar4 = 0; uVar4 != 2; uVar4 = uVar4 + 1) {
      if ((*(char *)((int)piVar3 + -0x1b) != '\0') &&
         (((*piVar3 != 0 || (piVar3[-1] != 0)) ||
          (iVar1 = FUN_0000ca88(uVar4 & 0xff,0x11,0x13), iVar1 != 0)))) {
        if (uVar4 < 2) goto LAB_0000a876;
        break;
      }
      piVar3 = piVar3 + 0x73;
    }
  }
  cVar2 = '\x01';
LAB_0000a876:
  return (int)cVar2;
}

