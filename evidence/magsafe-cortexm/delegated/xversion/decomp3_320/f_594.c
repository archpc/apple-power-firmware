
uint FUN_00000594(int param_1,uint param_2,char *param_3,uint param_4)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined1 *puVar8;
  byte bVar9;
  undefined1 auStack_28 [19];
  undefined1 local_15;
  
  iVar6 = DAT_00000708;
  if ((int)(param_4 << 0x16) < 0) {
    iVar6 = DAT_0000070c;
  }
  puVar8 = &local_15;
  if (param_2 == 0) {
    bVar9 = 0;
  }
  else {
    uVar4 = (param_4 & 0x7fff) >> 10;
    bVar9 = 0;
    do {
      uVar5 = FUN_0000089c(param_2,uVar4);
      *puVar8 = *(undefined1 *)(iVar6 + (param_2 - uVar5 * uVar4));
      bVar9 = bVar9 + 1;
      puVar8 = puVar8 + -1;
      bVar1 = uVar4 <= param_2;
      param_2 = uVar5;
    } while (bVar1);
  }
  if (((int)param_4 < 0) && (uVar4 = param_4 >> 0x17 & 0xff, bVar9 < uVar4)) {
    do {
      *puVar8 = 0x30;
      puVar8 = puVar8 + -1;
      bVar9 = bVar9 + 1;
    } while (bVar9 < uVar4);
  }
  else if (bVar9 == 0) {
    *puVar8 = 0x30;
    puVar8 = puVar8 + -1;
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
        iVar6 = 0;
        do {
          iVar3 = iVar6 + 1;
          iVar6 = iVar6 + 1;
        } while (param_3[iVar3] != '\0');
        uVar4 = uVar5 + iVar6;
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
  uVar7 = param_4 >> 0xf & 0xff;
  if (((int)uVar4 < (int)uVar7) && ((param_4 & 0x40) == 0)) {
    if ((param_4 & 0x100) == 0) {
      auStack_28[0] = 0x20;
    }
    else {
      auStack_28[0] = 0x30;
    }
    iVar6 = uVar7 - uVar4;
    uVar4 = uVar7;
    if (0 < iVar6) {
      do {
        (**(code **)(param_1 + 8))(param_1,auStack_28,1);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  if ((param_3 != (char *)0x0) && ((param_4 & 0x100) == 0)) {
    cVar2 = *param_3;
    while (cVar2 != '\0') {
      (**(code **)(param_1 + 8))(param_1,param_3,1);
      cVar2 = param_3[1];
      param_3 = param_3 + 1;
    }
  }
  (**(code **)(param_1 + 8))(param_1,puVar8 + 1,uVar5);
  if (((int)uVar4 < (int)uVar7) && ((param_4 & 0x40) != 0)) {
    auStack_28[0] = 0x20;
    iVar6 = uVar7 - uVar4;
    uVar4 = uVar7;
    if (0 < iVar6) {
      do {
        (**(code **)(param_1 + 8))(param_1,auStack_28,1);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  return uVar4;
}

