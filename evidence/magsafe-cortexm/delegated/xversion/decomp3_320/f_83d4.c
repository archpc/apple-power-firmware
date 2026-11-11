
void FUN_000083d4(int param_1)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = *(int *)(DAT_00008434 + param_1 * 4);
  iVar2 = DAT_00008438 + param_1 * 0x5c;
  pbVar3 = (byte *)(iVar2 + 0x57);
  uVar4 = (uint)*(byte *)(iVar2 + 0x58);
  uVar5 = uVar4 + 8;
  while( true ) {
    if (uVar5 <= (uVar4 & 0xff)) {
      *(char *)(iVar2 + 0x58) = (*(char *)(iVar2 + 0x58) == '\0') * '\b';
      return;
    }
    if (*(byte *)(iVar2 + 0x56) <= *pbVar3) break;
    *(undefined4 *)(iVar2 + (uint)*pbVar3 * 4 + 0xc) =
         *(undefined4 *)(iVar1 + (uVar4 & 0xff) * 4 + 0x60);
    *pbVar3 = *pbVar3 + 1;
    uVar4 = uVar4 + 1;
  }
  return;
}

