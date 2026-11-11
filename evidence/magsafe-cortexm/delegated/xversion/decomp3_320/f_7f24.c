
void FUN_00007f24(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = DAT_00007f64 + param_1 * 0x1cc;
  if (*(char *)(iVar1 + 0x2d) == '\x02') {
    iVar2 = *(byte *)(iVar1 + 8) - 1;
    if ((uint)*(byte *)(iVar1 + 0x15) == (iVar2 - (*(byte *)(iVar1 + 8) - 2)) - (uint)(iVar2 == 0))
    {
      uVar3 = 3;
      goto LAB_00007f5a;
    }
  }
  else {
    iVar1 = FUN_0000ca50(param_1,0x10);
    if (iVar1 != 0) {
      return;
    }
  }
  uVar3 = 4;
LAB_00007f5a:
  FUN_00007924(param_1,uVar3);
  return;
}

