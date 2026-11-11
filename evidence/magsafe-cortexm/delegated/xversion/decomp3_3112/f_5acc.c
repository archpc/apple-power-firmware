
void FUN_00005acc(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = DAT_00005b10 + param_1 * 0xf0;
  if (*(char *)(iVar2 + 0xe4) != '\0') {
    return;
  }
  iVar4 = DAT_00005b14 + param_1 * 0x1cc;
  uVar3 = (*(uint *)(*(int *)(DAT_00005b10 + param_1 * 0xf0) + 4) & 0xff) >> 6;
  uVar1 = (undefined1)uVar3;
  *(undefined1 *)(iVar4 + 0x41) = uVar1;
  *(undefined1 *)(iVar2 + 0xe4) = 1;
  if (uVar3 < *(byte *)(iVar4 + 0x3e)) {
    *(undefined1 *)(iVar4 + 0x3e) = uVar1;
  }
  FUN_00006d00();
  return;
}

