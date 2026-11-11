
void FUN_000078ac(uint param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_00007918 + param_1 * 0x1cc;
  if (*(char *)(iVar3 + 0xe) == '\x01') {
    iVar2 = *(int *)(DAT_0000791c + param_1 * 4);
    *(uint *)(iVar2 + 0x18c) =
         (*(uint *)(iVar2 + 0x18c) & 0xfffffffb) + (uint)(*(char *)(iVar3 + 0x1a) != '\0') * 4;
    FUN_00008d54(param_1);
    FUN_00002ee8(param_1);
    if (*(char *)(iVar3 + 0x15) == '\x01') {
      uVar1 = 0xe;
    }
    else {
      uVar1 = 10;
    }
    *(undefined1 *)(iVar3 + 0x45) = uVar1;
    *(undefined4 *)(iVar3 + 0x48) = 4;
    if (param_1 < 2) {
      *(undefined1 *)(DAT_00007920 + param_1 * 0x88 + 0x73) = 0;
      return;
    }
  }
  else {
    *(undefined1 *)(iVar3 + 0x22) = 1;
  }
  return;
}

