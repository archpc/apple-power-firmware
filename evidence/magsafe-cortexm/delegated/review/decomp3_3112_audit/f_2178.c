
void FUN_00002178(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  
  iVar1 = DAT_00002200;
  pcVar4 = (char *)(DAT_000021f8 + 0x31);
  puVar3 = (undefined4 *)(DAT_000021fc + 0x4c);
  for (iVar5 = 0; iVar5 != 8; iVar5 = iVar5 + 4) {
    if (*pcVar4 != '\0') {
      iVar2 = *(int *)(iVar1 + iVar5);
      *(uint *)(iVar2 + 300) = *(uint *)(iVar2 + 300) & 0xffffff8f;
      *(undefined4 *)(iVar2 + 0x11c) = 0x70;
      if ((pcVar4[-0x15] == '\x01') && (pcVar4[-0x1c] == '\0')) {
        FUN_00000b50();
        *(undefined4 *)(iVar2 + 0x188) = DAT_000021f4;
        *(uint *)(iVar2 + 300) = *(uint *)(iVar2 + 300) & 0xfffffdff;
        *(undefined4 *)(iVar2 + 0x11c) = 0x200;
        *puVar3 = 0;
        FUN_00000b58();
      }
    }
    pcVar4 = pcVar4 + 0x1cc;
    puVar3 = puVar3 + 0x17;
  }
  return;
}

