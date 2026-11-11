
void FUN_00009944(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00009960;
  iVar2 = FUN_00001460(DAT_00009960 + 0x38,0x1c);
  if (iVar2 == *(int *)(iVar1 + 0x54)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000967c(0x11);
}

