
void FUN_00005bf0(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_00005c30 + param_1 * 0xf0;
  if (*(char *)(iVar2 + 0xe4) != '\0') {
    return;
  }
  iVar3 = DAT_00005c34 + param_1 * 0x1cc;
  bVar1 = *(byte *)(*(int *)(DAT_00005c30 + param_1 * 0xf0) + 4) >> 6;
  *(byte *)(iVar3 + 0x41) = bVar1;
  *(undefined1 *)(iVar2 + 0xe4) = 1;
  if (bVar1 < *(byte *)(iVar3 + 0x3e)) {
    *(byte *)(iVar3 + 0x3e) = bVar1;
  }
  FUN_00006de4();
  return;
}

