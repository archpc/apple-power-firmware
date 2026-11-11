
void FUN_00002114(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar1 = DAT_0000219c;
  pcVar3 = (char *)(DAT_00002194 + 0x31);
  puVar4 = (undefined4 *)(DAT_00002198 + 0x4c);
  for (iVar5 = 0; iVar5 != 8; iVar5 = iVar5 + 4) {
    if (*pcVar3 != '\0') {
      iVar2 = *(int *)(iVar1 + iVar5);
      *(uint *)(iVar2 + 300) = *(uint *)(iVar2 + 300) & 0xffffff8f;
      *(undefined4 *)(iVar2 + 0x11c) = 0x70;
      if ((pcVar3[-0x15] == '\x01') && (pcVar3[-0x1c] == '\0')) {
        iVar2 = *(int *)(iVar1 + iVar5);
        FUN_00000b70();
        *(undefined4 *)(iVar2 + 0x188) = DAT_00002190;
        *(uint *)(iVar2 + 300) = *(uint *)(iVar2 + 300) & 0xfffffdff;
        *(undefined4 *)(iVar2 + 0x11c) = 0x200;
        *puVar4 = 0;
        FUN_00000b78();
      }
    }
    pcVar3 = pcVar3 + 0x1cc;
    puVar4 = puVar4 + 0x17;
  }
  return;
}

