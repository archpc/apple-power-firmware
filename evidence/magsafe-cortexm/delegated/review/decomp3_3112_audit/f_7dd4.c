
void FUN_00007dd4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = DAT_00007e20 + param_1 * 0x1cc;
  if (*(char *)(iVar1 + 0x2d) == '\x02') {
    uVar3 = 3;
    uVar2 = 3;
    if (*(char *)(iVar1 + 0x15) != '\0') {
      uVar2 = 4;
    }
    if (*(char *)(iVar1 + 0x15) != '\x01') {
      uVar3 = 4;
    }
    if (*(char *)(iVar1 + 8) != '\x01') {
      uVar2 = uVar3;
    }
  }
  else {
    iVar1 = FUN_0000c8d4(param_1,0x10);
    if (iVar1 != 0) {
      return;
    }
    uVar2 = 4;
  }
  FUN_000077cc(param_1,uVar2);
  return;
}

