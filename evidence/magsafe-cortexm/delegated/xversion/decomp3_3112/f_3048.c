
void FUN_00003048(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_00003080 + param_1 * 0x1cc;
  if ((*(char *)(iVar1 + 0x15) == '\0') && (*(char *)(iVar1 + 0x175) != '\0')) {
    FUN_0000c78c(param_1,0x4d,400,DAT_00003084);
    FUN_0000c88c(param_1,0xa1);
    return;
  }
  return;
}

