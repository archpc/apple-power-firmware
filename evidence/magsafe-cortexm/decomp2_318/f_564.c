
uint FUN_00000564(int param_1,uint param_2,char *param_3,uint param_4)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  int iVar8;
  byte bVar9;
  undefined1 auStack_28 [19];
  undefined1 local_15;
  
  iVar8 = DAT_000006e0;
  if ((int)(param_4 << 0x16) < 0) {
    iVar8 = DAT_000006e4;
  }
  puVar7 = &local_15;
  bVar9 = 0;
  if (param_2 != 0) {
    uVar4 = (param_4 & 0x7fff) >> 10;
    bVar9 = 0;
    do {
      uVar5 = FUN_00000880(param_2,uVar4);
      *puVar7 = *(undefined1 *)(iVar8 + (param_2 - uVar5 * uVar4));
      puVar7 = puVar7 + -1;
      bVar9 = bVar9 + 1;
      bVar1 = uVar4 <= param_2;
      param_2 = uVar5;
    } while (bVar1);
  }
  if ((int)param_4 < 0) {
    for (; (uint)bVar9 < (param_4 >> 0x17 & 0xff); bVar9 = bVar9 + 1) {
      *puVar7 = 0x30;
      puVar7 = puVar7 + -1;
    }
  }
  if (bVar9 == 0) {
    *puVar7 = 0x30;
    puVar7 = puVar7 + -1;
    bVar9 = 1;
  }
  uVar5 = (uint)bVar9;
  uVar4 = uVar5;
  if (param_3 == (char *)0x0) {
    param_3 = (char *)0x0;
  }
  else {
    cVar2 = *param_3;
    if ((param_4 & 0x100) == 0) {
      if (cVar2 != '\0') {
        iVar8 = 0;
        do {
          iVar3 = iVar8 + 1;
          iVar8 = iVar8 + 1;
        } while (param_3[iVar3] != '\0');
        uVar4 = uVar5 + iVar8;
      }
    }
    else {
      while (cVar2 != '\0') {
        (**(code **)(param_1 + 8))(param_1,param_3,1);
        cVar2 = param_3[1];
        uVar4 = uVar4 + 1;
        param_3 = param_3 + 1;
      }
    }
  }
  uVar6 = param_4 >> 0xf & 0xff;
  if (((param_4 & 0x40) == 0) && ((int)uVar4 < (int)uVar6)) {
    if ((param_4 & 0x100) == 0) {
      auStack_28[0] = 0x20;
    }
    else {
      auStack_28[0] = 0x30;
    }
    iVar8 = uVar6 - uVar4;
    uVar4 = uVar6;
    if (0 < iVar8) {
      do {
        (**(code **)(param_1 + 8))(param_1,auStack_28,1);
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
  }
  if (((param_4 & 0x100) == 0) && (param_3 != (char *)0x0)) {
    cVar2 = *param_3;
    while (cVar2 != '\0') {
      (**(code **)(param_1 + 8))(param_1,param_3,1);
      cVar2 = param_3[1];
      param_3 = param_3 + 1;
    }
  }
  (**(code **)(param_1 + 8))(param_1,puVar7 + 1,uVar5);
  if (((param_4 & 0x40) != 0) && ((int)uVar4 < (int)uVar6)) {
    auStack_28[0] = 0x20;
    iVar8 = uVar6 - uVar4;
    uVar4 = uVar6;
    if (0 < iVar8) {
      do {
        (**(code **)(param_1 + 8))(param_1,auStack_28,1);
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
  }
  return uVar4;
}

