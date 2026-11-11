
void FUN_000032a4(int param_1,int param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  
  iVar3 = DAT_00003394;
  iVar8 = DAT_0000338c + param_1 * 0x1cc;
  cVar2 = *(char *)(iVar8 + 0x44);
  cVar1 = *(char *)(iVar8 + 0x15);
  if (param_2 - 3U < 3) {
    (*(code *)**(undefined4 **)(iVar8 + 0x60))
              (param_1,0x12,0,(code *)**(undefined4 **)(iVar8 + 0x60),param_2);
    if ((cVar2 != '\0') &&
       ((*(char *)(iVar8 + 0x21) == '\0' || ((param_2 != 3 && (cVar1 == '\0')))))) {
      FUN_00003180(param_1);
      return;
    }
    FUN_0000301a(param_1,3);
    *(undefined1 *)(iVar8 + 0x2f) = 0;
    *(undefined4 *)(iVar8 + 100) = 0;
    if (cVar1 == '\x01') {
      uVar5 = 2;
    }
    else {
      uVar5 = 5;
    }
  }
  else {
    if (param_2 != 2) {
      return;
    }
    iVar6 = DAT_00003390 + param_1 * 0xf0;
    bVar4 = *(byte *)(iVar6 + 0xa4);
    pbVar7 = (byte *)(iVar6 + 0xa4);
    if (*(char *)(DAT_00003394 + param_1) == '\0') {
      bVar4 = bVar4 + 1;
      *pbVar7 = bVar4;
    }
    if (3 < bVar4) {
      *pbVar7 = 3;
      if ((*(char *)(iVar8 + 0x21) == '\0') || (cVar1 != '\x01')) {
        FUN_00006648();
      }
      else {
        FUN_00003180();
      }
      FUN_0000301a(param_1,1);
      return;
    }
    if (*(char *)(iVar3 + param_1) == '\0') {
      FUN_00006818();
      if (cVar1 == '\0') {
        *(undefined1 *)(iVar8 + 0x19) = 1;
      }
    }
    else {
      *(undefined1 *)(iVar3 + param_1) = 0;
    }
    iVar8 = FUN_00007288(param_1);
    if (iVar8 == 0) {
      return;
    }
    uVar5 = 1;
    *(undefined1 *)(iVar3 + param_1) = 1;
  }
  FUN_00003258(param_1,uVar5);
  return;
}

