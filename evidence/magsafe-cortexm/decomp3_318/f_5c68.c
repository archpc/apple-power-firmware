
void FUN_00005c68(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int *piVar7;
  char *pcVar8;
  uint uVar9;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar2 = DAT_00005ec0;
  iVar3 = *(int *)(DAT_00005ec0 + param_1 * 0xf0);
  uVar9 = (uint)*(byte *)(iVar3 + 2);
  FUN_00005a80(param_1);
  uVar4 = DAT_00005eb8;
  piVar7 = (int *)(iVar2 + param_1 * 0xf0);
  pcVar8 = (char *)(DAT_00005ec4 + param_1 * 0x1cc);
  if (uVar9 == 0x12) {
    if (pcVar8[0x15] == '\0') {
      uVar4 = *(uint *)(iVar3 + 4);
      if ((((int)uVar4 < 0) && (DAT_00005eb4 <= (DAT_00005eb0 & uVar4))) &&
         ((uVar4 & 0x4000000) != 0)) {
        FUN_00007172(param_1,0,0x12,((uVar4 & 0x1ffffff) >> 0x10) + 0x8800,pcVar8 + 0xec);
        return;
      }
    }
    else if (((pcVar8[0x15] == '\x01') && (uVar4 = *(uint *)(iVar3 + 4), (int)uVar4 < 0)) &&
            (uVar9 = (uVar4 & 0x1ffffff) >> 0x10, 0x1a < uVar9)) {
      if ((uVar4 & 0x7fffffff) >> 0x1b != 0) {
        FUN_00000170(iVar3 + 0x22,iVar3 + 8,uVar9 - 0x1a);
LAB_00005e9c:
        FUN_00000170(iVar3 + 8,DAT_00005ecc,0x1a);
LAB_00005ea6:
        uVar5 = 0xc;
LAB_00005ea8:
        FUN_000031a0(param_1,uVar5);
        return;
      }
      FUN_00000170(DAT_00005ecc,iVar3 + 8,0x1a);
    }
  }
  else {
    if (uVar9 == 0x10) {
      *(undefined1 *)((int)piVar7 + 0xa9) = 1;
      if ((DAT_00005eb0 & *(uint *)(iVar3 + 4)) != 0x20000) {
        return;
      }
      switch(*(undefined2 *)(iVar3 + 8)) {
      case 1:
        if (((*pcVar8 == '\0') || (-1 < (int)((uint)(byte)pcVar8[0x9e] << 0x18))) ||
           (-1 < (int)((uint)(byte)pcVar8[0x106] << 0x19))) break;
        *(undefined1 *)((int)piVar7 + 0xee) = 1;
        uVar5 = 0x10;
        goto LAB_00005ea8;
      case 2:
        if (*pcVar8 != '\x01') {
          uVar5 = 0x2e;
          goto LAB_00005ea8;
        }
        break;
      case 3:
        if (pcVar8[0x15] == '\x01') {
          if (pcVar8[0x175] == '\0') {
            return;
          }
          FUN_00006388(param_1,0x10,2,DAT_00005ec8);
          return;
        }
        break;
      case 4:
        if (pcVar8[0x15] == '\0') {
          return;
        }
      }
      FUN_000062f4(param_1,0x10);
      return;
    }
    if (uVar9 != 0x11) {
      if (uVar9 == 6) {
        (*(code *)**(undefined4 **)(pcVar8 + 0x60))(param_1,0x41,*piVar7);
        pcVar8[0x43] = '\x02';
        FUN_00003038(param_1,9,0x1b);
        return;
      }
      bVar1 = uVar9 - 3 < 2;
      if (bVar1) {
        (*(code *)**(undefined4 **)(pcVar8 + 0x60))(param_1,0x41,*piVar7);
      }
      if ((uVar9 < 0x10) && ((1 << uVar9 & DAT_00005ebc) != 0)) {
        return;
      }
      pcVar8[0x43] = '\x02';
      FUN_00003038(param_1,9,0x1b);
      if (bVar1) {
        return;
      }
      goto LAB_00005e0c;
    }
    if (pcVar8[0x15] == '\0') {
      uVar9 = *(uint *)(iVar3 + 4);
      if ((int)uVar9 < 0) {
        uVar6 = (uVar9 & 0x1ffffff) >> 0x10;
        if (uVar6 < 0x1b) goto LAB_00005ea6;
        uVar9 = (uVar9 & 0x7fffffff) >> 0x1b;
        if (uVar9 == 1) {
          FUN_000007f0(iVar3 + 0x22,iVar3 + 8,uVar6 - 0x1a);
          goto LAB_00005e9c;
        }
        if (uVar9 == 0) {
          FUN_00000170(DAT_00005ecc,iVar3 + 8,0x1a);
          local_18 = 0;
          local_1c = 0;
          uVar9 = *(uint *)(*piVar7 + 4) >> 0x10;
          FUN_00007172(param_1,0,0x11,&LAB_00008400 + (uVar4 & uVar9) + (uVar9 + 0x800 & 0x7800),
                       &local_1c);
        }
      }
    }
    else {
      FUN_000062f4(param_1,0x10);
    }
  }
  pcVar8[0x43] = '\x02';
  FUN_00003038(param_1,9,0x1b);
LAB_00005e0c:
  (*(code *)**(undefined4 **)(pcVar8 + 0x60))(param_1,0x1e,*piVar7);
  return;
}

