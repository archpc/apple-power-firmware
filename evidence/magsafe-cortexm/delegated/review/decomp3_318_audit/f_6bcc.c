
void FUN_00006bcc(int param_1,byte *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = DAT_00006cd8 + param_1 * 0x88;
  *(undefined4 *)(iVar10 + 0x80) = 0;
  bVar1 = *param_2;
  if ((bVar1 < 3) && (*(char *)(iVar10 + 0x7c) != '\x01')) {
    iVar9 = iVar10 + (uint)bVar1 * 3;
    bVar2 = *(byte *)(iVar9 + 5);
    cVar3 = *(char *)(iVar9 + 6);
    pcVar4 = (char *)(iVar9 + 6);
    iVar5 = FUN_00002fd4(param_2,0,0,0x2000,DAT_00006cd4);
    if (iVar5 != 0) {
      *pcVar4 = '\0';
    }
    iVar6 = FUN_00002fd4(param_2,1,0,0x2000,DAT_00006cd4);
    if (iVar6 == 0) {
      uVar7 = (*(uint *)(param_2 + 4) & 0xfff) >> 9;
      *(byte *)(iVar10 + 0x70) = (byte)uVar7;
      if (((*pcVar4 == '\0') || (bVar2 != uVar7)) &&
         ((bVar2 != uVar7 || ((cVar3 != '\x01' && ((cVar3 != '\0' || (iVar5 == 0)))))))) {
        *(byte *)(iVar9 + 5) = (byte)uVar7;
        *pcVar4 = '\x01';
        iVar5 = FUN_00002fd4(param_2,0,0,0x20,DAT_00006cd4);
        if ((iVar5 == 0) || (*(char *)(iVar10 + 0x73) != '\x01')) {
          *(byte *)(iVar10 + 0x71) = bVar1;
          iVar5 = FUN_00002fd4(param_2,0,0,0x2000,DAT_00006cd4);
          if (iVar5 == 0) {
            uVar8 = 0x40;
          }
          else {
            uVar8 = 2;
          }
          *(undefined4 *)(iVar10 + 0x80) = uVar8;
          if (param_3 == 0) {
            *(byte *)(iVar9 + 5) = bVar2;
            *pcVar4 = cVar3;
          }
        }
      }
    }
    else {
      *(undefined4 *)(iVar10 + 0x80) = 2;
    }
  }
  return;
}

