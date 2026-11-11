
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void switchD_00003ba4::caseD_4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  
  iVar2 = _caseD_7;
  iVar1 = DAT_00004194;
  switch(param_2) {
  case 2:
    if (*(char *)(_caseD_7 + 0xa8) == '\x01') {
      *(undefined1 *)(_caseD_7 + 0xa8) = 0;
      FUN_00006de4(0,0,2);
      return;
    }
    uVar4 = *(uint *)(DAT_00004194 + 0x104);
    uVar3 = uVar4;
    if ((int)(uVar4 << 4) < 0) {
      uVar3 = uVar4 >> 10;
    }
    *(ushort *)(_caseD_7 + 0xc4) = (ushort)DAT_00004190 & (ushort)uVar3;
    if ((int)uVar4 < 0) {
      uVar3 = uVar4 >> 0x1c | 8;
    }
    else {
      uVar3 = uVar4 >> 0x1c & 7;
    }
    uVar3 = *(uint *)(uVar3 * 4 + iVar1 + 0x98);
    *(uint *)(iVar1 + 0x118) = uVar3;
    sVar5 = (short)((uVar3 & 0xfffff) >> 10) * 0x32;
    *(short *)(iVar2 + 200) = sVar5;
    if (uVar3 >> 0x1e != 0) {
      sVar5 = (((ushort)(uVar3 >> 0x10) & 0x3fff) >> 4) * 0x32;
    }
    *(short *)(iVar2 + 0xc6) = sVar5;
    break;
  case 3:
    FUN_00002f62(0,3);
    *(undefined1 *)(iVar1 + 0x2f) = 0;
    *(undefined4 *)(iVar1 + 100) = 0;
    break;
  case 4:
  case 5:
    FUN_00002f62(0,0);
    FUN_00005a38(0);
    return;
  case 6:
    FUN_00002f62(0,0);
    FUN_00003088(0);
    return;
  default:
    goto switchD_000040da_caseD_7;
  case 8:
    break;
  }
  FUN_000031a0(0,0x14);
switchD_000040da_caseD_7:
  return;
}

