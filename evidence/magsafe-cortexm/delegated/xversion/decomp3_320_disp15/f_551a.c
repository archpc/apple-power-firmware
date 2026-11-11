
void switchD_00004ee2::caseD_4(void)

{
  int iVar1;
  code *in_r3;
  int unaff_r5;
  ushort *unaff_r6;
  int unaff_r7;
  
  iVar1 = (*in_r3)();
  if (iVar1 == 0) {
    iVar1 = unaff_r7 << 0x1a;
  }
  else {
    iVar1 = unaff_r5 << 0x18;
  }
  *(uint *)unaff_r6 = (uint)*unaff_r6 + iVar1;
  return;
}

