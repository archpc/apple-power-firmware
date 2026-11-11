
void FUN_0000a84c(void)

{
  int iVar1;
  int iVar2;
  int in_r3;
  
  *(undefined1 *)(in_r3 + 0x14) = 2;
  FUN_0000a500(0);
  *(undefined1 *)(in_r3 + 0x121) = 0;
  FUN_00001f68(1);
  iVar1 = DAT_0000a894;
  *(undefined1 *)(DAT_0000a894 + 0x48) = 0xff;
  iVar2 = DAT_0000a898;
  *(undefined4 *)(DAT_0000a898 + 0x48) = 10;
  *(int *)(iVar2 + 0x44) = iVar1 + 0x48;
  *(undefined4 *)(iVar2 + 0x40) = DAT_0000a89c;
  *(undefined4 *)(iVar2 + 0x3c) = 0;
  *(undefined4 *)(iVar2 + 0x38) = DAT_0000a8a0;
  *(undefined1 *)(DAT_0000a8a4 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x4c) = 1;
  FUN_0000d5e0(0);
  return;
}

