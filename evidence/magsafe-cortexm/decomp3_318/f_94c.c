
void FUN_0000094c(uint param_1)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    FUN_00001550(0x30);
  }
  iVar1 = DAT_00000984;
  bVar2 = 1;
  for (uVar4 = 0x1c; -1 < (int)uVar4; uVar4 = uVar4 - 4) {
    uVar3 = param_1 >> (uVar4 & 0xff) & 0xf;
    if ((uVar3 != 0) || ((bool)(bVar2 ^ 1))) {
      FUN_00001550(*(undefined1 *)(iVar1 + uVar3));
      bVar2 = 0;
    }
  }
  return;
}

