
void switchD_00004ee2::caseD_3(int param_1)

{
  int iVar1;
  ushort *unaff_r6;
  int unaff_r7;
  
  iVar1 = (**(code **)(*(int *)(DAT_000055ec + param_1 + 0x60) + 0x70))();
  if (iVar1 == 0) {
    iVar1 = unaff_r7 << 0x1a;
  }
  else {
    iVar1 = 0x3000000;
  }
  *(uint *)unaff_r6 = (uint)*unaff_r6 + iVar1;
  return;
}

