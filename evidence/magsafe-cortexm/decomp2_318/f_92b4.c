
void FUN_000092b4(uint param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 == 2) || (param_2 == 0)) {
    if (*(byte *)(DAT_00009330 + 1) != 2) {
      *(undefined1 *)(DAT_00009330 + 1) = 2;
      FUN_00009340();
      return;
    }
  }
  else {
    if (*(byte *)(DAT_00009330 + 1) != param_1) {
      *(char *)(DAT_00009330 + 1) = (char)param_1;
      FUN_00009340(param_1);
    }
    if (param_1 == 0) {
      iVar3 = FUN_00009290(param_2,DAT_0000933c);
      iVar2 = DAT_00009338;
      *DAT_00009328 = iVar3 * (uint)*(ushort *)(DAT_00009338 + 0x32) >> 0xe & 0xffff;
      uVar1 = *(ushort *)(iVar2 + 0x30);
    }
    else {
      if (param_1 != 1) {
        return;
      }
      iVar3 = FUN_00009290(param_2,DAT_00009334);
      iVar2 = DAT_00009338;
      *DAT_00009328 = iVar3 * (uint)*(ushort *)(DAT_00009338 + 0x36) >> 0xe & 0xffff;
      uVar1 = *(ushort *)(iVar2 + 0x34);
    }
    *DAT_0000932c = iVar3 * (uint)uVar1 >> 0xe & 0xffff;
  }
  return;
}

