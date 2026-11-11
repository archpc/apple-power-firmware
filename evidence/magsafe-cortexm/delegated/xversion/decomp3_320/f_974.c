
void FUN_00000974(uint param_1)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  
  if (param_1 == 0) {
    FUN_000014fc(0x30);
  }
  iVar1 = DAT_000009b0;
  bVar2 = 1;
  for (uVar5 = 0x1c; -1 < (int)uVar5; uVar5 = uVar5 - 4) {
    uVar3 = param_1 >> (uVar5 & 0xff) & 0xf;
    bVar4 = 1;
    if (uVar3 == 0) {
      bVar4 = ~bVar2;
    }
    if ((bool)(bVar4 & 1)) {
      FUN_000014fc(*(undefined1 *)(iVar1 + uVar3));
      bVar2 = 0;
    }
  }
  return;
}

