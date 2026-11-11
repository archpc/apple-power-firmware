
void FUN_00009094(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  
  lVar4 = FUN_00000e80();
  FUN_000090e0(0xaa);
  FUN_000090e0(0x80);
  FUN_0000910c(param_1);
  while( true ) {
    iVar2 = (int)((ulonglong)lVar4 >> 0x20);
    uVar3 = (uint)lVar4;
    if (lVar4 == 0) break;
    bVar1 = (byte)lVar4;
    if ((int)(-(uint)(0x7f < uVar3) - iVar2) < 0 !=
        (SBORROW4(0,iVar2) != SBORROW4(-iVar2,(uint)(0x7f < uVar3)))) {
      bVar1 = bVar1 | 0x80;
    }
    FUN_0000910c(bVar1,0x7f - uVar3);
    lVar4 = CONCAT44(iVar2 >> 7,(uVar3 >> 7) + iVar2 * 0x2000000);
  }
  return;
}

