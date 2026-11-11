
void FUN_0000781c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = DAT_00007850 + param_1 * 0x1cc;
  if ((*(char *)(iVar2 + 8) == '\x01') || (*(char *)(iVar2 + 1) == '\0')) {
    uVar1 = 4;
  }
  else {
    uVar1 = 3;
  }
  FUN_000077cc(param_1,uVar1);
  (*(code *)**(undefined4 **)(iVar2 + 0x60))(param_1,3,0);
  return;
}

