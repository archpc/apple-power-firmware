
void FUN_00003100(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_00003138 + param_1 * 0x1cc;
  if ((*(char *)(iVar1 + 0x15) == '\0') && (*(char *)(iVar1 + 0x175) != '\0')) {
    FUN_0000c908(param_1,0x4d,400,DAT_0000313c);
    FUN_0000ca08(param_1,0xa1);
    return;
  }
  return;
}

