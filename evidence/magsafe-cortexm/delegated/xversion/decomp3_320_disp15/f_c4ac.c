
void FUN_0000c4ac(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = *(char *)(*(int *)(DAT_0000c4e8 + param_1 * 0x30 + 4) + 0x14);
  if (cVar1 == '\x01') {
    uVar2 = 1;
  }
  else if (cVar1 == '\0') {
    uVar2 = 2;
  }
  else {
    uVar2 = 0;
  }
  FUN_0000c4ec(param_1,&stack0xfffffff0,uVar2);
  return;
}

