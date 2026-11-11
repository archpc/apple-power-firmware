
void FUN_00009dec(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_00009e04;
  *(int *)(DAT_00009e04 + 0x70) = *(int *)(DAT_00009e04 + 0x70) + 1;
  uVar2 = FUN_0000140c(iVar1 + 0x58,0x1c);
  *(undefined4 *)(iVar1 + 0x74) = uVar2;
  return;
}

