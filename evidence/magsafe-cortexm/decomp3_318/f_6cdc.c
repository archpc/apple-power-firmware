
void FUN_00006cdc(uint param_1,int param_2)

{
  int iVar1;
  
  if (param_1 < 2) {
    iVar1 = DAT_00006cfc + param_1 * 0x88;
    *(char *)(iVar1 + 0x71) = (char)param_2;
    iVar1 = iVar1 + param_2 * 3;
    *(undefined1 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 6) = 0;
  }
  return;
}

