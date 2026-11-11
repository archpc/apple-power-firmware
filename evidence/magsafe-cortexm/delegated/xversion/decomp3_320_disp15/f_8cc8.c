
undefined4 FUN_00008cc8(int param_1)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  
  uVar1 = DAT_00008d1c;
  iVar2 = *(int *)(DAT_00008d28 + param_1 * 4);
  *(uint *)(iVar2 + 0x118) = DAT_00008d1c;
  *(uint *)(iVar2 + 0x128) = *(uint *)(iVar2 + 0x128) | uVar1;
  *(undefined4 *)(iVar2 + 0xfc) = DAT_00008d20;
  FUN_00008c64();
  uVar1 = DAT_00008d24;
  cVar3 = '\n';
  while ((cVar3 != '\0' && ((*(uint *)(iVar2 + 0xa4) & uVar1) != 0))) {
    FUN_00000b80(0x1e0);
    cVar3 = cVar3 + -1;
  }
  if ((*(uint *)(iVar2 + 0xa4) & uVar1) != 0) {
    return 0xf;
  }
  *(uint *)(iVar2 + 0xf4) = *(uint *)(iVar2 + 0xf4) | 0x40000;
  return 0;
}

