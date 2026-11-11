
void FUN_000031ec(uint param_1,int param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  code *pcVar4;
  byte bVar5;
  undefined4 uVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  undefined4 uVar10;
  
  iVar3 = DAT_00003348;
  iVar9 = DAT_00003340 + param_1 * 0x1cc;
  cVar2 = *(char *)(iVar9 + 0x44);
  cVar1 = *(char *)(iVar9 + 0x15);
  if (param_2 - 3U < 3) {
    (*(code *)**(undefined4 **)(iVar9 + 0x60))
              (param_1,0x12,0,(code *)**(undefined4 **)(iVar9 + 0x60),param_2);
    if ((cVar2 != '\0') &&
       ((*(char *)(iVar9 + 0x21) == '\0' || ((param_2 != 3 && (cVar1 == '\0')))))) {
      FUN_000030c8(param_1);
      return;
    }
    FUN_00002f62(param_1,3);
    *(undefined1 *)(iVar9 + 0x2f) = 0;
    *(undefined4 *)(iVar9 + 100) = 0;
    if (cVar1 == '\x01') {
      uVar6 = 2;
    }
    else {
      uVar6 = 5;
    }
  }
  else {
    if (param_2 != 2) {
      return;
    }
    iVar7 = DAT_00003344 + param_1 * 0xf0;
    bVar5 = *(byte *)(iVar7 + 0xa4);
    pbVar8 = (byte *)(iVar7 + 0xa4);
    if (*(char *)(DAT_00003348 + param_1) == '\0') {
      bVar5 = bVar5 + 1;
      *pbVar8 = bVar5;
    }
    if (3 < bVar5) {
      *pbVar8 = 3;
      if ((cVar1 == '\x01') && (*(char *)(iVar9 + 0x21) != '\0')) {
        FUN_000030c8(param_1);
      }
      else {
        FUN_00006560(param_1);
      }
      FUN_00002f62(param_1,1);
      return;
    }
    if (*(char *)(iVar3 + param_1) == '\0') {
      FUN_00006730(param_1);
      if (cVar1 == '\0') {
        *(undefined1 *)(iVar9 + 0x19) = 1;
      }
    }
    else {
      *(undefined1 *)(iVar3 + param_1) = 0;
    }
    if (param_1 < 2) {
      uVar6 = FUN_00000b50();
      pcVar4 = DAT_0000334c;
      (*DAT_0000334c)(param_1);
      (*pcVar4)(param_1,4);
      uVar10 = 7;
      (*pcVar4)(param_1);
      FUN_00008b44(param_1);
      iVar9 = DAT_00003350 + param_1 * 0x88;
      *(undefined1 *)(iVar9 + 0x73) = 0;
      *(undefined4 *)(iVar9 + 0x80) = 0;
      *(undefined1 *)(iVar9 + 0x84) = 0;
      FUN_00000b58(uVar6);
      *(undefined1 *)(iVar9 + 0x74) = 5;
      FUN_0000c78c(param_1,uVar10,0x14,DAT_00003354);
      *(undefined1 *)(iVar9 + 0x73) = 1;
      iVar9 = FUN_00008b80(param_1);
      if (iVar9 == 0) {
        return;
      }
    }
    uVar6 = 1;
    *(undefined1 *)(iVar3 + param_1) = 1;
  }
  FUN_000031a0(param_1,uVar6);
  return;
}

