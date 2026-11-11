
undefined4 FUN_0000d1ec(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [32];
  
  uVar2 = DAT_0000d278;
  piVar1 = DAT_0000d274;
  iVar7 = DAT_0000d270 + 0xf8;
  iVar5 = 0;
  while( true ) {
    if (iVar5 == 4) {
      return 0;
    }
    (*pcRam000003f0)(piVar1,iVar7,0x80);
    iVar3 = FUN_0000cdb8(piVar1);
    if (iVar3 == 0) break;
    iVar6 = *piVar1;
    FUN_0000d2f4(uVar2,iVar7);
    iVar3 = DAT_0000d270;
    iVar8 = -0xb4;
    do {
      if (iVar8 + 0x24 == 0) {
        return 7;
      }
      (*pcRam000003f0)(auStack_38,iVar8 + iVar3 + 0xb4,0x24);
      iVar4 = FUN_0000d27c(auStack_34);
      iVar8 = iVar8 + 0x24;
    } while (iVar4 == 0);
    iVar7 = iVar6 + 0x80 + iVar7;
    iVar5 = iVar5 + 1;
  }
  return 0;
}

