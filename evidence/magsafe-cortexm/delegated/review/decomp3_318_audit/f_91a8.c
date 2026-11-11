
void FUN_000091a8(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint *puVar3;
  int iVar4;
  
  FUN_00001400(1,0x10);
  iVar4 = DAT_00009278;
  puVar2 = DAT_0000926c;
  uVar1 = DAT_00009268;
  if (*(char *)(DAT_00009278 + 0x26) == '\0') {
    *DAT_0000926c = 0x4000000;
    *puVar2 = *puVar2;
    puVar2[2] = 0;
    *puVar2 = *puVar2;
    puVar2[9] = 0xc;
    puVar2[0xe] = 1;
    puVar2[10] = 0x31;
    puVar2[5] = uVar1;
    puVar2[3] = 0x8000;
    *(undefined1 *)(iVar4 + 0x26) = 1;
  }
  FUN_00000b50();
  puVar3 = DAT_00009270;
  *DAT_00009270 = *DAT_00009270 | 8;
  FUN_00000b58();
  FUN_00000b50();
  puVar3[2] = 0x8000000;
  FUN_00000b58();
  puVar2[3] = 0;
  puVar2[5] = 0x4000;
  puVar2 = DAT_00009274;
  if (*(char *)(iVar4 + 0x27) == '\0') {
    *DAT_00009274 = 0x4000000;
    *puVar2 = *puVar2;
    puVar2[2] = 0;
    *puVar2 = *puVar2;
    puVar2[9] = 0xc;
    puVar2[0xe] = 1;
    puVar2[10] = 0x31;
    puVar2[5] = DAT_00009268;
    puVar2[3] = 0x8000;
    *(undefined1 *)(iVar4 + 0x27) = 1;
  }
  FUN_00000b50();
  puVar3 = DAT_00009270;
  *DAT_00009270 = *DAT_00009270 | 1;
  FUN_00000b58();
  FUN_00000b50();
  puVar3[2] = 0x1000000;
  FUN_00000b58();
  puVar2[3] = 0;
  puVar2[5] = 0x4000;
  return;
}

