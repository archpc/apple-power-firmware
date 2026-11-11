
void FUN_00003088(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_000030c4 + param_1 * 0x1cc;
  *(undefined1 *)(iVar1 + 0x20) = 0;
  FUN_0000c93c(param_1,0,0xe);
  if (*(char *)(iVar1 + 0x2e) != '\x05') {
    FUN_00002f62(param_1,0);
  }
  FUN_000031a0(param_1,1);
  *(undefined4 *)(iVar1 + 0x48) = 4;
  return;
}

