
void FUN_000078bc(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = DAT_00007900 + param_1 * 0x1cc;
  if (*(char *)(iVar1 + 0x15) == '\x01') {
    *(char *)(iVar1 + 0x35) = (char)param_2;
    if (*(char *)(iVar1 + 0x1c) == '\0') {
      FUN_00008c54(param_1,0,param_2);
      uVar2 = 1;
    }
    else {
      uVar2 = *(undefined1 *)(iVar1 + 0x1a);
    }
    FUN_00008c54(param_1,uVar2,param_2);
    FUN_00000b60(0x960);
  }
  return;
}

