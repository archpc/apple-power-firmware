
void FUN_00006450(int param_1)

{
  int iVar1;
  
  FUN_00006d00();
  iVar1 = DAT_00006490;
  FUN_00002f6c(param_1,4,*(undefined4 *)(DAT_00006490 + param_1 * 0xf0));
  iVar1 = iVar1 + param_1 * 0xf0;
  *(undefined1 *)(iVar1 + 0xd4) = 3;
  (*(code *)**(undefined4 **)(DAT_00006494 + param_1 * 0x1cc + 0x60))(param_1,0xf,iVar1 + 0xd4);
  FUN_000031a0(param_1,0x23);
  return;
}

