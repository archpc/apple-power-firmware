
void FUN_00005504(void)

{
  int iVar1;
  int unaff_r4;
  ushort *unaff_r6;
  int unaff_r7;
  
  iVar1 = (**(code **)(*(int *)(DAT_000055ec + unaff_r4 * 0x1cc + 0x60) + 0x70))();
  if (iVar1 == 0) {
    iVar1 = unaff_r7 << 0x1a;
  }
  else {
    iVar1 = 0x3000000;
  }
  *(uint *)unaff_r6 = (uint)*unaff_r6 + iVar1;
  return;
}

