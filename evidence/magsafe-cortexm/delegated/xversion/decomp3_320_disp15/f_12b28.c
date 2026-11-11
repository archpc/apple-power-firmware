
void FUN_00012b28(void)

{
  uint uVar1;
  int iVar2;
  int unaff_r5;
  short unaff_r6;
  int in_stack_00000054;
  int in_stack_0000006c;
  int in_stack_00000070;
  
  if ((ushort)(unaff_r6 + 1U) < *(ushort *)(unaff_r5 + 0x32)) {
    *(undefined2 *)(unaff_r5 + 0x32) = 0;
  }
  uVar1 = DAT_00012b8c;
  for (iVar2 = 0; iVar2 != 0x24; iVar2 = iVar2 + 2) {
    if ((uVar1 + *(ushort *)(in_stack_00000070 + iVar2 + 0x20) + 1 & 0xffff) < uVar1) {
      *(short *)(in_stack_00000070 + iVar2 + 0x20) = (short)DAT_00012b7c;
    }
  }
  if (1 < *(byte *)(unaff_r5 + in_stack_0000006c)) {
    *(undefined1 *)(unaff_r5 + in_stack_0000006c) = 0;
  }
  FUN_00000fd8(in_stack_00000054 + 0x20,0x7f,0);
  return;
}

