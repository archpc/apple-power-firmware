
undefined4 FUN_0000f2f4(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 unaff_r5;
  undefined4 unaff_r6;
  
  iVar2 = FUN_0000d0c8(&stack0xfffffff0);
  if ((((iVar2 == 0) && (iVar2 = FUN_0000d1d8(unaff_r5), iVar2 == 0)) &&
      (iVar2 = FUN_0000d3f4(), iVar2 == 0)) && (iVar2 = FUN_0000cf48(), iVar2 == 0)) {
    *(undefined1 *)(DAT_0000f350 + 4) = 5;
    (*pcRam000003f0)(&stack0xfffffff4,DAT_0000f34c,4);
    uVar1 = 0;
  }
  else {
    uVar1 = (undefined1)iVar2;
    *(undefined1 *)(DAT_0000f350 + 4) = 6;
    unaff_r6 = 0;
  }
  iVar2 = DAT_0000f354;
  *(undefined1 *)(DAT_0000f354 + 0x29) = uVar1;
  *(undefined4 *)(iVar2 + 0x70) = unaff_r6;
  return 0;
}

