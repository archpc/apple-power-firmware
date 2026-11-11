
uint FUN_00002c9c(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_00002cd0 + param_1 * 0x1cc;
  if ((*(char *)(iVar1 + 0x20) == '\x01') && (0x15 < *(byte *)(iVar1 + 0x45))) {
    return (uint)*(ushort *)(iVar1 + 0x54);
  }
  uVar2 = (uint)*(ushort *)(iVar1 + 0x54);
  if (DAT_00002ccc <= *(ushort *)(iVar1 + 0x54)) {
    uVar2 = DAT_00002ccc;
  }
  return uVar2;
}

