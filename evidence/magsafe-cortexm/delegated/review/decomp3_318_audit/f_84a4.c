
void FUN_000084a4(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(DAT_0000853c + param_1 * 4);
  if (param_2 == 0) {
    uVar2 = 3;
  }
  else {
    uVar2 = (uint)*(byte *)(DAT_00008540 + param_1 * 0x1cc + 0x35);
  }
  *(uint *)(iVar3 + 0x18c) = *(uint *)(iVar3 + 0x18c) & 0xfffffeff;
  *(uint *)(iVar3 + 0x18c) = *(uint *)(iVar3 + 0x18c) | 0x10;
  uVar1 = DAT_00008538;
  *(uint *)(iVar3 + 0x18c) = *(uint *)(iVar3 + 0x18c) & DAT_00008538 + 0x20;
  uVar2 = (uint)*(byte *)(DAT_00008544 + uVar2 * 4);
  *(uint *)(iVar3 + 0x18c) = uVar2 << 9 | *(uint *)(iVar3 + 0x18c) | uVar2 << 5;
  *(uint *)(iVar3 + 0x114) = *(uint *)(iVar3 + 0x114) & uVar1;
  *(uint *)(iVar3 + 0x114) = *(uint *)(iVar3 + 0x114) | 0xa00;
  FUN_00000b60(0x3c0);
  *(undefined4 *)(iVar3 + 0x11c) = 0x70;
  *(uint *)(iVar3 + 300) = *(uint *)(iVar3 + 300) | 0x60;
  if (*(int *)(iVar3 + 0xa4) << 0xe < 0) {
    uVar2 = 0x20;
  }
  else {
    if (-1 < *(int *)(iVar3 + 0xa4) << 0xd) {
      return;
    }
    uVar2 = 0x40;
  }
  *(uint *)(iVar3 + 0x124) = *(uint *)(iVar3 + 0x124) | uVar2;
  return;
}

