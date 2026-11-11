
undefined4 FUN_0000f134(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 unaff_r5;
  undefined4 unaff_r6;
  
  iVar2 = FUN_0000ceb8(&stack0xfffffff0);
  if ((((iVar2 == 0) && (iVar2 = FUN_0000cfc8(unaff_r5), iVar2 == 0)) &&
      (iVar2 = FUN_0000d1ec(), iVar2 == 0)) && (iVar2 = FUN_0000cd38(), iVar2 == 0)) {
    *(undefined1 *)(DAT_0000f190 + 4) = 5;
    (*pcRam000003f0)(&stack0xfffffff4,DAT_0000f18c,4);
    uVar1 = 0;
  }
  else {
    uVar1 = (undefined1)iVar2;
    *(undefined1 *)(DAT_0000f190 + 4) = 6;
    unaff_r6 = 0;
  }
  iVar2 = DAT_0000f194;
  *(undefined1 *)(DAT_0000f194 + 0x21) = uVar1;
  *(undefined4 *)(iVar2 + 0x74) = unaff_r6;
  return 0;
}

