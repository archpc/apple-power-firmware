
void FUN_00012b24(void)

{
  uint uVar1;
  int iVar2;
  int in_stack_00000054;
  int in_stack_0000006c;
  int in_stack_00000070;
  int in_stack_00000074;
  
  if ((DAT_00012b80 + 1U & 0xffff) < (uint)*(ushort *)(in_stack_00000074 + 0x32)) {
    *(undefined2 *)(in_stack_00000074 + 0x32) = 0;
  }
  uVar1 = DAT_00012b8c;
  for (iVar2 = 0; iVar2 != 0x24; iVar2 = iVar2 + 2) {
    if ((uVar1 + *(ushort *)(in_stack_00000070 + iVar2 + 0x20) + 1 & 0xffff) < uVar1) {
      *(short *)(in_stack_00000070 + iVar2 + 0x20) = (short)DAT_00012b7c;
    }
  }
  if (1 < *(byte *)(in_stack_00000074 + in_stack_0000006c)) {
    *(undefined1 *)(in_stack_00000074 + in_stack_0000006c) = 0;
  }
  FUN_00000fd8(in_stack_00000054 + 0x20,0x7f,0);
  return;
}

