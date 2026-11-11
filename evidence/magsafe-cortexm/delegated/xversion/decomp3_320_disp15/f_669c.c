
void FUN_0000669c(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  *(undefined1 *)(DAT_00006740 + param_1 * 0xf0 + 0xa5) = 0;
  iVar2 = DAT_00006744 + param_1 * 0x1cc;
  *(undefined1 *)(iVar2 + 0x15b) = 0;
  *(undefined4 *)(iVar2 + 0x104) = 0;
  *(undefined1 *)(iVar2 + 0x19) = 0;
  if (param_1 < 2) {
    for (; uVar3 != 3; uVar3 = uVar3 + 1) {
      FUN_00006dc0(param_1,uVar3 & 0xff);
    }
    iVar1 = DAT_00006748 + param_1 * 0x88;
    *(undefined4 *)(iVar1 + 0x80) = 0;
    *(undefined1 *)(iVar1 + 0x84) = 0;
    *(undefined1 *)(iVar1 + 0x7c) = 0;
    *(undefined1 *)(iVar1 + 0x73) = 0;
  }
  FUN_00006de4(param_1);
  *(undefined1 *)(DAT_0000674c + param_1 * 0x5c + 0x55) = 0;
  uVar3 = DAT_0000673c;
  iVar1 = *(int *)(DAT_00006750 + param_1 * 4);
  *(uint *)(iVar1 + 0x118) = DAT_0000673c + 0x7f;
  *(undefined4 *)(iVar1 + 0x14c) = 0xe00;
  if (1 < *(byte *)(iVar2 + 0x3e)) {
    *(uint *)(iVar1 + 0x154) = *(uint *)(iVar1 + 0x154) | 0x200;
  }
  *(uint *)(iVar1 + 0x128) = *(uint *)(iVar1 + 0x128) | uVar3;
  return;
}

