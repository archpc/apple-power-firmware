
undefined4 FUN_00002918(uint param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined2 local_18 [2];
  
  iVar1 = DAT_00002a14;
  if (1 < param_1) {
    return 7;
  }
  if ((param_1 == 1) && (*(char *)(DAT_00002a10 + 3) != '\0')) {
    return 0xf;
  }
  if ((param_5 == 0) && (*(char *)(DAT_00002a14 + param_1 * 0x1cc + 0x43) != '\0')) {
    return 0xf;
  }
  FUN_0000a908();
  iVar1 = iVar1 + param_1 * 0x1cc;
  if (*(char *)(iVar1 + 0x31) == '\0') {
    return 0xb;
  }
  if (*(char *)(iVar1 + 0x1d) != '\0') {
    if (*(char *)(iVar1 + 0x2f) == '\0') {
      if ((param_2 != 5) && (*(int *)(iVar1 + 0x48) != 0)) {
        return 0xf;
      }
    }
    else if (param_2 != 5) {
      return 0xf;
    }
    if ((*(char *)(iVar1 + 0x45) != '#') &&
       (((param_2 != 0 || (*(char *)(iVar1 + 0x45) != '\x0f')) && (param_2 != 5)))) {
      return 0xb;
    }
    if (((param_2 != 5) && (1 < *(byte *)(iVar1 + 0x3e))) &&
       ((*(char *)(iVar1 + 0x1c9) != '\x01' && ((*(char *)(iVar1 + 0x15) == '\0' && (param_5 == 0)))
        ))) {
      if (*(char *)(iVar1 + 0x16) != '\x03') {
        return 0xe;
      }
      local_18[0] = FUN_000088d4(param_1);
      if (*(char *)((int)local_18 + (uint)*(byte *)(iVar1 + 0x1a)) != '\x03') {
        return 0xe;
      }
    }
    *(char *)(iVar1 + 0x2e) = (char)param_2;
    *(undefined1 *)(iVar1 + 0x2f) = 1;
    *(undefined4 *)(iVar1 + 100) = param_4;
    if (param_3 != 0) {
      FUN_00000170(*(undefined4 *)(iVar1 + 0x6c),param_3,0x2c);
    }
    FUN_000028b8(param_1,0x200);
    return 0;
  }
  return 0xb;
}

