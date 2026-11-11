
void FUN_00009ddc(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_00009df4;
  *(int *)(DAT_00009df4 + 0x50) = *(int *)(DAT_00009df4 + 0x50) + 1;
  uVar2 = FUN_00001460(iVar1 + 0x38,0x1c);
  *(undefined4 *)(iVar1 + 0x54) = uVar2;
  return;
}

