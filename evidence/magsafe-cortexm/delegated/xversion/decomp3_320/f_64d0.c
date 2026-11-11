
void FUN_000064d0(int param_1)

{
  int iVar1;
  
  FUN_00006de4();
  iVar1 = DAT_00006510;
  FUN_00003024(param_1,4,*(undefined4 *)(DAT_00006510 + param_1 * 0xf0));
  iVar1 = iVar1 + param_1 * 0xf0;
  *(undefined1 *)(iVar1 + 0xd4) = 3;
  (*(code *)**(undefined4 **)(DAT_00006514 + param_1 * 0x1cc + 0x60))(param_1,0xf,iVar1 + 0xd4);
  FUN_00003258(param_1,0x23);
  return;
}

