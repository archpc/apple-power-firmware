
undefined4 FUN_00008b80(int param_1)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  
  uVar1 = DAT_00008bd8;
  iVar2 = *(int *)(DAT_00008be4 + param_1 * 4);
  *(uint *)(iVar2 + 0x118) = DAT_00008bd8;
  *(uint *)(iVar2 + 0x128) = *(uint *)(iVar2 + 0x128) | uVar1;
  *(undefined4 *)(iVar2 + 0xfc) = DAT_00008bdc;
  FUN_00008b1c();
  uVar1 = DAT_00008be0;
  cVar3 = '\n';
  while ((cVar3 != '\0' && ((*(uint *)(iVar2 + 0xa4) & uVar1) != 0))) {
    FUN_00000b60(0x1e0);
    cVar3 = cVar3 + -1;
  }
  if ((*(uint *)(iVar2 + 0xa4) & uVar1) != 0) {
    return 0xf;
  }
  *(uint *)(iVar2 + 0xf4) = *(uint *)(iVar2 + 0xf4) | 0x40000;
  return 0;
}

